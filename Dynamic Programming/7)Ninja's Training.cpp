Ninja's or Geek's Training
Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .

Example:
Input: arr[]= [[1, 2, 5], [3, 1, 1], [3, 3, 3]]
Output: 11
Explanation: Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum merit point will be 11.

Input: arr[]= [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
Output: 6
Explanation: Geek can perform any activity each day while adhering to the constraints, in order to maximize his total merit points as 6.

Input: arr[]= [[4, 2, 6]]
Output: 6
Explanation: Geek will learn a new move to make his merit points as 6.

1st Way:- MEMOIZATION
class Solution {
    public:
    int f(int day,int last,vector<vector<int>>& arr,vector<vector<int>>& dp){
        if(day==0){
            int maxi=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    maxi=max(maxi,arr[0][task]);
                }
            }
            return maxi;
        }
        if(dp[day][last]!=-1) return dp[day][last];
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                int point =arr[day][task]+f(day-1,task,arr,dp);
                maxi=max(maxi,point);
            }
        }
        return dp[day][last]=maxi;
    }
      int maximumPoints(vector<vector<int>>& arr) {
          // Code here
          int n=arr.size();
          vector<vector<int>>dp(n,vector<int>(4,-1));
          return f(n-1,3,arr,dp);
      }
  };

2nd Way:- TABULATION
class Solution {
    public:
      int maximumPoints(vector<vector<int>>& arr) {
          // Code here
          int n=arr.size();
          vector<vector<int>>dp(n,vector<int>(4,0));
          dp[0][0]=max(arr[0][1],arr[0][2]);
          dp[0][1]=max(arr[0][0],arr[0][2]);
          dp[0][2]=max(arr[0][0],arr[0][1]);
          dp[0][3]=max(arr[0][0],max(arr[0][1],arr[0][2]));
          
          for(int day=1;day<n;day++){
              for(int last=0;last<4;last++){
                  dp[day][last]=0;
                  for(int task=0;task<3;task++){
                      if(task!=last){
                          int point =arr[day][task]+dp[day-1][task];
                          dp[day][last]=max(dp[day][last],point);
                      }
                  }
              }
          }
          return dp[n-1][3];
      }
  };

3rd Way:- SPACE OPTIMIZATION
class Solution {
    public:
      int maximumPoints(vector<vector<int>>& arr) {
          // Code here
          int n=arr.size();
          vector<int>prev(4,0);
          prev[0]=max(arr[0][1],arr[0][2]);
          prev[1]=max(arr[0][0],arr[0][2]);
          prev[2]=max(arr[0][0],arr[0][1]);
          prev[3]=max(arr[0][0],max(arr[0][1],arr[0][2]));
          
          for(int day=1;day<n;day++){
              vector<int>temp(4,0);
              for(int last=0;last<4;last++){
                  temp[last]=0;
                  for(int task=0;task<3;task++){
                      if(task!=last){
                          int point =arr[day][task]+prev[task];
                          temp[last]=max(temp[last],point);
                      }
                  }
              }
              prev=temp;
          }
          return prev[3];
      }
  };