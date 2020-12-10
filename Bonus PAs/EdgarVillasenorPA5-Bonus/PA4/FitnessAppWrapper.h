///////////////////////////////////////////////////////////////////////////////
/// \file   FitnessAppWrapper.h 
/// \author	Edgar Villasenor
/// \date   11/17/17 
/// \brief   You are to write a basic fitness application, in C++, 
///          that allows the user of the application to manually edit 
///          “diet” and “exercise” plans.For this application you will 
///          need to create three classes : DietPlan, ExercisePlan, and FitnessAppWrapper.     
///           
///       
/// REVISION HISTORY:
/// \date  
///			11/17/17    
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdlib> // to use system("cls");

#include "DietPlan.h"
#include "ExcercisePlan.h"

class FitnessAppWrapper
{
public:
	FitnessAppWrapper(); // default constructor
	~FitnessAppWrapper(); // destructor

	void runApp(); // will drive the application
	void performUserSelection(const int &option);

	//Diet plan methods
	void loadWeeklyDietPlan(); // this will call the private loadWeeklyPlan() function
	void displayWeeklyDietPlan(); // this will call the private displayWeeklyPlan() function
	void storeWeeklyDietPlan(); // this will call the private storeWeeklyPlan() function
	bool editDietPlan(); // will prompt the user for the name of the plan to edit

	//Excercise plan methods
	void loadWeeklyExcercisePlan();
	void displayWeeklyExcercisePlan();
	void storeWeeklyExcercisePlan();
	bool editExcercisePlan();


private:
	DietPlan mDPList[7]; // will store the weekly list of DietPlan objects - 1 week = 7 days
	ExcercisePlan mEPList[7]; //store weekly list of ExcercisePlan objects

	fstream mFstrDP;    // stream object for input/output to dietPlans.txt
	fstream mFstrEP;	// stream object for i/o to excercisePlans.txt

	// private helper/utility functions
	void loadDailyPlan(fstream &fileStream, DietPlan &plan);
	void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void displayDailyPlan(const DietPlan &plan);
	void displayWeeklyPlan(const DietPlan weeklyPlan[]);
	void storeDailyPlan(fstream &fileStream, const DietPlan &plan);
	void storeWeeklyPlan(fstream &fileStream, const DietPlan weeklyPlan[]);

	//need to finish
	void loadDailyPlan(fstream &fileStream, ExcercisePlan &plan);
	void loadWeeklyPlan(fstream &fileStream, ExcercisePlan weeklyPlan[]);
	void displayDailyPlan(const ExcercisePlan &plan);
	void displayWeeklyPlan(const ExcercisePlan weeklyPlan[]);
	void storeDailyPlan(fstream &fileStream, const ExcercisePlan &plan);
	void storeWeeklyPlan(fstream &fileStream, const ExcercisePlan weeklyPlan[]);


	void displayMenu();
};