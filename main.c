#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "graphe.h"
#include "dijkstra.h"

#define NB_SOMMETS 10
#define NB_ARCS    NB_SOMMETS*2
#define POID_MAX   100

int main()
{
  Graphe g;
  char name[20];
  int i;


  srand(time(NULL));
  initGrapheVide(&g);
  
  printf("************* Construction du graphe *************\n");
  for(i=0; i<NB_SOMMETS; i++)
  {
    sprintf(name, "Ville-%d", i);
    if(!ajouteNoeud(&g, name))
      printf("%s deja present\n", name);
  }
  for(i=0; i<NB_ARCS; i++)
  {
    if(!ajouteArc(&g, (rand()%POID_MAX)+1, rand()%NB_SOMMETS, rand()%NB_SOMMETS))
      printf("Sommet de l'arc incorrect ou src=dest\n");
  }
  afficheGraphe(&g);
  printf("*********** Fin construction du graphe ***********\n\n");
  
  printf("******************** Dijkstra ********************\n");
  sprintf(name, "Ville-%d", rand()%NB_SOMMETS);
  dijkstra(&g, name);
  printf("****************** Fin Dijkstra ******************\n\n");
  
  printf("****************** Graphe finit ******************\n");
/*  for(i=0; i<g.nb_sommets; i++)
    if(g->tab_sommets[i].color == BLANC)
      supprimeNoeud(&g, i);*/
  afficheGraphe(&g);
  printf("****************** Graphe finit ******************\n");

  detruitGraphe(&g);

 return 0;
}
