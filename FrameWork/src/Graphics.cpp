#include "Graphics.h"

using namespace ci;

namespace graphics3D
{
	void drawCube
		(
		const  Vec3f& pos,
		const  Vec3f& size,
		const ColorA& color,
		const Quatf& rotate,
		const Vec3f& scale
		)
	{
		gl::pushModelView();
		gl::color(color);
		gl::translate(pos);
		gl::rotate(rotate);
		gl::scale(scale);
		gl::drawCube(Vec3f::zero(), size);
		gl::popModelView();
	}

	void drawSphere
		(
		const  Vec3f& pos,
		const  float& radius,
		const ColorA& color,
		const Quatf& rotate,
		const Vec3f& scale
		)
	{
		gl::pushModelView();
		gl::color(color);
		gl::translate(pos);
		gl::rotate(rotate);
		gl::scale(scale);
		gl::drawSphere(Vec3f::zero(), radius,20);
		gl::popModelView();
	}
}