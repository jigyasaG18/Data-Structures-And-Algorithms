Subarrays with Sum K
Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.

Examples:
Input: arr = [10, 2, -2, -20, 10], k = -10
Output: 3
Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.

Input: arr = [9, 4, 20, 3, 10, 5], k = 33
Output: 2
Explaination: Subarrays: arr[0...2], arr[2...4] have sum exactly equal to 33.

Input: arr = [1, 3, 5], k = 0
Output: 0
Explaination: No subarray with 0 sum.

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mpp;
        int cnt=0;
        int sum=0;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(mpp.find(sum-k)!=mpp.end()){
                cnt+=mpp[sum-k];
            }
            mpp[sum]++;
        }
        return cnt;
        
//Dry Run of the Code:
//Let's dry run this code with the given inputs.
//Initial State:
//mpp = {0: 1}
//Iteration 0 (i = 0, arr[0] = 9):
//Cumulative sum: sum = 9
//Check for sum - k = 9 - 33 = -24 in mpp: it's not found, so cnt remains 0.
//Update mpp: mpp = {0: 1, 9: 1}
//Iteration 1 (i = 1, arr[1] = 4):
//Cumulative sum: sum = 13
//Check for sum - k = 13 - 33 = -20: not found, cnt remains 0.
//Update mpp: mpp = {0: 1, 9: 1, 13: 1}
//Iteration 2 (i = 2, arr[2] = 20):
//Cumulative sum: sum = 33
//Check for sum - k = 33 - 33 = 0: found in mpp, which has a count of 1, so increment cnt: cnt = 1 + 0 = 1.
//Update mpp: mpp = {0: 1, 9: 1, 13: 1, 33: 1}
//Iteration 3 (i = 3, arr[3] = 3):
//Cumulative sum: sum = 36
//Check for sum - k = 36 - 33 = 3: not found, cnt remains 1.
//Update mpp: mpp = {0: 1, 9: 1, 13: 1, 33: 1, 36: 1}
//Iteration 4 (i = 4, arr[4] = 10):
//Cumulative sum: sum = 46
//Check for sum - k = 46 - 33 = 13: found in mpp, which has a count of 1, so increment cnt: cnt = 1 + 1 = 2.
//Update mpp: mpp = {0: 1, 9: 1, 13: 1, 33: 1, 36: 1, 46: 1}
//Iteration 5 (i = 5, arr[5] = 5):
//Cumulative sum: sum = 51
//Check for sum - k = 51 - 33 = 18: not found, cnt remains 2.
//Update mpp: mpp = {0: 1, 9: 1, 13: 1, 33: 1, 36: 1, 46: 1, 51: 1}
//Final Output:
//The final value of cnt is 2, which is returned by the function. This indicates that there are indeed two subarrays that sum to 33:
//The subarray from index 0 to 2: arr[0..2] = [9, 4, 20] (sum is 33)
//The subarray from index 2 to 4: arr[2..4] = [20, 3, 10] (sum is 33)
    }
};