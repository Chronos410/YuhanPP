#pragma once
class Bird
{
public:
	Bird();
	~Bird();

	virtual void render();
	virtual void goback();
	virtual float getX();
};

