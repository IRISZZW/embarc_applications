/* ------------------------------------------
 * Copyright (c) 2017, Synopsys, Inc. All rights reserved.

 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:

 * 1) Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.

 * 2) Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.

 * 3) Neither the name of the Synopsys, Inc., nor the names of its contributors may
 * be used
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 --------------------------------------------- */

/**
 * \file
 * \ingroup	EMBARC_APP_FREERTOS_IOT_ILIGHT_SMARTDEVICE
 * \brief	list for speeding up the calculation of sin or cos
 */

/**
 * \addtogroup  EMBARC_APP_FREERTOS_IOT_ILIGHT_SMARTDEVICE
 * @{
 */

/* embARC HAL */
#include "embARC.h"

/* custom HAL */
#include "fft.h"

#ifdef fft_16
/* sine list of 16 points */
const float sin_tab[8] = {
	-0.0000, -0.3827, -0.7071, -0.9239, -1.0000, -0.9239, -0.7071, -0.3827
};
/* cosine list of 16 points */
const float cos_tab[8] = {
	1.0000, 0.9239, 0.7071, 0.3827, 0.0000, -0.3827, -0.7071, -0.9239
};
#endif

#ifdef fft_32
/* sine list of 32 points */
const float sin_tab[16] = {
	-0.0000, -0.1951,
	-0.3827, -0.5556,
	-0.7071, -0.8315,
	-0.9239, -0.9808,
	-1.0000, -0.9808,
	-0.9239, -0.8315,
	-0.7071, -0.5556,
	-0.3827, -0.1951
};
/* cosine list of 32 points */
const float cos_tab[16] = {
	1.0000, 0.9808,
	0.9239, 0.8315,
	0.7071, 0.5556,
	0.3827, 0.1951,
	0.0000, -0.1951,
	-0.3827, -0.5556,
	-0.7071, -0.8315,
	-0.9239, -0.9808
};
#endif


#ifdef fft_64
/* sine list of 64 points */
const float sin_tab[32] = {
	-0.0000, -0.0980, -0.1951, -0.2903, -0.3827, -0.4714,
	-0.5556, -0.6344, -0.7071, -0.7730, -0.8315, -0.8819,
	-0.9239, -0.9569, -0.9808, -0.9952, -1.0000, -0.9952,
	-0.9808, -0.9569, -0.9239, -0.8819, -0.8315, -0.7730,
	-0.7071, -0.6344, -0.5556, -0.4714, -0.3827, -0.2903,
	-0.1951, -0.0980
};

/* cosine list of 64 points */
const float cos_tab[32] = {
	1.0000, 0.9952, 0.9808, 0.9569, 0.9239, 0.8819,
	0.8315, 0.7730, 0.7071, 0.6344, 0.5556, 0.4714,
	0.3827, 0.2903, 0.1951, 0.0980, 0.0000, -0.0980,
	-0.1951, -0.2903, -0.3827, -0.4714, -0.5556, -0.6344,
	-0.7071, -0.7730, -0.8315, -0.8819, -0.9239, -0.9569,
	-0.9808, -0.9952
};
#endif

#ifdef fft_128
/* sine list of 128 points */
const float sin_tab[64] = {
	-0.0000, -0.0491, -0.0980, -0.1467, -0.1951, -0.2430,
	-0.2903, -0.3369, -0.3827, -0.4276, -0.4714, -0.5141,
	-0.5556, -0.5957, -0.6344, -0.6716, -0.7071, -0.7410,
	-0.7730, -0.8032, -0.8315, -0.8577, -0.8819, -0.9040,
	-0.9239, -0.9415, -0.9569, -0.9700, -0.9808, -0.9892,
	-0.9952, -0.9988, -1.0000, -0.9988, -0.9952, -0.9892,
	-0.9808, -0.9700, -0.9569, -0.9415, -0.9239, -0.9040,
	-0.8819, -0.8577, -0.8315, -0.8032, -0.7730, -0.7410,
	-0.7071, -0.6716, -0.6344, -0.5957, -0.5556, -0.5141,
	-0.4714, -0.4276, -0.3827, -0.3369, -0.2903, -0.2430,
	-0.1951, -0.1467, -0.0980, -0.0491
};

