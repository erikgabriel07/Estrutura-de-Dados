#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *vet, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                int temp = vet[j + 1];
                vet[j + 1] = vet[j];
                vet[j] = temp;
            }
        }
    }
}

int main()
{
    int vet[] = { 4, 12, 5, 6, 19, 20, 3, 7, 1 };
    
    int size = sizeof(vet) / sizeof(vet[0]);
    
    bubble_sort(vet, size);
    
    printf("Ordenado: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}
