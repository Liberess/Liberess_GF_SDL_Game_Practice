#include "AudioManager.h"
#include <random>
#include <charconv>

AudioManager* AudioManager::s_pInstance = 0;

AudioManager::AudioManager()
	: m_sfx(0), m_bgm(0)
{
#ifdef WIN32
	Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
#endif
	init();
}

void AudioManager::init()
{
#ifdef WIN32
	Mix_VolumeMusic(30);
#endif
}

void AudioManager::PlaySFX(SfxType type)
{
#ifdef WIN32
	switch (type)
	{
	case SfxType::Coin:
		m_sfx = Mix_LoadWAV("Assets/Audio/SFX/Coin.wav");
		Mix_PlayChannel(0, m_sfx, 0);
		break;
	case SfxType::BtnClick:
		m_sfx = Mix_LoadWAV("Assets/Audio/SFX/BtnClick.mp3");
		Mix_PlayChannel(1, m_sfx, 0);
		break;
	case SfxType::GameOver:
		m_sfx = Mix_LoadWAV("Assets/Audio/SFX/GameOver.wav");
		Mix_PlayChannel(2, m_sfx, 0);
		break;
	case SfxType::Poop:
		m_sfx = Mix_LoadWAV("Assets/Audio/SFX/Poop.mp3");
		Mix_PlayChannel(3, m_sfx, 0);
		break;
	case SfxType::Move:
		m_sfx = Mix_LoadWAV("Assets/Audio/SFX/Move.mp3");
		Mix_PlayChannel(4, m_sfx, -1);
		SetSFXVolume(50);
		break;
	default:
		break;
	}
#endif

	// Mix_LoadWAV() : ȿ� �ε�
	// Mix_VolumeChunk() : ȿ� � �
	// Mix_PlayChannel() : ȿ� � (ä� 0~9, �ش� ȿ�, -1 = �ѹݺ� / n = n� �ݺ�)
	// Mix_HaltChannel() : �ش� ȿ� � (int = ä�, -1 = � ä�)
	// Mix_Pause() : �ش� ȿ� �Ͻ� � (int = ä�, -1 = � ä�)
	// Mix_Resume() : �ش� ȿ� �ٽ� � (int = ä�, -1 = � ä�)
	// Mix_FreeChunk() : ȿ� �
}

void AudioManager::PlayBGM()
{
#ifdef WIN32
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 3);

	char ch[10] = "";
	std::sprintf(ch, "%d", dis(gen));

	char result[100] = "";
	strcpy(result, "Assets/Audio/BGM/BGM0");
	strcat(result, ch);

	char ch2[] = ".wav";
	strcat(result, ch2);

	//m_bgm = Mix_LoadMUS("Assets/Audio/BGM/BGM00.wav");
	m_bgm = Mix_LoadMUS(result);
	if (m_bgm != nullptr)
		Mix_PlayMusic(m_bgm, -1);
#endif

	// Mix_LoadMUS() : � �ε�
	// Mix_VolumeMusic() : � � �
	// Mix_PlayMusic() : � � (�ش� ȿ�, -1 = �ѹݺ� / n = n� �ݺ�)
	// Mix_HaltMusic() : � �
	// Mix_PauseMusic() : � �Ͻ� �
	// Mix_ResumeMusic() : � �ٽ� �
	// Mix_FreeMusic() : � �

}

void AudioManager::SetSFXVolume(int value)
{
	if (value >= 0 && value <= 100)
		m_sfxVolume = value;
	else
		m_sfxVolume = 50;

#ifdef WIN32
	Mix_VolumeChunk(m_sfx, m_sfxVolume);
#endif
}

void AudioManager::SetBGMVolume(int value)
{
	if (value >= 0 && value <= 100)
		m_bgmVolume = value;
	else
		m_bgmVolume = 50;

#ifdef WIN32
	Mix_VolumeMusic(m_bgmVolume);
#endif
}

void AudioManager::clean()
{
#ifdef WIN32
	Mix_CloseAudio();
#endif
}

AudioManager::~AudioManager()
{
	clean();
}