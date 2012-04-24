#ifndef _GRAPHE_H_
#define _GRAPHE_H_

#include "noeud.h"


typedef struct sArc
{
	int val;
	Noeud* src;
	Noeud* dst;
} Arc;

typedef struct sGraphe
{
	Noeud*  tab_sommets ;
	Arc*    tab_arcs ;
	int nb_sommets ;
	int nb_arcs ;
} Graphe ;


void initGrapheVide(Graphe* g);
void detruitGraphe(Graphe* g);

/* retourne 1 si l'ajout a lieu */
int ajouteNoeud(Graphe* g, const char* str);
int ajouteArc(Graphe* g, const int v,const int i,const int j);

int find_pos(Graphe *g, const char *nom);
void afficheGraphe(Graphe *g);

#endif
