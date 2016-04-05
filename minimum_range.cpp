#include <iostream>
#include <vector>
#include <math.h> 

using namespace std;

int A[10] = {11,7,45,17,20,34,10,34,6,9};
int N = 10;
vector<int> M;

int query(int node, int b, int e, int i, int j)
{
	int p1, p2;
 
//if the current interval doesn't intersect 
//the query interval return -1
	if (i > e || j < b)
		return -1;
 
//if the current interval is included in 
//the query interval return M[node]
	if (b >= i && e <= j)
		return M[node];
 
//compute the minimum position in the 
//left and right part of the interval
	p1 = query(2 * node, b, (b + e) / 2, i, j);
	p2 = query(2 * node + 1, (b + e) / 2 + 1, e, i, j);
 
//return the position where the overall 
//minimum is
	if (p1 == -1)
		return M[node] = p2;
	if (p2 == -1)
		return M[node] = p1;
	if (A[p1] <= A[p2])
		return M[node] = p1;
	return M[node] = p2;
}

void initialize(int node, int b, int e)
{
	// the 
	if (b == e) {
		M[node] = b;
	} else {
		//compute the values in the left and right subtrees
		initialize(2 * node, b, (b + e) / 2);
		initialize(2 * node + 1, (b + e) / 2 + 1, e);
		//search for the minimum value in the first and 
		//second half of the interval
		if (A[M[2 * node]] <= A[M[2 * node + 1]]) {
			M[node] = M[2 * node];
		} else {
			M[node] = M[2 * node + 1]; 
		}
	}
}

int main (void) {

	M.resize(2 * pow(2,(int)log2(N)+1));

	initialize(1,0,N-1);

	cout << A[query(1,0,N-1,0,5)] << endl;

	return 0;
}