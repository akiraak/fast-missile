#pragma once

#define ANGtoRAD(x) (x * 57.295779f) // 角度 = ラジアン x 180 / 円周率
#define RADtoANG(x) (x * 0.017453f) // ラジアン = 角度 x 円周率 / 180
#define SCALE(x, x_max, scale_max) (scale_max * x / x_max)

namespace math {
  static const int BUFFER_SIZE = 4096;
  static int *sin_table = NULL;
  static int *cos_table = NULL;

  void release(){
    RELEASE_SAFE(sin_table);
    RELEASE_SAFE(cos_table);
  }

  void init(){
    release();

    sin_table = (int*)malloc(sizeof(int) * BUFFER_SIZE);
    cos_table = (int*)malloc(sizeof(int) * BUFFER_SIZE);
    for(int i = 0 ; i < BUFFER_SIZE; i++){
      float rad = ANGtoRAD(360.0f / (float)BUFFER_SIZE);
      sin_table[i] = FLOATtoFP(sinf(rad));
      cos_table[i] = FLOATtoFP(cosf(rad));
    }
  }

  int cosfp(int fp_rad) {
    return cos_table[fp_rad];
  }

  int sinfp(int fp_rad) {
    return sin_table[fp_rad];
  }

  int scale(int x, int x_max) {
    return SCALE(x, x_max, BUFFER_SIZE);
  }
}
