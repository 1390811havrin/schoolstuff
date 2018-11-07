#include <iostream>
#include <string>
#include "AdvisingDBAbstraction.h"

using namespace std;

AdvisingDBAbstraction::AdvisingDBAbstraction(string pathToFile): DBAbstraction(pathToFile)
{
	createAdvisorTable();
	createCoursesTable();
	createPlansTable();
	createStudentTable();
	createCoursesHavePrerequisites();
	createCoursesMakeUpPlansTable();
	createStudentsHaveTakenCourses();
}


#pragma region LargeScaleCreates
void AdvisingDBAbstraction::createStudentTable()
{
	string sql = "CREATE TABLE IF NOT EXISTS Students (ST_ID INTEGER PRIMARY KEY NOT NULL, f_Name TEXT, l_Name TEXT);";
	//execute the query to create the table
	if (!executeQueryNoResultsBack(sql))
	{
		cout << "Error creating Students table" << endl;
	}

}

void AdvisingDBAbstraction::createAdvisorTable()
{
	string sql = "CREATE TABLE IF NOT EXISTS Advisors (AD_ID INTEGER PRIMARY KEY NOT NULL, f_Name TEXT, l_Name TEXT)";
	//execute the query to create the table
	if (!executeQueryNoResultsBack(sql))
	{
		cout << "Error creating Advisors table" << endl;
	}

}

void AdvisingDBAbstraction::createPlansTable()
{
	string sql = "CREATE TABLE IF NOT EXISTS Plans (P_ID INTEGER PRIMARY KEY NOT NULL, NumYear INTEGER, semester INTEGER, name Text, AD_ID integer, ST_ID integer, Foreign Key(AD_ID) References Advisors(AD_ID), Foreign Key(ST_ID) References Students)";

	//execute the query to create the table
	if (!executeQueryNoResultsBack(sql))
	{
		cout << "Error creating Plans table" << endl;
	}

}

void AdvisingDBAbstraction::createCoursesTable()
{
	string sql = "CREATE TABLE IF NOT EXISTS Courses (C_ID INTEGER PRIMARY KEY NOT NULL, CName TEXT, CNumber TEXT, CredNum Integer, Required Integer)";

	//execute the query to create the table
	if (!executeQueryNoResultsBack(sql))
	{
		cout << "Error creating Courses table" << endl;
	}

}

void AdvisingDBAbstraction::createCoursesMakeUpPlansTable()
{
	string sql = "Create Table IF NOT Exists CoursesMakeUpPlans(P_ID Integer, C_ID Integer, Foreign Key(P_ID) References Plans(P_ID), Foreign Key(C_ID) References Courses(C_ID), Primary Key(P_ID, C_ID))";

	//execute the query to create the table
	if (!executeQueryNoResultsBack(sql))
	{
		cout << "Error creating CMUP table" << endl;
	}

}

void AdvisingDBAbstraction::createStudentsHaveTakenCourses()
{
	string sql = "Create Table IF NOT Exists StudentsHaveTakenCourses(ST_ID Integer, C_ID Integer, Foreign Key(ST_ID) References Students(ST_ID), Foreign Key(C_ID) References Courses(C_ID), Primary Key(ST_ID, C_ID))";

	//execute the query to create the table
	if (!executeQueryNoResultsBack(sql))
	{
		cout << "Error creating SHTC table" << endl;
	}

}

void AdvisingDBAbstraction::createCoursesHavePrerequisites()
{
	string sql = "Create Table IF NOT Exists CoursesHavePrereqs(C_ID Integer, Prereq Integer, Foreign Key(C_ID) References Courses(C_ID), Foreign Key(Prereq) References Courses(C_ID), Primary Key(C_ID, Prereq))";
	//execute the query to create the table
	if (!executeQueryNoResultsBack(sql))
	{
		cout << "Error creating CHP table" << endl;
	}

}
#pragma endregion


