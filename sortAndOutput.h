#ifndef SORT_AND_OUTPUT_H_
#define SORT_AND_OUTPUT_H_

#include "textStruct.h"

typedef int (comparator)(const void *, const void *);

// FUNCTION PROTOTYPES //
/**
 * @brief Sorting And Saving Sorted Text Into Output File
 * 
 * @param fileName Output File Name
 * @param textData Pointer To TextData Struct (See Struct Description)
 * @param textLine Array Of Pointers To TextLine Structs
 * @param comparator Pointer To Comparing Function
 * @return [int] Return Code (Success / Error)
 */
int sortAndOutput(const char *fileName, textData *textData, textLine *textLine, comparator *comparator);
// FUNCTION PROTOTYPES //

#endif // SORT_AND_OUTPUT_H_