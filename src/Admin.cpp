#include "Admin.h"
#include "Menu.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

Admin::Admin()
{
    this->adminLogin();
}

Admin::~Admin()
{
    //dtor
}

string Admin::getpass(bool show_asterisk = true)
{
    const char BACKSPACE = 8;
    const char RETURN = 13;

    string password;
    unsigned char ch = 0;

    while((ch = getch())!= RETURN)
    {
        if(ch == BACKSPACE)
        {
            if(password.length()!=0)
            {
                if(show_asterisk)
                cout << "\b \b";
                password.resize(password.length()-1);
            }
        }
        else if(ch == 0 || ch == 224) // handle escape sequences
        {
            getch(); // ignore non printable chars
            continue;
        }
        else
        {
            password += ch;
            if(show_asterisk)
            cout <<'*';
        }
    }

    cout << endl;
    return password;
}

void Admin::adminMenu(){
    cout << "Hi admin" << endl;
}

void Admin::adminLogin(){
    system("cls");
    bool loginTrue = false;
    string username, pwd;
    cout << "\n\n\n\n\n\n";

    cout << endl << setw(82) << "Admin Sign In to Login In the System\n\n";
    cout << setw(45);

    for(int i = 0; i < 36; i++)
    {
        Sleep(5);
        cout << "=";
    }

    cin.ignore(1000, '\n');
    cout << "\n\n" << setw(66) << "Admin Login : ";
    getline(cin, username);

    cout << "\n" << setw(66) << "Password : ";
    pwd = getpass();

    cout << "\n\n" << setw(45);
    for(int i = 0; i < 36; i++)
    {
        Sleep(5);
        cout << "=";
    }

    if(username == this->ADMIN_USERNAME && pwd == this->ADMIN_PWD)
    {
        cout << "\n\n\n" << setw(74) << "Login Successfully !!!" << endl;
        loginTrue = true;
    }
    else{
        cout << "\n\n\n" << setw(71) << "Login Failed !!!" << endl;
    }

    cout << "\n\n\n\n\t\t\t\t\t     ";
    system("pause");
    system("cls");

    if(loginTrue)
    {
        this->adminMenu();
    }
    else
    {
        Menu::selectUser();
    }
}

