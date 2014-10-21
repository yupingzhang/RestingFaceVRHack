RestingFaceVRHack
=================

Health related facial detection using faceshift

Using faceshift to detect the facial expression and analyse the health related sympton such as stroke and pain.

Basic idea:

1. import the neutral as the baseline.

2. while getting the stream data, using the weights of shapes to match a certain patterns,

3. select the key points for numerically measurement, using the vertices to compute the offset comparing to the baseline.

4. set a threshold for certain sympton, rendering heat map to help visualize and detect the danger of stroke or other disease.

Added:

1. Compute the average for 10 frames to reduce the noise.

2. set a interval time to check the certain pattern.

=========================================================
Finial demo

We did emotion patterns detection and facial gestures controls. 
