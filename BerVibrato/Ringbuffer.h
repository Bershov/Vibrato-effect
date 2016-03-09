#ifndef __RINGBUFFER_H
#define __RINGBUFFER_H

#ifdef _MSC_VER  
#define INLINE __forceinline
#else
#define INLINE inline
#endif

#include <vector>

// Hermite polynomial interpolation
INLINE float getSampleHermite4p3o(float x, float *y)
{
    static float c0, c1, c2, c3;

    // 4-point, 3rd-order Hermite (x-form)
    c0 = y[1];
    c1 = (1.0/2.0)*(y[2]-y[0]);
    c2 = (y[0] - (5.0/2.0)*y[1]) + (2.0*y[2] - (1.0/2.0)*y[3]);
    c3 = (1.0/2.0)*(y[3]-y[0]) + (3.0/2.0)*(y[1]-y[2]);
    return ((c3*x+c2)*x+c1)*x+c0;
}

class RingBuffer
{
public:
	RingBuffer();

    void write(float sample);
    void write_margined(float sample);
    float readWithDelay(int delay);
	void resize(int size);

public:
    INLINE float getHermiteAt(float delay)
    {
        float fReadIndex = writeIndex - 1 - delay;
        while(fReadIndex < 0)
            fReadIndex += size;
        while(fReadIndex >= size)
            fReadIndex -= size;

        int iPart = (int)fReadIndex; // integer part of the delay
        float fPart = fReadIndex - iPart; // fractional part of the delay
        
        return getSampleHermite4p3o(fPart, &(buffer[iPart]));
    }

private:
	std::vector<float>  buffer;
	int                 writeIndex;
	int                 size;

    static const int interpolatorMargin = 3;
};

#endif