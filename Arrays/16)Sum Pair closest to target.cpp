Sum Pair closest to target
Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a<=b whose sum is closest to target.
Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.

Examples:
Input: arr[] = [10, 30, 20, 5], target = 25
Output: [5, 20]
Explanation: As 5 + 20 = 25 is closest to 25.

Input: arr[] = [5, 2, 7, 1, 4], target = 10
Output: [2, 7]
Explanation: As (4, 7) and (2, 7) both are closest to 10, but absolute difference of (2, 7) is 5 and (4, 7) is 3. Hence, [2, 7] has maximum absolute difference and closest to target. 

Input: arr[] = [10], target = 10
Output: []
Explanation: As the input array has only 1 element, return an empty array.

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here 
    int n = arr.size();
    if (n < 2) return {}; // If there are fewer than 2 elements, return an empty vector

    // Sort the array
    sort(arr.begin(), arr.end());

    int closestSum = INT_MAX;
    vector<int> closestPair;
    int left = 0;
    int right = n - 1;

    while (left < right) { // Change to right, since a pair cannot be made with the same index
        int sum = arr[left] + arr[right];

        // Check if this sum is closer to the target than the previous closest sum
        if (abs(sum - target) < abs(closestSum - target) || 
            (abs(sum - target) == abs(closestSum - target) && abs(arr[left] - arr[right]) > abs(closestPair[0] - closestPair[1]))) {
            
            closestSum = sum;
            closestPair = {arr[left], arr[right]};
        }

        // Move the pointers accordingly
        if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    // Ensure the pair is sorted before returning
    sort(closestPair.begin(), closestPair.end());
    return closestPair;
    }
};