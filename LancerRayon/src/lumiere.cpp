#include <math.h>

#include "lumiere.h"
#include "couleurRVB.hpp"
#include "objet3D.hpp"


RVB Lumiere_Ambiante::Illumination(const Rayon &, const Intersection3D & i, const Point3D &, Liste<Objet3D> &) const {
	RVB res;

	res = i.Objt()->Ambiante() * couleur;

	return res;
}


RVB Lumiere_Ponctuelle::Illumination(const Rayon & r, const Intersection3D & i, const Point3D & p, Liste<Objet3D> & lo) const {

	// TODO A FAIRE
	Rayon rayLumiere = r;
	rayLumiere.Vect(this->pos - p);
	C_Liste_Intersection li;
	rayLumiere.Intersections(li, lo);

	return RVB(.1,.1,.1);//li.Vide() ? this->Couleur() : li.Premier()->Objt()->Diffuse() * li.Premier()->Objt()->Kd();
}

