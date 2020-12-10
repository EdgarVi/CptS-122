#include "Person.h"

class Student : public Person {

public:
	Student();
	~Student();



private:
	struct Course {
		string mCourseName;
		int mCredits;
		char mCurrentGrade;
	};

	Course mCourseArray[];
	int mNumCoursesTaken;
	int mTotalCredits;
};