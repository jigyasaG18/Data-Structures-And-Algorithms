Common in 3 Sorted Arrays
You are given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
If there are no such elements return an empty array. In this case, the output will be -1.
Note: can you handle the duplicates without using any additional Data Structure?

Examples :
Input: arr1 = [1, 5, 10, 20, 40, 80] , arr2 = [6, 7, 20, 80, 100] , arr3 = [3, 4, 15, 20, 30, 70, 80, 120]
Output: [20, 80]
Explanation: 20 and 80 are the only common elements in arr, brr and crr.

Input: arr1 = [1, 2, 3, 4, 5] , arr2 = [6, 7] , arr3 = [8,9,10]
Output: [-1]
Explanation: There are no common elements in arr, brr and crr.

Input: arr1 = [1, 1, 1, 2, 2, 2], B = [1, 1, 2, 2, 2], arr3 = [1, 1, 1, 1, 2, 2, 2, 2]
Output: [1, 2]
Explanation: We do not need to consider duplicates

class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        vector<int>ans;
        unordered_map<int,int>mpp;
        for (int i:arr2){
            mpp[i]++;
        }
        unordered_map<int,int>mpp2;
        for (int j:arr3){
            mpp2[j]++;
        }
        
        for (int k:arr1){
            if (mpp.find(k)!=mpp.end() && mpp2.find(k)!=mpp.end()){
                   ans.push_back(k);
                   mpp.erase(k);
                   mpp2.erase(k);
            }
        }

        if (ans.size()==0)   return {-1};
        return ans;
    }
};