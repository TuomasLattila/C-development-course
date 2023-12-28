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

Tehtävä L2T2.c
*/

#include <stdio.h>

#define MAX 10
#define MIN 3

int main(void)  {
    int iluku;
    int i, x;

    printf("Anna kokonaisluku väliltä 3 - 10: ");
    scanf("%d", &iluku);
    printf("\n");

    if ((iluku <= MAX) && (iluku >= MIN))    {
        for (i = 0; i < iluku; i++) {
            for (x = 0; x < iluku; x++)  {
                printf("*");
            }
            printf("\n");
        }
    } else  {
        printf("Antamasi luku ei ole määritellyllä välillä.\n");
    }
    return(0);
}
