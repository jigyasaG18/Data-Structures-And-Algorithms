Longest Consecutive Subsequence
Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Examples:
Input: arr[] = [2, 6, 1, 9, 4, 5, 3]
Output: 6
Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.
Input: arr[] = [1, 9, 3, 10, 4, 20, 2]
Output: 4
Explanation: 1, 2, 3, 4 is the longest consecutive subsequence.
Input: arr[] = [15, 13, 12, 14, 11, 10, 9]
Output: 7
Explanation: The longest consecutive subsequence is 9, 10, 11, 12, 13, 14, 15, which has a length of 7.

class Solution {
public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int res=1;
        int current=1;
        if(n==0) return 0;
        for (int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
               continue;
            }
            if(arr[i]==arr[i-1]+1){
                current++;
            }else{
                res = max(res,current);
                current=1;
            }
        }
        res = max(res,current);
        return res;
        
//eg. 2 6 1 9 4 5 3 
//sort- 1 2 3 4 5 6 9
// i = 1: arr[i] (2) == arr[i-1] (1) + 1 is true, so increment current -> current = 2.
//i = 2: arr[i] (3) == arr[i-1] (2) + 1 is true, so increment current -> current = 3. 
//i = 3: arr[i] (4) == arr[i-1] (3) + 1 is true, so increment current -> current = 4. 
//i = 4: arr[i] (5) == arr[i-1] (4) + 1 is true, so increment current -> current = 5. 
//i = 5: arr[i] (6) == arr[i-1] (5) + 1 is true, so increment current -> current = 6.
//i = 6: arr[i] (9) == arr[i-1] (6) + 1 is false. 
//Now we execute the else block: res = max(res, current) gives res = max(1, 6) = 6. 
//Reset current to 1 for the new sequence. 
//Final Calculation: After the loop ends, we have: We check res = max(res, current) one last time.
//Since current is now 1, we do the calculation: res = max(6, 1) = 6.
    }
};