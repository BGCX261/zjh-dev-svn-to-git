#include "AudioManager.h"
#include <cocos2d.h>
#include <SimpleAudioEngine.h>

GTSINGLETON_IMP(AudioManager);

AudioManager::AudioManager()
{
}


AudioManager::~AudioManager()
{
}


// Initialize the audio
bool AudioManager::Initialize(void)
{
	SetBackgroundMusicVolume(0.5f);
	SetEffectVolume(0.5f);

	return true;
}

// Destroy
void AudioManager::Destroy(void)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->end();
}


// Load a background music
bool AudioManager::LoadBackgroundMusic(const tchar* szFilePath)
{
	if(NULL == szFilePath)
	{
		return false;
	}

	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(szFilePath);

	return true;
}

// Play a background music
bool AudioManager::PlayBackgroundMusic(const tchar* szFilePath, bool bLoop)
{
	if(NULL == szFilePath)
	{
		return false;
	}

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(szFilePath, bLoop);

	return true;
}


// Stop playing background music
bool AudioManager::StopBackgroundMusic(bool bReleaseData)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(bReleaseData);
	return true;
}


// Pause playing background music
bool AudioManager::PauseBackgroundMusic(void)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	return true;
}


// Resume playing background music
bool AudioManager::ResumeBackgroundMusic(void)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	return true;
}


// If the background music is playing
bool AudioManager::IsBackgroundMusicPlaying(void)
{
	return CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying();
}


// Get background music volume, volume = [0.0, 1.0]
float AudioManager::GetBackgroundMusicVolume(void)
{
	return CocosDenshion::SimpleAudioEngine::sharedEngine()->getBackgroundMusicVolume();
}


// Set background music volume, volume = [0.0, 1.0]
void AudioManager::SetBackgroundMusicVolume(float volume)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(volume);
}


// Get effect volume, volume = [0.0, 1.0]
float AudioManager::GetEffectVolume(void)
{
	return CocosDenshion::SimpleAudioEngine::sharedEngine()->getEffectsVolume();
}


// Set effect volume, volume = [0.0, 1.0]
void AudioManager::SetEffectVolume(float volume)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->setEffectsVolume(volume);
}


// Play an effect
uint32 AudioManager::PlayEffect(const tchar* szFilePath, bool bLoop)
{
	if(NULL == szFilePath)
	{
		return 0;
	}

	return CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(szFilePath, bLoop);
}


// Pause an effect
void AudioManager::PauseEffect(int32 nSoundId)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseEffect(nSoundId);
}


// Pause all playing effects
void AudioManager::PauseAllEffects(void)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}


// Resume an effect
void AudioManager::ResumeEffect(int32 nSoundId)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeEffect(nSoundId);
}


// Resume all effects
void AudioManager::ResumeAllEffects(void)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}


// Stop playing an effect
void AudioManager::StopEffect(int32 nSoundId)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopEffect(nSoundId);
}


// Stop playing all effects
void AudioManager::StopAllEffects(void)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopAllEffects();
}


// Load an effect
bool AudioManager::LoadEffect(const tchar* szFilePath)
{
	if(NULL == szFilePath)
	{
		return false;
	}

	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(szFilePath);

	return true;
}


// Unload an effect from internal buffer
void AudioManager::UnloadEffect(const tchar* szFilePath)
{
	if(NULL == szFilePath)
	{
		return;
	}

	CocosDenshion::SimpleAudioEngine::sharedEngine()->unloadEffect(szFilePath);
}
