#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

#include "textStruct.h"
#include "sort.h"
#include "customStrcmp.h"
#include "customWarning/customWarning.h"
#include "outputText.h"
#include "consoleParser.h"
#include "menu.h"

typedef int (compareFunc)(const void *, const void *);
// TODO struct with textData and lineArray, name context
static int sortAndOutput(const char *outputFileName, const textData *textData, const textLine *lineArray, compareFunc *comparator) {
    customWarning(outputFileName != NULL, 1);
    customWarning(textData       != NULL, 1);
    customWarning(lineArray      != NULL, 1);
    customWarning(comparator     != NULL, 1);

    // mySort(lineArray, textData->lineCount, sizeof(textLine), comparator);

    // FUCKING SEGMENTATION FAULT
    quickSort(lineArray, sizeof(textLine), 0, textData->lineCount, comparator);
    saveChangedText(outputFileName, textData, lineArray);

    return 0;
} 

int main(int argc, const char *argv[]) {
    const char *fileName       = "texts/oneginEng.txt";
    const char *outputFileName = "texts/oneginOutEng.txt";

    textData text = {};
    
    textDataInitialize(fileName, &text);

    parseConsole(argc, argv);

    textDataDestruct(&text);
}
