#pragma once
#include "Singleton.h"
#include "GameConfig.h"


#include "Sprite2D.h"
#include "Sprite3D.h"

class Application : public CSingleton<Application>
{
public:
	Application(void);
	~Application(void);
	void		Init();
	void		Update( GLfloat deltaTime);
	void		Render();
	void		HandleKeyEvent(unsigned char key, bool bIsPresseded);
	void		HandleTouchEvent(GLint x, GLint y, bool bIsPresseded);
	void		Exit();

private:
	
	std::unique_ptr <Sprite2D> 	m_Sprite2DButton1;
	std::unique_ptr <Sprite2D>	m_Sprite2DButton2; 

	std::unique_ptr <Sprite3D> 	m_Plan; 
	std::unique_ptr <Sprite3D> 	m_Sprite3D1;
	std::unique_ptr <Sprite3D> 	m_Sprite3D;
	std::unique_ptr <Sprite3D> 	m_Sprite3DShape1;
	std::unique_ptr <Sprite3D> 	m_Sprite3DShape2;

};

