#include "DietPlan.hpp"

//DietPlan Methods
DietPlan::DietPlan(int cal, string name, string date)
{
	calGoal = cal;
	planName = name;
	planDate = date;
}
DietPlan::DietPlan()
{
	calGoal = 1600;
	planName = "New Plan";
	planDate = "Unknown";
}
DietPlan::DietPlan(const DietPlan& copyPlan)
{
	calGoal = copyPlan.calGoal;
	planDate = copyPlan.planDate;
	planName = copyPlan.planName;
}
DietPlan& DietPlan::operator=(const DietPlan& rhs)
{
	planName = rhs.planName;
	planDate = rhs.planDate;
	calGoal = rhs.calGoal;
	return *this; //no dangling pointer
}
int DietPlan::getGoal() const
{
	return calGoal;
}
string DietPlan::getName() const
{
	return planName;
}
string DietPlan::getDate() const
{
	return planDate;
}
void DietPlan::setGoal(int newGoal)
{
	calGoal = newGoal;
}
void DietPlan::setDate(string newDate)
{
	planDate = newDate;
}
void DietPlan::setName(string newName)
{
	planName = newName;
}

std::ostream& operator<< (std::ostream& lhs, const DietPlan& plan) //basically toString() implementation in Java. cout << planName will print this
{
	lhs << plan.getName() << "   " << plan.getDate() << "   " << plan.getGoal() << "   " << endl;
	return lhs;
}

std::istream& operator>>(std::istream& infile, DietPlan& plan)
{
	string grabber = "";
	getline(infile, grabber); //grabbing the name
	plan.setName(grabber);
	getline(infile, grabber); //grabbing the date
	plan.setDate(grabber);
	getline(infile, grabber); //grabbing the goal
	plan.setGoal(stoi(grabber));
	getline(infile, grabber); //grabbing the empty line for formatting purposes
	return infile;
}

DietPlan::~DietPlan()
{
	//don't need to do anything here
}

std::fstream& operator<< (std::fstream& outfile, DietPlan& plan)
{
	outfile << plan.getName() << endl << plan.getDate() << endl << plan.getGoal() << endl << endl;
	return outfile;
}