#include "GenericEngine.hpp"
#include <vector>

class SoftBodyEngine : GenericEngine
{
	std::vector<PointMass> points;
public:
	void update(float dt) 
	{
		// update everything here ...
	}
};