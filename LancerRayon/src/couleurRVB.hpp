#ifndef COULEURRVB_HPP
#define COULEURRVB_HPP

class RVB {
protected:

	float r, v, b;

public:

	// Constructeur
	RVB() {
		r = v = b = 0;
	}
	RVB(float _r, float _v, float _b) {
		r = _r;
		v = _v;
		b = _b;
	}

	// Lecture
	float R() const {
		return r;
	}
	float V() const {
		return v;
	}
	float B() const {
		return b;
	}
	int Nulle() const {
		return ((r == 0) && (v == 0) && (b == 0));
	}

	// Ecriture
	void R(float _r) {
		r = _r;
	}
	void V(float _v) {
		v = _v;
	}
	void B(float _b) {
		b = _b;
	}

	// Operations
	RVB operator +(const RVB &) const;
	RVB operator -(const RVB &) const;
	RVB operator *(float) const;
	RVB operator *(const RVB &) const;
	RVB & operator +=(const RVB &);
	RVB & operator -=(const RVB &);
	RVB & operator *=(float);
	RVB & operator *=(const RVB &);

	// Methodes
	RVB Melanger(const RVB &, float) const;
	void Borner(float, float);

};

#endif
