#ifndef LUMIERE_H_
#define LUMIERE_H_

#include "couleurRVB.hpp"
#include "rayon.hpp"
#include "intersection.hpp"

class Lumiere {
protected:
	RVB couleur; // Couleur de la lumiere

public:
	Lumiere() {
		couleur = RVB(1, 1, 1);
	}

	RVB Couleur() const {
		return couleur;
	}

	void Couleur(const RVB & c) {
		couleur = c;
	}

	virtual RVB Illumination(const Rayon &, const Intersection3D &, const Point3D &, Liste<Objet3D> &) const = 0;

};



class Lumiere_Ambiante: public Lumiere {
public:
	RVB Illumination(const Rayon &, const Intersection3D &, const Point3D &, Liste<Objet3D> &) const;
};



class Lumiere_Ponctuelle: public Lumiere {
protected:
	Point3D pos; // Position de la lumiere

public:
	Point3D Pos() const {
		return pos;
	}

	void Pos(const Point3D & p) {
		pos = p;
	}

	RVB Illumination(const Rayon &, const Intersection3D &, const Point3D &, Liste<Objet3D> &) const;
};

#endif
