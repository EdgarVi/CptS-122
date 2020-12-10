// This example studies sequential/linear search, binary search,
// selection sort, and bubble sort to explore Big-O analysis

#include "BigO.h"

int main(void)
{
	BigO::SortsAndSearches<int> myObj;
	bool found = false;
	
	int list[5] = { 5, 3, 0, -1, 8 }, pos = 0;

	// worst case scenario - Big-O(n)
	found = myObj.sequential_search(list, 5, 8, &pos);
	cout << "found target " << found << " at position: " << pos << endl;

	// best case scenario - Big-O(1)
	found = myObj.sequential_search(list, 5, 5, &pos);
	cout << "found target " << found << " at position: " << pos << endl;


	return 0;
}