#include <iostream>

class DumpListenerClass
{
private:
	unsigned int itsPort;

public:
	DumpListenerClass(unsigned int initialPort);
	~DumpListenerClass();

	unsigned int getPort() const
	{
		return itsPort;
	}

	void setPort(unsigned int port)
	{
		itsPort = port;
	}

};

DumpListenerClass::DumpListenerClass(unsigned int initialPort)
{
	itsPort = initialPort;
}

DumpListenerClass::~DumpListenerClass()
{
}


int main(int argc, char** argv)
{
	DumpListenerClass dumpListener(5555);
	//dumpListener.setPort(6666);



	std::cout << "Hello, World!  " << dumpListener.getPort() << std::endl;
}

