///////////////////////////////////////////////////////////////////////////////
/// \file         FitnessAppWrapper.h
/// \author       Edgar Villasenor
/// \date         10/18/17
/// \brief        Drives the application
///           
///       
/// REVISION HISTORY:
/// \date	10/12/17
///			10/13/17
///			10/15/17
///         10/16/17   
///			10/17/17
///			10/18/17
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "DietPlan.h"
#include "ExercisePlan.h"

using std::cin;
using std::cout;
using std::endl;
using std::ios;
using namespace std;

class FitnessAppWrapper {

public:
	FitnessAppWrapper(); //constructor - open files
	~FitnessAppWrapper(); //destructor - close files

	void runApp(void);

	// Load functions
	void loadDailyPlan(fstream &fileStream, DietPlan &plan);
	void loadDailyPlan(fstream &fileStream, ExercisePlan &plan);
	void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]);

	// Display functions
	void displayDailyPlan(DietPlan &plan);
	void displayDailyPlan(ExercisePlan & plan);
	void displayWeeklyPlan(DietPlan weeklyPlan[]);
	void displayWeeklyPlan(ExercisePlan weeklyPlan[]);

	// Store functions
	void storeDailyPlan(fstream &fileStream, DietPlan &plan);
	void storeDailyPlan(fstream &fileStream, ExercisePlan &plan);
	void storeWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void storeWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]);

	// Edit functions
	void editDailyPlan(DietPlan weeklyPlan[]);
	void editDailyPlan(ExercisePlan weeklyPlan[]);

	// Display Menu
	void displayMenu(void);

private:
	/* Files */
	fstream mDietPlanStream;
	fstream mExercisePlanStream;

};
