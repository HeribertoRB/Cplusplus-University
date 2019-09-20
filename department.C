//department.C

#include "department.h"
#include <iostream>
using namespace std;

long Department::depId = 100;

Department::Department()
{
  id = depId++;
  name = location = "SPACE";
  chairId = 0;
}

Department::Department(string depLoc, long depChairId, string depName)
{
  id = depId++;
  name = depName;
  chairId = depChairId;
  location = depLoc;
}

