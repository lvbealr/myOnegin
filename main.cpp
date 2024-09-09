#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <sys/stat.h>

#include "customWarning.h"

// void strToAscii(int *asciiArray, const char *string, size_t lenSize) {
//     size_t asciiArrayIndex = 1;
//     asciiArray[0]          = (int) lenSize;

//     while (*string != '\0') {
//         if (isalpha(*string) || *string == ' ') {
//             asciiArray[asciiArrayIndex] = tolower(*string);
//             asciiArrayIndex++;
//         }
//         string++;
//     }
// }

// size_t strAlphLen(const char *s) {
//     size_t count = 0;

//     while (*s != '\0') {
//         if (isalpha(*s) || (*s) == ' ') {
//             count++;
//         }
//         s++;
//     }
//     return count;
// }

// int customAsciiCmp(int *firstAscii, int *secondAscii) {
//     firstAscii++;
//     secondAscii++;

//     while (*firstAscii == *secondAscii++) {
//         if (*firstAscii++ == 0) {
//             return 0;
//         }
//     }
//     return (*firstAscii - *(secondAscii - 1));
// }

// int main() {
//     const size_t LINE_COUNT        = 5237;
//     const size_t MAX_SYMBOLS_COUNT = 70;

//     char str[LINE_COUNT][MAX_SYMBOLS_COUNT] = {};
//     int* asciiStrPointers[LINE_COUNT]       = {};

//     int lineIndex[LINE_COUNT] = {};

//     for (int i = 0; i < LINE_COUNT; i++) {
//         lineIndex[i] = i;
//     }

//     FILE *file = fopen("texts/oneginRU.txt", "r");
//     for (int i = 0; i < LINE_COUNT; i++) {
//         fgets(str[i], MAX_SYMBOLS_COUNT, file);
//         str[i][strlen(str[i]) - 1] = 0;

//         size_t len                 = strAlphLen(str[i]);
//         int *asciiStr              = (int *)calloc(len + 1, 8);

//         strToAscii(asciiStr, str[i], len);
        
//         asciiStrPointers[i] = asciiStr;
//     }

//     fclose(file);

//     for (int i = 0; i < LINE_COUNT - 1; i++) {
//         for (int j = 0; j < LINE_COUNT - i - 1; j++) {
//             if (customAsciiCmp(asciiStrPointers[lineIndex[j]], asciiStrPointers[lineIndex[j + 1]]) > 0) {
//                 int temp         = lineIndex[j];
//                 lineIndex[j]     = lineIndex[j + 1];
//                 lineIndex[j + 1] = temp;
//             }
//         }
//     }

//     FILE *fileOut = fopen("texts/oneginOutRU.txt", "w");

//     for (int i = 0; i < LINE_COUNT; i++) {
//         fputs(str[lineIndex[i]], fileOut);
//         fputs("\n", fileOut);
//     }

//     fclose(fileOut);
// }

struct textData {
    size_t fileSize           = 0;
    size_t lineCount          = 0;
    char *text                = NULL;
    char **newLine            = NULL;
    size_t *outputText        = NULL;
    size_t *sortedText        = NULL;
    size_t *reverseSortedText = NULL;
    size_t *origText          = NULL;
};

struct stat fileData;

// FUNCTION PROTOTYPES //
int textDataInitialize(const char *fileName, textData *textData);
size_t lineCounter(textData *textData);
int newLinePoint(textData *textData);
int customStrcmp(const char *firstString, const char *secondString);
int swap(size_t *firstElement, size_t *secondElement);
int bubbleSort(textData *textData);
int sort(textData *textData);
int printText(const textData *textData, const size_t * sortType);
int bubbleReverseSort(textData *textData);
int indexDataInitialize(textData *textData);
int fputsText(const textData *textData, const size_t *sortType, const char *mode);
// FUNCTION PROTOTYPES //

int textDataInitialize(const char *fileName, textData *textData) {
    customWarning(textData != NULL, 1);

    FILE *file = fopen(fileName, "r");
    struct stat fileData;
    fstat(fileno(file), &fileData);

    textData->fileSize = (size_t) fileData.st_size + 1; // last \n
    textData->text     = (char *)calloc(textData->fileSize, sizeof(char));

    fread(textData->text, sizeof(char), textData->fileSize, file);
    fclose(file);

    textData->lineCount = lineCounter(textData);

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

    int lineCount = 0; 

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
    size_t lineNumber = 1;
    
    char *textPointer = textData->text;

    while (textPointer < textData->text + textData->fileSize) {
        textPointer++;

        if (*textPointer == '\n') {
            textData->newLine[lineNumber] = textPointer + 1;
            lineNumber++;
        }
    }

    return 0;
}

