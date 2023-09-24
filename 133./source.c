#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct string_count {
        char seen[80];
        int count;
};
int compare(const void *a, const void *b){
    if ((*(struct string_count *)a).count > (*(struct string_count *)b).count)
        return 1;
    else if ((*(struct string_count *)a).count < (*(struct string_count *)b).count)
        return -1;
    else{
        return strcmp((*(struct string_count *)a).seen, (*(struct string_count *)b).seen);
    }
}
int num = 0;
int compare_and_add(char *string, struct string_count strings[]) {
    int found = 0;
    for (int i = 0; i < num && !found; i++){
        if (strcmp(string, strings[i].seen) == 0){
            strings[i].count++;
            found = 1;
            return 1;
        }
    } 
    if (!found){
        strcpy(strings[num].seen, string);
        strings[num].count = 1;
        num++;
        return 0;
    }    
}
void sort(struct string_count strings[]) {
    qsort(strings, num, sizeof(struct string_count), compare);
}
void print(struct string_count strings[]) {
    for(int i = 0; i < num; i++)
        printf("%d %s\n",strings[i].count, strings[i].seen);
}
/*int main() {
        struct string_count strings[20];
        int i;
        for( i=0 ; i<20 ; i++ )
                strings[i].count = 0;
        compare_and_add( "This", strings );
        compare_and_add( "is", strings );
        compare_and_add( "an", strings );
        compare_and_add( "apple,", strings );
        compare_and_add( "and", strings );
        compare_and_add( "this", strings );
        compare_and_add( "is", strings );
        compare_and_add( "a", strings );
        compare_and_add( "book.", strings );
        sort( strings );
        print( strings );
        return 0;
}*/