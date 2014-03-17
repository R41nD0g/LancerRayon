#include "couleurRVB.hpp"

// --------------------------------------------------------------------------
//
// Methodes (et operations) sur les couleurs
//
// --------------------------------------------------------------------------

RVB RVB::operator +(const RVB & c) const {
	RVB res;

	res.r = r + c.r;
	res.v = v + c.v;
	res.b = b + c.b;

	return res;
}

RVB RVB::operator -(const RVB & c) const {
	RVB res;

	res.r = r - c.r;
	res.v = v - c.v;
	res.b = b - c.b;

	return res;
}

RVB RVB::operator *(float m) const {
	RVB res;

	res.r = r * m;
	res.v = v * m;
	res.b = b * m;

	return res;
}

RVB RVB::operator *(const RVB & c) const {
	RVB res;

	res.r = r * c.r;
	res.v = v * c.v;
	res.b = b * c.b;

	return res;
}

RVB & RVB::operator +=(const RVB & c) {
	r += c.r;
	v += c.v;
	b += c.b;

	return *this;
}

RVB & RVB::operator -=(const RVB & c) {
	r -= c.r;
	v -= c.v;
	b -= c.b;

	return *this;
}

RVB & RVB::operator *=(float m) {
	r *= m;
	v *= m;
	b *= m;

	return *this;
}

RVB & RVB::operator *=(const RVB & c) {
	r *= c.r;
	v *= c.v;
	b *= c.b;

	return *this;
}

RVB RVB::Melanger(const RVB & c, float m) const {
	RVB res;

	// On borne le coefficient de melange par l'intervalle [0,1]
	if (m > 1)
		m = 1;
	if (m < 0)
		m = 0;

	res.r = (r * (1 - m)) + (c.r * m);
	res.v = (v * (1 - m)) + (c.v * m);
	res.b = (b * (1 - m)) + (c.b * m);

	return res;
}

void RVB::Borner(float min, float max) {
	if (r < min)
		r = min;
	if (v < min)
		v = min;
	if (b < min)
		b = min;
	if (r > max)
		r = max;
	if (v > max)
		v = max;
	if (b > max)
		b = max;
}

