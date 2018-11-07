#include <iostream>
#include <string>
#include "GUI.h"
#include "AdvisingDBAbstraction.h"

GUI::GUI()
{
}


GUI::~GUI()
{
}
bool GUI:: decipherChoice(int choice)
{
	if (choice == 1)
	{
		//add a student
		return addAStudent();
	}
	else if (choice == 2)
	{
		//add a course
		return addACourse();
	}

	else if (choice == 3)
	{
		//add a advisor
		return addAAdvisor();
	}
	else if (choice == 4)
	{
		//list students
		return listStudents();
	}
	else if (choice == 5)
	{
		//view plan
		return viewPlan();
	}
	else if (choice == 6)
	{
		//delete plan
		return deletePlan();
	}
	else if (choice == 7)
	{
		//convert plan to course
		return convertPlanToCourses();
	}
	else if (choice == 8)
	{
		//make a plan
		return makeAPlan();
	}
	else if (choice == 9)
	{
		//list all existing plans by name
		return listAllExistingPlansByName();
	}
	else if (choice == 0)
	{
		//exit app
		return false;
	}
	return true;
}

bool GUI:: addAStudent()
{
	
	

	return true;
}

bool GUI:: addACourse()
{
	return true;
}

bool GUI::addAAdvisor()
{
	return true;
}

bool GUI::listStudents()
{
	return true;
}

bool GUI::viewPlan()
{
	return true;
}

bool GUI::deletePlan()
{
	return true;
}

bool GUI::convertPlanToCourses()
{
	return true;
}

bool GUI::makeAPlan()
{
	return true;
}

bool GUI:: listAllExistingPlansByName()
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