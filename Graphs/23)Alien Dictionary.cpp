Alien Dictionary
Given a sorted dictionary of an alien language having some words dict and k starting alphabets of a standard dictionary. Find the order of characters in the alien language. If no valid ordering of letters is possible, then return an empty string.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be "true" if the order of string returned by the function is correct else "false" denotes incorrect string returned.

Examples:
Input: dict[] = ["baa","abcd","abca","cab","cad"], k = 4
Output: true
Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Input: dict[] = ["caa","aaa","aab"], k = 3
Output: true
Explanation: Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before "aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.

Input: dict[] = ["dhhid","dahi","cedg","fg","gdah","i","gbdei","hbgf","e","ddde"], k = 9 
Output: false

class Solution {
private:
vector<int> toposort(int V, vector<int> adj[]){
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int>topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        
        for(auto it : adj[node]){
            indegree[it]--;
            
            if(indegree[it]==0) q.push(it);
        }
    }
    return topo;
}
  public:
    string findOrder(vector<string> dict, int k) {
        // code here
        int n=dict.size();
        vector<int>adj[k];
        for(int i=0;i<n-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.size(),s2.size());
            
            for(int ptr=0;ptr<len;ptr++){
                if(s1[ptr]!=s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }
        vector<int>ans=toposort(k,adj);
        string ans1="";
        for(auto it : ans){
            ans1=ans1+char(it+'a');
        }
        return ans1;
    }
};