#include <stdio.h>
#include <stdbool.h>
int fib(int n)
{
    int a = 0, b = 1, c = 0;
    while (c < n)
    {
        {
            c = a + b;
            a = b;
            b = c;
            if (c < n)
                printf("%d\n ", c);
        }
    }
    printf("\n");
    return 0;
}

int prime(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    if (count == 2)
        printf("PRIME NUMBER\n");
    else
        printf("NOT A PRIME NUMBER\n");
    return 0;
}

bool isPrime(int n)
{

    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

void printPrime(int n)
{
    for (int i = 2; i <= n; i++)
        if (isPrime(i))
            printf("%d ", i);
    printf("\n");
}

void print_pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            printf(" ");
        }
        for (int k = n; k >= i; k--)
        {
            printf("* ");
        }
        printf("\n");
    }
}

int main()
{
    int choice = 0;
    int cont = 0;
    do
    {
        printf("----------MENU----------\n");
        printf("1-Fibonacci\n");
        printf("2-Check if prime\n");
        printf("3-Print all prime uptil n\n");
        printf("4-Star Pattern\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int n;
            printf("Enter the n value for finding the fibonacci uptil n:\n");
            scanf("%d", &n);
            fib(n);
        }
        break;
        case 2:
        {
            int n;
            printf("Enter a number to check if it is prime:\n");
            scanf("%d", &n);
            prime(n);
        }
        break;
        case 3:
        {
            int n;
            printf("Enter to print all prime uptil n:\n");
            scanf("%d", &n);
            printPrime(n);
        }
        break;
        case 4:
        {
            int n = 0;
            printf("Enter the value of n:");
            scanf("%d", &n);
            print_pattern(n);
        }
        }
        printf("Do you want to continue? (0 for no, 1 for yes)");
        scanf("%d", &cont);
    } while (cont != 0);
    return 0;
}