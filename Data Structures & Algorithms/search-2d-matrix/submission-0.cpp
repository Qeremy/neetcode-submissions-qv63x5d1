class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l1 = 0, r1 = matrix.size() - 1, l2 = 0, r2 = matrix[0].size() - 1;
        while(l1 <= r1){
            int mid = l1 + (r1 - l1)/2;
            if(matrix[mid][0] == target){
                return true;
            }

            if(matrix[mid][0] < target){
                //check if target is in current line
                if((mid + 1 < matrix.size() && target < matrix[mid+1][0]) || mid == matrix.size() - 1){
                    while(l2 <= r2){
                        int mid2 = l2 + (r2 - l2)/2;
                        if(matrix[mid][mid2] == target){
                            return true;
                        }
                        if(matrix[mid][mid2] < target){
                            r2 = mid2 - 1;
                        }
                        else{
                            l2 = mid2 + 1;
                        }
                    }
                    return false;
                }
                l1 = mid + 1;
                
            }
            else{
                r1 = mid - 1;
                
            }
        }

        return false;
    }
};
