/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero: 000437136
Päivämäärä: 24.1.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L2T3.c
*/

#include <stdio.h>
#include <string.h>

int main(void)  {
    char cMerkki;
    char sJono[15];
    int i;
    int iSumma = 0;

    printf("Anna merkki: ");
    scanf("%c", &cMerkki);
    printf("Merkki '%c' on ASCII-taulukon mukaan lukuna %d.\n", cMerkki, cMerkki);
    
    printf("Anna merkkijono: ");
    scanf("%s", sJono);
    for (i = 0; i < strlen(sJono); i++) {
        iSumma += sJono[i];
    }
    printf("Merkkijonon '%s' merkkien summa on %d.\n", sJono, iSumma);
    return(0);
}