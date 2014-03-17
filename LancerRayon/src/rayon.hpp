#ifndef RAYON_HPP_
#define RAYON_HPP_

#include "bases3d.hpp"
#include "intersection.hpp"
#include "liste.hpp"

class Lumiere;
class Objet3D;
class RVB;

class Rayon {
protected:

	Point3D orig; // Origine du rayon
	Vecteur3D vect; // Vecteur directeur (oriente) du rayon
	float milieu; // Indice courant du milieu du rayon

	static const int MAX_RECUR = 100; /*!< Profondeur maximale autorisée pour la récurrence */

public:

	Rayon() {
		milieu = 1;
	}

	// Lecture
	Point3D Orig() const {
		return orig;
	}
	Vecteur3D Vect() const {
		return vect;
	}
	float Milieu() const {
		return milieu;
	}

	// Ecriture
	void Orig(const Point3D & o) {
		orig = o;
	}
	void Vect(const Vecteur3D & v) {
		vect = v;
		vect.Normaliser();
	}
	void Milieu(float m) {
		milieu = m;
	}

	// Methodes
	int Intersections(C_Liste_Intersection &, Liste<Objet3D> &) const;
	RVB Lancer(Liste<Objet3D> &, Liste<Lumiere> &, int) const;
};

#endif /* RAYON_HPP_ */
