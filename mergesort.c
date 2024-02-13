#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int lb, int mid, int ub) {
    int temp[ub - lb + 1];
    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j]) {
            temp[k - lb] = arr[i];
            i++;
        } else {
            temp[k - lb] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k - lb] = arr[i];
        i++;
        k++;
    }

    while (j <= ub) {
        temp[k - lb] = arr[j];
        j++;
        k++;
    }

    for (int x = lb; x <= ub; x++) {
        arr[x] = temp[x - lb];
    }
}

void mergeSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);

    return 0;
}
