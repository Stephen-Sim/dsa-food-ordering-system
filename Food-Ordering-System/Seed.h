#ifndef SEED_H
#define SEED_H

#include <vector>
#include "Food.h"

class Seed
{
public:
    Seed();
    virtual ~Seed();

protected:

private:
    vector <Food> seedData;
};

#endif // SEED_H
