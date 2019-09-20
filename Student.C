//Student.C

#include "Student.h"
#include <iostream>

using namespace std;

long Student::nextStId = 500;

Student::Student():Person()
{
  yearOfStudy = 0;
  major = "SPACE";
  advisorId = 0;
  nextStId++;
}

Student::Student(int year, string m, long adv, string n, string e, string a, string d, string g):Person(nextStId, n, e, a, d, g)
{
  yearOfStudy = year;
  major = m;
  advisorId = adv;
  nextStId++;
}

