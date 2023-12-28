#include <stdio.h>

void valinat(char* pSana)  {
    printf("Anna valinta: ");
    scanf("%s", pSana);
    return;
}

int main (void) {
    char* pSana;
    char sana[10];
    valinat(pSana);

    printf("%ld", sizeof(sana));
    return(0);
}