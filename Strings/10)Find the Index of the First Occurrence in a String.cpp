Find the Index of the First Occurrence in a String
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

1st Way:-
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

2nd Way:-
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        string str;
        for(int i=0;i<haystack.size();i++){
            if(needle[0] == haystack[i]){
                str=haystack.substr(i,n); //extract a substring of length n
                if(str == needle) return i;
            }
        }
        return -1;
    }
};