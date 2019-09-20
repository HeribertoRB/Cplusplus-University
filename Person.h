//Person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
  friend class University;
 protected:
  long id;
  string name;
  string email;
  string address;
  string dateOfBirth;
  string gender;
 public:
  Person();
  Person(long i, string n, string e, string a, string d, string g);
};

#endif
