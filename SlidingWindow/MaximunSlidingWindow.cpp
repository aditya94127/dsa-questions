// 239. Sliding Window Maximum    
//  link-https://leetcode.com/problems/sliding-window-maximum/description/
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.
 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length






class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            // step -1 make space for new element 
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            // step-2 remove smaller element from back
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            //step -3
            dq.push_back(i);
            // step-4 we start getting answer when i>=k-1
            if(i>= k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};