/* cosine list of 128 points */
const float cos_tab[64] = {
	1.0000, 0.9988, 0.9952, 0.9892, 0.9808, 0.9700,
	0.9569, 0.9415, 0.9239, 0.9040, 0.8819, 0.8577,
	0.8315, 0.8032, 0.7730, 0.7410, 0.7071, 0.6716,
	0.6344, 0.5957, 0.5556, 0.5141, 0.4714, 0.4276,
	0.3827, 0.3369, 0.2903, 0.2430, 0.1951, 0.1467,
	0.0980, 0.0491, 0.0000, -0.0491, -0.0980, -0.1467,
	-0.1951, -0.2430, -0.2903, -0.3369, -0.3827, -0.4276,
	-0.4714, -0.5141, -0.5556, -0.5957, -0.6344, -0.6716,
	-0.7071, -0.7410, -0.7730, -0.8032, -0.8315, -0.8577,
	-0.8819, -0.9040, -0.9239, -0.9415, -0.9569, -0.9700,
	-0.9808, -0.9892, -0.9952, -0.9988
};
#endif


#ifdef fft_256
/* sine list of 256 points */
const float sin_tab[128] = {
	-0.0000, -0.0245, -0.0491, -0.0736, -0.0980, -0.1224,
	-0.1467, -0.1710, -0.1951, -0.2191, -0.2430, -0.2667,
	-0.2903, -0.3137, -0.3369, -0.3599, -0.3827, -0.4052,
	-0.4276, -0.4496, -0.4714, -0.4929, -0.5141, -0.5350,
	-0.5556, -0.5758, -0.5957, -0.6152, -0.6344, -0.6532,
	-0.6716, -0.6895, -0.7071, -0.7242, -0.7410, -0.7572,
	-0.7730, -0.7883, -0.8032, -0.8176, -0.8315, -0.8449,
	-0.8577, -0.8701, -0.8819, -0.8932, -0.9040, -0.9142,
	-0.9239, -0.9330, -0.9415, -0.9495, -0.9569, -0.9638,
	-0.9700, -0.9757, -0.9808, -0.9853, -0.9892, -0.9925,
	-0.9952, -0.9973, -0.9988, -0.9997, -1.0000, -0.9997,
	-0.9988, -0.9973, -0.9952, -0.9925, -0.9892, -0.9853,
	-0.9808, -0.9757, -0.9700, -0.9638, -0.9569, -0.9495,
	-0.9415, -0.9330, -0.9239, -0.9142, -0.9040, -0.8932,
	-0.8819, -0.8701, -0.8577, -0.8449, -0.8315, -0.8176,
	-0.8032, -0.7883, -0.7730, -0.7572, -0.7410, -0.7242,
	-0.7071, -0.6895, -0.6716, -0.6532, -0.6344, -0.6152,
	-0.5957, -0.5758, -0.5556, -0.5350, -0.5141, -0.4929,
	-0.4714, -0.4496, -0.4276, -0.4052, -0.3827, -0.3599,
	-0.3369, -0.3137, -0.2903, -0.2667, -0.2430, -0.2191,
	-0.1951, -0.1710, -0.1467, -0.1224, -0.0980, -0.0736,
	-0.0491, -0.0245
};

/* cosine list of 256 points */
const float cos_tab[128] = {
	1.0000, 0.9997, 0.9988, 0.9973, 0.9952, 0.9925,
	0.9892, 0.9853, 0.9808, 0.9757, 0.9700, 0.9638,
	0.9569, 0.9495, 0.9415, 0.9330, 0.9239, 0.9142,
	0.9040, 0.8932, 0.8819, 0.8701, 0.8577, 0.8449,
	0.8315, 0.8176, 0.8032, 0.7883, 0.7730, 0.7572,
	0.7410, 0.7242, 0.7071, 0.6895, 0.6716, 0.6532,
	0.6344, 0.6152, 0.5957, 0.5758, 0.5556, 0.5350,
	0.5141, 0.4929, 0.4714, 0.4496, 0.4276, 0.4052,
	0.3827, 0.3599, 0.3369, 0.3137, 0.2903, 0.2667,
	0.2430, 0.2191, 0.1951, 0.1710, 0.1467, 0.1224,
	0.0980, 0.0736, 0.0491, 0.0245, 0.0000, -0.0245,
	-0.0491, -0.0736, -0.0980, -0.1224, -0.1467, -0.1710,
	-0.1951, -0.2191, -0.2430, -0.2667, -0.2903, -0.3137,
	-0.3369, -0.3599, -0.3827, -0.4052, -0.4276, -0.4496,
	-0.4714, -0.4929, -0.5141, -0.5350, -0.5556, -0.5758,
	-0.5957, -0.6152, -0.6344, -0.6532, -0.6716, -0.6895,
	-0.7071, -0.7242, -0.7410, -0.7572, -0.7730, -0.7883,
	-0.8032, -0.8176, -0.8315, -0.8449, -0.8577, -0.8701,
	-0.8819, -0.8932, -0.9040, -0.9142, -0.9239, -0.9330,
	-0.9415, -0.9495, -0.9569, -0.9638, -0.9700, -0.9757,
	-0.9808, -0.9853, -0.9892, -0.9925, -0.9952, -0.9973,
	-0.9988, -0.9997
};
#endif

