#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Student {
	int id;
	double grade;
};
struct Date {
	int day;
	int month;
	int year;
};
struct Student2 {
	int id;
	double grade;
	struct Date birthday;
};

void printArray(char a[], int s) {
	int i;
	for (i = 0; i < s; i++) {
		printf("%c", a[i]);
	}
	printf("\n");
}

int main(void)
{
	char str[] = { 'C','S','t','r','i','n','g','!' };
	char str1[] = { 'C','S','t','r','i','n','g','!','\0'};
	char str2[] = "CString!"; //9 elements
	char str3[9] = { '\0' };

	printArray(str, 8);
	//printf("%s",str)
	printf("%s", str1);//cstring can use %s to printout directly!!!!
	printf("%s", str2);
	//printf("%s", str); -> run time erro!!!! not cstring

	printf("enter a value for str3: ");
	scanf("%8s", str3);/* hit enter = \0 :a null terminator      为什么不用&？因为字符串（char 数组）本身就是一个指向首字符的指针
	   only store the size of array-1
	   超过size会有runtime error */
	printf("the value of str3 is %s", str3);


	struct Student s1;//only declare
	s1.id = 1234;
	s1.grade = 82.5;
	printf("s1 with id =%d and grade =%lf\n", s1.id, s1.grade);

	struct Student s2 = {555,90.7};//use initializer -> 等于号
	printf("s2 with id =%d and grade =%lf\n", s2.id, s2.grade);

	struct Student student[3] = {
		{333,62.2},
		{441,88.3},
		{121,78.2}
	};
	for (int i = 0; i < 3; i++) {
		printf("s with id =%d and grade =%lf\n", student[i].id, student[i].grade);
	}

	struct Date d1 = { 28,10,2024 };
	printf("today date is %d/%d/%d\n", d1.day, d1.month, d1.year);

	struct Student2 s3 = { 111,77,30,9 };//year没有值，输出0，初始化时嵌套结构的花括号可以省略
	printf("%d\n", s3.birthday.year);

	return 0;
}