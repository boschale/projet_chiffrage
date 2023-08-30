#include "entete.h"
#include <stdlib.h>
#include <stdio.h>
// le perroquet repète la derniere lettre au lieu de recommencer à 0
// ne corrige pas en compte les valeurs négatives, modulo ne fonctionne pas
// il faut que le contenu des fichiers rentre dans les variables source et perroq
void chiffreSource(void)
{
    FILE *fps = NULL;
    char source[2];
    fps = fopen("sources.txt", "rt");
    if (fps == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

    FILE *fpp = NULL;
    char perroq[2];
    int result;
    int i=0;
    int j=0;
    fpp = fopen("peroq.def", "rt");
    if (fpp == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

    FILE *fpr = NULL;
    fpr = fopen("dest.txt", "w+t");
    if (fpr == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

    fread(&source, sizeof(source), sizeof(char), fps);
    if (feof(fps))
    {
        printf("\nFichier Vide !!!");
    }

    fread(&perroq, sizeof(perroq), sizeof(char), fpp);
    if (feof(fpp))
    {
        printf("\nFichier Vide !!!");
    }
    fread(&source, sizeof(source), sizeof(char), fps);
    fread(&perroq, sizeof(perroq), sizeof(char), fpp);
    while(i<sizeof(source))
    //while(!feof(fps))
    {

        printf("lettre source : %c\n", source);
//        if (feof(fps))
//        {
//           printf("\n\tFichier Fini !!!");
//        }
        printf("lettre perroq : %c\n", perroq);
        result = (source - perroq)%128;
        printf("lettre chiffrer : %c\n", result);
        fwrite(&result, sizeof(result), sizeof(char), fpr);

        i++;
        j++;
    }
    int retClose = fclose(fps);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }
}

