Longest Happy String
A string s is called happy if it satisfies the following conditions:
s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
A substring is a contiguous sequence of characters within a string.

Example 1:
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

Example 2:
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.

class Solution {
    public:
        string longestDiverseString(int a, int b, int c) {
            priority_queue<pair<int,char>>pq;
            if(a>0) pq.push({a,'a'});
            if(b>0) pq.push({b,'b'});
            if(c>0) pq.push({c,'c'});
            string ans="";
            while(!pq.empty()){
                auto[cnt1,char1]=pq.top();
                pq.pop();
                int n=ans.size();
                if(n>=2 && ans[n-1]==char1 && ans[n-2]==char1){//repetition issue
                    if(pq.empty()) break;//no valid characters left
    
                    auto[cnt2,char2]=pq.top(); 
                    pq.pop();
    
                    ans+=char2;
                    cnt2--;
    
                    if(cnt2>0) pq.push({cnt2,char2}); // Push back char2 if there's still count left
                    pq.push({cnt1,char1});
                }
                else{//no repetition issue
                    ans+=char1;
                    cnt1--;
                    if(cnt1>0) pq.push({cnt1,char1});
                }
            }
            return ans;
        }
    };