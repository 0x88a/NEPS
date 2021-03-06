#pragma once

#include "Pad.h"
#include "VirtualMethod.h"
#include "Vector.h"

struct SoundInfo
{
	PAD(40)
	float volume;
	PAD(12)
	int	entityIndex;
	int channel;
	int pitch;
	int flags;
	int soundIndex;
};

struct SoundParams
{
	void *filter;
	int entityIndex = -1;
	int channel;
	const char *soundEntry;
	int soundEntryHash;
	const char *sample;
	float volume = 1.0f;
	int seed;
	int soundLevel;
	int flags;
	int pitch = 100;
	Vector origin;
	PAD(3)
	bool updatePosition;
	float soundTime = 0.0f;
	int speakerEntity = -1;
	PAD(4)
};

struct ActiveChannels
{
	int count;
	short list[128];
};

struct Channel
{
	PAD(244)
	int soundSource;
	PAD(56)
	Vector origin;
	Vector direction;
	PAD(80)
};

class SoundEmitter
{
public:
	VIRTUAL_METHOD(const char *, getSoundName, 46, (int index), (this, index))
};

class Sound
{
public:
	VIRTUAL_METHOD(int, emitSound, 5, (SoundParams data), (this, data))
};
