Given an array arr[], its starting position l and its ending position r. Sort the array using the merge sort algorithm.

Examples:
Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]

Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

Input: arr[] = [1, 3 , 2]
Output: [1, 2, 3]

class Solution {
    public:
    void merge(vector<int> &arr, int l, int m, int r)
      {
           // Your code here
           vector<int> temp;
           int left=l;
           int right=m+1;
           while(left<=m && right<=r)
           {
               if(arr[left]<=arr[right]){
               temp.push_back(arr[left]);
               left++;
               }
               else{
               temp.push_back(arr[right]);
               right++;
               }
           }    
           while(left<=m)
           {
                temp.push_back(arr[left]);
                left++;
           }
           while(right<=r)
           {
                temp.push_back(arr[right]);
                right++;
           }
           for(int i=l; i<=r; i++)
           {
               arr[i]=temp[i-l];
           }
      }
      void mergeSort(vector<int>& arr, int l, int r) {
          // code here
          if(l>=r)return;
          int mid = (l+r)/2;
          mergeSort(arr,l,mid);
          mergeSort(arr,mid+1,r);
          merge(arr,l,mid,r);
      }
  };