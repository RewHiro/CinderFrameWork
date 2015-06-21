#include "Title.h"
#include "Graphics.h"
#include "cinder\Vector.h"
#include "input\Mouse.h"
#include "input\Key.h"
#include "object\Player.h"
#include "cinder\app\app.h"
#include "cinder\Unicode.h"
#include "input\UtilityGamePad.h"
#include "object\Player.h"

using namespace ci;
using namespace ci::app;
using namespace input;

Title::Title()
{
	GamePad::getInstance().init();
	font = Font(loadAsset("nicomoji_1.00.ttf"), 100);
	font01 = Font(loadAsset("sea.ttf"), 100);
	camera = CameraOrtho(0, getWindowWidth(), getWindowHeight(),0, 0.5f, 100.0f);
	camera.lookAt(Vec3f(0, 0, 10), Vec3f::zero(), Vec3f::yAxis());
	camera.setAspectRatio(getWindowWidth() / getWindowHeight());
	light = std::make_unique<gl::Light>(gl::Light::DIRECTIONAL, 0);
	light->setDirection(Vec3f::zAxis());
	light->setAmbient(Color(1, 1, 1));
	light->setDiffuse(Color(1, 1, 1));
}

SceneType Title::update()
{

	auto& gamepad = GamePad::getInstance();
	auto& key = Key::getInstance();
	if(1.0f == gamepad.getPressAxis(0,GamePad::AxisID::LEFT_Y))
	{
		++interval;
		if(interval % 7 == 0){
			++count;
			interval = 0;
		}
	}
	else if (-1.0f == gamepad.getPressAxis(0, GamePad::AxisID::LEFT_Y))
	{
		++interval;
		if (interval % 7 == 0){
			--count;
			interval = 0;
		}
	}

	if (gamepad.isPullButton(0,GamePad::ButtonID::RIGHT) || key.isPush(KeyEvent::KEY_RETURN))
	{
		playerNum() = static_cast<PlayerNum>((std::abs(count) % 3) + 2);
		type = SceneType::STAGE;
	}

	return type;
}
void Title::draw()
{
	gl::setMatrices(camera);
	light->enable();
	gl::color(Color(1, 1, 1));
	gl::drawCube(Vec3f(10,10,0), Vec3f::one() * 10);
	gl::pushMatrices();
	gl::drawStringCentered(ci::toUtf8((char16_t*)std::wstring(L"タコタコバンチョウ").c_str()), Vec2f(getWindowCenter().x, getWindowCenter().y*0.5f), Color::white(), font);


	std::wstring play_num_str = std::to_wstring((std::abs(count) % 3) + 2) + std::wstring(L"人で遊ぶ");

	gl::drawStringCentered(ci::toUtf8((char16_t*)play_num_str.c_str()), Vec2f(getWindowCenter().x, getWindowCenter().y*1.5f), Color::white(), font01);
	
	gl::popMatrices();
	light->disable();
}

void Title::resize()
{
	camera.setOrtho(0, getWindowWidth(), getWindowHeight(), 0, 0.5f, 100.0f);
	//camera.setAspectRatio(getWindowWidth() / getWindowHeight());
}
