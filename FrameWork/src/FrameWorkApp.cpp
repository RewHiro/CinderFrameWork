#include "cinder\app\AppNative.h"
#include "cinder\gl\gl.h"
#include "cinder\Camera.h"
#include "cinder\params\Params.h"
#include "Graphics.h"
#include "input\Key.h"
#include "input\Mouse.h"
#include "scene\SceneManager.h"
#include "cinder\gl\Light.h"
#include "cinder\gl\Material.h"
#include "cinder\gl\TextureFont.h"
#include "input\UtilityGamePad.h"


using namespace ci;
using namespace ci::app;
using namespace input;



class FrameWorkApp : public AppNative
{
	Vec3f pos = Vec3f::zero();
	Vec3f scale = Vec3f::one();

	//std::shared_ptr<gl::Light> light;
	std::unique_ptr<SceneManager> scene_manager;
public:

	void prepareSettings(Settings *settings)override;
	void setup()override;
	void resize()override;
	void shutdown()override;
	void mouseDown(MouseEvent event) override;
	void mouseUp(MouseEvent event)override;
	void mouseWheel(MouseEvent event)override;
	void mouseMove(MouseEvent event)override;
	void mouseDrag(MouseEvent event)override;
	void keyDown(KeyEvent event)override;
	void keyUp(KeyEvent event)override;
	void update()override;
	void draw()override;
};

void FrameWorkApp::prepareSettings(Settings *settings)
{
	settings->setWindowSize(Vec2i(1440, 810));
}

void FrameWorkApp::setup()
{
	GamePad::getInstance().init();
	scene_manager = std::make_unique<SceneManager>();

	gl::enableDepthRead();
	gl::enableDepthWrite();

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

	Key::getInstance();
	Mouse::getInstance();
}

void FrameWorkApp::resize()
{
	scene_manager->resize();
}

void FrameWorkApp::shutdown()
{
	GamePad::getInstance().shutdown();
}

void FrameWorkApp::mouseDown(MouseEvent event)
{
	Mouse::getInstance().setMouseDown(event);
}
void FrameWorkApp::mouseUp(MouseEvent event)
{
	Mouse::getInstance().setMouseUp(event);
}
void FrameWorkApp::mouseWheel(MouseEvent event)
{
	Mouse::getInstance().setWheelValue(static_cast<int>(event.getWheelIncrement()));
}
void FrameWorkApp::mouseMove(MouseEvent event)
{
	Mouse::getInstance().setPosition(event.getPos());
}
void FrameWorkApp::mouseDrag(MouseEvent event)
{

}

void FrameWorkApp::keyDown(KeyEvent event)
{
	Key::getInstance().setKeyDown(event.getCode());
}

void FrameWorkApp::keyUp(KeyEvent event)
{
	Key::getInstance().setKeyUp(event.getCode());
}


#define POLL_ITERATION_INTERVAL 30

void FrameWorkApp::update()
{
	GamePad::getInstance().update();
	scene_manager->update();
}

void FrameWorkApp::draw()
{
	gl::clear();

	scene_manager->draw();

	Mouse::getInstance().flush();
	Key::getInstance().flush();
	GamePad::getInstance().flush();
}

CINDER_APP_NATIVE(FrameWorkApp, RendererGl)
