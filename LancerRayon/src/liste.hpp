#ifndef LISTE_HPP_
#define LISTE_HPP_

template<class Item>
struct Maillon {
	Maillon * prev; // Pointeur vers le maillon precedent
	Item * item; // Pointeur vers l'element
	Maillon * next; // Pointeur vers le maillon suivant
};

template<class Item>
class Liste {
protected:

	Maillon<Item> * tete;
	Maillon<Item> * queue;
	Maillon<Item> * cour;
	int nb_item;

public:

	Liste() {
		tete = queue = cour = 0;
		nb_item = 0;
	}

	~Liste();

	// Lecture
	Item * Premier();
	Item * Dernier();
	Item * Courant() const;
	Item * Suivant();
	Item * Precedent();
	int Nb_item() const {
		return nb_item;
	}

	void Ajouter(Item * p);

	int Vide() const {
		return nb_item == 0;
	}
};

template<class Item>
Item * Liste<Item>::Premier() {
	if (tete == 0)
		return 0;

	cour = tete;
	return cour->item;
}

template<class Item>
Item * Liste<Item>::Dernier() {
	if (queue == 0)
		return 0;

	cour = queue;
	return cour->item;
}

template<class Item>
Item * Liste<Item>::Courant() const {
	if (cour == 0)
		return 0;

	return cour->item;
}

template<class Item>
Item * Liste<Item>::Suivant() {
	if (cour == 0)
		return 0;

	cour = cour->next;

	if (cour == 0)
		return 0;
	else
		return cour->item;
}

template<class Item>
Item * Liste<Item>::Precedent() {
	if (cour == 0)
		return 0;

	cour = cour->prev;

	if (cour == 0)
		return 0;
	else
		return cour->item;
}

template<class Item>
void Liste<Item>::Ajouter(Item * i) {
	Maillon<Item> * nm;
	nm = (Maillon<Item> *) malloc(sizeof(Maillon<Item> ));
	nm->prev = 0;
	nm->item = i;
	nm->next = tete;
	if (tete == 0) {
		cour = queue = nm;
	} else {
		tete->prev = nm;
	}

	tete = nm;
	nb_item++;
}

template<class Item>
Liste<Item>::~Liste() {
	Maillon<Item> * m;
	while (tete != 0) {
		m = tete;
		tete = tete->next;
		free(m);
	}
	tete = queue = cour = 0;
	nb_item = 0;
}

#endif
