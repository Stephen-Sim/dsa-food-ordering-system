#ifndef FOOD_H
#define FOOD_H

#include <string>
using std::string;

class Food
{
    public:
        Food();
        // Food(string, string, string, double);
        virtual ~Food();

    protected:

    private:
        string foodId;
        string foodName;
        double foodPrice;
        const string foodType[2] = {"Food", "Drink"};

};

#endif // FOOD_H
