#include "Menu.h"
#include "Admin.h"
#include "Customer.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

#define RETURN 13
using namespace std;

Menu::Menu()
{
    cout << "\n\n\n\n\n\n\n\n";
    cout << setw(45);
    for(int i = 0; i < 33; i++)
    {
        Sleep(5);
        cout << "*";
    }

    cout << "\n\n" << setw(78) << "Welcome to Food Ordering System\n\n";
    cout << setw(68) << "By Group A2\n\n";

    cout << setw(45) << endl;
    for(int i = 0; i < 33; i++)
    {
        Sleep(5);
        cout << "*";
    }

    cout << "\n\n\n\n\t\t\t\t\t     ";

    system("pause");

    this->userAction(this->selectUser());
}

Menu::~Menu()
{
    //dtor
}

int Menu::selectUser()
{
    system("cls");
    cout << "\n\n\n\n\n\n\n\n";

    cout << setw(45);
    for(int i = 0; i < 33; i++)
    {
        Sleep(5);
        cout << "*";
    }

    cout << endl << setw(69) << "The User Menu\n\n";
    cout << setw(68) << "1. Admin Login\n\n";
    cout << setw(71) << "2. Customer Order\n\n";
    cout << setw(61) << "3. Exit\n\n";

    cout << setw(45);
    for(int i = 0; i < 33; i++)
    {
        Sleep(5);
        cout << "*";
    }


    unsigned char opt = 0;
    int current = 1;

    cout << endl << setw(60) << "> 1";

    while((opt = getch())!= RETURN){

        if(opt == 72) // move up
        {
            if(current > 1){
                cout << "\b \b";
                cout << --current;
            }

        }
        else if(opt == 80) // move up
        {
            if(current < 3){
                cout << "\b \b";
                cout << ++current;
            }
        }

        fflush(stdin);
    }

    return current;
}

void Menu::exitPage(){
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << endl << setw(80) << "Thank You for Using Our System ! ! !";
    cout << "\n\n\n\n\t\t\t\t\t     ";
    system("pause");
    system("cls");
}

void Menu::userAction(int opt){
    system("cls");

    if(opt == 1)
    {
        Admin admin;
    }
    else if(opt == 2)
    {
        Customer customer;
    }
    else if(opt == 3)
    {
        Menu::exitPage();
    }
}
