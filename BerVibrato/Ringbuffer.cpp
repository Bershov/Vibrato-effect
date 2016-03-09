#include "RingBuffer.h"

RingBuffer::RingBuffer()
: size(0), writeIndex(0)
{}

void RingBuffer::resize(int sz)
{
	size = sz;
	buffer.resize(size + interpolatorMargin);
}

void RingBuffer::write(float sample)
{
	buffer[writeIndex] = sample;
	writeIndex++;
	if(writeIndex == size){
		writeIndex = 0;
	}
}

void RingBuffer::write_margined(float sample)
{
    buffer[writeIndex] = sample;

    if( writeIndex < interpolatorMargin )
    {
        buffer[size + writeIndex] = sample;
    }

    writeIndex++;
    if(writeIndex == size){
        writeIndex = 0;
    }
}

float RingBuffer::readWithDelay(int delay){
	int readIndex = writeIndex - delay;
	if (readIndex < 0){
		readIndex += size;
	}
	return buffer[readIndex];
}