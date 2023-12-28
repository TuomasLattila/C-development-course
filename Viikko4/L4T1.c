/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero: 
Päivämäärä: 6.2.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L4T1.c
*/

#include <stdio.h>
#include <string.h>

#define KOKO 52

struct kappaleenTiedot  {
    char aNimi[KOKO];
    char aEsittaja[KOKO];
    char aPituus[KOKO];
    int iJulkaisuVuosi;
};

int main(void)  {
    struct kappaleenTiedot kT;

    printf("Anna kappaleen nimi: ");
    fgets(kT.aNimi, KOKO, stdin);
    kT.aNimi[strlen(kT.aNimi)-1] = '\0';

    printf("Anna kappaleen esittäjä: ");
    fgets(kT.aEsittaja, KOKO, stdin);
    kT.aEsittaja[strlen(kT.aEsittaja)-1] = '\0';

    printf("Anna kappaleen pituus: ");
    fgets(kT.aPituus, KOKO, stdin);
    kT.aPituus[strlen(kT.aPituus)-1] = '\0';

    printf("Anna kappaleen julkaisuvuosi: ");
    scanf("%d", &kT.iJulkaisuVuosi);

    printf("Kappaleen nimi on '%s' ja esittäjä '%s'.\n", kT.aNimi, kT.aEsittaja);
    printf("Kappale on %s minuuttia pitkä ja julkaistu vuonna %d.\n", kT.aPituus, kT.iJulkaisuVuosi);
    printf("Kiitos ohjelman käytöstä.");
    return(0);
}
