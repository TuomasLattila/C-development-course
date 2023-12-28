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

Tehtävä L5T4.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define KOKO 30

typedef struct tiedot    {
    char aMerkkijono[KOKO];
    int iSumma;
} TIEDOT;

void kysyTiedosto(char* pNimi, int i)  {
    if (i == 1) {
        printf("Anna luettavan tiedoston nimi: ");
        scanf("%s", pNimi);
    } if (i == 2) {
        printf("Anna kirjoitettavan tiedoston nimi: ");
        scanf("%s", pNimi);
    }
    return;
}

int valikko(void)   {
    int iValinta;
    printf("Valitse haluamasi toiminto:\n");
    printf("1) Lue tiedosto\n");
    printf("2) Laske merkkijonojen summa\n");
    printf("3) Kirjoita tiedosto\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &iValinta);
    return iValinta;
}

TIEDOT *muistinVaraus(TIEDOT *pTaulukko, int iLkm)   {
    if ((pTaulukko = (TIEDOT*)realloc(pTaulukko, iLkm*sizeof(TIEDOT))) == NULL)  {
        perror("muistin varaus epäonnistui");
        exit(1);
    }
    return pTaulukko;
}

int laskuri(char *pMerkkiJono)  {
    int i;
    int iSumma = 0;

    for (i = 0; i < strlen(pMerkkiJono); i++) {
        iSumma += pMerkkiJono[i];
    }
    return iSumma;
}

TIEDOT *lueTiedosto(TIEDOT *pTaulukko, char *pNimi, char* pLkm)   {
    FILE *tiedosto;
    char aRivi[KOKO];
    int iLkm = 0;

    if ((tiedosto = fopen(pNimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    while ((fgets(aRivi, KOKO, tiedosto)) != NULL)  {
        aRivi[strlen(aRivi)-1] = '\0';
        iLkm++;
        pTaulukko = muistinVaraus(pTaulukko, iLkm);
        strcpy(pTaulukko[iLkm-1].aMerkkijono, aRivi);
        pTaulukko[iLkm-1].iSumma = laskuri(aRivi);
    }
    fclose(tiedosto);
    printf("Tiedosto '%s' luettu.\n", pNimi);
    sprintf(pLkm, "%d", iLkm);
    return pTaulukko;
}

void kirjoitaTiedosto(char *pNimi, TIEDOT *pTaulukko, int iLkm)   {
    int i;
    FILE *tiedosto;

    printf("Tiedostoon kirjoitetaan seuraavat arvot:\n");
    printf("Nimi;Arvo\n");
    for (i = 0; i < iLkm; i++) {
        printf("%s;%d\n", pTaulukko[i].aMerkkijono, pTaulukko[i].iSumma);
    }

    if ((tiedosto = fopen(pNimi, "w")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    fprintf(tiedosto, "Nimi;Arvo\n");
    for (i = 0; i < iLkm; i++) {
        fprintf(tiedosto, "%s;%d\n", pTaulukko[i].aMerkkijono, pTaulukko[i].iSumma);
    }
    fclose(tiedosto);
    printf("Tiedosto '%s' kirjoitettu.\n", pNimi);
    return;
}

int main(void)  {
    TIEDOT *pTaulukko = NULL;
    char pNimi1[KOKO], pNimi2[KOKO], pLkm[KOKO];
    int iValinta, i = 0;

    do  {
        iValinta = valikko();
        printf("\n");
        switch (iValinta)   {

        case 0:
            free(pTaulukko);
            pTaulukko = NULL;
            printf("Muisti vapautettu.\n");
            printf("Lopetetaan.\n");
            break;
        case 1:
            kysyTiedosto(pNimi1, 1);
            pTaulukko = lueTiedosto(pTaulukko, pNimi1, pLkm);
            break;
        case 2:
            if (atoi(pLkm) == 0)    {
                printf("Ei analysoitavaa, lue tiedosto ennen analyysia.\n");
            } else  {
                i++;
                printf("Summat laskettu %d merkkijonolle.\n", atoi(pLkm));
            }
            break;
        case 3:
            if (atoi(pLkm) == 0 || i == 0)    {
                printf("Ei kirjoitettavia tietoja, analysoi tiedot ennen tallennusta.\n");
            } else  {
                kysyTiedosto(pNimi2, 2);
                kirjoitaTiedosto(pNimi2, pTaulukko, atoi(pLkm));
            }
            break;
        default:
            printf("Tuntematon valinta, yritä uudelleen.\n");
            break;
        }
        printf("\n");
    } while (iValinta != 0);
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}
