/* A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1] 
*/

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int index = -1;  // Step 1: Initialize index to track where the first decreasing pair is found
            int n = nums.size();
    
            // Step 2: Find the first index from the end such that nums[i] < nums[i+1]
            // This identifies the pivot point where the permutation needs to change
            for(int i = n - 2; i >= 0; i--) {
                if(nums[i] < nums[i + 1]) {
                    index = i; // Found the pivot
                    break;
                }
            }
    
            // Step 3: If no such index is found, the array is in descending order
            // Hence, reverse the entire array to get the lowest permutation
            if(index == -1) {
                reverse(nums.begin(), nums.end());
                return;
            }
    
            // Step 4: Find the smallest element greater than nums[index] from the end
            // This ensures the next permutation is just slightly larger
            for(int i = n - 1; i > index; i--) {
                if(nums[i] > nums[index]) {
                    swap(nums[i], nums[index]); // Step 5: Swap the pivot with the found element
                    break;
                }
            }
    
            // Step 6: Reverse the suffix starting from index + 1 to end to get the next smallest lexicographical sequence
            reverse(nums.begin() + index + 1, nums.end());
        }
    };
    