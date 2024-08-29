class Solution {

    // Function to find floor of x
    // arr: input array
    // n is the size of array
    static int findFloor(long arr[], int n, long x) {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x) return i;
            else if (arr[i] > x) return i - 1;
        }
        return -1;
    }
}
public class FloorSorted_Array {
    public static void main(String[] args) {

        long arr[] = {1, 2, 8, 10, 10, 12, 19};
        int n = arr.length;
        long x = 5;
        System.out.println(Solution.findFloor(arr, n, x));
    }
}
