class Solution{
    public:
        vector<int> insertionSort(vector<int>& nums){
            int n = nums.size();

            for(int i = 1; i < n; i++){
                int key = nums[i];
                int j = i - 1;
                
                while(j >= 0 && nums[j] > key){
                    nums[j+1] = nums[j];
                    j--;
                }

                nums[j+1] = key;
            }
            return nums;
        }
};

/*
Insertion Sort Algorithm:
-------------------------
1. Insertion Sort builds the final sorted array one item at a time.
2. It takes each element and places it in its correct position within the already sorted part of the array.
3. It is similar to sorting playing cards in your hand.

Working:
--------
- Start from index 1 (as index 0 is already sorted).
- Take the current element (key) and compare it with elements to its left.
- Shift all larger elements to the right.
- Insert the key into its correct position.

Time Complexity:
----------------
- Best Case (already sorted):     O(n)
- Average Case:                   O(n²)
- Worst Case (reverse sorted):    O(n²)

Space Complexity:
-----------------
- O(1) → In-place sorting, no extra memory used.

Stable: ✅ (Yes)
In-place: ✅ (Yes)

Example:
--------
Input:  [5, 2, 4, 6, 1, 3]
Step 1: [2, 5, 4, 6, 1, 3]
Step 2: [2, 4, 5, 6, 1, 3]
Step 3: [2, 4, 5, 6, 1, 3]
Step 4: [1, 2, 4, 5, 6, 3]
Step 5: [1, 2, 3, 4, 5, 6]
Output: [1, 2, 3, 4, 5, 6]
*/