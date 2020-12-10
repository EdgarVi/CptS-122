///////////////////////////////////////////////////////////////////////////////
/// \file         FitnessAppWrapper.cpp
/// \author       Edgar Villasenor
/// \date         10/12/17
/// \brief        Methods that drive the application
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
#include "FitnessAppWrapper.h"

///////////////////////////////////////////////////////////////////////
/// FitnessAppWrapper ()
/// \pre    None
/// \post   Applicaton object has been instantiated and files have been opened
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
FitnessAppWrapper::FitnessAppWrapper()
{
	mDietPlanStream.open("dietPlans.txt");
	mExercisePlanStream.open("exercisePlans.txt");
}

///////////////////////////////////////////////////////////////////////
/// ~FitnessAppWrapper ()
/// \pre    Application running
/// \post   Application done running and files are closed
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
FitnessAppWrapper::~FitnessAppWrapper()
{
	if (mDietPlanStream.is_open()) {
		mDietPlanStream.close();
	}

	if (mExercisePlanStream.is_open()) {
		mExercisePlanStream.close();
	}
}

///////////////////////////////////////////////////////////////////////
/// runApp ()
/// \pre    Application instantiated
/// \post   Application done running and files are closed
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::runApp(void)
{
	cout << "Inside application" << endl;

	displayMenu();
}

///////////////////////////////////////////////////////////////////////
/// loadDailyPlan ()
/// \pre    Application instantiated
/// \post   DietPlan loaded from fileStream
/// \param  fileStream and plan
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::loadDailyPlan(fstream & fileStream, DietPlan & plan)
{
	fileStream >> plan;
}

///////////////////////////////////////////////////////////////////////
/// loadDailyPlan ()
/// \pre    Application instantiated
/// \post   ExercisePlan loaded from fileStream
/// \param  fileStream and plan
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::loadDailyPlan(fstream & fileStream, ExercisePlan & plan)
{
	fileStream >> plan;
}

///////////////////////////////////////////////////////////////////////
/// loadWeeklyPlan ()
/// \pre    weeklyPlan created and fileStream is open
/// \post   Entire DietPlan loaded from fileStream
/// \param  fileStream and weeklyPlan
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::loadWeeklyPlan(fstream & fileStream, DietPlan weeklyPlan[])
{
	int i = 0;
	char line[100] = "";
	while (!fileStream.eof()) {
		fileStream >> weeklyPlan[i];
		i++;
	}
}

///////////////////////////////////////////////////////////////////////
/// loadWeeklyPlan ()
/// \pre    weeklyPlan created and fileStream is open
/// \post   Entire ExercisePlan loaded from fileStream
/// \param  fileStream and weeklyPlan
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::loadWeeklyPlan(fstream & fileStream, ExercisePlan weeklyPlan[])
{
	int i = 0;
	char line[100] = "";
	while (!fileStream.eof()) {
		fileStream >> weeklyPlan[i]; // read from file
		i++;
	}
}

///////////////////////////////////////////////////////////////////////
/// displayDailyPlan ()
/// \pre    DietPlan loaded from stream
/// \post   Display plan to screen
/// \param  plan
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::displayDailyPlan(DietPlan & plan)
{
	cout << plan;
}

///////////////////////////////////////////////////////////////////////
/// displayDailyPlan ()
/// \pre    ExercisePlan loaded from stream
/// \post   Display plan to screen
/// \param  plan
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::displayDailyPlan(ExercisePlan & plan)
{
	cout << plan;
}

///////////////////////////////////////////////////////////////////////
/// displayWeeklyPlan ()
/// \pre    DietPlan loaded from stream
/// \post   Display DietPlan to screen
/// \param  weeklyPlan
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[])
{
	int i = 0;

	while (i < 7) {
		cout << weeklyPlan[i]; //write to screen
		i++;
	}
}

///////////////////////////////////////////////////////////////////////
/// displayWeeklyPlan ()
/// \pre    ExercisePlan loaded from stream
/// \post   Display ExercisePlan to screen
/// \param  weeklyPlan
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[])
{
	int i = 0;

	while (i < 7) {
		cout << weeklyPlan[i]; //write to screen
		i++;
	}
}

///////////////////////////////////////////////////////////////////////
/// storeDailyPlan ()
/// \pre    DietPlan loaded from stream
/// \post   Write plan to fileStream
/// \param  plan
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::storeDailyPlan(fstream & fileStream, DietPlan & plan)
{
	fileStream << plan;
}

///////////////////////////////////////////////////////////////////////
/// storeDailyPlan ()
/// \pre    ExercisePlan loaded from stream
/// \post   Write plan to fileStream
/// \param  plan
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::storeDailyPlan(fstream & fileStream, ExercisePlan & plan)
{
	fileStream << plan;
}

