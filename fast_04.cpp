#include "fast.h"

/*
  rand() の改善
*/

// 弾道ベクトルを生成
void spark_vector(int &dst_x, int &dst_y) {
  float radian = ANGtoRAD(myrand::rand() % 360);
  int speed = 50 + (myrand::rand() % 50);
  dst_x = FLOATtoFP(cosf(radian) * (float)speed);
  dst_y = FLOATtoFP(sinf(radian) * (float)speed);
}

int main() {
    myrand::init();
    BEGIN_TIME

    #define LOOP (100000000) // 1億

    for(int i = 0; i < LOOP; i++){
      int dst_x = 0;
      int dst_y = 0;
      spark_vector(dst_x, dst_y);

      // 処理が削除されないように最適化を無効にする
      volatile int temp = dst_x + dst_y;
    }

    END_TIME
    myrand::release();

  return 0;
}