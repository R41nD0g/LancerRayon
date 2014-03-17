#include <stdio.h>
#include <string>
#include "bases3d.hpp"
#include "plan.hpp"
#include "sphere.hpp"
#include "camera.hpp"
#include "pixelmap.hpp"
#include "intersection.hpp"
#include "lumiere.h"
#include "rayon.hpp"
#include "objet3D.hpp"

int main(void) {
	// Les lumieres
	Liste<Lumiere> liste_lumieres;
	// Les objets
	Liste<Objet3D> lisobj;
	// Une image Pixelmap
	//Pixelmap pixmap(900, 670);
	Pixelmap pixmap(400, 300);
	// Une image Bitmap
	Image bitmap;
	std::string nomImage = "image.bmp";

	// Initialisation des lumieres
	Lumiere_Ambiante ambiante;
	ambiante.Couleur(RVB(0.1, 0.1, 0.1));
	liste_lumieres.Ajouter(&ambiante);

	Lumiere_Ponctuelle ponctuelle;
	ponctuelle.Couleur(RVB(0.9, 0.9, 0.9));
	ponctuelle.Pos(Point3D(-1, 40, 10));
	liste_lumieres.Ajouter(&ponctuelle);

	// Initialisation des objets==============================

	// Le plan horizontal : le sol
	Plan sol;
	sol.depuisVetP(Vecteur3D(0, 1, 0), Point3D(0, 0, 0));
	sol.Couleur(RVB(0.75, 1, 0.75));
	sol.Reflexion(0.6);
	lisobj.Ajouter(&sol);

	// Le plan vertical : le mur
	Plan mur;
	mur.depuisVetP(Vecteur3D(0.2, 0, 1), Point3D(0, 0, -10));
	mur.Couleur(RVB(0.95, 0.55, 0.25));
	mur.Ambiante(0.1);
	mur.Reflexion(0.0);
	lisobj.Ajouter(&mur);

	// La moyenne sphere
	Sphere spher1;
	spher1.Centre(Point3D(1, 4, 0));
	spher1.SphereRayon(2);
	spher1.Couleur(RVB(1, 0, 0));
	spher1.Transparence(0);
	spher1.Milieu_int(1);
	spher1.Reflexion(0);
	spher1.Speculaire(RVB(1,0,1));
	spher1.Ks(0.6);
	spher1.Diffuse(RVB(1,0,1));
	spher1.Kd(0.8);
	spher1.Ka(0.3);
	lisobj.Ajouter(&spher1);

	// La grosse sphere
	Sphere spher2;
	spher2.Centre(Point3D(-8, 8, 0.5));
	spher2.SphereRayon(3);
	spher2.Couleur(RVB(0, 1, 0));
	spher2.Reflexion(0.75);
	lisobj.Ajouter(&spher2);

	// Une sphere en verre
	Sphere spher3;
	spher3.Centre(Point3D(3.5, 4, 5));
	spher3.SphereRayon(1);
	spher3.Couleur(RVB(0, 0, 1));
	spher3.Transparence(0.85);
	spher3.Reflexion(0.15);
	spher3.Milieu_int(1.5);
	lisobj.Ajouter(&spher3);

	// la Camera
	Camera cam;
	cam.Centre(Point3D(0, 5, 12));
	cam.Dir(Point3D(0, 1, 0));
	cam.Dist(125.0);
	cam.Haut(Vecteur3D(0, 1, 0));
	cam.Largeur((5.6 * 513) / 384);
	cam.Hauteur(5.6);

	cam.Calculer_image(pixmap, lisobj, liste_lumieres, 20);

	pixmap.Transferer(bitmap);
	bitmap.Enregistrer(nomImage.c_str());

	return 0;
}
