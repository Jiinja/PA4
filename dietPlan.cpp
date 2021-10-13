/*****************************************************************************************
* Programmer: Josh Maloy                                                                 *
* Class: CptS 122, Fall 2021; Lab Section 1                                              *
* Programming Assignment: PA4                                                            *
* Date: October 13, 2021                                                                 *
* Description: this program contains all necessary methods for the dietPlan object to    *
* function as intended.																	 *
******************************************************************************************/


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

std::fstream& operator>>(std::fstream& infile, DietPlan& plan)
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