class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row*col; 

        int s = 0;
        int e = n-1;
        
        while(s <= e) {
            int mid = s + (e-s)/2;

            // find row index and col index
            int rowIndex = mid/col;
            int colIndex = mid%col;
            // find current number by rowIndex and colIndex
            int currNumber = matrix[rowIndex][colIndex];

            if(currNumber == target) {
                return true;
            }
            else if(currNumber > target) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return false;
    }
};
