#include <cstdlib>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include "textStruct.h"
#include "customWarning/customWarning.h"
#include "sort.h"
#include "customFree.h"
#include "customStrcmp.h"
#include "outputText.h"
#include "sortAndOutput.h"

int textLinePoint(textData *textData, textLine *lineArray) {
    customWarning(textData  != NULL, 1);
    customWarning(lineArray != NULL, 1);

    char *textPointer = textData->text;

    size_t lineIndex  = 0;
    lineArray[lineIndex].linePointer = textPointer;

    while (textPointer < textData->text + textData->fileSize) {
        textPointer++;

        if (*textPointer == '\n') {
            lineIndex++;
            lineArray[lineIndex - 1].lineSize = (size_t) (textPointer - lineArray[lineIndex - 1].linePointer);
            lineArray[lineIndex].linePointer  = textPointer + 1;
        }
    }

    return 0;
}

int textLineInitialize(textData *textData, textLine *lineArray) {
    customWarning(textData != NULL, 1);

    return !(textLinePoint(textData, lineArray));
}

int textLineDestruct(textLine *lineArray) {
    customWarning(lineArray != NULL, 1);
    
    free(lineArray);
    lineArray = NULL;

    return 0;
}

int textDataInitialize(const char *fileName, textData *textData) {
    customWarning(textData != NULL, 1);

    struct stat fileData;
    stat(fileName, &fileData);

    textData->fileSize   = (ssize_t)fileData.st_size;

    textData->text       = (char *)calloc((size_t)textData->fileSize, sizeof(char));

    int openFile = open(fileName, O_RDONLY);
    customWarning(openFile != noSuchFile, 1);

    ssize_t sizeRead     = read(openFile, textData->text, (size_t)textData->fileSize); 

    customWarning(sizeRead == textData->fileSize, 1);

    close(openFile);

    textData->lineCount  = lineCounter(textData);

    textLine *lineArray  = (textLine *)calloc(textData->lineCount, sizeof(textLine));
    textLineInitialize(textData, lineArray);

    const char *outputFileName = "texts/oneginOutEng.txt";

    sortAndOutput   (outputFileName, textData, lineArray, &customStrcmp);
    sortAndOutput   (outputFileName, textData, lineArray, &customReverseStrcmp);
    saveOriginalText(outputFileName, textData);

    /*/ QSORT /*/

    // qsort(lineArray, textData->lineCount, sizeof(textLine), &customStrcmp);
    // qsort(lineArray, textData->lineCount, sizeof(textLine), &customReverseStrcmp);

    /*/ QSORT /*/

    return (openFile <= 0); // openFile returns -1 by error, so textDataInitialize returns 0 by success and 1 by error
}

int textDataDestruct(textData *textData) {
    customWarning(textData != NULL, 1);

    textData->fileSize          = 0;
    textData->lineCount         = 0;

    free(textData->text);

    return 0;
}

size_t lineCounter(textData *textData) {
    customWarning(textData != NULL, 1);

    size_t lineCount  = 0; 

    char *textPointer = textData->text;
    while (textPointer < textData->text + textData->fileSize) {
        if (*textPointer == '\n') {
            lineCount++;
        }
        textPointer++;
    }
    
    return lineCount;
}