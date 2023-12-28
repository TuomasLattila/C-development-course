/*
CT60A2500 C-ohjelmoinnin perusteet
Tekijä: Tuomas Lättilä
Opiskelijanumero: 000437136
Päivämäärä: 8.2.2023
Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:

Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
vaikuttaneet siihen yllä mainituilla tavoilla.

Tehtävä L4T5.c
*/

#include <stdio.h>
#include <string.h>

int valikko(void){
    int x;
    printf("Valitse haluamasi toiminto:\n");
    printf("1) Tulosta merkkijono\n");
    printf("2) Tulosta merkkijono takaperin\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &x);
    return x;
}

char tulosta1(char *pSana, int i){
    if (pSana[i] == '\0'){
        return(0);
    } else{
        printf("%c\n", pSana[i]);
        return (tulosta1(pSana, i+1));
    }
}

char tulosta2(char *pSana, int i){
    if (i == -1){
        return(0);
    } else{
        printf("%c\n", pSana[i]);
        return (tulosta2(pSana, i-1));
    }
}

int main(int argc, char *argv[]){
    int iValinta;

    if (argc < 2){
        printf("Et antanut tarpeeksi parametreja.\n");
    } else if (argc > 2){
        printf("Annoit liikaa parametreja.\n");
    } else{
        do{
            iValinta = valikko();
            switch (iValinta){
            case (0):
                printf("Lopetetaan.\n");
                break;
            case (1):
                tulosta1(argv[1], 0);
                break;
            case (2):
                tulosta2(argv[1], (strlen(argv[1])-1));
                break;
            default:
                printf("Tuntematon valinta, yritä uudelleen.\n");
                break;  
            } 
            printf("\n");
        } while (iValinta != 0);
        printf("Kiitos ohjelman käytöstä.\n");
    }
    return(0);
}