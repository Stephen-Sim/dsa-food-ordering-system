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

Order::Order(Food food, int quantity, double totalAmount)
{
    this->food = food;
    this->quantity = quantity;
    this->totalAmount = totalAmount;
}

Order::~Order()
{
    //dtor
}

void Order::orderScreen(vector <Order>& order)
{
    cout << fixed;
    system("cls");
    unsigned char opt = 0;
    int current = 1;

    cout << "\n\t\t\t\t1. Add Order\t\t2. Confirm Order\t\t3. Back" << endl;

    if (order.size() != 0)
    {
        cout << "\n\t\t" << setfill('-') << setw(85) << "\n";
        cout << "\t\t|" << setfill(' ') << setw(5) << "Bil" << " |";
        cout << setfill(' ') << setw(18) << "Food Name" << " |";
        cout << setfill(' ') << setw(10) << "Quantity" << " |";
        cout << setfill(' ') << setw(14) << "Food Type" << " |";
        cout << setfill(' ') << setw(11) << "Price" << " |";
        cout << setfill(' ') << setw(13) << "Total Price" << " |";
        cout << "\n\t\t" << setfill('-') << setw(85) << "\n";

        double sum = 0;

        for (int i = 0; i < order.size(); i++)
        {
            cout << "\t\t|" << setfill(' ') << setw(5) << i + 1 << " |";
            cout << setfill(' ') << setw(18) << order[i].food.getFoodName() << " |";
            cout << setfill(' ') << setw(10) << order[i].getQuantity() << " |";
            cout << setfill(' ') << setw(14) << order[i].food.getFoodType() << " |";
            cout << setfill(' ') << setw(11) << setprecision(2) << order[i].food.getFoodPrice() << " |";
            cout << setfill(' ') << setw(13) << setprecision(2) << order[i].getTotalAmount() << " |";
            cout << "\n\t\t" << setfill('-') << setw(85) << "\n";

            sum += order[i].getTotalAmount();
        }
        cout << "\t\t|" << setfill(' ') << setw(50) << "Total Price: RM " << sum << setw(30) << "|\n";
        cout << "\t\t" << setfill('-') << setw(85) << "\n";
    }

    cout << endl << setfill(' ') << setw(60) << "> " << current;
    while ((opt = _getch()) != RETURN) {

        if (opt == 72) // move up
        {
            if (current > 1) {
                cout << "\b \b";
                cout << --current;
            }
        }
        else if (opt == 80) // move up
        {
            if (current < 3) {
                cout << "\b \b";
                cout << ++current;
            }
        }
        fflush(stdin);
    }


    if (current == 1) {
        // add order
        this->addOrder(order);
        this->orderScreen(order);
    }
    else if (current == 2)
    {
        // pay order
        this->confirmOrder(order);
        this->orderScreen(order);
    }
    else if (current == 3) {
        // back
        Customer::cusMenu();
    }
}

string Order::getFoodTypeFromUser()
{
    unsigned char ch = 0;

    string foodType = "food";

    cout << " food";

    while ((ch = _getch()) != RETURN)
    {
        if (ch == 72)
        {
            if (foodType == "drink") {
                cout << "\b\b\b\b\b";
                foodType = "food";
                cout << " food";
            }

        }
        else if (ch == 80)
        {
            if (foodType == "food") {
                cout << "\b\b\b\b\b";
                foodType = "drink";
                cout << "drink";
            }
        }
        fflush(stdin);
    }

    return foodType;
}

void Order::addOrder(vector <Order>& order)
{
    system("cls");

    cout << "Move Arrow Key Up to select Food, Down to Select Drink";
    string foodType; int quantity; double foodPrice, totalAmount;

    cout << "\n\n\n\n\n" << endl;

    cout << "\n" << setw(69) << "Choose the Food Type  : ";
    foodType = getFoodTypeFromUser();


    cout << "\n\n" << setw(69) << "Choose the Food       : ";

    vector <Food> foods = Food::getFoodFromFile();

    vector <Food> temps = this->getFoodByType(foods, foodType);

    Food selectedFood = this->selectOrderFood(temps);

    cout << "\n\n" << setw(69) << "Choose Food Quantity  : ";

    quantity = this->getOrderQuantity();
    foodPrice = selectedFood.getFoodPrice();
    totalAmount = quantity * foodPrice;

    Order o(selectedFood, quantity, totalAmount);

    order.push_back(o);

    cout << "\n\n\n" << setw(75) << "Order Successfully Added !!!" << endl;
    cout << "\n\n\t\t\t\t\t     ";
    system("pause");
}

vector <Food> Order::getFoodByType(vector<Food> foodList, string foodType)
{
    vector <Food> foods;

    for (int i = 0; i < foodList.size(); i++)
    {
        if (foodList[i].getFoodType() == foodType)
        {
            foods.push_back(foodList[i]);
        }
    }

    return foods;
}


Food Order::selectOrderFood(vector<Food> foodList)
{
    unsigned char ch = 0;
    int i = 0;
    cout << foodList[i].getFoodName();

    while ((ch = _getch()) != RETURN)
    {
        if (ch == 80) // move down
        {
            if (i < foodList.size() - 1)
            {
                for (int j = 0; j < foodList[i].getFoodName().size(); j++)
                {
                    cout << "\b \b";
                }

                i++;

                cout << foodList[i].getFoodName();
            }
        }
        else if (ch == 72) // move up
        {
            if (i > 0)
            {
                for (int j = 0; j < foodList[i].getFoodName().size(); j++)
                {
                    cout << "\b \b";
                }

                i--;

                cout << foodList[i].getFoodName();
            }
        }
        fflush(stdin);
    }

    return foodList[i];
}

int Order::getOrderQuantity()
{
    unsigned char ch = 0;
    int i = 1;
    cout << 1;

    while ((ch = _getch()) != RETURN)
    {
        if (ch == 80) // move down
        {
            if (i < 9)
            {
                cout << "\b \b";
                i++;
                cout << i;
            }
        }
        else if (ch == 72) // move up
        {
            if (i > 1)
            {
                cout << "\b \b";
                i--;
                cout << i;
            }
        }
        fflush(stdin);
    }

    return i;
}

int Order::getQuantity()
{
    return this->quantity;
}

double Order::getTotalAmount()
{
    return this->totalAmount;
}


void Order::confirmOrder(vector <Order>& order)
{
    if (order.size() > 0)
    {
        ofstream file("receipt.csv", ofstream::out);

        file << "Bil" << ',' << "Food Name" << ',' << "Quantity" << ',' << "Total Amount" << endl;
        double sum = 0;
        for (int i = 0; i < order.size(); i++)
        {
            file << i + 1 << ',' << order[i].food.getFoodName() << ',' << order[i].getQuantity() << ',' << order[i].getTotalAmount() << endl;
            sum += order[i].getTotalAmount();
        }

        file << ',' << ',' << "Total Amount(RM)" << ',' << sum << endl;

        file.close();

        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << endl << setw(71) << "Receipt Generated !!!";
        cout << "\n\n\n\n\t\t\t\t\t     ";
        system("pause");
        system("cls");
    }
    else {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << endl << setw(73) << "Opps, No Order Make !!!";
        cout << "\n\n\n\n\t\t\t\t\t     ";
        system("pause");
        system("cls");
    }

    order.clear();
}
