#include <stdio.h>
#include <stdlib.h>


void fibonacci(int n);

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}

void fibonacci(int n) {
    int a = 0, b = 1, c;
    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return;
    }
    printf("Fibonacci Series: %d", a);
    if (n == 1) return;
    printf(" %d", b);
    for (int i = 2; i < n; i++) {
        c = a + b;
        printf(" %d", c);
        a = b;
        b = c;
    }
    printf("\n");
}


