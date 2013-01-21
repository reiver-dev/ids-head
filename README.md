### IDS Head
========
## Required:
- mongoclient
- boost_system
- boost_filesystem
- boost_program_options
- boost_thread
- logog
- config++
- msgpack
- zmq

## Making:
```shell
$ cmake
$ make
Built target ids_head
```

## Quick Start:
###Start:
```shell
$ mongod # [--dbpath path] if needed
./ids_head config.cfg
```
###Stop:
```shell
./ids_head stop
```
