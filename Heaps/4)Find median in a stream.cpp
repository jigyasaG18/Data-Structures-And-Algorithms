Find median in a stream
Given a data stream arr[] where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read.
There are two cases for median on the basis of data set size.
1. If the data set has an odd number then the middle one will be consider as median.
2. If the data set has an even number then there is no distinct middle value and the median will be the arithmetic mean of the two middle values.

Examples:
Input:  arr[] = [5, 15, 1, 3, 2, 8]
Output: [5.0, 10.0, 5.0, 4.0, 3.0, 4.0] 
Explanation: 
After reading 1st element of stream – 5 -> median = 5.0
After reading 2nd element of stream – 5, 15 -> median = (5+15)/2 = 10.0 
After reading 3rd element of stream – 5, 15, 1 -> median = 5.0
After reading 4th element of stream – 5, 15, 1, 3 ->  median = (3+5)/2 = 4.0
After reading 5th element of stream – 5, 15, 1, 3, 2 -> median = 3.0
After reading 6th element of stream – 5, 15, 1, 3, 2, 8 ->  median = (3+5)/2 = 4.0

Input: arr[] = [2, 2, 2, 2]
Output: [2.0, 2.0, 2.0, 2.0]
Explanation: 
After reading 1st element of stream – 2 -> median = 2.0
After reading 2nd element of stream – 2, 2 -> median = (2+2)/2 = 2.0
After reading 3rd element of stream – 2, 2, 2 -> median = 2.0
After reading 4th element of stream – 2, 2, 2, 2 ->  median = (2+2)/2 = 2.0

class Solution {
    public:
      vector<double> getMedian(vector<int> &arr) {
          // code here
          int n=arr.size();
          priority_queue<int>maxheap;
          priority_queue<int,vector<int>,greater<int>>minheap;
          vector<double>ans;
          for(int i=0;i<n;i++){
              maxheap.push(arr[i]);
              
              int temp=maxheap.top();
              maxheap.pop();
              minheap.push(temp);
              
              if(minheap.size()>maxheap.size()){
                  temp=minheap.top();
                  minheap.pop();
                  maxheap.push(temp);
              }
              double median;
          if(maxheap.size()!=minheap.size()){
              median = maxheap.top();
          }
          else{
              median = (double)((maxheap.top())+(minheap.top()))/2;
          }
            ans.push_back(median);
          }
          return ans;
      }
  };