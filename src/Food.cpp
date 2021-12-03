#include "Food.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

Food::Food()
{
    //ctor
}

Food::~Food()
{
    //dtor
}

Food::Food(string foodCode, string foodName, string foodType, double foodPrice)
{
    this->foodCode  = foodCode;
    this->foodName  = foodName;
    this->foodType  = foodType;
    this->foodPrice = foodPrice;
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

void Food::displayFood()
{
    system("cls");

    cout << "\n\n\t\t\t\t1. Sort Food\t\t2. Search Food\t\t3. Back" << endl;

    vector <Food> foodList = Food::getFoodFromFile();
    Food::getFoodDataTable(foodList);
}

vector <Food> Food::getFoodFromFile()
{
    ifstream  inputFood("food.csv" , ios::in);
    vector <Food> foodList;
    vector <string> row;
    string foodCode, foodName, foodType, temp, word;
    double foodPrice;
    if (inputFood.is_open())
    {
        while(getline(inputFood, temp))
        {
            row.clear();
            stringstream s(temp);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            foodCode    =   row[0];
            foodName    =   row[1];
            foodType    =   row[2];
            foodPrice   =   stof(row[3]);

            Food food(foodCode, foodName, foodType, foodPrice);

            foodList.push_back(food);
        }

        inputFood.close();
    }
    else
        cout << "Unable to open file";

    return foodList;
}

void Food::getFoodDataTable(vector <Food> foodList)
{

}


