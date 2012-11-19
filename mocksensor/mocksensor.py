#/usr/bin/python

import zmq
import ctypes
import msgpack

from io import BytesIO
from time import time, sleep

from pycap import *



def init_zmq(address):
    zcontext = zmq.Context()
    zsocket = zcontext.socket(zmq.PUSH)
    zsocket.connect("tcp://" + address)
    return zcontext, zsocket


def init_pcap(filename):
    errbuf = ctypes.create_string_buffer(512)
    handle = pcap_open_offline(filename.encode(), errbuf)
    if not handle:
        print(errbuf.value.decode())
        exit(0)
    return handle

def mocksensor(filename, address, interval_sec):
    zcontext, zsocket = init_zmq(address)
    pcap = init_pcap(filename)

    packetData = ctypes.POINTER(ctypes.c_ubyte*65536)()
    pkthdrPointer = ctypes.POINTER(pcap_pkthdr)()
    try:
        timestamp = 0
        buf = BytesIO()
        count = 0
        while pcap_next_ex(pcap, ctypes.byref(pkthdrPointer),  ctypes.byref(packetData)) > 0:
            count += 1
            pktheader = pkthdrPointer.contents
            t = pktheader.tv_sec + pktheader.tv_usec // 100000
            if timestamp == 0:
                timestamp = t
            elif t - timestamp >= interval_sec:
                timestamp = t
                zsocket.send(buf.getbuffer().tobytes())
                sleep(interval_sec)
            else:
                header = (pktheader.tv_sec, pktheader.tv_usec, pktheader.caplen, pktheader.len)
                buf.write(msgpack.packb(header))
                buf.write(msgpack.packb(packetData.contents[:pktheader.len]))

        # last send
        zsocket.send(buf.getbuffer().tobytes())
        print(count)

    except KeyboardInterrupt:
        pass
    finally:
        print('Shutting down')
        pcap_close(pcap)
        zcontext.destroy()



if __name__ == "__main__":
    mocksensor("test.pcap", "localhost:31337", 5)




