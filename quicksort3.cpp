#include <iostream>
#include <array>

using namespace std;

array<int,9> nums = {4,2,6,1,9,20,15,-4,8};

void swap (int a, int b) {
	int tmp = nums[a];
	nums[a] = nums[b];
	nums[b] = tmp;
}

int partition(int lo, int hi) {
	int i=lo;
	int p = nums[hi];
	for (int j=lo; j<hi; ++j) {
		if (nums[j]<=p) {
			swap(i,j);
			++i;
		}
	}
	swap(i,hi);
	return i;
}

void quicksort (int lo, int hi) {
	if (lo < hi) {
		int p = partition(lo, hi);
		quicksort(lo, p-1);
		quicksort(p+1, hi);
	}
}

int main () {

	for (int i = 0; i<nums.size(); ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;

	quicksort(0,nums.size()-1);

	for (int i = 0; i<nums.size(); ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;

	return 0;
}