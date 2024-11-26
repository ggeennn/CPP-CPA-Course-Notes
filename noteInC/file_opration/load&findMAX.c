#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10
struct product {
	int id;
	double price;
};
void loadProducts(FILE* fp, struct product prds[], int* size) {
	int i = 0;
	if (fp != NULL)
	{
		while (fscanf(fp, "%d,%lf", &prds[i].id, &prds[i].price) == 2 && i < *size)
		{
			printf("id=%d and price=%lf\n", prds[i].id, prds[i].price);
			i++;
			printf("that's it\n");

		}
		*size = i;
		//4- close the file
		fclose(fp);

	}
	else
	{
		printf("Failed to open file\n");
	}

}

void printProduct(struct product prds[], int size) {
	int i;
	printf("%-6s\t%-8s\n", "ID", "PRICE");
	for (i = 0; i < size;i++) {
		printf("%06d\t%8.2lf\n",prds[i].id,prds[i].price);
	}
}

void findMaxPrice(struct product prds[], int size,double *max,int *id){
	*max = prds[0].price;
	*id = prds[0].id;
	for (int i = 1; i < size; i++) {
		if (prds[i].price > *max) {
			*max = prds[i].price;
			*id = prds[i].id;
		}
	}
}

int main(void)
{

	struct product products[SIZE];


	FILE* fp = NULL;

	fp = fopen("test.txt", "r");
	int size = 10;
	loadProducts(fp, products,&size);
	printProduct(products, size);

	int maxid;
	double maxprice;
	findMaxPrice(products, size, &maxprice, &maxid);
	printf("max price = %lf, max id = %d\n",maxprice,maxid);
	printf("done\n");
	return 0;
}
