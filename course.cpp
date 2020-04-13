#include "stdafx.h"
#include "student.h"
#include "global.h"
#include"course.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector> 
#include<algorithm>
#include<list>
#include<iterator>
using namespace std;

bool Course::compare(Student & a, Student & b)
{
	return a > b;
};

GRADE Course::rawletterGrade(const double t)
{
	if (t > 93.0) return(A);
	else if (t > 90.0) return(AMINUS);
	else if (t > 87.0) return(BPLUS);
	else if (t > 83.0) return(B);
	else if (t > 80.0) return(BMINUS);
	else if (t > 77.0) return(CPLUS);
	else if (t > 73.0) return(C);
	else if (t > 67.0) return(CMINUS);
	else if (t > 60.0) return(D);
	else return(F);
};

GRADE Course::percentletterGrade(const double t)
{
	if (t > 0.9) return(A);
	else if (t > 0.75) return(AMINUS);
	else if (t > 0.6) return(BPLUS);
	else if (t > 0.45) return(B);
	else if (t > 0.35) return(BMINUS);
	else if (t > 0.25) return(CPLUS);
	else if (t > 0.15) return(C);
	else if (t > 0.05) return(D);
	else return(F);
};

void Course::grabData()
{
	Student sV, sL;
	string nF;
	string nL;
	double rS;

	ifstream infile("D:\\assign3class.dat");

	while (!infile.eof())
	{
		infile >> nL >> nF >> rS;
		sV.setLastName(nL);
		sV.setFirstName(nF);
		sV.setRawScore(rS);

		sL.setLastName(nL);
		sL.setFirstName(nF);
		sL.setRawScore(rS);

		classSize++;

		gradeVec.push_back(sV);
		nameList.push_back(sL);

	}

	gradeVec.shrink_to_fit();
}

void Course::setRank()
{
	sort(gradeVec.begin(), gradeVec.end(), compare);
};

void Course::assignPointGrade()
{
	int i;
	GRADE g;
	for (i = 0; i < classSize; i++)
	{

		g = rawletterGrade(gradeVec[i].getRawScore());
		gradeVec[i].setPointGrade(g);
	}
}

void Course::assignCurveGrade()
{
	int i;
	GRADE g1, g2;
	double rank = 0, s1, s2;

	iterVec = gradeVec.begin();

	for (i = 0; i < classSize; i++)
	{
		rank = (classSize - i - 1) / double(classSize);
		g1 = percentletterGrade(rank);
		s1 = iterVec->getRawScore();

		gradeVec[i].setCurveGrade(g1);

		if ((i > 0) && (s2 == s1))
			gradeVec[i].setCurveGrade(g2);
		else
		{
			g2 = g1;
			s2 = s1;
		}
		iterVec++;
	};
};


void Course::assignLetterGrade()
{
	int i;
	for (i = 0; i < classSize; i++) gradeVec[i].setLetterGrade();
}


void Course::displayGradeReport()
{
	int i;
	string g, nL1, nL2, nF1, nF2;
	ofstream outputFile;
	outputFile.open("D:\\report.dat");

	// find the same student stored both in nameList and score vector
	for (i = 0; i<classSize; i++)
	{
		iterList = nameList.begin();
		while (iterList != nameList.end())
		{
			nF1 = iterList->getFirstName();
			nF2 = gradeVec[i].getFirstName();
			nL1 = iterList->getLastName();
			nL2 = gradeVec[i].getLastName();

			if ((nL1 == nL2) && (nF1 == nF2))
			{
				g = gradeVec[i].getLetterGrade();
				iterList->setFinalGrade(g);
				break;
			};
			iterList++;
		};

	};

	outputFile << setw(60) << "Grade Report" << endl;

	outputFile.setf(ios::left);
	outputFile.setf(ios::fixed);


	outputFile << setw(30) << "First Name" << setw(30) << "Last Name" << setw(30) << "Raw Score" << setw(30) << "Letter Grade" << endl;
	outputFile << endl;

	for (iterList = nameList.begin(); iterList != nameList.end(); iterList++)
	{

		outputFile << setw(30) << iterList->getFirstName() << setw(30) <<iterList->getLastName() << setw(30) << setprecision(2)<<iterList->getRawScore() << setw(30) << iterList->getLetterGrade() << endl;
	}
	outputFile.close();


};

