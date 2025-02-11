Count ways to N'th Stair
There are n stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).

Example 1:
Input: n = 4
Output: 3
Explanation: 
You can reach 4th stair in 3 ways. 3 possible ways are:
1, 1, 1, 1
1, 1, 2
2, 2
Here, note that {1, 1, 2}, {1, 2, 1} and {2, 1, 1} are considered same as their order does not matter. 

Example 2:
Input: n = 5
Output: 3
Explanation: You may reach the 5th stair in 3 ways. The 3 possible ways are:
1, 1, 1, 1, 1
1, 1, 1, 2
1, 2, 2

class Solution {
    public:
      // Function to count number of ways to reach the nth stair
      // when order does not matter.
      long long countWays(int n) {
          // your code here
          return n/2 + 1;
      }
  };