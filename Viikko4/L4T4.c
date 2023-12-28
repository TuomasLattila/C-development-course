/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero:
Päivämäärä: 8.2.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L4T4.c
*/

#include <stdio.h>
#include <stdlib.h>
#define RIVI 3
#define SARAKE 3
#define KOKO 30

void kysyNimi(char *pNimi)  {
    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", pNimi);
    return;
}

void tulostaKijoita(int (*matriisi)[SARAKE], char *pMatriisinNimi1, char *pMatriisinNimi2, char *pNimi)   {
    int i, j;
    FILE *tiedosto;

    if ((tiedosto = fopen(pNimi, "a")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    printf("\n%s\n", pMatriisinNimi1);
    fprintf(tiedosto, "%s\n", pMatriisinNimi1);

    for (i=0; i<RIVI; i++){
        for (j=0; j<SARAKE; j++){
            printf("%4d ", matriisi[i][j]);
            fprintf(tiedosto, "%4d ", matriisi[i][j]);
        }
        printf("\n");
        fprintf(tiedosto,"\n");
    }
    fprintf(tiedosto, "\n");
    printf("\n");
    printf("%s\n", pMatriisinNimi2);
    fprintf(tiedosto, "%s\n", pMatriisinNimi2);

    for (i=0; i<RIVI; i++){
        for (j=0; j<SARAKE; j++){
            printf("%4d ", matriisi[j][i]);
            fprintf(tiedosto, "%4d ", matriisi[j][i]);
        }
        printf("\n");
        fprintf(tiedosto,"\n");
    }
    printf("\n");
    fclose(tiedosto);
    return;
}

int main(void)  {
    char aNimi[KOKO], aNimi1[] = "Lähtömatriisi: ", aNimi2[] = "Lähtömatriisin transpoosi: ";
    char *ptrNimi;
    int matriisi[RIVI][SARAKE], i, j;

    ptrNimi = aNimi;

    kysyNimi(aNimi);
    printf("Anna arvot lähtömatriisille: \n");

    for (i=0; i<RIVI; i++){
        for (j=0; j<SARAKE; j++){
            printf("Rivi %d, alkio %d: ", i+1, j+1);
            scanf("%d", &matriisi[i][j]);
        }
    }

    tulostaKijoita(matriisi, aNimi1, aNimi2, ptrNimi);
    printf("Tiedosto '%s' kirjoitettu.\n", aNimi);
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}
