#include "BerVibrato.h"

BerVibrato::BerVibrato()
: depth(0)
, sampleRate(0)
{
	setFrequency(VIBRATO_FREQUENCY_DEFAULT_HZ);
	setDepth(VIBRATO_DEPTH_DEFAULT_PERCENT / 100);
}

void BerVibrato::initialize(float sr)
{
	sampleRate = sr;
	lfo.initialize(sampleRate, VIBRATO_FREQUENCY_DEFAULT_HZ);
	buffer.resize(BASE_DELAY_SEC * sampleRate * 2);
}

void BerVibrato::setFrequency(float frequency)
{
	lfo.setFrequency(frequency);
}

void BerVibrato::setDepth(float dt)
{
	depth = dt;
}