#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class Person
{
private:	

public:
    float Balance()
    {

    }
protected:
	string forLog;
	string forPass;
	string phone_number;
	string postcode;
	string FIO[2];
    string card_number;
	
};
class Client :public Person
{
private:

    string login = "login.txt";
    string password = "password.txt";
    string information = "info.txt";
    string Balance = "Balance.txt";
    string login_correct;
    string pass_correct;
    string login_checker;
    string pass_checker;
    string balance_checker;
    float money = 505.5;
 
    int card_number;

protected:

public:
    int Authorization()
    {
        fstream log;
        fstream pass;
        fstream info;

        log.open(login, fstream::in | fstream::out | fstream::app);
        pass.open(password, fstream::in | fstream::out | fstream::app);
        info.open(information, fstream::in | fstream::out | fstream::app);

        if (!log.is_open() && !pass.is_open())
        {
            cout << "Error!" << endl;
        }
        else
        {

            while (!log.eof()) //Пока не закончатся символы, идем по циклу.
            {
                login_correct = "";
                log >> login_correct; //Передаем данные с файла в переменную.
            }
            while (!pass.eof()) //Пока не закончатся символы, идем по циклу.
            {
                pass_correct = "";
                pass >> pass_correct; //Передаем данные с файла в переменную.
            }

            cout << "Enter your login: "; cin >> login_checker;
            cout << endl;
            cout << "Enter your password: "; cin >> pass_checker;

            if (login_checker == login_correct && pass_checker == pass_correct)
            {
                cout << "Access granted" << endl;
                cout << "-------------------------------------------" << endl;
                while (!info.eof())
                {
                    getline(info, forLog);
                    cout << endl;
                    cout << forLog;
                }
                srand(time(NULL));
                int n = rand();
                if (n % 2 == 0)
                    show_balance();
                else
                    show_balance(n);
            }
            else
            {
                cout << "Wrong login or password\nAccess denied" << endl;
            }
            return 0;
        }
    }
    int Registration()
    {
        fstream log;
        fstream pass;
        fstream info;
        fstream balance;

        log.open(login, fstream::in | fstream::out | fstream::app);
        pass.open(password, fstream::in | fstream::out | fstream::app);
        info.open(information, fstream::in | fstream::out | fstream::app);
        balance.open(Balance, fstream::in | fstream::out | fstream::app);

        if (!log.is_open() && !pass.is_open())
        {
            cout << "Error!" << endl;
        }
        else
        {

            cout << "Enter new login: "; cin >> forLog;
            cout << endl;
            cout << "Enter new password: "; cin >> forPass;
            cout << endl;
            cout << "Enter your name: "; cin >> FIO[0];
            cout << endl;
            cout << "Enter your surname: "; cin >> FIO[1];
            cout << endl;
            cout << "Enter your phone number: "; cin >> phone_number;
            cout << endl;
            cout << "Enter your postal code: "; cin >> postcode;
            cout << endl;
            cout << "Enter your card number: "; cin >> card_number;

            log << forLog;
            pass << forPass;
            info << "Name: " << FIO[0] << "\n";
            info << "Surname: " << FIO[1] << "\n";
            info << "Phone number: " << phone_number << "\n";
            info << "Postal code: " << postcode << "\n";
            balance << card_number;

            cout << "Registration completed successfully" << endl;
            return 0;

        }
    }
    void show_balance()
    {
        fstream balance;
        balance.open(Balance, fstream::in | fstream::out | fstream::app);
        if (!balance.is_open())
        {
            cout << "Error!" << endl;
        }
        else
        {

            while (!balance.eof()) //Пока не закончатся символы, идем по циклу.
            {
                balance_checker = "";
                balance >> balance_checker; //Передаем данные с файла в переменную.
            }
            cout << "Card number: " << balance_checker << endl;

        }
    }
    void show_balance(int a)
    {
        cout << "card number:**** **** **** ****" << endl;
        cout << "Card number is hidden.";
    }
};
int main()
{
    setlocale(LC_ALL, "Russian");
	Client Test;
	int choosen_number;
	start:
	cout << "1.Registration\n2.Authorization\n1/2?";
	cin >> choosen_number;
    if (choosen_number == 1) {
        Test.Registration();
    }
	else if (choosen_number == 2)
		Test.Authorization();
	else
		goto start;

	return 0;
}
