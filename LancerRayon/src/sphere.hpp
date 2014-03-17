#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "const.hpp"
#include "bases3d.hpp"
#include "sphere.hpp"
#include "intersection.hpp"
#include "objet3D.hpp"

class Sphere: public Objet3D {
protected:

	Point3D centre; // Centre de la sphere
	float rayon; // Rayon  de la sphere


public:

	Sphere() :
		Objet3D() {
		rayon = 1;
		Milieu_int(1);
		Milieu_ext(1);
	}

	virtual ~Sphere(){};

	Point3D Centre() const {
		return centre;
	}
	float SphereRayon() const {
		return rayon;
	}

	void Centre(const Point3D & c) {
		centre = c;
	}
	void SphereRayon(float r) {
		rayon = r;
	}

	Vecteur3D Normale(const Point3D &) const;
	int Intersection(const Rayon &, C_Liste_Intersection &);
};

#endif
