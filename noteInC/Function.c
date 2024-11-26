
// Function,void


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define ADULT_FARE 3.25
void print_header(void) {//data_type function_name(type p1,type p2...){ ...; return value;}
	printf("**************************************\n");
	return;//可以不写return;
}

double calculate_tax(double income) {
	const double tax = 0.13;
	double tax_amount = income * tax;
	return tax_amount;
}


int sum(int n1, int n2) {
	int result = n1 + n2;
	return result;
}

void sum2(void) { // no return value

	int num1, num2;
	printf("enter the value of number1: ");
	scanf("%d", &num1);
	printf("enter the value of number2: ");
	scanf("%d", &num2);

	printf("in sum2: the sum of %d and %d is %d\n", num1, num2, num1+num2);

	return;
}

int sum3(void) { //no input(parameter) needed
	int num1, num2;
	printf("enter the value of number1: ");
	scanf("%d", &num1);
	printf("enter the value of number2: ");
	scanf("%d", &num2);

	return num1+num2;

}

int main(void)
{
	double income1 = 3000;
    print_header();
	double tax_value = calculate_tax(income1);
	printf("the hst tax=%.2lf\n", tax_value);

	int num1, num2;
	printf("enter the value of number1: ");
	scanf("%d", &num1);
	printf("enter the value of number2: ");
	scanf("%d", &num2);

	printf("the sum of %d and %d is %d\n", num1,num2,sum(num1,num2));

	print_header();
	print_header();
	
	sum2();

	print_header();
	print_header();
	print_header();

	printf("the sum is %d\n", sum3());


	return 0;
}




// Function求指数


/* Raise an Integer to the Power of an Integer
 * power.c
 */

#include <stdio.h>

 // getNonNegInt returns a non-negative integer
 //
 // getNonNegInt assumes that the user enters only
 // integer values and no trailing characters
 //
int getNonNegInt(void)
{
    int value;

    do {
        printf(" Non-negative : ");
        scanf("%d", &value);
        if (value < 0)
            printf(" * Negative! *\n");
    } while (value <= 0);

    return value;
}

// power returns the value of base raised to
//  the power of exponent (base^exponent)
//
//  power assumes that base and exponent are
//  integer values and exponent is non-negative
//
int power(int base, int exponent)
{
    int result, i;

    result = 1;
    for (i = 0; i < exponent; i++)
        result = result * base;

    return result;
}

int main(void)
{
    int base, exp, answer;

    printf("Enter base : ");
    scanf("%d", &base);

    printf("Enter exponent\n");
    exp = getNonNegInt();
    answer = power(base, exp);

    printf("%d^%d is %d\n", base, exp, answer);

    return 0;
}
