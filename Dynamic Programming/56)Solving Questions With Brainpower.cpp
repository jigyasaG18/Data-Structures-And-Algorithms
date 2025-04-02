Solving Questions With Brainpower
You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].
The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.
For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
Return the maximum points you can earn for the exam.

Example 1:
Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.

Example 2:
Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.

1st Way:- MEMOIZATION
class Solution {
    public:
    long func(int ind,vector<vector<int>>&questions,vector<long>&dp){
        int n=questions.size();
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        long take=questions[ind][0]+func(ind+questions[ind][1]+1,questions,dp);
        long not_take=func(ind+1,questions,dp);
        return dp[ind]=max(take,not_take);
    }
        long long mostPoints(vector<vector<int>>& questions) {
            int n=questions.size();
            vector<long>dp(n,-1);
            return func(0,questions,dp);
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int n=questions.size();
            vector<long> dp(n + 1, 0); 
            for (int i = n - 1; i >= 0; --i) {
                long take = questions[i][0];
                if (i + questions[i][1] + 1 < n) {
                    take += dp[i + questions[i][1] + 1];
                }
                long not_take = dp[i + 1];            
                dp[i] = max(take, not_take);
            }
            return dp[0];
        }
    };