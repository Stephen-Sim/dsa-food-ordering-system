#ifndef FOOD_H
#define FOOD_H

#include <string>
using std::string;

class Food
{
    public:
        Food();
        virtual ~Food();
        void setFoodCode(string);
        void setFoodName(string);
        void setFoodType();
        void setFoodPrice(double);

    protected:

    private:
        string foodCode;
        string foodName;
        double foodPrice;
        const string foodTypeList[2] = {"Food", "Drink"};
        string foodType;

};

#endif // FOOD_H
