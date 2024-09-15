#include <cstddef>
#include <cctype>

#include "customStrcmp.h"
#include "customWarning/customWarning.h"

int customStrcmp(const char *firstString, const char *secondString) {
    customWarning(firstString  != NULL, 1);
    customWarning(secondString != NULL, 1);

    int firstIndex    = 0, secondIndex   = 0;
    int firstElement  = 0, secondElement = 0;

    int asciiDiff     = 0;

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

    firstString       = firstString  - 2; // shift to end of previous line
    secondString      = secondString - 2; // shift to end of previous line

    int firstIndex    = 0, secondIndex   = 0;
    int firstElement  = 0, secondElement = 0;

    int asciiDiff     = 0;

    while (asciiDiff == 0) {
        firstElement  = firstString[firstIndex];
        secondElement = secondString[secondIndex];

        if (firstElement  == '\n' || firstElement  == EOF) {
            return (secondElement == '\n' || secondElement == EOF) ? 0 : -1;
        }
        if (secondElement == '\n' || secondElement == EOF) {
            return 1; // ...
        }
        if (isalpha(firstElement) || firstElement  == ' ') {
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