// 34. Find First and Last Position of Element in Sorted Array
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109
// --------------------------------------------------------------------------------------------------------------------------------------------

Think of this test case
// [0,2,2,2,2,2]  target=2


class Solution {
public:

    int leftmost(vector<int>&nums,int target,int n){
        int left=-1;
        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){   // Dont stop the search store the potential answer and search for leftmost if present  
                left=mid;
                r=mid-1;
            }
            else if(nums[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return left;
    }
     int rightmost(vector<int>&nums,int target,int n){
        int right=-1;
        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){  // similarly for right most
                right=mid;
                l=mid+1;
            }
            else if(nums[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        return {leftmost(nums,target,n),rightmost(nums,target,n)};
    }
};