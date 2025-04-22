// Euclidean Algorithm

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define DEBUGGER(a, b, expected, result) do { \
    printf("Input: %d, %d should equal %d. Equaled: %d\n", (a), (b), (expected), (result)); \
    assert((expected) == (result)); \
} while (0)

typedef struct Input 
{
    int m;
    int n;
} Input;

// If -1 -> continue algorithm execution
// If any other number -> return that number
int PreliminaryStep(struct Input* input)
{
    if(input->m < 0) input->m = -input->m;
    if(input->n < 0) input->n = -input->n;

    if(input->m == 0 && input->n == 0) return 0; 

    if(input->m == 0) return input->n;
    if(input->n == 0) return input->m;

    if(input->m < input->n)
    {
        int tempM = input->m;
        input->m = input->n;
        input->n = tempM;
    }

    return -1;
}

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
    DEBUGGER(48, 18, 6, result);

    result = EuclideanAlgorithm(&(Input){119, 544}, 1);
    DEBUGGER(119, 544, 17, result);

    result = EuclideanAlgorithm(&(Input){101, 103}, 1);
    DEBUGGER(101, 103, 1, result);

    result = EuclideanAlgorithm(&(Input){100, 25}, 1);
    DEBUGGER(100, 25, 25, result);

    result = EuclideanAlgorithm(&(Input){0, 34}, 1);
    DEBUGGER(0, 34, 34, result);

    result = EuclideanAlgorithm(&(Input){123456, 789012}, 1);
    DEBUGGER(123456, 789012, 12, result);

    result = EuclideanAlgorithm(&(Input){-48, 18}, 1);
    DEBUGGER(-48, 18, 6, result);

    return 0;
}