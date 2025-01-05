Count Pairs whose sum is less than target
Given an array arr[] and an integer target. You have to find the number of pairs in the array whose sum is strictly less than the target.

Examples:
Input: arr[] = [7, 2, 5, 3], target = 8
Output: 2
Explanation: There are 2 pairs with sum less than 8: (2, 5) and (2, 3). 

Input: arr[] = [5, 2, 3, 2, 4, 1], target = 5
Output: 4
Explanation: There are 4 pairs whose sum is less than 5: (2, 2), (2, 1), (3, 1) and (2, 1).

Input: arr[] = [2, 1, 8, 3, 4, 7, 6, 5], target = 7
Output: 6
Explanation: There are 6 pairs whose sum is less than 7: (2, 1), (2, 3), (2, 4), (1, 3), (1, 4) and (1, 5).

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
          int n = arr.size();
        sort(arr.begin(), arr.end());
        int i = 0;
        int j = n-1;
        int cnt = 0;
        
        while(i < j){
            int sum = arr[i] + arr[j];
            if(sum >= target) j--;
            else{
                cnt += (j-i);
                i++;
            }
        }
        
        return cnt;
    }
//DRY RUN:-
//Step 1: Sort the Array
//The first step in the function is to sort the array. After sorting, the array `arr` will be:
//arr[] = [2, 3, 5, 7]
//Step 2: Initialization
//We then initialize:
//- `n = arr.size()` → `n = 4`
//- `i = 0` (points to the start of the array)
//- `j = n-1` → `j = 3` (points to the end of the array)
//- `cnt = 0` (to count the valid pairs)
//Step 3: First Iteration (i = 0, j = 3)
//- Calculate `sum = arr[i] + arr[j]` → `sum = arr[0] + arr[3]` → `sum = 2 + 7 = 9`
//- Check if `sum >= target`. Here, `9 >= 8` is true, so we decrement `j`:
//j-- → j = 2
//Step 4: Second Iteration (i = 0, j = 2)
//- Calculate `sum = arr[i] + arr[j]` → `sum = arr[0] + arr[2]` → `sum = 2 + 5 = 7`
//- Check if `sum >= target`. Here, `7 >= 8` is false, so we calculate the number of pairs:
//cnt += (j - i) → cnt += (2 - 0) → cnt += 2 → cnt = 2
//Now, we increment `i`: i++ → i = 1
//Step 5: Third Iteration (i = 1, j = 2)
//- Calculate `sum = arr[i] + arr[j]` → `sum = arr[1] + arr[2]` → `sum = 3 + 5 = 8`
//- Check if `sum >= target`. Here, `8 >= 8` is true, so we decrement `j`:
//j-- → j = 1
//Step 6: Fourth Iteration (i = 1, j = 1)
//Now, `i` is equal to `j` (`i = 1` and `j = 1`), which means we have exhausted all possible pairs. The while loop terminates.
//Final Output
//The final count of pairs with sums strictly less than the target is: cnt = 2
//The valid pairs are `(2, 5)` and `(2, 3)`.
};