class Solution{
    public:
        int partition(vector<int>& nums, int low, int high){
            int pivot = nums[high];

            int i = low - 1;

            for(int j = low; j <= high-1; j++){
                if(nums[j] < pivot){
                    i++;
                    swap(nums[i],nums[j]);
                }
            }

            swap(nums[i+1],nums[high]);
            return i+1;
        }

        void quickSort(vector<int>& nums, int low, int high){
            int pi = partition(nums,low,high);

            quickSort(nums,low,pi-1);
            quickSort(nums,pi+1,high);
        }

};

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