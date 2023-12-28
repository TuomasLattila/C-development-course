#include <stdio.h>

int main(void)  {
    char merkki[1];
    char merkkijono[20];
    
    printf("Anna merkki: ");
    scanf("%s", merkki);
    printf("Annoit merkin '%s'.\n", merkki);

    printf("Anna korkeintaan 20 merkkiä pitkä merkkijono: ");
    scanf("%s", merkkijono);
    printf("Annoit merkkijonon '%s'.\n", merkkijono);
    return(0);
}