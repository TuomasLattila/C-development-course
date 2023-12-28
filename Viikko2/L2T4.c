/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero: 
Päivämäärä: 24.1.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L2T4.c
*/

#include <stdio.h>

#define PII 3.141

int main(void)  {
    int iValinta;
    float fSade;
    float fKeha = 0;
    float fP_Ala = 0;

    printf("Anna ympyrän säde: ");
    scanf("%f", &fSade);
    printf("\n");
    printf("Valikko:\n");
    printf("1) Laske ympyrän kehän pituus\n");
    printf("2) Laske ympyrän pinta-ala\n");
    printf("Valitse: ");
    scanf("%d", &iValinta);

    switch (iValinta)    {
        case 1:
            fKeha = (2*PII*fSade);
            printf("Ympyrän säde on %.3f ja sen kehän pituus %.3f.", fSade, fKeha);
            break;
        case 2:
            fP_Ala = (PII*(fSade*fSade));
            printf("Ympyrän säde on %.3f ja sen pinta-ala on %.3f.", fSade, fP_Ala);
            break;
        default:
            printf("Tuntematon valinta.");
            break;
    }
    return(0);
}
