#include "fast.h"

/*
  マクロ化
*/

#define MATH_COSFP(x) (math::cos_table[x])
#define MATH_SINFP(x) (math::sin_table[x])
#define RAND (myrand::rand_table[myrand::now_index++])
#define RAND_NEXT \
          if(myrand::now_index >= myrand::BUFFER_SIZE){\
            myrand::now_index = 0;\
          }

// 弾道ベクトルを生成
#define spark_vector(i, x, y)\
  int theta = RAND % math::BUFFER_SIZE;\
  RAND_NEXT\
  int speed = FLOATtoFP(50 + (RAND % 50));\
  RAND_NEXT\
  dst_x = MATH_COSFP(theta) * speed;\
  dst_y = MATH_SINFP(theta) * speed;

int main() {
    myrand::init();
    math::init();
    BEGIN_TIME

    #define LOOP (100000000) // 1億

    for(int i = 0; i < LOOP; i++){
      int dst_x = 0;
      int dst_y = 0;
      spark_vector(i, dst_x, dst_y);

      // 処理が削除されないように最適化を無効にする
      volatile int temp = dst_x + dst_y;
    }

    END_TIME

    myrand::release();
    math::release();

    return 0;
}