Letter Tile Possibilities
You have n  tiles, where each tile has one letter tiles[i] printed on it.
Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

Example 1:
Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

Example 2:
Input: tiles = "AAABBC"
Output: 188
Example 3:

Input: tiles = "V"
Output: 1

class Solution {
    public:
    void func(int index,vector<int>&vis,set<string>&set,string tiles,string res){
        int n=tiles.size();
        set.insert(res);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                func(index+1,vis,set,tiles,res+tiles[i]);
                vis[i]=0;
            }
        }
    }
        int numTilePossibilities(string tiles) {
            int n=tiles.size();
            vector<int>vis(n,0);
            set<string>set;
            string res;
            func(0,vis,set,tiles,res);
            return set.size()-1;
        }
    };