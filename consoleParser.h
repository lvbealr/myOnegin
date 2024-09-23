#ifndef CONSOLE_PARSER_H_
#define CONSOLE_PARSER_H_

#include <cstring>

#include "menu.h"

const char *isValueFlag(const char *consoleFlag) {
    return strchr(consoleFlag, '=');
}

#define parseConsole(argc, argv) {                                                \
    const char* eqPosition = NULL;                                                \
                                                                                  \
    if (argc == 1) {                                                              \
        DEFAULT_MODE()                                                            \
    }                                                                             \
                                                                                  \
    else {                                                                        \
        for (int flagNumber = 1; flagNumber < argc; flagNumber++) {               \
            if (!strcmp(argv[flagNumber], "-sMode")) {                            \
                SORT_MODE()                                                       \
            }                                                                     \
            else if (!strcmp(argv[flagNumber], "-rsMode")) {                      \
                REVERSE_SORT_MODE()                                               \
            }                                                                     \
                                                                                  \
            else if (!strcmp(argv[flagNumber], "-oMode")) {                       \
                ORIGINAL_MODE()                                                   \
            }                                                                     \
                                                                                  \
            else {                                                                \
                if ((eqPosition = isValueFlag(argv[flagNumber])) != NULL) {       \
                    printf("%c", *eqPosition);                                    \
                }                                                                 \
                else {                                                            \
                    printf("This Flag [%s] Doesn't Exist!\n", argv[flagNumber]);  \
                }                                                                 \
            }                                                                     \
        }                                                                         \
    }                                                                             \
}

#endif // CONSOLE_PARSER_H_