#pragma once
#include "stdafx.h"
#include "student.h"
#include "global.h"
#include<string>
#include<vector> 
#include<algorithm>
#include<list>
#include<iterator>
using namespace std;

class Course
{
private:

	list<Student> nameList;
	list<Student>::iterator iterList;

	vector<Student> gradeVec;
	vector<Student>::iterator iterVec;

	int classSize;

	GRADE rawletterGrade(const double);
	GRADE percentletterGrade(const double);

public:
	Course()
	{
		classSize = 0;
	}

	void grabData();
	void setRank();
	void assignPointGrade();
	void assignCurveGrade();
	void assignLetterGrade();
	void displayGradeReport();
	static bool compare(Student &, Student &);

};
