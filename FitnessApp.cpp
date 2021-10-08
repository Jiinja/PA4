#include "FitnessApp.h"
#include <Windows.h>

//fitness appwrapper  

void FitnessAppWrapper::runApp()
{
	int userChoice = 0;
	string userChoiceGrabber = "";
	ExercisePlan weeklyExercise[7];
	DietPlan weeklyDiet[7];
	do {
		userChoice = 0;
		while (userChoice == 0) //this while loop grabs user inputs until they are valid. If not valid, it says so and reprints the menu
		{
			displayMenu();
			getline(cin, userChoiceGrabber);
			if (!isNumber(userChoiceGrabber.c_str()) || stoi(userChoiceGrabber) > 9 || stoi(userChoiceGrabber) < 1)
			{
				cout << "Invalid choice, please try again" << endl << endl;
			}
			else
			{
				userChoice = stoi(userChoiceGrabber);
			}
		}
		switch(userChoice){
		case 1: //load weekly diet plan
		{
			fstream dietFile;
			dietFile.open("diet.txt", std::ios::in);
			loadWeeklyPlan(dietFile, weeklyDiet);
			dietFile.close();
			cout << endl << endl;
			Sleep(1000);
		}
			break;
		case 2: //load weekly exercise plan
		{
			fstream exerciseFile;
			exerciseFile.open("exercise.txt", std::ios::in);
			loadWeeklyPlan(exerciseFile, weeklyExercise);
			exerciseFile.close();
			cout << endl << endl;
			Sleep(500);
		}
			break;
		case 3: //store weekly diet plan
		{
			fstream dietFile;
			dietFile.open("diet.txt", std::ios::out);
			storeWeeklyPlan(dietFile, weeklyDiet);
			dietFile.close();
			cout << endl << endl;
			Sleep(500);
		}
			break;
		case 4: //store weekly exercise plan
		{
			fstream exerciseFile;
			exerciseFile.open("exercise.txt", std::ios::out);
			storeWeeklyPlan(exerciseFile, weeklyExercise);
			exerciseFile.close();
			cout << endl << endl;
			Sleep(500);
		}
		break;
		case 5: //display weekly diet plan
			cout << endl << endl;
			displayWeeklyPlan(weeklyDiet);
			cout << endl << endl;
			Sleep(500);
			break;
		case 6: //display weekly exercise plan
			cout << endl << endl;
			displayWeeklyPlan(weeklyExercise);
			cout << endl << endl;
			Sleep(500);
			break; 
		case 7: //edit weekly diet plan
			cout << endl << endl;
			cout << "Which Plan would you like to edit?" << endl;
			displayWeeklyPlan(weeklyDiet);
			userChoice = 0;
			while (userChoice == 0)
			{
				getline(cin, userChoiceGrabber);
				if (isNumber(userChoiceGrabber.c_str())) userChoice = stoi(userChoiceGrabber);
				else cout << "Invalid entry. Please try again" << endl;
			}
			editPlan(weeklyDiet[userChoice - 1]);
			Sleep(500);
			break;
		case 8: //edit weekly diet plan
			cout << endl << endl;
			cout << "Which plan would you like to edit?" << endl;
			displayWeeklyPlan(weeklyExercise);
			userChoice = 0;
			while (userChoice == 0)
			{
				getline(cin, userChoiceGrabber);
				if (isNumber(userChoiceGrabber.c_str())) userChoice = stoi(userChoiceGrabber);
				else cout << "Invalid entry. Please try again" << endl;
			}
			editPlan(weeklyExercise[userChoice - 1]);
			Sleep(500);
			break; 
		}
	} while (userChoice != 9);
	fstream exerciseFile;		//Storing exercisePlan
	exerciseFile.open("exercise.txt", std::ios::out);
	storeWeeklyPlan(exerciseFile, weeklyExercise);
	exerciseFile.close();
	fstream dietFile;			//Storing dietPlan
	dietFile.open("diet.txt", std::ios::out);
	storeWeeklyPlan(dietFile, weeklyDiet);
	dietFile.close();
}
void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, DietPlan& plan)
{
	fileStream >> plan;
}
void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, ExercisePlan& plan)
{
	fileStream >> plan;
}
void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[])
{
	for (int j = 0; j < 7; j++)
	{
		DietPlan newPlan;
		loadDailyPlan(fileStream, newPlan);
		weeklyPlan[j] = newPlan;
	}
}
void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[])
{
	for (int j = 0; j < 7; j++)
	{
		ExercisePlan newPlan;
		loadDailyPlan(fileStream, newPlan);
		weeklyPlan[j] = newPlan;
	}
}
void FitnessAppWrapper::displayDailyPlan(DietPlan& plan)
{
	cout << plan;
}
void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan)
{
	cout << plan;
}
void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[])
{
	for (int j = 0; j < 7; j++)
	{
		cout << "[" << j+1 << "] ";
		displayDailyPlan(weeklyPlan[j]);
	}
}
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[])
{
	for (int j = 0; j < 7; j++)
	{
		cout << "[" << j+1 << "] ";
		displayDailyPlan(weeklyPlan[j]);
	}
}
void FitnessAppWrapper::storeDailyPlan(fstream& fileStream, DietPlan& plan)
{
	fileStream << plan;
}
void FitnessAppWrapper::storeDailyPlan(fstream& fileStream, ExercisePlan& plan)
{
	fileStream << plan;
}
void FitnessAppWrapper::storeWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[])
{
	for (int j = 0; j < 7; j++)
	{
		storeDailyPlan(fileStream, weeklyPlan[j]);
	}
}
void FitnessAppWrapper::storeWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[])
{
	for (int j = 0; j < 7; j++)
	{
		storeDailyPlan(fileStream, weeklyPlan[j]);
	}
}
void FitnessAppWrapper::displayMenu()
{
	cout << "[1] Load weekly diet plan from file" << endl;
	cout << "[2] Load weekly exercise plan from file" << endl;
	cout << "[3] Store weekly diet plan from file" << endl;
	cout << "[4] Store weekly exercise plan from file" << endl;
	cout << "[5] Display weekly diet plan" << endl;
	cout << "[6] Display weekly exercise plan" << endl;
	cout << "[7] Edit daily diet plan" << endl;
	cout << "[8] Edit daily exercise plan" << endl;
	cout << "[9] Exit" << endl;
}

