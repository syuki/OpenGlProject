/// @File	: main.cpp
// @brief	: OoenGL���g��
// @date	: 2014/09/30

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glew32.lib")

/// Memory leak check
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

/// Includes
#include <Windows.h>
#define SN_VER_0_2
#include <snStudy.h>

#include "testOpenGL.h"

void InitScene(LPVOID lpParam)
{
	// For now, we just clear color to light blue,
	// to see if OpenGL context is working
	glClearColor(0.0f, 0.5f, 1.0f, 1.0f);
}

void RenderScene(LPVOID lpParam)
{
	// Typecast lpParam to COpenGLControl pointer
	COpenGLControl* oglControl = (COpenGLControl*)lpParam;

	// We just clear color
	glClear(GL_COLOR_BUFFER_BIT);

	// Had to rename to SwapBuffersM, M stands for member, because there is SwapBuffers windows function
	oglControl->SwapBuffersM();
}


/// �G���g���[�|�C���g
// �����@�F�����ς�
// �߂�l�F0
// 2014/09/30
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

	// �E�B���h�E�쐬���������s
	snStudy::WindowManager test1("HyperRacing", hInstance);
	test1.Init();

	COpenGLControl tess;

	tess.InitOpenGL(hInstance, &(test1.GetWindowHandle()), 3, 1, InitScene, RenderScene, NULL, &tess);

	for (;test1.MessageProcessing();){
		tess.Render(&tess);
		Sleep(10);
	}

	tess.ReleaseOpenGLControl(&tess);

	return 0;
}

//=EOF=