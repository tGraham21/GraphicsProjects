# include "SoftBodyEngine.hpp"


Collision SoftBodyEngine::findCollision(glm::vec2 const & position)
{
	return { glm::vec2{0.f, 1.f}, -position.y };
}

void SoftBodyEngine::update(float dt)
{
	for (auto & p : m_points)
		p.Velocity += m_gravity * dt;

	for (auto & p : m_points)
		p.Position += p.Velocity * dt;

	for (PointMass& p : m_points)
	{
		Collision c = findCollision(p.Position);

		// check if collision took place
		if (c.Depth < 0) continue;

		// normal and tangential velocity
		glm::vec2 vn = c.Normal * glm::dot(c.Normal, p.Velocity);
		glm::vec2 vt = p.Velocity - vn;

		vn = -m_elasticity * vn;

		// read about exponential smoothing 
		vt *= std::exp(-m_friction * dt);
		
		p.Velocity = vn + vt;
	}
}