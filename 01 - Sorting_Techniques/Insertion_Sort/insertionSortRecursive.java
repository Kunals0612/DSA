import java.util.*;

class Solution {
    public void insertionSort(List<Integer> nums, int n) {
        // Base case: if the array has 1 or no element, it's already sorted
        if (n <= 1) {
            return;
        }

        // Recursively sort first (n-1) elements
        insertionSort(nums, n - 1);

        int key = nums.get(n - 1);
        int j = n - 2;

        // Shift elements to right to insert the key at the correct position
        while (j >= 0 && nums.get(j) > key) {
            nums.set(j + 1, nums.get(j));
            j--;
        }

        // Place the key at the right position
        nums.set(j + 1, key);
    }
}
