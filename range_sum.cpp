class NumArray {
public:
    int N;
    vector<int> M;
    vector<int> A;

    int query(int node, int b, int e, int i, int j)
    {
    	int p1, p2;
     
    //if the current interval doesn't intersect 
    //the query interval return -1
    	if (i > e || j < b)
    		return 0;
     
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
    	//if (p1 == -1)
    	//	return M[node] = p2;
    	//if (p2 == -1)
    	//	return M[node] = p1;
    	return p1 + p2;
    }

    void initialize(int node, int b, int e)
    {
        if (b == e) {
            M[node] = A[b];
        } else {
            // initialise the sub parts
            initialize(2 * node, b, (b + e) / 2);
            initialize(2 * node + 1, (b + e) / 2 + 1, e);

            // initialise the current node to be the sum of the sub parts            
            M[node] = M[2*node] + M[2*node+1];
        }
    }

    NumArray(vector<int> &nums) {
        if (!nums.empty()) {
            A = nums;
            N = nums.size();
            M.resize(2*pow(2,(int)log2(N)+1));
            initialize(1,0,N-1);
        }
    }

    int sumRange(int i, int j) {
        if (!M.empty()) {
            return query(1, 0, N-1, i, j);
        }
        return 0;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);