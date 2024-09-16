#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "customWarning/customWarning.h"
#include "customStrcmp.h"
#include "textStruct.h"
#include "sort.h"

void mySort(void *array, size_t arrayLength, size_t size, int (*comparator)(const void *first, const void *second)) {  
    customWarning(array      != NULL, (void) 1);
    customWarning(comparator != NULL, (void) 1);

    char *arrayData = (char *)array;
    for (size_t firstIndex = 0; firstIndex < arrayLength; firstIndex++) {
        for (size_t bubbleIndex = 0; bubbleIndex < arrayLength - firstIndex - 1; bubbleIndex++) {
            if (comparator(arrayData + size * bubbleIndex, arrayData + size * (bubbleIndex + 1)) > 0) {
                mySwap(arrayData + size * bubbleIndex, arrayData + size * (bubbleIndex + 1), size);
            }
        }
    }
}

void mySwap(void *firstElem, void *secondElem, size_t size) {
    customWarning(firstElem  != NULL, (void) 1);
    customWarning(secondElem != NULL, (void) 1);

    char *firstChar  = (char *)firstElem;
    char *secondChar = (char *)secondElem;

    char temp = 0;

    for (size_t index = 0; index < size; index++) {
        temp = firstChar[index];
        firstChar[index] = secondChar[index];
        secondChar[index] = temp;
    }
}
