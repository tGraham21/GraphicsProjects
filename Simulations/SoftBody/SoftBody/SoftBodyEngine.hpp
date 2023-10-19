#include "GenericEngine.hpp"
#include <vector>

class SoftBodyEngine : GenericEngine
{
	std::vector<PointMass> m_points;
	// how much energy will be retained on collision [0, 1]
	float m_elasticity = .75;

	float m_friction = .15;

	glm::vec2 m_gravity = { 0, -9.8 };

	Collision findCollision(glm::vec2 const & position);

public:
	
	void update(float dt);

	void addPoint(PointMass const& p)
	{
		m_points.push_back(p);
	}
};