#ifndef TEXT_STRUCT_H_
#define TEXT_STRUCT_H_

#include <cstdio>

/**
 * @brief Codes Of File Errors
 * 
 */
enum fileErrors {
    noSuchFile = -1            // File Does Not Exist 
};

/**
 * @brief Line Of Text Struct 
 */
struct textLine {
    char *linePointer  = NULL; /** Pointer To The Beggining Of The Line */ 
    size_t lineSize    = 0;    /** Line Length */
};

/**
 * @brief Text Of File Struct
 */
struct textData {
    ssize_t   fileSize  = 0;    /** File Size (In Byte) */
    size_t    lineCount = 0;    /** Lines Number Of Text */
    char     *text      = NULL; /** Pointer To The Beggining Of The Text */
    textLine *lineArray = NULL; /** Pointer To The Text Lines Array */
};

// FUNCTION PROTOTYPES //
/**
 * @brief Initializing Of TextData Struct
 * 
 * @param fileName Input File Name
 * @param textData Pointer To TextData Struct (See Struct Description)
 * @return [int] Return Code (Success / Error) 
 */
int textDataInitialize(const char *fileName, textData *textData);

/**
 * @brief Destructing Of TextData Struct
 * 
 * @param textData Pointer To TextData Struct (See Struct Description)
 * @return [int] Return Code (Success / Error) 
 */
int textDataDestruct(textData *textData);

/**
 * @brief Counting Lines In Text
 * 
 * @param textData Pointer To TextData Struct (See Struct Description)
 * @return [size_t] Lines Number In Text 
 */
size_t lineCounter(textData *textData);

/**
 * @brief Pointing New Lines In Text
 * 
 * @param textData Pointer To TextData Struct (See Struct Description)
 * @param lineArray Array Of Pointers To TextLine Structs
 * @return [int] Return Code (Success / Error) 
 */
int textLinePoint(textData *textData, textLine *lineArray);

/**
 * @brief Initializing TextLine Struct
 * 
 * @param textData Pointer To TextData Struct (See Struct Description)
 * @param lineArray Array Of Pointers To TextLine Structs
 * @return [int] Return Code (Success / Error)
 */
int textLineInitialize(textData *textData, textLine *lineArray);

/**
 * @brief Destructing TextLine Struct
 * 
 * @param lineArray Array Of Pointers To TextLine Struct
 * @return [int] Return Code (Success / Error)
 */
int textLineDestruct(textLine *lineArray);
// FUNCTION PROTOTYPES //

#endif // TEXT_STRUCT_H_