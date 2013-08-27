#pragma once

namespace myrand {
  static const int BUFFER_SIZE = 4096;
  //static const int BUFFER_SIZE = 65535;
  static int *rand_table = NULL;
  static int now_index = 0;
  //static unsigned short now_index = 0;

  void release(){
    RELEASE_SAFE(rand_table);
  }

  void init(){
    release();

    rand_table = (int*)malloc(sizeof(int) * BUFFER_SIZE);
    for(int i = 0 ; i < BUFFER_SIZE; i++){
      rand_table[i] = rand();
    }
  }

  int rand(){
    now_index++;
    /*
    if(now_index > BUFFER_SIZE - 1){
      now_index = 0;
    }
    */
    return rand_table[now_index];
  }
}
