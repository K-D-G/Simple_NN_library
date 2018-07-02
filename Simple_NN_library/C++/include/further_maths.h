#ifndef __FURTHER_MATHS_H
#define __FURTHER_MATHS_H
#include <cmath>

namespace further_maths{
  float epsilon(){
    return 1e-7;
  }

  float sum(float* array){
    float total=0;
    for(int i=0; i<sizeof(array); i++){
      total+=array[i];
    }
    return total;
  }

  float* add_constant(float* arr, float constant){
    float result[sizeof(arr)];
    for(int i=0; i<sizeof(arr); i++){
      result[i]=arr[i]+constant;
    }
    return result;
  }

  float* subtract_arrays(float* arr, float arr2[]){
    float result[sizeof(arr)];
    for(int i=0; i<sizeof(arr); i++){
      result[i]=arr[i]-arr2[i];
    }
    return result;
  }

  float* subtract_constant(float* arr, float constant){
    float result[sizeof(arr)];
    for(int i=0; i<sizeof(arr); i++){
      result[i]=arr[i]-constant;
    }
    return result;
  }

  float* square_array(float* arr){
    float result[sizeof(arr)];
    for(int i=0; i<sizeof(arr); i++){
      result[i]=arr[i]*arr[i];
    }
    return result;
  }

  float* array_abs(float* arr){
    float result[sizeof(arr)];
    for(int i=0; i<sizeof(arr); i++){
      result[i]=std::abs(arr[i]);
    }
    return result;
  }

  float* multiply_arrays(float* arr, float* arr2){
    float result[sizeof(arr)];
    for(int i=0; i<sizeof(arr); i++){
      result[i]=arr[i]*arr2[i];
    }
    return result;
  }

  float mean(float* arr){
    int divide_operand=sizeof(arr);
    float total=0;
    for(int i=0; i<sizeof(arr); i++){
      total+=arr[i];
    }
    return total/divide_operand;
  }

  float* divide_arrays(float* arr, float* arr2){
    float result[sizeof(arr)];
    for(int i=0; i<sizeof(arr); i++){
      result[i]=arr[i]/arr2[i];
    }
    return result;
  }

  float* array_log(float* arr){
    float result[sizeof(arr)];
    for(int i=0; i<sizeof(arr); i++){
      result[i]=std::log10(arr[i]);
    }
    return result;
  }

  float* maximum(float** arr){
    float result[sizeof(arr)];
    for(int i=0; i<sizeof(arr); i++){
      for(int j=0; j<sizeof(arr[i]); j++){
        if(result[j]<arr[i][j]){result[j]=arr[i][j];}
      }
    }
    return result;
  }

  float max(float* arr){
    float result=0;
    for(int i=0; i<sizeof(arr); i++){
      result*=(1-arr[i]);
    }

    return 1-result;
  }

  float* make_array(float number, int size){
    float result[size];
    for(int i=0; i<size; i++){
      result[i]=number;
    }
    return result;
  }

  float ln(float x){
    log(x);
  }


  float** zip(float* x, float* y){
    //float result[sizeof(x)][2];
    float** result;
    for(int i=0; i<sizeof(x); i++){
      result[i][0]=x[i];
      result[i][1]=y[i];
    }
    return result;
  }

  float*** dot_product(float*** batch, float* error){
    //float result[sizeof(batch[0])][2][sizeof(batch[0][0][0])];
    float*** result;
    for(int i=0; i<sizeof(batch); i++){
      for(int j=0; j<sizeof(batch[i]); j++){
        for(int x=0; x<sizeof(batch[i][j]); x++){
          result[i][j][x]=batch[i][j][x]*error[x];
        }
      }
    }
    return result;
  }

  int constrain(int x, int y, int z){
    if(x<y){return y;}
    else if(x>z){return z;}
    return x;
  }
}
#endif
