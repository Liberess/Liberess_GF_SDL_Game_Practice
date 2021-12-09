#include "MenuButton.h"
#include "AudioManager.h"

MenuButton::MenuButton(const LoaderParams* pParams, void(*callback)())
	: SDLGameObject(pParams), m_callback(callback)
{
	m_bReleased = false;
}

void MenuButton::draw()
{
	SDLGameObject::draw();
}

void MenuButton::clean()
{
	SDLGameObject::clean();
}

void MenuButton::update()
{
	// pMousePos = ���콺 �������� ��ǥ���� ���� �´�.
	Vector2D* pMousePos =
				TheInputHandler::Instance()->getMousePosition();

	// ���콺 ������ ��ǥ�� x���� �޴���ư�� x�� �������� ������
	// y�� �������� ���� ���̿� ������
	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height)
		&& pMousePos->getY() > m_position.getY())
	{
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT) &&
			m_bReleased)
		{
			m_currentFrame = CLICKED;
			m_callback();
			m_bReleased = false;

#ifdef WIN32
			TheAudioManager::Instance()->PlaySFX(SfxType::BtnClick);
#endif // WIN32

			SDL_Delay(200);
		}
		else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_bReleased = true;
			m_currentFrame = MOUSE_OVER;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}