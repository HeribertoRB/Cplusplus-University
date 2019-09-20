//faculty.C

#include <iostream>
#include "faculty.h"
using namespace std;

long Faculty::nextFacultyId = 600;

Faculty::Faculty():Person()
{
  salary = 0;
  yearOfExp = 0;
  departId = 0; 
  nextFacultyId++;
}

Faculty::Faculty(float sal, int exp, long depId, string n, string e, string a, string d, string g):Person(nextFacultyId, n, e, a, d, g)
{
  salary = sal;
  yearOfExp = exp;
  departId = depId;
  nextFacultyId++;
}

