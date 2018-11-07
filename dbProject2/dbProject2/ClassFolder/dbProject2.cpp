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
	
	potatoe3 = gUIKEY.printLoginScreen();
	system("cls");


	while (continueON)
	{
		int choice;
		gUIKEY.printAdvisorChoices(potatoe3);
		cin >> choice;
		system("cls");
		continueON = gUIKEY.decipherChoice(choice, adb);

	}

 }


