# include <stdio.h>
# include <stdlib.h>

// Function to sort an array using bubble sort
void sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++){ // Outer loop for passes
        for(int j = 0; j < n - i; j++){ // Inner loop for comparisons
            if(arr[j] > arr[j + 1]){ // Swap if the current element is greater than the next
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the mean of an array
float findMean(int arr[], int n){
    float sum = 0;
    for(int i = 0; i < n; i++){ // Sum all elements in the array
        sum += arr[i];
    }
    return sum / n; // Return the average
}

// Comparison function for qsort
int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b); // Return the difference between two integers
}

// Function to calculate the median of an array
float findMedian(int arr[], int n){
    qsort(arr, n, sizeof(int), compare); // Sort the array using qsort
    // If the size is even, return the average of the two middle elements
    // Otherwise, return the middle element
    return (n % 2 == 0) ? (arr[n / 2 - 1] + arr[n / 2]) / 2.0 : arr[n / 2];
}

// Function to calculate the mode of an array
int findMode(int arr[], int n){
    int maxCount = 0, mode = arr[0]; // Initialize mode and maxCount
    for(int i = 0; i < n; i++){ // Iterate through the array
        int count = 0;
        for(int j = 0; j < n; j++){ // Count occurrences of arr[i]
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > maxCount){ // Update mode if a higher frequency is found
            maxCount = count;
            mode = arr[i];
        }
    }
    return mode; // Return the mode
}

int main(){
    int n;
    scanf("%d", &n); // Read the size of the array
    int arr[n];

    for(int i = 0; i < n; i++){ // Read the elements of the array
        scanf("%d", &arr[i]);
    }

    // Print the mean of the array
    printf("%.2f\n", findMean(arr, n));
    // Print the median of the array
    printf("%.2f\n", findMedian(arr, n));
    // Print the mode of the array
    printf("%d\n", findMode(arr, n));

    return 0; // Exit the program
}
