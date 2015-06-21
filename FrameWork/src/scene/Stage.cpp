#include "Stage.h"
#include "object\Background.h"
#include "object\Player.h"
#include "object\Ground.h"
#include "input/UtilityGamePad.h"
#include "MainCamera.h"
#include "cinder\app\App.h"

using namespace ci;
using namespace ci::app;
using namespace input;

Stage::Stage()
{

	GamePad::getInstance().init();
	Player::getVector().clear();
	auto aspect_ratio = 0;

	auto player_num = static_cast<int>(playerNum());

	for (int i = 0; i < player_num; ++i)
	{
		div_cameras.emplace_back();
	}


	switch (playerNum())
	{
		case PlayerNum::TWO:
			aspect_ratio = (getWindowSize().x) / (getWindowSize().y*0.5f);

			div_cameras.at(0).area = Area(0, getWindowHeight() * 0.5f, getWindowWidth(), getWindowHeight() - 1);
			div_cameras.at(1).area = Area(0, 0, getWindowWidth(), getWindowHeight() * 0.5f - 1);

			break;
		case PlayerNum::THREE:
			aspect_ratio = (getWindowSize().x*0.5f) / (getWindowSize().y*0.5f);

			//　横、高さ、横、高さ
			div_cameras.at(0).area = Area(getWindowWidth() * 0.25f, getWindowHeight() * 0.5f, getWindowWidth() * 0.75f, getWindowHeight() - 1);
			div_cameras.at(1).area = Area(0, 0, getWindowWidth() * 0.5f - 1, getWindowHeight() * 0.5f - 1);
			div_cameras.at(2).area = Area(getWindowWidth() * 0.5f + 1, 0, getWindowWidth(), getWindowHeight()*0.5f - 1);

			break;
		case PlayerNum::FOUR:
			aspect_ratio = (getWindowSize().x*0.5f) / (getWindowSize().y*0.5f);
			div_cameras.at(0).area = Area(0, getWindowHeight() * 0.5f, getWindowWidth() * 0.5f - 1, getWindowHeight() - 1);
			div_cameras.at(1).area = Area(getWindowWidth() * 0.5f + 1, getWindowHeight() * 0.5f, getWindowWidth(), getWindowHeight() - 1);
			div_cameras.at(2).area = Area(0, 0, getWindowWidth() * 0.5f - 1, getWindowHeight()*0.5f - 1);
			div_cameras.at(3).area = Area(getWindowWidth() * 0.5f + 1, 0, getWindowWidth(), getWindowHeight()*0.5f - 1);
			break;
	}

	addObject("background", std::make_shared<Background>());
	addObject("ground", std::make_shared<Ground>());

	for (int i = 0; i < player_num; ++i)
	{
		div_cameras.at(i).camera.setPerspective(90.0f, aspect_ratio, 2.0f, 200.0f);
		div_cameras.at(i).camera.lookAt(Vec3f(0, 20, -30), Vec3f::zero(), Vec3f::yAxis());
	}
	if(player_num >= 2)
	{
		addObject("player1", std::make_shared<Player>(Vec3f(0, 2, -10), Quatf(Vec3f::yAxis(), 0), div_cameras.at(0).camera, Player::Type::ONE, ColorA(239 / 255.0f, 133 / 255.0f, 140 / 255.0f, 1.0f)));
		addObject("player2", std::make_shared<Player>(Vec3f(0, 2, 10), Quatf(Vec3f::yAxis(), static_cast<float>(M_PI)), div_cameras.at(1).camera, Player::Type::TWO, ColorA(0 / 255.0f, 174 / 255.0f, 224 / 255.0f, 1.0f)));

		Player::getVector().emplace_back(GameObject::getObjectType<Player>("player1"));
		Player::getVector().emplace_back(GameObject::getObjectType<Player>("player2"));
	}
	if(player_num >= 3)
	{
		addObject("player3", std::make_shared<Player>(Vec3f(10, 2, 0), Quatf(Vec3f::yAxis(), static_cast<float>(M_PI * 0.5f)), div_cameras.at(2).camera, Player::Type::THREE, ColorA(90 / 255.0f, 165 / 255.0f, 114 / 255.0f, 1.0f)));
		Player::getVector().emplace_back(GameObject::getObjectType<Player>("player3"));
	}
	if (player_num >= 4)
	{
		addObject("player4", std::make_shared<Player>(Vec3f(-10, 2, 0), Quatf(Vec3f::yAxis(), static_cast<float>(M_PI * 1.5f)), div_cameras.at(3).camera, Player::Type::FOUR, ColorA(248 / 255.0f, 229 / 255.0f, 140 / 255.0f, 1.0f)));
		Player::getVector().emplace_back(GameObject::getObjectType<Player>("player4"));
	}

	param = ci::params::InterfaceGl("camera_test", Vec2i::one() * 300.0f);
	param.addParam("test", &dis);


	light = std::make_unique<gl::Light>(gl::Light::SPOTLIGHT, 1);
	light->lookAt(Vec3f::yAxis() * 246, Vec3f::zero());
	light->setAmbient(Color(0.2f, 0.2f, 0.2f));
	light->setDiffuse(Color(0.3f, 0.3f, 0.3f));
	light->setSpotCutoff(30.0f);
	light->setAttenuation(0.2f, 0, 0);

}

