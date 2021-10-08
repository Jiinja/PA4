#include "DietPlan.hpp"

class FitnessAppWrapper
{
public:
	void runApp();
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
	void exit();
	void editPlan(ExercisePlan& plan);
	void editPlan(DietPlan& plan);
private:

};

bool isNumber(const std::string& s); //got from stack exchange https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
