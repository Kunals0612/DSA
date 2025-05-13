class Solution{
    public:
        vector<int> bubbleSort(vector<int>& nums){
            int n = nums.size();
            bool swapped;

            for(int i = 0; i < n-1; i++){
                swapped = false;
                for(int j = 0; j < n - i - 1; j++){
                    if(nums[j] > nums[j+1]){
                        swap(nums[j],nums[j+1]);
                        swapped = true;
                    }
                }
                if(!swapped){
                    break;
                }
            }

            return nums;

        }

};

/*
Bubble Sort Algorithm:
----------------------
1. Bubble Sort is a simple sorting algorithm that repeatedly steps through the list,
   compares adjacent elements, and swaps them if they are in the wrong order.

2. Each iteration "bubbles up" the largest unsorted element to its correct position
   at the end of the list.

3. The process is repeated for all elements until no swaps are needed,
   indicating the list is sorted.

Optimization:
-------------
- A boolean flag `swapped` is used to stop the algorithm early if the list is already sorted.

Time Complexity:
----------------
- Best Case: O(n)         → When the list is already sorted (due to `swapped` optimization)
- Average Case: O(n^2)
- Worst Case: O(n^2)

Space Complexity:
-----------------
- O(1) → In-place sorting, no extra space needed

Stable: ✅ (Yes — preserves relative order of equal elements)
In-place: ✅ (Yes)

Example:
--------
Input:  [5, 3, 8, 4, 2]
Pass 1: [3, 5, 4, 2, 8]
Pass 2: [3, 4, 2, 5, 8]
Pass 3: [3, 2, 4, 5, 8]
Pass 4: [2, 3, 4, 5, 8]
Output: [2, 3, 4, 5, 8]
*/