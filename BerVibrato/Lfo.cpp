#include "Lfo.h"
#define _USE_MATH_DEFINES
#include <math.h> /*sin*/

Lfo::Lfo() 
	: index(0), sampleRate(0), frequency(0), phase(0)
{}

Lfo::~Lfo(void) {}

void Lfo::initialize(float sr, float freq) 
{
	sampleRate = sr;
	frequency = freq;
}

void Lfo::setFrequency(float freq) 
{
	frequency = freq;
}

void Lfo::setPhase(float ph)
{
	phase = ph;
}

float Lfo::getValue()
{
    const float dp = 2 * M_PI * frequency / sampleRate; // phase step

    float value = sin(phase);
    value = (value + 1) * 0.5; // transform from [-1; 1] to [0; 1]

    phase += dp;
    while(phase > 2 * M_PI)
        phase -= 2 * M_PI;

    return value; 
}
