Pair with given sum in a sorted array
You are given an integer target and an array arr[]. You have to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order.
Note: pairs should have elements of distinct indexes. 

Examples :
Input: arr[] = [-1, 1, 5, 5, 7], target = 6
Output: 3
Explanation: There are 2 pairs which sum up to 6 : {1, 5}, {1, 5} and {-1, 7}.

Input: arr[] = [1, 1, 1, 1], target = 2
Output: 6
Explanation: There are 6 pairs which sum up to 2 : {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1} and {1, 1}.

Input: arr[] = [-1, 10, 10, 12, 15], target = 125
Output: 0
Explanation: There is no such pair which sums up to 4.

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int cnt=0;
        unordered_map<int,int>mpp;
        for(auto it : arr){
            if(mpp.find(target-it)!=mpp.end()){
                cnt+=mpp[target-it];
            }
            mpp[it]++;
        }
        return cnt;
        
//Let's dry run your provided code using the input `arr[] = [-1, 1, 5, 5, 7]` and `target = 6`. 
//1. First Iteration (it = -1):
//- `target - it = 6 - (-1) = 7`
//- Check `mpp.find(7)`: not found (since `mpp` is empty)
//- Update `mpp` with `-1`: `mpp = {-1: 1}`
//- `cnt = 0`
//2. Second Iteration (it = 1):
//- `target - it = 6 - 1 = 5`
//- Check `mpp.find(5)`: not found
//- Update `mpp` with `1`: `mpp = {-1: 1, 1: 1}`
//- `cnt = 0`
//3. Third Iteration (it = 5):
//- `target - it = 6 - 5 = 1`
//- Check `mpp.find(1)`: found with count 1
//- Increment `cnt` by `mpp[1]` (which is 1): `cnt = 1`
//- Update `mpp` with `5`: `mpp = {-1: 1, 1: 1, 5: 1}`
//- `cnt = 1`
//4. Fourth Iteration (it = 5):
//- `target - it = 6 - 5 = 1`
//- Check `mpp.find(1)`: found with count 1
//- Increment `cnt` by `mpp[1]` (which is 1): `cnt = 2`
//- Update `mpp` with `5`: `mpp = {-1: 1, 1: 1, 5: 2}`
//- `cnt = 2`
//5. Fifth Iteration (it = 7):
//- `target - it = 6 - 7 = -1`
//- Check `mpp.find(-1)`: found with count 1
//- Increment `cnt` by `mpp[-1]` (which is 1): `cnt = 3`
//- Update `mpp` with `7`: `mpp = {-1: 1, 1: 1, 5: 2, 7: 1}`
//- `cnt = 3`
//After iterating through all the elements in the array, we find that `cnt` is `3`, which is the expected output. 
//The pairs contributing to the count are:
//- `{1, 5}` (first 5)
//- `{1, 5}` (second 5)
//- `{-1, 7}`
    }
};