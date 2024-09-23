#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "customWarning/customWarning.h"
#include "sort.h"

void mySort(const void *array, const size_t arrayLength, const size_t size, compareFunc *comparator) {  
    customWarning(array      != NULL, (void) 1);
    customWarning(comparator != NULL, (void) 1);

    const char *arrayData = (const char *)array;
    
    for (size_t firstIndex = 0; firstIndex < arrayLength; firstIndex++) {
        for (size_t bubbleIndex = 0; bubbleIndex < arrayLength - firstIndex - 1; bubbleIndex++) {
            if (comparator(arrayData + size * bubbleIndex, arrayData + size * (bubbleIndex + 1)) > 0) {
                mySwap(arrayData + size * bubbleIndex, arrayData + size * (bubbleIndex + 1), size);
            }
        }
    }
}

void mySwap(const void *firstElem, const void *secondElem, const size_t size) {
    customWarning(firstElem  != NULL, (void) 1);
    customWarning(secondElem != NULL, (void) 1);

    char *firstChar  = (char *)firstElem;
    char *secondChar = (char *)secondElem;

    for (size_t index = 0; index < size; index++) {
        char temp         = firstChar[index];
        firstChar[index]  = secondChar[index];
        secondChar[index] = temp;
    }
}

void quickSort(const void *array, const size_t size, const size_t start, const size_t end,
               const compareFunc *comparator) {
    customWarning(array != NULL, (void) 1);

    if (start < end) {
        size_t left   = start;
        size_t right  = end;

        size_t middle = (left + right) / 2;

        const char *charArray = (char *)array;

        while (left <= right) {
            while(comparator(charArray + left * size, charArray + middle * size) < 0) {
                left++;
            }
            
            while (comparator(charArray + right * size, charArray+ middle * size) > 0) {
                right--;
            }

            if (left <= right) {
                mySwap(charArray + left * size, charArray + right * size, size);
                left++;
                right--;
            }
        }
        quickSort(charArray, size, start, right, comparator);
        quickSort(charArray, size, left,  end,   comparator);
    }
}