Reverse a String
You are given a string s, and your task is to reverse the string.

Examples:
Input: s = "Geeks"
Output: "skeeG"

Input: s = "for"
Output: "rof"

Input: s = "a"
Output: "a"

1st Way:-
class Solution {
  public:
    string reverseString(string& s) {
        // code here
        int n=s.length();
        int left=0;
        int right=n-1;
        while(left<right){ // or while(left<=right) can also be used
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }
};

2nd Way:-
class Solution {
public:
    void reverseString(vector<char>& s) {
         int n=s.size();
        int left=0;
        int right=n-1;
        while(left<right){ // or while(left<=right) can also be used
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};