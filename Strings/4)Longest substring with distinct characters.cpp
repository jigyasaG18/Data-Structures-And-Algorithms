Longest substring with distinct characters
Given a string s, find the length of the longest substring with all distinct characters. 

Examples:
Input: s = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest substring with all distinct characters.

Input: s = "aaa"
Output: 1
Explanation: "a" is the longest substring with all distinct characters.

Input: s = "abcdefabcbb"
Output: 6
Explanation: The longest substring with all distinct characters is "abcdef", which has a length of 6.

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<int,int>mpp;
        int maxcnt=0;
        int start=0;
        for(int end=0;end<s.length();end++){
            if(mpp.find(s[end])!=mpp.end() && mpp[s[end]]>=start){
                //char is repeated within the current window
                start=mpp[s[end]]+1;
            }
            mpp[s[end]]=end;
            
            maxcnt=max(maxcnt,end-start+1);
        }
        return maxcnt;
    }
};