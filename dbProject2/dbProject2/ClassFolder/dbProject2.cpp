#include <iostream>
#include <string>
#include "C:\Users\David H\Desktop\school\schoolstuff\dbProject2\dbProject2\Headers\GUI.h"
#include "sqlite3.h"
#include "C:\Users\David H\Desktop\school\schoolstuff\dbProject2\dbProject2\Headers\AdvisingDBAbstraction.h"

using namespace std;



int main()
{
#pragma region variables
	bool continueON = true;
	string potatoe3 = "";
	GUI gUIKEY;
	string 	pathToFile = "C:\\Users\\David H\\Advising.db";
	AdvisingDBAbstraction adb(pathToFile);
#pragma endregion


#pragma region Preloads

	gUIKEY.addAAdvisor(adb, 1, "John", "Smith");
	gUIKEY.addAAdvisor(adb, 2, "Joe", "Brown");

	gUIKEY.addAStudent(adb, 1, "George", "Washington");
	gUIKEY.addAStudent(adb, 2, "John", "Adams");

	gUIKEY.addACourse(adb, 1, "Terrible Ideas", "C000", 4, 1, -1, -1);
	gUIKEY.addACourse(adb, 2, "IncromprehensibleIdeas", "C000B", 4, 1, -1, -1);
	gUIKEY.addACourse(adb, 3, "Inconceivable Ideas", "C000C", 4, 1, -1, -1);
	gUIKEY.addACourse(adb, 4, "Abhorrent Ideas", "C000A", 4, 1, -1, -1);

	gUIKEY.addACourse(adb, 5, "Bad Ideas", "C001", 4, 1, 1, -1);
	gUIKEY.addACourse(adb, 6, "Poor Ideas", "C001A", 4, 1, 1, -1);
	gUIKEY.addACourse(adb, 7, "lousy Ideas", "C001B", 4, 0, -1, -1);
	gUIKEY.addACourse(adb, 7, "lousier Ideas", "C001C", 4, 0, -1, -1);

	gUIKEY.addACourse(adb, 8, "Ideas", "C002", 4, 1, 1, 2);
	gUIKEY.addACourse(adb, 9, "Average Ideas", "C002A", 4, 0, 1, 2);
	gUIKEY.addACourse(adb, 10, "Normal Ideas", "C002B", 4, 0, 1, 2);
	gUIKEY.addACourse(adb, 11, "StatusQuoIdeas", "C002C", 4, 0, 1, 2);

	gUIKEY.addACourse(adb, 12, "AboveAverageIdeas", "C003", 4, 1, 3, -1);
	gUIKEY.addACourse(adb, 13, "BetterIdeas", "C003A", 4, 1, 3, -1);
	gUIKEY.addACourse(adb, 14, "GreatIdeas", "C004", 4, 1, 7, 8);
	gUIKEY.addACourse(adb, 15, "TranscendentIdeas", "C005", 4, 1, 9, 5);
	gUIKEY.addACourse(adb, 16, "DivineIdeas", "C006", 4, 1, 9, 10);
	gUIKEY.addACourse(adb, 17, "IncomprehensibleIdeas", "C007", 4, 1, 10, 11);

	gUIKEY.makeAPlan(adb, "The Great Pumpkin", 2018, 1, 1, 1, 1, 1, 2, 3, 4);
	gUIKEY.makeAPlan(adb, "The Great Squash", 2018, 1, 2, 2, 2, 1, 2, 3, 4);

#pragma endregion
	int sf;


	potatoe3 = gUIKEY.printLoginScreen();
	system("cls");



	

	while (continueON)
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		int choice;
		gUIKEY.printAdvisorChoices(potatoe3);
		cin >> choice;
		continueON = gUIKEY.decipherChoice(choice, adb);


	}

 }


