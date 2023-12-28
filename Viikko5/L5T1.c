/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero: 
Päivämäärä: 14.2.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L5T1.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* muistinVaraus(void)   {
    char* pMuistiVaraus;

    if ((pMuistiVaraus = (char*)malloc(30)) == NULL)    {
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    printf("Muisti varattu 30 merkille.\n");
    return (char*)malloc(30);
}

char* merkkijononSijoitus(char* pMuistiOsoite)   {
    printf("Anna merkkijono: ");
    fgets(pMuistiOsoite, 32 , stdin);
    pMuistiOsoite[strlen(pMuistiOsoite)-1] = '\0';
    return pMuistiOsoite;
}

int main(void)  {
    char *pMuistiOsoite = NULL;

    pMuistiOsoite = muistinVaraus();
    pMuistiOsoite = merkkijononSijoitus(pMuistiOsoite);

    printf("Annoit merkkijonon '%s'.\n", pMuistiOsoite);
    free(pMuistiOsoite);
    pMuistiOsoite = NULL;
    printf("Muisti vapautettu.\n");

    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}
