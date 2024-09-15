#ifndef TEXT_STRUCT_H_
#define TEXT_STRUCT_H_

#include <cstdio>

enum fileErrors {
    noSuchFile = -1
};

struct textLine {
    char *linePointer  = NULL;
    size_t lineSize    = 0;
};

struct textData {
    ssize_t fileSize   = 0;
    size_t lineCount   = 0;
    char *text         = NULL;
};

// FUNCTION PROTOTYPES //
int textDataInitialize(const char *fileName, textData *textData);
int textDataDestruct(textData *textData);
size_t lineCounter(textData *textData);
int newLinePoint(textData *textData);
int fputsText(const textData *textData, const size_t *sortType, const char *mode);
int textLinePoint(textData *textData, textLine *lineArray);
int textLineInitialize(textData *textData, textLine *lineArray);
int textLineDestruct(textLine *lineArray);
// FUNCTION PROTOTYPES //

#endif // TEXT_STRUCT_H_