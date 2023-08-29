#include <stdlib.h>
#include <stdio.h>
#include "entete.h"

int main(void)
{
    int choixMenu;
    do
    {
        printf("---Menu---\n\n");
        printf("0. quitter le menu \n");
        printf("1.Definir le perroquet\n");
        printf("2.Dechiffrer le fichier source\n");
        printf("3.Chiffrer le fichier source\n");
        printf("\nVotre choix?\n\n");
        scanf("%d", &choixMenu);
        fflush(stdin);

    switch (choixMenu)
    {
    case 0:
        break;
    case 1:
        ecrirePerroquet();
        lirePerroquet();
        system("PAUSE");
        break;
    case 2:
        dechiffreSource();
        system("PAUSE");
        break;
    case 3:
        chiffreSource();
        system("PAUSE");
        break;
    default:
        printf("error");
        break;
    }
    }
    while (choixMenu !=0);
    return 0;
}



