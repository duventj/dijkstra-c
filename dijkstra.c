#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphe.h"
#include "dijkstra.h"
#include "pqueue.h"

/*************** pqueue heap definitions ***************/
#define pri dist
typedef Distance node_t;

static int cmp_pri(double next, double curr)
{
	return (next > curr);
}
static double
get_pri(void *a)
{
	return (double) ((node_t *) a)->pri;
}
static void
set_pri(void *a, double pri)
{
	((node_t *) a)->pri = pri;
}
static size_t
get_pos(void *a)
{
	return ((node_t *) a)->pos;
}
static void
set_pos(void *a, size_t pos)
{
	((node_t *) a)->pos = pos;
}
/*******************************************************/


static pqueue_t *pq;

void update_dist(Graphe *g, Distance *d, int n)
{
  int i, j, k;
  
  for(i=0; i<g->nb_arcs; i++)
    if(g->tab_arcs[i].src == &(g->tab_sommets[n]))
    {
      k = d[n].dist+g->tab_arcs[i].val;
      j = find_pos(g, g->tab_arcs[i].dst->nom);
      if(k < d[j].dist)
      {
	d[j].pred = n;
	pqueue_change_priority(pq, k, &d[j]);
      }
      else if (d[j].dist<0)
      {
	d[j].pred = n;
	d[j].dist = k;
	pqueue_insert(pq, &d[j]);
      }
      g->tab_arcs[i].dst->color = GRIS;
    }
}

void dijkstra(Graphe *g, const char *nom_sommet)
{
  Distance *d, *dd;
  int i;
  int depart = find_pos(g, nom_sommet);
  
  if (depart>=0)
  {
    printf("Au depart de %s :\n", g->tab_sommets[depart].nom);
    d = (Distance*) malloc(g->nb_sommets * sizeof(Distance));
    pq = pqueue_init(g->nb_sommets, cmp_pri, get_pri, set_pri, get_pos, set_pos);
    for(i=0; i<g->nb_sommets; i++)
    {
      d[i].pred = i;
      d[i].dist = -1;
    }
    d[depart].dist = 0;
    pqueue_insert(pq, &d[depart]);
    while((dd = pqueue_pop(pq)))
    {
      i = dd-d; /*(dd-d)/0x0B;   tres bizarre
      printf("upd_dist(%d), %x %x %d\n", i, dd, d, dd-d);*/
      update_dist(g, d, i);
      g->tab_sommets[i].color = NOIR;
    }
    
    for(i=0; i<g->nb_sommets; i++)
      printf("Sommet %s : %d, apres %s\n", g->tab_sommets[i].nom, d[i].dist, g->tab_sommets[d[i].pred].nom); 
    free(d);
  }
  else
    printf("Sommet inconnu\n");
}
