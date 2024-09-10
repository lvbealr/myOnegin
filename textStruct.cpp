#include <cstdlib>
#include <sys/stat.h>

#include "textStruct.h"
#include "customWarning.h"
#include "sort.h"

int textDataInitialize(const char *fileName, textData *textData) {
    customWarning(textData != NULL, 1);

    FILE *file           = fopen(fileName, "r");
    struct stat fileData;
    fstat(fileno(file), &fileData);

    textData->fileSize   = (size_t) fileData.st_size + 1; // last \n
    textData->text       = (char *)calloc(textData->fileSize, sizeof(char));

    fread(textData->text, sizeof(char), textData->fileSize, file);

    // size_t sizeFread     = fread(textData->text, sizeof(char), textData->fileSize, file);
    // printf("%lu %lu", sizeFread, textData->fileSize);

    fclose(file);

    textData->lineCount  = lineCounter(textData);

    textData->newLine    = (char **)calloc(textData->lineCount, sizeof(char **));
    newLinePoint(textData);

    textData->outputText = (size_t *)calloc(textData->lineCount * 3, sizeof (size_t *)); // for 3 texts;

    textData->sortedText        = textData->outputText;
    textData->reverseSortedText = textData->sortedText        + textData->lineCount;
    textData->origText          = textData->reverseSortedText + textData->lineCount; 

    sort(textData);

    return 0;
}

int textDataDestruct(textData *textData) {
    customWarning(textData != NULL, 1);

    textData->fileSize          = 0;
    textData->lineCount         = 0;

    free(textData->text);
    free(textData->newLine);
    free(textData->outputText);

    textData->origText          = NULL;
    textData->sortedText        = NULL;
    textData->reverseSortedText = NULL;

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

int newLinePoint(textData *textData) {
    customWarning(textData != NULL, 1);

    *textData->newLine = textData->text;
    size_t lineNumber  = 1;
    
    char *textPointer  = textData->text;

    while (textPointer < textData->text + textData->fileSize) {
        textPointer++;

        if (*textPointer == '\n') {
            textData->newLine[lineNumber] = textPointer + 1;
            lineNumber++;
        }
    }

    return 0;
}

int indexDataInitialize(textData *textData) {
    customWarning(textData != NULL, 1);

    for (size_t lineIndex = 0; lineIndex < textData->lineCount; lineIndex++) {
        (textData->sortedText)[lineIndex]        = lineIndex;
        (textData->reverseSortedText)[lineIndex] = lineIndex;
        (textData->origText)[lineIndex]          = lineIndex;
    }

    return 0;
}

int fputsText(const textData *textData, const size_t *sortType, const char *mode) {
    customWarning(textData != NULL, 1);
    customWarning(sortType != NULL, 1);

    char *textPointer    = NULL;
    char *endLinePointer = NULL;

    FILE *fileOut = fopen("texts/oneginOutEng.txt", mode);

    for (size_t line   = 0; line < textData->lineCount; line++) {
        textPointer    = textData->newLine[sortType[line]];
        endLinePointer = textData->newLine[sortType[line] + 1];

        if (*textPointer != '\n') {
            while (textPointer < endLinePointer) {
                fputc(*textPointer, fileOut);
                textPointer++;
            }
        }
    }

    fputc('\n', fileOut);

    fclose(fileOut);
    return 0;
}

