#include <iostream>
#include <sys/stat.h>
#include "Menu.h"
#include "Order.h"
#include "Seed.h"
using namespace std;

inline bool exists (const std::string& filename) {
  struct stat buffer;
  return (stat (filename.c_str(), &buffer) == 0);
}

int main()
{
    system("color 17");
    if(!exists("food.csv"))
    {
        Seed seed;
    }

    Menu menu;
    // Order order;
    return 0;
}
