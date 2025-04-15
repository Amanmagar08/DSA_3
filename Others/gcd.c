#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int num1, num2;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if (num1 < 0) num1 = -num1;
    if (num2 < 0) num2 = -num2;

    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));

    return 0;
}
