// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution.

#include <iostream>
#include <vector>

using namespace std;

struct tile {
    tile (int a, int b) : val{a}, pos{b} {};
    int val;
    int pos;
};

bool comp (tile a, tile b) {
    return a.val < b.val;
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int size = nums.size();
        vector<tile> vec;
        for (int x=0;x<size;++x) {
            tile tmp{nums[x],x};
            vec.push_back(tmp);
        }
        sort(vec.begin(), vec.end(), comp);
        
        vector<int> returnVals;
        int tmp, i=0, j=size-1;
        
        // sliding door
        while (1) {            
            tmp = vec[i].val + vec[j].val;
            if (tmp == target) {
                returnVals.push_back(vec[i].pos);
                returnVals.push_back(vec[j].pos);
                break;
            } else if (tmp < target) {
                ++i;
            } else {
                --j;
            }
        }
        return returnVals;
    }
};

int main () {

    vector<int> v = {5,-7,34,2,3,4,8,45,-5,-23};
    int target = 42;
    Solution s;
    vector<int> r = s.twoSum(v,target);

    cout << r[0] << " " << r[1] << endl;

    return 0;
}

