Implement Pow
Implement the function power(b, e), which calculates b raised to the power of e (i.e. be).

Examples:
Input: b = 3.00000, e = 5
Output: 243.00000

Input: b = 0.55000, e = 3
Output: 0.16638

Input: b = -0.67000, e = -7
Output: -16.49971

// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code here
        return pow(b,e);
    }
};