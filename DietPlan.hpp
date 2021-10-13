/*****************************************************************************************
* Programmer: Josh Maloy                                                                 *
* Class: CptS 122, Fall 2021; Lab Section 1                                              *
* Programming Assignment: PA4                                                            *
* Date: October 13, 2021                                                                 *
* Description: this program contains all necessary method definitions for the            *
* dietPlan object to function as intended.										     *
******************************************************************************************/

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
std::fstream& operator>>(std::fstream& infile, DietPlan& plan);
std::fstream& operator<< (std::fstream& outfile, DietPlan& plan);
