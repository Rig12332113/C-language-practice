#include "count_day.h"
void count_day(int year, int day, int month, int results[7]){
    int leap;
    leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    int days = 0;
    switch(month){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                days = 31;
                break;
            case 4: case 6: case 9: case 11:
                days = 30;
                break;
            case 2:
                if (leap)
                    days = 29;
                else
                    days = 28;
                break;
    }
    int total = 0;
    while(month > 1){
        switch(month - 1){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                total += 31;
                break;
            case 4: case 6: case 9: case 11:
                total += 30;
                break;
            case 2:
                if (leap)
                    total += 29;
                else
                    total += 28;
                break;
        }
        month--;
    }
    for(int i = 0; i < days; i++)
        results[(day + total + i) % 7]++;
}