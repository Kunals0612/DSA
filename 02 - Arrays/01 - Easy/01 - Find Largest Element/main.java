import java.util.*;

class Solution {
    public int findLargest(List<Integer> nums) {
        int largest = Integer.MIN_VALUE;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums.get(i) > largest) {
                largest = nums.get(i);
            }
        }

        return largest;
    }
}
