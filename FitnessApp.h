/*****************************************************************************************
* Programmer: Josh Maloy                                                                 *
* Class: CptS 122, Fall 2021; Lab Section 1                                              *
* Programming Assignment: PA4                                                            *
* Date: October 13, 2021                                                                 *
* Description: this program contains all necessary method definitions for the fitnessapp *
* to function as intended.	NOTE: its .h because VS is trash and im scared to change it  *
******************************************************************************************/

#include "DietPlan.hpp"

class FitnessAppWrapper
{
public:
	void runApp();
private:
	void loadDailyPlan(fstream& fileStream, DietPlan& plan);
	void loadDailyPlan(fstream& fileStream, ExercisePlan& plan);
	void loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]);
	void displayDailyPlan(DietPlan& plan);
	void displayDailyPlan(ExercisePlan& plan);
	void displayWeeklyPlan(DietPlan weeklyPlan[]);
	void displayWeeklyPlan(ExercisePlan weeklyPlan[]);
	void storeDailyPlan(fstream& fileStream, DietPlan& plan);
	void storeDailyPlan(fstream& fileStream, ExercisePlan& plan);
	void storeWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]);
	void storeWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]);
	void displayMenu();
	void editPlan(ExercisePlan& plan);
	void editPlan(DietPlan& plan);


};

bool isNumber(const std::string& s); //got from stack exchange https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
