#include "Name.h"

Name::Name()
{
    fname = "";
    lname = "";
}
Name::Name(string first, string last)
{
    fname = first;
    lname = last;
}

string Name::getFullName() { return getFirstName() + " " + getLastName(); }
string Name::getFirstName(){ return fname; }
string Name::getLastName() { return lname; }
