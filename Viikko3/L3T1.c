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

Tehtävä L3T1.c
*/

#include <stdio.h>

float pintaAla(float kanta, float korkeus);

int main(void)  {
    float kanta;
    float korkeus;
    float ala;

    printf("Tämä ohjelma laskee suorakulmion pinta-alan.\n");
    printf("Anna suorakulmion kanta: ");
    scanf("%f", &kanta);
    printf("Anna suorakulmion korkeus: ");
    scanf("%f", &korkeus);

    ala = pintaAla(kanta, korkeus);

    printf("Suorakulmion pinta-ala on %.2f.\n", ala);
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

float pintaAla(float kanta, float korkeus)  {
    return (kanta * korkeus);
}
