#include "Name.h"

#ifndef DEPOSITER_H
#define DEPOSITER_H


class Depositer
{
    private:
        Name name;
        double ssn;

    public:
        Depositer();
        Depositer(Name, int);

        Name getName();
        double getSSN();


};

#endif // DEPOSITER_H
