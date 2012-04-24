#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "noeud.h"

char* strdup(const char*);

void init_noeud(Noeud* n, const char* nom_noeud)
{  
    n->nom = strdup(nom_noeud);
/*    if(n->nom = (char*) malloc(strlen(nom_noeud)))
      strcpy(n->nom, nom_noeud);*/
    n->color = BLANC;
}

void detruit_noeud(Noeud *n)
{
  if (n->nom != NULL)
  {
    free(n->nom);
    n->nom = NULL;
  }
  else
    printf("Noeud probablement deja detruit\n");
}