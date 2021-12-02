#ifndef ADMIN_H
#define ADMIN_H

#include <string>

using std::string;

class Admin
{
    public:
        Admin();
        virtual ~Admin();
        string getpass(bool);
        void adminAction(int);
        int adminMenu();
        void adminLogin();
        void addFood();

    protected:

    private:
        const string ADMIN_USERNAME = "admin";
        const string ADMIN_PWD = "abc123";
};

#endif // ADMIN_H
