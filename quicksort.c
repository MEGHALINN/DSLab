#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;
    int temp;

    while (1) {
        while (left <= right && arr[left] <= pivot)
            left++;
        while (left <= right && arr[right] > pivot)
            right--;
        if (left > right)
            break;
        else {
            temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }
    arr[low] = arr[right];
    arr[right] = pivot;
    return right;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    quicksort(arr, 0, n - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
