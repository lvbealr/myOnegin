#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

#include "customWarning.h"
#include "textStruct.h"
#include "customStrcmp.h"
#include "sort.h"
#include "putText.h"

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
//     const size_t LINE_COUNT                 = 5237;
//     const size_t MAX_SYMBOLS_COUNT          = 70;

//     char str[LINE_COUNT][MAX_SYMBOLS_COUNT] = {};
//     int* asciiStrPointers[LINE_COUNT]       = {};

//     int lineIndex[LINE_COUNT]               = {};

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
        
//         asciiStrPointers[i]        = asciiStr;
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

// TODO FLAGS (-sort, -rstort, -orig, -all)
// TODO ascii magic numbers
// TODO myFree : free(&ptr) | *ptr = NULL;
// CHECK QSORT() LOMUTO, HOARE

int main() {
    const char *fileName = "texts/oneginEng.txt";
    textData Onegin      = {};

    textDataInitialize(fileName, &Onegin);
    
    putText(&Onegin);
    
    textDataDestruct(&Onegin);
}