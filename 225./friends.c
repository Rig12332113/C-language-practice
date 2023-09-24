#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct person {
    unsigned int id;
    char name[32];
}Person;
typedef struct friends {
    unsigned id1;
    unsigned id2;
}Friends;
int main(void){
    FILE *filein = fopen("friends", "rb");
    int people_num = 0;
    fread(&people_num, sizeof(int), 1, filein);
    Person *people = (Person *)malloc(sizeof(Person) * people_num);
    for(int i = 0; i < people_num; i++){
        fread(&people[i], sizeof(Person), 1, filein);
    }
    int friend_num = 0;
    fread(&friend_num, sizeof(int), 1, filein);
    Friends *friend = (Friends *)malloc(sizeof(Friends) * friend_num);
    for(int i = 0; i < friend_num; i++){
        fread(&friend[i], sizeof(Friends), 1, filein);
    }
    char name1[32], name2[32];
    int ID1 = 0, ID2 = 0;
    while(scanf("%s%s", name1, name2) == 2){
        if (strcmp(name1, "end") == 0)
            break;
        for (int i = 0; i < people_num; i++){
            if (strcmp(people[i].name, name1) == 0)
                ID1 = people[i].id;
            else if (strcmp(people[i].name, name2) == 0)
                ID2 = people[i].id;
        }
        int found = 0;
        for(int i = 0; i < friend_num; i++){
            if ((friend[i].id1 == ID1 && friend[i].id2 == ID2) || (friend[i].id1 == ID2 && friend[i].id2 == ID1)){
                found = 1;
                break;
            }
        }
        if (found)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}