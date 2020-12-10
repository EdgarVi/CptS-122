///////////////////////////////////////////////////////////////////////////////
/// \file         DietPlan.cpp
/// \author       Edgar Villasenor
/// \date         10/11/17
/// \brief        This application creates basic diet plans
///           
///       
/// REVISION HISTORY:
/// \date	10/11/17
///			10/12/17
///         10/15/17
///			10/16/17
///			10/17/17
///			10/18/17
///////////////////////////////////////////////////////////////////////////////
#include "DietPlan.h"

///////////////////////////////////////////////////////////////////////
/// DietPlan ()
/// \pre    None
/// \post   DietPlan object has been instantiated
/// \param  newGoalCalories, newPlanName, newDate
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
DietPlan::DietPlan(int newGoalCalories, string newPlanName, string newDate)
{

	mGoalCalories = newGoalCalories;
	mPlanName = newPlanName;
	mDate = newDate;

}

///////////////////////////////////////////////////////////////////////
/// DietPlan()
/// \pre    DietPlan has been instantiated
/// \post   Shallow copy has been created
/// \param  Diet plan object
/// \return Copy of Diet Plan
/// \throw  No exception handling
///////////////////////////////////////////////////////////////////////
DietPlan::DietPlan(DietPlan & copy)
{

	mGoalCalories = copy.getGoalCalories();
	mPlanName = copy.getPlanName();
	mDate = copy.getDate();

}

///////////////////////////////////////////////////////////////////////
/// ~DietPlan ()
/// \pre    DietPlan type object exists
/// \post   None
/// \param  (repeat for every parameter)
/// \return	None
/// \throw  No exception handling
///////////////////////////////////////////////////////////////////////
DietPlan::~DietPlan()
{
	//This doesn't need to do anything becuase we are not using dynamic memory
}

///////////////////////////////////////////////////////////////////////
/// getGoalCalories ()
/// \pre    DietPlan has been instantiated
/// \post   Goal calories has been sent  
/// \param  None
/// \return New goal calories
/// \throw  No exception handling
///////////////////////////////////////////////////////////////////////
int DietPlan::getGoalCalories() const
{
	return mGoalCalories;
}

///////////////////////////////////////////////////////////////////////
/// getPlanName ()
/// \pre    DietPlan has been instantiated 
/// \post   Plan name has been sent
/// \param  None
/// \return PlanName
/// \throw  No exception handling
///////////////////////////////////////////////////////////////////////
string DietPlan::getPlanName() const
{
	return mPlanName;
}

///////////////////////////////////////////////////////////////////////
/// getDate ()
/// \pre    DietPlan has been instantiated 
/// \post   Date has been set
/// \param  None
/// \return Date
/// \throw  No exception handling
///////////////////////////////////////////////////////////////////////
string DietPlan::getDate() const
{
	return mDate;
}

///////////////////////////////////////////////////////////////////////
/// setGoalCalories ()
/// \pre    DietPlan has been instantiated
/// \post   mGoalCalories has been set to newGoalCalories
/// \param  newGoalCalories
/// \return Void
/// \throw  No exception handling
///////////////////////////////////////////////////////////////////////
void DietPlan::setGoalCalories(int newGoalCalories)
{
	mGoalCalories = newGoalCalories;
}

///////////////////////////////////////////////////////////////////////
/// setPlanName ()
/// \pre    DietPlan has been instantiated
/// \post   mPlanName has been set to newPlanName
/// \param  newPlanName
/// \return Void
/// \throw  No exception handling
///////////////////////////////////////////////////////////////////////
void DietPlan::setPlanName(string newPlanName)
{
	mPlanName = newPlanName;
}

///////////////////////////////////////////////////////////////////////
/// setStartingDate ()
/// \pre    DietPlan has been instantiated
/// \post   mDate has been set to newStartingDate
/// \param  newStartingDate
/// \return Void
/// \throw No exception handling 
///////////////////////////////////////////////////////////////////////
void DietPlan::setDate(string newStartingDate)
{
	mDate = newStartingDate;
}

///////////////////////////////////////////////////////////////////////
/// editGoal ()
/// \pre    Goal has been set
/// \post   Goal has been set to new goal
/// \param  None
/// \return Void
/// \throw  No exception handling 
///////////////////////////////////////////////////////////////////////
void DietPlan::editGoal()
{
	int newGoal = 0;

	cout << "New goal calories: ";

	cin >> newGoal;

	this->setGoalCalories(newGoal);

}


///////////////////////////////////////////////////////////////////////
/// operator<< ()
/// \pre    DietPlan has been initialized
/// \post   DietPlan has been displayed to screen
/// \param  Outstream and Dietplan
/// \return Void
/// \throw  No exception handling 
///////////////////////////////////////////////////////////////////////
ostream & operator<<(ostream & lhs, DietPlan & rhs)
{
	lhs << rhs.getPlanName() << endl << rhs.getGoalCalories() << endl << rhs.getDate() << endl << endl;

	return lhs;
}

///////////////////////////////////////////////////////////////////////
/// operator<< ()
/// \pre    Stream has been opened and DietPlan has been initialized
/// \post   DietPlan has been written to file
/// \param  File and DietPlan
/// \return None
/// \throw  No exception handling 
///////////////////////////////////////////////////////////////////////
fstream & operator<<(fstream & output, DietPlan & rhs)
{
	output << rhs.getPlanName() << endl << rhs.getGoalCalories() << endl << rhs.getDate() << endl << endl;

	return output;
}

///////////////////////////////////////////////////////////////////////
/// operator>> ()
/// \pre	Stream has been opened and DietPlan is initialized
/// \post   DietPlan parsed from file
/// \param  File and DietPlan
/// \return Void
/// \throw  No exception handling 
///////////////////////////////////////////////////////////////////////
fstream & operator >> (fstream & input, DietPlan & rhs)
{

	char line[100] = "";

	string emptyLine;

	string planName;
	int goal = 0;
	string date;

	input.getline(line, 100, '\n');
	planName = line;
	rhs.setPlanName(planName);

	input.getline(line, 100, '\n');
	goal = atoi(line);
	rhs.setGoalCalories(goal);

	input.getline(line, 100, '\n');
	date = line;
	rhs.setDate(date);

	input.getline(line, 100, '\n');
	emptyLine = line; //Move cursor to next line

	return input;
}






