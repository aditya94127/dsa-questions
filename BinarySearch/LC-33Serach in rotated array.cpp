// 33. Search in Rotated Sorted Array

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104



-----------------------------------------------------------------------------------------------------------------------------------------------------------
USE THE CONCEPT OF FINDING THE INDEX  MINIMUM NUMBER AND APPLY BINARY SEARCH TO ITSLEFT && TO ITS RIGHT.

class Solution {
public:


//find the pivot using index of minimum number in the array
    int pivot(vector<int>& nums){
        int n=nums.size();
        int l=0,r=nums.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[r])
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }

    int bs(int l,int r,vector<int>&arr, int target){

        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]==target)
                return mid;
            else if(arr[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }


    int search(vector<int>& nums, int target) {
        int pivot_indx=pivot(nums);
        int n=nums.size();
        int indx=bs(0,pivot_indx-1,nums,target);
        if(indx!=-1) return indx;
        indx=bs(pivot_indx,n-1,nums,target);
        return indx;
    }
};