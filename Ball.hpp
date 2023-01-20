#include "raylib.h"

class Ball
{
private:
	Color color;
	float radius, velocity, gravity;
public:
	float x, y, bounceImpulse;
	Ball(float aX, float aY, float aRadius, float aBounceImpulse, Color aColor)
	{
		x = aX;
		y = aY;
		radius = aRadius;
		bounceImpulse = aBounceImpulse;
		velocity = 0;
		gravity = 9.81;
		color = aColor;
	}

	void move()
	{
		if (y + radius > GetScreenHeight())
		{
			velocity = bounceImpulse * -1;
			if (bounceImpulse > 1) bounceImpulse *= 0.8;
			else bounceImpulse = 0;
		}
		else
		{
			velocity += gravity;
		}
		y += velocity * GetFrameTime();
	}

	void draw()
	{
		DrawCircle(x, y, radius, color);
	}
};
