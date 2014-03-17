#include <math.h>
#include <iostream>
#include "sphere.hpp"


Vecteur3D Sphere::Normale(const Point3D & t) const {
	Vecteur3D res(centre, t);
	res.Normaliser();
	return res;
}


int Sphere::Intersection(const Rayon & r, C_Liste_Intersection & l) {
	// TODO A vérifier
	Vecteur3D dirRay = r.Vect(); /*!< Direction du rayon */
	dirRay.Normaliser();

	Vecteur3D dirCentre = r.Orig() - this->Centre(); /*!< Vecteur entre origine du rayon et centre de la sphere */

	//On cherche à résoudre une équation définie
	//par un polynôme du second degré où a=1
	float b = (dirCentre * dirRay) * 2;
	float c = (dirCentre * dirCentre) - (this->rayon * this->rayon);

	//Calcul du delta et recherche des solutions
	float d = (b*b) - (4.0*c);
	if(d < 0.0){
		return false;
	}
	float rootD = sqrt(d);
	float t0 = 0.5 * (-b - rootD);
	float t1 = 0.5 * (-b + rootD);

	if(t0 >= 0.0 || t1 >= 0.0){
		float t = (t0 >= 0.0 ? t0 : t1);

		float dist = (r.Vect()*t).Longueur();
		l.Ajouter(Intersection3D(dist,this,r.Milieu()));
		return true;
	}
	return false; //TODO A modifier
}
