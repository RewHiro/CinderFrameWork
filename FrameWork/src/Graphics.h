#pragma once
#include "cinder\gl\gl.h"
#include "cinder\Vector.h"

namespace graphics3D
{
	void drawCube
		(
		const  ci::Vec3f& pos,
		const  ci::Vec3f& size,
		const ci::ColorA& color = ci::ColorA::white(),
		const ci::Quatf& rotate = ci::Quatf::identity(),
		const ci::Vec3f& scale = ci::Vec3f::one()
		);

	void drawSphere
		(
		const  ci::Vec3f& pos,
		const  float& radius,
		const ci::ColorA& color = ci::ColorA::white(),
		const ci::Quatf& rotate = ci::Quatf::identity(),
		const ci::Vec3f& scale = ci::Vec3f::one()
		);
}
namespace g3d = graphics3D;