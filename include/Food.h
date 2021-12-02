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

        string getFoodCode();
        string getFoodName();
        string getFoodType();
        double getFoodPrice();

    protected:

    private:
        string foodCode;
        string foodName;
        double foodPrice;
        string foodType;

};

#endif // FOOD_H
