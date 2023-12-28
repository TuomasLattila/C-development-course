/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero: 
Päivämäärä: 31.1.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L3T5.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void siemenAlustus(void) {
    int iSiemen;

    printf("Anna satunnaisgeneraattorin siemenluku: ");
    scanf("%d", &iSiemen);
    srand(iSiemen);
}

int kysyMaara(void) {
    int x;
    printf("Anna arvottavien merkkien määrä: ");
    scanf("%d", &x);
    return x;
}

char* generaattori(int iMaara)   {
    char* cMerkkiJono = malloc(30);
    int i;
    int iLaskuri = 0;

    for (i = 0; i < iMaara; i++)    {
        int iArvo = ((rand() % 95) + 32);
        char cMerkki = iArvo;
        if (isalpha(cMerkki) || isdigit(cMerkki) || isspace(cMerkki))  {
            cMerkkiJono[iLaskuri] = cMerkki;
            iLaskuri++;
        }
    }
    return cMerkkiJono;
}

void tarkistaC(char *cJono)   {
    int j;
    int vastaus = 0;

    for (j = 0;cJono[j] != '\0'; j++)    {
        if (cJono[j] == 'c'){
            vastaus = 1;
        }
    }
    if (vastaus == 1)   {
        printf("Merkkijonosta löydettiin merkki 'c'.\n");
    }   else    {
        printf("Merkkijonossa ei ollut merkkiä 'c'.\n");
    }
}

int main(void)  {
    printf("Tämä ohjelma luo satunnaisia merkkijonoja.\n");
    siemenAlustus();
    int iMaara = kysyMaara();
    printf("\n");
    char* cJono = generaattori(iMaara);

    tarkistaC(cJono);
    printf("Generoitiin merkkijono '%s', jossa on %ld merkkiä.\n", cJono, strlen(cJono));
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

