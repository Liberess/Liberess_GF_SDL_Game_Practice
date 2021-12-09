#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameObject.h"
#include "PauseState.h"
#include "GameStateMachine.h"
#include "GameOverState.h"
#include "TextManager.h"
#include "AudioManager.h"
#include <iostream>
#include <cmath>
#include <cstring>

const std::string PlayState::s_playID = "PLAY";
PlayState *PlayState::s_pInstance  = nullptr;

void PlayState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++) // �Ʈ �Ʈ
		m_gameObjects[i]->update();

	for (int i = 2; i < m_gameObjects.size(); i++) // � �浹 üũ
	{
		if (checkCollision(
			dynamic_cast<SDLGameObject*>(m_gameObjects[1]),	// �÷�̾�
			dynamic_cast<SDLGameObject*>(m_gameObjects[i])))	// �1
		{
			TheGame::Instance()->getStateMachine()
				->changeState(GameOverState::Instance());

#ifdef WIN32
			TheAudioManager::Instance()->PlaySFX(SfxType::GameOver);
#endif
		}
	}

	if (TheInputHandler::Instance()->isKeyDown( // Pause â
		SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->
			changeState(PauseState::Instance());
	}

	TheGame::Instance()->m_time += 0.01f;
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); ++i)
		m_gameObjects[i]->draw();

#ifdef WIN32
	// Time Unit Change
	int second = (int)floor(TheGame::Instance()->m_time);
	int minute = second / 60;
	second = second % 60;

	// Set Time Text
	std::string a = (minute < 10) ? "0" + std::to_string(minute) : std::to_string(minute);
	std::string b = " : ";
	std::string c = (second < 10) ? "0" + std::to_string(second) : std::to_string(second);
	std::string d = a + b + c;

	char ch[100] = "";
	strcpy(ch, d.c_str());

	// Draw Time Text UI
	SDL_Color color = { 255, 255, 255 };
	TheTextManager::Instance()->drawText(
		ch, 10, 10, 15, color, TheGame::Instance()->getRenderer());
#endif
}

bool PlayState::onEnter()
{
	std::cout << "entering PlayState" << std::endl;

	if (!TheTextureManager::Instance()->load("Assets/platform.png",
		"platform", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("Assets/Ninja_Frog-export.png", 
	"player", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load(
		"Assets/poop-export.png", "poop",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* platform = new Platform(
		new LoaderParams(0, 432, 720, 48, "platform"));
	m_gameObjects.push_back(platform);

	GameObject* player = new Player(
		new LoaderParams(328, 368, 64, 64, "player"));
	m_gameObjects.push_back(player);

	int xPos = -10;
	for (int i = 2; i < 38; i++)
	{
		m_gameObjects.push_back(new Enemy(
			new LoaderParams(xPos, -64, 32, 32, "poop")));
		xPos += 20;
	}

#ifdef WIN32
	TheAudioManager::Instance()->PlayBGM();
#endif // WIN32

	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState" << std::endl;

	for (int i = 0; i < m_gameObjects.size(); i++)
		m_gameObjects[i]->clean();

	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("player");
	TheTextureManager::Instance()->clearFromTextureMap("poop");
	TheTextureManager::Instance()->clearFromTextureMap("platform");

	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }

	return true;
}