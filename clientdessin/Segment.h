#pragma once
#include "Vecteur2D.h"
#include "Forme.h"

/**
cf. classe JAVA de m�me nom

*/
class Segment : public Forme
{
private:
	Vecteur2D _x, _y;
public:
	Segment(int couleur, Vecteur2D x, Vecteur2D y);
	Segment(Segment &s);
	/**
	* @param x
	* @param y
	*/
	Segment(const double x, const double y);

	Vecteur2D getX() const;
	Vecteur2D getY() const;
	void setX(Vecteur2D x);
	void setY(Vecteur2D y);


	void dessiner(VisiteurDessiner * visiteurDessiner) const;
	const Segment translation(const Vecteur2D & VectTrans);
	
	operator string() const;

};

