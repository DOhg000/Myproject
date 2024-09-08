#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

void Registration();
int Logging();

int main()
{
	setlocale(LC_ALL, "ru");
	bool rez = true;
	while (rez)
	{
		int put;

		cout << "1. ���� � �������\n"
			<< "2. ����������� ��������\n"
			<< "3. ��������� ������" << endl;

		cout << "������� ����� �������: ";
		cin >> put;
		cout << endl << endl;

		switch (put)
		{
		case 1:
			Logging();
			break;
		case 2:
			Registration();
			break;
		case 3:
			rez = false;
			break;
		default:
			break;
		}
	}
}

void Registration()
{
	char log[100];
	char pass[100];
	cout << "������� ����� ��� �����������:\t";
	cin >> log;
	cout << endl;

	cout << "������� ������ ��� �����������:\t";
	cin >> pass;
	cout << endl;

	ofstream fout;
	fout.open("loginbase.txt");

	fout << log << endl << pass;
	fout.close();
	cout << "����������� �������!" << endl;
}

int Logging()
{
	string login, password;
	char log_check[100];
	char pass_check[100];

	cout << "������� �����:\t";
	cin >> login;
	cout << endl;

	cout << "������� ������:\t";
	cin >> password;
	cout << endl;

	ifstream fin;
	fin.open("loginbase.txt");
	if (!fin.is_open())
	{
		cout << "���� �� ����� ���� ������!" << endl;
		return 0;
	}
	else
	{
		fin.getline(log_check, 50);
		fin.getline(pass_check, 50);

		if (log_check == login && pass_check == password)
		{
			cout << "����������� ������ �������!" << endl;
			fin.close();
			return 0;
		}
		else
		{
			cout << "������ �����������!" << endl;
			fin.close();
			return 0;
		}
	}
}