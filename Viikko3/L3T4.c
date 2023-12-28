/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero: 000437136
Päivämäärä: 31.1.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L3T4.c
*/

#include <stdio.h>

#define ARVO 60

int tarkistus(char *pNimi);
char* yhdistys(char *pNimi1, char *pNimi2);

int main(void)  {
    char aNimi1[ARVO];
    char aNimi2[ARVO];
    int iPituus1;
    int iPituus2;

    printf("Anna ensimmäinen merkkijono (max 30 merkkiä): ");
    fgets(aNimi1, 60, stdin);

    printf("Anna toinen merkkijono (max 30 merkkiä): ");
    fgets(aNimi2, 60, stdin);

    iPituus1 = tarkistus(aNimi1);
    iPituus2 = tarkistus(aNimi2);
    
    if ((iPituus1+iPituus2) > 60)   {
        printf("Merkkijonojen yhteenlaskettu pituus on liian pitkä ohjelman muistialueelle.\n");
    }   else    {
        printf("Yhdistetty merkkijono on:\n");
        printf("'%s'\n", yhdistys(aNimi1, aNimi2));
    }

    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

int tarkistus(char *pNimi)  {
    int iPituus = 0;

    while (*pNimi != '\n')    {
        iPituus++;
        pNimi++;
    }
    return iPituus;
}

char* yhdistys(char *pNimi1, char *pNimi2)   {
    int i = 0;
    int j = 0;

    while (pNimi1[i] != '\n') {
        i++;
    }
    while (pNimi2[j] != '\n') {
        pNimi1[i] = pNimi2[j];
        i++;
        j++;
    }
    return pNimi1;
}