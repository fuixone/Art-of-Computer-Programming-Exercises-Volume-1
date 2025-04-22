/**
 * Exercise 3 of 1.1
 * 
 * [20] Change Algorithm E so that all trivial operations such as m <- n are avoided.
 * Write this new algorithm in the style of Algorithm E, and call it Algorithm F
 */

#include "euclid.h"
#include "debugger.h"

int FeuclideanAlgorithm(struct Input* input)
{

    int prelimResult;
    if((prelimResult = PreliminaryStep(input)) != -1) return prelimResult;

    int remainder;
    int m = input->m;
    int n = input->n;

    while(n != 0)
    {   
        remainder = m % n;
        m = n;
        n = remainder;
    }

    return m;    
}

int main()
{
    int result = FeuclideanAlgorithm(&(Input){48, 18});
    DEBUGGER_EXPECTED(48, 18, 6, result);

    result = FeuclideanAlgorithm(&(Input){119, 544});
    DEBUGGER_EXPECTED(119, 544, 17, result);

    result = FeuclideanAlgorithm(&(Input){101, 103});
    DEBUGGER_EXPECTED(101, 103, 1, result);

    result = FeuclideanAlgorithm(&(Input){100, 25});
    DEBUGGER_EXPECTED(100, 25, 25, result);

    result = FeuclideanAlgorithm(&(Input){0, 34});
    DEBUGGER_EXPECTED(0, 34, 34, result);

    result = FeuclideanAlgorithm(&(Input){123456, 789012});
    DEBUGGER_EXPECTED(123456, 789012, 12, result);

    result = FeuclideanAlgorithm(&(Input){-48, 18});
    DEBUGGER_EXPECTED(-48, 18, 6, result);

    result = FeuclideanAlgorithm(&(Input){0, 0});
    DEBUGGER_EXPECTED(0, 0, 0, result);

    return 0;
}