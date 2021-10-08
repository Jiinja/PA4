#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::string;
using std::fstream;
using std::endl;
using std::cin;
using std::getline;

class ExercisePlan
{
public:
	ExercisePlan(int goal, string name, string date);
	ExercisePlan();
	ExercisePlan(const ExercisePlan& copyPlan); //describes how to copy ExercisePlan objects
	ExercisePlan& operator = (const ExercisePlan& rhs);
	int getGoal() const;
	string getName() const;
	string getDate() const;
	void setGoal(int newGoal);
	void setName(string newName);
	void setDate(string newName);
	~ExercisePlan();
private:
	int stepGoal;
	string planName;
	string planDate;
};

std::ostream& operator<< (std::ostream& lhs, const ExercisePlan& plan);
std::istream& operator>> (std::istream& infile, ExercisePlan& plan);
std::fstream& operator<< (std::fstream& outfile, ExercisePlan& plan);