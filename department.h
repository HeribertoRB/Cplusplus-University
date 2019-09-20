//department.h
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
using namespace std;

class Department
{
  friend class University;
 private:
  long id;
  string name;
  string location;
  long chairId;
  static long depId;
 public:
  Department();
  Department(string depLoc, long depChairId, string depName);
};

#endif
