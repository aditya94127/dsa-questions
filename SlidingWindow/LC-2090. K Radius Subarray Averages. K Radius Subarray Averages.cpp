class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n,-1);
        long sum=0,window=2*k+1;
        if (n < window) return ans;
        for(int i=0;i<window;i++){
            sum+=nums[i];
        }
        
        ans[k++]=sum/window;


        int j=window,start=0;
        while(j<n){
            sum+=nums[j++];
            sum-=nums[start++];
            ans[k++]=sum/window;
        }
        return ans;
    }
};