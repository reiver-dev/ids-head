// my second program in C++

#include <iostream>
//#include <string>
//using namespace std;

//����� ����
class CoreClass
{
private:
	//��������� listeners[] subSystems[] clients[] ;

	int logger;
	int	config; //��������� ��� ������ ar['max_file_size'] = 7
public:
	//
	CoreClass ()
	{};
	~CoreClass()
	{};

	void loadConfig ()
	{
		std::cout << "loadConfig\n";
	};
	void initLogging()// ����. ������������
	{
		std::cout << "initLogging\n";
	};
	void initSubSystems()
	{
		std::cout << "initSubSystems\n";
	};


	void initListeners()
	{
		std::cout << "initListeners\n";
	};
	void linkClients()
	{
		std::cout << "linkClients\n";
	}; // ��������
	void linkListeners()
	{
		std::cout << "linkListeners\n";
	};
	void linkSubSystems()
	{
		std::cout << "linkSubSystems\n";
	};
	void startListeners()
	{
		std::cout << "startListeners\n";
	};


};

//������ ��������� ---------------------------
class STrafficManagerClass
{
public:
	//
	STrafficManagerClass ()
	{};
	~STrafficManagerClass()
	{};

	void someStreetMagicHere ()
	{
		std::cout << "someStreetMagicHere\n";
	};
};


class SAutorizationClass
{
private:
	int sessionLifeTime;
	char sessions[10];

public:
	//
	SAutorizationClass ()
	{};
	~SAutorizationClass()
	{};

	void createSession ()
	{
		std::cout << "createSession\n";
	};

	bool sessionValidate (int dump) //�� ���
	{
		std::cout << "sessionValidate\n";
		return false;
	};
};

class STrafficSaverClass
{
private:

public:
	//
	STrafficSaverClass ()
	{};
	~STrafficSaverClass ()
	{};
};

class SLogingClass
{
private:

public:
	//
	SLogingClass ()
	{};
	~SLogingClass ()
	{};
};


//������ ���������� ---------------------------
class DumpClass
{
private:
	char sessionHash[5];
	char sessionKey[5];
	int dump;
public:
	//
	DumpClass ()
	{};
	~DumpClass ()
	{};

	void parse ()
	{
		std::cout << "parse\n";
	};
	void unpack ()
	{
		std::cout << "unpack\n";
	};
	void toLittleEndian ()
	{
		std::cout << "toLittleEndian\n";
	};
};



class ReceiverClass
{
private:
	DumpClass Message;
public:
	//
	ReceiverClass ()
	{};
	~ReceiverClass ()
	{};
	void toSTrafficManager ()
	{
		std::cout << "toSTrafficManager\n";
	};

};

class DumpListenerClass
{
private:
	int port;
	ReceiverClass recievers;//��������
public:
	//
	DumpListenerClass ()
	{};
	~DumpListenerClass ()
	{};

	void startListen ()
	{
		std::cout << "startListen\n";
	};

	void stopListen ()
	{
		std::cout << "stopListen\n";
	};

	void getActiveSensorsCount ()
	{
		std::cout << "getActiveSensorsCount\n";
	};

	void manageReceiver ()
	{
		std::cout << "manageReceiver\n";
	};
};

class SensorListenerClass
{
private:
	int port;
	char message[5];
public:
	//
	SensorListenerClass ()
	{};
	~SensorListenerClass ()
	{};
	void startListen ()
	{
		std::cout << "startListen\n";
	};

	void stopListen ()
	{
		std::cout << "stopListen\n";
	};

	void receiveMessage ()
	{
		std::cout << "receiveMessage\n";
	};

	void sendMessage ()
	{
		std::cout << "sendMessage\n";
	};

};

int main ()
{
	CoreClass Core;
	Core.loadConfig();
	Core.initLogging();
	Core.initSubSystems();
	///�������
	Core.linkClients();
	Core.initListeners();
	Core.linkListeners();
	Core.startListeners();


	int i=5;
	//std::cout << i;
	std::cin >>i;
	system("pause");/////////////
	return 0;
}

