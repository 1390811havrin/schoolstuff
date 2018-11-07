#pragma once
#include <iostream>
#include <string>
#include "DBAbstraction.h"
#include "Sqlite3.h"


class AdvisingDBAbstraction
{
public:

	AdvisingDBAbstraction(string pathToFile);


	

private:
#pragma region creates
	void createStudentTable();
	void createAdvisorTable();
	void createPlansTable();
	void createCoursesTable();
	void createCoursesMakeUpPlansTable();
	void createStudentsHaveTakenCourses();
	void createCoursesHavePrerequisites();
#pragma endregion

#pragma region inserts
	void insertStudent(string f_name, string l_name, int st_id);
	void insertStudent( string f_name, string l_name);
	void insertAdvisor(string f_name, string l_name, int ad_id);
	void insertAdvisor(string f_name, string l_name);
	void insertCourses(int c_id, string cname, string cnumber, int credNum, int req);
	void insertCourses(string cname, string cnumber, int credNum, int req);
	void insertPlans(string name, int year, int semester, int p_id, int ad_id, int st_id);
	void insertPlans(string name, int year, int semester, int ad_id, int st_id);
	void insertCoursesHavePrereqs(int c_id, int prereq);
	void insertStudentsHaveTakenCourses(int st_id, int c_id);
	void insertCoursesMakeUpPlans(int p_id, int c_id);
#pragma endregion

#pragma region gets
	void listStudents();
	void listPlans();
	void listCourses();
	void listAdvisors();

#pragma endregion

	


};

