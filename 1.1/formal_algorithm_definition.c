// Most basic state
typedef struct State
{
    int k;
} State;

// Halting condition
int IsHalting(State* s, int upperLimit)
{
    return s->k >= upperLimit;
}

void Transition(State* s)
{
    s->k+=1;
}



