#include <iostream>
#include <unordered_map>
#include <vector>

#include "User.h"
#include <fstream>

int ID_Number;
unordered_map<string, User> users;
string current_user = "";
Chat public_chat;

#include "Functions.h"

using namespace std;

auto main() -> int
{
    ID_Number = 1;
	char input;
	int proof;
	bool access = false;
	int input_2 = -1;
	string message = "";
	set_data_from_file();

	do
	{
		system("cls");																	// ������� ������ �������
		cout << "0 - log in" << endl;													// �����������
		cout << "1 - sign up" << endl;													// �����������
		cout << "q - close Console Chat" << endl;										// �����

		cin >> input;																	// �������� ������ �����
		switch (input)
		{
		case '0':
			access = Authorization();
			break;

		case '1':
			access = Registration();
			break;

		case 'q':																	// �����
			cout << "Are you sure you want to close the Console Chat?" << endl;		// ����������, ��� ������������ ����� ����� �� ����������� ����
			cout << "0 - No" << endl;
			cout << "1 - Yes" << endl;
			cin >> proof;
			if (proof == 0)
				input = 'f';														// ������ �������� ���������� input, ����� �� ����� �� �����															
			break;																	// �����, �� ������ � ������� �� ����

		default:
			cout << "Incorrect data." << endl;										// ������� ���������, ���� ��������� ������ �� ������������� ������������ ������. ������� ����� ���������� ������
			system("pause");
		}

		if (input != 'q' && access)
		{
			access = true;
			do
			{
				system("cls");															// ������� ������ �������
				cout << current_user << endl;
				cout << "0 - exit" << endl;												// �����
				cout << "1 - to choose chat" << endl;									// ����� ������������ �����
				//cout << "2 - to start new chat" << endl;								// ������� ����� ��������� ���

				cin >> input_2;
				int chats_count = users[current_user].get_chats_count(), id;
				switch (input_2)
				{
				case 0:
					cout << "Are you sure you want to exit?" << endl;					// ����������, ��� ������������ ����� ����� �� ����������� ����
					cout << "0 - No" << endl;
					cout << "1 - Yes" << endl;
					cin >> proof;
					if (proof == 1)															// ������ �������� ���������� access, ����� ����� �� �����
						access = false;													// �����, �� ������ � �������� � ����
					break;

				case 1:
					cout << "0 - public chat" << endl;

					for (int i = 0; i < chats_count; i++)
					{
						id = users[current_user].get_receiver_id(i);
						cout << id << " - chat with user " <<
							users[get_login_from_id(id)].getName() << endl;
					}
					cout << "Choose chat: ";
					cin >> id;

					Communication(id);

					//system("pause");
					break;

				//case 2:

					//break;

				default:
					cout << "Incorrect data." << endl;
					system("pause");
				}
			} while (access);
			
		}
	} while (input != 'q');
	/*
	for (auto& const e : users)
	{
		cout << e.second << endl;
	}
	*/
	return 0;
}