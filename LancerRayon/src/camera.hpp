#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "const.hpp"
#include "bases3d.hpp"
#include "pixelmap.hpp"

class Objet3D;
class Lumiere;

class Camera {
protected:

	Point3D centre; // Centre de l'ecran de la camera
	float largeur; // Largeur de l'ecran
	float hauteur; // Hauteur de l'ecran
	float dist; // Distance focale de la camera
	Vecteur3D dir; // Direction de vue de la camera
	Vecteur3D haut; // Vecteur definissant l'orientation de la "tete" de la camera

public:

	Camera() {
		centre = Point3D(0, 0, -1);
		largeur = hauteur = 2;
		dist = 10;
		dir = Vecteur3D(0, 0, 1);
		haut = Vecteur3D(0, 1, 0);
	}

	Point3D Centre() const {
		return centre;
	}
	float Largeur() const {
		return largeur;
	}
	float Hauteur() const {
		return hauteur;
	}
	float Dist() const {
		return dist;
	}
	Vecteur3D Dir() const {
		return dir;
	}
	Vecteur3D Haut() const {
		return haut;
	}

	void Centre(const Point3D & c) {
		centre = c;
	}
	void Largeur(float l) {
		largeur = l;
	}
	void Hauteur(float h) {
		hauteur = h;
	}
	void Dist(float d) {
		dist = d;
	}
	void Dir(const Vecteur3D & d) {
		dir = d;
		dir.Normaliser();
	}
	void Dir(const Point3D & c) {
		dir = c - centre;
		dir.Normaliser();
	}
	void Haut(const Vecteur3D &);

	void Calculer_image(Pixelmap &, Liste<Objet3D> &, Liste<Lumiere> &, int) const;
};

#endif
