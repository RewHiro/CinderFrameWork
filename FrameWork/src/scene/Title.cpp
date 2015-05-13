#include "Title.h"
#include "Graphics.h"
#include "cinder\Vector.h"
#include "input\Mouse.h"
#include "object\Player.h"

using namespace ci;
using namespace ci::app;
using namespace input;

Title::Title()
{
	addObject("Player", std::make_shared<Player>(object_task));
}

SceneType Title::update()
{
	auto& mouse = Mouse::getInstance();
	if(mouse.isPush(MouseCode::LEFT))
	{
		type = SceneType::STAGE;
	}
	if(mouse.isPush(MouseCode::RIGHT))
	{
		findObject("Player")->destory();
	}
	updateObject();
	return type;
}
void Title::draw()
{
	drawObject();
}