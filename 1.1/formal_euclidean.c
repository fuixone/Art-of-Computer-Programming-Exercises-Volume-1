// Formal state-like implementation of Euclidean Algorithm
#include "debugger.h"
#include "formal_euclidean.h"

/**
 * Definitions
 */

 static struct Pair
 {
     int m, n;
 } Pair;
 
 static struct Quad
 {
     int m, n, r, stage;
 } Quad;
 
 static enum StateType
 {
     PAIR,
     QUAD,
     DONE
 } StateType;
 
 static struct State
 {
     enum StateType kind;    
     union
     {
         struct Pair pair;
         struct Quad quad;
     };
     int result;
 } State;

static void EuclideanAlgorithm(struct State* s);
static void HandleEdgeCases(struct State* s);
static int IsNotDone(struct State* s);
static void Run(struct State* s);
int GCD(int a, int b);

/**
 * Implementation
 */

static void EuclideanAlgorithm(struct State* s)
{
    switch(s->kind)
    {
        case PAIR:
            s->kind = QUAD;
            s->quad = (struct Quad){s->pair.m, s->pair.n, 0, 1};
            return;
        case QUAD:
            switch(s->quad.stage)
            {
                case 1:
                    s->kind = QUAD;
                    s->quad.r = s->quad.m % s->quad.n;
                    s->quad.stage = 2;
                    return;
                case 2:
                    if(s->quad.r == 0)
                    {
                        s->kind = DONE;
                        s->result = s->quad.n;
                        return;
                    }
                    s->quad.stage = 3;
                    return;
                case 3:
                    s->quad.m = s->quad.n;
                    s->quad.n = s->quad.r;
                    s->quad.stage = 1;
                    return;
            }
            break;
        case DONE:
            return;
    }
    return;
}

static void HandleEdgeCases(struct State* s)
{
    struct Pair* pair = &(s->pair);

    if(pair->m < 0) pair->m = -pair->m;
    if(pair->n < 0) pair->n = -pair->n;

    if(pair->n == 0 && pair->m == 0)
    {
        s->kind = DONE;
        s->result = 0;
        return;
    }

    if(pair->n == 0 || pair->m == 0)
    {
        s->kind = DONE;
        s->result = pair->n == 0 ? pair->m : pair->n;
        return;
    };

    if(pair->m < pair->n)
    {
        int tempM = pair->m;
        pair->m = pair->n;
        pair->n = tempM;
    }

    return;
}

static int IsNotDone(struct State* s)
{
    return s->kind != DONE;
}

static void Run(struct State* s)
{
    HandleEdgeCases(s);

    while(IsNotDone(s))
    {
        EuclideanAlgorithm(s);
    }
}

int GCD(int a, int b) 
{
    struct State state = {.kind = PAIR, .pair = {a, b}};
    Run(&state);
    return state.result;
};

static void Test()
{
    struct State s1 = {.kind = PAIR, .pair = {48, 18}};
    Run(&s1);
    DEBUGGER_EXPECTED(48, 18, 6, s1.result);

    struct State s2 = {.kind = PAIR, .pair = {119, 544}};
    Run(&s2);
    DEBUGGER_EXPECTED(119, 544, 17, s2.result);

    struct State s3 = {.kind = PAIR, .pair = {101, 103}};
    Run(&s3);
    DEBUGGER_EXPECTED(101, 103, 1, s3.result);

    struct State s4 = {.kind = PAIR, .pair = {100, 25}};
    Run(&s4);
    DEBUGGER_EXPECTED(100, 25, 25, s4.result);

    struct State s5 = {.kind = PAIR, .pair = {0, 34}};
    Run(&s5);
    DEBUGGER_EXPECTED(0, 34, 34, s5.result);

    struct State s6 = {.kind = PAIR, .pair = {123456, 789012}};
    Run(&s6);
    DEBUGGER_EXPECTED(123456, 789012, 12, s6.result);

    struct State s7 = {.kind = PAIR, .pair = {-48, 18}};
    Run(&s7);
    DEBUGGER_EXPECTED(-48, 18, 6, s7.result);

    struct State s9 = {.kind = PAIR, .pair = {20, 0}};  
    Run(&s9);
    DEBUGGER_EXPECTED(20, 0, 20, s9.result);

    struct State s10 = {.kind = PAIR, .pair = {0, 0}};
    Run(&s10);
    DEBUGGER_EXPECTED(0, 0, 0, s10.result);

    struct State s11 = {.kind = PAIR, .pair = {5, 1}};
    Run(&s11);
    printf("%d", s11.result);
    DEBUGGER_EXPECTED(5, 1, 1, s11.result);
}

/**
 * Uncomment to run tests
 */

int main()
{
    Test();
    return 0;
}