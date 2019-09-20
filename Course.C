//Course.C

#include "Course.h"
#include <iostream>
using namespace std;

long Course::nextCRN = 200;

Course::Course()
{
  CRN = nextCRN++;
  maxAvaliableSeats = 0;
  name = "SPACE";
  departId = assignedSeats = isTaughtBy = 0;
}

Course::Course(int avaSeats, string n, long id, long taught)
{
  assignedSeats = 0;
  CRN = nextCRN++;
  maxAvaliableSeats = avaSeats;
  name = n;
  departId = id;
  isTaughtBy = taught;
}