#pragma region LargeScaleInserts
void AdvisingDBAbstraction::insertStudent(string f_name, string l_name, int st_id)
{
	string sql = "Insert into Students (f_name, l_name, ST_ID) Values (?, ?, ?);";
	sqlite3_stmt* mystatement;
	int statusofPrep = sqlite3_prepare_v2(db, sql.c_str(), -1, &mystatement, NULL);
	if (statusofPrep == SQLITE_OK)
	{
		sqlite3_bind_text(mystatement, 1, f_name.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(mystatement, 2, l_name.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_int(mystatement, 3, st_id);
		if (!executeQueryNoResultsBack(mystatement))
		{
			cout << "Error inserting into Students" << endl;
		}
	}
}

void AdvisingDBAbstraction::insertStudent(string f_name, string l_name)
{
	string sql = "Insert into Students (f_name, l_name) Values (?, ?);";
	sqlite3_stmt* mystatement;
	int statusofPrep = sqlite3_prepare_v2(db, sql.c_str(), -1, &mystatement, NULL);
	if (statusofPrep == SQLITE_OK)
	{
		sqlite3_bind_text(mystatement, 1, f_name.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(mystatement, 2, l_name.c_str(), -1, SQLITE_STATIC);
		if (!executeQueryNoResultsBack(mystatement))
		{
			cout << "Error inserting into Students" << endl;
		}
	}

}



void AdvisingDBAbstraction::insertAdvisor(string f_name, string l_name, int ad_id)
{
	string sql = "Insert into Advisors (f_name, l_name, AD_ID) Values (?, ?, ?);";
	sqlite3_stmt* mystatement;
	int statusofPrep = sqlite3_prepare_v2(db, sql.c_str(), -1, &mystatement, NULL);
	if (statusofPrep == SQLITE_OK)
	{
		sqlite3_bind_text(mystatement, 1, f_name.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(mystatement, 2, l_name.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_int(mystatement, 3, ad_id);
		if (!executeQueryNoResultsBack(mystatement))
		{
			cout << "Error inserting into Advisors" << endl;
		}
	}


}

void AdvisingDBAbstraction::insertAdvisor(string f_name, string l_name)
{
	string sql = "Insert into Advisors (f_name, l_name) Values (?, ?);";
	sqlite3_stmt* mystatement;
	int statusofPrep = sqlite3_prepare_v2(db, sql.c_str(), -1, &mystatement, NULL);
	if (statusofPrep == SQLITE_OK)
	{
		sqlite3_bind_text(mystatement, 1, f_name.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(mystatement, 2, l_name.c_str(), -1, SQLITE_STATIC);
		if (!executeQueryNoResultsBack(mystatement))
		{
			cout << "Error inserting into Advisors" << endl;
		}
	}




}

void AdvisingDBAbstraction::insertCourses(int c_id, string cname, string cnumber, int credNum, int req)
{
	string sql = "Insert into Courses (C_ID, CName, CNumber, CredNum, Required) Values (?, ?, ?, ?, ?);";
	sqlite3_stmt* mystatement;
	int statusofPrep = sqlite3_prepare_v2(db, sql.c_str(), -1, &mystatement, NULL);
	if (statusofPrep == SQLITE_OK)
	{
		sqlite3_bind_int(mystatement, 1, c_id);
		sqlite3_bind_text(mystatement, 2, cname.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(mystatement, 3, cnumber.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_int(mystatement, 4, credNum);
		sqlite3_bind_int(mystatement, 5, req);
		if (!executeQueryNoResultsBack(mystatement))
		{
			cout << "Error inserting into Courses" << endl;
		}
	}


}

void AdvisingDBAbstraction::insertCourses(string cname, string cnumber, int credNum, int req)
{
	string sql = "Insert into Courses ( CName, CNumber, CredNum, Required) Values (?, ?, ?, ?);";
	sqlite3_stmt* mystatement;
	int statusofPrep = sqlite3_prepare_v2(db, sql.c_str(), -1, &mystatement, NULL);
	if (statusofPrep == SQLITE_OK)
	{

		sqlite3_bind_text(mystatement, 1, cname.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(mystatement, 2, cnumber.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_int(mystatement, 3, credNum);
		sqlite3_bind_int(mystatement, 4, req);
		if (!executeQueryNoResultsBack(mystatement))
		{
			cout << "Error inserting into Courses" << endl;
		}
	}

}

void AdvisingDBAbstraction::insertPlans(string name, int year, int semester, int p_id, int ad_id, int st_id)
{
	string sql = "Insert into Plans (name, NumYear, semester, P_ID, AD_ID, ST_ID) Values (?, ?, ?, ?, ?, ?);";
	sqlite3_stmt* mystatement;
	int statusofPrep = sqlite3_prepare_v2(db, sql.c_str(), -1, &mystatement, NULL);
	if (statusofPrep == SQLITE_OK)
	{

		sqlite3_bind_text(mystatement, 1, name.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_int(mystatement, 2, year);
		sqlite3_bind_int(mystatement, 3, semester);
		sqlite3_bind_int(mystatement, 4, p_id);
		sqlite3_bind_int(mystatement, 5, ad_id);
		sqlite3_bind_int(mystatement, 6, st_id);
		if (!executeQueryNoResultsBack(mystatement))
		{
			cout << "Error inserting into Plans" << endl;
		}
	}

}

void AdvisingDBAbstraction::insertPlans(string name, int year, int semester, int ad_id, int st_id)
{
	string sql = "Insert into Plans (name, NumYear, semester, AD_ID, ST_ID) Values (?, ?, ?, ?, ?);";
	sqlite3_stmt* mystatement;
	int statusofPrep = sqlite3_prepare_v2(db, sql.c_str(), -1, &mystatement, NULL);
	if (statusofPrep == SQLITE_OK)
	{

		sqlite3_bind_text(mystatement, 1, name.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_int(mystatement, 2, year);
		sqlite3_bind_int(mystatement, 3, semester);
		sqlite3_bind_int(mystatement, 4, ad_id);
		sqlite3_bind_int(mystatement, 5, st_id);
		if (!executeQueryNoResultsBack(mystatement))
		{
			cout << "Error inserting into Plans" << endl;
		}
	}


}

void AdvisingDBAbstraction::insertCoursesHavePrereqs(int c_id, int prereq)
{
	string sql = "Insert into CoursesHavePrereqs (C_ID, Prereq) Values (?, ?);";
	sqlite3_stmt* mystatement;
	int statusofPrep = sqlite3_prepare_v2(db, sql.c_str(), -1, &mystatement, NULL);
	if (statusofPrep == SQLITE_OK)
	{
		sqlite3_bind_int(mystatement, 1, c_id);
		sqlite3_bind_int(mystatement, 2, prereq);
		
		if (!executeQueryNoResultsBack(mystatement))
		{
			cout << "Error inserting into CHP" << endl;
		}
	}



}

void AdvisingDBAbstraction::insertStudentsHaveTakenCourses(int st_id, int c_id)
{
	string sql = "Insert into StudentsHaveTakenCourses (ST_ID, C_ID) Values (?, ?);";
	sqlite3_stmt* mystatement;
	int statusofPrep = sqlite3_prepare_v2(db, sql.c_str(), -1, &mystatement, NULL);
	if (statusofPrep == SQLITE_OK)
	{
		sqlite3_bind_int(mystatement, 1, st_id);
		sqlite3_bind_int(mystatement, 2, c_id);

		if (!executeQueryNoResultsBack(mystatement))
		{
			cout << "Error inserting into SHTC" << endl;
		}
	}

}

void AdvisingDBAbstraction::insertCoursesMakeUpPlans(int p_id, int c_id)
{
	string sql = "Insert into CoursesMakeUpPlans (P_ID, C_ID) Values (?, ?);";
	sqlite3_stmt* mystatement;
	int statusofPrep = sqlite3_prepare_v2(db, sql.c_str(), -1, &mystatement, NULL);
	if (statusofPrep == SQLITE_OK)
	{
		sqlite3_bind_int(mystatement, 1, p_id);
		sqlite3_bind_int(mystatement, 2, c_id);

		if (!executeQueryNoResultsBack(mystatement))
		{
			cout << "Error inserting into CMUP" << endl;
		}
	}


}

#pragma endregion
#pragma region gets
void AdvisingDBAbstraction::listStudents()
{
	string sql = "Select ST_ID, f_Name, l_Name from Students;";
		sqlite3_stmt* myStatement;
		if (prepareQueryWithResults(sql, myStatement))
		{
			int statusOfStep = sqlite3_step(myStatement);

			while (statusOfStep == SQLITE_ROW)
			{
				int st_id(sqlite3_column_int(myStatement, 1));
				string firstName((char*)sqlite3_column_text(myStatement, 2));
				string lastName((char*)sqlite3_column_text(myStatement, 3));
				cout << st_id << ". " << firstName << lastName << endl;
			
				statusOfStep = sqlite3_step(myStatement);
			}
			sqlite3_finalize(myStatement);
		}
}
void AdvisingDBAbstraction::listPlans()
{
	string sql = "Select P_ID, NumYear, semester, name, AD_ID, ST_ID from Plans;";
	sqlite3_stmt* myStatement;
	if (prepareQueryWithResults(sql, myStatement))
	{
		int statusOfStep = sqlite3_step(myStatement);

		while (statusOfStep == SQLITE_ROW)
		{
			int p_id(sqlite3_column_int(myStatement, 1));
			int year(sqlite3_column_int(myStatement, 2));
			int semester(sqlite3_column_int(myStatement, 3));
			string name((char*)sqlite3_column_text(myStatement, 4));
			int ad_id(sqlite3_column_int(myStatement, 5));
			int st_id(sqlite3_column_int(myStatement, 6));
			cout << "P_ID: " << p_id << " Year: " << year << " Semester: " << semester << " Name: " << name << " ADID: "  << ad_id << " ST_ID: " << st_id << endl;

			statusOfStep = sqlite3_step(myStatement);
		}
		sqlite3_finalize(myStatement);
	}

}
void AdvisingDBAbstraction::listCourses()
{
	string sql = "Select C_ID, CName, CNumber, CredNum, Required from Courses;";
	sqlite3_stmt* myStatement;
	if (prepareQueryWithResults(sql, myStatement))
	{
		int statusOfStep = sqlite3_step(myStatement);

		while (statusOfStep == SQLITE_ROW)
		{
			int c_id(sqlite3_column_int(myStatement, 1));
			string cname((char*)sqlite3_column_text(myStatement, 2));
			string cnumber((char*)sqlite3_column_text(myStatement, 3));
			int crednum(sqlite3_column_int(myStatement, 4));
			int required(sqlite3_column_int(myStatement, 5));
			string req;
			if (required)
			{
				req = "True";
			}
			else
			{
				req = "false";
			}
			cout << "CourseID: " << c_id << " Course Name: " << cname << " Course Number: " << cnumber << " Credits Amount: " << crednum << " Required: " << req << endl;

			statusOfStep = sqlite3_step(myStatement);
		}
		sqlite3_finalize(myStatement);
	}


}
void AdvisingDBAbstraction::listAdvisors()
{
	string sql = "Select AD_ID, f_Name, l_Name from Advisors;";
	sqlite3_stmt* myStatement;
	if (prepareQueryWithResults(sql, myStatement))
	{
		int statusOfStep = sqlite3_step(myStatement);

		while (statusOfStep == SQLITE_ROW)
		{
			int ad_id(sqlite3_column_int(myStatement, 1));
			string firstName((char*)sqlite3_column_text(myStatement, 2));
			string lastName((char*)sqlite3_column_text(myStatement, 3));
			cout << "Advisor ID: " << ad_id << " First Name: " << firstName << "Last Name: " << lastName << endl;

			statusOfStep = sqlite3_step(myStatement);
		}
		sqlite3_finalize(myStatement);
	}

}

#pragma endregion

