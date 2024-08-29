import java.lang.*;
import java.util.*;

class Solution {
    public String removeOuterParentheses(String s) {
        int count = 0;
        StringBuilder s1 = new StringBuilder("");
        for (int i = 0; i < s.length(); i++) 
        {
            if (s.charAt(i) == '(')
            {
                count++;
                if (count > 1)
                {
                    s1.append(s.charAt(i));
                }
            }
            else if (s.charAt(i) == ')')
            {
                count--;
                if (count > 0)
                {
                    s1.append(s.charAt(i));
                }
            }
        }
        return s1.toString();
    }
}

public class removeOuterPar {
    public static void main(String[] args) {
        String s = "(()())(())";
        Solution obj = new Solution();
        System.out.println(obj.removeOuterParentheses(s));
    }
}