#include "camera.hpp"
#include "bases3d.hpp"
#include "pixelmap.hpp"
#include "rayon.hpp"
#include "rayon.hpp"
#include <stdio.h>
#include <iostream>

void Camera::Haut(const Vecteur3D & h) {

	haut = h - (dir * (dir * h));
	if (!haut.Nul())
		haut.Normaliser();
}

/**
 * Calculer la valeur de l'ensemble des pixels du viewport
 * @param pm
 * @param lo
 * @param ll
 * @param complexite
 */
void Camera::Calculer_image(Pixelmap & pm, Liste<Objet3D> & lo, Liste<Lumiere> & ll, int complexite) const {
	/**Coordonn�es du rep�re (u abscisse, v ordonn�e, w profondeur)*/
	Vecteur3D u,v,w;
	Vecteur3D ray;/*!< Vecteur du rayon � lancer */
	Point3D corner; /*!< Coin sup�rieur gauche de l'image */
	Point3D p; /*!< Point actuel */
	Rayon r; /*!< Rayon � lancer */
	RVB couleur; /*!< Couleur du point actuel */

	//D�terminer rep�re local � la cam�ra
	w = this->Dir();
	w.Normaliser();
	u = w.Cross(this->Haut());
	u.Normaliser();
	v = u.Cross(w);
	v.Normaliser();

	//D�terminer le coin sup�rieur gauche de l'image
	corner = this->Centre() + w*Dist() - u*(pm.Largeur()/2) + v*(pm.Hauteur()/2);
	//corner = this->Centre() - u*(pm.Largeur()*0.5) + v*(pm.Hauteur()*0.5) + w*this->Dist();

	//El�ments constants du rayon � lancer
	r.Orig(this->Centre());

	//TODO A faire
	for(int i = 0 ; i < pm.Largeur() ; i++){
		for(int j = 0 ; j < pm.Hauteur() ; j++){
			//Rep�rer le pixel recherch�
			p = corner + u*i - v*j;
			//R�cup�rer le vecteur du rayon � lancer
			ray = p - this->Centre();
			ray.Normaliser();

			//Trouver couleur
			r.Vect(ray);
			couleur = r.Lancer(lo, ll, 1);
			pm.Map(i, j, couleur);
			//std::cout << couleur.R() << ", " << couleur.V() << ", " << couleur.B() << std::endl;
		}
	}
	std::cout << "Calcul termin�" << std::endl;
}
