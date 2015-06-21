#include "Ground.h"
#include "Graphics.h"

using namespace ci;
using namespace cinder::app;

Ground::Ground():
texture(loadImage(loadAsset("ground.jpg")))
{

}

void Ground::update()
{

}

void Ground::draw()
{
	texture.bind();
	g3d::drawCube(Vec3f::zero(), Vec3f(200, 1, 200));
	texture.unbind();
}