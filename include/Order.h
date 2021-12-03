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
        Order(Food, int, double);
        virtual ~Order();

        void orderScreen(vector<Order>&);
        void addOrder(vector<Order>&);
        vector <Food> getFoodByType(vector<Food>, string);
        Food selectOrderFood(vector<Food>);
        int getOrderQuantity();
        int getQuantity();
        double getTotalAmount();
        void confirmOrder(vector<Order> &);

        Food food;

    protected:

    private:
        int quantity;
        double totalAmount;
};

#endif // ORDER_H
