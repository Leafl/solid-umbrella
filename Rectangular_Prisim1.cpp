/*
 * File:   Rectangular_Prisim1.cpp
 * Author: Suzuka/Emma
 *
 * Date: October 30, 2017, 6:53 PM
 */

#include "Rectangular_Prisim1.h"

Rectangular_Prisim1::Rectangular_Prisim1()
{
    assert(false&&"Do not use default Rectangular Prism1 constructor.");
}

/** 
 * "Basic" constructor for Rectangular Prisim
 * 
 * @param _e	    e
 * @param _f	    f
 * @param _b	    b
 * @param _c	    c
 * @param _depth    depth
 */
Rectangular_Prisim1::Rectangular_Prisim1(vec3 _e, vec3 _f, vec3 _b, vec3 _c, float _depth)
{
	f=_f;

	depth=_depth;
	fillColor=vec3(1, 1, 1); //white
	borderColor=vec3(0, 0, 0); //black

	//initalize the remaining cornners
	initalizeRemainingPoints( _c,  _b,  _f,  _e,  _depth);
	buildRectangularPrisim1();
}

/**
 * "Bold semi basic" constructor for Rectangular Prisim
 * 
 * @param _e	    e
 * @param _f	    f
 * @param _b	    b
 * @param _c	    c
 * @param _depth    depth
 * @param fc	    fill color
 * @param bc	    border color
 * @param tex	    texture if it's passed in
 */
Rectangular_Prisim1::Rectangular_Prisim1(vec3 _e, vec3 _f, vec3 _b, vec3 _c, float _depth, vec3 fc, vec3 bc, Texture* tex)
{
	//draw in e, f, b, c
	e = _e;
	f = _f;
	b = _b;
	c = _c;

	depth=_depth;
	fillColor=fc;
	borderColor=bc;
	texture=tex;

	//initalize the remaining cornners
	initalizeRemainingPoints(_e, _f, _b, _c, _depth);
	buildRectangularPrisim1();
}

/**
 * Initalizes the rest of the ponts that aren't already
 * initalized.
 */
void Rectangular_Prisim1::initalizeRemainingPoints(vec3 _e, vec3 _f, vec3 _b, vec3 _c, float _depth)
{
	g = vec3(e.x, (e.y+_depth), e.z);
	h = vec3(f.x, (f.y+_depth), f.z);
	a = vec3(b.x, (b.y+_depth), b.z);
	d = vec3(c.x, (c.y+_depth), c.z);
}
/**
 * build RectangularPrisim1();
 * @pre: remaining points have been initalized correctly? hopefully?
 *
 */
void Rectangular_Prisim1::buildRectangularPrisim1()
{
	//ueses Quad1 class to build the quads, (triangle fan)
	//first point in Quad1 is the hub in terms of tirangle fan
	ein=new Quad1(h, f, b, a);//good
	zwei=new Quad1(a, b, c, d);//good
	drei=new Quad1(d, c, e, g);//good
	vier=new Quad1(g, e, f, h);//good
	fuenf=new Quad1(g, h, a, d); //top of the rectangular prisim,
	sechs=new Quad1(e, f, b, c); //bottom of the rectangular prisim

	ein->setFillColor(fillColor);
	zwei->setFillColor(fillColor);
	drei->setFillColor(fillColor);
	vier->setFillColor(fillColor);
	fuenf->setFillColor(fillColor);
	sechs->setFillColor(fillColor);

	ein->setBorderColor(borderColor);
	zwei->setBorderColor(borderColor);
	drei->setBorderColor(borderColor);
	vier->setBorderColor(borderColor);
	fuenf->setBorderColor(borderColor);
	sechs->setBorderColor(borderColor);
}

void Rectangular_Prisim1::printCoords()
{
	//vec3 _e, vec3 _f, vec3 _b, vec3 _c
	std::cout <<"\te: " << std::setw(15) << std::right <<"x: "<< float(e.x) << std::setw(15) << std::right <<"y: "<< float(e.y) << std::setw(15) << std::right <<"z: "<< float(e.z) <<std::endl;

	std::cout <<"\tf: " << std::setw(15) << std::right <<"x: "<< f.x << std::setw(15) << std::right <<"y: "<< f.y << std::setw(15) << std::right <<"z: "<< f.z <<std::endl;

	std::cout <<"\tb: " << std::setw(15) << std::right <<"x: "<< b.x << std::setw(15) << std::right <<"y: "<< b.y << std::setw(15) << std::right <<"z: "<< b.z <<std::endl;

	std::cout <<"\tc: " << std::setw(15) << std::right <<"x: "<< c.x << std::setw(15) << std::right <<"y: "<< c.y << std::setw(15) << std::right <<"z: "<< c.z <<std::endl;
}

/**
 * draws the Quads
 * @param s
 */
void Rectangular_Prisim1::draw(Shader* s)
{
	// Draw each Quad1
	ein->draw(s,texture);
	zwei->draw(s,texture);
	drei->draw(s,texture);
	vier->draw(s,texture);
	fuenf->draw(s,texture);
	sechs->draw(s,texture);
}

Rectangular_Prisim1::Rectangular_Prisim1(const Rectangular_Prisim1& orig)
{
    
}

Rectangular_Prisim1::~Rectangular_Prisim1()
{
	delete ein;
	delete zwei;
	delete drei;
	delete vier;
	delete fuenf;
	delete sechs;
	
	delete texture;
}

