Product Array Puzzle
Given an array, arr[] construct a product array, res[] where each element in res[i] is the product of all elements in arr[] except arr[i]. Return this resultant array, res[].
Note: Each element is res[] lies inside the 32-bit integer range.

Examples:
Input: arr[] = [10, 3, 5, 6, 2]
Output: [180, 600, 360, 300, 900]
Explanation: For i=0, res[i] = 3 * 5 * 6 * 2 is 180.
For i = 1, res[i] = 10 * 5 * 6 * 2 is 600.
For i = 2, res[i] = 10 * 3 * 6 * 2 is 360.
For i = 3, res[i] = 10 * 3 * 5 * 2 is 300.
For i = 4, res[i] = 10 * 3 * 5 * 6 is 900.

Input: arr[] = [12, 0]
Output: [0, 12]
Explanation: For i = 0, res[i] is 0.
For i = 1, res[i] is 12.

// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n=arr.size();
        int product=1;
        int zero=0;
        for(auto it : arr){
            if(it != 0) product*=it;
            else zero++;
        }
        vector<int>result(arr.size());
        for(int i=0;i<n;i++){
            if(zero>1) result[i]=0; //More than one zero results in all zeros
            else if(zero==1) { // One zero means zero for non-zero elements as in [12,0] can be produced as [0,12]
                if(arr[i]==0) result[i]=product;
                else if(arr[i]!=0) result[i]=0;
            }      
            else result[i]=product/arr[i];
        }
        return result;
    }
};