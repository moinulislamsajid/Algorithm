#include <bits/stdc++.h>
using namespace std;

pair<int, int> maxWaterContainer(vector<int>& heights) {
    int left = 0, right = heights.size() - 1;
    int maxWater = 0;
    pair<int, int> result = {0, 0};  // Stores the indices of the two lines

    while (left < right) {
        // Calculate the current water held by the container
        int minHeight = min(heights[left], heights[right]);
        int width = right - left;
        int currentWater = minHeight * width;

        // Update the maximum water and indices if needed
        if (currentWater > maxWater) {
            maxWater = currentWater;
            result = {left, right};  // Save the current left and right indices
        }

        // Move the pointer corresponding to the smaller height
        if (heights[left] < heights[right]) {
            left++;
        } else {
            right--;
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n;
        cin >> n;  // Number of elements in the array
        vector<int> heights(n);

        // Input array of heights
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        // Get the result pair of indices
        pair<int, int> result = maxWaterContainer(heights);

        // Print left index first, then right index
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}
