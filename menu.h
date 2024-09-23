#ifndef MENU_H_
#define MENU_H_

// MENU MACROS //
#define SORT_MODE()         {sortAndOutput(outputFileName,    &text, text.lineArray, &customStrcmp);}
#define REVERSE_SORT_MODE() {sortAndOutput(outputFileName,    &text, text.lineArray, &customReverseStrcmp);}
#define ORIGINAL_MODE()     {saveOriginalText(outputFileName, &text);}

#define DEFAULT_MODE() {                                                           \
    sortAndOutput(outputFileName,    &text, text.lineArray, &customStrcmp);        \
    sortAndOutput(outputFileName,    &text, text.lineArray, &customReverseStrcmp); \
    saveOriginalText(outputFileName, &text);                                       \
    }
// MENU MACROS //

#endif // MENU_H_