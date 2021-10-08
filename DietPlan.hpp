#include "ExercisePlan.hpp"

class DietPlan
{
public:
	DietPlan(int cal, string name, string date);
	DietPlan();
	DietPlan(const DietPlan& copyPlan); //describes how to copy dietplan objects
	DietPlan& operator=(const DietPlan& rhs);
	int getGoal() const;
	string getName() const;
	string getDate() const;
	void setName(string newName);
	void setDate(string newDate);
	void setGoal(int newGoal);
	~DietPlan();
private:
	int calGoal;
	string planName;
	string planDate;
};

std::ostream& operator<< (std::ostream& lhs, const DietPlan& plan);
std::istream& operator>>(std::istream& infile, DietPlan& plan);
std::fstream& operator<< (std::fstream& outfile, DietPlan& plan);
