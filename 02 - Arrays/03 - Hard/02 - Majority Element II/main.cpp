/* Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109 */

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int n = nums.size();
    
            // Initialize two candidate elements with dummy values
            int first = INT_MAX, second = INT_MAX;
    
            // Count for the two potential majority elements
            int count1 = 0, count2 = 0;
    
            // First pass: Find two most frequent candidates
            for(int i = 0; i < n; i++){
                if(first == nums[i]){
                    // If current element is equal to first candidate, increment count1
                    count1++;
                }else if(second == nums[i]){
                    // If current element is equal to second candidate, increment count2
                    count2++;
                }else if(count1 == 0){
                    // If count1 is 0, assign new candidate to first
                    count1++;
                    first = nums[i];
                }else if(count2 == 0){
                    // If count2 is 0, assign new candidate to second
                    count2++;
                    second = nums[i];
                }else{
                    // If current element matches neither candidate, decrease both counts
                    count1--;
                    count2--;
                }
            }
    
            // Reset counts for validation in the second pass
            count1 = 0;
            count2 = 0;
    
            // Second pass: Count actual occurrences of the two candidates
            for(int i = 0; i < n; i++){
                if(nums[i] == first){
                    count1++;
                }
                if(nums[i] == second){
                    count2++;
                }
            }
    
            vector<int> res;
    
            // Check if the candidates appear more than ⌊n/3⌋ times
            if(count1 > n / 3){
                res.push_back(first);
            }
    
            // Avoid pushing the same element twice if both candidates are equal
            if(count2 > n / 3 && second != first){
                res.push_back(second);
            }
    
            return res;
        }
    };
    