/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero: 000437136
Päivämäärä: 21.2.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L6T1.c
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct kirjain  {
    char cKirjain;
    struct kirjain *pSeuraava;
} KIRJAIN;

int main(void)  {
    KIRJAIN *pAlku = NULL, *pLoppu = NULL;
    KIRJAIN *pUusi, *ptr;
    char cValinta;

    printf("Anna listan kirjaimet.\n");
    printf("Anna kirjain, q lopettaa: ");
    scanf("%c", &cValinta);

    while (cValinta != 'q') {
        if ((pUusi = (KIRJAIN*)malloc(sizeof(KIRJAIN))) == NULL)    {
            perror("Muistin varaus epäonnistui");
            exit(0);
        }

        pUusi->cKirjain = cValinta;
        pUusi->pSeuraava = NULL;

        if (pAlku == NULL)  {
            pAlku = pUusi;
            pLoppu = pUusi;
        } else {
            pLoppu->pSeuraava = pUusi;
            pLoppu = pUusi;
        }

        printf("Anna kirjain, q lopettaa: ");
        scanf(" %c", &cValinta);
    }
    printf("Listassa on seuraavat kirjaimet:\n");
    //listan läpikäynti
    ptr = pAlku;
    while (ptr != NULL) {
        printf("%c ", ptr->cKirjain);
        ptr = ptr->pSeuraava;
    }
    printf("\n\n");
    // muistin vapautus
    ptr = pAlku;
    while (ptr != NULL) {
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }
    printf("Muisti vapautettu.\n");
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}