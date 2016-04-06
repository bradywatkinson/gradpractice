// ACM style code contest solution c

// given a set of stick lengths, find how many combinations 
// cannot make a triangle
// n < 2000

// solution is lon(n)n^2 but is fine in the space of n < 2000


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> sticks;


// finds first point distinctly greater
int find_x (float x) {
	
	int lo = 0;
	int hi = sticks.size();
	int mid;

	while (1) {
		mid = (lo+hi)/2;
		if (hi-lo<2) {
			break;
		} else if (x < sticks[mid])  { // lower
			hi = mid;
		} else {
			lo = mid;
		}
	}

	return sticks.size() - hi;
}

int main () {

	int n,l,count;
	while (1) {
		cin >> n;
		if (n==0) break;
		for (int i=0;i<n;++i) {
			cin >> l;
			sticks.push_back(l);
		}
		sort(sticks.begin(), sticks.end());
		count = 0;
		for (int i=0;i<n;++i) {
			for (int j=i+1;j<n;++j) {
				count += find_x (sticks[i]+sticks[j]);
			}
		}
		sticks.clear();
		cout << count << endl;
	}

	return 0;
}