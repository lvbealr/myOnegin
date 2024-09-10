#include <cstdio>

#include "putText.h"
#include "customWarning.h"

int putText(textData *text) {
    customWarning(text != NULL, 1);

    fputsText(text, text->sortedText,        "w");
    fputsText(text, text->reverseSortedText, "a");
    fputsText(text, text->origText,          "a");

    return 0;
}