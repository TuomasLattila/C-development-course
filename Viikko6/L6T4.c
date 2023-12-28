/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero:
Päivämäärä: 25.2.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L6T4.c
*/

#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define KOKO 30

typedef struct tiedot{
    float iArvo;
    struct tm *pvm;
    struct tiedot *pSeuraava;
} TIEDOT;

int valikko(int iValinta)   {
    printf("Valitse haluamasi toiminto:\n");
    printf("1) Lue tiedosto\n");
    printf("2) Analysoi\n");
    printf("3) Kirjoita tiedosto\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &iValinta);
    return(iValinta);
}

void kysyTiedosto(char *pNimi, int i)  {
    if (i == 1) {
        printf("Anna luettavan tiedoston nimi: ");
        scanf("%s", pNimi);
        return;
    } else if (i == 3)  {
        printf("Anna kirjoitettavan tiedoston nimi: ");
        scanf("%s", pNimi);
    }
    return;
}

TIEDOT *muistinVaraus()  {
    TIEDOT *pU = NULL;
    struct tm *pUA;
    if ((pU = (TIEDOT*)malloc(sizeof(TIEDOT))) == NULL) {
        perror("Muistin varaaminen epäonnistui");
        exit(0);
    }
    if ((pUA = (struct tm*)malloc(sizeof(struct tm))) == NULL)  {
        perror("Muistin varaaminen epäonnistui");
        exit(0);
    }
    pU->pvm = pUA;
    pU->pSeuraava = NULL;
    return(pU);
}

TIEDOT *lueTiedosto(TIEDOT *pA, char *pNimi)    {
    TIEDOT *pU = NULL, *ptr = NULL;
    FILE *tiedosto;
    char aRivi[KOKO], *p1, *p2;

    kysyTiedosto(pNimi, 1);

    if ((tiedosto = fopen(pNimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    while ((fgets(aRivi, KOKO, tiedosto)) != NULL)  {
        aRivi[strlen(aRivi)-1] = '\0';
        if ((p1 = strtok(aRivi, ";")) == NULL)  {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", aRivi);
            exit(1);
        }
        if ((p2 = strtok(NULL, ";")) == NULL)  {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", aRivi);
            exit(1);
        }
        pU = muistinVaraus();
        strptime(p1, "%d.%m.%Y", (pU->pvm));
        pU->iArvo = atof(p2);

        if (pA == NULL) {
            pA = pU;
        } else {
            ptr = pA;
            while(ptr->pSeuraava != NULL)   {
                ptr = ptr->pSeuraava;
            }
            ptr->pSeuraava = pU;
        }

    }
    fclose(tiedosto);
    printf("Tiedosto '%s' luettu linkitettyyn listaan.\n", pNimi);
    return(pA);
}

void analysoiTiedot(TIEDOT *pA, float *pSumma, char *pMaara)  {
    TIEDOT *ptr = pA;
    int i;
    
    for (i = 0; i < 12; i++)    {
         pSumma[i] = (0.0);
         pMaara[i] = (0);
     }

    while(ptr != NULL)  {
        if (ptr->pvm != NULL) {
            pSumma[(ptr->pvm)->tm_mon] += ptr->iArvo;
            pMaara[(ptr->pvm)->tm_mon] += 1;
        }
        ptr = ptr->pSeuraava;
    }
    printf("Laskettu lämpötilojen keskiarvot eri kuukausille.\n");
    return;
}

void kirjoitaTiedosto(char *pNimi, float *pSumma, char *pMaara)  {
    FILE *tiedosto;
    int i;

    kysyTiedosto(pNimi, 3);

    printf("Kuukausi;Keskiarvo\n");
    for (i = 0; i < 12; i++)    {
        if (pMaara[i] != 0) {
            printf("KK %d;%.2f\n", (i+1), (pSumma[i]/pMaara[i]));
        } else {
            printf("KK %d;%.2f\n", (i+1), 0.0);
        }
    }
    printf("\n");
    if ((tiedosto = fopen(pNimi, "w")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    fprintf(tiedosto, "Kuukausi;Keskiarvo\n");
    for (i = 0; i < 12; i++)    {
        if (pMaara[i] != 0) {
            fprintf(tiedosto,"KK %d;%.2f\n", (i+1), (pSumma[i]/pMaara[i]));
        } else {
            fprintf(tiedosto,"KK %d;%.2f\n", (i+1), 0.0);
        }
    }
    fclose(tiedosto);
    printf("Tiedosto '%s' kirjoitettu.\n", pNimi);
    return;
}

void vapautaMuisti(TIEDOT *pA)  {
    TIEDOT *ptr = pA;

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
    char pNimi[KOKO], aMaara[KOKO];
    int iValinta = 0, x = 0;
    float aSumma[KOKO];

    do  {
        iValinta = valikko(iValinta);
        printf("\n");
        switch (iValinta)
        {
        case 0:
            vapautaMuisti(pAlku);
            printf("Lopetetaan.\n");
            break;
        case 1:
            pAlku = lueTiedosto(pAlku, pNimi);
            break;
        case 2:
            if (pAlku != NULL)  {
                analysoiTiedot(pAlku, aSumma, aMaara);
                x = 1;
            } else  {
                printf("Ei analysoitavia tietoja, lue tiedot ensin.\n");
            }
            break;
        case 3:
            if (x == 1) {
                kirjoitaTiedosto(pNimi, aSumma, aMaara);
            } else {
                printf("Ei kirjoitettavia tietoja, analysoi tiedot ensin.\n");
            }
            break;
        default:
        printf("Tuntematon valinta, yritä uudelleen.\n");
            break;
        }
        printf("\n");
    } while(iValinta != 0);
    printf("Kiitos ohjelman käytöstä.");
    return(0);
}
