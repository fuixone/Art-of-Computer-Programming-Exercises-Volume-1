// Debugger
#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <stdio.h>
#include <assert.h>

#define DEBUGGER_EXPECTED(a, b, expected, result) do { \
    printf("Input: %d, %d SHOULD == %d, EQUALS == %d, TRUTH == %d\n", a, b, expected, result, expected == result); \
    assert((expected) == (result)); \
} while(0);

#define DEBUGGER_TRUTHY(truth) do { \
    printf("Result was: %s\n", truth ? "true" : "false"); \
    assert(truth); \
} while(0);

#endif // DEBUGGER_H