#include <bits/stdc++.h>
using namespace std;
#define N 1e9

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);
};

vector<int> Solution::twoSum(vector<int>& nums, int target){
    
    long int H[2*N+1] = {0};
    vector<int> ans(2, 0);

    for(int i=0; i<nums.length; i++){
        
        if(nums[i] < 0){
            H[0-nums[i]] = abs(nums[i])+i;

            if(H[target - nums[i]] > 0){
                ans[0] = i;
                ans[1] = H[target - nums[i]]-abs(nums[i]);

                return ans;
            }
        }
        else{
            H[0-nums[i]] = abs(nums[i])+i;

            if(H[target - nums[i]] > 0){
                ans[0] = i;
                ans[1] = H[target - nums[i]]-abs(nums[i]);

                return ans;
            }
        }
    }

}

int main(){

}