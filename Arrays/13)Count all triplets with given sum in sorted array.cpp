Count all triplets with given sum in sorted array
Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, such that arr[i] + arr[j] + arr[k] = target and i < j < k.

Examples:
Input: arr[] = [-3, -1, -1, 0, 1, 2], target = -2
Output: 4
Explanation: Two triplets that add up to -2 are:
arr[0] + arr[3] + arr[4] = (-3) + 0 + (1) = -2
arr[0] + arr[1] + arr[5] = (-3) + (-1) + (2) = -2
arr[0] + arr[2] + arr[5] = (-3) + (-1) + (2) = -2
arr[1] + arr[2] + arr[3] = (-1) + (-1) + (0) = -2

Input: arr[] = [-2, 0, 1, 1, 5], target = 1
Output: 0
Explanation: There is no triplet whose sum is equal to 1. 

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int n=arr.size();
        unordered_map<int,int>mpp;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(mpp.find(target-(arr[i]+arr[j]))!=mpp.end()){
                    cnt+=mpp[target-(arr[i]+arr[j])];
                }
            }
            mpp[arr[i]]++;
        }
        return cnt;
        
//Dry Run
//1. Initialization:
   //- `arr = [-3, -1, -1, 0, 1, 2]`
   //- `target = -2`
   //- `n = 6`
   //- `mpp` is empty `{}`.
   //- `cnt = 0`.

//2. Outer loop: Iterate `i` from `0` to `5`:
     //- Iteration 1 (`i = 0`):
    // - `arr[i] = -3`
    // - Inner loop: Iterate `j` from `1` to `5`:
    // - `j = 1`: 
     //    - `arr[j] = -1`
      //   - Calculate `required = target - (arr[i] + arr[j]) = -2 - (-3 + -1) = -2 + 4 = 2`.
     //    - `mpp` does not contain `2`, so nothing is added to `cnt`.
     //  - `j = 2`: 
        // - `arr[j] = -1`
     //    - Calculate `required = -2 - (-3 - 1) = -2 + 4 = 2` (same as above).
        // - `mpp` does not contain `2`, so nothing is added to `cnt`.
      // -`j = 3`: 
        // - `arr[j] = 0`
         //- Calculate `required = -2 - (-3 + 0) = -2 + 3 = 1`.
     //    - `mpp` does not contain `1`, so nothing is added to `cnt`.
      // - `j = 4`: 
      //   - `arr[j] = 1`
      //   - Calculate `required = -2 - (-3 + 1) = -2 + 2 = 0`.
       //  - `mpp` does not contain `0`, so nothing is added to `cnt`.
    //   - `j = 5`: 
      //   - `arr[j] = 2`
      //   - Calculate `required = -2 - (-3 + 2) = -2 + 1 = -1`.
      //   - `mpp` does not contain `-1`, so nothing is added to `cnt`.
    // - Update `mpp[-3]++` → `mpp = {-3: 1}`.

   //- Iteration 2 (`i = 1`):
     //- `arr[i] = -1`
    // - Inner loop, iterate `j` from `2` to `5`:
       
      // - `j = 2`: 
        // - `arr[j] = -1`
      //   - Calculate `required = -2 - (-1 - 1) = -2 + 2 = 0`.
       //  - `mpp` does not contain `0`, so nothing is added to `cnt`.
    //   - `j = 3`: 
      //   - `arr[j] = 0`
        // - Calculate `required = -2 - (-1 + 0) = -2 + 1 = -1`.
        // - `mpp` contains `-1` (the number of times `-1` has been seen before is `0`).
         //- `cnt += 0` (still remains `0`).
    //   - `j = 4`: 
      //   - `arr[j] = 1`
       //  - Calculate `required = -2 - (-1 + 1) = -2 + 0 = -2`.
    //     - `mpp` does not contain `-2`, so nothing is added to `cnt`.
     //  - `j = 5`: 
      //   - `arr[j] = 2`
    //     - Calculate `required = -2 - (-1 + 2) = -2 + 1 = -1`.
    //     - `mpp` contains `-1` (the number of times `-1` has been seen before is `1`).
     //    - `cnt += 1` → now `cnt = 1`.
   //  - Update `mpp[-1]++` → `mpp = {-3: 1, -1: 1}`.

  // - Iteration 3** (`i = 2`):
   //  - `arr[i] = -1`
   //  - Inner loop, iterate `j` from `3` to `5`:
       
   //    - `j = 3`: 
   //      - `arr[j] = 0`
    //     - Calculate `required = -2 - (-1 - 1) = -2 + 2 = 0`.
     //    - `mpp` does not contain `0`, so nothing is added to `cnt`.
       //- `j = 4`: 
       //  - `arr[j] = 1`
        // - Calculate `required = -2 - (-1 + 1) = -2 + 0 = -2`.
       //  - `mpp` does not contain `-2`, so nothing is added to `cnt`.
      // - `j = 5`: 
        // - `arr[j] = 2`
      //   - Calculate `required = -2 - (-1 + 2) = -2 + 1 = -1`.
      //   - `mpp` contains `-1` (the number of times `-1` has been seen before is `1`).
     //    - `cnt += 1` → now `cnt = 2`.
    // - Update `mpp[-1]++` → `mpp = {-3: 1, -1: 2}`.

   //- Iteration 4(`i = 3`):
     //- `arr[i] = 0`
     //- Inner loop, iterate `j` from `4` to `5`:
       
      // - `j = 4`: 
       //  - `arr[j] = 1`
      //   - Calculate `required = -2 - (0 + 1) = -2 - 1 = -3`.
       //  - `mpp` contains `-3` (the number of times `-3` has been seen before is `1`).
       //  - `cnt += 1` → now `cnt = 3`.
    //   - `j = 5`: 
        // - `arr[j] = 2`
      //   - Calculate `required = -2 - (0 + 2) = -2 - 2 = -4`.
        // - `mpp` does not contain `-4`, so nothing is added to `cnt`.
    // - Update `mpp[0]++` → `mpp = {-3: 1, -1: 2, 0: 1}`.

   //- Iteration 5 (`i = 4`):
    // - `arr[i] = 1`
     //- Inner loop, iterate `j` from `5` to `5` (only one j):
       
       //- `j = 5`: 
         //- `arr[j] = 2`
       //  - Calculate `required = -2 - (1 + 2) = -2 - 3 = -5`.
        // - `mpp` does not contain `-5`, so nothing is added to `cnt`.
     //- Update `mpp[1]++` → `mpp = {-3: 1, -1: 2, 0: 1, 1: 1}`.

//3.Final Count: After finishing all iterations, the final value of `cnt` is `3`.
    }
};