/*
    Exercise 1 of 1.1

[10]
The text showed how to interchange the values of variables m and n,
using the replacement notation, by setting:
    t <-- m
    m <-- n
    n <-- t

Show how the values of four variables (a, b, c, d) can be rearranged to (b, c, d, a)
by a sequence of replacements.

In other words, the new value of a is to be the original value of b, etc.
Try to use the minimum number of replacements.

*/

#include "debugger.h"

// Attention: void* is used only in this simple example,
// in a real program this would be incorrect!
typedef struct
{
    void* a;
    void* b;
    void* c;
    void* d;
} Point;

int IsInterchanged(Point* interchanged, Point* original)
{
    return 
        interchanged->a == original->b &&
        interchanged->b == original->c &&
        interchanged->c == original->d &&
        interchanged->d == original->a;
}

void Interchange(Point* p)
{
    void* pA = p->a;

    p->a = p->b;
    p->b = p->c;
    p->c = p->d;
    p->d = pA;
}

// According to the answers
void ANSWERSInterchange(Point* p)
{
    void* pT = p->a;
    p->a = p->b;
    p->b = p->c;
    p->c = p->d;
    p->d = pT;
}

int main()
{
    Point p1 = {(void *)1, (void *)2, (void *)3, (void*)4};
    Point p1Original = p1;
    Interchange(&p1);
    DEBUGGER_TRUTHY(IsInterchanged(&p1, &p1Original));

    Point p2 = {(void *)'a', (void *)'b', (void*)'c', (void *)'d'};
    Point p2Original = p2;
    Interchange(&p2);
    DEBUGGER_TRUTHY(IsInterchanged(&p2, &p2Original));

    Point p3 = {(void *)"a string", (void *)"b string", (void *)"c string", (void *)"d string"};
    Point p3Original = p3;
    Interchange(&p3);
    DEBUGGER_TRUTHY(IsInterchanged(&p3, &p3Original));

    Point answerP = {(void *)1, (void *)2, (void *)3, (void *)4};
    Point answerPOriginal = answerP;
    ANSWERSInterchange(&answerP);
    DEBUGGER_TRUTHY(IsInterchanged(&answerP, &answerPOriginal));
}