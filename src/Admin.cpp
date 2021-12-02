#include "Admin.h"
#include "Menu.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
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
                password.resize(password.length() - 1);
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
                cout << '*';
        }
    }

    cout << endl;
    return password;
}

int Admin::adminMenu(){
    system("cls");
    int opt;

    cout << "\n\n\n\n\n\n\n\n";

    cout << setw(45);
    for(int i = 0; i < 33; i++)
    {
        Sleep(5);
        cout << "*";
    }

    cout << endl << setw(68) << "Admin Action\n\n";
    cout << setw(68) << "1. Add Food\n\n";
    cout << setw(79) << "2. Display Food Detail\n\n";
    cout << setw(64) << "3. Back\n\n";

    cout << setw(45);
    for(int i = 0; i < 33; i++)
    {
        Sleep(5);
        cout << "*";
    }


    do{
        cout << endl << setw(60) << "> ";
        cin >> opt;

        if(opt != 1 && opt != 2 && opt != 3)
        {
            cout << setw(78) << "Invalid Input !! Please Enter Again" << endl;
        }
    }while(opt != 1 && opt != 2 && opt != 3);

    return opt;
}

void Admin::adminAction(int opt){
    switch(opt){

    case 1:
        // add item
        this->addFood();
        break;

    case 2:
        // display item

        break;

    case 3:
        // back to main menu
        Menu::userAction(Menu::selectUser());
        break;

    default:
        // nothing
        break;
    }
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
        int opt = this->adminMenu();
        this->adminAction(opt);
    }
    else
    {
        Menu::userAction(Menu::selectUser());
    }
}

void Admin::addFood(){
    system("cls");

    cin.clear();
    cin.ignore(1000, '\n');

    string foodCode, foodName, foodType;
    double foodPrice;

    cout << "\n\n\n\n\n\n" << endl;
    cout << "\n" << setw(64) << "Enter the Food Code  : ";
    getline(cin, foodCode);

    cout << "\n" << setw(64) << "Enter the Food Name  : ";
    getline(cin, foodCode);

    cout << "\n" << setw(64) << "Enter the Food Type  : ";
    getline(cin, foodCode);

    cout << "\n" << setw(67) << "Enter the Food Price : RM ";
    cin >> foodPrice;

}

