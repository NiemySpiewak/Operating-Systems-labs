#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    void *handle = dlopen("libcollatz.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Błąd ładowania biblioteki: %s\n", dlerror());
        return 1;
    }

    int (*collatz_conjecture)(int) = dlsym(handle, "collatz_conjecture");
    int (*test_collatz_convergence)(int, int, int*) = dlsym(handle, "test_collatz_convergence");

    if (!collatz_conjecture || !test_collatz_convergence) {
        fprintf(stderr, "Nie znaleziono funkcji!\n");
        dlclose(handle);
        return 1;
    }

    int input = 19;
    int max_iter = 50;
    int steps[max_iter];

    int num_steps = test_collatz_convergence(input, max_iter, steps);

    if (num_steps) {
        printf("Dynamiczna: %d -> ", input);
        for (int i = 0; i < num_steps; i++) {
            printf("%d ", steps[i]);
        }
        printf("\n");
    } else {
        printf("Nie udało się dojść do 1 w %d krokach\n", max_iter);
    }

    dlclose(handle);
    return 0;
}
