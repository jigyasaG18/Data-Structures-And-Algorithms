Trapping Rain Water
Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

Examples:
Input: arr[] = [3, 0, 1, 0, 4, 0 2]
Output: 10
Explanation: Total water trapped = 0 + 3 + 2 + 3 + 0 + 2 + 0 = 10 units.

Input: arr[] = [3, 0, 2, 0, 4]
Output: 7
Explanation: Total water trapped = 0 + 3 + 1 + 3 + 0 = 7 units.

Input: arr[] = [1, 2, 3, 4]
Output: 0
Explanation: We cannot trap water as there is no height bound on both sides.

Input: arr[] = [2, 1, 5, 3, 1, 0, 4]
Output: 9
Explanation: Total water trapped = 0 + 1 + 0 + 1 + 3 + 4 + 0 = 9 units.

1st Way:-
class Solution {
    // Function to find the trapped water between the blocks.
  public:
    int trappingWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int total=0;
        vector<int>prefixmax(n);
        vector<int>suffixmax(n);
        prefixmax[0]=arr[0];
        for(int i=0;i<n;i++){
            prefixmax[i]=max(prefixmax[i-1],arr[i]);
        }
        suffixmax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            suffixmax[i]=max(suffixmax[i+1],arr[i]);
        }
        for(int i=0;i<n;i++){
            int leftmax=prefixmax[i];
            int rightmax=suffixmax[i];
            
            if(arr[i]<leftmax && arr[i]<rightmax){
                total+=min(leftmax,rightmax)-arr[i];
            }
        }
        return total;
    }
};

2nd Way:-
class Solution {

    // Function to find the trapped water between the blocks.
  public:
    int trappingWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int lmax=0;
        int rmax=0;
        int total=0;
        int l=0;
        int r=n-1;
        while(l<=r){
            if(arr[l]<arr[r]){
                if(lmax>arr[l]){
                    total+=lmax-arr[l];
                }
                else {
                    lmax=arr[l];
                }
                 l++;
            }
            else {
                if(rmax>arr[r]){
                    total+=rmax-arr[r];
                }
                else{
                    rmax=arr[r];
                }
                  r--;
            }
        }
        return total;
    }
};