void FitnessAppWrapper::editPlan(ExercisePlan& plan)
{
	displayDailyPlan(plan);
	cout << "[1] Edit Name" << endl;
	cout << "[2] Edit Date" << endl;
	cout << "[3] Edit Goal" << endl;
	int userChoice = 0;
	string userChoiceGrabber = "";
	while (userChoice == 0) {
		getline(cin, userChoiceGrabber);
		if (isNumber(userChoiceGrabber.c_str()) 
			&& stoi(userChoiceGrabber) > 0 
			&& stoi(userChoiceGrabber) < 4) 
			userChoice = stoi(userChoiceGrabber);
		else cout << "Invalid entry. Please try again" << endl;
	}
	cout << endl << endl;
	switch (userChoice) {
	case 1:
		cout << "What would you like the new name to be?" << endl;
		getline(cin, userChoiceGrabber);
		plan.setName(userChoiceGrabber);
		break;
	case 2:
		cout << "What would you like the new Date to be?" << endl;
		getline(cin, userChoiceGrabber);
		plan.setDate(userChoiceGrabber);
		break;
	case 3:
		cout << "What would you like the new Goal to be?" << endl;
		getline(cin, userChoiceGrabber);
		if (isNumber(userChoiceGrabber))
		{
			userChoice = stoi(userChoiceGrabber);
			plan.setGoal(userChoice);
		}
		else cout << "Invalid entry. Please try again" << endl;
	}
	cout << endl << endl;
}

void FitnessAppWrapper::editPlan(DietPlan& plan)
{
	displayDailyPlan(plan);
	cout << "[1] Edit Name" << endl;
	cout << "[2] Edit Date" << endl;
	cout << "[3] Edit Goal" << endl;
	int userChoice = 0;
	string userChoiceGrabber = "";
	while (userChoice == 0) {
		getline(cin, userChoiceGrabber);
		if (isNumber(userChoiceGrabber.c_str())
			&& stoi(userChoiceGrabber) > 0
			&& stoi(userChoiceGrabber) < 4)
			userChoice = stoi(userChoiceGrabber);
		else cout << "Invalid entry. Please try again" << endl;
	}
	cout << endl << endl;
	switch (userChoice) {
	case 1:
		cout << "What would you like the new name to be?" << endl;
		getline(cin, userChoiceGrabber);
		plan.setName(userChoiceGrabber);
		break;
	case 2:
		cout << "What would you like the new Date to be?" << endl;
		getline(cin, userChoiceGrabber);
		plan.setDate(userChoiceGrabber);
		break;
	case 3:
		cout << "What would you like the new Goal to be?" << endl;
		getline(cin, userChoiceGrabber);
		if (isNumber(userChoiceGrabber))
		{
			userChoice = stoi(userChoiceGrabber);
			plan.setGoal(userChoice);
		}
		else cout << "Invalid entry. Please try again" << endl;
	}
	cout << endl << endl;
}

bool isNumber(const std::string& s) //returns true if the string is a number, else false
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}
