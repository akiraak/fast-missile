#include "fast.h"

/*
  double から float へ
*/

// 弾道ベクトルを生成
void spark_vector(float &dst_x, float &dst_y) {
  float radian = ANGtoRAD(rand() % 360);
  int speed = 50 + (rand() % 50);
  dst_x = cosf(radian) * (float)speed;
  dst_y = sinf(radian) * (float)speed;
}

int main() {
    BEGIN_TIME

    #define LOOP (100000000) // 1億

    for(int i = 0; i < LOOP; i++){
      float dst_x = 0;
      float dst_y = 0;
      spark_vector(dst_x, dst_y);

      // 処理が削除されないように最適化を無効にする
      volatile float temp = dst_x + dst_y;
    }

    END_TIME

  return 0;
}