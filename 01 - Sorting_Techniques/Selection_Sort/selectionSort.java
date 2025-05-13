import java.util.*;

class Solution {
    public List<Integer> selectionSort(List<Integer> nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (nums.get(j) < nums.get(minIdx)) {
                    minIdx = j;
                }
            }
            // Swap elements at index i and minIdx
            int temp = nums.get(i);
            nums.set(i, nums.get(minIdx));
            nums.set(minIdx, temp);
        }
        return nums;
    }
}

/*
Selection Sort Algorithm:
-------------------------
1. Selection sort divides the array into two parts:
   - Sorted part (initially empty)
   - Unsorted part (initially the whole array)

2. It repeatedly selects the minimum element from the unsorted part 
   and swaps it with the first unsorted element.

3. This process is done in-place and requires no extra space.

Time Complexity:
----------------
- Best Case: O(n^2)
- Average Case: O(n^2)
- Worst Case: O(n^2)

Space Complexity:
-----------------
- O(1) -> No extra space used

Stable: ❌ (Not stable by default)
In-place: ✅ (Yes)

Example:
Input:  [64, 25, 12, 22, 11]
Output: [11, 12, 22, 25, 64]
*/
