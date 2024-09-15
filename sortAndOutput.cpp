#include "sortAndOutput.h"
#include "textStruct.h"
#include "sort.h"
#include "outputText.h"

int sortAndOutput(const char *outputFileName, textData *textData, textLine *lineArray,
                  int (*comparator)(const void *firstElem, const void *secondElem)) {
    mySort(lineArray, textData->lineCount, sizeof(textLine), comparator);
    saveChangedText(outputFileName, textData, lineArray);

    return 0;
}