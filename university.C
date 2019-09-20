//university.C
#include <fstream>
#include "university.h"
using namespace std;

bool University::failure;
bool University::success;

University::University()
{

}

University::~University()
{

}

//This function will create a department if it does not exist
bool University::CreateNewDepartment(string depName, string depLoc, long depChairId)
{
  if(((depChairId != 0) && (!depChairExist(depChairId))))
    {
      cout << "The chair with id " << depChairId << " does not exits" << endl;
      return failure;
    }
  Department D(depLoc, depChairId, depName);
  Departments.push_back(D);
  return success;
}

//This function will check if a department chair exist
bool University::depChairExist(long depChairId)
{
  vector<Faculty> Faculties;

  for(int i = 0; i < Faculties.size(); i++)
    {
      if(Faculties[i].id == depChairId)
	return success;
    }
  return failure;
}

//This function will create a student if its major and advisor exist
bool University::CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender,int sYearOfStudy, string sMajor, long sAdvisorId)
{
  bool found = false;
  for(int i=0; !found && i < Departments.size(); i++)
     {
	if(Departments[i].name == sMajor)
	  {
	    found = true;
	  }
     }
  if(found = false)
    {
      cout << "The major " << sMajor << " does not exist" << endl;
      return failure;
    }

  found = false;
  if(sAdvisorId != 0)
    {
      for(int a=0; !found && a < Faculties.size(); a++)
	{
	  if(Faculties[a].id == sAdvisorId)
	    found = true;
	}
      if(found == false)
      {
        cout << "The Advisor id " << sAdvisorId << " does not exist" << endl;
	cout << "----------------------------------" << endl;
	return failure;
      }
    }

  Student Stu(sYearOfStudy, sMajor, sAdvisorId, sName, sEmail, sAddress, sDateOfBirth, sGender);
  Students.push_back(Stu);
  return success;
}

//This function will create a course if the faculty exist
bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
  bool found = false;
  if(cTaughtBy != 0)
    {
      for(int i = 0; !found && i < Faculties.size(); i++)
	{
	  if(Faculties[i].id == cTaughtBy)
	    found = true;
        }  
  if(found == false)
    {
      cout << "Faculty Id " << cTaughtBy << " does not exist" << endl;
      return failure;
    } 
    }
   
  found = false;
  for(int a=0; !found && a < Departments.size(); a++)
    {
      if(cDepId == Departments[a].id)
	found = true;
    }
  if(found == false)
    {
      cout << "The department does not exist" << endl;
      return failure;
    }

  Course cou(cMaxSeat, cName, cDepId, cTaughtBy);
  Courses.push_back(cou);
  return success;
}

//This function will create a new faculty if its department exist
bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender,float fSalary, int fYearOfExp, long fDepId)
{
 
  bool found = false;
  for(int i=0; !found && i < Departments.size(); i++)
    {
      if(Departments[i].id == fDepId)
	found = true;
    }
  if(found = false)
    {
      cout << "The department does not exist" << endl;
      return failure;
    }

  Faculty fa(fSalary, fYearOfExp, fDepId, fName, fEmail, fAddress, fDateOfBirth, fGender);
  Faculties.push_back(fa);
  return success;
}

//This function will show the courses taught by a faculty if the faculty exist
bool University::ListCoursesTaughtByFaculty(long facultyId)
{
  for(int i=0; i < Faculties.size(); i++)
    {
      if(Faculties[i].id == facultyId)
	{
	  cout << Faculties[0].name << " is teaching: " << endl;
	  for(int a=0; a < Courses.size(); a++)
	    {
	      if(Courses[a].isTaughtBy == facultyId)
		{
		  cout << "Course Name: " << Courses[a].name << ". Course Id: " << Courses[a].CRN << endl; 
		}
	    }
	  cout << "******************************************" << endl;
	  return success;
	}
    }
  cout << "Faculty id " << facultyId << " does not exist" << endl;
  cout << "--------------------------------" << endl;
  return failure;
}

//This function will show the courses taken by a student if the student exist
bool University::ListCoursesTakenByStudent(long studentId)
{
  for(int i=0; i < Students.size(); i++)
    {
      if(Students[i].id == studentId)
	{
	  cout << Students[i].name << " has taken:" << endl;
	  for(int a=0; a < Students[i].coursesTaken.size(); a++)
	    {
	      cout << "Course Name: " << Students[i].coursesTaken[a].name << ". Course ID: " <<  Students[i].coursesTaken[a].CRN << endl;
	    }
	  cout << "******************************************" << endl;
	  return success;
	}
    }
  cout << "Student id " << studentId << " does not exist" << endl;
  return failure;
}

