#ifndef FOOD_H
#define FOOD_H

#include <string>
#include <vector>
using std::string;
using std::vector;

class Food
{
    public:
        Food();
        virtual ~Food();
        Food(string, string, string, double);
        static vector <Food> foodList;
        void setFoodCode(string);
        void setFoodName(string);
        void setFoodType();
        void setFoodPrice(double);

        string getFoodCode();
        string getFoodName();
        string getFoodType();
        double getFoodPrice();

        static void displayFood(char);
        static void displayFood(char, vector<Food>&);
        static vector <Food> getFoodFromFile();
        static void getFoodDataTable(vector<Food>, int);
        static void sortFoodDataTable(vector<Food>, int, int);
        static void displaySort(vector <Food>&, char, int, bool);
        static vector <Food> sortFood(vector <Food> foodList);
        static void sortByName(vector<Food>&);
        static void sortByType(vector<Food>&);
        static void sortByPrice(vector<Food>&);
        static void swapValue(vector <Food>&, int, int, int);
        static void searchMenu(vector <Food>);
        static Food binarySearch(vector <Food>, string, bool&);

    protected:

    private:
        string foodCode;
        string foodName;
        string foodType;
        double foodPrice;

};

#endif // FOOD_H
