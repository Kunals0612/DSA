import java.util.*;

class Solution {
    public void bubbleSort(List<Integer> nums, int n) {
        // Base case: if size is 1, array is sorted
        if (n == 1) {
            return;
        }

        int count = 0;

        // Perform one pass of bubble sort
        for (int i = 0; i < n - 1; i++) {
            if (nums.get(i) > nums.get(i + 1)) {
                // Swap nums[i] and nums[i + 1]
                int temp = nums.get(i);
                nums.set(i, nums.get(i + 1));
                nums.set(i + 1, temp);
                count++;
            }
        }

        // If no swaps were done in this pass, array is already sorted
        if (count == 0) {
            return;
        }

        // Recursive call for the remaining array
        bubbleSort(nums, n - 1);
    }
}
