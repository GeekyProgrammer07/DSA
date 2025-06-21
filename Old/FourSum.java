import java.util.*;

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        
        for (int i = 0; i < nums.length - 3; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < nums.length - 2; j++) {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int left = j + 1;
                int right = nums.length - 1;
                
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        result.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
                        
                        // Skip duplicates for the third and fourth elements
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
}

public class FourSum {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {1000000000,1000000000,1000000000,1000000000};
        long start = System.currentTimeMillis();
        List<List<Integer>> result = solution.fourSum(nums,-294967296);
        long end = System.currentTimeMillis();
        
        System.out.println("Quadruplets that sum to zero: " + result);
        System.out.println("Done in " + (end - start) + " ms");
    }
}
