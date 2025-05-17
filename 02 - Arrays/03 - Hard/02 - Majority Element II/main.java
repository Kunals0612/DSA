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
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;

        // Step 1: Initialize two candidates and their counters
        int first = Integer.MAX_VALUE, second = Integer.MAX_VALUE;
        int count1 = 0, count2 = 0;
        List<Integer> res = new ArrayList<>();

        // Step 2: First pass to find potential candidates
        for (int i = 0; i < n; i++) {
            if (first == nums[i]) {
                // If current number matches first candidate
                count1++;
            } else if (second == nums[i]) {
                // If current number matches second candidate
                count2++;
            } else if (count1 == 0) {
                // Assign new candidate to first if its count is 0
                first = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                // Assign new candidate to second if its count is 0
                second = nums[i];
                count2 = 1;
            } else {
                // If current number matches neither, decrement both counts
                count1--;
                count2--;
            }
        }

        // Step 3: Reset counts for final validation
        count1 = 0;
        count2 = 0;

        // Step 4: Count actual occurrences of the candidates
        for (int i = 0; i < n; i++) {
            if (nums[i] == first) {
                count1++;
            }
            if (nums[i] == second) {
                count2++;
            }
        }

        // Step 5: Check if candidates appear more than n / 3 times
        if (count1 > n / 3) {
            res.add(first);
        }

        // Avoid duplicate entry if first == second
        if (count2 > n / 3 && second != first) {
            res.add(second);
        }

        return res;
    }
}
