///////////////////////////////////////////////////////////////////////////////
/// \file         ExcercisePlan.cpp
/// \author       Edgar Villasenor
/// \date         10/18/17
/// \brief        This application creates basic excercise plans
///           
///       
/// REVISION HISTORY:
/// \date	10/11/17
///			10/12/17
///         10/15/17   
///			10/16/17
///			10/17/17
///////////////////////////////////////////////////////////////////////////////
#include "ExercisePlan.h"

///////////////////////////////////////////////////////////////////////
/// ExercisePlan ()
/// \pre    None
/// \post   ExercisePlan object has been instantiated
/// \param  newGoalSteps, newPlanName, newDate
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
ExercisePlan::ExercisePlan(int newGoalSteps, string newExerciseName, string newDate)
{

	mGoalSteps = newGoalSteps;
	mExerciseName = newExerciseName;
	mDate = newDate;

}

///////////////////////////////////////////////////////////////////////
/// ExercisePlan()
/// \pre    ExercisePlan has been instantiated
/// \post   Shallow copy has been created
/// \param  ExercisePlan object
/// \return Copy of ExercisePlan
/// \throw  No exception handling
///////////////////////////////////////////////////////////////////////
ExercisePlan::ExercisePlan(ExercisePlan & copy)
{

	mGoalSteps = copy.getGoalSteps();
	mExerciseName = copy.getExerciseName();
	mDate = copy.getDate();

}

///////////////////////////////////////////////////////////////////////
/// ~ExercisePlan ()
/// \pre    ExercisePlan type object exists
/// \post   None
/// \param  (repeat for every parameter)
/// \return	None
/// \throw  No exception handling
///////////////////////////////////////////////////////////////////////
ExercisePlan::~ExercisePlan()
{
	//This doesn't need to do anything becuase we are not using dynamic memory
}

///////////////////////////////////////////////////////////////////////
/// getGoalSteps ()
/// \pre    ExercisePlan has been instantiated
/// \post   Goal steps has been sent  
/// \param  None
/// \return mGoalSteps
/// \throw  No exception handling
///////////////////////////////////////////////////////////////////////
int ExercisePlan::getGoalSteps() const
{
	return mGoalSteps;
}

///////////////////////////////////////////////////////////////////////
/// getExerciseName ()
/// \pre    ExercisePlan has been instantiated 
/// \post   Exercise name has been sent
/// \param  None
/// \return mExerciseName
/// \throw  No exception handling
///////////////////////////////////////////////////////////////////////
string ExercisePlan::getExerciseName() const
{
	return mExerciseName;
}

///////////////////////////////////////////////////////////////////////
/// getDate ()
/// \pre    ExercisePlan has been instantiated 
/// \post   Date has been set
/// \param  None
/// \return mDate
/// \throw  No exception handling
///////////////////////////////////////////////////////////////////////
string ExercisePlan::getDate() const
{
	return mDate;
}

///////////////////////////////////////////////////////////////////////
/// setGoalSteps ()
/// \pre    ExercisePlan has been instantiated
/// \post   mGoalSteps has been set to newGoalSteps
/// \param  newGoalSteps
/// \return Void
/// \throw  No exception handling
///////////////////////////////////////////////////////////////////////
void ExercisePlan::setGoalSteps(int newGoalSteps)
{
	mGoalSteps = newGoalSteps;
}

///////////////////////////////////////////////////////////////////////
/// setExerciseName ()
/// \pre    ExercisePlan has been instantiated
/// \post   mExerciseName has been set to newExerciseName
/// \param  newExerciseName
/// \return Void
/// \throw  No exception handling
///////////////////////////////////////////////////////////////////////
void ExercisePlan::setExerciseName(string newExerciseName)
{
	mExerciseName = newExerciseName;
}

///////////////////////////////////////////////////////////////////////
/// setDate ()
/// \pre    ExercisePlan has been instantiated
/// \post   mDate has been set to newDate
/// \param  newDate
/// \return Void
/// \throw  No exception handling
///////////////////////////////////////////////////////////////////////
void ExercisePlan::setDate(string newDate)
{
	mDate = newDate;
}

///////////////////////////////////////////////////////////////////////
/// editGoal ()
/// \pre    Goal has been set
/// \post   Goal has been set to new goal
/// \param  None
/// \return Void
/// \throw  No exception handling 
///////////////////////////////////////////////////////////////////////
void ExercisePlan::editGoal()
{
	int newGoal = 0;
	cin >> newGoal;

	this->setGoalSteps(newGoal);

	//cout << this->getGoalSteps() << endl;
	cout << *this;
}

///////////////////////////////////////////////////////////////////////
/// operator<< ()
/// \pre    ExercisePlan has been initialized
/// \post   ExercisePlan has been displayed to screen
/// \param  Outstream and ExercisePlan
/// \return Void
/// \throw  No exception handling 
///////////////////////////////////////////////////////////////////////
ostream & operator<<(ostream & lhs, ExercisePlan & rhs)
{
	lhs << rhs.getExerciseName() << endl << rhs.getGoalSteps() << endl << rhs.getDate() << endl << endl;

	return lhs;
}

///////////////////////////////////////////////////////////////////////
/// operator<< ()
/// \pre    Stream has been opened and ExercisePlan has been initialized
/// \post   ExercisePlan has been written to file
/// \param  File and ExercisePlan
/// \return None
/// \throw  No exception handling 
///////////////////////////////////////////////////////////////////////
fstream & operator<<(fstream & output, ExercisePlan & rhs)
{
	//write to file
	output << rhs.getExerciseName() << endl << rhs.getGoalSteps() << endl << rhs.getDate() << endl << endl;

	return output;
}

///////////////////////////////////////////////////////////////////////
/// operator>> ()
/// \pre	Stream has been opened and ExercisePlan is initialized
/// \post   ExercisePlan parsed from file
/// \param  File and ExercisePlan
/// \return Void
/// \throw  No exception handling 
///////////////////////////////////////////////////////////////////////
fstream & operator >> (fstream & input, ExercisePlan & rhs)
{

	char line[100] = "";

	string emptyLine;

	string planName;
	int goal = 0;
	string date;


	input.getline(line, 100, '\n');
	planName = line;
	rhs.setExerciseName(planName);

	input.getline(line, 100, '\n');
	goal = atoi(line);
	rhs.setGoalSteps(goal);

	input.getline(line, 100, '\n');
	date = line;
	rhs.setDate(date);

	input.getline(line, 100, '\n');
	emptyLine = line; //Move cursor to next line

	return input;
}
