#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == x) {
            return mid;
        }
        
        if (arr[mid] < x) {
            low = mid + 1;
        }
        
        else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int main()
{
    int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    
    int size = sizeof(arr) / sizeof(arr[0]);

    int x = 70;
    int found_value = binary_search(arr, 0, size - 1, x);
    
    if (found_value != -1) printf("Valor %d encontrado na posicao %d!", x, found_value);
    else printf("Valor nao encontrado!");

    return 0;
}