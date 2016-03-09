Vibrato audio effect.   
Vibrato is a musical effect consisting of a regular, pulsating change of pitch. It is used to add expression to vocal and instrumental music   

Using:  
  
\#include "BerVibrato/BerVibrato.h"  
//...
BerVibrato vbr;  
vbr.initialize(SampleRateHz);  
//...  
vbr.setDepth(depth); // depth (amount) from (0; 1]  
vbr.setFrequency(freq); // Vibrato rate in Hz  
//...  
vbr.processOneSample(sample);  
