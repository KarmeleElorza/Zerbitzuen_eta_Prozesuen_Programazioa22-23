#include <stdio.h>
int main(int argc, char *argv[]){
    printf("Hello World\n");
    printf("SArtu zenbaki bat\n");
    int zenb = 0;
    scanf("%i",&zenb);
    printf("Sartutako zenbakia: %i\n", zenb);
    printf("Sartutako zenbakiaren direkzioa: %p\n", &zenb);
    int *punteroa = &zenb;
    *punteroa = 7;
    printf("Aldatu egin da zenbakia: %i\n", zenb);
    return 0;
}