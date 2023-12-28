/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero: 000437136
Päivämäärä: 14.2.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L5T2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KOKO 50

char* kysyTiedosto(void){
    char pTiedostoNimi[KOKO];
    char *ptr;

    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", pTiedostoNimi);
    ptr = pTiedostoNimi;
    return ptr;
}

void lueTiedosto(char* pNimi)   {
    char aRivi[KOKO], pJoukkue[KOKO], *p1, *p2;
    FILE *tiedosto;
    int i = 101, x, y;

    if ((tiedosto = fopen(pNimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    
    printf("Tiedosto '%s' luettu.\n", pNimi);

    while ((fgets(aRivi, KOKO, tiedosto)) != NULL)    {
        if ((p1 = strtok(aRivi, ";")) == NULL) {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", aRivi);
            exit(1);
        }
        if ((p2 = strtok(NULL, "\n")) == NULL) {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", aRivi);
            exit(1);
        }
        if (atoi(p2) < i) {
            y = 0;
            i = atoi(p2);
            for (x = 0; x < strlen(p1); x++)    {    
                pJoukkue[x] = p1[x];
                y++;
            }
            pJoukkue[y] = '\0';
        }
    }
    fclose(tiedosto);
    printf("Pienin pistemäärä oli joukkueella '%s' %d pisteellä.\n", pJoukkue, i);
    return;
}

int main(void)  {
    char *aNimi;

    aNimi = kysyTiedosto();
    lueTiedosto(aNimi);
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}