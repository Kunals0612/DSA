import java.util.*;

class Solution {
    public List<Integer> findUnion(List<Integer> num1, List<Integer> num2) {
        List<Integer> unionList = new ArrayList<>();
        int n = num1.size();
        int m = num2.size();

        int i = 0, j = 0;

        while (i < n && j < m) {
            int a = num1.get(i);
            int b = num2.get(j);

            if (a < b) {
                if (unionList.isEmpty() || !unionList.get(unionList.size() - 1).equals(a)) {
                    unionList.add(a);
                }
                i++;
            } else if (b < a) {
                if (unionList.isEmpty() || !unionList.get(unionList.size() - 1).equals(b)) {
                    unionList.add(b);
                }
                j++;
            } else {
                if (unionList.isEmpty() || !unionList.get(unionList.size() - 1).equals(a)) {
                    unionList.add(a);
                }
                i++;
                j++;
            }
        }

        while (i < n) {
            int a = num1.get(i);
            if (unionList.isEmpty() || !unionList.get(unionList.size() - 1).equals(a)) {
                unionList.add(a);
            }
            i++;
        }

        while (j < m) {
            int b = num2.get(j);
            if (unionList.isEmpty() || !unionList.get(unionList.size() - 1).equals(b)) {
                unionList.add(b);
            }
            j++;
        }

        return unionList;
    }
}
