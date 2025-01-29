Distribute Candies Among Children I and II
You are given two positive integers n and limit.
Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.

Example 1:
Input: n = 5, limit = 2
Output: 3
Explanation: There are 3 ways to distribute 5 candies such that no child gets more than 2 candies: (1, 2, 2), (2, 1, 2) and (2, 2, 1).

Example 2:
Input: n = 3, limit = 3
Output: 10
Explanation: There are 10 ways to distribute 3 candies such that no child gets more than 3 candies: (0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2), (1, 1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) and (3, 0, 0).

For I :-
1st Way:-
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;

        // Iterate through all valid counts for the first child
        for (int i = 0; i <= limit; i++) {
            // Iterate through all valid counts for the second child
            for (int j = 0; j <= limit; j++) {
                // Calculate the remaining candies for the third child
                int k = n - (i + j);
                
                // Check if k is within valid range for the third child
                if (0 <= k && k <= limit) {
                    ans++;  // Count this valid distribution
                }
            }
        }
        
        return ans;  // Return total valid distributions
    }
};

2nd Way:-
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans=0;
        for(int i=0;i<=limit;i++){
            for(int j=0;j<=limit;j++){
                for(int k=0;k<=limit;k++){
                    if(i+j+k == n) ans++;
                }
            }
        }
        return ans;
    }
};


For II :-
/* Approach : Min Max Range Distribution
1. Find min and max range of how many candies we can give to first child.
2. For each element in this range, find min and max range of 2nd child.
3. Now, if we give i candies to first child, 
   we can choose to give secondMin to secondMax candies to 2nd child
   and remaining candies to 3rd child.
   So we will have secondMax - secondMin + 1 distribution corresponding to this i.
4. Sum of distributions for all i's will be our ans.
Time : O(n)
Space : O(1)
*/
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        // find min and max range of first child
        int firstMin = max(0, n - 2 * limit);   // we can give maximum limit candies to a child
        int firstMax = min(limit, n);
        // try all possibilities within range of first child
        for(int i=firstMin; i<=firstMax; i++){
            // find min and max range of second child
            int secondMin = max(0, n - i - limit);
            int secondMax = min(limit, n - i);
            /* if we give i candies to first child, 
               we can choose to give secondMin to secondMax candies to 2nd child
               and remaining candies to 3rd child.
               So we will have secondMax - secondMin + 1 distribution corresponding to this i.
            */
            ans += secondMax - secondMin + 1;
        }
        return ans;
    }
};