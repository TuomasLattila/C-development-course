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

Tehtävä L4T2.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])    {
    char aRivi[50]; FILE *tiedosto; int i; int iLaskuri = 0;
    
    if (argc < 3)   {
        printf("Et antanut tarpeeksi parametreja.\n");
    } else if (argc > 3)   {
        printf("Annoit liikaa parametreja.\n");
    } else  {
        if ((tiedosto = fopen(argv[1], "r")) == NULL)   {
            perror("Tiedoston avaaminen epäonnistui, lopetetaan");
            exit(0);
        }
        tiedosto = fopen(argv[1], "r");
        for (i = 0; i < atoi(argv[2]); i++)   {
            if ((fgets(aRivi, 50, tiedosto)) == NULL)   {
                printf("\n");
                printf("Tiedostossa ei ole enempää rivejä luettavaksi.\n");
                break;
            }
            printf("%s", aRivi);
            iLaskuri++;
        }
        fclose(tiedosto);
        if (atoi(argv[2]) == iLaskuri)  {
            printf("\n");
        } printf("Tiedostosta '%s' luettu %d riviä.\n", argv[1], iLaskuri);
    }
    return(0);
}
