
import java.util.*;
class Solution {
    public ArrayList<Integer> majorityElement(int[] nums) {
        ArrayList <Integer> l1 = new ArrayList<Integer>();
        HashMap <Integer, Integer> map = new HashMap<>();
        for (int i : nums) {
            if (map.containsKey(i))
            {
                map.put(i, map.get(i) + 1);
            } else if (!map.containsKey(i)) {
                map.put(i, 1);
            }
        }
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue() > nums.length / 3) 
            {
                l1.add(entry.getKey());    
            }
        }
        return l1;
    }
}
public class majorityElementII 
{

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {0,0,0};
        System.out.println(solution.majorityElement(nums));
    }
}