#ifndef _NOEUD_H_
#define _NOEUD_H_

#define TAILLE_NOM 100


typedef enum { BLANC=0x00, GRIS=0x01, NOIR=0x02 } Couleur;


typedef struct sNoeud 
{
	char *nom ;
	Couleur color;
} Noeud ;

void init_noeud(Noeud*, const char*);
void detruit_noeud(Noeud*);


#endif
