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

Tehtävä L3T3.c
*/

#include <stdio.h>
#include <stdlib.h>

int kirjoitaTiedot(int iLuku, char *pNimi);
void lueTiedot(char *pNimi);

int main(void)  {
    int iLuku;
    char aNimi[30];
    int iValinta;

    printf("Anna kokonaisluku: ");
    scanf("%d", &iLuku);
    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", aNimi);
    printf("\n");

    do  {
        printf("Valitse haluamasi toiminto:\n");
        printf("1) Lisää lukuun\n");
        printf("2) Tulosta tulokset\n");
        printf("0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &iValinta);
        printf("\n");

        if (iValinta == 0)  {
            printf("Lopetetaan.\n");
            printf("\n");
            break;
        } else if (iValinta == 1)   {
            iLuku = kirjoitaTiedot(iLuku, aNimi);
        } else if (iValinta == 2)   {
            lueTiedot(aNimi);
        } else  {
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
        printf("\n");
    }   while (iValinta != 0);
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

int kirjoitaTiedot(int iLuku, char *pNimi)  {
    int iLuku1;
    FILE *tiedosto;

    printf("Anna lukuun lisättävä kokonaisluku: ");
    scanf("%d", &iLuku1);
    printf("%d+%d=%d\n", iLuku, iLuku1, (iLuku+iLuku1));

    if ((tiedosto = fopen(pNimi, "a")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }   else    {
        tiedosto = fopen(pNimi, "a");
        fprintf(tiedosto, "%d+%d=%d\n", iLuku, iLuku1, (iLuku+iLuku1));
    }
    fclose(tiedosto);
    iLuku = (iLuku + iLuku1);
    return iLuku;
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
}
