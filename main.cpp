#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

#include "textStruct.h"
#include "sort.h"
#include "customStrcmp.h"
#include "customWarning/customWarning.h"
#include "outputText.h"

typedef int (compareFunc)(const void *, const void *);

// TODO FLAGS (-sort, -rstort, -orig, -all)
// TODO myFree : free(&ptr) | *ptr = NULL;
// CHECK QSORT() LOMUTO, HOARE

static int sortAndOutput(const char *outputFileName, textData *textData, textLine *lineArray, compareFunc *comparator) {
    customWarning(outputFileName != NULL, 1);
    customWarning(textData       != NULL, 1);
    customWarning(lineArray      != NULL, 1);
    customWarning(comparator     != NULL, 1);

    mySort(lineArray, textData->lineCount, sizeof(textLine), comparator);
    saveChangedText(outputFileName, textData, lineArray);

    return 0;
} 

int main() {
    const char *fileName       = "texts/oneginEng.txt";
    const char *outputFileName = "texts/oneginOutEng.txt";

    textData Onegin = {};
    
    textDataInitialize(fileName, &Onegin);
    
    sortAndOutput(outputFileName,    &Onegin, Onegin.lineArray, &customStrcmp);
    sortAndOutput(outputFileName,    &Onegin, Onegin.lineArray, &customReverseStrcmp);
    saveOriginalText(outputFileName, &Onegin);

    textDataDestruct(&Onegin);
}
