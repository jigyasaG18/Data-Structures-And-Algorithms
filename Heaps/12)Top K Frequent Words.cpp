Top K Frequent Words
Given an array of strings words and an integer k, return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Example 1:
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.

class Solution {
    public:
        vector<string> topKFrequent(vector<string>& words, int k) {
            unordered_map<string,int>mpp;
            for(auto it : words) mpp[it]++;
            vector<pair<int,string>>temp;
            for(auto it : mpp) temp.push_back({it.second,it.first});
    
            auto comp=[&](pair<int,string>&p1, pair<int,string>&p2){
                if(p1.first==p2.first) return p1.second<p2.second;
                return p1.first>p2.first;
            };
    
            sort(temp.begin(),temp.end(),comp);
    
            int i=0;
            vector<string>ans;
            while(i<k){
            ans.push_back(temp[i].second);
            i++;
            }
            return ans;
        }
    };