#include "entete.h"
#include <stdlib.h>
#include <stdio.h>

void dechiffreSource(void)
{

    FILE *fps = NULL;
    char source;

    fps = fopen("dest.txt", "rt");
    if (fps == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

//    fread(&source, sizeof(source), sizeof(char), fps);
//    if (feof(fps))
//    {
//        printf("\nFichier Vide !!!");
//    }

    FILE *fpp = NULL;
    char perroq;
    char result;

    FILE *fpr = NULL;
    fpr = fopen("dest.crt", "w+t");
    if (fpr == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

    fpp = fopen("peroq.def", "rt");
    if (fpp == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

//    fread(&perroq, sizeof(perroq), sizeof(char), fpp);
//    if (feof(fpp))
//    {
//        printf("\nFichier Vide !!!");
//    }

    //Tant que la fin de fichier n'a pas été détectée
    while(!feof(fps))
    {
        fread(&dest, sizeof(dest), sizeof(char), fpr);
        printf("lettre dest : %c\n", dest);
        if (feof(fpr))
        {
           printf("\n\tFichier Fini !!!");
        }
        fread(&perroq, sizeof(perroq), sizeof(char), fpp);
        printf("lettre perroq : %c\n", perroq);
        result = (dest + perroq) % 128;
        printf("lettre chiffrer : %c\n", result);
        fwrite(&result, sizeof(result), sizeof(char), fpr);
    }
    int retClose = fclose(fps);
    //int retClose = fclose(fpp);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }
}
