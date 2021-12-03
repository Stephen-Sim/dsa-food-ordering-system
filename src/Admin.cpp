#include "Admin.h"
#include "Menu.h"
#include "Food.h"
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

Admin::Admin()
{
    this->adminLogin();
}

Admin::~Admin()
{
    //dtor
}

string Admin::getPass(bool show_asterisk = true)
{
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

void Admin::adminMenu(){
    system("cls");

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

    adminAction(current);
}

void Admin::adminAction(int opt){

    switch(opt){

    case 1:
        // add item
        addFood();
        adminMenu();
        break;

    case 2:
        // display item
        Food::displayFood('a');
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

    cout << "\n\n" << setw(66) << "Admin Login : ";
    getline(cin, username);

    cout << "\n" << setw(66) << "Password : ";
    pwd = getPass();

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

    fflush(stdin);
    cout << "\n\n\n\n\t\t\t\t\t     ";
    system("pause");
    system("cls");

    if(loginTrue)
    {
        this->adminMenu();
    }
    else
    {
        Menu::userAction(Menu::selectUser());
    }
}

void Admin::addFood(){
    system("cls");

    cout << "Move Arrow Key Up to select Food, Down to Select Drink";
    Food food;
    string foodCode, foodName, foodType;
    double foodPrice;

    cout << "\n\n\n\n\n" << endl;
    cout << "\n" << setw(69) << "Enter the Food Code  : ";
    getline(cin, foodCode);
    food.setFoodCode(foodCode);

    cout << "\n" << setw(69) << "Enter the Food Name  : ";
    getline(cin, foodName);
    food.setFoodName(foodName);

    cout << "\n" << setw(69) << "Enter the Food Type  : ";
    food.setFoodType();

    cout << "\n\n" << setw(72) << "Enter the Food Price : RM ";
    cin >> foodPrice;
    food.setFoodPrice(foodPrice);

    ofstream file("food.csv", ofstream::out | ofstream::app);
    file << food.getFoodCode() << ',' << food.getFoodName() << ','  << food.getFoodType() << ','  << food.getFoodPrice() << endl;
    file.close();

    cout << "\n\n\n" << setw(75) << "Food Successfully Added !!!" << endl;
    cout << "\n\n\t\t\t\t\t     ";
    system("pause");
}


