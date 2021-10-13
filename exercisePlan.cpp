/*****************************************************************************************
* Programmer: Josh Maloy                                                                 *
* Class: CptS 122, Fall 2021; Lab Section 1                                              *
* Programming Assignment: PA4                                                            *
* Date: October 13, 2021                                                                 *
* Description: this program contains all necessary methods for the exercisePlan object to*
* function as intended.																	 *
******************************************************************************************/

#include "ExercisePlan.hpp"

//ExercisePlan Methods
ExercisePlan::ExercisePlan(int goal, string name, string date)
{
	stepGoal = goal;
	planName = name;
	planDate = date;
}
ExercisePlan::ExercisePlan()
{
	stepGoal = 5000;
	planName = "New Plan";
	planDate = "Unknown";
}
ExercisePlan::ExercisePlan(const ExercisePlan& copyPlan)
{
	stepGoal = copyPlan.stepGoal;
	planDate = copyPlan.planDate;
	planName = copyPlan.planName;
}
ExercisePlan& ExercisePlan::operator=(const ExercisePlan& rhs)
{
	planName = rhs.planName;
	planDate = rhs.planDate;
	stepGoal = rhs.stepGoal;
	return *this; // no dangling pointer
}
int ExercisePlan::getGoal() const
{
	return stepGoal;
}
string ExercisePlan::getName() const
{
	return planName;
}
string ExercisePlan::getDate() const
{
	return planDate;
}
void ExercisePlan::setGoal(int newGoal)
{
	stepGoal = newGoal;
}
void ExercisePlan::setName(string newName)
{
	planName = newName;
}
void ExercisePlan::setDate(string newName)
{
	planDate = newName;
}

ExercisePlan::~ExercisePlan()
{
	//don't need to do anything here
}

std::ostream& operator<< (std::ostream& lhs, const ExercisePlan& plan)
{
	lhs << plan.getName() << "   " << plan.getDate() << "   " << plan.getGoal() << "   " << endl;
	return lhs;
}

std::fstream& operator>> (std::fstream& infile, ExercisePlan& plan)
{
	string grabber = "";
	getline(infile, grabber);
	plan.setName(grabber);
	getline(infile, grabber);
	plan.setDate(grabber);
	getline(infile, grabber);
	plan.setGoal(stoi(grabber));
	getline(infile, grabber);
	return infile;
}

std::fstream& operator<< (std::fstream& outfile, ExercisePlan& plan)
{
	outfile << plan.getName() << endl << plan.getDate() << endl << plan.getGoal() << endl << endl;
	return outfile;
}