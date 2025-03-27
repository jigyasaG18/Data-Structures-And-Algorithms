Maximal Rectangle
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1

class Solution {
    public:
    int largestRectangleArea(vector<int>& heights) {
            stack<int> st;
            int maxarea = 0;
            int n = heights.size();
            int width;
            for (int i = 0; i <= n; i++) {
                while (!st.empty() && (i==n || heights[st.top()] >= heights[i])) {
                    int height = heights[st.top()];
                    st.pop();
                    if(st.empty()) width=i;
                    else width=i-st.top()-1;
                    maxarea=max(maxarea,height*width);
                }
                st.push(i);
                }
                return maxarea;
                }
        int maximalRectangle(vector<vector<char>>& matrix) {
            int n=matrix.size();
            int m=matrix[0].size();
            int maxarea=0;
            vector<int>height(m,0);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]=='1'){
                        height[j]++;
                    }
                    else height[j]=0;
                }
                int area=largestRectangleArea(height);
                maxarea=max(maxarea,area);
            }
            return maxarea;
        }
    };