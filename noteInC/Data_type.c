/*
multiline common symbols
name:
number:
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {

	/*
	Character_Constants 	Escape_Sequence	    ASCII_Value(%d)
		 alarm      	          \a	            7
		 backspace	              \b	            8
		 form feed	              \f               	12
		 newline	              \n	            10
		 carriage return	      \r             	13
		 horizontal tab	          \t               	9
		 vertical tab	          \v	            11
		 single quote             \'	            39
		 backslash	              \\	            92
		 double quote	          \"	            34
		 question mark	          \?	            63
	*/

	printf("Welcome\vto ?C?\?\n");// "\n" means a new line, "\t" means a tab(6 spaces)
	printf("this is \"wayne\"\\Jun\n");// \" means " use in strings
	printf("this is \"wayne\"\n");

	/*

		-variable: container for values
	 ***************** data type:*******************************
		 1. integer value
		 (char:1 byte = 8 bit; short = 2 byte; int:4 byte; long:8 byte)
		 2. floating point value
		 (float = 4 byte; double = 8 byte)
		 more info:
		 https://intro2c.sdds.ca/B-Computations/types
	***********************************************************
		-how to name variable:
		 1.must be: a-z/A-Z/0-9/underscore
		 2.cannot start with digit
		 3.cannot be keyword


	-declare variable:
	data type + variable name

	*/
	const int MAX_AGE = 100;  // 声明一个整型常量 MAX_AGE，值为 100 cannot be modified
	// Declares a constant integer MAX_AGE with a value of 100

	printf("Max age is %d\n", MAX_AGE);  // 输出: Max age is 100
	// Output: Max age is 100

	int num = 2;
	char ch;/*integral types:
			  1. char：store characters (such as letters or symbols),
			  but it actually stores the ASCII value of the character, with a size of 1 byte.
			  2. int：store integers, typically with a size of 4 bytes.
			  */

	double average;
	float pi = 3.14159f;
	double largePi = 3.141592653589793;/*Floating-point types：
							1. float:store floating-point numbers (decimal values) and
							typically occupies 4 bytes, with a precision of about 6-7 digits.
							2. double:more precise, 8 bytes, 15-16 digits.
							*/

	printf("Float value: %f\n", pi);  // float conversion specifier: %f ; Output: Float value: 3.141590
	printf("Double value: %.15lf\n", largePi);// Output: Double value: 3.141592653589793

	num = 5;
	average = 2.4467;
	ch = 'c';



	printf("num=%d\n", num);/*conversion specifier : %d (short) int (16bit / 2byte memory);
	long int "%ld" (32bit); long long int "%lld" (64bit same as double)
	*/
	printf("average=%lf\n", average);//double CS: %lf
	printf("average = %.2lf \n", average);
	printf("ch=%c\n", ch);//character CS: %c
	printf("ch=%d\n", ch);/*When a character is printed using %d, it outputs the integer value corresponding
	to the character's ASCII code. In this case, 'c' has an ASCII value of 99, so the output will be:99
	*/


	int age;
	printf("Please Enter Your Age: ");
	scanf("%d", &age);//form: scanf(format, address); prefix & to refer to the 'address of' of a variable.
	printf("Your age is %d\n", age);
	printf("5 %% 2 is %d\n", 5 % 2);
	printf("5 * 2 is %d\n", 5 * 2);
	printf("5 / 2 is %d\n", 5 / 2);

	num = 5;//assignment operator(赋值): =
	int sum = 2 + num * 3;
	/*  Operands(variables / constents..) and operators(+-*% ...), form an instruction or expression
	 -binary operation refers to two operands(+-*除%);
	 -unary operation refers to one operand(+ or -, 正负)
	*/

	printf("the sum is %d\n", sum);//form:  printf(format, expression);

	int ro;
	ro = sum == num;
	printf("%d == %d yields %d\n", sum, num, ro);// output: 17 == 5 yields 0
	/* 6 relational operations: == < <= > >= !=
	  -yields 1 for true, 0 for false.
	  -The value of a relational expression is of type int.
	*/

	sum = sum = 10;
	printf("the sum is %d\n", sum);//10

	sum += 5;// sum = sum + 5;
	printf("the sum is %d\n", sum);//15
	sum %= 3;
	printf("the sum is %d\n", sum);//0
	printf("Prefix:  %d\n", ++sum);//1
	printf("         %d\n", sum);//1
	printf("Postfix: %d\n", sum++);//1, means sum+1 for next statement
	printf("         %d\n", ++sum);//3	
	/* shorthand assignment:
	  - binary operators:
	  a.+=  b.-=  c.*=  d./=  e.%=
	  (%=for integral operands only, int and char; not for floating-point)
	  - unary operators:
	  ++i; i++; --i; i--
	  (prefix operator changes value before use, postfix operator changes the value after use) */
	int i = 0;
	printf("i=%d\n", i++);
	printf("i=%d\n", i);


	num = 5;
	double c = num / 2;// 2 operands both int make num/2 a integral operation, result:2, store in dbl:2.0
	printf("c=%.2lf\n", c);//2.00

	char digit = '6';
	printf("digit as a char: %c\n", digit);
	printf("digit as an int: %d\n", digit);//'6'(ASCII 54)
	digit = digit - '0';//'0'(ASCII 48), 54-48, char can store int for 1byte(2^8, -128~127)
	printf("new digit as an int: %d\n", digit);//output 6

	char lower = 't';
	printf("%c\n", lower);
	printf("%c\n", lower - ('a' - 'A'));
	char upper = 'J';
	printf("%c\n", upper);
	printf("%c\n", upper + ('a' - 'A'));/*ASCII Value : 'A' - 'Z' = 65 - 90 'a' - 'z' = 97 - 122
	In the ASCII system, lower&uppercase letters are 32 units apart, by +/- 32, can convert between lowercase and uppercase letters.
	*/


	return 0;
}