Perfect Number
Given a number N. Check if it is perfect or not. A number is perfect if sum of factorial of its digit is equal to the given number.

Example 1:
Input: N = 23
Output: 0
Explanation: The sum of factorials of digits of 23 is 2! + 3! = 2 + 6 = 8 which is not equal to 23. Thus, answer is 0.

Example 2:
Input: N = 145
Output: 1
Explanation: The sum of factorials of digits of 145 is 1! + 4! + 5! = 1 + 24 + 120 = 145 which is equal to 145.Thus, answer is 1.

class Solution {
  public:
  int fact(int n){
      if(n==1 || n==0) return 1;
      else return n*fact(n-1);
  }
    int isPerfect(int N) {
        // code here
        int sum = 0;
        int temp = N;
        while(temp > 0){
            int digit = temp % 10;
            sum += fact(digit);
            temp /= 10;
        }
        return (sum == N) ? 1 : 0;
    }
};