/*

Majority element 2
You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

Note: The answer should be returned in an increasing format.

Examples:

Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output: [5, 6]
Explanation: 5 and 6 occur more n/3 times.
Input: arr[] = [1, 2, 3, 4, 5]
Output: []
Explanation: The total number of votes are 5. No candidate occur more than floor (5/3) times. 
Constraint:
1 <= arr.size() <= 106
1 <= arr[i] <= 105*/



class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> count;
    for (int num : arr) {
        count[num]++;
    }
    vector<int> result;
    for (auto& entry : count) {
        if (entry.second > n / 3) {
            result.push_back(entry.first);
        }
    }
    sort(result.begin(), result.end());
    return result;
}
    
};
