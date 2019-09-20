//faculty.h
#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include <string>
using namespace std;

class Faculty: public Person
{
  friend class University;
 private:
  float salary;
  int yearOfExp;
  long departId;
  static long nextFacultyId;
 public:
  Faculty();
  Faculty(float sal, int exp, long depId, string n, string e, string a, string d, string g);
};

#endif
