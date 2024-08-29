import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> threeSums(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.length - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right++;
                    left++;
                    right--;
                } else if (sum < 0)
                {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
}

public class threeSum {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {-1,0,1,2,-1,-4};
        List<List<Integer>> result = new ArrayList<>();
        long start = System.currentTimeMillis();
        result = solution.threeSums(nums);
        long end = System.currentTimeMillis();
        System.out.println("Done in " + (end - start));
    }
}
