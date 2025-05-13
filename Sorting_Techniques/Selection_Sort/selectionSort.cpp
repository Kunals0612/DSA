class Solution {
public:
    vector<int> selectionSort(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            int min_idx = i;
            // Find the index of the minimum element in the unsorted part
            for(int j = i+1; j < n; j++){
                if(nums[j] < nums[min_idx]){
                    min_idx = j;
                }
            }
            // Swap the found minimum element with the first element of the unsorted part
            swap(nums[i], nums[min_idx]);
        }
    }
};


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
