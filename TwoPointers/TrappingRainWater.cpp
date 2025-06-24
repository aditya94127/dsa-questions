// THink of [3,0,6]  and [3,1,6]
// for a particular index ans is min of(left most height and right most)- nums[i]


// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

// Example 1:


// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9
 

// Constraints:

// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105

class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();vector<int>left(n,0),right(n,0);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++) left[i]=max(left[i-1],nums[i]);
        for(int i=n-2;i>=0;i--) right[i]=max(right[i+1],nums[i]);
        int ans=0;
        for(int i=1;i<nums.size()-1;i++){
            ans=ans+min(left[i],right[i])-nums[i];
        }
        return ans;
    }
};