/**
 * Exercise 4 of 1.1
 * 
 * [16] What is the GCD of 2166 and 6099 = 57
 */

#include <stdio.h>

#include "formal_euclidean.h"

 int main()
 {
    int a = 2166;
    int b = 6099;

    int gcd = GCD(a, b);

    printf("GCD between %d and %d is: %d", a, b, gcd);

    return 0;
 }