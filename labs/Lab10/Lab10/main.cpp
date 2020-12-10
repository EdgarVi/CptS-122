
#include <iostream>
#include <vector>

#define EXIT 9

using namespace std;
int main(void) {
	


	// vector demo
	vector<int> v;
	int choice = 0;
	
	while(choice != EXIT){
		cout << "1. Insert to vector\n2. print vector\n";
		cout << "3. pop_back()\n4. size()\n9. exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Integer to insert: ";
			int number;
			cin >> number;
			v.push_back(number);
			break;
		case 2:
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << endl;
			}
			break;
		case 3:
			v.pop_back(); // delete last element in the vector
			break;
		case 4:
			cout << "vector has " << v.size() << " elements\n";
			break;
		}
	}

	return 0;
}