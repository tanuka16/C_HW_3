#include "Depositer.h"

Depositer::Depositer()
{
    name = Name();
    ssn = 0;
}

Depositer::Depositer(Name n, int s)
{
    name = n;
    ssn = s;
}

Name Depositer::getName() { return name; }
double Depositer::getSSN() { return ssn; }

