#include <stdlib.h>

void insert_sorted(int* array, int value, int size) {
    int *array = realloc(array, ++size);

}

void insert_pos(int* array, int pos, int value, int size) {
    int *array = realloc(array, ++size);
    for(int i = size-1; i >= pos; i--) {
        array[i] = array[i-1];
    }
    array[pos] = value;
}

