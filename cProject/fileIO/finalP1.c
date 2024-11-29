#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 定义结构体
struct medalCount {
	char country[50];
	int year;
	char season[10];  // "Summer" 或 "Winter"
	int gold;
	int silver;
	int bronze;
	int total;
};
void readMedalFile(const char* filename, struct medalCount* data, int* size, int year, const char* season) {
	FILE* fp = NULL;
	char line[300];  // buffer
	int i = 0;
	int c = 0; //for investigating read process
	fp = fopen(filename, "r");
	if (fp != NULL) {
		// 跳过第一行标题
		fgets(line, sizeof(line), fp);

		// 逐行读取文件
		while (fgets(line, sizeof(line), fp)) {
			struct medalCount temp;

			// 解析每行数据
			sscanf(line, "%*[^,],%*d,%d,%[^,],%*[^,],%d,%d,%d,%d", &temp.year, temp.country, &temp.gold, &temp.silver, &temp.bronze, &temp.total);  //why can read line NO.810? check demo
			
			/* code in commemt, for investigating read process：
			printf("Read line: Year: %d, Country: %s, Gold: %d, Silver: %d, Bronze: %d\n", temp.year, temp.country, temp.gold, temp.silver, temp.bronze);
			c++; 
			printf("after header file line NO. %d\n", c);
			*/

			// 判断年份和赛季是否匹配
			if (temp.year == year && strstr(line, season) != NULL) {
				strcpy(data[i].country,temp.country);
				data[i].year = temp.year;
				strcpy(data[i].season,season);
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
		printf("Error: Could not open file.\n");
	}
}

// 查找银牌最多的记录
void topsilver(struct medalCount* data, int size, int* maxsilver, char* maxcountry) {
	int i;
	for (i = 0; i < size; i++) {
		if (data[i].silver > *maxsilver) {
			*maxsilver = data[i].silver;
			strcpy(maxcountry, data[i].country);  // 使用当前国家名开始
		}
		else if (data[i].silver == *maxsilver) {
			// 拼接具有相同银牌数的国家
			strcat(maxcountry, " ");
			strcat(maxcountry, data[i].country);
		}
	}
}

// 主函数
int main(void) {
	struct medalCount data[100]; // 假设最多存储100条记录
	struct medalCount result;
	char file[] = "Olympic_Games_Medal_Tally.csv";
	int size, year, i;
	char season[20];
	int maxSilver = 0;
	char maxCountry[100];

	//still need to enhance input check process
	printf("Please enter the year: ");
	scanf("%d", &year);
	do {
		printf("Type in: 1(summer) / 2(winter) ? ");
		scanf("%d", &i);
		if (i == 1) {
			strcpy(season, "Summer");
		}
		else if (i == 2) {
			strcpy(season, "Winter");
		}
		else {
			printf("Invalid input, please tey again.\n");
		}
	}while(i != 1 && i != 2);


	// 读取文件
	readMedalFile(file, data, &size, year, season);

	if (size > 0) {
		printf("Total records found: %d\n", size);

		// 查找银牌最多的记录
		topsilver(data, size, &maxSilver, maxCountry);

		// 输出结果
		printf("Country(ies) with most silver medals:\n");
		printf("Year:\t%d\nSeason:\t%s\nCountry(ies): %s\n", year, season, maxCountry);
		printf("Silver medal number:\t%d\n",maxSilver);
	}
	else {
		printf("No records found for the specified year and season.\n");
	}
	printf("if loop pick data %d times\n", size); //testing
	return 0;
}
