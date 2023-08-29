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
    //fseek(fp, 5, SEEK_SET);   //Décalage de 5 à partir du début du fichier
    //fseek(fp, -5, SEEK_END);    //Décalage de 5 à partir de la fin de fichier

    fread(&perroq, sizeof(perroq), sizeof(char), fpp);
    if (feof(fpp))
    {
        printf("\nFichier Vide !!!");
    }

    //Tant que la fin de fichier n'a pas été détectée
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



