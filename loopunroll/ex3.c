/* ############################################################################ 
 
   Copyright 2017 
   Author: Shahzeb Siddiqui

   https://github.com/shahzebsiddiqui/PerformanceTuning
 
    This file is part of PerformanceTuning. 
 
    PerformanceTuning is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or 
    (at your option) any later version. 
 
    PerformanceTuning if distributed in the hope that it will be useful, 
    but WITHOUT ANY WARRANTY; without even the implied warranty of 
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
    GNU General Public License for more details. 
 
    You should have received a copy of the GNU General Public License 
    along with buildtest.  If not, see <http://www.gnu.org/licenses/>. 
############################################################################# 
*/

#include "stdio.h"
#include "math.h"
#include "time.h"
#include <sys/time.h>

int main()
{
  static int N = 50000;
  float A[N];
  float B[N];
  float C[N];

  struct timeval start, end;
  double time_elapsed_seconds;

  gettimeofday(&start, NULL);
  for (int i = 0; i < N; i++)
  {
    A[i] = pow(-1.0,i) * i/N;
    B[i] = pow(-1.0,i+1) * i/N;
    C[i] = 0.f;
  }
  gettimeofday(&end, NULL);

  time_elapsed_seconds = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec*1000000 + start.tv_usec))/1000000.0;
  printf("Initialization Time: %f\n", time_elapsed_seconds);
 
  gettimeofday(&start,NULL);
  for (int i = 0; i < N; i+=4)
  {
    C[i] = A[i] * B[i];
    C[i+1] = A[i+1] * B[i+1];
    C[i+2] = A[i+2] * B[i+2];
    C[i+3] = A[i+3] * B[i+3];
    C[i+4] = A[i+4] * B[i+4];
    C[i+5] = A[i+5] * B[i+5];
    C[i+6] = A[i+6] * B[i+6];
    C[i+7] = A[i+7] * B[i+7];
  } 
  gettimeofday(&end, NULL);
  time_elapsed_seconds = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec*1000000 + start.tv_usec))/1000000.0;
  printf("C = A * B Unroll 8x Time: %f\n", time_elapsed_seconds);
  return 0;
}
