#include "camera.h"
#include <glm/gtc/type_ptr.hpp>

namespace {
	float pan_speed = 0.1f;
	float roll_speed = 0.1f;
	float rotation_speed = 0.05f;
	float zoom_speed = 0.1f;
};

// FIXME: Calculate the view matrix
glm::mat4 Camera::get_view_matrix() const
{
	return glm::mat4();
	glm::vec3 tangent = glm::cross(look_, up_);
	glm::vec3 newup = glm::cross(tangent, look_);
	float view_mat [16] = {
		tangent.x, newup.x, -look_.x, eye_.x,
		tangent.y, newup.y, -look_.y, eye_.y,
		tangent.z, newup.z, -look_.z, eye_.z,
		0.0f,      0.0f,    0.0f,     1.0f
	};
	return glm::inverse(glm::make_mat4(view_mat));
}
