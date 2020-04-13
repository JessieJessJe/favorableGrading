#pragma once
#include "stdafx.h"
#include "global.h"
#include<string>
using namespace std;

class Student
{
private:
	string nameFirst;
	string nameLast;
	double rawScore;
	double percentRank;
	GRADE  pointGrade;
	GRADE  curveGrade;
	string letterGrade;

public:
	void setFirstName(string s) { nameFirst = s; }
	void setLastName(string s) { nameLast = s; }
	void setRawScore(double s) { rawScore = s; }
	void setPercent(double p) { percentRank = p; }
	void setPointGrade(GRADE g) { pointGrade = g; }
	void setCurveGrade(GRADE g) { curveGrade = g; }
	void setFinalGrade(string g) { letterGrade = g; }
	void setLetterGrade()
	{
		GRADE g;
		if ((rawScore >= BAR) && (curveGrade >= pointGrade))
			g = curveGrade;
		else    g = pointGrade;

		switch (g)
		{
		case F:  letterGrade = "F"; break;
		case D:  letterGrade = "D"; break;
		case CMINUS:letterGrade = "C-"; break;
		case C:  letterGrade = "C"; break;
		case CPLUS: letterGrade = "C+"; break;
		case BMINUS:letterGrade = "B-"; break;
		case B:  letterGrade = "B"; break;
		case BPLUS: letterGrade = "B+"; break;
		case AMINUS:letterGrade = "A-"; break;
		case A:  letterGrade = "A"; break;
		}

	}

	string getFirstName() { return nameFirst; }
	string getLastName() { return nameLast; }
	double getRawScore() { return rawScore; }
	double getPercent() { return percentRank; }
	string getLetterGrade() { return letterGrade; }

	bool operator>(const Student& r)
	{
		return rawScore > r.rawScore;
	}

	bool operator>(double& r)
	{
		return rawScore > r;
	}
	bool operator>=(const Student& r)
	{
		return rawScore >= r.rawScore;
	}
	bool operator==(const Student& r)
	{
		return rawScore == r.rawScore;
	}
	bool operator<(const Student& r)
	{
		return rawScore < r.rawScore;
	}
	bool operator<=(const Student& r)
	{
		return rawScore <= r.rawScore;
	}
};

 
