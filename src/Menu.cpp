#include "Menu.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
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
    cout << setw(68) << "By Group 2\n\n";

    cout << setw(45) << endl;
    for(int i = 0; i < 33; i++)
    {
        Sleep(5);
        cout << "*";
    }

    cout << "\n\n\n\n\t\t\t\t\t     ";

    system("pause");

    system("cls");

    this->selectUser();

}

Menu::~Menu()
{
    //dtor
}

int Menu::selectUser()
{
    int opt;

    cout << "\n\n\n\n\n\n\n\n";

    cout << setw(45);
    for(int i = 0; i < 33; i++)
    {
        Sleep(5);
        cout << "*";
    }

    cout << endl << setw(69) << "The Action Menu\n\n";
    cout << setw(68) << "1. Admin Login\n\n";
    cout << setw(71) << "2. Customer Order\n\n";

    cout << setw(45);
    for(int i = 0; i < 33; i++)
    {
        Sleep(5);
        cout << "*";
    }


    do{
        cout << endl << setw(60) << "> ";
        cin >> opt;

        if(opt != 1 && opt != 2)
        {
            cout << setw(78) << "Invalid Input !! Please Enter Again" << endl;
        }
    }while(opt != 1 && opt != 2);

    return 0;
}
