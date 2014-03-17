#include <math.h>
#include "plan.hpp"
#include "bases3d.hpp"

// --------------------------------------------------------------------------
//
// Methodes (et operations) sur les objets 3D "plan"
//
// --------------------------------------------------------------------------


float Plan::Distance(const Point3D & p) const {
	return ((a * p.X()) + (b * p.Y()) + (c * p.Z()) + d);
}


void Plan::depuisVetP(Vecteur3D v,const Point3D & p) {
	v.Normaliser();

	a = v.X();
	b = v.Y();
	c = v.Z();
	d = -((a * p.X()) + (b * p.Y()) + (c * p.Z()));
}


int Plan::Intersection(const Rayon & r, C_Liste_Intersection & l) {
	float cosalpha; // Cosinus de l'angle entre le vecteur directeur du rayon et la normale au plan
	float dist; // Distance entre l'origine du rayon et le plan
	Intersection3D i; // Intersection entre le rayon et le plan

	cosalpha = Normale() * r.Vect();

	if (cosalpha == 0) {
		// Les deux vecteurs sont perpendiculaires, donc le rayon est paralelle
		// au plan. Pour simplifier on decide que c'est un cas de
		// non-intersection.

		return 0;
	} else {
		// Il existe un point d'intersection
		dist = Distance(r.Orig());

		// On initialise l'intersection
		i.Dist(-(dist / cosalpha));
		i.Objt(this);
		i.Norm(Normale());
		if (dist > 0)
			i.Milieu(Milieu_neg());
		else
			i.Milieu(Milieu_pos());

		// Puis on la rajoute dans la liste des intersections
		l.Ajouter(i);

		// Et on dit qu'il y a eu intersection
		return 1;
	}
}
