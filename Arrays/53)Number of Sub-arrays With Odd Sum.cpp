Number of Sub-arrays With Odd Sum
Given an array of integers arr, return the number of subarrays with an odd sum.
Since the answer can be very large, return it modulo 109 + 7.

Example 1:
Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.

Example 2:
Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.

Example 3:
Input: arr = [1,2,3,4,5,6,7]
Output: 16

1st Way:-
class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int n=arr.size();
            int mod=1e9+7;
            int oddcnt=0;
            int evencnt=0;
            int sum=0;
            long long int ans=0;
            for(auto it : arr){
                sum += it;
                if(sum%2==0){
                    evencnt++;
                    ans += (oddcnt)%mod; //odd+odd=even and even+even=even
                    //we are adding oddcnt because we got an even sum but we need odd sum and even+odd will result in odd sum
                }
                else{
                    oddcnt++;
                    ans += (evencnt+1)%mod; //odd+even=odd
                }
            }
            return (ans)%mod;
        }
    };

2nd Way:-class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int n=arr.size();
            int mod=1e9+7;
            int oddcnt=0;
            int evencnt=1; //since we are considered prefix sum as 0 and it is even hence even cnt we can take as 1
            int sum=0;
            long long int ans=0;
            for(auto it : arr){
                sum += it;
                if(sum%2==0){
                    evencnt++;
                    ans += (oddcnt)%mod; //odd+odd=even and even+even=even
                    //we are adding oddcnt because we got an even sum but we need odd sum and even+odd will result in odd sum
                }
                else{
                    oddcnt++;
                    ans += (evencnt)%mod; //odd+even=odd
                }
            }
            return (ans)%mod;
        }
    };
