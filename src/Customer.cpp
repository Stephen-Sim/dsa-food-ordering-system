#include "Customer.h"
#include "Menu.h"
#include "Food.h"
#include "Order.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>

#define RETURN 13
#define BACKSPACE 8

using namespace std;

Customer::Customer()
{
    //ctor
    this->cusMenu();
}

Customer::~Customer()
{
    //dtor
}

void Customer::cusMenu(){
    system("cls");

    cout << "\n\n\n\n\n\n\n\n";

    cout << setw(45);
    for(int i = 0; i < 33; i++)
    {
        Sleep(5);
        cout << "*";
    }

    cout << endl << setw(68) << "Customer Action\n\n";
    cout << setw(68) << "1. Make Order\n\n";
    cout << setw(75) << "2. Display Food Menu\n\n";
    cout << setw(62) << "3. Back\n\n";

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

    cusAction(current);
}

void Customer::cusAction(int opt){

    if(opt == 1)
    {
        Order order;
    }
    else if(opt == 2)
    {
        Food::displayFood('c');
    }
    else if(opt == 3)
    {
        Menu::userAction(Menu::selectUser());
    }
}
