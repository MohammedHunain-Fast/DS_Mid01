int rows = 3, cols = 4;

// Allocation:
int** matrix = new int*[rows]; // Allocate array of row pointers
for (int i = 0; i < rows; i++) {
    matrix[i] = new int[cols]; // Allocate each row
}

// Deallocation (Must be done in REVERSE order):
for (int i = 0; i < rows; i++) {
    delete[] matrix[i]; // Free each row array
}
delete[] matrix;        // Free pointer array
matrix = nullptr;
