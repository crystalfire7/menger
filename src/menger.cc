#include "menger.h"

namespace {
	const int kMinLevel = 0;
	const int kMaxLevel = 4;
};

Menger::Menger()
{
	// Add additional initialization if you like
}

Menger::~Menger()
{
}

void
Menger::set_nesting_level(int level)
{
	nesting_level_ = level;
	dirty_ = true;
}

bool
Menger::is_dirty() const
{
	return dirty_;
}

void
Menger::set_clean()
{
	dirty_ = false;
}

void
create_cube(std::vector<glm::vec4>& vertices,
                    std::vector<glm::uvec3>& faces,
                    glm::vec3 min, glm::vec3 max)
{
	vertices.push_back(glm::vec4(min.x, min.y, min.z, 1.0f)); // 0
	vertices.push_back(glm::vec4(min.x, max.y, min.z, 1.0f)); // 1
	vertices.push_back(glm::vec4(max.x, max.y, min.z, 1.0f)); // 2
	vertices.push_back(glm::vec4(max.x, min.y, min.z, 1.0f)); // 3
	vertices.push_back(glm::vec4(min.x, min.y, max.z, 1.0f)); // 4
	vertices.push_back(glm::vec4(min.x, max.y, max.z, 1.0f)); // 5
	vertices.push_back(glm::vec4(max.x, max.y, max.z, 1.0f)); // 6
	vertices.push_back(glm::vec4(max.x, min.y, max.z, 1.0f)); // 7

	faces.push_back(glm::uvec3(0, 2, 1)); // 0
	faces.push_back(glm::uvec3(0, 3, 2)); // 1
	faces.push_back(glm::uvec3(1, 6, 5)); // 2
	faces.push_back(glm::uvec3(1, 2, 6)); // 3
	faces.push_back(glm::uvec3(3, 6, 2)); // 4
	faces.push_back(glm::uvec3(3, 7, 6)); // 5
	faces.push_back(glm::uvec3(6, 4, 5)); // 6
	faces.push_back(glm::uvec3(6, 7, 4)); // 7
	faces.push_back(glm::uvec3(5, 0, 1)); // 8
	faces.push_back(glm::uvec3(5, 4, 0)); // 9
	faces.push_back(glm::uvec3(4, 7, 3)); // 10
	faces.push_back(glm::uvec3(4, 3, 0)); // 11

}

// create_sponge(std::vector<glm::vec4>& vertices,
//                     std::vector<glm::uvec3>& faces,
//                     glm::vec3 min, glm::vec3 max,
//                     int depth)
// {
// 	if(depth)

// }

// FIXME generate Menger sponge geometry
void
Menger::generate_geometry(std::vector<glm::vec4>& vertices,
                          std::vector<glm::uvec3>& faces) const
{
	glm::vec3 offset(1.75f, 0.0f, -5.0f);
	create_cube(vertices, faces, offset + glm::vec3(-.5f,-.5f,-.5f), offset + glm::vec3(.5f,.5f,.5f));
	// vertices.push_back(glm::vec4(-0.5f, -0.5f, -0.5f, 1.0f));
	// vertices.push_back(glm::vec4(0.5f, -0.5f, -0.5f, 1.0f));
	// vertices.push_back(glm::vec4(0.0f, 0.5f, -0.5f, 1.0f));
	// faces.push_back(glm::uvec3(0, 1, 2));
}

