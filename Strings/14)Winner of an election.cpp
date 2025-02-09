Winner of an election
Given a lowercase string array arr[]. Each element in the array represents a vote cast for a candidate. Return the name of the candidate who received the maximum number of votes and the count of votes he received. In case of a tie between two or more candidates, return the lexicographically smallest name.
Note: Return an array of strings, the winning candidate name as the first element and the vote count as the second element (typecast the count to string).

Examples :
Input: arr[] = ["john", "johnny", "jackie", "johnny", "john", "jackie", "jamie", "jamie", "john", "johnny", "jamie", "johnny", "john"]
Output: ["john", "4"]
Explanation: "john" has 4 votes casted for him, but so does "johnny". "john" is lexicographically smaller, so we print "john" and the votes he received.

Input: n = 3
arr[] = ["andy", "blake", "clark"]
Output: ["Andy", "1"]
Explanation: All the candidates get 1 votes each. We print "andy" as it is lexicographically smaller.

class Solution {
    public:
      // Function to return the name of candidate that received maximum votes.
      vector<string> winner(vector<string> &arr) {
          // code here
          int n=arr.size();
          vector<string>ans;
          unordered_map<string,int>mpp;
          for(auto it : arr){
              mpp[it]++;
          }
          string res = "";
          int temp =0;
          for(auto it : mpp){
  // If current candidate has more votes, or if it has the same votes but is 
  //lexicographically smaller
  if (it.second > temp || (it.second == temp && (res.empty() || it.first < res))){
                  temp = it.second;
                  res = it.first;
              }
          }
          ans.push_back(res);
          ans.push_back(to_string(temp));
          return ans;
      }
  };