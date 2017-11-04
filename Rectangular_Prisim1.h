/*
 * File:   Rectangular_Prisim1.h
 * Author: Suzuka
 *
 * Date: October 30, 2017, 6:53 PM
 *
 * Rectangular Prisim uses Quad1 (Triangle fans)
 *
 * some code borrowed from StuetzleC's "tectrahedron" (cube class)
 */

#ifndef RECTANGULAR_PRISIM1_H
#define RECTANGULAR_PRISIM1_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <stdio.h>

#include "Rectangular_Prisim1.h"
#include "DrawableObject.h"
#include "Triangle.hpp"
#include "Texture.hpp"
#include "Shader.hpp"
#include "Vertex.hpp"
#include "Quad1.h"

using glm::vec3;
class Triangle;

class Rectangular_Prisim1: public DrawableObject
{
public:
	Rectangular_Prisim1();
	Rectangular_Prisim1(const Rectangular_Prisim1& orig);
	
	//rectangular prisim that takes in bottom left cornner, length, width, depth, fill color, border color, texture
	Rectangular_Prisim1(vec3 _f, float _length, float _width, float _depth, vec3 fc, vec3 bc, Texture* tex = NULL);

	//give the bottom points build a rectangular prisim, and the depth of the rectangular prisim
	Rectangular_Prisim1(vec3 _e, vec3 _f, vec3 _b, vec3 _c,float  _depth);

	//additional params: fill color, border color, texture
	Rectangular_Prisim1(vec3 _e, vec3 _f, vec3 _b, vec3 _c, float _depth, vec3 fc, vec3 bc, Texture* tex= NULL);

	void setTexture(Texture*);
	void printCoords();

	// The draw function
	void draw(Shader*);//draw the rectangular prisim
	//vec3 getEyeDirection(Camera*, int vertNum = 0 ); //taken from StuetzleC "tetrahedron"
	virtual ~Rectangular_Prisim1();

private:
	// some code taken from StuetzleC "tetrahedron" aka code that's been altered to apply to cube
	//identifiers changed because, why not?
	Triangle* dasDreieck [12];
	Vertex* ecken[8]; //f,e,g,h,b,c,d,a
	float depth;
	float length;
	float width;
	
	GLuint rp1_VertexArrayObject;
	Gluint rp1_VertexBufferObject;
	
	void buildRectangularPrisim1();
	void initalizeRemainingPoints(vec3 _e, vec3 _f, vec3 _b, vec3 _c, float _depth);

	//uses triangle fan to build the quads1
	Quad1* ein;
	Quad1* zwei;
	Quad1* drei;
	Quad1* vier;
	Quad1* fuenf;
	Quad1* sechs;
	Texture* texture;

	// Colors
	vec3 fillColor;
	vec3 borderColor;

	//the rectangular prisim points
	vec3 a;
	vec3 b;
	vec3 c;
	vec3 d;
	vec3 e;
	vec3 f;
	vec3 g;
	vec3 h;
};
#endif /* RECTANGULAR_PRISIM1_H */
