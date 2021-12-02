#include "Food.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

Food::Food()
{
    //ctor
}

Food::~Food()
{
    //dtor
}


void Food::setFoodCode(string foodCode)
{
    this->foodCode = foodCode;
}

void Food::setFoodName(string foodName)
{
    this->foodName = foodName;
}

void Food::setFoodType()
{
    const char RETURN = 13;
    unsigned char ch = 0;

    string foodType = "food";

    cout << " food";

    while((ch = getch())!= RETURN)
    {
        if(ch == 72)
        {
            if(foodType == "Drink"){
                cout << "\b\b\b\b\b";
                foodType = "food";
                cout << " food";
            }

        }
        else if(ch == 80)
        {
            if(foodType == "Food"){
                cout << "\b\b\b\b\b";
                foodType = "drink";
                cout << "drink";
            }
        }
    }

    this->foodType = foodType;
}

void Food::setFoodPrice(double foodPrice)
{
    this->foodPrice = foodPrice;
}

string Food::getFoodCode()
{
    return this->foodCode;
}

string Food::getFoodName()
{
    return this->foodName;
}

string Food::getFoodType()
{
    return this->foodType;
}

double Food::getFoodPrice()
{
    return this->foodPrice;
}


