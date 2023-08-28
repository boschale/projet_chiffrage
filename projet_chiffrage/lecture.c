#include "entete.h"

void lireFichier(void)
{

    FILE *fp = NULL;
    char source = "abcd";

    fp = fopen("sources.txt", "rt");
    if (fp == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

    //1ere lecture
    //fseek(fp, 5, SEEK_SET);   //Décalage de 5 à partir du début du fichier
    //fseek(fp, -5, SEEK_END);    //Décalage de 5 à partir de la fin de fichier

    fread(&source, sizeof(source), sizeof(char), fp);
    if (feof(fp))
    {
        printf("\nFichier Vide !!!");
    }

    //Tant que la fin de fichier n'a pas été détectée
    while(!feof(fp))
    {
        printf("\nsource : %c", source);
        fread(&source, sizeof(source), sizeof(char), fp);
        if (feof(fp))
        {
           printf("\n\tFichier Fini !!!");
        }
    }

    int retClose = fclose(fp);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }
}


