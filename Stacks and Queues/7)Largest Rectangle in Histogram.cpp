Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4

1st Way:-
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxarea = max(maxarea, heights[element] * (nse - pse - 1));  
            }
            st.push(i);
        }
            while (!st.empty()) {
                int element = st.top();
                st.pop();
                int nse = n;
                int pse = st.empty() ? -1 : st.top();
                maxarea = max(maxarea, heights[element] * (nse - pse - 1));
            }
        return maxarea;
    }
};

2nd Way:-
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         stack < int > st;
      int maxA = 0;
      int n = heights.size();
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
          int height = heights[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }
};