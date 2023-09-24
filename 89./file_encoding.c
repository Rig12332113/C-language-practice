#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main(void){
    FILE *filein = fopen("test", "r");
    FILE *fileout = fopen("test.enc", "w");
    assert(filein != NULL);
    int key = 0;
    scanf("%d", &key);
    char buffer[65536];
    int size = 0;
    while((size = fread(buffer, sizeof(char), 65536, filein)) != 0){
        for(int i = 0; i < size; i++){
            buffer[i] = buffer[i] ^ key;
        }
        fwrite(buffer, sizeof(char), size, fileout);
    }
    fclose(filein);
    fclose(fileout);

    return 0;
}
