Intersection of Two arrays with Duplicate Elements
Given two integer arrays a[] and b[], you have to find the intersection of the two arrays. 
Intersection of two arrays is said to be elements that are common in both arrays. 
The intersection should not have duplicate elements and the result should contain items in any order.

Examples:
Input: a[] = [1, 2, 1, 3, 1], b[] = [3, 1, 3, 4, 1]
Output: [1, 3]
Explanation: 1 and 3 are the only common elements and we need to print only one occurrence of common elements.
Input: a[] = [1, 1, 1], b[] = [1, 1, 1, 1, 1]
Output: [1]
Explanation: 1 is the only common element present in both the arrays.

class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
unordered_set<int> setA(a.begin(), a.end());//Insert all unique elements from a
unordered_set<int> intersection;//To hold the intersection

    // Iterate through array b and check for common elements
    for (int num : b) {
        if (setA.find(num) != setA.end()) {
            intersection.insert(num); // Add to intersection set if found in setA
        }
    }

    // Convert the unordered_set to a vector
    vector<int> ans(intersection.begin(), intersection.end());

    // Sort the resulting vector
    sort(ans.begin(), ans.end());

    return ans;
    }
};