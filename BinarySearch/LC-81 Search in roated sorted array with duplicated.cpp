

class Solution {
public:


//find the pivot using index of minimum number in the array
    int pivot(vector<int>& nums){
        int n=nums.size();
        int l=0,r=nums.size()-1;
        while(l<r){
            while(l<r && nums[l]==nums[l+1])    // remove the duplicate numbers
                l++;
            while(l<r && nums[r]==nums[r-1])    // remove the duplicate numbers
                r--;
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
                return 1;
            else if(arr[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return 0;
    }


    bool search(vector<int>& nums, int target) {
        int pivot_indx=pivot(nums);
        int n=nums.size();
        if(bs(0,pivot_indx-1,nums,target) || bs(pivot_indx,n-1,nums,target))
            return true;
      
        return false;
    }
};

// WORST CASE TIME COMPLEXITY IS O(n) because of duplicated ex: [2,2,2,2,2,2,2] 