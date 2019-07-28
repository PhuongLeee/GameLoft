#include "Application.h"
#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
extern GLint screenWidth;
extern GLint screenHeight;

Application::Application(void)
{
}


Application::~Application(void)
{
}


void Application::Init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	std::unique_ptr <Shaders>  m_Shaders;
	std::unique_ptr <Texture>  m_texture;
	std::unique_ptr <Models>   m_model;
	std::unique_ptr <Camera>   m_Camera;

	//button
	m_Shaders = std::make_unique<Shaders>(new Shaders());
	m_Shaders->Init("..\\Data\\Shaders\\TextureShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	 

	m_model = std::make_unique<Models>(new Models());
	m_model->Init("..\\Data\\Model\\Sprite2D.nfg", NFG); 

	m_texture = std::make_unique<Texture>(new Texture());
	m_texture->Init("..\\Data\\Textures\\button1.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);


	m_Sprite2DButton1 = std::make_unique<Sprite2D>(new Sprite2D(m_model, m_Shaders, m_texture));
	m_Sprite2DButton1->Set2DPosition(200, 50);
	m_Sprite2DButton1->SetSize(700 * 0.1, 250 * 0.1);
	m_Sprite2DButton1->Init();


	m_texture = std::make_unique<Texture>(new Texture());
	m_texture->Init("..\\Data\\Textures\\button2.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);


	m_Sprite2DButton2 = std::make_unique<Sprite2D>(new Sprite2D(m_model, m_Shaders, m_texture));
	m_Sprite2DButton2->Set2DPosition(400, 50);
	m_Sprite2DButton2->SetSize(700 * 0.1, 250 * 0.1);
	m_Sprite2DButton2->Init();

	//camera
	Vector3 CameraPos(10, 40, 40);
	Vector3 TargetPos(0, 0, 0);
	float fFovY = 0.7f;
	m_Camera = std::make_unique<Camera>(new Camera());
	m_Camera->Init(CameraPos, TargetPos, fFovY, (GLfloat)screenWidth / screenHeight, 1.0f, 5000.0f, 1.0f);


	//plan
	m_model = std::make_unique<Models>(new Models());
	m_model->Init("..\\Data\\Model\\Plan.nfg", NFG);
	m_Shaders = std::make_unique<Shaders>(new Shaders());
	m_Shaders->Init("..\\Data\\Shaders\\ColorShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	m_texture = std::make_unique<Texture>(new Texture());
	m_texture->Init("..\\Data\\Textures\\Dirt.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);

	m_Plan = std::make_unique<Sprite3D>(new Sprite3D(m_model, m_Shaders, m_Camera, m_texture));
	m_Plan->Set3DScale(Vector3(20, 20, 20));
	m_Plan->Init();

	//box
	m_model = std::make_unique<Models>(new Models());
	m_model->Init("..\\Data\\Model\\box.nfg", NFG);
	m_Shaders = std::make_unique<Shaders>(new Shaders());
	m_Shaders->Init("..\\Data\\Shaders\\ColorShader.vs", "..\\Data\\Shaders\\ColorShader.fs");

	m_Sprite3D = std::make_unique<Sprite3D>(new Sprite3D(m_model, m_Shaders, m_Camera, Vector4(0.0, 0.0, 1.0, 0.5)));
	m_Sprite3D->Set3DScale(Vector3(1, 1, 1));
	m_Sprite3D->Init();

	//box
	m_model = std::make_unique<Models>(new Models());
	m_model->Init("..\\Data\\Model\\box.nfg", NFG);
	m_Shaders = std::make_unique<Shaders>(new Shaders());
	m_Shaders->Init("..\\Data\\Shaders\\TextureShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	m_texture = std::make_unique<Texture>(new Texture());
	m_texture->Init("..\\Data\\Textures\\Grass.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);

	m_Sprite3DShape2 = std::make_unique<Sprite3D>(new Sprite3D(m_model, m_Shaders, m_Camera, m_texture));
	m_Sprite3DShape2->Set3DScale(Vector3(1, 1, 1));
	m_Sprite3DShape2->Set3DPosition(Vector3(-20, -20, 10));
	m_Sprite3DShape2->Init();


	//cirle
	m_model = std::make_unique<Models>(new Models());
	m_model->Init("..\\Data\\Model\\Bila.nfg", NFG);
	m_Shaders = std::make_unique<Shaders>(new Shaders());
	m_Shaders->Init("..\\Data\\Shaders\\TextureShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	m_texture = std::make_unique<Texture>(new Texture());
	m_texture->Init("..\\Data\\Textures\\Grass.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);

	m_Sprite3D1 = std::make_unique<Sprite3D>(new Sprite3D(m_model, m_Shaders, m_Camera, m_texture));
	m_Sprite3D1->Init();
	m_Sprite3D1->Set3DScale(Vector3(0.1, 0.1, 0.1)); 


	//Bila
	m_model = std::make_unique<Models>(new Models());
	m_model->Init("..\\Data\\Model\\bila.nfg", NFG);
	m_Shaders = std::make_unique<Shaders>(new Shaders());
	m_Shaders->Init("..\\Data\\Shaders\\ColorShader.vs", "..\\Data\\Shaders\\ColorShader.fs");

	m_Sprite3DShape1 = std::make_unique<Sprite3D>(new Sprite3D(m_model, m_Shaders, m_Camera, Vector4(0.0, 0.0, 1.0, 0.5)));
	m_Sprite3DShape1->Set3DScale(Vector3(1, 1, 1));
	m_Sprite3DShape1->Set3DPosition(Vector3(-20,0,10));
	m_Sprite3DShape1->Init();

}

void Application::Update(GLfloat deltaTime)
{
	//update
	m_Plan->Update(deltaTime);
	m_Sprite3D->Update(deltaTime); 
	m_Sprite2DButton1->Update(deltaTime);
	m_Sprite2DButton2->Update(deltaTime);
	m_Sprite3D1->Update(deltaTime);
	m_Sprite3DShape1->Update(deltaTime);
	m_Sprite3DShape2->Update(deltaTime);
}

void Application::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Draw
	
	//3D
	m_Plan->Draw();
	m_Sprite3D->Draw();
	m_Sprite3D1->Draw();
	m_Sprite3DShape1->Draw();
	m_Sprite3DShape2->Draw();
	
	//2D 
	m_Sprite2DButton1->Draw();
	m_Sprite2DButton2->Draw();
}

void Application::HandleKeyEvent(unsigned char key, bool bIsPresseded)
{

}

void Application::HandleTouchEvent(GLint x, GLint y, bool bIsPresseded)
{
}

void Application::Exit()
{
	exit(0);
}
