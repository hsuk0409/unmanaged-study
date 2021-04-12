#include <stdio.h>

int factorial(int n);
int factorialRecursive(int n, int fac);

int factorialRecursive(int n, int fac)
{
    if (n <= 1) {
        return fac;
    }

    return factorialRecursive(n - 1, n * fac);
}

int factorial(int n)
{
    return factorialRecursive(n, 1);
}

int main(void)
{
    int result = factorial(5);
    printf("Factorial func result:: %d\n", result);
    
    return 0;
}
