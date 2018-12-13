
#include "GeometricObject.h"
class Rectangle :
	public GeometricObject
{
public:
	Ray normal;
	Ray perp1;
	Ray perp2;

	Rectangle();
	~Rectangle();
};