SceneType Stage::update()
{
	auto& camera = MainCamera::getInstance();

	updateObject();

	return type;
}

void Stage::draw()
{

	auto player_num = static_cast<int>(playerNum());

	for(auto& div_camera: div_cameras)
	{
		gl::pushMatrices();
		gl::setViewport(div_camera.area);
		div_camera.camera.update();
		light->enable();
		drawObject();
		light->disable();
		gl::popMatrices();
	}

}

void Stage::resize()
{
	float aspect_ratio = 0.0f;

	switch (playerNum())
	{
		case PlayerNum::TWO:
			aspect_ratio = (getWindowSize().x) / (getWindowSize().y*0.5f);
			div_cameras.at(0).area = Area(0, getWindowHeight() * 0.5f, getWindowWidth(), getWindowHeight() - 1);
			div_cameras.at(1).area = Area(0, 0, getWindowWidth(), getWindowHeight() * 0.5f - 1);
			break;
		case PlayerNum::THREE:
			aspect_ratio = (getWindowSize().x*0.5f) / (getWindowSize().y*0.5f);
			div_cameras.at(0).area = Area(getWindowWidth() * 0.25f, getWindowHeight() * 0.5f, getWindowWidth() * 0.75f, getWindowHeight() - 1);
			div_cameras.at(1).area = Area(0, 0, getWindowWidth() * 0.5f - 1, getWindowHeight() * 0.5f - 1);
			div_cameras.at(2).area = Area(getWindowWidth() * 0.5f + 1, 0, getWindowWidth(), getWindowHeight()*0.5f - 1);
			break;
		case PlayerNum::FOUR:
			aspect_ratio = (getWindowSize().x*0.5f) / (getWindowSize().y*0.5f);

			div_cameras.at(0).area = Area(0, getWindowHeight() * 0.5f, getWindowWidth() * 0.5f - 1, getWindowHeight() - 1);
			div_cameras.at(1).area = Area(getWindowWidth() * 0.5f + 1, getWindowHeight() * 0.5f, getWindowWidth(), getWindowHeight() - 1);
			div_cameras.at(2).area = Area(0, 0, getWindowWidth() * 0.5f -1, getWindowHeight()*0.5f - 1);
			div_cameras.at(3).area = Area(getWindowWidth() * 0.5f + 1, 0, getWindowWidth(), getWindowHeight()*0.5f - 1);

			break;
	}

	for (int i = 0; i < static_cast<int>(playerNum()); ++i)
	{
		div_cameras.at(i).camera.setPerspective(90.0f, aspect_ratio, 2.0f, 200.0f);
	}
}