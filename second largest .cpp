/*
second largest 

Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.
Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.
Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105*/



// User function template for C++
// User function template for C++
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    // Function returns the second largest element
    int getSecondLargest(vector<int>& arr) {
        int n = arr.size(); // Get the size of the vector
        if (n < 2) {
            return -1; // Not enough elements for a second largest
        }

        int max = INT_MIN, smax = INT_MIN;

        // Find the largest element
        for (int i = 0; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        // Find the second largest element
        for (int i = 0; i < n; i++) {
            if (arr[i] != max && arr[i] > smax) {
                smax = arr[i];
            }
        }

        return (smax == INT_MIN) ? -1 : smax; // Return -1 if there's no second largest
    }
};
