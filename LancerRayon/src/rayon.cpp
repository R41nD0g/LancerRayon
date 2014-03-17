#include "rayon.hpp"
#include "objet3D.hpp"
#include "lumiere.h"


int Rayon::Intersections(C_Liste_Intersection & li, Liste<Objet3D> & lo) const {
	// Il n'y a pas d'intersection au depart
	li.Vider();

	// Pour chaque objet 3D
	for (lo.Premier(); lo.Courant() != 0; lo.Suivant())
		lo.Courant()->Intersection(*this, li);

	return !(lo.Vide());
}

RVB Rayon::Lancer(Liste<Objet3D> & lo, Liste<Lumiere> & ll, int recur) const {
	RVB res;
	Objet3D* intersecte;
	C_Liste_Intersection li; /*!< Liste des intersections */

	this->Intersections(li, lo);
	if(li.Vide())
		return RVB(0,0,0); //TODO A modifier
	//else

	intersecte = li.Premier()->Objt();
	res = intersecte->Couleur();

	for(ll.Premier() ; ll.Courant() != 0 ; ll.Suivant()){
		//TODO Trouver à quoi correspond quel paramètre
		res += ll.Courant()->Illumination(*this,*(li.Premier()), this->Orig() + (this->Vect() * li.Premier()->Dist()), lo);
	}

	//Condition d'arrêt : profondeur trop importante
	if(recur < MAX_RECUR){
		//Rayon réfléchi
		Rayon rayReflechi;
		rayReflechi.Orig(this->Orig() + (this->Vect() * li.Premier()->Dist()));
		rayReflechi.Vect(this->Vect().Reflechir(li.Premier()->Norm()));
		res += rayReflechi.Lancer(lo, ll, recur+1) * intersecte->Kr();


		//Rayon réfracté
		/*Rayon rayRefracte;
		rayRefracte.Orig(this->Orig() + (this->Vect() * li.Premier()->Dist()));
		rayRefracte.Vect(this->Vect().Refracter(li.Premier()->Norm(), this->Milieu(), li.Premier()->Milieu()));
		res += rayRefracte.Lancer(lo, ll, recur+1) * intersecte->Kt();*/
	}

	return res;
}

