// You are given a 0-indexed array nums consisting of positive integers.

// A partition of an array into one or more contiguous subarrays is called good if no two subarrays contain the same number.

// Return the total number of good partitions of nums.

// Since the answer may be large, return it modulo 109 + 7.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: 8
// Explanation: The 8 possible good partitions are: ([1], [2], [3], [4]), ([1], [2], [3,4]), ([1], [2,3], [4]), ([1], [2,3,4]), ([1,2], [3], [4]), ([1,2], [3,4]), ([1,2,3], [4]), and ([1,2,3,4]).
// Example 2:

// Input: nums = [1,1,1,1]
// Output: 1
// Explanation: The only possible good partition is: ([1,1,1,1]).
// Example 3:

// Input: nums = [1,2,1,3]
// Output: 2
// Explanation: The 2 possible good partitions are: ([1,2,1], [3]) and ([1,2,1,3]).
 

class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int indx=0;indx<nums.size();indx++)
            mp[nums[indx]]=indx;
        int i=0,j=0,ans=1,mod=1e9+7;
        while(i<nums.size()){
            // every partition has 2 choices
            if(i>j){
                ans=(ans*2)%mod;
            }
            if(j<mp[nums[i]]){
                j=mp[nums[i]];
            }
            i++;
        }
        return (ans)%mod;
    }
};