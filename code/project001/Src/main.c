#include <stdio.h>

// Three global variables
int x = 5;
int y = 7;
int z = 0;

int main(void) {
    // Sum two of them
    z = x + y;

    // Print the result
    printf("The sum is %d\n", z);

    // Infinite loop
    while (1) {
    }
    return 0;
}