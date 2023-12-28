/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero: 
Päivämäärä: 22.2.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L6T3.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KOKO 30

typedef struct laskutoimitus    {
    char aLasku[50];
    int iLuku1;
    int iLuku2;
    struct laskutoimitus *pSeuraava;
} LASKUTOIMITUS;

int valikko(void)   {
    int iValinta = 0;
    printf("Valitse haluamasi toiminto:\n");
    printf("1) Lisää lukuun\n");
    printf("2) Kirjoita historia tiedostoon\n");
    printf("3) Lue historia tiedostosta\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &iValinta);
    return(iValinta);
}

void kysyTiedosto(char *pNimi, int i) {
    if (i == 1) {
        printf("Anna kirjoitettavan tiedoston nimi: ");
        scanf("%s", pNimi);
    }
    if (i == 2) {
        printf("Anna luettavan tiedoston nimi: ");
        scanf("%s", pNimi);
    }
    return;
}

LASKUTOIMITUS *muistinVaraus() {
    LASKUTOIMITUS *pU = NULL;
    if ((pU = (LASKUTOIMITUS*)malloc(sizeof(LASKUTOIMITUS))) == NULL)   {
        perror("Muistin varaaminen epäonnistui");
        exit(0);
    }
    pU->pSeuraava = NULL;
    return pU;
}

LASKUTOIMITUS *lisaaLukuun(LASKUTOIMITUS *pA, int iSumma)   {
    LASKUTOIMITUS *pU = NULL, *ptr = NULL;
    int iLuku = 0;

    printf("Anna lukuun lisättävä kokonaisluku: ");
    scanf("%d", &iLuku);

    pU = muistinVaraus();
    pU->iLuku1 = iSumma;
    pU->iLuku2 = iLuku;
    sprintf(pU->aLasku, "%d+%d=%d", iSumma, iLuku, (iSumma+iLuku));
    iSumma = (iSumma+iLuku);

    if (pA == NULL) {
        pA = pU;
    } else {
        ptr = pA;
        while (ptr->pSeuraava != NULL) {
            ptr = ptr->pSeuraava;
        }
        ptr->pSeuraava = pU;
    }
    printf("%s\n", pU->aLasku);
    return (pA);
}

void kirjoitaTiedosto(LASKUTOIMITUS *pA, char *pNimi)    {
    if (pA == NULL) {
        printf("Ei kirjoitettavia tietoja.\n");
    }   else{
        LASKUTOIMITUS *ptr =pA;
        FILE *tiedosto;

        kysyTiedosto(pNimi, 1);

        while (ptr != NULL) {
            printf("%s\n", ptr->aLasku);
            ptr = ptr->pSeuraava;
        }
        printf("\n");

        if ((tiedosto = fopen(pNimi, "w")) == NULL) {
            perror("Tiedoston avaaminen epäonnistui, lopetetaan");
            exit(0);
        }
        ptr = pA;
        while (ptr != NULL) {
            fprintf(tiedosto, "%s\n", ptr->aLasku);
            ptr = ptr->pSeuraava;
        }
        fclose(tiedosto);
        printf("Tiedosto '%s' kirjoitettu.\n", pNimi);
        return;
    }
}

LASKUTOIMITUS *lueTiedosto(LASKUTOIMITUS *pA, char *pNimi)  {
    char aRivi[KOKO], *p1 = NULL, *p2 = NULL;
    LASKUTOIMITUS *pU = NULL, *ptr = NULL;
    FILE *tiedosto;

    kysyTiedosto(pNimi, 2);

    if ((tiedosto = fopen(pNimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    printf("Tiedostossa oleva laskuhistoria:\n");
    while (fgets(aRivi, KOKO, tiedosto) != NULL) {
        printf("%s", aRivi);
        aRivi[strlen(aRivi)-1] = '\0';

        pU = muistinVaraus();
        strcpy(pU->aLasku, aRivi);

        if ((p1 = strtok(aRivi, "+")) == NULL)  {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", aRivi);
            exit(1);
        }

        if ((p2 = strtok(NULL, "=")) == NULL)  {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", aRivi);
            exit(1);
        }

        pU->iLuku1 = atoi(p1);
        pU->iLuku2 = atoi(p2);

        if (pA == NULL) {
            pA = pU;
        } else {
            ptr = pA;
            while (ptr->pSeuraava != NULL) {
                ptr = ptr->pSeuraava;
            }
            ptr->pSeuraava = pU;
        }
    }
    fclose(tiedosto);
    printf("Tiedosto '%s' luettu ja tulostettu.\n", pNimi);
    return(pA);
}

void muistinVapautus(LASKUTOIMITUS *pA)    {
    LASKUTOIMITUS *ptr = pA;
    while(ptr != NULL)  {
        pA = ptr->pSeuraava;
        free(ptr);
        ptr = pA;
    }
    printf("Muisti vapautettu.\n");
}

int laskeSumma(LASKUTOIMITUS *pA, int iSumma)   {
    LASKUTOIMITUS *ptr = pA;
    while(ptr->pSeuraava != NULL)   {
        ptr = ptr->pSeuraava;
    }
    iSumma = (ptr->iLuku1+ptr->iLuku2);
    return (iSumma);
}

int main(int argc, char *argv[])  {
    if (argc < 2)  {
        printf("Et antanut tarpeeksi parametreja.\n");
        exit(0);
    } else if (argc > 2)    {
        printf("Annoit liikaa parametrejä, lopetetaan.\n");
        exit(0);
    } else  {
        char pNimi[KOKO];
        LASKUTOIMITUS *pAlku = NULL;
        int iSumma = atoi(argv[1]), iValinta;

        printf("Annoit luvun %d.\n", iSumma);

        do  {
            iValinta = valikko();
            printf("\n");
            switch (iValinta)   {
            
            case 0:
                muistinVapautus(pAlku);
                printf("Lopetetaan.\n");
                break;

            case 1:
                pAlku = lisaaLukuun(pAlku, iSumma);
                iSumma = laskeSumma(pAlku, iSumma); //Päivittää summa-arvoa
                break;

            case 2:
                kirjoitaTiedosto(pAlku, pNimi);
                break;

            case 3:
                pAlku = lueTiedosto(pAlku, pNimi);
                break;
            default:
                printf("Annoit väärän valinnan, yritä uudelleen\n");
                break;
            }
            printf("\n");
        } while (iValinta != 0);
        
    }
    printf("Kiitos ohjelman käytöstä.\n");
}
