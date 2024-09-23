#ifndef SORT_H_
#define SORT_H_

typedef int (compareFunc)(const void *, const void *);

// FUNCTION PROTOTYPES //
/**
 * @brief Universal Sorting Of Different Data Types
 * 
 * @param array Pointer To Data Array
 * @param arrayLength Size Of Data Array
 * @param size Size Of Data Array Elements
 * @param comparator Pointer To Comparing Function
 */
void mySort(const void *array, size_t arrayLength, size_t size,
            compareFunc comparator);
            
/**
 * @brief Universal Swapping Of Different Data Types
 * 
 * @param firstElem Pointer To First Element To Swap
 * @param secondElem Pointer To Second Element To Swap
 * @param size Size Of Element
 */
void mySwap(const void *firstElem, const void *secondElem, size_t size);
// FUNCTION PROTOTYPES //

void quickSort(const void *array, const size_t size, const size_t start, const size_t end,
               const compareFunc *comparator);

#endif // SORT_H_