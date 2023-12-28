/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero: 000437136
Päivämäärä: 7.2.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L4T3.c
*/

#include <stdio.h>
#include <stdlib.h>
#define KOKO 30

typedef struct laskutoimitus    {
    char aLasku[50];
    int iLuku1;
    int iLuku2;
} LASKUTOIMITUS;


void kirjoitaTiedot(char *pNimi, LASKUTOIMITUS *plt, int i);
void lueTiedot(char *pNimi);
void lisaaLuku(LASKUTOIMITUS *plt);
void kysyNimi(char *pNimi);

int main(void)  {
    LASKUTOIMITUS alt[KOKO]; 
    int iLuku;
    char aNimi[KOKO]; 
    int iValinta;
    int i = 0;

    printf("Anna kokonaisluku: ");
    scanf("%d", &alt->iLuku1);
    kysyNimi(aNimi);
    printf("\n");

    do  {
        printf("Valitse haluamasi toiminto:\n");
        printf("1) Lisää lukuun\n");
        printf("2) Kirjoita historia tiedostoon\n");
        printf("3) Lue historia tiedostosta\n");
        printf("0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &iValinta);
        printf("\n");

        if (iValinta == 0)  {
            printf("Lopetetaan.\n");
            printf("\n");
            break;
        } else if (iValinta == 1)   {
            lisaaLuku(&alt[i]);

            iLuku = (alt[i].iLuku1 + alt[i].iLuku2);
            sprintf(alt[i].aLasku, "%d+%d=%d", alt[i].iLuku1, alt[i].iLuku2, iLuku);
            printf("%s\n", alt[i].aLasku);
            i++;
            alt[i].iLuku1 = iLuku;
        } else if (iValinta == 2)   {
            kirjoitaTiedot(aNimi, alt, i);
        } else if (iValinta == 3)   {
            lueTiedot(aNimi);
        } else  {
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
        printf("\n");
    }   while (iValinta != 0);
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

void kysyNimi(char *pNimi) {
    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", pNimi);
    return;
}

void lisaaLuku(LASKUTOIMITUS *plt)    {
    printf("Anna lukuun lisättävä kokonaisluku: ");
    scanf("%d", &plt->iLuku2);
    return;
}

void kirjoitaTiedot(char *pNimi, LASKUTOIMITUS *plt, int i)  {
    FILE *tiedosto;
    int j;

    if ((tiedosto = fopen(pNimi, "a")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }   else    {
        tiedosto = fopen(pNimi, "a");
        for (j=0; j<i; j++)  {
            fprintf(tiedosto, "%s\n", plt[j].aLasku);
        }
    }
    fclose(tiedosto);
    printf("Tiedosto '%s' kirjoitettu.\n", pNimi);
    return;
}

void lueTiedot(char *pNimi) {
    FILE *tiedosto;
    char rivi[50];

    if ((tiedosto = fopen(pNimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }   else    {
        printf("Tiedostossa oleva laskuhistoria:\n");
        tiedosto = fopen(pNimi, "r");

        while(fgets(rivi, 50, tiedosto) != NULL)    {
            printf("%s", rivi);
        }
    }
    printf("Tiedosto '%s' luettu ja tulostettu.\n", pNimi);
    fclose(tiedosto);
    return;
}

