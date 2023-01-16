#include <stdio.h>
#include <math.h>
int main()
{
    int choice = 0;
    int cont = 0;
    printf("----------MENU----------\n");

    do
    {
        printf("1-ADDITION\n");
        printf("2-SUBTRACTION\n");
        printf("3-MULTIPLICATION\n");
        printf("4-DIVISION\n");
        printf("5-Square root of a number\n");
        printf("6-Sine value of a number\n");
        printf("7-Cosine value of a number\n");
        printf("8-Tangent value of a number\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            float num1 = 0, num2 = 0;
            printf("Enter the first number:\n");
            scanf("%f", &num1);
            printf("Enter the second number:\n");
            scanf("%f", &num2);
            printf("The Addition of the two numbers:%f\n", (num1 + num2));
        }
        break;
        case 2:
        {
            float num1 = 0, num2 = 0;
            printf("Enter the first number:\n");
            scanf("%f", &num1);
            printf("Enter the second number:\n");
            scanf("%f", &num2);
            printf("The Difference of the two numbers:%f\n", (num1 - num2));
        }
        break;
        case 3:
        {
            float num1 = 0, num2 = 0;
            printf("Enter the first number:\n");
            scanf("%f", &num1);
            printf("Enter the second number:\n");
            scanf("%f", &num2);
            printf("The Product of the two numbers:%f\n", (num1 * num2));
        }
        break;
        case 4:
        {
            float num1 = 0, num2 = 0;
            printf("Enter the first number:\n");
            scanf("%f", &num1);
            printf("Enter the second number:\n");
            scanf("%f", &num2);
            printf("The Quotient on dividing the two numbers:%f\n", (num1 / num2));
        }
        break;
        case 5:
        {
            double num1 = 0;
            printf("Enter the first number:\n");
            scanf("%lf", &num1);
            printf("The square root of the number is:%lf\n", (sqrt(num1)));
        }
        break;
        case 6:
        {
            double num1 = 0;
            printf("Enter the number:\n");
            scanf("%lf", &num1);
            printf("The Sine value of the number is:%lf\n", (sin(num1)));
        }
        break;
        case 7:
        {
            double num1 = 0;
            printf("Enter the number:\n");
            scanf("%lf", &num1);
            printf("The Cosine value of the number is:%lf\n", (cos(num1)));
        }
        break;
        case 8:
        {
            double num1 = 0;
            printf("Enter the number:\n");
            scanf("%lf", &num1);
            printf("The Tangent value of the number is:%lf\n", (tan(num1)));
        }
        default:
        {
            printf("Enter the right choice!\n");
        }
        }
        printf("Do you want to continue? (0 for yes, 1 for no)");
        scanf("%d", &cont);
    } while (cont != 1);
    return 0;
}