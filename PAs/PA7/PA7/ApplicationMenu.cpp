///////////////////////////////////////////////////////////////////////////////
/// \file         ApplicationMenu.cpp
/// \author       Edgar Villasenor
/// \date         8 November 2017
/// \brief        Contains the methods for the menu application
///
///
///              
///           
///       
///				
///////////////////////////////////////////////////////////////////////////////
#include "ApplicationMenu.h"

ApplicationMenu::ApplicationMenu()
{
	//open streams
	mClassListStream.open("classList.csv");
	mChronicAbsenceStream.open("ChronicAbsenceReport.txt");
	mStudentReportStream.open("StudentReport.txt");
	mMasterStream.open("Master.txt");
}

ApplicationMenu::~ApplicationMenu()
{


	//close streams
	if (mClassListStream.is_open()) {
		mClassListStream.close();
	}

	if (mChronicAbsenceStream.is_open()) {
		mChronicAbsenceStream.close();
	}

	if (mStudentReportStream.is_open()) {
		mStudentReportStream.close();
	}

	if (mMasterStream.is_open()) {
		mMasterStream.close();
	}

}



void ApplicationMenu::displayMenu()
{
	int option = 0, subOption = 0;
	List MasterList;

	//menu selection
	do {
		cout << "1. Import course list\n2. Load master list\
				\n3. Store master list\n4. Mark absences\
				\n5. Edit absences\n6. Generate report\
				\n7. Exit" << endl;
		cin >> option;
		switch (option) {
		case 1:
			importCourseList(mClassListStream, MasterList);
			break;
		case 2:
			loadMasterList(mMasterStream, MasterList);
			break;
		case 3:
			StoreMasterList(mMasterStream, MasterList);
			break;
		case 4:
			markAbsences(MasterList);
			break;
		case 5:
			//Bonus feature
			cout << "This feature is not available" << endl;
			break;
		case 6:
			//user has two options
			cout << "1. Generate report for all students\n2. Generate report for students with certain number of absences" << endl;
			cin >> subOption;
			//submenu
			switch (subOption) {
			 case 1:
				 GenerateStudentReport(mStudentReportStream, MasterList);
				break;
			 case 2:
				 int threshold = 0;
				 cout << "How many absences are acceptable before a student is under probation? ";
				 cout << "Absences: ";
				 cin >> threshold;
				 GenerateChronicAbsenceReport(mChronicAbsenceStream, MasterList, threshold);
				 break;
			}
			break;
		case 7:
			cout << "Ending application" << endl;
			break;
		}
	} while (option != 7);
}

void ApplicationMenu::importCourseList(fstream & filestream, List & studentList)
{
	//read from the original CSV file, mStudentListStream,
	//delete the contents of the original linked list and add the 
	//contents of mStudentListStream to the now empty linked list
	

	//delete the contents of the list if it is not empty
	if (studentList.getHeadPtr() != nullptr) {
		while (!studentList.getHeadPtr()) {
			studentList.deleteAtFront();
		}
	}
	

	string line;

	getline(filestream, line, '\n');

	cout << line << endl;

	int recordNum = 0, IDNum = 0, absences = 0;
	string name, email, units, program, level;
	studentList.setHeadPtr(nullptr);


	while (!filestream.eof()) {

		getline(filestream, line, ',');
		recordNum = stoi(line);

		cout << line << " ";

		getline(filestream, line, ',');
		IDNum = stoi(line);

		cout << line << " ";


		getline(filestream, line, ',');
		name = line;

		getline(filestream, line, ',');
		name = name + "," + line; //concatenate strings

		cout << line << " ";

		getline(filestream, line, ',');
		email = line;

		cout << line << " ";

		getline(filestream, line, ',');
		units = line;

		cout << line << " ";

		getline(filestream, line, ',');
		program = line;
		
		cout << line << " ";

		getline(filestream, line, '\n');
		level = line;

		cout << line << endl;

	

		//insert data to front of master list, note: number of absences and stack of absent days 
		//have not been initialized yet
		studentList.insertAtFront(recordNum, IDNum, name, email, units, program, level, absences, NULL);
	}

	
}

void ApplicationMenu::loadMasterList(fstream & filestream, List & studentList)
{
	//read from Master.txt, overwrite whatever is in studentList


	//delete the contents of the list if it is not empty
	if (studentList.getHeadPtr() != nullptr) {
		while (!studentList.getHeadPtr()) {
			studentList.deleteAtFront();
		}
	}


	//note Master.txt includes number of absences and most recent absence

	//read from file
	char line[1000] = "";

	filestream.getline(line, 1000, '\n');


	cout << line;
	int recordNum = 0, IDNum = 0, absences = 0;
	string name, email, units, program, level;
	Stack absentDays;


	while (!filestream.eof()) {

		filestream.getline(line, 25, ',');
		recordNum = atoi(line);

		filestream.getline(line, 25, ',');
		IDNum = atoi(line);

		filestream.getline(line, 25, ',');
		name = line;

		filestream.getline(line, 25, ',');
		name = name + line; //concatenate strings

		filestream.getline(line, 25, ',');
		email = line;

		filestream.getline(line, 25, ',');
		units = line;

		filestream.getline(line, 25, ',');
		program = line;

		filestream.getline(line, 25, ',');
		level = line;

		filestream.getline(line, 25, ',');
		absences = atoi(line);

		filestream.getline(line, 25, ',');
		absentDays.push(line);
		//insert data to front of Master List, note: number of absences and stack of absent days 
		//have not been initialized yet
		studentList.insertAtFront(recordNum, IDNum, name, email, units, program, level, absences, absentDays);
	}
}

