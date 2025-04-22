// Euclidean Algorithm

#include "euclid.h"

#include <stdbool.h>

#include "debugger.h"

int EuclideanAlgorithm(struct Input* input, int flag)
{

    if(flag) 
    {
        int prelimResult;
        if((prelimResult = PreliminaryStep(input)) != -1) return prelimResult;
        flag = 0;
    }

    int remainder;
    if((remainder = input->m % input->n) == 0) return input->n;
    
    input->m = input->n;
    input->n = remainder;
    return EuclideanAlgorithm(input, 0);
}

int main()
{
    int result = EuclideanAlgorithm(&(Input){48, 18}, 1);
    DEBUGGER_EXPECTED(48, 18, 6, result);

    result = EuclideanAlgorithm(&(Input){119, 544}, 1);
    DEBUGGER_EXPECTED(119, 544, 17, result);

    result = EuclideanAlgorithm(&(Input){101, 103}, 1);
    DEBUGGER_EXPECTED(101, 103, 1, result);

    result = EuclideanAlgorithm(&(Input){100, 25}, 1);
    DEBUGGER_EXPECTED(100, 25, 25, result);

    result = EuclideanAlgorithm(&(Input){0, 34}, 1);
    DEBUGGER_EXPECTED(0, 34, 34, result);

    result = EuclideanAlgorithm(&(Input){123456, 789012}, 1);
    DEBUGGER_EXPECTED(123456, 789012, 12, result);

    result = EuclideanAlgorithm(&(Input){-48, 18}, 1);
    DEBUGGER_EXPECTED(-48, 18, 6, result);

    result = EuclideanAlgorithm(&(Input){0, 0}, 1);
    DEBUGGER_EXPECTED(0, 0, 0, result);

    return 0;
}