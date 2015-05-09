#include "Title.h"
#include "Graphics.h"
#include "cinder\Vector.h"
#include "input\Mouse.h"

using namespace ci;
using namespace ci::app;
using namespace input;

SceneType Title::update()
{
	auto& mouse = Mouse::getInstance();
	if(mouse.isPush(MouseEvent::LEFT_DOWN))
	{
		type = SceneType::STAGE;
	}
	return type;
}
void Title::draw()
{
	g3d::drawSphere(Vec3f::zero(), 10);
}