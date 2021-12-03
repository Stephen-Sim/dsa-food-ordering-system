#include "Food.h"
#include "Admin.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include <conio.h>
#include <windows.h>
#include <vector>

#define RETURN 13
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
    unsigned char opt = 0;
    int current = 1;
    int i = 1;

    vector <Food> foodList = Food::getFoodFromFile();
    Food::getFoodDataTable(foodList, i);

    while((opt = getch())!= RETURN){

        if(opt == 77) // move right
        {
            ++i;
            if(i * 10 > ceil(foodList.size()) + 10){
                i--;
            }

            Food::getFoodDataTable(foodList, i);
            continue;
        }
        else if(opt == 75) // move left
        {
            --i;
            if(i <= 0)
                i = 1;

            Food::getFoodDataTable(foodList, i);
            continue;
        }
        else if(opt == 72) // move up
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

    }
    else if(current == 2)
    {

    }
    else if(current == 3){
        Admin::adminMenu();
    }
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

#define iValue ((counter - 1) * 10)
#define dataTableSize i < foodList.size() && i < counter * 10

void Food::getFoodDataTable(vector <Food> foodList, int counter)
{
    system("cls");
    cout << "\n\n\t\t\t\t1. Sort Food\t\t2. Search Food\t\t3. Back" << endl;
    cout << fixed;
    // table header
    cout << "\n\t\t" << setfill('-') << setw(85) << "\n";
    cout << "\t\t|" << setfill(' ') << setw(5) << "Bil" << " |";
    cout << setfill(' ') << setw(13) << "Food Code" << " |";
    cout << setfill(' ') << setw(25) << "Food Name" << " |";
    cout << setfill(' ') << setw(15) << "Food Type" << " |";
    cout << setfill(' ') << setw(15) << "Price" << " |";
    cout << "\n\t\t" << setfill('-') << setw(85) << "\n";

    for(int i = iValue; dataTableSize; i++)
    {
        cout << "\t\t|" << setfill(' ') << setw(5) << i + 1 << " |";
        cout << setfill(' ') << setw(13) << foodList[i].foodCode << " |";
        cout << setfill(' ') << setw(25) << foodList[i].foodName << " |";
        cout << setfill(' ') << setw(15) << foodList[i].foodType << " |";
        cout << setfill(' ') << setw(15) << setprecision(2) << foodList[i].foodPrice << " |";
        cout << "\n\t\t" << setfill('-') << setw(85) << "\n";
    }

    cout << endl << setfill(' ') << setw(60) << "> 1";
}


