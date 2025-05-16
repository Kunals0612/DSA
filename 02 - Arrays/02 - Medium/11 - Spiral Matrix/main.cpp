/* Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100 */

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
            int left = 0, right = m-1, top = 0, bottom = n-1;
            vector<int> res;
    
            while(left <= right && top <= bottom){
                for(int i = left; i <= right; i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
    
                for(int j = top; j <= bottom; j++){
                    res.push_back(matrix[j][right]);
                }
                right--;
    
                if(top <= bottom){
                    for(int i = right; i >= left; i--){
                        res.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                }
    
                if(left <= right){
                    for(int j = bottom; j >= top; j--){
                        res.push_back(matrix[j][left]);
                    }
                    left++;
                }
            }
    
            return res;
    
        }
    };
