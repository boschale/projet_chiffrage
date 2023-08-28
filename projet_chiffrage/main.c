#include <stdlib.h>
#include <stdio.h>
#include "entete.h"

int affichageMenu(void)
{
    int choixMenu;

    while (choixMenu !=0)
    {
        printf("---Menu---\n\n");
        printf("1.Definir le perroquet\n");
        printf("2.Dechiffrer le mot source\n");
        printf("3.Chiffrer le mot source\n");
        printf("\nVotre choix?\n\n");
        scanf("%d", &choixMenu);
        return choixMenu;
    }

}
int main(void)
{
    switch (affichageMenu())
    {
    case 0:
        break;
    case 1:
        ecrirePerroquet();
        break;
    case 2:
        dechiffreSource();
        break;
    case 3:
        chiffreSource();
        break;
    default:
        printf("error");
        break;
    }

    system("PAUSE");
    return 0;
}



