// 3265. Count Almost Equal Pairs I

// You are given an array nums consisting of positive integers.

// We call two integers x and y in this problem almost equal if both integers can become equal after performing the following operation at most once:

// Choose either x or y and swap any two digits within the chosen number.
// Return the number of indices i and j in nums where i < j such that nums[i] and nums[j] are almost equal.

// Note that it is allowed for an integer to have leading zeros after performing an operation.

 

// Example 1:

// Input: nums = [3,12,30,17,21]

// Output: 2

// Explanation:

// The almost equal pairs of elements are:

// 3 and 30. By swapping 3 and 0 in 30, you get 3.
// 12 and 21. By swapping 1 and 2 in 12, you get 21.
// Example 2:

// Input: nums = [1,1,1,1,1]

// Output: 10

// Explanation:

// Every two elements in the array are almost equal.

// Example 3:

// Input: nums = [123,231]

// Output: 0

// Explanation:

// We cannot swap any two digits of 123 or 231 to reach the other.

 

// Constraints:

// 2 <= nums.length <= 100
// 1 <= nums[i] <= 106


// ___________________________________________________________________________________________________________________________________________________________________________


class Solution {
public:
    int fun(string s1,string s2){
        int mx=max(s1.length(),s2.length());

        // case : when s1 =3 and s2=300 (they are almost equal as s1 can me converted to 003)
        while(s1.length()<mx) s1="0"+s1;
        while(s2.length()<mx) s2="0"+s2;




        int diff=0;unordered_map<char,int>freq1,freq2;
        for(int i=0;i<mx;i++){
            if(s1[i]!=s2[i]) diff++;
                freq1[s1[i]]++;
                freq2[s2[i]]++;

        }
        return diff<=2 && freq1==freq2;
    }


    int countPairs(vector<int>& nums) {
        int count=0,n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                count+=fun(to_string(nums[i]),to_string(nums[j]));
            }
        }
        return count;
    }
};

// 1 1 1 2
// 1 2 1 2 {in this case we can not use set as this will give W/A, 
// we want frequency should also be same so we use hashmap}