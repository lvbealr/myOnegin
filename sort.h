#ifndef SORT_H_
#define SORT_H_

// FUNCTION PROTOTYPES //
void mySort(void *array, size_t arrayLength, size_t size,
            int (*comparator)(const void *firstElem, const void *secondElem));
void mySwap(void *firstElem, void *secondElem, size_t size);
// FUNCTION PROTOTYPES //

#endif // SORT_H_