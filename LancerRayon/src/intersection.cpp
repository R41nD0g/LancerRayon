#include "intersection.hpp"
#include "const.hpp"


Intersection3D * C_Liste_Intersection::Premier() {
	// On elimine le cas d'une liste vide
	if (tete == 0)
		return 0;

	cour = tete;
	return cour->inter;
}

Intersection3D * C_Liste_Intersection::Dernier() {
	// On elimine le cas d'une liste vide
	if (tete == 0)
		return 0;

	cour = queue;
	return cour->inter;
}

Intersection3D * C_Liste_Intersection::Courant() const {
	// On elimine le cas d'une liste vide ou epuisee
	if (cour == 0)
		return 0;

	return cour->inter;
}

Intersection3D * C_Liste_Intersection::Suivant() {
	// On elimine le cas d'une liste epuisee
	if (cour == 0)
		return 0;

	cour = cour->next;

	if (cour == 0)
		return 0;
	else
		return cour->inter;
}

Intersection3D * C_Liste_Intersection::Precedent() {
	// On elimine le cas d'une liste epuisee
	if (cour == 0)
		return 0;

	cour = cour->prev;

	if (cour == 0)
		return 0;
	else
		return cour->inter;
}

void C_Liste_Intersection::Ajouter(const Intersection3D & i) {
	S_Maillon_Intersection * nm; // Nouveau maillon
	Intersection3D * ni; // Nouvelle intersection
	S_Maillon_Intersection * mc; // Maillon en cours d'etude

	// On se debarrase des cas d'intersections avant le depart du rayon
	if (i.Dist() > EPSILON) {
		// On cree une nouvelle intersection pour y stocker les infos
		ni = new Intersection3D;
		// On copie les informations de l'intersection a ajouter
		(*ni) = i;

		// On cree un nouveau maillon pour la liste
		nm = (S_Maillon_Intersection *) malloc(sizeof(S_Maillon_Intersection));
		// On le renseigne
		nm->prev = 0;
		nm->inter = ni;
		nm->next = 0;

		// On traite le cas d'une liste vide
		if (tete == 0) {
			tete = queue = cour = nm;
		} else {
			// On regarde s'il ne faut pas le placer en fin de liste
			if (i > (*queue->inter)) {
				nm->prev = queue;
				queue->next = nm;
				queue = nm;
			} else {
				// On cherche devant quel maillon inserer ce nouvel element

				mc = tete;
				while (i > (*mc->inter))
					mc = mc->next;

				// Et on insere le nouveau maillon devant
				nm->prev = mc->prev;
				nm->next = mc;
				if (mc->prev != 0)
					mc->prev->next = nm;
				mc->prev = nm;
				if (mc == tete)
					tete = nm;
			}
		}
	}
}

void C_Liste_Intersection::Ajouter(const C_Liste_Intersection & l) {
	S_Maillon_Intersection * mc; // Maillon en cours d'etude

	// Pour chaque intersection de la liste a ajouter
	for (mc = l.tete; mc != 0; mc = mc->next)
		// On ajoute a la liste actuelle l'intersection a ajouter
		Ajouter(*mc->inter);
}

void C_Liste_Intersection::Vider() {
	S_Maillon_Intersection * m; // Maillon courant

	while (tete != 0) {
		if (tete->inter != 0)
			delete tete->inter;

		m = tete;
		tete = tete->next;
		free(m);
	}

	tete = queue = cour = 0;
}
