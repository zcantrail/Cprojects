#include "stdafx.h"
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

// This is the global space. It is for classes and global variables.
class collegeCorses
{
public:
	collegeCorses();
	void setData(string d, int cn, double ch, double t);
	void outputData();
private:
	string department;
	int courseNum;
	double creditHours;
	double tuition;
};
collegeCorses::collegeCorses()
{
	department = "Default";
	courseNum = 00;
	creditHours = 0.0;
	tuition = 0.0;
}
void collegeCorses::setData(string d, int cn, double ch, double t)
{
	department = d;
	courseNum = cn;
	creditHours = ch;
	tuition = t;
}
void collegeCorses::outputData()
{
	cout << "Course number " << courseNum << " in the " << department << " department has " << creditHours << " credit hours" << ", and tuition is $" << tuition << "." << endl;
}
class labCourse : public collegeCorses
{
public:
	void setData(double lf, string d, int cn, double ch, double t);
	void outputData();

private:
	double labFee;
};

void labCourse::setData(double lf, string d, int cn, double ch, double t)
{
	collegeCorses::setData(d, cn, ch, t);
	labFee = lf;
}
void labCourse::outputData()
{
	collegeCorses::outputData();
	cout << "The Lab fee is $" << labFee << endl;
}
int main()
{
	// Place your main code here.
	labCourse biology;
	biology.setData(20, "science", 3, 15.4, 100.33);
	biology.outputData();
	// Force the console to stay open until a key is pressed
	cout << endl;
	system("pause");
	return 0;
}

