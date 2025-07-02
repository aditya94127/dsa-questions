class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
          int l=0,r=n*m-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(matrix[mid/m][mid%m]==target){  // conversion of index of 1-D array into 2-D array
                                              // 1-D indx
                                                //2-D [idx/number of column][indx % number of column]
               return true;
            }
            else if(matrix[mid/m][mid%m]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return 0;
    }
};