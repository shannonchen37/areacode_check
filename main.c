#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int readDate();
int Search(char *, int);
void Show(int);

struct Code {
  char province[20];     // 省
  char abbreviation[4];  // 省的简称
  char city[24];         // 市
  int areacode;          // 区号
  int zipcode;           // 邮编
};

struct Code codes[5000];
int n;

int main() {
  char s[22];
  int index = -1;
  n = readDate();
  printf("请输入要查询的城市：");
  scanf("%s", s);
  index = Search(s, n);
  if (index >= 0)
    Show(index);
  else
    printf("没有该城市，或者城市输入有误。\n");
  return 0;
}

int readDate()  // 读取数据，返回人数
{
  FILE *infile = fopen("./change.txt", "r");  // 以输入的方式打开文件
  if (!infile)                                // 测试是否成功打开
  {
    printf("open error!\n");
    exit(1);
  }

  int i = 0;
  fscanf(infile, "%s %s %s %d %d", codes[i].province, codes[i].abbreviation,
         codes[i].city, &codes[i].areacode, &codes[i].zipcode);
  while (!feof(infile)) {
    ++i;
    fscanf(infile, "%s %s %s %d %d", codes[i].province, codes[i].abbreviation,
           codes[i].city, &codes[i].areacode, &codes[i].zipcode);
  }
  fclose(infile);
  return i;
}

int Search(char *s, int n)  // 顺序查找，待改进
{
  int i;
  for (i = 0; i < n; i++)
    if (strcmp(codes[i].city, s) == 0) return i;
  return -1;
}

void Show(int i) {
  printf("省份：%s\n", codes[i].province);
  printf("简称：%s\n", codes[i].abbreviation);
  printf("城市：%s\n", codes[i].city);
  printf("区号：0%d\n", codes[i].areacode);
  printf("邮政编码：%d\n", codes[i].zipcode);
}