#include "entete.h"

void lirePerroquet(void)
{

    FILE *fpp = NULL;
    char perroq;

    fpp = fopen("peroq.def", "rt");
    if (fpp == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

    //1ere lecture
    //fseek(fp, 5, SEEK_SET);   //D�calage de 5 � partir du d�but du fichier
    //fseek(fp, -5, SEEK_END);    //D�calage de 5 � partir de la fin de fichier

    fread(&perroq, sizeof(perroq), sizeof(char), fpp);
    if (feof(fpp))
    {
        printf("\nFichier Vide !!!");
    }

    //Tant que la fin de fichier n'a pas �t� d�tect�e
    while(!feof(fpp))
    {
        printf("\nlettre : %c", perroq);
        fread(&perroq, sizeof(perroq), sizeof(char), fpp);
        if (feof(fpp))
        {
           printf("\n\tFichier Fini !!!");
        }
    }
    int retClose = fclose(fpp);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }
}