///////////////////////////////////////////////////////////////////////
/// storeWeeklyPlan ()
/// \pre    DietPlan loaded from stream
/// \post   Write plan to fileStream
/// \param  plan
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::storeWeeklyPlan(fstream & fileStream, DietPlan weeklyPlan[])
{

	fileStream.close(); 

	fileStream.open("dietPlans.txt", fstream::out, fstream::trunc); // Delete current contents of file and open for writing

	int i = 0;
	while (i < 7) {
		fileStream << weeklyPlan[i]; 
		i++;
	}
}

///////////////////////////////////////////////////////////////////////
/// storeWeeklyPlan ()
/// \pre    ExercisePlan loaded from stream
/// \post   Write plan to fileStream
/// \param  plan
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::storeWeeklyPlan(fstream & fileStream, ExercisePlan weeklyPlan[])
{
	fileStream.close();

	fileStream.open("dietPlans.txt", fstream::out, fstream::trunc); // Delete current contents of file and open for writing

	int i = 0;
	while (i < 7) {
		fileStream << weeklyPlan[i];
		i++;
	}
}

///////////////////////////////////////////////////////////////////////
/// editDailyPlan ()
/// \pre    DietPlan loaded from stream
/// \post   Edit goal
/// \param  weeklyPlan
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::editDailyPlan(DietPlan weeklyPlan[])
{
	string daySelected;
	int i = 0;

	cout << "Select the day (Sunday - Saturday) that you would like to edit" << endl;

	cin >> daySelected;

	while (weeklyPlan[i].getPlanName() != daySelected) {
		//look for correct day
		i++;
	}

	if (weeklyPlan[i].getPlanName() == daySelected) {
		cout << "Current Goal Calories: ";
		cout << weeklyPlan[i].getGoalCalories() << endl;
		weeklyPlan[i].editGoal();
	} else {
		cout << "Please enter a valid day (Sunday - Saturday)" << endl; //recursive call
		editDailyPlan(weeklyPlan);
	}
}

///////////////////////////////////////////////////////////////////////
/// editDailyPlan ()
/// \pre    ExercisePlan loaded from stream
/// \post   Edit goal
/// \param  weeklyPlan
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::editDailyPlan(ExercisePlan weeklyPlan[])
{
	string daySelected;
	int i = 0;

	cout << "Select the day (Sunday - Saturday) that you would like to edit" << endl;

	cin >> daySelected;

	while (weeklyPlan[i].getExerciseName() != daySelected) {
		i++;
	}

	if (weeklyPlan[i].getExerciseName() == daySelected) {
		cout << "Current Goal Steps: ";
		cout << weeklyPlan[i].getGoalSteps() << endl;
		weeklyPlan[i].editGoal();
	}
	else {
		cout << "Please enter a valid day (Sunday - Saturday)" << endl;
		editDailyPlan(weeklyPlan);
	}
}

///////////////////////////////////////////////////////////////////////
/// displayMenu ()
/// \pre    Application is running
/// \post   Application will be ended
/// \param  None
/// \return	Void
/// \throw	No exception handling
///////////////////////////////////////////////////////////////////////
void FitnessAppWrapper::displayMenu(void)
{
	int option = 0;


	DietPlan weeklyDietPlan[7];
	ExercisePlan weeklyExercisePlan[7];

	do {
		cout << "MENU\n1. Load Weekly Diet Plan\n2. Load Weekly Excercise Plan\
				\n3. Store Weekly Diet Plan\n4. Store Weekly Excercise Plan\
				\n5. Display Weekly Diet Plan\n6. Display Weekly Excercise Plan\
				\n7. Edit Daily Diet Plan\n8. Edit Daily Excercise Plan\n9. Exit" << endl;
		cin >> option;

		switch (option) {
		case 1:
			loadWeeklyPlan(mDietPlanStream, weeklyDietPlan);
			break;
		case 2:
			loadWeeklyPlan(mExercisePlanStream, weeklyExercisePlan);
			break;
		case 3:
			storeWeeklyPlan(mDietPlanStream, weeklyDietPlan);
			break;
		case 4:
			storeWeeklyPlan(mExercisePlanStream, weeklyExercisePlan);
			break;
		case 5:
			displayWeeklyPlan(weeklyDietPlan);
			break;
		case 6:
			displayWeeklyPlan(weeklyExercisePlan);
			break;
		case 7:
			editDailyPlan(weeklyDietPlan);
			break;
		case 8:
			editDailyPlan(weeklyExercisePlan);
			break;
		case 9:
			cout << "Ending Application" << endl;
			break;
		}
	} while (option != 9);


}
