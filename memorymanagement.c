#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr1, *arr2, *arr3;
    
    printf("=== MEMORY MANAGEMENT ===\n");
    
    // 1. USER INPUT FOR ARRAY SIZE
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    // 2. MALLOC - Raw memory allocation (uninitialized)
    printf("\n1. MALLOC Example:\n");
    arr1 = (int*)malloc(n * sizeof(int));
    if (arr1 == NULL) {
        printf("Malloc failed - Out of memory!\n");
        exit(1);
    }
    
    printf("malloc(%d): %p (%d bytes)\n", n, (void*)arr1, n * sizeof(int));
    for(i = 0; i < n; i++) {
        arr1[i] = i * 10;
    }
    
    // 3. CALLOC - Zero-initialized memory
    printf("\n2. CALLOC Example:\n");
    arr2 = (int*)calloc(n, sizeof(int));  // All zeros initially
    if (arr2 == NULL) {
        printf("Calloc failed!\n");
        exit(1);
    }
    
    printf("calloc(%d): %p (%d bytes) - All zeros\n", n, (void*)arr2, n * sizeof(int));
    
    // 4. REALLOC - Resize existing allocation
    printf("\n3. REALLOC Example:\n");
    int new_size;
    printf("Enter new size: ");
    scanf("%d", &new_size);
    
    arr2 = (int*)realloc(arr2, new_size * sizeof(int));
    if (arr2 == NULL) {
        printf("Realloc failed!\n");
        exit(1);
    }
    
    printf("realloc(%d): %p (%d bytes)\n", new_size, (void*)arr2, new_size * sizeof(int));
    
    // Fill new elements
    for(i = n; i < new_size; i++) {
        arr2[i] = i * 100;
    }
    
    // 5. DISPLAY ALLOCATED MEMORY
    printf("\n=== ARRAY CONTENTS ===\n");
    printf("Array 1 (malloc): ");
    for(i = 0; i < n; i++) printf("%d ", arr1[i]);
    printf("\nArray 2 (calloc+realloc): ");
    for(i = 0; i < new_size; i++) printf("%d ", arr2[i]);
    printf("\n");
    
    // 6. MEMORY LEAK PREVENTION - FREE ALL ALLOCATIONS
    printf("\n4. MEMORY DEALLOCATION:\n");
    free(arr1);
    printf("arr1 freed: %p\n", (void*)arr1);
    arr1 = NULL;  // Prevent dangling pointer
    
    free(arr2);
    printf("arr2 freed: %p\n", (void*)arr2);
    arr2 = NULL;
    
    // 7. DYNAMIC 2D ARRAY (Matrix)
    printf("\n5. DYNAMIC 2D ARRAY:\n");
    int rows = 3, cols = 4;
    int **matrix = (int**)malloc(rows * sizeof(int*));
    
    for(i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    
    // Initialize matrix
    for(i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
        }
    }
    
    // Print matrix
    printf("3x4 Matrix:\n");
    for(i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Free 2D array properly
    for(i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    printf("Matrix freed successfully\n");
    
    printf("\n=== Memory Management Complete ===\n");
    printf("All pointers set to NULL to prevent dangling references\n");
    
    return 0;
}
