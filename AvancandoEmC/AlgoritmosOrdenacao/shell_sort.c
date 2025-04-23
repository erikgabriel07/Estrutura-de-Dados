#include <stdio.h>
#include <stdlib.h>

void shell_sort(int *vet, int size) {
    int h = 1;
    while (h < size)
        h = (3 * h) + 1;
    
    while (h > 0) {
        for (int i = h; i < size; i++) {
            int key = vet[i];
            int j = i;
            
            while (j >= h && vet[j - h] > key) {
                vet[j] = vet[j - h];
                j -= h;
            }
            
            vet[j] = key;
        }
        
        h /= 3;
    }
}

int main()
{
    int vet[] = { 4, 12, 5, 6, 19, 20, 3, 7, 1 };
    
    int size = sizeof(vet) / sizeof(vet[0]);
    
    shell_sort(vet, size);
    
    printf("Ordenado: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}
