#pragma once
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <sys/time.h>

#define BEGIN_TIME \
			struct timeval start_time;\
        	gettimeofday(&start_time, NULL);

#define END_TIME \
        	struct timeval end_time;\
        	gettimeofday(&end_time, NULL);\
        	printf("経過時間 %lf秒\n", (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec)*1.0E-6);


#define FIXED_POINT (1 << 12) // 4096

// 固定少数とfloatの変換
#define FLOATtoFP(x) ((int)(x * (float)FIXED_POINT))
#define FPtoFLOAT(x) (((float)x) / (float)FIXED_POINT))
#define FPtoINT(x) (x >> 12)

#define RELEASE_SAFE(x) {if(x){free(x); x = NULL;}};

#include "math.h"
#include "rand.h"
