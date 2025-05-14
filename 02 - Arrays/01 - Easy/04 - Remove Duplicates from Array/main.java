class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;

        int uniqueIndex = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1]){
                nums[uniqueIndex] = nums[i];
                uniqueIndex++;
            }
        }

        return uniqueIndex;
    }
}