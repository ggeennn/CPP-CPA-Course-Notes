#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000
struct medalCount{
	char country[50];
	int year;
	char season[10];	// Season: "Summer" or "Winter"
	int gold;
	int silver;
	int bronze;
	int total;
};

int strCmp(const char* s1, const char* s2) {
	while (*s1 && *s2) {
		if (*s1 != *s2) {
			return 0;
		}
		s1++;
		s2++;
	}
	return *s1 == '\0' && *s2 == '\0';
}

void strCopy(const char* src,char* dest) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';  // 确保字符串终止
}

void readMedalFile(const char* filename, struct medalCount* data, int* size, int year, const char* season) {
	FILE* fp = NULL;
	fp = fopen(filename, "r");
	int i = 0;
	char ch;
	char edition[50];
	char ssn[10];
	struct medalCount temp;
	if (fp != NULL) {
		//skip 1st row
		do {
			ch = fgetc(fp);
		} while (ch != '\n' && ch != EOF);
		//2nd row start reading
		while (fscanf(fp, "%[^,],%*d,%d,%[^,],%*[^,],%d,%d,%d,%d",
			edition,&temp.year, &temp.country, &temp.gold, &temp.silver, &temp.bronze,&temp.total) == 7) {
			sscanf(edition, "%*d %s %*s", ssn);
			if (temp.year == year && strCmp(season, ssn)) {
				strCopy(temp.country, data[i].country);
				data[i].year = temp.year;
				strCopy(ssn, data[i].season);
				data[i].gold = temp.gold;
				data[i].silver = temp.silver;
				data[i].bronze = temp.bronze;
				data[i].total = temp.total;
				i++;
			}
		}
		*size = i;
		fclose(fp);
	}
	else {
		printf("invalid filename, pls try again\n");
		*size = 0;
	}
}



void topSilver(struct medalCount* data, int size, struct medalCount* result);

int main(void)
{
	struct medalCount data[SIZE];  //data array 超size没有处理
	char file[] = "Olympic_Games_Medal_Tally.csv";
	int size, year;
	char season[20];
	printf("pls enter the year: ");
	scanf("%d", &year);
	printf("type in: summer/winter ? ");
	scanf("%s", season);
	readMedalFile(file, data, &size, year, season);

	//test read
	for (int i = 0; i < size; i++) { 
		printf("Country: %s, Year: %d, Season: %s, Gold: %d, Silver: %d, Bronze: %d, Total: %d\n", data[i].country, data[i].year, data[i].season, data[i].gold, data[i].silver, data[i].bronze, data[i].total); }


	return 0;
}


