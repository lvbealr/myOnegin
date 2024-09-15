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

enum fileErrors {
    noSuchFile = -1
};

int textLinePoint(textData *textData, textLine *lineArray) {
    customWarning(textData != NULL, 1);
    customWarning(lineArray != NULL, 1);

    char *textPointer = textData->text;

    size_t lineIndex = 0;
    lineArray[lineIndex].linePointer = textPointer;

    while (textPointer < textData->text + textData->fileSize) {
        textPointer++;

        if (*textPointer == '\n') {
            lineIndex++;
            lineArray[lineIndex - 1].lineSize = (size_t) (textPointer - lineArray[lineIndex - 1].linePointer);
            lineArray[lineIndex].linePointer  = textPointer + 1;
        }
    }

    // /*/ CHECK textLine /*/
    // for (size_t i = 0; i < textData->lineCount; i++) {
    //     for (size_t j = 0; j < lineArray[i].lineSize; j++) {
    //         printf("%c", *(lineArray[i].linePointer + j));
    //     }
    //     printf("\n");
    // }
    // /*/ CHECK textLine /*/

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

    mySort(lineArray, textData->lineCount, sizeof(textLine), &customStrcmp);
    /*/ CHECK SORTED TEXT /*/
    for (size_t i = 0; i < textData->lineCount; i++) {
        if (*(lineArray[i].linePointer) != '\n') {
            for (size_t j = 0; j < lineArray[i].lineSize; j++) {
                printf("%c", *(lineArray[i].linePointer + j));
            }
            printf("\n");
        }
    }
    /*/ CHECK SORTED TEXT /*/

    printf("\n");

    mySort(lineArray, textData->lineCount, sizeof(textLine), &customReverseStrcmp);
    /*/ CHECK SORTED TEXT /*/
    for (size_t i = 0; i < textData->lineCount; i++) {
        if (*(lineArray[i].linePointer) != '\n') {
            for (size_t j = 0; j < lineArray[i].lineSize; j++) {
                printf("%c", *(lineArray[i].linePointer + j));
            }
            printf("\n");
        }
    }
    /*/ CHECK SORTED TEXT /*/

    printf("\n");

    for (ssize_t index = 0; index < textData->fileSize; index++) {
        if (index > 0 && textData->text[index] == '\n' && textData->text[index - 1] == '\n') {
            continue;
        }
        else {
            printf("%c", textData->text[index]);
        }
    }

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