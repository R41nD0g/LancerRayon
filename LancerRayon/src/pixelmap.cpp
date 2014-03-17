#include <math.h>
#include "pixelmap.hpp"
#include "bases3d.hpp"
#include "bitmap.hpp"

void Pixelmap::Correction(float g) {
	int taille; // Nombre de pixels a traiter
	int index; // Indice du pixel traite
	RVB * cour; // Pixel en cours d'etude

	// Puis on cherche la valeur maximale de la pixelmap
	taille = largeur * hauteur;
	for (index = 0, cour = map; index < taille; index++, cour++) {
		(*cour).R(pow((*cour).R(), (1 / g)));
		(*cour).V(pow((*cour).V(), (1 / g)));
		(*cour).B(pow((*cour).B(), (1 / g)));
	}
}

void Pixelmap::Normaliser() {
	int taille; // Nombre de pixels a traiter
	int index; // Indice du pixel traite
	RVB * cour; // Pixel en cours d'etude
	float max; // Intensite maximale des composantes des pixels formant la pixelmap

	// On cherche la valeur maximale de la pixelmap
	taille = largeur * hauteur;
	max = map[0].R();
	for (index = 0, cour = map; index < taille; index++, cour++) {
		if (max < cour->R())
			max = cour->R();
		if (max < cour->V())
			max = cour->V();
		if (max < cour->B())
			max = cour->B();
	}

	// Et enfin on fait le transfert a l'aide de couleurs normalisees
	if (max != 0)
		max = 1 / max;
	for (index = 0, cour = map; index < taille; index++, cour++)
		(*cour) *= max;
}

void Pixelmap::Transferer(Image & b) const {
	int taille; // Nombre de pixels a traiter
	int index; // Indice du pixel traite
	RVB * cour; // Pixel en cours d'etude

	// On commence par redimmensionner le bitmap a la taille de la pixelmap
	b.Redimensionner(largeur, hauteur);

	// Et on fait le transfert de tous les pixels
	taille = largeur * hauteur;
	for (index = 0, cour = map; index < taille; index++, cour++)
		b.Map(index, (*cour));
}
