///////////////////////////////////////////////////////////////////////////////
/// \file         Main Program App (main.cpp)
/// \author       Edgar Villasenor
/// \date         18 October 2017
/// \brief        This is a basic fitness application. The application
///				  reads diet and exercise plans from a file. Users
///				  may edit goal calories or goals steps to be completed
///              
///           
///       
/// REVISION HISTORY:
/// \date		10/11/17
///				10/12/17
///				10/13/17
///				10/16/17
///				10/17/17
///				10/18/17
///////////////////////////////////////////////////////////////////////////////

#include "FitnessAppWrapper.h"

#include <fstream>

using namespace std;

int main(void) {


	FitnessAppWrapper Application; // Instantiate application

	Application.runApp(); // Run application

	return 0;
}