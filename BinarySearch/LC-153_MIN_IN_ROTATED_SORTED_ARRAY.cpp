
// 153. Find Minimum in Rotated Sorted Array
// Hint
// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// You must write an algorithm that runs in O(log n) time.

 

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.
// Example 2:

// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
// Example 3:

// Input: nums = [11,13,15,17]
// Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 






class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){    // l<=r as this condition will not break so we have used l<r
            int mid=(l+r)/2;
            if(nums[mid]>nums[r])  // in this case answer cannot be in left side
                l=mid+1;
            else
                r=mid;       // mid can be our answer ,so we have not done mid-1
        }
        return nums[l];
    }
};

-------------------------------------------------------------------------------------------------------

FOR MAXIMUM ELEMENT
 while (lo < hi)
    {
        // If the current subarray is already sorted,
        // the maximum is at the hi index
        if (arr[lo] <= arr[hi])
            return arr[hi];
        
        int mid = (lo + hi) / 2;

        // The left half is sorted, the maximum must 
        // be either arr[mid] or in the right half.
        if (arr[mid] > arr[lo])
            lo = mid;
        else
            hi = mid - 1;
    }

    return arr[lo]; 
}