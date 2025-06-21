import java.util.*;
class GfG {
    int maxLen(int arr[], int n) {
        // Your code here
        int maxLength = 0;
        int sum = 0;
        HashMap<Integer, Integer> sumIndexMap = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];

            if (sum == 0) {
                maxLength = i + 1;
            }

            if (sumIndexMap.containsKey(sum)) {
                maxLength = Math.max(maxLength, i - sumIndexMap.get(sum));
            } else {
                sumIndexMap.put(sum, i);
            }
        }
        return maxLength;
    }
}

public class largestSubarray {
    public static void main(String[] args) {
        GfG g = new GfG();
        int arr[] = { 1, 0 };
        int n = arr.length;
        System.out.println("Length of the longest subarray with 0 sum is " + g.maxLen(arr, n));
    }
}
