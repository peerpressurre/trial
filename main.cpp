#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool LogIn(File& datafile)
{
	datafile.open(path, ios::in);
	if (datafile.is_open())
	{
		string login, password;
		cout << "Enter login: ";
		cin >> login;
		this->setLogin(login);
		cout << "Enter password: ";
		cin >> password;
		this->setPassword(password);
		string line, data = this->getLogin() + ' ' + this->getPassword();
		bool exitloop = true;
		while (getline(datafile, line, '\n') && exitloop)
		{
			if (line == data)
			{
				datafile.close();
				cout << "You are in" << endl;
				return true;
				exitloop = false;
				break;
			}
		}
	}
	else
	{
		cout << "Error opening file" << endl;
		return false;
	}
	datafile.close();
	cout << "Wrong login or password" << endl;
	return false;
}

int main()
{
    fstream file;
    string path = "file.txt";
    LogIn(file, path);

    return 0;
}