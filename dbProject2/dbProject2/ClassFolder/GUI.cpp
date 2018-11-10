#include <iostream>
#include <string>
#include <vector>
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

bool GUI::addAStudent(AdvisingDBAbstraction &adb, int st_id, string fname, string lname)
{

	adb.insertStudent(fname, lname, st_id);
	return false;
}

bool GUI:: addACourse(AdvisingDBAbstraction &adb)
{
	cout << "In the Free Edition you must know what your courses prerequisites are to create it along with your course ID" << endl;
	cout << "The autofill feature is included in the paid version" << endl;
	int c_id;
	vector<int> prereqID;
	int prereqYN;
	int prereq;
	string cname;
	string cnumber;
	int credNum;
	int req;

	cout << "Please enter in Course ID: " << endl;
	cin >> c_id;
	cout << "Are there any Prereqs?(1 for yes 0 for no)" << endl;
	cin >> prereqYN;
	while (prereqYN)
	{
		cout << "Please Enter in your Prereq ID" << endl;
		cin >> prereq;
		prereqID.push_back(prereq);

		cout << "Are there any more Prereqs?(1 for yes 0 for no)" << endl;
		cin >> prereqYN;
	}
	cout << "Please Enter in Course Name: " << endl;
	cin >> cname;
	cout << "Please Enter in Course Number: " << endl;
	cin >> cnumber;
	cout << "Please Enter in How Many Credits it's Worth: " << endl;
	cin >> credNum;
	cout << "Please Enter in whether or not it's required(1 for required 0 for not required): " << endl;
	cin >> req;
	cout << "Thank You!" << endl;
	adb.insertCourses(c_id, cname, cnumber, credNum, req);
	for (int i = 0; i < prereqID.size(); i++)
	{
		adb.insertCoursesHavePrereqs(c_id, prereqID[i]);
	}

	return true;
}

bool GUI::addACourse(AdvisingDBAbstraction &adb, int c_id, string cname, string cnumber, int crednum, int req, int prereq1, int prereq2)
{
	adb.insertCourses(c_id, cname, cnumber, crednum, req);
	if(prereq1 > -1)
	adb.insertCoursesHavePrereqs(c_id, prereq1);
	if(prereq2> -1)
	adb.insertCoursesHavePrereqs(c_id, prereq2);

	return false;
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

bool GUI::addAAdvisor(AdvisingDBAbstraction &adb, int ad_id, string fname, string lname)
{

	adb.insertAdvisor(fname, lname, ad_id);
	return false;
}

bool GUI::listStudents(AdvisingDBAbstraction &adb)
{
	adb.listStudents();

	return true;
}

bool GUI::viewPlan(AdvisingDBAbstraction &adb)
{
	int p_id;
	cout << " This will display courses in the plan for more general information see list all plans" << endl;
	cout << "Please Enter In  Plan ID: " << endl;
	cin >> p_id;

	adb.listPlans(p_id);

	return true;
}

bool GUI::deletePlan(AdvisingDBAbstraction &adb)
{

	int p_id;
	cout << "Caution: Deleting a Plan also deletes all information about the plan" << endl;
	cout << " Enter in Plan ID please" << endl;
	cin >> p_id;
	adb.deletePlan(p_id);
	return true;
}

bool GUI::convertPlanToCourses(AdvisingDBAbstraction &adb)
{
	int st_id;
	int p_id;
	cout << "Specify your students ID" << endl;
	cin >> st_id;
	cout << "Specify your students Plan ID " << endl;
	cin >> p_id;
	adb.convertPlanToCourses(p_id, st_id);
	return true;
}

bool GUI::makeAPlan(AdvisingDBAbstraction &adb)
{
	string name;
	int year;
	int semester;
	int p_id;
	int ad_id;
	int st_id;
	int numCourses;
	int cc;
	cout << "If you don't know your plan ID then enter in a negative number and it will auto generate for you." << endl;
	cout << " Enter Name Of Plan: " << endl;
	cin >> name;
	cout << "Enter in Year: " << endl;
	cin >> year;
	cout << "Enter in Semester(1 or 2): " << endl;
	cin >> semester;
	cout << "Enter in Plan_ID: " << endl;
	cin >> p_id;
	cout << "Enter in the corresponding Advisor's ID: " << endl;
	cin >> ad_id;
	cout << "Enter in Students ID" << endl;
	cin >> st_id;
	//case where auto generates
	if(p_id < 0)
	adb.insertPlans(name, year, semester, ad_id, st_id);
	if (p_id >= 0)
	adb.insertPlans(name, year, semester, p_id, ad_id, st_id);

	cout << "Step 2 choosing classes for this students plan" << endl;
	cout << "Please Make Note of Which Course ID you want for adding to the plan" << endl;

	adb.listCoursesAStudentCanTake(st_id);

	cout << "How Many courses to you want to add to your plan?" << endl;
	cin >> numCourses;

	for (int i = 0; i < numCourses; i++)
	{
		cout << "Please enter in your " << i << " Course_ID: " << endl;
		cin >> cc;
		adb.insertCoursesMakeUpPlans(p_id, cc);

	}
	cout << "Thank you!" << endl;

	system("cls");
	return true;
}

bool GUI::makeAPlan(AdvisingDBAbstraction & adb, string name, int year, int semester, int p_id, int ad_id, int st_id, int course1, int course2, int course3, int course4)
{

	adb.insertPlans(name, year, semester, p_id, ad_id, st_id);
	adb.insertCoursesMakeUpPlans(p_id, course1);
	adb.insertCoursesMakeUpPlans(p_id, course2);
	adb.insertCoursesMakeUpPlans(p_id, course3);
	adb.insertCoursesMakeUpPlans(p_id, course4);
	return false;
}

bool GUI:: listAllExistingPlansByName(AdvisingDBAbstraction &adb)
{
	adb.listPlans();
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
	cout << "1. Add a student" << endl; // is working
	cout << "2. Add a course" << endl; //is working
	cout << "3. Add a Advisor" << endl; //is working
	cout << "4. List Students" << endl; // is working
	cout << "5. View Plan" << endl;	 //is working
	cout << "6. delete Plan" << endl; //is working
	cout << "7. Convert Plan to Courses" << endl;
	cout << "8. Make a Plan" << endl; //isworking
	cout << "9. List all existing Plans by name" << endl; //is working
	cout << "0. Exit App" << endl;
}