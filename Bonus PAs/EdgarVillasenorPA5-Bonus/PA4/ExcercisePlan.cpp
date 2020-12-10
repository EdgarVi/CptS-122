///////////////////////////////////////////////////////////////////////////////
/// \file    ExcercisePlan.cpp    
/// \author	 Edgar Villasenor
/// \date    11/17/17
/// \brief   You are to write a basic fitness application, in C++, 
///          that allows the user of the application to manually edit 
///          “diet” and “exercise” plans.For this application you will 
///          need to create three classes : DietPlan, ExercisePlan, and FitnessAppWrapper.     
///           
///       
/// REVISION HISTORY:
/// \date  
///          11/17/17
///////////////////////////////////////////////////////////////////////////////
#include "ExcercisePlan.h"

///////////////////////// Member functions ///////////////////////////////////////////
ExcercisePlan::ExcercisePlan(const string & newPlanName, const string & newDate, const int & newGoalSteps)
{
	this->mPlanName = newPlanName;
	this->mDate = newDate;
	this->mGoalSteps = newGoalSteps;
	cout << "Inside ExcercisePlan's constructor" << endl;
}

ExcercisePlan::ExcercisePlan(const ExcercisePlan & copy)
{
	this->mPlanName = copy.mPlanName;  // this is copy a std::string to another one; std::string is an object, 
									   // so the overloaded assignment for one is called here!
	this->mDate = copy.mDate;  // calls std::string overloaded assignment operator!
	this->mGoalSteps = copy.mGoalSteps;  // simple assignment between integers
}

ExcercisePlan::~ExcercisePlan()
{
	cout << "Inside of ExcercisePlan's destructor!" << endl;
}

string ExcercisePlan::getPlanName() const
{
	return this->mPlanName;
}

string ExcercisePlan::getDate() const
{
	return this->mDate;
}

int ExcercisePlan::getGoalSteps() const
{
	return this->mGoalSteps;
}

void ExcercisePlan::setPlanName(const string & newPlanName)
{
	this->mPlanName = newPlanName; // calls std::string overloaded assignment (=) operator
}

void ExcercisePlan::setDate(const string & newDate)
{
	this->mDate = newDate; // calls std::string overloaded assignment (=) operator
}

void ExcercisePlan::setGoalSteps(const int & newGoalSteps)
{
	this->mGoalSteps = newGoalSteps;

}

ExcercisePlan & ExcercisePlan::operator=(const ExcercisePlan & rhs)
{
	// check for self assignment
	if (this != &rhs) // the & here is the "address of" operator
	{
		// we are not peforming self-assignment if inside here
		this->mPlanName = rhs.mPlanName;  // this is copy a std::string to another one; std::string is an object, 
										  // so the overloaded assignment (=) for one is called here!
		this->mDate = rhs.mDate;  // calls std::string overloaded assignment (=) operator!
		this->mGoalSteps = rhs.mGoalSteps;  // simple assignment between integers
	}

	return (*this);
}

void ExcercisePlan::editGoal()
{
	cout << "Please enter a new Steps goal: ";
	cin >> this->mGoalSteps;

	cout << (*this) << endl; // can use "*this" here because we've overloaded the stream insertion << (ostream, DietPlan) 
							 // and we want to see the current object's plan details
}

ostream & operator<<(ostream & lhs, const ExcercisePlan & rhs)
{
	lhs << rhs.getPlanName() << endl << rhs.getGoalSteps() << endl << rhs.getDate();

	return lhs; // allows for chaining of stream insertions cout << DietPlan object1 << DietPlan object2...
}

fstream & operator<<(fstream & lhs, const ExcercisePlan & rhs)
{
	// cast lhs to ofstream so can easily output std::string (plan name)
	((ofstream &)(lhs)) << rhs.getPlanName() << endl << rhs.getGoalSteps() << endl << rhs.getDate();

	return lhs; // allows for chaining of stream insertions fstr << DietPlan object1 << DietPlan object2...
}


fstream & operator >> (fstream & lhs, ExcercisePlan & rhs)
{
	char tempString[100] = "";
	lhs.getline(tempString, 100); // read the plan name, including the newline in the file
	rhs.setPlanName(tempString); // when the char * is passed into setPlanName a std::string is constructed and
								 // initialized with the char * value 
	int goalSteps = 0;
	lhs.getline(tempString, 100);  // read the goal calories line as a string, then convert to an integer, this way we can read in the newline
	goalSteps = atoi(tempString); // convert the char * string representation to its corresponding integer, i.e. "42" to 42 int
	rhs.setGoalSteps(goalSteps);
	lhs.getline(tempString, 100);  // read the date from the file, also reads newline
	rhs.setDate(tempString);

	return lhs; // allows for chaining of stream extractions fstr >> DietPlan object1 >> DietPlan object2...
}
