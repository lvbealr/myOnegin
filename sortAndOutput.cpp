#include "sortAndOutput.h"
#include "textStruct.h"
#include "sort.h"
#include "outputText.h"
#include "customWarning/customWarning.h"

int sortAndOutput(const char *outputFileName, textData *textData, textLine *lineArray,
                  int (*comparator)(const void *firstElem, const void *secondElem)) {
    customWarning(outputFileName != NULL, 1);
    customWarning(textData       != NULL, 1);
    customWarning(lineArray      != NULL, 1);
    customWarning(comparator     != NULL, 1);

    mySort(lineArray, textData->lineCount, sizeof(textLine), comparator);
    saveChangedText(outputFileName, textData, lineArray);

    return 0;
}