//This function will show the faculties in a department if the department exist
bool University::ListFacultiesInDepartment(long departId)
{
  for(int i =0; i < Departments.size(); i++)
    {
      if(Departments[i].id == departId)
	{
	  cout << "Faculties in " << Departments[i].name << " department:" << endl;
	  for(int a=0; a < Faculties.size(); a++)
	    {
	      if(Faculties[a].departId == departId)
		{
	      cout << "Faculty name: " << Faculties[a].name << ". Faculty ID: " << Faculties[a].id << endl;
		}	    
	    }
	  cout << "******************************************" << endl;
	  return success;
	}
    }
  cout << "Department id " << departId << " does not exist" << endl;
  cout << "----------------------------------" << endl;
  return failure;
}

//This function will show the students of a faculy if the faculty exist
bool University::ListStudentsOfAFaculty(long facultyId)
{
  for(int i=0; i < Faculties.size(); i++)
    {
      if(Faculties[i].id == facultyId)
	{
	  cout << "Students on faculty " << Faculties[i].name << endl;
	  for(int a=0; a < Students.size(); a++)
	    {
	      cout << "Student name: " << Students[a].name << ". Student ID: " << Students[a].id << endl;
	    }
	  cout << "******************************************" << endl;
	  return success;
	}
    }
  cout << "Faculty id " << facultyId << " does not exist" << endl;
  cout << "-----------------------------------" << endl;
  return failure;
}

//This function will show the courses of a department if the department exist
bool University::ListCoursesOfADepartment(long departId)
{
  for(int i=0; i < Departments.size(); i++)
    {
      if(Departments[i].id == departId)
	{
	  cout << "Courses in " << Departments[i].name << " department: " << endl;
	  for(int a=0; a < Courses.size(); a++)
	    {
	      if(Courses[a].departId == departId)
		{
		  cout << "Course Name: " << Courses[a].name << ". Course ID: " << Courses[a].CRN << endl;
		}
	    }
	  cout << "******************************************" << endl;
	  return success;
	} 
    }
  cout << "Department id " << departId << " does not exist" << endl;
  cout << "--------------------------------" << endl;
  return failure;
}

//This function will add a course to a student if the course and student exist
bool University::AddACourseForAStudent(long courseId, long stId)
{
  bool found = false;
  int c;
  for(c = 0; !found && c < Courses.size(); c++)
    {
      if(Courses[c].CRN == courseId)
	{
	  if(Courses[c].assignedSeats >= Courses[c].maxAvaliableSeats)
	    {
	      cout << "Course " << Courses[c].name << " has full seats" << endl;
	      return failure;
	    }
	  else
	    found = true;
	}
    }
  if(found == false)
    {
      cout << "The Courss Id " << courseId << " does not exist" << endl;
      cout << "--------------------------------" << endl;
      return failure;
    }
  for(int s = 0; s < Students.size(); s++)
    {
      if(Students[s].id == stId)
	{
	  Students[s].coursesTaken.push_back(Courses[c]);
	  return success;
	}
    }
  cout << "Student Id " << stId << " does not exist" << endl;
  cout << "----------------------------------" << endl; 
  return failure;
}

//This function will assign a department chair to a faculty if the department and faculty exist
bool University::AssignDepartmentChair(long facultyId, long departId)
{
  for(int f=0; f < Faculties.size(); f++)
    {
      if(Faculties[f].id == facultyId)
	{
	  for(int d=0; d < Departments.size(); d++)
	    {
	      if(Departments[d].id == departId)
		{
		  Departments[d].chairId = Faculties[f].id;
		  return success;
		}
	    }
	  cout << "Department ID " << departId << " does not exist" << endl;
	  cout << "------------------------------" << endl;
	  return failure;
	}
    }
  cout << "Faculty ID " << facultyId << " does not exist" << endl;
  cout << "--------------------------------" << endl;
  return failure;
}

//This function will assign a course to a faculty if the course and faculty exist
bool University::AssignInstructorToCourse(long facultyId, long courseId)
{
  for(int f=0; f < Faculties.size(); f++)
    {
      if(Faculties[f].id == facultyId)
	{
	  for(int c=0; c < Courses.size(); c++)
	    {
	      if(Courses[c].CRN == courseId)
		{
		  Courses[c].isTaughtBy = Faculties[f].id;
		  return success;
		}
	    }
	  cout << "Course ID " << courseId << " does not exist" << endl;
	  return failure;
	}
    }
  cout << "Faculty ID " << facultyId << " does not exist" << endl;
  return failure;
}

