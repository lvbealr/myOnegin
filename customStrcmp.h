#ifndef CUSTOM_STRCMP_H_
#define CUSTOM_STRCMP_H_

// FUNCTION PROROTYPES //
/**
 * @brief Forward String Comparing (Alphabetical Order From Left To Right)
 * 
 * @param firstElem Pointer To First String To Compare
 * @param secondElem Pointer To Second String To Compare
 * @return [int] Return Code (Success / Error)
 */
int customStrcmp(const void *firstElem, const void *secondElem);

/**
 * @brief Backward String Comparing (Alphabetical Order From Right To Left)
 * 
 * @param firstElem Pointer To First String To Compare
 * @param secondElem Pointer To Second String To Compare
 * @return [int] Return Code (Success / Error)
 */
int customReverseStrcmp(const void *firstElem, const void *secondElem);
// FUNCTION PROTOTYPES //

#endif // CUSTOM_STRCMP_H_