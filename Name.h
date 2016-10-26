#include <string>
using namespace std;

#ifndef NAME_H
#define NAME_H


class Name
{
    private:
        string fname, lname;
    public:
        Name();
        Name(string, string);

        string getFullName();
        string getFirstName();
        string getLastName();

};

#endif // NAME_H
