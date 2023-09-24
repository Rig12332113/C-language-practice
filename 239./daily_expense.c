#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct expense
{
    int year, month, date;
    char cat[80];
    int cost;
}Expense;
int compare(const void *a, const void *b){
    if (((Expense *)a)->year > ((Expense *)b)-> year)
        return 1;
    else if (((Expense *)a)->year < ((Expense *)b)-> year)
        return -1;
    else if (((Expense *)a)->month > ((Expense *)b)-> month)
        return 1;
    else if (((Expense *)a)->month < ((Expense *)b)-> month)
        return -1;
    else if (((Expense *)a)->date > ((Expense *)b)-> date)
        return 1;
    else if (((Expense *)a)->date < ((Expense *)b)-> date)
        return -1;
    else 
        return strcmp(((Expense *)a)->cat, ((Expense *)b)-> cat);
}
int main(void){
    int num = 0;
    Expense data[50000];
    while(scanf("%d%d%d%s%d", &data[num].year, &data[num].month, &data[num].date, data[num].cat, &data[num].cost) != EOF){
        int duplicate = 0;
        for(int i = 0; i < num && !duplicate; i++){
            if (data[num].year == data[i].year && data[num].month == data[i].month
                && data[num].date == data[i].date && strcmp(data[num].cat, data[i].cat) == 0){
                data[i].cost += data[num].cost;
                duplicate = 1;
            }
        }
        if (!duplicate)
            num++;
    }
    qsort(data, num, sizeof(Expense), compare);
    for(int i = 0; i < num; i++){
        printf("%d %d %d %s %d\n", data[i].year, data[i].month, data[i].date, data[i].cat, data[i].cost);
    }
    return 0;
}