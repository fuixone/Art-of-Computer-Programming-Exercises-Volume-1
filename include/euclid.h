#ifndef EUCLID_H
#define EUCLID_H


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

    if(input->n == 0 || input->m == 0) return 0;

    if(input->m < input->n)
    {
        int tempM = input->m;
        input->m = input->n;
        input->n = tempM;
    }

    return -1;
}

#endif // EUCLID_H