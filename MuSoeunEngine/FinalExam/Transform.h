#pragma once
#include<math.h>
namespace Transform
{
	struct Vertex
	{
	public:
		float x;
		float y;
	};

	struct Vector
	{
	public:
		float x_meter;
		float y_meter;
	};


	Vertex MoveVertex(Vertex point, Vector meter)
	{
		Vertex res = { point.x + meter.x_meter / 800.0f*60, point.y + meter.y_meter / 600.0f*60 };
		return res;
	}
	Vertex RotateVertex(Vertex point, float angle_degree)
	{
		Vertex res = { (point.x * cosf(-angle_degree) - point.y * sinf(-angle_degree))*60 , (point.x * sinf(-angle_degree) + point.y * cosf(-angle_degree))*60 };
		return res;
	}

	Vertex ScaleVertex(Vertex point, Vector meter)
	{
		Vertex res = { point.x * meter.x_meter / 800.0f*60 , point.y * meter.y_meter / 600.0f*60 };
		return res;

	}

};