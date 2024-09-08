#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <string>
#include <thread>
#include <cstdio> 
#include <cstring> 
#include <winsock2.h> 
#pragma comment(lib, "WS2_32.lib")
using namespace std;


DWORD WINAPI serverReceive(LPVOID lpParam) { //��������� ������ �� �������
	setlocale(LC_ALL, "ru");
	char buffer[1024] = { 0 }; //����� ��� ������
	SOCKET client = *(SOCKET*)lpParam; //����� ��� �������
	while (true) { //���� ������ �������
		if (recv(client, buffer, sizeof(buffer), 0) == SOCKET_ERROR) {
			//���� �� ������� �������� ������ ������, �������� �� ������ � �����
			cout << "������ ��������� ������ ������, ��� �� ������ ������������, ��� ������: " << WSAGetLastError() << endl;
			return -1;
		}
		if (strcmp(buffer, "exit\n") == 0) { //���� ������ ������������
			cout << "������ ���������� � ��������." << endl;
			break;
		}
		cout << "Client: " << buffer << endl; //����� ������� ��������� �� ������� �� ������
		memset(buffer, 0, sizeof(buffer)); //�������� �����
	}
	return 1;
}


DWORD WINAPI serverSend(LPVOID lpParam) { //�������� ������ �������
	setlocale(LC_ALL, "ru");
	char buffer[1024] = { 0 };
	SOCKET client = *(SOCKET*)lpParam;
	while (true) {
		fgets(buffer, 1024, stdin);
		if (send(client, buffer, sizeof(buffer), 0) == SOCKET_ERROR) {
			cout << "�� ������� ��������� ������, ��� ������: " << WSAGetLastError() << endl;
			return -1;
		}
		if (strcmp(buffer, "exit\n") == 0) {
			cout << "������ ��������!" << endl;
			break;
		}
	}
	return 1;
}


int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WSADATA WSAData; //������ 
	SOCKET server, client; //������ ������� � �������
	SOCKADDR_IN serverAddr, clientAddr; //������ �������
	WSAStartup(MAKEWORD(2, 2), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0); //������� ������
	if (server == INVALID_SOCKET) {
		cout << "������ �������� ������, ��� ������: " << WSAGetLastError() << endl;
		return -1;
	}
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(5555);
	if (bind(server, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
		cout << "�� ������� ��������� ������ � ������, ��� ������: " << WSAGetLastError() << endl;
		return -1;
	}

	if (listen(server, 0) == SOCKET_ERROR) { //���� �� ������� �������� ������
		cout << "�� ������� ���������� �������, ��� ������: " << WSAGetLastError() << endl;
		return -1;
	}
	cout << "������������� �����������..." << endl;

	char buffer[1024]; //������� ����� ��� ������
	int clientAddrSize = sizeof(clientAddr); //���������������� ����� �������
	if ((client = accept(server, (SOCKADDR*)&clientAddr, &clientAddrSize)) != INVALID_SOCKET) {
		//���� ���������� �����������
		cout << "������ ���������!" << endl;
		cout << "���� ������ ��������� ������,���������. " << "Enter \"exit\" ������������" << endl;

		DWORD tid; //�������������
		HANDLE t1 = CreateThread(NULL, 0, serverReceive, &client, 0, &tid); //�������� ������ ��� ��������� ������
		if (t1 == NULL) { //������ �������� ������
			cout << "������ �������� ������: " << WSAGetLastError() << endl;
		}
		HANDLE t2 = CreateThread(NULL, 0, serverSend, &client, 0, &tid); //�������� ������ ��� �������� ������
		if (t2 == NULL) {
			cout << "������ �������� ������: " << WSAGetLastError() << endl;
		}

		WaitForSingleObject(t1, INFINITE);
		WaitForSingleObject(t2, INFINITE);

		closesocket(client); //������� �����
		if (closesocket(server) == SOCKET_ERROR) { //������ �������� ������
			cout << "������ �������� ������, ��� ������:  " << WSAGetLastError() << endl;
			return -1;
		}
		WSACleanup();
	}
}