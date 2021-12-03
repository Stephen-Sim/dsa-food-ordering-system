#include "Seed.h"
#include <fstream>
#include <vector>
#include "Food.h"

#include <iostream>
using namespace std;


Seed::Seed()
{
    //ctor
    seedData.push_back(Food("FO103", "Nasi Kerabu", "food", 7.5));
    seedData.push_back(Food("FO101", "Sarawak Laksa", "food", 5.5));
    seedData.push_back(Food("DR102", "Kopi", "drink", 2));
    seedData.push_back(Food("FO102", "Mee Goreng Mamak", "food", 5.5));
    seedData.push_back(Food("FO106", "Roti John", "food", 5));
    seedData.push_back(Food("FO105", "Nasi Lemak", "food", 4));
    seedData.push_back(Food("FO104", "Nasi Kandar", "food", 7));
    seedData.push_back(Food("DR103", "Cendol", "drink", 3));
    seedData.push_back(Food("DR101", "Teh O Ais", "drink", 1.2));
    seedData.push_back(Food("DR104", "Milo", "drink", 2));
    seedData.push_back(Food("FO106", "Nasi Ayam", "food", 5));

    ofstream file("food.csv", ofstream::out);

    for(int i = 0; i < seedData.size(); i++)
    {
        file << seedData[i].getFoodCode() << ',' << seedData[i].getFoodName() << ','  << seedData[i].getFoodType() << ','  << seedData[i].getFoodPrice() << endl;
    }
    file.close();
}

Seed::~Seed()
{
    //dtor
}
