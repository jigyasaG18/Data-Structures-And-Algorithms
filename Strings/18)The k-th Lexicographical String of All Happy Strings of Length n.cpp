The k-th Lexicographical String of All Happy Strings of Length n
A happy string is a string that consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

Example 1:
Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".

Example 2:
Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.

Example 3:
Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab".

class Solution {
    public:
    bool func(int ind,char prev,string &ans,int &n,int &k){
        if(ind==n){ //if we reached the end 
            k--; 
            if(k==0) return true;
            else return false;
        }
        bool res=false;
        for(char ch ='a';ch<='c';ch++){
            if(ch!=prev){ //current character should not be equal to previous character
                ans.push_back(ch); //push the character into the ans string
                res=func(ind+1,ch,ans,n,k); //now char ch becomes the previous char
                if(res==true) return true;
                ans.pop_back(); //pop the character from ans string
            }
        }
        return res; //return res
    }
        string getHappyString(int n, int k) {
            string ans="";
            func(0,'d',ans,n,k); //any character will work instead of a,b,c in char prev
            return ans;
        }
    };