#ifdef fft_512
/* sine list of 512 points */
const float sin_tab[256] = {
	-0.0000, -0.0123, -0.0245, -0.0368, -0.0491, -0.0613,
	-0.0736, -0.0858, -0.0980, -0.1102, -0.1224, -0.1346,
	-0.1467, -0.1589, -0.1710, -0.1830, -0.1951, -0.2071,
	-0.2191, -0.2311, -0.2430, -0.2549, -0.2667, -0.2785,
	-0.2903, -0.3020, -0.3137, -0.3253, -0.3369, -0.3484,
	-0.3599, -0.3713, -0.3827, -0.3940, -0.4052, -0.4164,
	-0.4276, -0.4386, -0.4496, -0.4605, -0.4714, -0.4822,
	-0.4929, -0.5035, -0.5141, -0.5246, -0.5350, -0.5453,
	-0.5556, -0.5657, -0.5758, -0.5858, -0.5957, -0.6055,
	-0.6152, -0.6249, -0.6344, -0.6438, -0.6532, -0.6624,
	-0.6716, -0.6806, -0.6895, -0.6984, -0.7071, -0.7157,
	-0.7242, -0.7327, -0.7410, -0.7491, -0.7572, -0.7652,
	-0.7730, -0.7807, -0.7883, -0.7958, -0.8032, -0.8105,
	-0.8176, -0.8246, -0.8315, -0.8382, -0.8449, -0.8514,
	-0.8577, -0.8640, -0.8701, -0.8761, -0.8819, -0.8876,
	-0.8932, -0.8987, -0.9040, -0.9092, -0.9142, -0.9191,
	-0.9239, -0.9285, -0.9330, -0.9373, -0.9415, -0.9456,
	-0.9495, -0.9533, -0.9569, -0.9604, -0.9638, -0.9670,
	-0.9700, -0.9729, -0.9757, -0.9783, -0.9808, -0.9831,
	-0.9853, -0.9873, -0.9892, -0.9909, -0.9925, -0.9939,
	-0.9952, -0.9963, -0.9973, -0.9981, -0.9988, -0.9993,
	-0.9997, -0.9999, -1.0000, -0.9999, -0.9997, -0.9993,
	-0.9988, -0.9981, -0.9973, -0.9963, -0.9952, -0.9939,
	-0.9925, -0.9909, -0.9892, -0.9873, -0.9853, -0.9831,
	-0.9808, -0.9783, -0.9757, -0.9729, -0.9700, -0.9670,
	-0.9638, -0.9604, -0.9569, -0.9533, -0.9495, -0.9456,
	-0.9415, -0.9373, -0.9330, -0.9285, -0.9239, -0.9191,
	-0.9142, -0.9092, -0.9040, -0.8987, -0.8932, -0.8876,
	-0.8819, -0.8761, -0.8701, -0.8640, -0.8577, -0.8514,
	-0.8449, -0.8382, -0.8315, -0.8246, -0.8176, -0.8105,
	-0.8032, -0.7958, -0.7883, -0.7807, -0.7730, -0.7652,
	-0.7572, -0.7491, -0.7410, -0.7327, -0.7242, -0.7157,
	-0.7071, -0.6984, -0.6895, -0.6806, -0.6716, -0.6624,
	-0.6532, -0.6438, -0.6344, -0.6249, -0.6152, -0.6055,
	-0.5957, -0.5858, -0.5758, -0.5657, -0.5556, -0.5453,
	-0.5350, -0.5246, -0.5141, -0.5035, -0.4929, -0.4822,
	-0.4714, -0.4605, -0.4496, -0.4386, -0.4276, -0.4164,
	-0.4052, -0.3940, -0.3827, -0.3713, -0.3599, -0.3484,
	-0.3369, -0.3253, -0.3137, -0.3020, -0.2903, -0.2785,
	-0.2667, -0.2549, -0.2430, -0.2311, -0.2191, -0.2071,
	-0.1951, -0.1830, -0.1710, -0.1589, -0.1467, -0.1346,
	-0.1224, -0.1102, -0.0980, -0.0858, -0.0736, -0.0613,
	-0.0491, -0.0368, -0.0245, -0.0123
};

