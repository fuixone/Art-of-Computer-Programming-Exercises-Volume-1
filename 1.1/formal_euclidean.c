// Formal state-like implementation of Euclidean Algorithm

#include "debugger.h"

typedef struct
{
    int n, m;
} Pair;

typedef struct
{
    int m, n, r;
    int stage;
} Quad;

typedef enum 
{
    PAIR,
    QUAD,
    DONE
} StateType;

typedef struct 
{
    StateType kind;
    union
    {
        Pair pair;
        Quad quad;
        int result;
    };
} State;

void EuclideanAlgorithm(State* s)
{
    switch(s->kind)
    {
        case PAIR:
            s->kind = QUAD;
            s->quad = (Quad){s->pair.m, s->pair.n, 0, 1};
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

void HandleEdgeCases(State* s)
{
    Pair* pair = &(s->pair);

    if(pair->m < 0) pair->m = -pair->m;
    if(pair->n < 0) pair->n = -pair->n;

    if(pair->m == 0 && pair->n == 0)
    {
        s->kind = DONE;
        s->result = 0;
        return;
    }

    if(pair->m == 0) 
    {
        s->kind = DONE;
        s->result = pair->n;
        return;
    } 
    if(pair->n == 0)
    {
        s->kind = DONE;
        s->result = pair->m;
        return;
    }

    if(pair->m < pair->n)
    {
        int tempM = pair->m;
        pair->m = pair->n;
        pair->n = tempM;
    }

    return;
}

int IsNotDone(State* s)
{
    return s->kind != DONE;
}

void Run(State* s)
{
    HandleEdgeCases(s);

    while(IsNotDone(s))
    {
        EuclideanAlgorithm(s);
    }
}

int main()
{
    State s1 = {.kind = PAIR, .pair = {48, 18}};
    Run(&s1);
    DEBUGGER_EXPECTED(48, 18, 6, s1.result);

    State s2 = {.kind = PAIR, .pair = {119, 544}};
    Run(&s2);
    DEBUGGER_EXPECTED(119, 544, 17, s2.result);

    State s3 = {.kind = PAIR, .pair = {101, 103}};
    Run(&s3);
    DEBUGGER_EXPECTED(101, 103, 1, s3.result);

    State s4 = {.kind = PAIR, .pair = {100, 25}};
    Run(&s4);
    DEBUGGER_EXPECTED(100, 25, 25, s4.result);

    State s5 = {.kind = PAIR, .pair = {0, 34}};
    Run(&s5);
    DEBUGGER_EXPECTED(0, 34, 34, s5.result);

    State s6 = {.kind = PAIR, .pair = {123456, 789012}};
    Run(&s6);
    DEBUGGER_EXPECTED(123456, 789012, 12, s6.result);

    State s7 = {.kind = PAIR, .pair = {-48, 18}};
    Run(&s7);
    DEBUGGER_EXPECTED(-48, 18, 6, s7.result);

    State s8 = {.kind = PAIR, .pair = {0, 0}};
    Run(&s8);
    DEBUGGER_EXPECTED(0, 0, 0, s8.result);

    return 0;
}