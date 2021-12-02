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

    cout << "Hello World" << endl;

    return 0;
}