/* cosine list of 512 points */
const float cos_tab[256] = {
	1.0000 , 0.9999, 0.9997, 0.9993, 0.9988, 0.9981,
	0.9973, 0.9963, 0.9952, 0.9939, 0.9925, 0.9909,
	0.9892, 0.9873, 0.9853, 0.9831, 0.9808, 0.9783,
	0.9757, 0.9729, 0.9700, 0.9670, 0.9638, 0.9604,
	0.9569, 0.9533, 0.9495, 0.9456, 0.9415, 0.9373,
	0.9330, 0.9285, 0.9239, 0.9191, 0.9142, 0.9092,
	0.9040, 0.8987, 0.8932, 0.8876, 0.8819, 0.8761,
	0.8701, 0.8640, 0.8577, 0.8514, 0.8449, 0.8382,
	0.8315, 0.8246, 0.8176, 0.8105, 0.8032, 0.7958,
	0.7883, 0.7807, 0.7730, 0.7652, 0.7572, 0.7491,
	0.7410, 0.7327, 0.7242, 0.7157, 0.7071, 0.6984,
	0.6895, 0.6806, 0.6716, 0.6624, 0.6532, 0.6438,
	0.6344, 0.6249, 0.6152, 0.6055, 0.5957, 0.5858,
	0.5758, 0.5657, 0.5556, 0.5453, 0.5350, 0.5246,
	0.5141, 0.5035, 0.4929, 0.4822, 0.4714, 0.4605,
	0.4496, 0.4386, 0.4276, 0.4164, 0.4052, 0.3940,
	0.3827, 0.3713, 0.3599, 0.3484, 0.3369, 0.3253,
	0.3137, 0.3020, 0.2903, 0.2785, 0.2667, 0.2549,
	0.2430, 0.2311, 0.2191, 0.2071, 0.1951, 0.1830,
	0.1710, 0.1589, 0.1467, 0.1346, 0.1224, 0.1102,
	0.0980, 0.0858, 0.0736, 0.0613, 0.0491, 0.0368,
	0.0245, 0.0123, 0.0000, -0.0123, -0.0245, -0.0368,
	-0.0491, -0.0613, -0.0736, -0.0858, -0.0980, -0.1102,
	-0.1224, -0.1346, -0.1467, -0.1589, -0.1710, -0.1830,
	-0.1951, -0.2071, -0.2191, -0.2311, -0.2430, -0.2549,
	-0.2667, -0.2785, -0.2903, -0.3020, -0.3137, -0.3253,
	-0.3369, -0.3484, -0.3599, -0.3713, -0.3827, -0.3940,
	-0.4052, -0.4164, -0.4276, -0.4386, -0.4496, -0.4605,
	-0.4714, -0.4822, -0.4929, -0.5035, -0.5141, -0.5246,
	-0.5350, -0.5453, -0.5556, -0.5657, -0.5758, -0.5858,
	-0.5957, -0.6055, -0.6152, -0.6249, -0.6344, -0.6438,
	-0.6532, -0.6624, -0.6716, -0.6806, -0.6895, -0.6984,
	-0.7071, -0.7157, -0.7242, -0.7327, -0.7410, -0.7491,
	-0.7572, -0.7652, -0.7730, -0.7807, -0.7883, -0.7958,
	-0.8032, -0.8105, -0.8176, -0.8246, -0.8315, -0.8382,
	-0.8449, -0.8514, -0.8577, -0.8640, -0.8701, -0.8761,
	-0.8819, -0.8876, -0.8932, -0.8987, -0.9040, -0.9092,
	-0.9142, -0.9191, -0.9239, -0.9285, -0.9330, -0.9373,
	-0.9415, -0.9456, -0.9495, -0.9533, -0.9569, -0.9604,
	-0.9638, -0.9670, -0.9700, -0.9729, -0.9757, -0.9783,
	-0.9808, -0.9831, -0.9853, -0.9873, -0.9892, -0.9909,
	-0.9925, -0.9939, -0.9952, -0.9963, -0.9973, -0.9981,
	-0.9988, -0.9993, -0.9997, -0.9999
};
#endif

