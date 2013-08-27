#include "fast.h"

/*
  最適化なし
*/

// 弾道ベクトルを生成
void spark_vector(double &dst_x, double &dst_y) {
  double radian = ANGtoRAD(rand() % 360);
  double speed = 50 + (rand() % 50);
  dst_x = cos(radian) * speed;
  dst_y = sin(radian) * speed;
}

int main() {
    BEGIN_TIME

    #define LOOP (100000000) // 1億

    for(int i = 0; i < LOOP; i++){
      double dst_x = 0;
      double dst_y = 0;
      spark_vector(dst_x, dst_y);

      // 処理が削除されないように最適化を無効にする
      volatile double temp = dst_x + dst_y;
    }

    END_TIME

  return 0;
}