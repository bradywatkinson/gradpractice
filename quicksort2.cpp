#include <iostream>
#include <array>

using namespace std;

array<int,10> nums = {1,4,3,6,7,2,12,-1,3,8};


int main (void) {

	cout << "begin: ";
	for (auto it=nums.begin(); it!=nums.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	quicksort(0,9);

	cout << "end: ";
	for (auto it=nums.begin(); it!=nums.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}

void quicksort(int lo, int hi) {

	if (lo < hi) {
		int p = partition(lo,hi);
		quicksort(lo,p-1);
		quicksort(p+1,hi);
	}
}

int partition (int lo, int hi) {
	int pivot = nums[hi];
	int i = 0;
	for (int j=0; j<hi; ++j) {
		if (nums[j] <= pivot) {
			swap(i,j);
			i+++;
		}
	}
	swap(i,hi);

}