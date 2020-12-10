#include "merge_sort.h"

vector<int>& merge_sort(vector<int>& arr)
{
	
}

void merge_step(vector<int>& arr, int a1_start, int a1_end, int a2_start, int a2_end)
{
	vector<int> result;
	int a = a1_start, b = a2_start;
	
	for (int i = a1_start; i <= a2_end; i++) {
		if (a > a1_end) {
			result.push_back(arr[b++]);
		}
		else if (b> a2_end) {
			result.push_back(arr[a++]);
		}
		else if (arr[a] < arr[b]) {
			result.push_back(arr[a++]);
		} else {
			result.push_back(arr[b]++);
		}
	}

	for (int i = a2_end; i >= a1_start; i--) {
		arr[i] = result.back();
		result.pop_back();
	}

}