/** sin and cos list of 1024 points */
#ifdef fft_1024
/* sine list of 512 points */
const float sin_tab[512] = {
	-0.0000, -0.0061, -0.0123, -0.0184, -0.0245, -0.0307,
	-0.0368, -0.0429, -0.0491, -0.0552, -0.0613, -0.0674,
	-0.0736, -0.0797, -0.0858, -0.0919, -0.0980, -0.1041,
	-0.1102, -0.1163, -0.1224, -0.1285, -0.1346, -0.1407,
	-0.1467, -0.1528, -0.1589, -0.1649, -0.1710, -0.1770,
	-0.1830, -0.1891, -0.1951, -0.2011, -0.2071, -0.2131,
	-0.2191, -0.2251, -0.2311, -0.2370, -0.2430, -0.2489,
	-0.2549, -0.2608, -0.2667, -0.2726, -0.2785, -0.2844,
	-0.2903, -0.2962, -0.3020, -0.3078, -0.3137, -0.3195,
	-0.3253, -0.3311, -0.3369, -0.3427, -0.3484, -0.3542,
	-0.3599, -0.3656, -0.3713, -0.3770, -0.3827, -0.3883,
	-0.3940, -0.3996, -0.4052, -0.4108, -0.4164, -0.4220,
	-0.4276, -0.4331, -0.4386, -0.4441, -0.4496, -0.4551,
	-0.4605, -0.4660, -0.4714, -0.4768, -0.4822, -0.4876,
	-0.4929, -0.4982, -0.5035, -0.5088, -0.5141, -0.5194,
	-0.5246, -0.5298, -0.5350, -0.5402, -0.5453, -0.5505,
	-0.5556, -0.5607, -0.5657, -0.5708, -0.5758, -0.5808,
	-0.5858, -0.5908, -0.5957, -0.6006, -0.6055, -0.6104,
	-0.6152, -0.6201, -0.6249, -0.6296, -0.6344, -0.6391,
	-0.6438, -0.6485, -0.6532, -0.6578, -0.6624, -0.6670,
	-0.6716, -0.6761, -0.6806, -0.6851, -0.6895, -0.6940,
	-0.6984, -0.7028, -0.7071, -0.7114, -0.7157, -0.7200,
	-0.7242, -0.7285, -0.7327, -0.7368, -0.7410, -0.7451,
	-0.7491, -0.7532, -0.7572, -0.7612, -0.7652, -0.7691,
	-0.7730, -0.7769, -0.7807, -0.7846, -0.7883, -0.7921,
	-0.7958, -0.7995, -0.8032, -0.8068, -0.8105, -0.8140,
	-0.8176, -0.8211, -0.8246, -0.8280, -0.8315, -0.8349,
	-0.8382, -0.8416, -0.8449, -0.8481, -0.8514, -0.8546,
	-0.8577, -0.8609, -0.8640, -0.8670, -0.8701, -0.8731,
	-0.8761, -0.8790, -0.8819, -0.8848, -0.8876, -0.8904,
	-0.8932, -0.8960, -0.8987, -0.9013, -0.9040, -0.9066,
	-0.9092, -0.9117, -0.9142, -0.9167, -0.9191, -0.9215,
	-0.9239, -0.9262, -0.9285, -0.9308, -0.9330, -0.9352,
	-0.9373, -0.9395, -0.9415, -0.9436, -0.9456, -0.9476,
	-0.9495, -0.9514, -0.9533, -0.9551, -0.9569, -0.9587,
	-0.9604, -0.9621, -0.9638, -0.9654, -0.9670, -0.9685,
	-0.9700, -0.9715, -0.9729, -0.9743, -0.9757, -0.9770,
	-0.9783, -0.9796, -0.9808, -0.9820, -0.9831, -0.9842,
	-0.9853, -0.9863, -0.9873, -0.9883, -0.9892, -0.9901,
	-0.9909, -0.9917, -0.9925, -0.9932, -0.9939, -0.9946,
	-0.9952, -0.9958, -0.9963, -0.9968, -0.9973, -0.9977,
	-0.9981, -0.9985, -0.9988, -0.9991, -0.9993, -0.9995,
	-0.9997, -0.9998, -0.9999, -1.0000, -1.0000, -1.0000,
	-0.9999, -0.9998, -0.9997, -0.9995, -0.9993, -0.9991,
	-0.9988, -0.9985, -0.9981, -0.9977, -0.9973, -0.9968,
	-0.9963, -0.9958, -0.9952, -0.9946, -0.9939, -0.9932,
	-0.9925, -0.9917, -0.9909, -0.9901, -0.9892, -0.9883,
	-0.9873, -0.9863, -0.9853, -0.9842, -0.9831, -0.9820,
	-0.9808, -0.9796, -0.9783, -0.9770, -0.9757, -0.9743,
	-0.9729, -0.9715, -0.9700, -0.9685, -0.9670, -0.9654,
	-0.9638, -0.9621, -0.9604, -0.9587, -0.9569, -0.9551,
	-0.9533, -0.9514, -0.9495, -0.9476, -0.9456, -0.9436,
	-0.9415, -0.9395, -0.9373, -0.9352, -0.9330, -0.9308,
	-0.9285, -0.9262, -0.9239, -0.9215, -0.9191, -0.9167,
	-0.9142, -0.9117, -0.9092, -0.9066, -0.9040, -0.9013,
	-0.8987, -0.8960, -0.8932, -0.8904, -0.8876, -0.8848,
	-0.8819, -0.8790, -0.8761, -0.8731, -0.8701, -0.8670,
	-0.8640, -0.8609, -0.8577, -0.8546, -0.8514, -0.8481,
	-0.8449, -0.8416, -0.8382, -0.8349, -0.8315, -0.8280,
	-0.8246, -0.8211, -0.8176, -0.8140, -0.8105, -0.8068,
	-0.8032, -0.7995, -0.7958, -0.7921, -0.7883, -0.7846,
	-0.7807, -0.7769, -0.7730, -0.7691, -0.7652, -0.7612,
	-0.7572, -0.7532, -0.7491, -0.7451, -0.7410, -0.7368,
	-0.7327, -0.7285, -0.7242, -0.7200, -0.7157, -0.7114,
	-0.7071, -0.7028, -0.6984, -0.6940, -0.6895, -0.6851,
	-0.6806, -0.6761, -0.6716, -0.6670, -0.6624, -0.6578,
	-0.6532, -0.6485, -0.6438, -0.6391, -0.6344, -0.6296,
	-0.6249, -0.6201, -0.6152, -0.6104, -0.6055, -0.6006,
	-0.5957, -0.5908, -0.5858, -0.5808, -0.5758, -0.5708,
	-0.5657, -0.5607, -0.5556, -0.5505, -0.5453, -0.5402,
	-0.5350, -0.5298, -0.5246, -0.5194, -0.5141, -0.5088,
	-0.5035, -0.4982, -0.4929, -0.4876, -0.4822, -0.4768,
	-0.4714, -0.4660, -0.4605, -0.4551, -0.4496, -0.4441,
	-0.4386, -0.4331, -0.4276, -0.4220, -0.4164, -0.4108,
	-0.4052, -0.3996, -0.3940, -0.3883, -0.3827, -0.3770,
	-0.3713, -0.3656, -0.3599, -0.3542, -0.3484, -0.3427,
	-0.3369, -0.3311, -0.3253, -0.3195, -0.3137, -0.3078,
	-0.3020, -0.2962, -0.2903, -0.2844, -0.2785, -0.2726,
	-0.2667, -0.2608, -0.2549, -0.2489, -0.2430, -0.2370,
	-0.2311, -0.2251, -0.2191, -0.2131, -0.2071, -0.2011,
	-0.1951, -0.1891, -0.1830, -0.1770, -0.1710, -0.1649,
	-0.1589, -0.1528, -0.1467, -0.1407, -0.1346, -0.1285,
	-0.1224, -0.1163, -0.1102, -0.1041, -0.0980, -0.0919,
	-0.0858, -0.0797, -0.0736, -0.0674, -0.0613, -0.0552,
	-0.0491, -0.0429, -0.0368, -0.0307, -0.0245, -0.0184,
	-0.0123, -0.0061
};

