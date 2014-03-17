#ifndef OBJET3D_HPP_
#define OBJET3D_HPP_

#include "couleurRVB.hpp"
#include "rayon.hpp"
#include "intersection.hpp"

class Objet3D
{
 protected:

  RVB couleur;      // Couleur generale        de l'objet
  RVB ambiante;     // Couleur ambiante        de l'objet
  RVB diffuse;      // Couleur diffuse         de l'objet
  RVB speculaire;   // Couleur speculaire      de l'objet
  RVB transparence; // Couleur de transparence de l'objet
  float     ka;           // Coefficient d'ambiance de l'objet
  float     kd;           // Coefficient de diffusion de l'objet
  float     ks;           // Coefficient de specularite de l'objet
  float     kr;           // Coefficient de reflexion de l'objet
  float     kt;           // Coefficient de transparence de l'objet
  float     milieu1;      // Indice de milieu d'un cote de l'objet
  float     milieu2;      // Indice de milieu de l'autre cote de l'objet

 public:

  // Constructeur
  Objet3D() {speculaire=RVB(1,1,1); ka=0.1; kd=1; ks=1; kr=0; kt=0;}
  virtual ~Objet3D() {}

  // Lecture
  RVB Couleur()      const {return couleur;}
  RVB Ambiante()     const {return ambiante;}
  RVB Diffuse()      const {return diffuse;}
  RVB Speculaire()   const {return speculaire;}
  RVB Transparence() const {return transparence;}
  float     Ka()           const {return ka;}
  float     Kd()           const {return kd;}
  float     Ks()           const {return ks;}
  float     Kr()           const {return kr;}
  float     Kt()           const {return kt;}
  float     Milieu1()      const {return milieu1;}
  float     Milieu_int()   const {return milieu1;}
  float     Milieu_pos()   const {return milieu1;}
  float     Milieu2()      const {return milieu2;}
  float     Milieu_ext()   const {return milieu2;}
  float     Milieu_neg()   const {return milieu2;}

  // Ecriture
  virtual void Couleur     (const RVB & c) {couleur=c; ambiante=c*ka; diffuse=c*kd; transparence=c*kt;}
  virtual void Ambiante    (const RVB & c) {ambiante=c;}
  virtual void Diffuse     (const RVB & c) {diffuse=c;}
  virtual void Speculaire  (const RVB & c) {speculaire=c;}
  virtual void Transparence(const RVB & c) {transparence=c;}
  virtual void Ka          (float a)             {ka=a; ambiante=couleur*ka;}
  virtual void Kd          (float d)             {kd=d; diffuse=couleur*kd;}
  virtual void Ks          (float s)             {ks=s; speculaire=RVB(ks,ks,ks);}
  virtual void Kr          (float r)             {kr=r;}
  virtual void Kt          (float t)             {kt=t; transparence=couleur*kt;}
  virtual void Ambiante    (float a)             {Ka(a);}
  virtual void Diffuse     (float d)             {Kd(d);}
  virtual void Speculaire  (float s)             {Ks(s);}
  virtual void Reflexion   (float r)             {Kr(r);}
  virtual void Transparence(float t)             {Kt(t);}
  virtual void Milieu1     (float m)             {milieu1=m;}
  virtual void Milieu_int  (float m)             {milieu1=m;}
  virtual void Milieu_pos  (float m)             {milieu1=m;}
  virtual void Milieu2     (float m)             {milieu2=m;}
  virtual void Milieu_ext  (float m)             {milieu2=m;}
  virtual void Milieu_neg  (float m)             {milieu2=m;}

  // Methodes
  virtual int Intersection(const Rayon &,C_Liste_Intersection &) = 0;
};


#endif /* OBJET3D_HPP_ */
