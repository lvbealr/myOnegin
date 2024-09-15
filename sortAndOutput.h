#ifndef SORT_AND_OUTPUT_H_
#define SORT_AND_OUTPUT_H_

#include "textStruct.h"

// FUNCTION PROTOTYPES //
int sortAndOutput(const char *fileName, textData *textData, textLine *textLine,
                  int (*comparator)(const void *firstElem, const void *secondElem));
// FUNCTION PROTOTYPES //

#endif // SORT_AND_OUTPUT_H_