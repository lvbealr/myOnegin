#ifndef TEXT_STRUCT_H_
#define TEXT_STRUCT_H_

#include <cstdio>

// TODO: FUNCTIONS TO INITIALIZE TEXTLINE STRUCT //
// TODO: ONE SORT-FUNCTION TO SORT FORWARD AND SORT BACKFORWARD ?? //
struct textLine {
    char **linePointer = NULL;
    size_t lineSize    = 0;
};

// TODO: DELETE CHAR **NEWLINE FROM TEXTDATA //
struct textData {
    ssize_t fileSize          = 0;
    size_t lineCount          = 0;
    char *text                = NULL;
    char **newLine            = NULL;
    size_t *sortedText        = NULL;
    size_t *reverseSortedText = NULL;
    size_t *origText          = NULL;
};

// FUNCTION PROTOTYPES //
int textDataInitialize(const char *fileName, textData *textData);
int textDataDestruct(textData *textData);
size_t lineCounter(textData *textData);
int newLinePoint(textData *textData);
int indexDataInitialize(textData *textData);
int fputsText(const textData *textData, const size_t *sortType, const char *mode);
// FUNCTION PROTOTYPES //

#endif // TEXT_STRUCT_H_