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

		cout << "1. Вход в аккаунт\n"
			<< "2. Регистрация аккаунта\n"
			<< "3. Завершить работу" << endl;

		cout << "Введите номер оперции: ";
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
	cout << "Введите логин для регистрации:\t";
	cin >> log;
	cout << endl;

	cout << "Введите пароль для регистрации:\t";
	cin >> pass;
	cout << endl;

	ofstream fout;
	fout.open("loginbase.txt");

	fout << log << endl << pass;
	fout.close();
	cout << "Регистрация успешна!" << endl;
}

int Logging()
{
	string login, password;
	char log_check[100];
	char pass_check[100];

	cout << "Введите логин:\t";
	cin >> login;
	cout << endl;

	cout << "Введите пароль:\t";
	cin >> password;
	cout << endl;

	ifstream fin;
	fin.open("loginbase.txt");
	if (!fin.is_open())
	{
		cout << "Файл не может быть открыт!" << endl;
		return 0;
	}
	else
	{
		fin.getline(log_check, 50);
		fin.getline(pass_check, 50);

		if (log_check == login && pass_check == password)
		{
			cout << "Авторизация прошла успешно!" << endl;
			fin.close();
			return 0;
		}
		else
		{
			cout << "Ошибка авторизации!" << endl;
			fin.close();
			return 0;
		}
	}
}