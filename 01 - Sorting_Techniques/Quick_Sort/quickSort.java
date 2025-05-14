import java.util.*;

class Solution {

    // Function to perform partitioning
    public int partition(List<Integer> nums, int low, int high) {
        int pivot = nums.get(high);
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (nums.get(j) < pivot) {
                i++;
                // Swapping elements smaller than pivot to the left side
                int temp = nums.get(i);
                nums.set(i, nums.get(j));
                nums.set(j, temp);
            }
        }

        // Place pivot at the correct position
        int temp = nums.get(i + 1);
        nums.set(i + 1, nums.get(high));
        nums.set(high, temp);

        return i + 1;
    }

    // QuickSort function
    public void quickSort(List<Integer> nums, int low, int high) {
        if (low < high) {
            int pi = partition(nums, low, high);
            quickSort(nums, low, pi - 1);    // Sort left part
            quickSort(nums, pi + 1, high);   // Sort right part
        }
    }

    /*
    Quick Sort Algorithm:
    ---------------------
    1. Quick Sort is a Divide and Conquer algorithm.
    2. It picks an element as a pivot and partitions the array around the pivot.
    3. Elements smaller than pivot go to the left; greater go to the right.

    Working:
    --------
    - Choose a pivot (commonly the last element).
    - Partition the array so all elements < pivot come before, and > pivot come after.
    - Recursively apply QuickSort on the left and right subarrays.

    Time Complexity:
    ----------------
    - Best Case (balanced partition):     O(n log n)
    - Average Case:                       O(n log n)
    - Worst Case (already sorted array):  O(n²)

    Space Complexity:
    -----------------
    - O(log n) → Due to recursive stack space.

    Stable: ❌ (No) — equal elements may change order.
    In-place: ✅ (Yes) — uses constant extra space.

    Example:
    --------
    Input:  [5, 2, 9, 1, 5, 6]
    Step 1: Choose pivot = 6 → partition around it.
    Step 2: Recursively apply quickSort to left [5, 2, 1, 5] and right [9]
    Output: [1, 2, 5, 5, 6, 9]
    */
}
