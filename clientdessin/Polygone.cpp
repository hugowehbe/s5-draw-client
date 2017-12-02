#include <sstream>
#include "VisiteurDessiner.h"
#include "Polygone.h"

/**
* @param xCentre
* @param yCentre
* @param rayon
*/



Polygone::Polygone(int couleur) : Forme(couleur)
{
	
}

Polygone::Polygone(Polygone & p) : Forme(p)
{
	_nbCotes = p._nbCotes;
	_vecteurs = p._vecteurs;
	_cotes = p._cotes;
}


void Polygone::dessiner(VisiteurDessiner * visiteurDessiner) const
{
	return visiteurDessiner->visite(this);

}

//Translation fausse mais retour faux pour �viter les erreurs de compilo
/*virtual*/ Forme * Polygone::translation(const Vecteur2D & VectTrans) const {

	
	return new Polygone(getCouleur());

}

/*virtual*/ Forme * Polygone::homothetie(const Vecteur2D & point, const double & rapport) const {

	return new Polygone(getCouleur());

}

/*virtual*/ double Polygone::aire() const {
	return 0;
}

void Polygone::Construction() {
	
		for (int i = 1; i < _vecteurs.size(); i++) {
			_cotes.push_back(Segment(getCouleur(), _vecteurs[i-1], _vecteurs[i]));
			_nbCotes++;
		}
		_cotes.push_back(Segment(getCouleur(), _vecteurs[_vecteurs.size() - 1], _vecteurs[0]));
		_nbCotes++;
	
}

/*virtual*/ Forme * Polygone::rotation(const Vecteur2D & centre, const double & angle) const {


	return new Polygone(getCouleur());

}

Polygone::operator string() const
{
	ostringstream oss;

	//oss << "Polygone : " << "Centre = " << _centre << ", rayon = " << _rayon;
	oss << "Test";
	return oss.str();
}

Polygone Polygone::operator=(const Polygone & p)
{	
	_vecteurs = p._vecteurs;
	_cotes = p._cotes;
	this->Construction();
	return *this;

}

Polygone & Polygone::operator+=(const Vecteur2D & v)
{
	_vecteurs.push_back(v);
	return *this;
}

Polygone Polygone::operator+(const Vecteur2D & v)
{
	Polygone p = Polygone(*this);
	p += v;
	return p;
}

vector<Vecteur2D> Polygone::getVecteurs() const
{
	return _vecteurs;
}

void Polygone::setVecteurs(vector<Vecteur2D> v)
{
	_vecteurs = v;
}

vector<Segment> Polygone::getCotes() const
{
	return _cotes;
}

void Polygone::setCotes(vector<Segment> s)
{
	_cotes = s;
}

int Polygone::getNbCotes() const
{
	return _nbCotes;
}

void Polygone::setNbCotes(int nbCotes)
{
	_nbCotes = nbCotes;
}

ostream & operator << (ostream & os, const Polygone * p)
{
	return os;
}

const string Polygone::encoderForme() const
{
	ostringstream oss;
	for (Segment s : _cotes) {
		oss << s.encoderForme();
	}
	return oss.str();
}

const string Polygone::encoderFenetre() const
{
	ostringstream oss;
	oss << "Polygone, " << 0 << ", " << 0 << ", " << 500 << ", " << 500 << "\r\n";
	return oss.str();
}



