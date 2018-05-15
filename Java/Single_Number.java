/*
136. Single Number
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/

public class Single_Number {

    public int singleNumber(int[] nums) {
        int result = 0;
        for (int num : nums) {
            result = result ^ num;
        }
        return result;
    }

    public static void main(String[] args) {
        Single_Number s = new Single_Number();
        int[] nums = {2, 2, 1};
        int result = s.singleNumber(nums);
        System.out.println(result);

        int[] nums2 = {4, 1, 2, 1, 2};
        int result2 = s.singleNumber(nums2);
        System.out.println(result2);
    }
}
