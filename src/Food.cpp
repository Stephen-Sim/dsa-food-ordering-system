#include "Food.h"
#include "Admin.h"
#include "Customer.h"
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

vector <Food> Food::foodList = Food::sortFood(Food::getFoodFromFile());

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



void Food::displayFood(char currentUser, vector <Food> & foodList)
{
    system("cls");
    unsigned char opt = 0;
    int current = 1;
    int i = 1;

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

        if(opt == 72) // move down
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
        Food::displaySort(foodList, currentUser, 1, true);
    }
    else if(current == 2)
    {
        Food::searchMenu(foodList);
        Food::displayFood(currentUser, foodList);
    }
    else if(current == 3){
        if(currentUser == 'a')
        {
            Admin::adminMenu();
        }
        else
        {
            Customer::cusMenu();
        }
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

void Food::sortFoodDataTable(vector <Food> foodList, int counter, int current)
{
    system("cls");
    cout << "\n\n\t\t1. Sort By Name\t\t2. Search By Type\t3. Search By Price\t    4. Back" << endl;
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

    cout << endl << setfill(' ') << setw(60) << "> " << current;
}

void Food::swapValue(vector <Food> & foodList, int i, int j, int x = 0)
{
    if (foodList[i].getFoodName()[x] > foodList[j].getFoodName()[x])
    {
        Food temp(foodList[i].getFoodCode(), foodList[i].getFoodName(), foodList[i].getFoodType(), foodList[i].getFoodPrice());
        foodList[i] = foodList[j];
        foodList[j] = temp;
    }
    else if(foodList[i].getFoodName()[x] == foodList[j].getFoodName()[x])
    {
        swapValue(foodList, i, j, x + 1);
    }
}

vector <Food> Food::sortFood(vector <Food> foodList)
{
    for (int i = 0; i < foodList.size(); i++)
    {
        for(int j = i + 1; j < foodList.size(); j++)
        {
            swapValue(foodList, i, j);
        }
    }

    return foodList;
}

void Food::sortByName(vector <Food> & foodList)
{
    for (int i = 0; i < foodList.size(); i++)
    {
        for(int j = i + 1; j < foodList.size(); j++)
        {
            swapValue(foodList, i, j);
        }
    }
}

void Food::sortByType(vector <Food> & foodList)
{
    for (int i = 0; i < foodList.size(); i++)
    {
        for(int j = i + 1; j < foodList.size(); j++)
        {
            if (foodList[i].getFoodType() > foodList[j].getFoodType())
            {
                Food temp(foodList[i].getFoodCode(), foodList[i].getFoodName(), foodList[i].getFoodType(), foodList[i].getFoodPrice());
                foodList[i] = foodList[j];
                foodList[j] = temp;
            }
        }
    }
}

void Food::sortByPrice(vector <Food> & foodList)
{
    for (int i = 0; i < foodList.size(); i++)
    {
        for(int j = i + 1; j < foodList.size(); j++)
        {
            if (foodList[i].getFoodPrice() > foodList[j].getFoodPrice())
            {
                Food temp(foodList[i].getFoodCode(), foodList[i].getFoodName(), foodList[i].getFoodType(), foodList[i].getFoodPrice());
                foodList[i] = foodList[j];
                foodList[j] = temp;
            }
        }
    }
}

void Food::displaySort(vector <Food> & foodList, char currentUser, int current, bool isTrue)
{
    unsigned char opt = 0; int i = 1;

    if(isTrue == true)
    {
        Food::sortFoodDataTable(foodList, i, current);
    }

    while((opt = getch())!= RETURN){

        if(opt == 77) // move right
        {
            ++i;
            if(i * 10 > ceil(foodList.size()) + 10){
                i--;
            }

            Food::sortFoodDataTable(foodList, i, current);
            continue;
        }
        else if(opt == 75) // move left
        {
            --i;
            if(i <= 0)
                i = 1;

            Food::sortFoodDataTable(foodList, i, current);
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
            if(current < 4){
                cout << "\b \b";
                cout << ++current;
            }
        }

        fflush(stdin);
    }

    if(current == 1)
    {
        sortByName(foodList);
        Food::sortFoodDataTable(foodList, i, current);
        Food::displaySort(foodList, currentUser, current, false);
    }
    else if(current == 2)
    {
        sortByType(foodList);
        Food::sortFoodDataTable(foodList, i, current);
        Food::displaySort(foodList, currentUser, current, false);
    }
    else if(current == 3)
    {
        sortByPrice(foodList);
        Food::sortFoodDataTable(foodList, i, current);
        Food::displaySort(foodList, currentUser, current, false);
    }
    else if(current == 4){
        Food::displayFood(currentUser, foodList);
    }
}

void Food::searchMenu(vector <Food> foodList)
{
    system("cls");
    bool isTrue = false;
    string foodName;
    cout << "\n\n\n\tEnter Food By Name : ";
    getline(cin, foodName);

    Food result = Food::binarySearch(foodList, foodName, isTrue);

    if(isTrue)
    {
        cout << "\n\n\n\n\t\t" << setfill('-') << setw(85) << "\n";
        cout << "\t\t|" << setfill(' ') << setw(5) << "Bil" << " |";
        cout << setfill(' ') << setw(13) << "Food Code" << " |";
        cout << setfill(' ') << setw(25) << "Food Name" << " |";
        cout << setfill(' ') << setw(15) << "Food Type" << " |";
        cout << setfill(' ') << setw(15) << "Price" << " |";
        cout << "\n\t\t" << setfill('-') << setw(85) << "\n";

        cout << "\t\t|" << setfill(' ') << setw(5) << 1 << " |";
        cout << setfill(' ') << setw(13) << result.getFoodCode() << " |";
        cout << setfill(' ') << setw(25) << result.getFoodName() << " |";
        cout << setfill(' ') << setw(15) << result.getFoodType() << " |";
        cout << setfill(' ') << setw(15) << setprecision(2) << result.getFoodPrice() << " |";
        cout << "\n\t\t" << setfill('-') << setw(85) << "\n";
    }
    else
    {
        cout << "\n\n\n\t\t" << setfill('-') << setw(85) << "\n";
        cout << "\t\t|" << setfill(' ') << setw(84) << " |\n";
        cout << "\t\t|" << setfill(' ') << setw(54) << "Record Not Found !!! " << setw(30) << "|\n";
        cout << "\t\t|" << setfill(' ') << setw(84) << " |\n";
        cout << "\t\t" << setfill('-') << setw(85) << "\n";
    }

    cout << "\n\n\n\n\t\t\t\t\t     ";
    system("pause");
}

Food Food::binarySearch(vector <Food> foodList, string foodName, bool &isTrue)
{
    sortByName(foodList);

    int low = 0, high = foodList.size() - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if (foodList[mid].getFoodName() == foodName)
        {
            isTrue = true;
            return foodList[mid];
        }

        int i = 0;
        while(i + 1)
        {
            if(i > foodList[mid].getFoodName().length() || i > foodList[mid].getFoodName().length())
            {
                break;
            }

            if(foodList[mid].getFoodName()[i] == foodName[i])
            {
                i++;
                continue;
            }

            if (foodList[mid].getFoodName()[i] < foodName[i])
                low = mid + 1;
            else
                high = mid - 1;

            break;
        }
    }

    Food food(" ", " ", " ", 0.0);

    return food;
}


