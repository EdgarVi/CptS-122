///////////////////////////////////////////////////////////////////////////////
/// \file         ApplicationMenu.h
/// \author       Edgar Villasenor
/// \date         8 November 2017
/// \brief        Class that drives the program
///
///
///              
///           
///       
///				
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>


#include "List.h"


#include "ChronicAbsenceReport.txt"
#include "StudentReport.txt"
#include "Master.txt"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;

using std::fstream;

using std::string;

using namespace std;

class ApplicationMenu {

public:
	//constructors
	ApplicationMenu();
	~ApplicationMenu();


	//application methods
	void displayMenu();
	void importCourseList(fstream &filestream, List &studentList);
	void loadMasterList(fstream &filestream, List &studentList);
	void StoreMasterList(fstream &filestream, List &studentList);
	void markAbsences(List &studentList);
	void GenerateStudentReport(fstream &filestream, List &studentList);
	void GenerateChronicAbsenceReport(fstream &filestream, List &studentList, int &threshold);


private:
	//member attributes
	List attendanceList;
	fstream mClassListStream;
	fstream	mChronicAbsenceStream;
	fstream mStudentReportStream;
	fstream mMasterStream;

};