int customStrcmp(const char *firstString, const char *secondString) {
    customWarning(firstString  != NULL, 1);
    customWarning(secondString != NULL, 1);

    int firstIndex    = 0, secondIndex   = 0;
    int firstElement  = 0, secondElement = 0;

    int asciiDiff  = 0;

    while (asciiDiff == 0) {
        firstElement  = firstString[firstIndex];
        secondElement = secondString[secondIndex];

        if (firstElement == '\n' || firstElement == EOF) {
            return (secondElement == '\n' || secondElement == EOF) ? 0 : -1;
        }
        if (secondElement == '\n' || secondElement == EOF) {
            return 1; // ...
        }
        if (isalpha(firstElement) || firstElement == ' ') {
            if (isalpha(secondElement) || secondElement == ' ') {
                asciiDiff += firstElement - secondElement;
                firstIndex++; secondIndex++;
            }
            else {
                secondIndex++;
            }
        }
        else {
            firstIndex++;
        }
    }
    return asciiDiff;
}

int customReverseStrcmp(const char *firstString, const char *secondString) {
    customWarning(firstString  != NULL, 1);
    customWarning(secondString != NULL, 1);

    firstString  = firstString - 2;
    secondString = secondString - 2;

    int firstIndex   = 0, secondIndex   = 0;
    int firstElement = 0, secondElement = 0;

    int asciiDiff = 0;

    while (asciiDiff == 0) {
        firstElement  = firstString[firstIndex];
        secondElement = secondString[secondIndex];

        if (firstElement == '\n' || firstElement == EOF) {
            return (secondElement == '\n' || secondElement == EOF) ? 0 : -1;
        }
        if (secondElement == '\n' || secondElement == EOF) {
            return 1; // ...
        }
        if (isalpha(firstElement) || firstElement == ' ') {
            if (isalpha(secondElement) || secondElement == ' ') {
                asciiDiff += firstElement - secondElement;
                firstIndex--; secondIndex--;
            }
            else {
                secondIndex--;
            }
        }
        else {
            firstIndex--;
        }
    }

    return asciiDiff;
}

int swap(size_t *firstElement, size_t *secondElement) {
    customWarning(firstElement  != NULL, 1);
    customWarning(secondElement != NULL, 1);

    size_t temp = 0;
    temp = *firstElement;
    *firstElement = *secondElement;
    *secondElement = temp;

    return 0;
}

int bubbleSort(textData *textData) {
    customWarning(textData != NULL, 1);

    for (size_t i = 0; i < textData->lineCount - 1; i++) {
        for (size_t j = 0; j < textData->lineCount - i - 1; j++) {
            if (customStrcmp((textData->newLine)[(textData->sortedText)[j]    ],
                             (textData->newLine)[(textData->sortedText)[j + 1]]) > 0) {
                                swap(&(textData->sortedText)[j], &(textData->sortedText)[j + 1]);
                             }
        }
    }

    return 0;
}

int bubbleReverseSort(textData *textData) {
    customWarning(textData != NULL, 1);

    for (size_t i = 0; i < textData->lineCount - 1; i++) {
        for (size_t j = 0; j < textData->lineCount - i - 1; j++) {
            if (customReverseStrcmp((textData->newLine)[(textData->reverseSortedText)[j] + 1],
                             (textData->newLine)[(textData->reverseSortedText)[j + 1] + 1]) > 0) {
                                swap(&(textData->reverseSortedText)[j], &(textData->reverseSortedText)[j + 1]);
                             }
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

int sort(textData *textData) {
    customWarning(textData != NULL, 1);

    indexDataInitialize(textData);
    bubbleSort(textData);
    bubbleReverseSort(textData);

    return 0;
}

int fputsText(const textData *textData, const size_t *sortType, const char *mode) {
    customWarning(textData != NULL, 1);
    customWarning(sortType != NULL, 1);

    char *textPointer    = NULL;
    char *endLinePointer = NULL;

    FILE *fileOut = fopen("texts/oneginOutEng.txt", mode);

    for (size_t line = 0; line < textData->lineCount; line++) {
        textPointer = textData->newLine[sortType[line]];
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

int main() {
    const char *fileName = "texts/oneginEng.txt";
    textData Onegin = {};

    textDataInitialize(fileName, &Onegin);
    fputsText(&Onegin, Onegin.sortedText, "w");
    fputsText(&Onegin, Onegin.reverseSortedText, "a");
    fputsText(&Onegin, Onegin.origText, "a");
    textDataDestruct(&Onegin);
}