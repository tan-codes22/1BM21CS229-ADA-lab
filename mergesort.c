#include <stdio.h>
int n;
// Function to merge two subarrays
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    int Left[n1], Right[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        Left[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        Right[j] = arr[middle + 1 + j];

    // Merge the temporary arrays back into arr[]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        } else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of Left[], if there are any
    while (i < n1) {
        arr[k] = Left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of Right[], if there are any
    while (j < n2) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i <n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test the merge sort function
int main() {
    int arr[20],i;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    

    printf("Given array: \n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nSorted array: \n");
    printArray(arr, n);

    return 0;
}
