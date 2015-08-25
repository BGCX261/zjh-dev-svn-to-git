#ifndef _AUDIO_MANAGER_H_
#define _AUDIO_MANAGER_H_

#include <GTGreenTea.h>

class AudioManager : public GTSingleton<AudioManager>
{
public:
	AudioManager();
	~AudioManager();

	// Initialize the audio
	bool Initialize(void);
	// Destroy
	void Destroy(void);

	// Load a background music
	bool LoadBackgroundMusic(const tchar* szFilePath);
	// Play a background music
	bool PlayBackgroundMusic(const tchar* szFilePath, bool bLoop);
	// Stop playing background music
	bool StopBackgroundMusic(bool bReleaseData = false);
	// Pause playing background music
	bool PauseBackgroundMusic(void);
	// Resume playing background music
	bool ResumeBackgroundMusic(void);
	// If the background music is playing
	bool IsBackgroundMusicPlaying(void);
	// Get background music volume, volume = [0.0, 1.0]
	float GetBackgroundMusicVolume(void);
	// Set background music volume, volume = [0.0, 1.0]
	void SetBackgroundMusicVolume(float volume);

	// Get effect volume, volume = [0.0, 1.0]
	float GetEffectVolume(void);
	// Set effect volume, volume = [0.0, 1.0]
    void SetEffectVolume(float volume);
	// Play an effect
	uint32 PlayEffect(const tchar* szFilePath, bool bLoop = false);
	// Pause an effect
	void PauseEffect(int32 nSoundId);
	// Pause all playing effects
	void PauseAllEffects(void);
	// Resume an effect
	void ResumeEffect(int32 nSoundId);
	// Resume all effects
	void ResumeAllEffects(void);
	// Stop playing an effect
	void StopEffect(int32 nSoundId);
	// Stop playing all effects
	void StopAllEffects(void);
	// Load an effect
	bool LoadEffect(const tchar* szFilePath);
	// Unload an effect from internal buffer
    void UnloadEffect(const tchar* szFilePath);
};

#endif /* _AUDIO_MANAGER_H_ */
