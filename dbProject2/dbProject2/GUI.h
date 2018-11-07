#pragma once
#include <iostream>
#include <string>
#include "AdvisingDBAbstraction.h"
using namespace std;

class GUI: public AdvisingDBAbstraction
{

public:
	GUI();
	~GUI();

	bool decipherChoice(int choice);

	bool addAStudent();

	bool addACourse();

	bool addAAdvisor();

	bool listStudents();

	bool viewPlan();

	bool deletePlan();

	bool convertPlanToCourses();

	bool makeAPlan();

	bool listAllExistingPlansByName();

	string printLoginScreen();

	void printAdvisorChoices(string tempPotatoe);


};

