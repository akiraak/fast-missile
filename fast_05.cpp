#include "fast.h"

/*
  sinf() conf() の改善
*/

// 弾道ベクトルを生成
void spark_vector(int &dst_x, int &dst_y) {
  int theta = myrand::rand() % math::BUFFER_SIZE;
  int speed = FLOATtoFP(50 + (myrand::rand() % 50));
  dst_x = math::cosfp(theta) * speed;
  dst_y = math::sinfp(theta) * speed;
}

int main() {
    myrand::init();
    math::init();
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
    math::release();

    return 0;
}