#ifndef PLAN_HPP
#define PLAN_HPP

#include "const.hpp"
#include "bases3d.hpp"
#include "objet3D.hpp"
#include "intersection.hpp"
#include "rayon.hpp"


class Plan: public Objet3D {
protected:

	float a, b, c, d; // coefficients normalises du plan
					  // le vecteur (a,b,c) est orthogonal au plan
public:

	// Constructeur
	Plan() :
		Objet3D() {
		// Par defaut, on cree le plan (xOy)
		a = b = d = 0;
		c = 1;

		Milieu_pos(1);
		Milieu_neg(1);
	}

	void depuisVetP(Vecteur3D v, const Point3D & p);

	Vecteur3D Normale() const {
		return Vecteur3D(a, b, c);
	}

	float Distance(const Point3D &) const;

	// Methodes
	int Intersection(const Rayon &, C_Liste_Intersection &);
};

#endif

