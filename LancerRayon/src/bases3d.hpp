#ifndef BASES3D_HPP
#define BASES3D_HPP

#include <stdlib.h>
#include "liste.hpp"

class Vecteur3D;

class Point3D {
protected:

	float x, y, z;

public:

	Point3D() {
		x = y = z = 0;
	}

	Point3D(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	float X() const {
		return x;
	}
	float Y() const {
		return y;
	}
	float Z() const {
		return z;
	}

	void X(float _x) {
		x = _x;
	}
	void Y(float _y) {
		y = _y;
	}
	void Z(float _z) {
		z = _z;
	}

	Point3D operator +(const Vecteur3D &) const; // P2=P1+V
	Point3D operator -(const Vecteur3D &) const; // P2=P1-V
	Vecteur3D operator -(const Point3D &) const; // V =P2-P1

};

// ------------------------------------------------------------

class Vecteur3D {
protected:

	float x, y, z;

public:

	Vecteur3D() {
		x = y = z = 0;
	}

	Vecteur3D(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	Vecteur3D(const Point3D & p) {
		x = p.X();
		y = p.Y();
		z = p.Z();
	}

	Vecteur3D(const Point3D & p1, const Point3D & p2) {
		x = p2.X() - p1.X();
		y = p2.Y() - p1.Y();
		z = p2.Z() - p1.Z();
	}

	float X() const {
		return x;
	}
	float Y() const {
		return y;
	}
	float Z() const {
		return z;
	}
	int Nul() const {
		return ((x == 0) && (y == 0) && (z == 0));
	}

	void X(float _x) {
		x = _x;
	}
	void Y(float _y) {
		y = _y;
	}
	void Z(float _z) {
		z = _z;
	}

	float Longueur() const;
	void Normaliser();
	Vecteur3D operator +(const Vecteur3D &) const; // V3=V1+V2
	Vecteur3D operator -(const Vecteur3D &) const; // V3=V1-V2
	Vecteur3D operator -() const; // V2=-V1
	Vecteur3D operator *(float) const; // V2=V1.k
	float operator *(const Vecteur3D &) const; // k =V1.V2
	Vecteur3D Cross(const Vecteur3D &) const; // V3=V1xV2

	// Resultat de la reflexion du vecteur selon une normale en parametre
	// (les vecteurs doivent etres normalises)
	Vecteur3D Reflechir(const Vecteur3D &) const;

	/**
	 * Resultat de la refraction du vecteur selon un axe en parametre
	 * (le vecteur et la normale doivent etres normalises)
	 * les parametres suivants sont les indices des milieux
	 */
	Vecteur3D Refracter(const Vecteur3D &, float, float) const;
};

#endif
