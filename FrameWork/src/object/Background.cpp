#include "Background.h"
#include "cinder\gl\gl.h"
#include "cinder\app\App.h"
#include "cinder\ImageIo.h"
#include "cinder\gl\Texture.h"



using namespace cinder;
using namespace cinder::app;

Background::Background():
texture(loadImage(loadAsset("background03.jpg")))
{

}

void Background::update()
{

}

void Background::draw()
{
	
	glDisable(GL_CULL_FACE);
	glDisable(GL_LIGHTING);

	texture.bind();

	gl::color(ColorA(1, 1, 1,1));

	gl::drawSphere(Vec3f::zero(),100,20);

	texture.unbind();

	glEnable(GL_LIGHTING);
	glEnable(GL_CULL_FACE); 
}