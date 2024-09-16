#include <cstddef>
#include <cctype>
#include <cstdlib>

#include "customStrcmp.h"
#include "customWarning/customWarning.h"
#include "textStruct.h"

int customStrcmp(const void *firstElem, const void *secondElem) {
    customWarning(firstElem  != NULL, 1);
    customWarning(secondElem != NULL, 1);
    
    const char *firstString  = ((const textLine *)firstElem)->linePointer;
    const char *secondString = ((const textLine *)secondElem)->linePointer;

    size_t firstIndex   = 0, secondIndex   = 0;
    int    firstElement = 0, secondElement = 0;

    int asciiDiff = 0;

    while (asciiDiff == 0) {
        firstElement  = firstString[firstIndex];
        secondElement = secondString[secondIndex];

        if (firstElement == '\n' || firstElement == EOF) {
            return (secondElement == '\n' || secondElement == EOF) ? 0 : -1;
        }

        if (secondElement == '\n' || secondElement == EOF) {
            return 1;
        }

        if (isalpha(firstElement) || firstElement == ' ' || firstElement == '\'') {
            if (isalpha(secondElement) || secondElement == ' ' || secondElement == '\'') {
                asciiDiff += tolower(firstElement) - tolower(secondElement);
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

int customReverseStrcmp(const void *firstElem, const void *secondElem) {
    customWarning(firstElem  != NULL, 1);
    customWarning(secondElem != NULL, 1);

    const char *firstString  = ((const textLine *)firstElem)->linePointer;
    const char *secondString = ((const textLine *)secondElem)->linePointer;

    const size_t firstLen  = ((const textLine *)firstElem)->lineSize;
    const size_t secondLen = ((const textLine *)secondElem)->lineSize;

    size_t firstIndex   = firstLen - 1, secondIndex   = secondLen - 1;
    int    firstElement = 0,            secondElement = 0;

    int asciiDiff = 0;

    while (asciiDiff == 0) {
        firstElement  = firstString[firstIndex];
        secondElement = secondString[secondIndex];

        if (firstElement  == '\n' || firstElement  == EOF) {
            return (secondElement == '\n' || secondElement == EOF) ? 0 : -1;
        }
        
        if (secondElement == '\n' || secondElement == EOF) {
            return 1;
        }
        
        if (isalpha(firstElement) || firstElement  == ' ' || firstElement == '\'') { 
            if (isalpha(secondElement) || secondElement == ' ' || secondElement == '\'') {
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
