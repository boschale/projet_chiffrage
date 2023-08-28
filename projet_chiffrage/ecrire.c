#include "entete.h"
#include <stdlib.h>
#include <stdio.h>


void ecrirePerroquet(void)
{
    FILE *fp = NULL;

    fp = fopen("peroq.def", "w+t");
    if (fp == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

    char perroquet;
    printf("Entrez le perroquet\n");
    scanf(" %c", &perroquet);

    fwrite(&perroquet, sizeof(perroquet), 1, fp);

    int retClose = fclose(fp);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

}
