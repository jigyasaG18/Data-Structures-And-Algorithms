Kth Smallest Number in Multiplication Table
Given three integers m, n and k. Consider a grid of m * n, where mat[i][j] = i * j (1 based index). The task is to return the kth smallest element in the m * n multiplication table.

Examples :
Input: m = 3, n = 3, k = 5
Output: 3
Explanation: The 5th smallest element is 3. 

Input: m = 2, n = 3, k = 6
Output: 6 
Explanation: [1, 2, 3][2, 4, 6]. The 6th smallest element is 6.

class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
       int low=1;
       int high=m*n;
       int ans;
       while(low<=high)
       {
           int count=0;
           int mid=(low+high)/2;
 for(int i=1;i<=m;i++)//find the number of smaller element than mid in each row
           {
               count=count+min(mid/i,n);
           }
           if(count>=k)
           {
               high=mid-1;
               ans=mid;
           }
           else
              low=mid+1;
       }
       return ans;
    }
};