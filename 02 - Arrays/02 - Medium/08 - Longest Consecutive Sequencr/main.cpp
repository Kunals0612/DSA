/* Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109 */

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            int n = nums.size();
            sort(nums.begin(),nums.end());
            int count = 0, maxCount = 0;
            set<int> st;
    
            if(nums.empty()){
                return 0;
            }
            
            for(int i = 0; i < n; i++){
                st.insert(nums[i]);
            }
    
            for(auto& it : st){
                if(st.find(it+1) != st.end()){
                    count++;
                }else{
                    maxCount = max(maxCount,count);
                    count = 0;
                }
            }
            maxCount = max(maxCount,count);
    
            return maxCount + 1;
            
        }
    };