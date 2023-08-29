#include "entete.h"

void lireFichier(void)
{

    FILE *fps = NULL;
    char source;

    fps = fopen("sources.txt", "rt");
    if (fps == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

    //1ere lecture
    //fseek(fp, 5, SEEK_SET);   //D�calage de 5 � partir du d�but du fichier
    //fseek(fp, -5, SEEK_END);    //D�calage de 5 � partir de la fin de fichier

    fread(&source, sizeof(source), sizeof(char), fps);
    if (feof(fps))
    {
        printf("\nFichier Vide !!!");
    }

    //Tant que la fin de fichier n'a pas �t� d�tect�e
    while(!feof(fps))
    {
        printf("\nsource : %c", source);
        fread(&source, sizeof(source), sizeof(char), fps);
        if (feof(fps))
        {
           printf("\n\tFichier Fini !!!");
        }
    }
    int retClose = fclose(fps);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }
}


