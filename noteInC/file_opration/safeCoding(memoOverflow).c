// Insufficient Memory
// table_plus.c

#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;
    char label [14];
    int n;
    double price;
    char c;

    fp = fopen("spring.txt","r");

    if (fp != NULL)
    {
        printf("    Spring Items\n"
            "    ============\n\n"
            "No Description  Price\n"
            "---------------------\n");

        while (fscanf(fp,"%d;%13[^;]%c", &n, label, &c) == 3)
        {
            if (c == ';')
            {
                fscanf(fp,"%lf\n", &price);
            }
            else
            {
                fscanf(fp, "%*[^;];%lf%*c", &price);
            }

            printf("%2d %-13s%5.2lf\n", n, label, price);
        }

        fclose(fp);
    }

    return 0;
}