void ApplicationMenu::StoreMasterList(fstream & filestream, List & studentList)
{
	//write contents of MasterList to Master.txt
	while (studentList.getHeadPtr() != nullptr) {
		filestream << studentList.getHeadPtr()->getRecordNumber() << ",";
		filestream << studentList.getHeadPtr()->getIDNumber() << ",";
		filestream << studentList.getHeadPtr()->getName() << ",";
		filestream << studentList.getHeadPtr()->getEmail() << ",";
		filestream << studentList.getHeadPtr()->getUnits() << ",";
		filestream << studentList.getHeadPtr()->getProgram() << ",";
		filestream << studentList.getHeadPtr()->getLevel() << ",";
		filestream << studentList.getHeadPtr()->getAbsences() << ",";
		filestream << studentList.getHeadPtr()->getAbsentStack().peek() << endl; //get most recent absence from top of stack
		studentList.setHeadPtr(studentList.getHeadPtr()->getNextPtr());
	}

}

void ApplicationMenu::markAbsences(List & studentList)
{
	//mark absences of each node in the linked list

	int isAbsent = 0;

	while (studentList.getHeadPtr() != nullptr) {
		cout << "Is " << studentList.getHeadPtr()->getName() << " absent? (Enter 0 for FALSE, 1 for TRUE)" << endl;
		cin >> isAbsent;


		if (isAbsent == 1) {
			// retrieved from stackoverflow - http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c 
			string date;
			time_t t = time(0);   // get time now
			struct tm * now = localtime(&t);
			date = (now->tm_year + 1900);
			date = date + "-";
			date = date + to_string((now->tm_mon + 1));
			date = date + "-";
			date = date + to_string(now->tm_mday);

			Stack Absence;

			Absence.push(date); //push to top of stack
			studentList.getHeadPtr()->setAbsences(studentList.getHeadPtr()->getAbsences() + 1); //update number of absences
			studentList.getHeadPtr()->setAbsentStack(Absence); //set stack to node
		}

		studentList.setHeadPtr(studentList.getHeadPtr()->getNextPtr());
	}

}



void ApplicationMenu::GenerateStudentReport(fstream & filestream, List & studentList)
{
	//report for all students
	while (studentList.getHeadPtr() != nullptr) {
		filestream << studentList.getHeadPtr()->getRecordNumber() << ",";
		filestream << studentList.getHeadPtr()->getIDNumber() << ",";
		filestream << studentList.getHeadPtr()->getName() << ",";
		filestream << studentList.getHeadPtr()->getEmail() << ",";
		filestream << studentList.getHeadPtr()->getUnits() << ",";
		filestream << studentList.getHeadPtr()->getProgram() << ",";
		filestream << studentList.getHeadPtr()->getLevel() << ",";
		filestream << studentList.getHeadPtr()->getAbsences() << ",";
		filestream << studentList.getHeadPtr()->getAbsentStack().peek() << endl; //get most recent absence from top of stack
		studentList.setHeadPtr(studentList.getHeadPtr()->getNextPtr());
	}

}

void ApplicationMenu::GenerateChronicAbsenceReport(fstream & filestream, List & studentList, int & threshold)
{

	//report for chronically absent students

	while (studentList.getHeadPtr() != nullptr) {
		if (studentList.getHeadPtr()->getAbsences() >= threshold) {
			// write data of selected students to outfile
			filestream << studentList.getHeadPtr()->getRecordNumber() << ",";
			filestream << studentList.getHeadPtr()->getIDNumber() << ",";
			filestream << studentList.getHeadPtr()->getName() << ",";
			filestream << studentList.getHeadPtr()->getEmail() << ",";
			filestream << studentList.getHeadPtr()->getUnits() << ",";
			filestream << studentList.getHeadPtr()->getProgram() << ",";
			filestream << studentList.getHeadPtr()->getLevel() << ",";
			filestream << studentList.getHeadPtr()->getAbsentStack().peek() << ","; //get most recent absence from top of stack
			filestream << studentList.getHeadPtr()->getAbsences() << endl;
		}
		studentList.setHeadPtr(studentList.getHeadPtr()->getNextPtr());
	}
}