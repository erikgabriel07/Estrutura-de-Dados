#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *vet, int low, int high) {
    int p = vet[low];
    int i = low;
    int j = high;
    
    while (i < j) {
        while (vet[i] <= p && i <= high - 1) {
            i++;
        }
        
        while(vet[j] > p && j >= low + 1) {
            j--;
        }
        
        if (i < j) {
            swap(&vet[i], &vet[j]);
        }
    }
    swap(&vet[low], &vet[j]);
    return j;
}

void quick_sort(int *vet, int low, int high) {
    if (low < high) {
        int pi = partition(vet, low, high);
        
        quick_sort(vet, low, pi - 1);
        quick_sort(vet, pi + 1, high);
    }
}

int main()
{
    int vet[] = { 4, 12, 5, 6, 19, 20, 3, 7, 1 };
    
    int size = sizeof(vet) / sizeof(vet[0]);
    
    quick_sort(vet, 0, size - 1);
    
    printf("Ordenado: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}
