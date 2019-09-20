//Course.h
#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course
{
  friend class University;
 private:
  long CRN;
  int maxAvaliableSeats;
  string name;
  long departId;
  long assignedSeats;
  long isTaughtBy;
  static long nextCRN;
 public:
  Course();
  Course(int avaSeats, string n, long id, long taught);
};

#endif
