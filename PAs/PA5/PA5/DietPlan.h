///////////////////////////////////////////////////////////////////////////////
/// \file         DietPlan.h
/// \author       Edgar Villasenor
/// \date         10/18/17
/// \brief        This application creates basic diet plans
///           
///       		
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <fstream>
#include <string>


using std::string;
using std::cin;
using std::cout;
using std::endl;


using namespace std;

class DietPlan {
public:
	/* Constructors */
	DietPlan(int newGoalCalories = 0, string newPlanName = "\0", string newDate = "\0"); /* Default constructor */
	DietPlan(DietPlan & copy); /* create shallow copy */
	~DietPlan();


	/* Getters */
	int getGoalCalories() const;
	string getPlanName() const;
	string getDate() const;

	/* Setters */
	void setGoalCalories(int newGoalCalories);
	void setPlanName(string newPlanName);
	void setDate(string newDate);

	/* Other Member Functions */
	void editGoal();

private:
	/* Object attributes */
	int mGoalCalories;
	string mPlanName;
	string mDate;
};

/* Non-Member Functions*/
ostream & operator << (ostream &lhs, DietPlan &rhs); // write to screen
fstream & operator << (fstream & output, DietPlan &rhs); // write to file
fstream & operator >> (fstream & input, DietPlan &rhs); // read from file
