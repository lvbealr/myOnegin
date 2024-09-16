#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

#include "customWarning/customWarning.h" // TODO header unused
#include "textStruct.h"
#include "customStrcmp.h"                // TODO header unused
#include "sort.h"                        // TODO header unused

// TODO FLAGS (-sort, -rstort, -orig, -all)
// TODO myFree : free(&ptr) | *ptr = NULL;
// CHECK QSORT() LOMUTO, HOARE

int main() {
    const char *fileName = "texts/oneginEng.txt";
    textData    Onegin   = {}; // TODO align like this
    
    textDataInitialize(fileName, &Onegin);
    textDataDestruct(&Onegin);
}
