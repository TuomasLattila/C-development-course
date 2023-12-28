#include <stdio.h>

int main(void)  {
    int luku1, luku2;
    int luku3 = 10;

    printf("Anna ensimmäinen kokonaisluku: ");
    scanf("%d", &luku1);
    printf("Anna toinen kokonaisluku: ");
    scanf("%d", &luku2);

    printf("%d * %d = %d\n", (luku1+1), luku2, ((luku1+1)*luku2));
    printf("(%d / %d) - %d = %d\n", luku1, luku2, luku3, ((luku1/luku2)-luku3));
    printf("%d %% %d = %d\n", luku1, (luku2-1), (luku1%(luku2-1)));
    return(0);

}