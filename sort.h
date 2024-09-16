#ifndef SORT_H_
#define SORT_H_

// FUNCTION PROTOTYPES //
/**
 * @brief Universal Sorting Of Different Data Types
 * 
 * @param array Pointer To Data Array
 * @param arrayLength Size Of Data Array
 * @param size Size Of Data Array Elements
 * @param comparator Pointer To Comparing Function
 */
void mySort(void *array, size_t arrayLength, size_t size,
            int (*comparator)(const void *firstElem, const void *secondElem));
            
/**
 * @brief Universal Swapping Of Different Data Types
 * 
 * @param firstElem Pointer To First Element To Swap
 * @param secondElem Pointer To Second Element To Swap
 * @param size Size Of Element
 */
void mySwap(void *firstElem, void *secondElem, size_t size);
// FUNCTION PROTOTYPES //

#endif // SORT_H_