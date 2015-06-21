#pragma once
#include "cinder\Camera.h"
namespace game{
class Camera
{
	ci::CameraPersp camera;
	ci::Quatf rotate = ci::Quatf::identity();
	ci::Vec3f target_point = ci::Vec3f::zero();
public:
	Camera() = default;
	Camera(const float verticalFovDegrees, const float aspectRatio, const float nearPlane, const float farPlane);
	virtual ~Camera() = default;
	void lookAt(const ci::Vec3f &aEyePoint, const ci::Vec3f &target, const ci::Vec3f &aUp);
	void setPos(const ci::Vec3f& pos);
	void setDirection(const ci::Vec3f& direction);
	void setPerspective(const float verticalFovDegrees, const float aspectRatio, const float nearPlane, const float farPlane);
	void rotation(const ci::Quatf& rotate);
	void setCenterOfInterestPoint(const ci::Vec3f &centerOfInterestPoint);
	void setRotate(const ci::Quatf& rotate);
	void setTargetPoint(const ci::Vec3f& point);

	ci::Vec3f getPos()const;
	ci::Quatf getRotate()const;
	ci::Vec3f getViewDirection()const;

	void update();
};
}