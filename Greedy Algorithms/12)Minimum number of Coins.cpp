Minimum Number of Coins
Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
Find the minimum number of coins and/or notes needed to make the change for Rs N. You must return the list containing the value of coins required. 

Example 1:
Input: N = 43
Output: 20 20 2 1
Explaination: Minimum number of coins and notes needed to make 43. 

Example 2:
Input: N = 1000
Output: 500 500
Explaination: Minimum possible notes is 2 notes of 500.

class Solution{
    public:
        vector<int> minPartition(int N)
        {
            // code here
            vector<int>denominations={1,2,5,10,20,50,100,200,500,2000};
            int j=denominations.size()-1;//largest denomination
            vector<int>ans;
            while(N>0){
                while(denominations[j]>N) j--; //if denomination is greater than given amt
                N -= denominations[j]; //else reduce the denomination value from total amt
                ans.push_back(denominations[j]);
            }
            return ans;
        }
    };