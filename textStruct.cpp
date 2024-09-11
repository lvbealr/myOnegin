#include <cstdlib>
#include <sys/stat.h>

#include "textStruct.h"
#include "customWarning.h"
#include "sort.h"
#include "customFree.h"

int textDataInitialize(const char *fileName, textData *textData) {
    customWarning(textData != NULL, 1);

    // FILE *file           = fopen(fileName, "r");
    // struct stat fileData;
    // fstat(fileno(file), &fileData);

    struct stat fileData;
    stat(fileName, &fileData);

    // TODO CHECK FILENAME
    // TODO read <io.h> !!!!!!!!
    // TODO binary mode (by read())
    // TODO \r \n to -> \0
    // TODO fputs(buffer = textData->text) without replace \r \n -> \0
    // TODO strchr() to find \n == for(;;) !!!! OPTIONAL !!!!

    textData->fileSize   = (size_t) /*TODO ⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⣿⣿⣿⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀ spaces
                                           ⠀⠀⠀⠀⠀⠀⢀⣾⡿⠋⠀⠿⠇⠉⠻⣿⣄⠀⠀⠀⠀⠀⠀
                                           ⠀⠀⠀⠀⠀⢠⣿⠏⠀⠀⠀⠀⠀⠀⠀⠙⣿⣆⠀⠀⠀⠀⠀
                                           ⠀⠀⠀⠀⢠⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣆⠀⠀⠀⠀
                                           ⠀⠀⠀⠀⢸⣿⡄⠀⠀⠀⢀⣤⣀⠀⠀⠀⠀⣿⡿⠀⠀⠀⠀
                                           ⠀⠀⠀⠀⠀⠻⣿⣶⣶⣾⡿⠟⢿⣷⣶⣶⣿⡟⠁⠀⠀⠀⠀
                                           ⠀⠀⠀⠀⠀⠀⣿⡏⠉⠁⠀⠀⠀⠀⠉⠉⣿⡇⠀⠀⠀⠀⠀
                                           ⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀
                                           ⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀
                                           ⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀
                                           ⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀
                                           ⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀
                                           ⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀
                                           ⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⣸⣿⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀
                                           ⠀⠀⠀⠀⠀⠀⣿⡇⢀⣴⣿⠇⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀
                                           ⠀⠀⠀⢀⣠⣴⣿⣷⣿⠟⠁⠀⠀⠀⠀⠀⣿⣧⣄⡀⠀⠀⠀
                                           ⠀⢀⣴⡿⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠙⢿⣷⣄⠀
                                           ⢠⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣆
                                           ⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿
                                           ⣿⣇⠀⠀⠀⠀⠀⠀⢸⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿
                                           ⢹⣿⡄⠀⠀⠀⠀⠀⠀⢿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⡿
                                           ⠀⠻⣿⣦⣀⠀⠀⠀⠀⠈⣿⣷⣄⡀⠀⠀⠀⠀⣀⣤⣾⡟⠁
                                           ⠀⠀⠈⠛⠿⣿⣷⣶⣾⡿⠿⠛⠻⢿⣿⣶⣾⣿⠿⠛⠉⠀⠀*/ fileData.st_size; // last \n

    textData->text       = (char *)calloc(textData->fileSize, sizeof(char));

    FILE *file           = fopen(fileName, "r");

    // fread(textData->text, sizeof(char), textData->fileSize, file);

    size_t sizeFread            = fread(textData->text, sizeof(char), textData->fileSize, file);

    customWarning(sizeFread == textData->fileSize, 1);

    fclose(file);

    textData->lineCount         = lineCounter(textData);

    textData->newLine           = (char **)calloc(textData->lineCount, sizeof(char *));
    newLinePoint(textData);

    /* TODO Use pointers, not indeces 
        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣠⣤⣤⣀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀
        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀
        ⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀
        ⠀⠀⠀⠀⢀⣀⢾⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⢋⣭⡍⣿⣿⣿⣿⣿⣿⠀
        ⠀⢀⣴⣶⣶⣝⢷⡝⢿⣿⣿⣿⠿⠛⠉⠀⠀⣰⣿⣿⢣⣿⣿⣿⣿⣿⣿⡇
        ⢀⣾⣿⣿⣿⣿⣧⠻⡌⠿⠋⠁⠀⠀⠀⠀⢰⣿⣿⡏⣸⣿⣿⣿⣿⣿⣿⣿
        ⣼⣿⣿⣿⣿⣿⣿⡇⠁⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⠇⢻⣿⣿⣿⣿⣿⣿⡟
        ⠙⢹⣿⣿⣿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⣿⣿⡿⠟⠁
        ⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    */
    textData->sortedText        = (size_t *)calloc(textData->lineCount, sizeof(size_t));
    textData->reverseSortedText = (size_t *)calloc(textData->lineCount, sizeof(size_t));
    textData->origText          = (size_t *)calloc(textData->lineCount, sizeof(size_t));

    // TODO 3 calloc's or 3 buffers and 3 pointers
    // TODO STRUCT ARRAY FOR ...

    sort(textData);

    return 0;
}

int textDataDestruct(textData *textData) {
    customWarning(textData != NULL, 1);

    textData->fileSize          = 0;
    textData->lineCount         = 0;

    customFree(textData->text);
    free(textData->newLine);
    free(textData->origText);
    free(textData->sortedText);
    free(textData->origText);

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

