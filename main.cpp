#include "stdafx.h"
#include"student.h"
#include"course.h"
#include "global.h"

using namespace std;

int main() 
{
	Course c;

	c.grabData();  
	c.setRank();  
	c.assignPointGrade();  
	c.assignCurveGrade();  
	c.assignLetterGrade();  
	c.displayGradeReport();

	return 0;
}
