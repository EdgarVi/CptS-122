///////////////////////////////////////////////////////////////////////////////
/// \file         ExercisePlan.h
/// \author       Edgar Villasenor
/// \date         10/18/17
/// \brief        This application creates basic exercise plans
///           
///       
/// REVISION HISTORY:
/// \date	10/11/17
///			10/12/17
///         10/15/17   
///			10/16/17
///			10/17/17
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


class ExercisePlan {
public:

	/* Constructors */
	ExercisePlan(int newGoalSteps = 0, string newExcerciseName = "/0", string newDate = "/0");
	ExercisePlan(ExercisePlan & copy);
	~ExercisePlan();

	/* Getters */
	int getGoalSteps() const;
	string getExerciseName() const;
	string getDate() const;

	/* Setters */
	void setGoalSteps(int newGoalSteps);
	void setExerciseName(string newExcerciseName);
	void setDate(string newDate);

	/* Other member funcitons */
	void editGoal();


private:
	/* Attributes */
	int mGoalSteps;
	string mExerciseName;
	string mDate;

	fstream mExercisePlanStream;
};

ostream & operator << (ostream &lhs, ExercisePlan &rhs); // write to screen
fstream & operator << (fstream & output, ExercisePlan &rhs); // write to file
fstream & operator >> (fstream & input, ExercisePlan &rhs); // read from file