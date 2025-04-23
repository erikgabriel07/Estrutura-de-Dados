#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *vet, int size) {
    for (int i = 0; i < size; i++) {
        int key = vet[i];
        int j = i - 1;
        
        while (j >= 0 && vet[j] > key) {
            vet[j + 1] = vet[j];
            j--;
        }
        
        vet[j + 1] = key;
    }
}

int main()
{
    int vet[] = { 4, 12, 5, 6, 19, 20, 3, 7, 1 };
    
    int size = sizeof(vet) / sizeof(vet[0]);
    
    insertion_sort(vet, size);
    
    printf("Ordenado: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}
