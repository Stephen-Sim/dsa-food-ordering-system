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
        void adminMenu();
        void adminLogin();

    protected:

    private:
        const string ADMIN_USERNAME = "admin";
        const string ADMIN_PWD = "abc123";
};

#endif // ADMIN_H
