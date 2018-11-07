#pragma once
#include <iostream>
#include <string>
#include "AdvisingDBAbstraction.h"
using namespace std;

class GUI
{

public:
	GUI();
	~GUI();

	void createTables(string pathToFile);

	bool decipherChoice(int choice, AdvisingDBAbstraction &adb);

	bool addAStudent(AdvisingDBAbstraction &adb);

	bool addACourse(AdvisingDBAbstraction &adb);

	bool addAAdvisor(AdvisingDBAbstraction &adb);

	bool listStudents(AdvisingDBAbstraction &adb);

	bool viewPlan(AdvisingDBAbstraction &adb);

	bool deletePlan(AdvisingDBAbstraction &adb);

	bool convertPlanToCourses(AdvisingDBAbstraction &adb);

	bool makeAPlan(AdvisingDBAbstraction &adb);

	bool listAllExistingPlansByName(AdvisingDBAbstraction &adb);

	string printLoginScreen();

	void printAdvisorChoices(string tempPotatoe);


};

