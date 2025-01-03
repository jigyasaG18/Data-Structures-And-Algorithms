Count Subarrays with given XOR
Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

Examples: 
Input: arr[] = [4, 2, 2, 6, 4], k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.

Input: arr[] = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. Hence, the answer is 2.

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mpp;
        int cnt=0;
        int xorr=0;
        for(int i=0;i<n;i++){
            xorr=xorr^arr[i];
            if(xorr==k) cnt++;
// Check if there exists a prefix XOR that gives the required XOR with k
            int requiredXor = xorr ^ k;
            if (mpp.find(requiredXor) != mpp.end()) {
                cnt += mpp[requiredXor];
            }
            mpp[xorr]++;
        }
        return cnt;
        
 //Dry Run:-
//arr = [4, 2, 2, 6, 4] and k=6
//Let's dry run the provided code with the given input array `arr = [4, 2, 2, 6, 4]` and query value `k = 6`.
//1. Iteration through the array elements:
  // - i = 0 (arr[0] = 4)
   //  - `xorr = 0 ^ 4 = 4`
   //  - Check if `xorr == k`: `4 == 6` (False)
  //   - Update `cnt += mpp[4 ^ 6]` (which is `cnt += mpp[2]`):
    //   - Since `mpp` is empty, `mpp[2] = 0`. So, `cnt = 0 + 0 = 0`.
   //  - Update the map: `mpp[4]++` ➔ `{4: 1}`
  
 //i = 1 (arr[1] = 2)
// - `xorr = 4 ^ 2 = 6`
  //   - Check if `xorr == k`: `6 == 6` (True)
     //  - Increment `cnt`: `cnt = 0 + 1 = 1`.
    // - Update `cnt += mpp[6 ^ 6]` (which is `cnt += mpp[0]`):
     //  - Since `mpp` only has `4`, `mpp[0] = 0`. So, `cnt = 1 + 0 = 1`.
 //    - Update the map: `mpp[6]++` ➔ `{4: 1, 6: 1}`
  
  // i = 2 (arr[2] = 2)
  //   - `xorr = 6 ^ 2 = 4`
   //  - Check if `xorr == k`: `4 == 6` (False)
  //   - Update `cnt += mpp[4 ^ 6]` (which is `cnt += mpp[2]`):
  //     - Since `mpp` has `4` and `6` but not `2`, `mpp[2] = 0`. So, `cnt = 1 + 0 = 1`.
   //  - Update the map: `mpp[4]++` ➔ `{4: 2, 6: 1}`
  
  // i = 3 (arr[3] = 6)
   //  - `xorr = 4 ^ 6 = 2`
   //  - Check if `xorr == k`: `2 == 6` (False)
    // - Update `cnt += mpp[2 ^ 6]` (which is `cnt += mpp[4]`):
    //   - `mpp[4] = 2`. So, `cnt = 1 + 2 = 3`.
  //   - Update the map: `mpp[2]++` ➔ `{4: 2, 6: 1, 2: 1}`

   //i = 4 (arr[4] = 4)
    // - `xorr = 2 ^ 4 = 6`
     //- Check if `xorr == k`: `6 == 6` (True)
     //  - Increment `cnt`: `cnt = 3 + 1 = 4`.
   //  - Update `cnt += mpp[6 ^ 6]` (which is `cnt += mpp[0]`):
     //  - Again, `mpp[0] = 0`. So, `cnt = 4 + 0 = 4`.
    // - Update the map: `mpp[6]++` ➔ `{4: 2, 6: 2, 2: 1}`

//At the end of the iterations, the value of `cnt` is `4`.
    }
};