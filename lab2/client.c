#include <stdio.h>
#include "collatz.h"

int main() {
    int input = 6;
    int max_iter = 50;
    int steps[max_iter];

    int num_steps = test_collatz_convergence(input, max_iter, steps);

    if (num_steps) {
        printf("Statyczna: %d -> ", input);
        for (int i = 0; i < num_steps; i++) {
            printf("%d ", steps[i]);
        }
        printf("\n");
    } else {
        printf("Nie udało się dojść do 1 w %d krokach\n", max_iter);
    }

    return 0;
}