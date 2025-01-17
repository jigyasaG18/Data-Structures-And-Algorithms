Word Ladder-II
Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
Keep the following conditions in mind:
A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
Return an empty list if there is no such transformation sequence.
The first part of this problem can be found here.

Example 1:
Input:
startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}
Output:
der dfr dfs
der des dfs
Explanation:
The length of the smallest transformation is 3.
And the following are the only two ways to get
to targetWord:-
"der" -> "des" -> "dfs".
"der" -> "dfr" -> "dfs".

Example 2:
Input:
startWord = "gedk", targetWord = "geek", 
wordList = {"geek", "gefk"}
Output:
"gedk" -> "geek"

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        q.push({beginWord});
        vector<string>usedonlevel;
        usedonlevel.push_back(beginWord);
        int level=0;
        vector<vector<string>>ans;
        while(!q.empty()){
            vector<string>vec=q.front();
            q.pop();
            
            if(vec.size()>level){
                level++;
                
                for(auto it : usedonlevel){
                    st.erase(it);
                }
                usedonlevel.clear();
            }
            string word=vec.back();
            if(word==endWord){
                if(ans.size()==0) ans.push_back(vec);
                else if(ans[0].size()==vec.size()) ans.push_back(vec);
            }

            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    
            if(st.count(word)>0){
                vec.push_back(word);
                q.push(vec);
                usedonlevel.push_back(word);
                vec.pop_back();
            }
                }
                word[i]=original;
            }
        }
        return ans;
    }
};