/* cosine list of 1024 points */
const float cos_tab[512] = {
	1.0000, 1.0000, 0.9999, 0.9998, 0.9997, 0.9995,
	0.9993, 0.9991, 0.9988, 0.9985, 0.9981, 0.9977,
	0.9973, 0.9968, 0.9963, 0.9958, 0.9952, 0.9946,
	0.9939, 0.9932, 0.9925, 0.9917, 0.9909, 0.9901,
	0.9892, 0.9883, 0.9873, 0.9863, 0.9853, 0.9842,
	0.9831, 0.9820, 0.9808, 0.9796, 0.9783, 0.9770,
	0.9757, 0.9743, 0.9729, 0.9715, 0.9700, 0.9685,
	0.9670, 0.9654, 0.9638, 0.9621, 0.9604, 0.9587,
	0.9569, 0.9551, 0.9533, 0.9514, 0.9495, 0.9476,
	0.9456, 0.9436, 0.9415, 0.9395, 0.9373, 0.9352,
	0.9330, 0.9308, 0.9285, 0.9262, 0.9239, 0.9215,
	0.9191, 0.9167, 0.9142, 0.9117, 0.9092, 0.9066,
	0.9040, 0.9013, 0.8987, 0.8960, 0.8932, 0.8904,
	0.8876, 0.8848, 0.8819, 0.8790, 0.8761, 0.8731,
	0.8701, 0.8670, 0.8640, 0.8609, 0.8577, 0.8546,
	0.8514, 0.8481, 0.8449, 0.8416, 0.8382, 0.8349,
	0.8315, 0.8280, 0.8246, 0.8211, 0.8176, 0.8140,
	0.8105, 0.8068, 0.8032, 0.7995, 0.7958, 0.7921,
	0.7883, 0.7846, 0.7807, 0.7769, 0.7730, 0.7691,
	0.7652, 0.7612, 0.7572, 0.7532, 0.7491, 0.7451,
	0.7410, 0.7368, 0.7327, 0.7285, 0.7242, 0.7200,
	0.7157, 0.7114, 0.7071, 0.7028, 0.6984, 0.6940,
	0.6895, 0.6851, 0.6806, 0.6761, 0.6716, 0.6670,
	0.6624, 0.6578, 0.6532, 0.6485, 0.6438, 0.6391,
	0.6344, 0.6296, 0.6249, 0.6201, 0.6152, 0.6104,
	0.6055, 0.6006, 0.5957, 0.5908, 0.5858, 0.5808,
	0.5758, 0.5708, 0.5657, 0.5607, 0.5556, 0.5505,
	0.5453, 0.5402, 0.5350, 0.5298, 0.5246, 0.5194,
	0.5141, 0.5088, 0.5035, 0.4982, 0.4929, 0.4876,
	0.4822, 0.4768, 0.4714, 0.4660, 0.4605, 0.4551,
	0.4496, 0.4441, 0.4386, 0.4331, 0.4276, 0.4220,
	0.4164, 0.4108, 0.4052, 0.3996, 0.3940, 0.3883,
	0.3827, 0.3770, 0.3713, 0.3656, 0.3599, 0.3542,
	0.3484, 0.3427, 0.3369, 0.3311, 0.3253, 0.3195,
	0.3137, 0.3078, 0.3020, 0.2962, 0.2903, 0.2844,
	0.2785, 0.2726, 0.2667, 0.2608, 0.2549, 0.2489,
	0.2430, 0.2370, 0.2311, 0.2251, 0.2191, 0.2131,
	0.2071, 0.2011, 0.1951, 0.1891, 0.1830, 0.1770,
	0.1710, 0.1649, 0.1589, 0.1528, 0.1467, 0.1407,
	0.1346, 0.1285, 0.1224, 0.1163, 0.1102, 0.1041,
	0.0980, 0.0919, 0.0858, 0.0797, 0.0736, 0.0674,
	0.0613, 0.0552, 0.0491, 0.0429, 0.0368, 0.0307,
	0.0245, 0.0184, 0.0123, 0.0061, 0.0000, -0.0061,
	-0.0123, -0.0184, -0.0245, -0.0307, -0.0368, -0.0429,
	-0.0491, -0.0552, -0.0613, -0.0674, -0.0736, -0.0797,
	-0.0858, -0.0919, -0.0980, -0.1041, -0.1102, -0.1163,
	-0.1224, -0.1285, -0.1346, -0.1407, -0.1467, -0.1528,
	-0.1589, -0.1649, -0.1710, -0.1770, -0.1830, -0.1891,
	-0.1951, -0.2011, -0.2071, -0.2131, -0.2191, -0.2251,
	-0.2311, -0.2370, -0.2430, -0.2489, -0.2549, -0.2608,
	-0.2667, -0.2726, -0.2785, -0.2844, -0.2903, -0.2962,
	-0.3020, -0.3078, -0.3137, -0.3195, -0.3253, -0.3311,
	-0.3369, -0.3427, -0.3484, -0.3542, -0.3599, -0.3656,
	-0.3713, -0.3770, -0.3827, -0.3883, -0.3940, -0.3996,
	-0.4052, -0.4108, -0.4164, -0.4220, -0.4276, -0.4331,
	-0.4386, -0.4441, -0.4496, -0.4551, -0.4605, -0.4660,
	-0.4714, -0.4768, -0.4822, -0.4876, -0.4929, -0.4982,
	-0.5035, -0.5088, -0.5141, -0.5194, -0.5246, -0.5298,
	-0.5350, -0.5402, -0.5453, -0.5505, -0.5556, -0.5607,
	-0.5657, -0.5708, -0.5758, -0.5808, -0.5858, -0.5908,
	-0.5957, -0.6006, -0.6055, -0.6104, -0.6152, -0.6201,
	-0.6249, -0.6296, -0.6344, -0.6391, -0.6438, -0.6485,
	-0.6532, -0.6578, -0.6624, -0.6670, -0.6716, -0.6761,
	-0.6806, -0.6851, -0.6895, -0.6940, -0.6984, -0.7028,
	-0.7071, -0.7114, -0.7157, -0.7200, -0.7242, -0.7285,
	-0.7327, -0.7368, -0.7410, -0.7451, -0.7491, -0.7532,
	-0.7572, -0.7612, -0.7652, -0.7691, -0.7730, -0.7769,
	-0.7807, -0.7846, -0.7883, -0.7921, -0.7958, -0.7995,
	-0.8032, -0.8068, -0.8105, -0.8140, -0.8176, -0.8211,
	-0.8246, -0.8280, -0.8315, -0.8349, -0.8382, -0.8416,
	-0.8449, -0.8481, -0.8514, -0.8546, -0.8577, -0.8609,
	-0.8640, -0.8670, -0.8701, -0.8731, -0.8761, -0.8790,
	-0.8819, -0.8848, -0.8876, -0.8904, -0.8932, -0.8960,
	-0.8987, -0.9013, -0.9040, -0.9066, -0.9092, -0.9117,
	-0.9142, -0.9167, -0.9191, -0.9215, -0.9239, -0.9262,
	-0.9285, -0.9308, -0.9330, -0.9352, -0.9373, -0.9395,
	-0.9415, -0.9436, -0.9456, -0.9476, -0.9495, -0.9514,
	-0.9533, -0.9551, -0.9569, -0.9587, -0.9604, -0.9621,
	-0.9638, -0.9654, -0.9670, -0.9685, -0.9700, -0.9715,
	-0.9729, -0.9743, -0.9757, -0.9770, -0.9783, -0.9796,
	-0.9808, -0.9820, -0.9831, -0.9842, -0.9853, -0.9863,
	-0.9873, -0.9883, -0.9892, -0.9901, -0.9909, -0.9917,
	-0.9925, -0.9932, -0.9939, -0.9946, -0.9952, -0.9958,
	-0.9963, -0.9968, -0.9973, -0.9977, -0.9981, -0.9985,
	-0.9988, -0.9991, -0.9993, -0.9995, -0.9997, -0.9998,
	-0.9999, -1.0000
};

#endif

/** @} */

