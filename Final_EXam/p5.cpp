#include <iostream>
#include <vector>
#include <utility> // For std::pair
#include <algorithm> // For std::min

using namespace std;

// Function to find the maximum water container
pair<int, int> maxWaterContainer(const vector<int>& heights) {
    int left = 0; // Start pointer
    int right = heights.size() - 1; // End pointer
    int maxArea = 0; // Variable to keep track of the maximum area
    pair<int, int> result = {0, 0}; // To store the indices of the best pair

    while (left < right) {
        // Calculate the area between the two lines
        int height = min(heights[left], heights[right]);
        int width = right - left;
        int area = height * width;

        // Update max area and the result if we found a larger area
        if (area > maxArea) {
            maxArea = area;
            result = {left, right}; // Store the indices of the lines
        }

        // Move the pointer pointing to the shorter line
        if (heights[left] < heights[right]) {
            left++; // Move left pointer to the right
        } else {
            right--; // Move right pointer to the left
        }
    }

    return result; // Return the best pair of indices
}

int main() {
    int t; // Number of test cases
    cin >> t; // Read number of test cases
    while (t--) {
        int n; // Size of the array
        cin >> n; // Read the number of lines (array size)
        vector<int> heights(n); // Vector to store heights

        for (int i = 0; i < n; ++i) {
            cin >> heights[i]; // Read heights of the lines
        }

        // Get the indices of the lines that can hold the most water
        pair<int, int> indices = maxWaterContainer(heights);
        cout << indices.first << " " << indices.second << endl; // Output the indices
    }
    return 0; // End of the program
}
