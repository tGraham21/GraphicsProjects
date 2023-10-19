#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ObjectDefinitions.hpp"

class GenericEngine
{
	std::vector<glm::vec3> m_verticies;
	std::vector<glm::vec3> m_indicies;

	void buildCircle(glm::vec2 pos, float radius, int vCount)
	{
		float angle = 360.f / vCount;
		int tCount = vCount - 2;

		for (size_t i = 0; i < vCount; i++)
		{
			float currAngle = angle * i;
			float x = radius * cos(glm::radians(currAngle));
			float y = radius * sin(glm::radians(currAngle));
			float z = 0.0f;

			m_verticies.push_back({ pos.x + x, pos.y + y, z });
		}

		for (size_t i = 0; i < tCount; i++)
			m_indicies.push_back({ 0, i + 1, i + 2 });
	}

public:
	virtual void update(float dt) = 0; // must define update function to be called every frame
};