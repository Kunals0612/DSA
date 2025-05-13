import java.util.*;

class Solution {
    public void merge(List<Integer> nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        List<Integer> leftPart = new ArrayList<>();
        List<Integer> rightPart = new ArrayList<>();

        // Copy data to temporary lists
        for (int i = 0; i < n1; i++) {
            leftPart.add(nums.get(left + i));
        }

        for (int j = 0; j < n2; j++) {
            rightPart.add(nums.get(mid + 1 + j));
        }

        int i = 0, j = 0;
        int k = left;

        // Merge the temporary lists back into nums
        while (i < n1 && j < n2) {
            if (leftPart.get(i) <= rightPart.get(j)) {
                nums.set(k, leftPart.get(i));
                i++;
            } else {
                nums.set(k, rightPart.get(j));
                j++;
            }
            k++;
        }

        // Copy remaining elements of leftPart
        while (i < n1) {
            nums.set(k, leftPart.get(i));
            i++;
            k++;
        }

        // Copy remaining elements of rightPart
        while (j < n2) {
            nums.set(k, rightPart.get(j));
            j++;
            k++;
        }
    }

    public void mergeSort(List<Integer> nums, int left, int right) {
        // Base case: if only one element, return
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;

        // Recursively sort left and right halves
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        // Merge the sorted halves
        merge(nums, left, mid, right);
    }
}

/*
Merge Sort Algorithm:
---------------------
1. Merge Sort is a Divide and Conquer algorithm.
2. It divides the array into two halves, recursively sorts them, and then merges the sorted halves.
3. This process continues until the base case of one-element subarrays is reached.

Working:
--------
- Divide the array into two halves.
- Recursively sort the left and right halves.
- Merge the two sorted halves into a single sorted array.

Time Complexity:
----------------
- Best Case:     O(n log n)
- Average Case:  O(n log n)
- Worst Case:    O(n log n)

Space Complexity:
-----------------
- O(n) → Requires temporary arrays/lists for merging.

Stable: ✅ (Yes) — maintains the relative order of equal elements.  
In-place: ❌ (No) — requires extra space for merging.

Example:
--------
Input:  [5, 2, 4, 6, 1, 3]
Step 1: Divide into [5, 2, 4] and [6, 1, 3]
Step 2: Divide [5, 2, 4] → [5] [2, 4], then [2, 4] → [2] [4]
Step 3: Merge [2, 4] → [2, 4], then [5] and [2, 4] → [2, 4, 5]
Step 4: Similarly merge [6, 1, 3] → [1, 3, 6]
Step 5: Merge [2, 4, 5] and [1, 3, 6] → [1, 2, 3, 4, 5, 6]

Output: [1, 2, 3, 4, 5, 6]
*/
