Construct the Lexicographically Largest Valid Sequence
Given an integer n, find a sequence that satisfies all of the following:
The integer 1 occurs once in the sequence.
Each integer between 2 and n occurs twice in the sequence.
For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.
Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.
A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

Example 1:
Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.

Example 2:
Input: n = 5
Output: [5,3,1,4,3,5,2,4,2]

class Solution 
{
public:
    vector<int> constructDistancedSequence(int n) 
    {
        // Step 1: Initialize structures
        vector<int> result(2 * n - 1, -1); // Final sequence array
        vector<bool> used(n + 1, false); // To track used numbers

        // Step 2: Start the recursive backtracking function
        solve(0, n, result, used);

        return result;
    }

private:
    bool solve(int i, int n, vector<int>& result, vector<bool>& used) 
    {
        // Step 3: If we've reached the end, return true
        if (i >= result.size())
        {
            return true;
        } 

        // Step 4: If the position is occupied, move to the next index
        if (result[i] != -1)
        {
            return solve(i + 1, n, result, used);
        } 

        // Step 5: Try placing numbers from `n` to `1`
        for (int num = n; num >= 1; num--)
        {
            if (used[num])
            {
                continue; // Skip if already used
            } 

            // Step 6: Mark the number as used and place it
            used[num] = true;
            result[i] = num;

            if (num == 1 || (i + num < result.size() && result[i + num] == -1))
            {
                if (num > 1)
                {
                    result[i + num] = num;
                } 

                // Step 7: Continue solving recursively
                if (solve(i + 1, n, result, used))
                {
                    return true;
                } 

                // Step 8: Backtrack if solution is not found
                if (num > 1)
                {
                    result[i + num] = -1;
                } 
            }

            // Step 9: Backtrack and try another number
            used[num] = false;
            result[i] = -1;
        }
        return false;
    }
};