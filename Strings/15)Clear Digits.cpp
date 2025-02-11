Clear Digits
You are given a string s.
Your task is to remove all digits by doing this operation repeatedly:
Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

Example 1:
Input: s = "abc"
Output: "abc"
Explanation: There is no digit in the string.

Example 2:
Input: s = "cb34"
Output: ""
Explanation:
First, we apply the operation on s[2], and s becomes "c4".
Then we apply the operation on s[1], and s becomes "".

class Solution {
    public:
        string clearDigits(string s) {
            string ans = "";
            for (char c : s){
                if(isdigit(c)){ //if character is a digit, remove it from the ans string
                    if(!ans.empty()){
                        ans.pop_back();
                    }
                }
                else{ //if a character is not a digit, push it into the ans string
                    ans.push_back(c);
                }
            }
            return ans;
        }
    };