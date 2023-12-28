/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero: 
Päivämäärä: 30.1.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L3T2.c
*/

#include <stdio.h>
#include <stdlib.h>

#define ARVO 30

int lueTiedot(char *pNimiL);
void kirjoitaTiedot(char *pNimiK, int summa);

int main(void)  {
    int summa;
    char aNimiL[ARVO];
    char aNimiK[ARVO];

    printf("Tämä ohjelma laskee tiedostossa olevien lukujen summan.\n");
    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", aNimiL);

    summa = lueTiedot(aNimiL);
    printf("Tiedosto '%s' luettu, lukujen summa oli %d.\n", aNimiL, summa);
    printf("\n");

    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", aNimiK);
    
    kirjoitaTiedot(aNimiK, summa);
    printf("\n");

    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

int lueTiedot(char *pNimiL)   {
    int rivi;
    FILE *tiedosto;
    int summa = 0;

    if ((tiedosto = fopen(pNimiL, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    } else  {
        tiedosto = fopen(pNimiL, "r");

        while (fscanf(tiedosto, "%d", &rivi) == 1)    {
            summa += rivi;
        }
    fclose(tiedosto);
    }
    return summa;
}

void kirjoitaTiedot(char *pNimiK, int summa) {
    FILE *tiedosto;

    if ((tiedosto = fopen(pNimiK, "w")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    } else  {
        tiedosto = fopen(pNimiK, "w");
        fprintf(tiedosto, "Lukujen summa oli %d.\n", summa);
        fclose(tiedosto);
    }
    printf("Tiedosto '%s' kirjoitettu.\n", pNimiK);
}
