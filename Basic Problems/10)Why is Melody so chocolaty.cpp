Why is Melody so chocolaty?
Chunky gets happy by eating Melody. Given an array arr[], each element represents the happiness Chunky gets by eating the melody.
Chunky knows why Melody is so chocolaty but will only tell you once you tell him the maximum happiness he can get by eating two adjacent melodies.

Examples:
Input : arr[] = [1, 2, 3, 4, 5]
Output : 9
Explanation: maximum happiness he can get is 9, selecting arr[3] = 4 and arr[4] = 5 which adds up to 9.

Input : arr[] = [2, 1, 3, 4]
Output : 7
Explanation: maximum happiness he can get is 7, selecting arr[2] = 3 and arr[3] = 4 which adds up to 7.

class Solution {
    public:
      int maxHappiness(vector<int> &arr) {
          // Your code goes here.
          int n=arr.size();
          int maxi=INT_MIN;
          for(int i=0;i<n-1;i++){
              int sum=arr[i]+arr[i+1];
              maxi=max(maxi,sum);
          }
          return maxi;
      }
  };