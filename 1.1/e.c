// Euclidean Algorithm

#include <stdio.h>
#include <assert.h>

#define DEBUGGER(a, b, expected, result) do { \
    printf("Input: %d, %d should equal %d. Equaled: %d\n", (a), (b), (expected), (result)); \
    assert((expected) == (result)); \
} while (0)

int EuclideanAlgorithm(int m, int n)
{

    if(m < 0) m = -m;
    if(n < 0) n = -n;

    if(m == 0 && n == 0) return 0;

    if(m == 0) return n;
    if(n == 0) return m;

    int remainder;
    if((remainder = m % n) == 0) return n;
    
    m = n;
    n = remainder;
    return EuclideanAlgorithm(m, n);
}

int main()
{
    int result = EuclideanAlgorithm(48, 18);
    DEBUGGER(48, 18, 6, result);

    result = EuclideanAlgorithm(101, 103);
    DEBUGGER(101, 103, 1, result);

    result = EuclideanAlgorithm(100, 25);
    DEBUGGER(100, 25, 25, result);

    result = EuclideanAlgorithm(0, 34);
    DEBUGGER(0, 34, 34, result);

    result = EuclideanAlgorithm(123456, 789012);
    DEBUGGER(123456, 789012, 12, result);

    result = EuclideanAlgorithm(-48, 18);
    DEBUGGER(-48, 18, 6, result);

    return 0;
}