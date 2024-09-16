#include "outputText.h"
#include "sortAndOutput.h"
#include "textStruct.h"
#include "sort.h"
#include "customWarning/customWarning.h"

typedef int (comparator)(const void *, const void *);

// TODO read about static functions
int sortAndOutput(const char *outputFileName, textData *textData, textLine *lineArray, comparator *comparator) {
    customWarning(outputFileName != NULL, 1);
    customWarning(textData       != NULL, 1);
    customWarning(lineArray      != NULL, 1);
    customWarning(comparator     != NULL, 1);

    mySort(lineArray, textData->lineCount, sizeof(textLine), comparator);
    saveChangedText(outputFileName, textData, lineArray);

    return 0;
} 
