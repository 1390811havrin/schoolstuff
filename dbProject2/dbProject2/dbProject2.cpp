#include <iostream>
#include <string>
#include "GUI.h"

using namespace std;

int main()
{
#pragma region variables
	bool continueON = true;
	string potatoe3 = "";
	GUI gUIKEY;
#pragma endregion

	potatoe3 = gUIKEY.printLoginScreen();
	system("cls");


	while (continueON)
	{
		int choice;
		gUIKEY.printAdvisorChoices(potatoe3);
		cin >> choice;
		system("cls");
		continueON = gUIKEY.decipherChoice(choice);

	}

 }


