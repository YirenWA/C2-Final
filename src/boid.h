/*
 *
 */

#ifndef _BOID
#define _BOID
#include <vector>
#include "ofMain.h"

class Boid
{
	// all the methods and variables after the
	// private keyword can only be used inside
	// the class
protected:
	ofVec3f position;
	ofVec3f velocity;

	int size2 = 9.5;
	float separationWeight;
	float cohesionWeight;
	float alignmentWeight;

	float separationThreshold;
	float neighbourhoodSize;

	ofVec3f separation(std::vector<Boid*>& otherBoids);
	ofVec3f cohesion(std::vector<Boid*>& otherBoids);
	ofVec3f alignment(std::vector<Boid*>& otherBoids);

	// all the methods and variables after the
	// public keyword can only be used by anyone
public:
	Boid();
	Boid(ofVec3f& pos, ofVec3f& vel);

	~Boid();

	ofVec3f getPosition();
	ofVec3f getVelocity();


	float getSeparationWeight();
	float getCohesionWeight();
	float getAlignmentWeight();

	float getSeparationThreshold();
	float getNeighbourhoodSize();

	void setSeparationWeight(float f);
	void setCohesionWeight(float f);
	void setAlignmentWeight(float f);

	void setSeparationThreshold(float f);
	void setNeighbourhoodSize(float f);

	int getDraw2Size();
	void setDraw2Size(int s);

	virtual void update(std::vector<Boid*>& otherBoids, ofVec3f& min, ofVec3f& max);

	void updateWithinCircle(int radius);

	void walls(ofVec3f& min, ofVec3f& max);

	virtual void draw();
	virtual void draw1();
	virtual void draw2();
	virtual void draw3();

	int mouseX;
	int mouseY;

};


#endif