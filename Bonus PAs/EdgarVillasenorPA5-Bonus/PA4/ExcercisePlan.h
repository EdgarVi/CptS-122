///////////////////////////////////////////////////////////////////////////////
/// \file         ExcercisePlan.h
/// \author       Edgar Villasenor
/// \date         11/17/17
/// \brief        Constructors and methods for a diet plan that contains a plan name, date
///				  goal calories
///       
/// REVISION HISTORY:
/// \date  
///				  11/17/17
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ofstream;

class ExcercisePlan
{
public:
	//Constructors
	ExcercisePlan(const string &newPlanName = "", const string &newDate = "", const int &newGoalSteps = 0);
	ExcercisePlan(const ExcercisePlan &copy);
	~ExcercisePlan();

	

	//Getters
	string getPlanName() const;
	string getDate() const;
	int getGoalSteps() const;

	//Setters
	void setPlanName(const string &newPlanName);
	void setDate(const string &newDate);
	void setGoalSteps(const int &newGoalSteps);

	//Other member functions
	ExcercisePlan &operator=(const ExcercisePlan &rhs);
	void editGoal();

private:
	string mPlanName;
	string mDate;
	int mGoalSteps;
};

//Non member functions
ostream & operator<< (ostream &lhs, const ExcercisePlan &rhs); // will allow cout << DietPlan object1 << ExcercisePlan object2...
														  // write a complete ExcercisePlan to a file
fstream & operator<< (fstream &lhs, const ExcercisePlan &rhs); // will allow fstr << DietPlan object1 << ExcercisePlan object2... 
														  // read a complete ExcercisePlan from a file
fstream & operator >> (fstream &lhs, ExcercisePlan &rhs); // will allow fstr >> ExcercisePlan object1 >> ExcercisePlan object2...