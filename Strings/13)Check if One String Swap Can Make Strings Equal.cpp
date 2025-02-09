Check if One String Swap Can Make Strings Equal
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

Example 1:
Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".

Example 2:
Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.

Example 3:
Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.

//The solution checks if two strings can be made equal with at most one swap by tracking the first mismatch and attempting a swap when a second mismatch is found. The core logic:
// 0 mismatches: Already equal 
// 1 mismatch: Impossible to fix with one swap 
// 2 mismatches: Swap and check if strings become equal 
// >2 mismatches: Immediately return false 

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int pos = -1;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]){
                if(pos == -1) { //it is first mismatch
                pos = i;
                }
                else{
                    swap(s1[i] , s1[pos]);
                    return s1 == s2;
                }
            }
        }
        return s1 == s2;
    }
};