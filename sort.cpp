#include <cstdio>

#include "customWarning.h"
#include "customStrcmp.h"
#include "textStruct.h"
#include "sort.h"

int sort(textData *textData) {
    customWarning(textData != NULL, 1);

    indexDataInitialize(textData);
    bubbleSort(textData);
    bubbleReverseSort(textData);

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

int swap(size_t *firstElement, size_t *secondElement) {
    customWarning(firstElement  != NULL, 1);
    customWarning(secondElement != NULL, 1);

    size_t temp    = 0;
    temp           = *firstElement;
    *firstElement  = *secondElement;
    *secondElement = temp;

    return 0;
}