#include <iostream>
#include <string>
#include "C:\Users\David H\Desktop\school\schoolstuff\dbProject2\dbProject2\Headers\GUI.h"
#include "C:\Users\David H\Desktop\school\schoolstuff\dbProject2\dbProject2\Headers\AdvisingDBAbstraction.h"

GUI::GUI()
{
}


GUI::~GUI()
{
}

void GUI::createTables(string pathToFile)
{

	AdvisingDBAbstraction adb(pathToFile);
}

bool GUI:: decipherChoice(int choice, AdvisingDBAbstraction &adb)
{
	if (choice == 1)
	{
		//add a student
		return addAStudent(adb);
	}
	else if (choice == 2)
	{
		//add a course
		return addACourse(adb);
	}

	else if (choice == 3)
	{
		//add a advisor
		return addAAdvisor(adb);
	}
	else if (choice == 4)
	{
		//list students
		return listStudents(adb);
	}
	else if (choice == 5)
	{
		//view plan
		return viewPlan(adb);
	}
	else if (choice == 6)
	{
		//delete plan
		return deletePlan(adb);
	}
	else if (choice == 7)
	{
		//convert plan to course
		return convertPlanToCourses(adb);
	}
	else if (choice == 8)
	{
		//make a plan
		return makeAPlan(adb);
	}
	else if (choice == 9)
	{
		//list all existing plans by name
		return listAllExistingPlansByName(adb);
	}
	else if (choice == 0)
	{
		//exit app
		return false;
	}
	return true;
}

bool GUI:: addAStudent(AdvisingDBAbstraction &adb)
{
	int stdID = -1;
	string fname;
	string lname;
	cout << " Please Enter In First Name: " << endl;
	cin >> fname;
	cout << "Please Enter In Last Name: " << endl;
	cin >> lname;
	cout << "Please Enter In ST_ID if you don't yet have one for the student enter in a negative number and one will be assigned to him automatically: " << endl;
	cin >> stdID;

	if(stdID >= 0)
	adb.insertStudent(fname, lname, stdID);
	if (stdID < 0)
		adb.insertStudent(fname, lname);

	return true;
}

bool GUI:: addACourse(AdvisingDBAbstraction &adb)
{



	return true;
}

bool GUI::addAAdvisor(AdvisingDBAbstraction &adb)
{
	int stdID = -1;
	string fname;
	string lname;
	cout << " Please Enter In First Name: " << endl;
	cin >> fname;
	cout << "Please Enter In Last Name: " << endl;
	cin >> lname;
	cout << "Please Enter In AD_ID if you don't yet have one for the advisor enter in a negative number and one will be assigned to him automatically: " << endl;
	cin >> stdID;

	if (stdID >= 0)
		adb.insertAdvisor(fname, lname, stdID);
	if (stdID < 0)
		adb.insertAdvisor(fname, lname);

	return true;
}

bool GUI::listStudents(AdvisingDBAbstraction &adb)
{
	adb.listStudents();

	return true;
}

bool GUI::viewPlan(AdvisingDBAbstraction &adb)
{
	int stdID = -1;
	string fname;
	string lname;
	cout << " Please Enter In Name Of Plan: " << endl;
	cin >> fname;
	cout << "Please Enter In : " << endl;
	cin >> lname;
	cout << "Please Enter In ST_ID if you don't yet have one for the student enter in a negative number and one will be assigned to him automatically: " << endl;
	cin >> stdID;

	if (stdID >= 0)
		adb.insertStudent(fname, lname, stdID);
	if (stdID < 0)
		adb.insertStudent(fname, lname);

	return true;


	return true;
}

bool GUI::deletePlan(AdvisingDBAbstraction &adb)
{
	return true;
}

bool GUI::convertPlanToCourses(AdvisingDBAbstraction &adb)
{
	return true;
}

bool GUI::makeAPlan(AdvisingDBAbstraction &adb)
{
	return true;
}

bool GUI:: listAllExistingPlansByName(AdvisingDBAbstraction &adb)
{
	return true;
}

string GUI::printLoginScreen()
{
	string potatoe1 = "";
	string potatoe2 = "";

	cout << "Please Enter In Your Advisor Username" << endl;
	cin >> potatoe1;
	cout << "Please Enter In Your Advisor PassCode" << endl;
	cin >> potatoe2;
	return potatoe1;
}


void GUI::printAdvisorChoices(string tempPotatoe)
{
	cout << "Welcome Advisor " << tempPotatoe << "! " << endl;
	cout << "Please Choose What you Would Like To Do Today!" << endl;
	cout << "1. Add a student" << endl;
	cout << "2. Add a course" << endl;
	cout << "3. Add a Advisor" << endl;
	cout << "4. List Students" << endl;
	cout << "5. View Plan" << endl;
	cout << "6. delete Plan" << endl;
	cout << "7. Covert Plan to Courses" << endl;
	cout << "8. Make a Plan" << endl;
	cout << "9. List all existing Plans by name" << endl;
	cout << "0. Exit App" << endl;
}