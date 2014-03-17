#ifndef INTERSECTION_HPP_
#define INTERSECTION_HPP_

#include "bases3d.hpp"

class Objet3D;

class Intersection3D {
protected:

	// Donnees diverses sur l'intersection
	float dist; // Distance entre le point d'intersection et l'origine du rayon
	Objet3D * objt; // Objet intersecte par le rayon

	// Donnees pour la reflexion
	Vecteur3D norm; // Normale de l'objet au point d'intersection

	// Donnees pour la refraction
	float milieu; // Indice de milieu apres l'intersection

public:

	// Constructeur
	Intersection3D() {
		dist = 0;
		objt = 0;
		milieu = 1;
	}
	Intersection3D(float d, Objet3D * o, float m) {
		dist = d;
		objt = o;
		milieu = m;
	}

	// Lecture
	float Dist() const {
		return dist;
	}
	Objet3D * Objt() const {
		return objt;
	}
	Vecteur3D Norm() const {
		return norm;
	}
	float Milieu() const {
		return milieu;
	}

	// Ecriture
	void Dist(float d) {
		dist = d;
	}
	void Objt(Objet3D * const o) {
		objt = o;
	}
	void Norm(const Vecteur3D & n) {
		norm = n;
		norm.Normaliser();
	}
	void Milieu(float m) {
		milieu = m;
	}

	// Operations
	int operator <(const Intersection3D & i) const {
		return dist < i.dist;
	}
	int operator >(const Intersection3D & i) const {
		return dist > i.dist;
	}
};

//////////////////////////////////////////////////////// LISTE_INTERSECTION

// Les listes d'intersections sont toujours triees dans l'ordre croissant

struct S_Maillon_Intersection {
	S_Maillon_Intersection * prev; // Pointeur vers le maillon precedent
	Intersection3D * inter; // Pointeur vers l'intersection
	S_Maillon_Intersection * next; // Pointeur vers le maillon suivant
};

class C_Liste_Intersection {
protected:

	S_Maillon_Intersection * tete; // Premier element de la liste
	S_Maillon_Intersection * queue; // Dernier element de la liste
	S_Maillon_Intersection * cour; // Element courant de la liste

public:

	// Constructeur
	C_Liste_Intersection() {
		tete = queue = cour = 0;
	}

	// Destructeur
	~C_Liste_Intersection() {
		Vider();
	}

	// Lecture
	Intersection3D * Premier();
	Intersection3D * Dernier();
	Intersection3D * Courant() const;
	Intersection3D * Suivant();
	Intersection3D * Precedent();

	// Ecriture
	void Ajouter(const Intersection3D &);
	void Ajouter(const C_Liste_Intersection &);
	void Vider();

	// Methodes
	int Vide() const {
		return tete == 0;
	}

	// Operations
	C_Liste_Intersection & operator +=(const Intersection3D & i) {
		Ajouter(i);
		return *this;
	}
};

#endif /* INTERSECTION_HPP_ */
