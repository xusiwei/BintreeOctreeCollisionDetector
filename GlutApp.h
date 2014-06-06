#ifndef GLUT_APP_H
#define GLUT_APP_H

class GlutApp 
{
public:
	typedef void (*MenuFuncPtr)(void);

	struct MenuEntry 
	{
		int id;
		const char* str;
		MenuFuncPtr fun;
	};

	// ��ǰ App ʵ��ָ��,ָ������ʵ��
	static GlutApp* s_pCurrentApp;

	// �Ҽ��˵� �������ֵ
	static const int MAX_MENU = 32;

	// ctor
	GlutApp();

	// getter and setters:
	static void initGlut(int argc, char** argv) { s_argc = argc; s_argv = argv; }

	void setDisplayMode(unsigned int mode) { m_displayMode = mode; }

	void setWindowsSize(int w, int h) { m_winWidth = w; m_winHeight = h; }

	int getWindowWidth() { return m_winWidth; }

	int getWindowHeight() { return m_winHeight; }

	void setWindowsPos(int x, int y) { m_winPosX = x; m_winPosY = y; }

	void setTitle(char *title) { m_title = title; }

	void run();

	void addRightMenu(const char *str, MenuFuncPtr fun);

	// ��ʼ��
	virtual void onInit(){}

	//////////////////////////////////////////////////////////////////////////
	// GLUT delegate callbacks:

	// ���к���
	virtual void onIdle(){}

	// ͼ����ʾ��OpenGL��ͼָ�
	virtual void onDisplay() = 0; // ���������д������ʵ��������

	// ���ڴ�С�ı�
	virtual void onResize(int w, int h){}

	//////////////////////////////////////////////////////////////////////////
	// �����¼���Ӧ ����:

	// һ�㰴�����ɴ�ӡ�ַ���ESC��
	virtual void onKey(unsigned char key, int x, int y){}

	// һ�㰴�� ����
	virtual void onKeyDown(unsigned char key, int x, int y) {}

	// ���ⰴ������һ�㰴���ⰴ����
	virtual void onSpecialKey(int key, int x, int y){}

	// ���ⰴ������
	virtual void onSpecialKeyDown(int key, int x, int y){}

	//////////////////////////////////////////////////////////////////////////
	// ����¼���Ӧ ����:

	// ��갴��
	//! @param button: The button parameter is one of GLUT LEFT BUTTON, GLUT MIDDLE BUTTON, or GLUT RIGHT BUTTON.
	//! @param state: The state parameter is either GLUT UP or GLUT DOWN indicating 
	//                 whether the callback was due to a release or press respectively.
	virtual void onMousePress(int button, int state, int x, int y){}

	// ����ƶ�
	virtual void onMouseMove(int x, int y){}

	// ����϶�
	virtual void onMousePressMove(int x,int y){}

	//////////////////////////////////////////////////////////////////////////
	// ��ʱ����� ������
	virtual void onTimer() {}

	void setTimer(int delay, int period = 0);

protected:
	void registerMenus();

	// actual GLUT callback functions:
	static void KeyboardCallback(unsigned char key, int x, int y);

	static void KeyboardUpCallback(unsigned char key, int x, int y);

	static void SpecialKeyboardCallback(int key, int x, int y);

	static void SpecialKeyboardUpCallback(int key, int x, int y);

	static void ReshapeCallback(int w, int h);

	static void IdleCallback();

	static void MouseFuncCallback(int button, int state, int x, int y);

	static void	MotionFuncCallback(int x,int y);

	static void MousePassiveCallback(int x, int y);

	static void DisplayCallback();

	static void MenuCallback(int menuId);
	
	static void TimerCallback(int period);
private:
	unsigned int m_displayMode;

	// for glutInit
	static int s_argc;
	static char** s_argv;

	char *m_title;

	// for glutSetWindowSize
	int m_winWidth;
	int m_winHeight;

	// for windows position
	int m_winPosX;
	int m_winPosY;

	// for menus:
	int       m_menuCount;
	MenuEntry m_menuEntry[MAX_MENU];

	// for timer:
	int m_delay;
	int m_period;
};

#endif // GLUT_APP_H
