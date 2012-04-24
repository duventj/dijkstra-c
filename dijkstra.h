#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

typedef struct sDistance
{
	int pred;
	int dist;
	size_t pos;
} Distance ;

void dijkstra(Graphe*, const char*);

#endif