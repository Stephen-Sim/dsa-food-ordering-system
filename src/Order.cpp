#include "Order.h"
#include "Customer.h"
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

Order::Order()
{
    //ctor
    vector <Order> order;
    this->orderScreen(order);
}

Order::~Order()
{
    //dtor
}

void Order::orderScreen(vector <Order> & order)
{
    system("cls");
    unsigned char opt = 0;
    int current = 1;

    cout << "\n\t\t\t\t1. Add Order\t\t2. Pay\t\t3. Back" << endl;

    if(order.size() != 0)
    {
        cout << "\n\t\t" << setfill('-') << setw(85) << "\n";
        cout << "\t\t|" << setfill(' ') << setw(5) << "Bil" << " |";
        cout << setfill(' ') << setw(18) << "Food Name" << " |";
        cout << setfill(' ') << setw(10) << "Quantiy" << " |";
        cout << setfill(' ') << setw(14) << "Food Type" << " |";
        cout << setfill(' ') << setw(11) << "Price" << " |";
        cout << setfill(' ') << setw(13) << "Total Price" << " |";
        cout << "\n\t\t" << setfill('-') << setw(85) << "\n";

        for(int i = 0; i < order.size(); i++)
        {

        }
    }

    cout << endl << setfill(' ') << setw(60) << "> 1";
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


    if(current == 1){
        // add order
        this->addOrder(order);
    }
    else if(current == 2)
    {
        // pay order
    }
    else if(current == 3){
        // back
        Customer::cusMenu();
    }
}

string getFoodType()
{
    unsigned char ch = 0;

    string foodType = "food";

    cout << " food";

    while((ch = getch())!= RETURN)
    {
        if(ch == 72)
        {
            if(foodType == "drink"){
                cout << "\b\b\b\b\b";
                foodType = "food";
                cout << " food";
            }

        }
        else if(ch == 80)
        {
            if(foodType == "food"){
                cout << "\b\b\b\b\b";
                foodType = "drink";
                cout << "drink";
            }
        }
    }

    return foodType;
}

void Order::addOrder(vector <Order> & order)
{
    system("cls");

    cout << "Move Arrow Key Up to select Food, Down to Select Drink";
    Food food;
    string foodCode, foodName, foodType;
    double foodPrice;

    cout << "\n\n\n\n\n" << endl;

    cout << "\n" << setw(69) << "Choose the Food Type  : ";
    foodType = getFoodType();


    cout << "\n\n" << setw(69) << "Choose the Food       : ";

    vector <Food> foods = Food::getFoodFromFile();

    if(foodType == "drink")
    {

    }
    else if(foodType == "food")
    {

    }

    cout << "\n\n\n" << setw(75) << "Order Successfully Added !!!" << endl;
    cout << "\n\n\t\t\t\t\t     ";
    system("pause");
}

void displayFoodByType(vector<Food>, string foodType)
{

}
