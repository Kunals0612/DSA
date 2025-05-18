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
    
    public int reversePairs(int[] nums) {
        int count = 0;
        count = mergeSort(nums, 0, nums.length - 1);
        return count;
    }

    private int mergeSort(int[] nums, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);
        count += merge(nums, left, mid, right);
        return count;
    }

    private int merge(int[] nums, int left, int mid, int right) {
        int count = 0;

        int[] leftArr = Arrays.copyOfRange(nums, left, mid + 1);
        int[] rightArr = Arrays.copyOfRange(nums, mid + 1, right + 1);

        // Count reverse pairs
        int i = 0, j = 0;
        while (i < leftArr.length) {
            while (j < rightArr.length && (long) leftArr[i] > 2L * rightArr[j]) {
                j++;
            }
            count += j;
            i++;
        }

        // Merge sorted halves
        i = 0; 
        j = 0;
        int k = left;

        while (i < leftArr.length && j < rightArr.length) {
            if (leftArr[i] <= rightArr[j]) {
                nums[k++] = leftArr[i++];
            } else {
                nums[k++] = rightArr[j++];
            }
        }

        while (i < leftArr.length) {
            nums[k++] = leftArr[i++];
        }

        while (j < rightArr.length) {
            nums[k++] = rightArr[j++];
        }

        return count;
    }
}
