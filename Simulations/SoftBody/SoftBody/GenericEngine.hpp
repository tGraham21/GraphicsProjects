#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ObjectDefinitions.hpp"

class GenericEngine
{
	float gravity = 9.8;

public:
	virtual void update(float dt) = 0; // must define update function to be called every frame
};