#include <stdio.h>
#include <assert.h>
typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;

int main(void){
    char inputname[80];
    char outputname[80];
    scanf("%s %s", inputname, outputname);
    FILE *filein = fopen(inputname, "rb");
    assert(filein != NULL);
    FILE *fileout = fopen(outputname, "wt");
    assert(fileout != NULL);
    Student temp;
    fprintf(fileout, "<table border=\"1\">\n");
    fprintf(fileout, "<tbody>\n");
    while(fread(&temp, sizeof(Student), 1, filein)){
        fprintf(fileout, "<tr>\n");
        fprintf(fileout, "<td>%s</td>\n", temp.name);
        fprintf(fileout, "<td>%d</td>\n", temp.id);
        fprintf(fileout, "<td>%s</td>\n", temp.phone);
        fprintf(fileout, "<td>%f, %f, %f, %f</td>\n", temp.grade[0], temp.grade[1], temp.grade[2], temp.grade[3]);
        fprintf(fileout, "<td>%d, %d, %d</td>\n", temp.birth_year, temp.birth_month, temp.birth_day);
        fprintf(fileout, "</tr>\n");

    }
    fprintf(fileout, "</tbody>\n");
    fprintf(fileout, "</table>\n");
    return 0;
}