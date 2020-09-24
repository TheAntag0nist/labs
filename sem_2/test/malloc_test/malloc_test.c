#include <stdio.h>
#include <stdlib.h>

int main(void){
    const int blockCount = 1024;
    const int blockSize = 1024*1024;
    char **buf;

    printf("Hit something...\n");
    getchar();
    buf = (char**)malloc(blockCount*sizeof(char*));
    for (int i=0; i<blockCount; i++){
        buf[i] = (char*)malloc(blockSize*sizeof(char));
    }

    printf("Memory allocated\n");
    printf("Hit something...\n");
    getchar();

    for (int i=0; i<blockCount; i++){
        free(buf[i]);
    }
    free(buf);

    printf("Hit something...\n");
    printf("Memory freed\n");
    getchar();
  return 0;
}