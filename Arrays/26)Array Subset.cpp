Array Subset
Given two arrays a[] and b[] of size m and n respectively, the task is to determine whether b[] is a subset of a[]. Both arrays are not sorted, and elements are distinct.

Examples:
Input: a[] = [11, 7, 1, 13, 21, 3, 7, 3], b[] = [11, 3, 7, 1, 7]
Output: true
Explanation: b[] is a subset of a[]

Input: a[] = [1, 2, 3, 4, 4, 5, 6], b[] = [1, 2, 4]
Output: true
Explanation: b[] is a subset of a[]

Input: a[] = [10, 5, 2, 23, 19], b[] = [19, 5, 3]
Output: false
Explanation: b[] is not a subset of a[]

1st Way:-
class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        unordered_map<int,int>mpp;
        for(int i : a){
            mpp[i]++;
        }
        for(int j : b){
            if(mpp.find(j)==mpp.end()) return false;
        }
        return true;
    }
};

2nd Way:-
class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        unordered_set<int>st(a.begin(),a.end());
        for(auto ele1 : b)
        {
            if(st.find(ele1) == st.end()){
                return false;
            }
        }
        return true;
        
    }
};