Positive and negative elements
Given an array arr containing equal number of positive and negative elements, arrange the array such that every positive element is followed by a negative element.
Note: The relative order of positive and negative numbers should be maintained.

Examples:
Input: arr[] = [-1, 2, -3, 4, -5, 6]
Output: [2, -1, 4, -3, 6, -5]
Explanation: Positive numbers in order are 2, 4 and 6. Negative numbers in order are -1, -3 and -5. So the arrangement we get is 2, -1, 4, -3, 6 and -5.

Input: arr[] = [-3, 2, -4, 1]
Output: [2, -3, 1, -4] 
Explanation: The positive numbers are 2,1 and negetive numbers are -3, -4.

class Solution {
    public:
      vector<int> arranged(vector<int>& arr) {
          // code here
          int n=arr.size();
          vector<int>positive,negative;
          int index=0;
          for(int i=0;i<n;i++){
              if(arr[i]<0){
                  negative.push_back(arr[i]);
              }
              else{
                  positive.push_back(arr[i]);
              }
          }
          // Alternate between positive and negative numbers
          int i = 0, j = 0;
          while (index < n) {
              arr[index] = positive[i];
              index++;
              i++;
              
              arr[index] = negative[j];
              index++;
              j++;
          }
          return arr;
      }
  };