//This function will show all the departments
bool University::ListDepartments()
{
  for(int i=0; i < Departments.size(); i++)
    {
      cout << "Department name: " <<  Departments[i].name << ". Department ID: " << Departments[i].id << endl;
    }
  cout << "******************************************" << endl;
  return success;
}

//This function will show all the students
bool University::ListStudents()
{
  for(int i=0; i < Students.size(); i++)
    {
      cout << "Student name: " << Students[i].name << ". Student ID: " << Students[i].id << endl;
    }
  cout << "******************************************" << endl;
  return success;
}

//This function will show all the courses
bool University::ListCourses()
{
  for(int i=0; i < Courses.size(); i++)
    {
      cout << "Course name: " << Courses[i].name << ". Course ID: " << Courses[i].CRN << endl;
    }
  cout << "******************************************" << endl;
  return success;
}

//This function will show all the faculties
bool University::ListFaculties()
{
  for(int i=0; i < Faculties.size(); i++)
    {
      cout << "Faculty name: " << Faculties[i].name << ". Faculty ID: " << Faculties[i].id << endl;
    }
  cout << "******************************************" << endl;
}

//This function will open a file and call another function to do something if the file exist
bool University::ProcessTransactionFile(string fileName)
{
  ifstream fin;
  string word;
  string word2;
  string word3;
  string word4;
  string word5;
  string word6;
  int intNum;
  long longNum;
  long longNum2;
  float floatNum;

  fin.open(fileName.data());
  if(!fin)
    {
      cout << fileName << " file does not exist" << endl;
      return failure;
    }
  else
    {
      while(fin)
	{
	  fin >> word;
	  if(word == "CreateNewDepartment")
	    {
	      fin >> word;
	      fin >> word2;
	      fin >> longNum;
	      CreateNewDepartment(word, word2, longNum);
	    }
	  else if(word == "CreateNewStudent")
	    {
	      fin >> word;
	      fin >> word2;
	      fin >> word3;
	      fin >> word4;
	      fin >> word5;
	      fin >> intNum;
	      fin >> word6;
	      fin >> longNum;
	      CreateNewStudent(word, word2, word3, word4, word5, intNum, word6, longNum);
	    }
	  else if(word == "CreateNewCourse")
	    {
	      fin >> word;
	      fin >> longNum;
	      fin >> longNum2;
	      fin >> intNum;
	      CreateNewCourse(word, longNum, longNum2, intNum);
	    }
	  else if(word == "CreateNewFaculty")
	    {
	      fin >> word;
	      fin >> word2;
	      fin >> word3;
	      fin >> word4;
	      fin >> word5;
	      fin >> floatNum;
	      fin >> intNum;
	      fin >> longNum;
	      CreateNewFaculty(word, word2, word3, word4, word5, floatNum, intNum, longNum);
	    }
	 
	  else if(word == "ListCoursesTaughtByFaculty")
	    {
	      fin >> longNum;
	      ListCoursesTaughtByFaculty(longNum);
	    }
	  
	  else if(word == "ListCoursesTakenByStudent")
	    {
	      fin >> longNum;
	      ListCoursesTakenByStudent(longNum);
	    }
	  else if(word == "ListFacultiesInDepartment")
	    {
	      fin >> longNum;
	      ListFacultiesInDepartment(longNum);
	    }
	  else if(word == "ListStudentsOfAFaculty")
	    {
	      fin >> longNum;
	      ListStudentsOfAFaculty(longNum);
	    }
	  else if(word == "ListCoursesOfADepartment")
	    {
	      fin >> longNum;
	      ListCoursesOfADepartment(longNum);
	    }
	  else if(word == "AddACourseForAStudent")
	    {
	      fin >> longNum;
	      fin >> longNum2;
	      AddACourseForAStudent(longNum, longNum2);
	    }
	  else if(word == "AssignDepartmentChair")
	    {
	      fin >> longNum;
	      fin >> longNum2;
	      AssignDepartmentChair(longNum, longNum2);
	    }
	  else if(word == "AssignInstructorToCourse")
	    {
	      fin >> longNum;
	      fin >> longNum2;
	      AssignInstructorToCourse(longNum, longNum2);
	    }
	  else if(word == "ListDepartments")
	    {
	      ListDepartments();
	    }
	  else if(word == "ListStudents")
	    {
	      ListStudents();
	    }
	  else if(word == "ListCourses")
	    {
	      ListCourses();
	    }
	  else if(word == "ListFaculties")
	    {
	      ListFaculties();
	    }
	}
    }
}

