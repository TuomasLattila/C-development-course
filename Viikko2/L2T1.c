#include <stdio.h>

int main(void)  {
    int luku;
    int tesi_1 = 14;
    int testi_2 = 17;
    int testi_3 = 20;
    int testi_4 = 23;
    int testi_5 = 26;
    int testi_6 = 30;

    printf("Anna palautettujen tehtävien lukumäärä: ");
    scanf("%d", &luku);

    if (luku < tesi_1)  {
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 0.\n", luku);
    } else if ((luku > tesi_1) && (luku <= testi_2))    {
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 1.\n", luku);
    } else if ((luku > testi_2) && (luku <= testi_3))   {
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 2.\n", luku);
    } else if ((luku > testi_3) && (luku <= testi_4))   {
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 3.\n", luku);
    } else if ((luku > testi_4) && (luku <= testi_5))   {
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 4.\n", luku);
    } else if ((luku > testi_5) && (luku <= testi_6))   {
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 5.\n", luku);
    } else  {
        printf("Kurssilla on vain 30 tehtävää.\n");
    }

    return(0);
}