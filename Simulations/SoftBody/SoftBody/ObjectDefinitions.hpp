#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Circle
{
	glm::vec2 Position;
	float Radius;
};

struct PointMass 
{
	glm::vec2 Position;
	glm::vec2 Velocity;
};

struct Collision
{
	glm::vec2 Normal{ 0.f, 0.f };
	float Depth = -std::numeric_limits<float>::infinity();
};