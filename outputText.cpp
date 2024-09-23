#include "textStruct.h"
#include "outputText.h"
#include "customWarning/customWarning.h"

// use comparator to print orig text

int saveChangedText(const char *fileName, const textData *textData, const textLine *lineArray) {
    customWarning(fileName   != NULL, 1);
    customWarning(textData   != NULL, 1);
    customWarning(lineArray  != NULL, 1);

    FILE *outputFile = fopen(fileName, "a");
    customWarning(outputFile != NULL, 1);

    for (size_t line = 0; line < textData->lineCount; line++) {
        if ((*lineArray[line].linePointer) != '\n') {
            for (size_t symbol = 0; symbol < lineArray[line].lineSize; symbol++) {
                putc(*(lineArray[line].linePointer + symbol), outputFile);
            }
            putc('\n', outputFile);
        }
    }
    putc('\n', outputFile);
    fclose(outputFile);

    return 0;
}

int saveOriginalText(const char *fileName, const textData *textData) {
    customWarning(fileName   != NULL, 1);
    customWarning(textData   != NULL, 1);

    FILE *outputFile = fopen(fileName, "a");
    customWarning(outputFile != NULL, 1);

    for (ssize_t symbol = 0; symbol < textData->fileSize; symbol++) {
        if (symbol > 0 && textData->text[symbol] == '\n' && textData->text[symbol - 1] == '\n') {
            continue;
        }

        else {
            putc(textData->text[symbol], outputFile);
        }
    }

    fclose(outputFile);

    return 0;
}
