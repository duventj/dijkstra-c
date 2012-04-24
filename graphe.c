#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"

int find_pos(Graphe *g, const char *nom)
{
  int i;
  for(i=0; i<g->nb_sommets; i++)
    if(!strcmp(nom, g->tab_sommets[i].nom))
      return i;
  return -1;
}
/*
void* copyWithoutI(void* ptr, const int sz, const int elem_sz, const int i)
{
  void* tmp=NULL;
  
  tmp = (void*)malloc((sz-1)*elem_sz);
  memcpy(tmp, ptr, (i-1)*elem_sz);
  ptr+=(unsigned int)(i+1)*elem_sz;
  memcpy(tmp+(unsigned int)(i-1)*elem_sz, ptr, (sz-i+1)*elem_sz);
  return tmp;
}
#define wicpy(type, ptr, sz, i) (type*)copyWithoutI(ptr, sz,sizeof(type), i);\
				    free((type*)ptr);\
				    
int supprimeNoeud(Graphe *g, const int n)
{
  unsigned int i;
  Arc* tmp=NULL;
  Noeud* ttmp;
  
  if(n>=g->nb_sommets)
    return 0;
  else 
  {
    for(i=0; i<g->nb_arcs; i++)
    {
      if((g->tab_arcs[i].src==&(g->tab_sommets[i])) || (g->tab_arcs[i].dst==&(g->tab_sommets[i])))
      {
	tmp = wicpy(Arc, g->tab_arcs, g->nb_arcs, i);
	free(g->tab_arcs);
	g->tab_arcs = tmp;
      }
    }
    detruit_noeud(&g->tab_sommets[n]);
    ttmp = wicpy(Noeud, g->tab_sommets, g->nb_sommets, n);
    free(g->tab_sommets);
    g->tab_sommets = ttmp;
  }
  return 1;
}

int supprimeNoeudParNom(Graphe *g, const char* name)
{
  return supprimeNoeud(g, find_pos(g, name));
}
*/
#define aff_col(n) ((n.color)? ((n.color==0x02)?"noir":"gris"):"blanc")
void afficheGraphe(Graphe *g)
{
  int i;
  
  printf("%d noeuds\n", g->nb_sommets);
  for(i=0; i<g->nb_sommets; i++)
    printf("Sommet %d : %s, %s\n", i, g->tab_sommets[i].nom, aff_col(g->tab_sommets[i]));
  printf("%d arcs\n", g->nb_arcs);
  for(i=0; i<g->nb_arcs; i++)
    printf("Arc %s --> %s : %d \n", g->tab_arcs[i].src->nom, g->tab_arcs[i].dst->nom, g->tab_arcs[i].val);
}

void initGrapheVide(Graphe* g)
{
	g->tab_sommets = NULL;
	g->tab_arcs = NULL;
	g->nb_sommets = 0;
	g->nb_arcs = 0;
}


int ajouteNoeud(Graphe* g, const char* str)
{
  int n = g->nb_sommets ;
  
  if(find_pos(g, str) < 0)
  {
    g->tab_sommets = (Noeud*) realloc(g->tab_sommets, (n+1)*sizeof(Noeud));
    init_noeud(&(g->tab_sommets[n]), str);
    g->nb_sommets ++ ;
    return 1;
  }
  else 
    return 0;
}


int ajouteArcParNom(Graphe *g, const int v, char *source, char* dest)
{
  return ajouteArc(g, v, find_pos(g, source), find_pos(g, dest));
}

int ajouteArc(Graphe* g, const int v,const int i,const int j)
{
  Noeud *ni, *nj;
  int t;

  if ((i >= g->nb_sommets) || (j >= g->nb_sommets) || (i==j))
    return 0;
  
  ni = &(g->tab_sommets[i]);
  nj = &(g->tab_sommets[j]);
  
  for(t=0; t<g->nb_arcs; t++)
  {	
    if ((g->tab_arcs[t].src == ni ) && (g->tab_arcs[t].dst == nj ))
    {
      printf("modif val for %s -%d-> %s \n", ni->nom, v, nj->nom);
      g->tab_arcs[t].val = v;
      return 1;
    }
  }
  g->tab_arcs = (Arc*)realloc(g->tab_arcs, sizeof(Arc)*(g->nb_arcs+1));
  
  g->tab_arcs[g->nb_arcs].val= v;
  g->tab_arcs[g->nb_arcs].src= ni;
  g->tab_arcs[g->nb_arcs].dst= nj;
  g->nb_arcs++ ;
  
  return 1;
}

void detruitGraphe(Graphe* g)
{
  int i ;
  for(i=0; i<g->nb_sommets; i++)
    detruit_noeud(&g->tab_sommets[i]);
  free(g->tab_sommets) ;
  free(g->tab_arcs) ;
  initGrapheVide(g) ;
}
