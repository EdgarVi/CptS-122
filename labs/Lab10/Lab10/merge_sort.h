#pragma once
#include <iostream>
#include <vector>

using namespace std;


// make two partions of the array and call merge_step
vector<int> &merge_sort(vector<int> &arr);

//combine the two subarrays into one sorted array
void merge_step(vector<int> &arr, int a1_start, int a1_end, int a2_start, int a2_end);