#include "camera.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include "glm/ext.hpp"
#include <iostream>

namespace {
	float pan_speed = 0.1f;
	float roll_speed = 0.1f;
	float rotation_speed = 0.05f;
	float zoom_speed = 0.1f;
};

void Camera::strafe_tangent(int direction) {
	eye_ += direction * pan_speed *
	        glm::normalize(glm::cross(look_, up_)); // tangent
}

void Camera::strafe_up(int direction) {
	eye_ += direction * pan_speed *
	        glm::normalize(glm::cross(glm::normalize(glm::cross(look_, up_)), look_)); // recomputed up
}

void Camera::strafe_forward(int direction){
	eye_ += direction * zoom_speed * look_;
}

void Camera::zoom(int direction) {
	glm::vec3 center = eye_ + camera_distance_ * look_;
	camera_distance_ -= direction * zoom_speed;
	eye_ = center - camera_distance_ * look_;
	
}

void Camera::roll(int direction) {
	up_ = glm::rotate(up_, roll_speed * direction, -look_);
	// up_ = glm::cos(roll_speed * direction) * up_ + glm::sin(roll_speed * direction) * glm::normalize(glm::cross(look_, up_));
}

void Camera::rotate(float dx, float dy){
	glm::vec3 center = eye_ + camera_distance_ * look_; // center
	glm::vec3 tangent = glm::normalize(glm::cross(look_, up_));
	glm::vec3 newup = glm::normalize(glm::cross(tangent, look_));

	glm::vec3 dir_world = glm::normalize(dx * tangent + dy * newup);

	glm::vec3 eye_rel_cent = eye_ - center;
	glm::vec3 norm = glm::normalize(glm::cross(dir_world, look_));

	eye_rel_cent = glm::rotate(eye_rel_cent, rotation_speed, norm);
	eye_ = eye_rel_cent + center;
	look_ = -glm::normalize(eye_rel_cent);
	up_ = glm::normalize(glm::rotate(up_, rotation_speed, norm));

}
// FIXME: Calculate the view matrix
glm::mat4 Camera::get_view_matrix() const
{
	glm::vec3 tangent = glm::normalize(glm::cross(look_, up_));
	glm::vec3 newup = glm::normalize(glm::cross(tangent, look_));
	float view_mat [16] = {
		tangent.x, newup.x, -look_.x, eye_.x,
		tangent.y, newup.y, -look_.y, eye_.y,
		tangent.z, newup.z, -look_.z, eye_.z,
		0.0f,      0.0f,    0.0f,     1.0f
	};
	return glm::inverse(glm::transpose(glm::make_mat4(view_mat)));
	// return glm::inverse(glm::mat4(glm::vec4(tangent, 0.0f), glm::vec4(newup, 0.0f), glm::vec4(-look_, 0.0f), glm::vec4(eye_, 1.0f)));
}
