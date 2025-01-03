#include <iostream>
#include <vector>

using namespace std;

// Function to smooth a 2D matrix using a 3x3 kernel
void smoothMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Create a temporary matrix to store the smoothed values
    vector<vector<int>> smoothedMatrix(rows, vector<int>(cols, 0));

    // Define the smoothing kernel (3x3 matrix)
    vector<vector<int>> kernel = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    // Iterate through each element of the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int sum = 0;
            int count = 0;

            // Apply the kernel to each element
            for (int k = -1; k <= 1; ++k) {
                for (int l = -1; l <= 1; ++l) {
                    int x = i + k;
                    int y = j + l;

                    // Check if the neighboring element is within bounds
                    if (x >= 0 && x < rows && y >= 0 && y < cols) {
                        sum += matrix[x][y] * kernel[k + 1][l + 1];
                        count++;
                    }
                }
            }

            // Calculate the average value
            smoothedMatrix[i][j] = sum / count;
        }
    }

    // Update the original matrix with the smoothed values
    matrix = smoothedMatrix;
}

int main() {
    // Matrix
    vector<vector<int>> matrix = {
    	 {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
       
    };

    // Smooth the matrix
    smoothMatrix(matrix);

    // Print the smoothed matrix
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}