#ifndef ORDER_H
#define ORDER_H

#include "Food.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class Order
{
    public:
        Order();
        virtual ~Order();

        void orderScreen(vector<Order>&);
        void addOrder(vector<Order>&);
        vector <Food> getFoodByType(vector<Food>, string);
        Food selectOrderFood(vector<Food>);

    protected:

    private:
        vector <Food> food;
        int quantity;
        double totalAmount;
};

#endif // ORDER_H
