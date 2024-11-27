#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "Food.h"

using std::string;

class Admin
{
public:
    Admin();
    virtual ~Admin();
    string getPass(bool);
    static void adminAction(int);
    static void adminMenu();
    void adminLogin();
    static void addFood(vector<Food>&);

protected:

private:
    const string ADMIN_USERNAME = "admin";
    const string ADMIN_PWD = "abc123";
};

#endif // ADMIN_H
