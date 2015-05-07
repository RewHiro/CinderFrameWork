#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder\Camera.h"
#include "cinder/params\Params.h"
#include "Graphics.h"
#include "Key.h"
#include "Mouse.h"


using namespace ci;
using namespace ci::app;
using namespace input;


class FrameWorkApp : public AppNative {


	ci::CameraPersp camera;
	ci::params::InterfaceGl param;
	ci::params::InterfaceGl box_param;
	Vec3f pos = Vec3f::zero();
	Vec3f scale = Vec3f::one();
	Quatf rotate;
	Quatf test_rotate;

	Vec3f box_pos = Vec3f::zero();
	Vec3f box_scale = Vec3f::one();
	float size = 5.0f;
	Quatf box_rotate;

  public:

	void setup();
	void mouseDown( MouseEvent event );	
	void mouseUp(MouseEvent event);
	void mouseWheel(MouseEvent event);
	void mouseMove(MouseEvent event);
	void mouseDrag(MouseEvent event);
	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void update();
	void draw();
};

void FrameWorkApp::setup()
{
	param = ci::params::InterfaceGl("test", Vec2i::one() * 300.0f);
	param.addParam("pos",&pos);
	param.addParam("rotate", &rotate);
	param.addParam("scale", &scale);

	box_param = ci::params::InterfaceGl("box", Vec2i::one() * 200);
	box_param.addParam("pos", &box_pos);
	box_param.addParam("size", &size);
	box_param.addParam("scale", &box_scale);
	box_param.addParam("rotate", &box_rotate);

	camera.setPerspective(90.0f, getWindowAspectRatio(), 2.0f, 200.0f);
	camera.lookAt(Vec3f::zAxis() * 30.0f, Vec3f::zero(), Vec3f::yAxis());
	Key::getInstance();
	Mouse::getInstance();
}

void FrameWorkApp::mouseDown( MouseEvent event )
{
	Mouse::getInstance().setMouseDown(event.getCode());
}
void FrameWorkApp::mouseUp(MouseEvent event)
{
	Mouse::getInstance().setMouseUp(event.getCode());
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

void FrameWorkApp::update()
{
	gl::setMatrices(camera);
	gl::rotate(rotate);
	
	auto& key = Key::getInstance();
	static float angle = 0.0f;
	if(key.isPress('w'))
	{
		angle += 1.0f;
		test_rotate = Quatf(Vec3f::yAxis(), angle);
	}
}

void FrameWorkApp::draw()
{
	gl::clear(); 
	param.draw();

	//g3d::drawCube(box_pos, size,ColorA::white(),box_rotate,box_scale);
	g3d::drawSphere(box_pos, size, ColorA::white(), box_rotate, box_scale);
	Mouse::getInstance().flush();
	Key::getInstance().flush();
}

CINDER_APP_NATIVE( FrameWorkApp, RendererGl )
