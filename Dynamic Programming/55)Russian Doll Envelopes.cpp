Russian Doll Envelopes
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
Note: You cannot rotate an envelope.

Example 1:
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1

class Solution {
    public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }
        int maxEnvelopes(vector<vector<int>>& envelopes) {
            sort(envelopes.begin(),envelopes.end(),comp);
            vector<int>v;
            for(auto i : envelopes){
                v.push_back(i[1]);
            }
            vector<int>temp;
            temp.push_back(v[0]);
            for(int i=0;i<v.size();i++){
                if(v[i]>temp.back()){
                    temp.push_back(v[i]);
                }
                else{
                    auto ind=lower_bound(temp.begin(),temp.end(),v[i]);
                    *ind=v[i];
                }
            }
            return temp.size();
        }
    };