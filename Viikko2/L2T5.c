/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero: 
Päivämäärä: 24.1.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L2T5.c
*/

#include <stdio.h>

int main(void)  {
    int iLuku;
    int iValinta;
    int iLuku1;
    int iLuku2;

    printf("Anna kokonaisluku: ");
    scanf("%d", &iLuku);
    printf("\n");

    do  {
        printf("Valikko:\n");
        printf("1) Lisää lukuun\n");
        printf("2) Vähennä luvusta\n");
        printf("0) Lopeta\n");
        printf("Valintasi: ");
        scanf("%d", &iValinta);
        printf("\n");

        if (iValinta == 0)  {
            printf("Lopetetaan.\n");
            printf("\n");
            break;
        } else if (iValinta == 1)   {
            printf("Anna lukuun lisättävä kokonaisluku: ");
            scanf("%d", &iLuku1);
            iLuku = (iLuku + iLuku1);
            printf("Luku on nyt %d.\n", iLuku);
        } else if (iValinta == 2)   {
            printf("Anna luvusta vähennettävä kokonaisluku: ");
            scanf("%d", &iLuku2);
            iLuku = (iLuku - iLuku2);
            printf("Luku on nyt %d.\n", iLuku);
        } else  {
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
        printf("\n");
    }   while (iValinta != 0);
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}
