#include <math.h>
#include "bases3d.hpp"

Point3D Point3D::operator +(const Vecteur3D & v) const {
	Point3D res;

	res.X(x + v.X());
	res.Y(y + v.Y());
	res.Z(z + v.Z());

		return res;
}

Point3D Point3D::operator -(const Vecteur3D & v) const {
	Point3D res;

	res.X(x - v.X());
	res.Y(y - v.Y());
	res.Z(z - v.Z());

	return res;

}

Vecteur3D Point3D::operator -(const Point3D & p) const {
	Vecteur3D v(p, *this);

	return v;
}


// --------------------------------------------------------------------------

float Vecteur3D::Longueur() const {
	return sqrt((x * x) + (y * y) + (z * z));
}

void Vecteur3D::Normaliser() {
	float norme = Longueur();
	x /= norme;
	y /= norme;
	z /= norme;
}

Vecteur3D Vecteur3D::operator +(const Vecteur3D & v) const {
	Vecteur3D res;

	res.X(x + v.X());
	res.Y(y + v.Y());
	res.Z(z + v.Z());

	return res;
}

Vecteur3D Vecteur3D::operator -(const Vecteur3D & v) const {
	Vecteur3D res;

	res.X(x - v.X());
	res.Y(y - v.Y());
	res.Z(z - v.Z());

	return res;
}

Vecteur3D Vecteur3D::operator -() const {
	Vecteur3D res;

	res.X(- x);
	res.Y(-y);
	res.Z(-z);

	return res;
}

Vecteur3D Vecteur3D::operator *(float m) const {
	Vecteur3D res;

	res.X(x * m);
	res.Y(y * m);
	res.Z(z * m);

	return res;
}

float Vecteur3D::operator *(const Vecteur3D & v) const {
	return ((x * v.x) + (y * v.y) + (z * v.z));
}

Vecteur3D Vecteur3D::Cross(const Vecteur3D & v) const {
	Vecteur3D res;

	res.x = (y * v.Z()) - (z * v.Y());
	res.y = (z * v.X()) - (x * v.Z());
	res.z = (x * v.Y()) - (y * v.X());

	return res;
}

Vecteur3D Vecteur3D::Reflechir(const Vecteur3D & n) const { //TODO
	Vecteur3D res = (*this) - (n * (2 * (n * (*this))));

	return res;
}

/**
 * Vecteur issu de la réfraction entre deux milieux
 * @param norm Le vecteur normal à la surface de séparation des deux milieux
 * @param m1 L'indice de réfraction du premier milieu
 * @param m2 L'indice de réfraction du second milieu
 * @return Le vecteur issu de la réfraction
 */
Vecteur3D Vecteur3D::Refracter(const Vecteur3D & norm, float m1, float m2) const {
	Vecteur3D res;
	double angle; /*!< Angle entre le vecteur réfracté et la norme (radians) */

	// TODO A FAIRE

	//Récupérer l'angle
	angle = asin((m1 / m2) * sin(acos(norm.Longueur() / this->Longueur())));

	//Recherche longueur et direction
	//TODO à faire
	//res.

	return res;
}

