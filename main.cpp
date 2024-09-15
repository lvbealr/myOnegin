#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

#include "customWarning/customWarning.h"
#include "textStruct.h"
#include "customStrcmp.h"
#include "sort.h"

// TODO FLAGS (-sort, -rstort, -orig, -all)
// TODO ascii magic numbers
// TODO myFree : free(&ptr) | *ptr = NULL;
// CHECK QSORT() LOMUTO, HOARE

int main() {
    const char *fileName = "texts/oneginEng.txt";
    textData Onegin      = {};
    
    textDataInitialize(fileName, &Onegin);
    textDataDestruct(&Onegin);
}