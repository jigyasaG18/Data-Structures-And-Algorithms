Tuple with Same Product
Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

Example 1:
Input: nums = [2,3,4,6]
Output: 8
Explanation: There are 8 valid tuples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)

Example 2:
Input: nums = [1,2,4,5,10]
Output: 16
Explanation: There are 16 valid tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)

//Approach
//Compute all pairs (i, j) and their products.
//Store product frequencies in a hashmap.
//For each new pair (x, y), if product = x * y exists in the map:
//We can pair it with all previous occurrences → forming 8 × count(product) new tuples.
//Update the hashmap for future pairs.
//Why 8 × count(product)?
//Each matching pair (p1, p2) & (q1, q2) can be arranged as:
//(p1, p2, q1, q2), (p2, p1, q1, q2), (p1, p2, q2, q1), … (8 ways).

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
         unordered_map<int, int> mpp;
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                ans += 8 * mpp[product];
                mpp[product]++;
            }
        return ans;
    }
};