#include "cinder/Vector.h"
#include "cinder/gl/gl.h"
#include "cinder/Color.h"

using namespace ci;

namespace graphics2D{

	void drawLine
		(
		const Vec2f& start,
		const Vec2f& end,
		const Color& color,
		float width = 1.0f
		)
	{
		gl::color(color);
		gl::lineWidth(width);
		gl::drawLine(start, end);
	}

	void drawFillRect(
		const Vec2f& pos,
		const Vec2f& size,
		const Color& color,
		const Quatf& quartenion = Quatf::identity(),
		const Vec3f& scale = Vec3f::one()
		)
	{
		auto rect = Rectf(pos, pos+ size);
		gl::rotate(quartenion);
		gl::color(color);
		gl::drawSolidRect(rect);
	}

	void drawRect(
		const Vec2f& pos,
		const Vec2f& size,
		const Color& color
		)
	{
		gl::color(color);
		auto rect = Rectf(pos, pos + size);
		gl::drawStrokedRect(rect);
	}

	void drawFillCircle
		(
		const Vec2f& pos,
		const float radius,
		const Color& color
		)
	{
		gl::color(color);
		gl::drawSolidCircle(pos, radius);
	}

	void drawCircle
		(
		const Vec2f& pos,
		const float radius,
		const Color& color
		)
	{
		gl::color(color);
		gl::drawStrokedCircle(pos, radius);
	}
}

namespace graphics3D{
	void drawCube
		(
		const Vec3f& pos,
		const Vec3f& size,
		const ColorA& color,
		const Quatf& quartenion = Quatf::identity(),
		const Vec3f& scale = Vec3f::one()
		)
	{
		gl::pushModelView();
		gl::color(color);
		gl::rotate(quartenion);
		gl::scale(scale);
		gl::drawStrokedCube(pos, size);
		gl::popModelView();
	}

	void drawFillCube
		(
		const Vec3f& pos,
		const Vec3f& size,
		const ColorA& color,
		const Quatf& quartenion = Quatf::identity(),
		const Vec3f& scale = Vec3f::one()
		)
	{
		gl::pushModelView();
		gl::color(color);
		gl::rotate(quartenion);
		gl::scale(scale);
		gl::drawCube(pos, size);
		gl::popModelView();
	}
}