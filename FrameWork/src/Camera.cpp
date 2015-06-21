#include "Camera.h"
#include "cinder\gl\gl.h"

using namespace ci;
namespace game{
	Camera::Camera(const float verticalFovDegrees, const float aspectRatio, const float nearPlane, const float farPlane)
{
	camera.setPerspective(verticalFovDegrees, aspectRatio, nearPlane, farPlane);
}

void Camera::lookAt(const Vec3f &aEyePoint, const Vec3f &target, const Vec3f &aUp)
{
	camera.lookAt(aEyePoint, target, aUp);
}

void Camera::setDirection(const ci::Vec3f& direction)
{
	camera.setViewDirection(direction);
}

void Camera::setPos(const Vec3f& pos)
{
	camera.setEyePoint(pos);
}

void Camera::setPerspective(const float verticalFovDegrees, const float aspectRatio, const float nearPlane, const float farPlane)
{
	camera.setPerspective(verticalFovDegrees, aspectRatio, nearPlane, farPlane);
}

void Camera::rotation(const Quatf& rotate)
{
	this->rotate *= rotate;
}

void Camera::setCenterOfInterestPoint(const Vec3f &centerOfInterestPoint)
{
	camera.setCenterOfInterestPoint(centerOfInterestPoint);
}

void Camera::setRotate(const ci::Quatf& rotate)
{
	this->rotate = rotate;
}

void Camera::setTargetPoint(const ci::Vec3f& point)
{
	target_point = point;
}

Vec3f Camera::getPos()const
{
	return camera.getEyePoint();
}

Quatf Camera::getRotate()const
{
	return rotate;
}
ci::Vec3f Camera::getViewDirection()const
{
	return camera.getViewDirection();
}

void Camera::update()
{
	gl::setMatrices(camera);
}
}