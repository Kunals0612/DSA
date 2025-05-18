/* Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1 */

class Solution {
    public:
    
        void merge(vector<int>& nums, int left, int mid, int right, int& count){
            int n1 = mid - left + 1;
            int n2 = right - mid;
    
            vector<int> l(n1), r(n2);
    
            for(int i = 0; i < n1; i++){
                l[i] = nums[left+i];
            }
    
            for(int j = 0; j < n2; j++){
                r[j] = nums[mid+1+j];
            }
    
            int i = 0, j = 0;
            int k = left;
    
            while(i < n1 && j < n2){
                if(l[i] <= r[j]){
                    nums[k] = l[i];
                    i++;
                }else{
                    nums[k] = r[j];
                    j++;
                }
                k++;
            }
    
            while(i < n1){
                nums[k] = l[i];
                i++;
                k++;
            }
            
            while(j < n2){
                nums[k] = r[j];
                j++;
                k++;
            }
    
            i = 0, j = 0;
            while(i < n1){
                while(j < n2 && l[i] > 2 * (long long)r[j]){
                    j++;
                }
                count += j;
                i++;
            }
        }
    
        void mergeSort(vector<int>& nums, int left, int right, int& count){
            if(left >= right){
                return;
            }
    
            int mid = left + (right - left) / 2;
            mergeSort(nums,left,mid,count);
            mergeSort(nums,mid+1,right,count);
            merge(nums,left,mid,right,count);
        }
    
        int reversePairs(vector<int>& nums) {
            int count = 0;
            mergeSort(nums,0,nums.size()-1,count);
            return count;
        }
    };
