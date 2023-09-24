#include<stdio.h>
#include<stdlib.h>
#define size 200
#define bigsize 65537
int count[bigsize] = {0};
int main()
{
  char filename[size];
  int a = 0;
  short int num = 0;
  scanf("%s", filename);
  FILE *fp = fopen(filename, "rb");
  fread(&a, sizeof(int), 1, fp);
  for (int i = 0; i < a; i++){
    fread(&num, sizeof(short int), 1, fp);
    count[num + 32768]++;
  }
  fclose(fp);
  int max = 0, index = 0;
  for (int i = 0; i < 65536; i++)
    if (count[i] >= max){
      index = i;
      max = count[i];
    }
  printf("%d\n%d\n", index - 32768, max);
  return 0;
}