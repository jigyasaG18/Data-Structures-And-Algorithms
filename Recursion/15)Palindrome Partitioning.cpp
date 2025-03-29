Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]

class Solution {
    public:
    bool ispalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    void func(int ind,string s,vector<vector<string>>&res,vector<string>&ans){
        if(ind==s.size()){
            res.push_back(ans);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(ispalindrome(s,ind,i)){
                ans.push_back(s.substr(ind,i-ind+1));
                func(i+1,s,res,ans);
                ans.pop_back();
                        }
        }
    }
        vector<vector<string>> partition(string s) {
            vector<vector<string>>res;
            vector<string>ans;
            func(0,s,res,ans);
            return res;
        }
    };