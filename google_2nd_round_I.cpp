#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<float> nums = {11, 12, 12.5, 15, 16.55, 16.7, 16.78, 18.1, 19, 21.11111, 24, 25, 28.7};

// find the indecies of the closest value to x
// in a sorted array

int find_x (float x) {
	
	int lo = 0;
	int hi = nums.size();
	int mid;

	while (1) {
		mid = (lo+hi)/2;
		if (hi-lo<2) {
			break;
		} else if (x < nums[mid])  { // lower
			hi = mid;
		} else {
			lo = mid;
		}
	}
	if (fabs(nums[lo]-x) < fabs(nums[hi]-x)) {
		return lo;
	}
	return hi;
}

int main () {

	int r = find_x(16.6);

	cout << nums[r] << endl;

	return 0;
}