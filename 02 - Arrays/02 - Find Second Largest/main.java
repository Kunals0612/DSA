import java.util.*;

class Solution{
    public int findSecondLargest(List<Integer> nums){
        int largest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums.get(i) > largest){
                secondLargest = largest;
                largest = nums.get(i);
            }else if(nums.get(i) > secondLargest && nums.get(i) != largest){
                secondLargest = nums.get(i);
            }
        }

        return secondLargest;
    }
}