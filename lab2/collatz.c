#include "collatz.h"

int collatz_conjecture(int input)
{
    if (input%2 ==0)
    {
        return input/2;
    }
    else
    {
        return input*3 + 1;
    }

}

int test_collatz_convergence(int input, int max_iter, int *steps) {
    int count;
    for (count = 0; count < max_iter && input != 1; count++) {
        input = collatz_conjecture(input);
        steps[count] = input;
    }
    if (input == 1) {
        return count;
    } else {
        return 0;
    }
}

