//Person.C

#include <iostream>
#include "Person.h"
using namespace std;

Person::Person()
{
  id = 0;
  name = "SPACE";
  email = "SPACE";
  address = "SPACE";
  dateOfBirth = "SPACE";
  gender = "SPACE";
}

Person::Person(long i, string n, string e, string a, string d, string g)
{
  id = i;
  name = n;
  email = e;
  address = a;
  dateOfBirth = d;
  gender = g;
}

