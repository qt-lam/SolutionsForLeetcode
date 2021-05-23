#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stack>
#include <stdio.h>
#include <stdarg.h>
#include <set>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

//±©¡¶∑®≥¢ ‘
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> answers;
        if(queries.empty()||nums.empty()){
            return answers;
        }

        sort(nums.begin(),nums.end());
        for(int i=0;i<queries.size();i++){
            int first=queries[i][0];
            int second=queries[i][1];
            int Max=-1;
            int j=0;

            for(;j<nums.size();j++){
                if(nums[j]>second){
                    answers.push_back(Max); 
                    break;
                }
                Max=max(Max,nums[j]^first);
            }
            if(j==nums.size()){
                answers.push_back(Max);
            }
        }

        return answers;
    }
};


//≤‚ ‘
int main()
{
    vector<int> nums{0,1,2,3,4};
    vector<vector<int>>queries{{3,1},{1,3},{5,6}};
    Solution a;
    a.maximizeXor(nums,queries);
    return 0;
}