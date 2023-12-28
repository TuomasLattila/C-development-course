/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero: 
Päivämäärä: 21.2.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L6T2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KOKO 30

typedef struct tiedot   {
    char aTehtava[5];
    int iMaara;
    struct tiedot *pSeuraava;
} TIEDOT;

void kysyTiedosto(char *pNimi)  {
    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", pNimi);
    return;
}

TIEDOT* varaaMuisti(void)    {
    TIEDOT *pUusi;
    if ((pUusi = (TIEDOT*)malloc(sizeof(TIEDOT))) == NULL)  {
        perror("Muistin varaus epäonnistui");
        exit(0);
    }
    pUusi->pSeuraava = NULL;
    return(pUusi);
}

TIEDOT* lueTiedosto(TIEDOT *pA, char *pNimi)  {
    char aRivi[KOKO], *p1, *p2;
    FILE *tiedosto;
    TIEDOT *pUusi, *ptr;

    if ((tiedosto = fopen(pNimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    } 
    while (fgets(aRivi, 30, tiedosto) != NULL)  {
        if ((p1 = strtok(aRivi, ";")) == NULL)  {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", aRivi);
            exit(1);
        }

        if ((p2 = strtok(NULL, ";")) == NULL)  {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", aRivi);
            exit(1);
        }
        pUusi = varaaMuisti();
        strcpy(pUusi->aTehtava, p1);
        pUusi->iMaara = atoi(p2);

        if (pA == NULL) {
            pA = pUusi;
        } else {
            ptr = pA;
            while (ptr->pSeuraava != NULL) {
                ptr = ptr->pSeuraava;
            }
            ptr->pSeuraava = pUusi;
        }
    }
    fclose(tiedosto);
    printf("Tiedosto '%s' luettu linkitettyyn listaan.\n", pNimi);
    return (pA);
}

void tulostaTiedot(TIEDOT *pA)  {
    TIEDOT *ptr = pA;
    printf("Tehtäviä tehtiin seuraavasti:\n");
    while (ptr != NULL) {
        printf("Tehtävän %s teki %d opiskelijaa.\n", ptr->aTehtava, ptr->iMaara);
        ptr = ptr->pSeuraava;
    }
    return;
}

void muistinVapautus(TIEDOT *pA)  {
    TIEDOT *ptr; 
    ptr = pA;
    while (ptr != NULL) {
        pA = ptr->pSeuraava;
        free(ptr);
        ptr = pA;
    }
    printf("Muisti vapautettu.\n");
    return;
}

int main(void)  {
    TIEDOT *pAlku = NULL;
    char pNimi[KOKO];

    kysyTiedosto(pNimi);
    pAlku = lueTiedosto(pAlku, pNimi);
    tulostaTiedot(pAlku);
    printf("\n");
    muistinVapautus(pAlku);
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}
