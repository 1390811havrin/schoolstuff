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

	bool addAStudent(AdvisingDBAbstraction &adb, int st_id, string fname, string lname);

	bool addACourse(AdvisingDBAbstraction &adb);

	bool addACourse(AdvisingDBAbstraction &adb, int c_id, string cname, string cnumber, int crednum, int req, int prereq1, int prereq2);

	bool addAAdvisor(AdvisingDBAbstraction &adb);

	bool addAAdvisor(AdvisingDBAbstraction &adb, int ad_id, string fname, string lname);

	bool listStudents(AdvisingDBAbstraction &adb);

	bool viewPlan(AdvisingDBAbstraction &adb);

	bool deletePlan(AdvisingDBAbstraction &adb);

	bool convertPlanToCourses(AdvisingDBAbstraction &adb);

	bool makeAPlan(AdvisingDBAbstraction &adb);

	bool makeAPlan(AdvisingDBAbstraction &adb, string name, int year, int semester, int p_id, int ad_id, int st_id, int course1, int course2, int course3, int course4);

	bool listAllExistingPlansByName(AdvisingDBAbstraction &adb);
	
	string printLoginScreen();

	void printAdvisorChoices(string tempPotatoe);


};

