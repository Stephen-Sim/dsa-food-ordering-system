#ifndef MENU_H
#define MENU_H

class Menu
{
public:
    Menu();
    virtual ~Menu();
    static int selectUser();
    static void exitPage();
    static void userAction(int);

protected:

private:
};

#endif // MENU_H
