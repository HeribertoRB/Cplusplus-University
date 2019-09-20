//Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <vector>
#include "Course.h"
using namespace std;

class Student: public Person
{
  friend class University;
 private:
  int yearOfStudy;
  string major;
  long advisorId;
  vector<Course> coursesTaken;
  static long nextStId;
 public:
  Student();
  Student(int year, string m, long adv, string n, string e, string a, string d, string g);
};

#endif
