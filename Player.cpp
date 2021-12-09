#include "Player.h"
#include "Game.h"
#include "TextureManager.h"
#include "AudioManager.h"

Player::Player(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{
	m_flipX = SDL_FLIP_NONE;
}

void Player::draw()
{
	SDLGameObject::draw();

	m_currentFrame = int(((SDL_GetTicks() / 100) % 11));
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);

	handleInput(); // 이동 입력

	SDLGameObject::update();
}

void Player::clean()
{

}

void Player::handleInput()
{
	static bool isWalking = false;
	static int count = 0;

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		isWalking = true;

		if (m_position.getX() + m_width < TheGame::Instance()->getScreenWidth())
		{
			m_velocity.setX(4);
			m_flipX = SDL_FLIP_NONE;
		}
		else
		{
			m_velocity.setX(0);
		}
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		isWalking = true;

		if (m_position.getX() > 0)
		{
			m_velocity.setX(-4);
			m_flipX = SDL_FLIP_HORIZONTAL;
		}
		else
		{
			m_velocity.setX(0);
		}
	}
	else
	{
		isWalking = false;

		m_velocity.setX(0);
	}

	if (isWalking)
	{
		m_currentRow = 2; //Run

		if(count == 0)
#ifdef WIN32
			TheAudioManager::Instance()->PlaySFX(SfxType::Move);
#endif // WIN32



		++count;
	}
	else
	{
		count = 0;
		m_currentRow = 1; //Idle
#ifdef WIN32
		TheAudioManager::Instance()->StopSFX(SfxType::Move);
#endif // WIN32
	}
}