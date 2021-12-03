#include <stdio.h>
#include <stdlib.h>
#include "function.h"


int main(void)
{
   Point *point_array;
   int i, length, N;
   float ans;

   scanf("%d", &length);
   // give point_array memory and get first element address
   point_array = ones_vec_1(length);

   scanf("%d", &N);
   for (i = 0; i < N; i++){
      int first, second;
      scanf("%d %d", &first, &second);
      // compute distance of two points
      ans = compute_distance(point_array, first, second);
      printf("%.3f\n", ans);
   }

   return 0;
}
//partial judge

//#include <stdio.h>
//#include <stdlib.h>
//#include "function.h"
#include <math.h>

Point * ones_vec_1(int length)
{
   /// Please implement
   /// 1. Malloc memory for point array
   Point *a = (Point*)malloc(sizeof(Point)*length);
   /// 2. Read values into point array
   for(int i=0;i<length;i++) scanf("%d %d",&a[i].x,&a[i].y);
   /// 3. Return the address of the first element in the array
   return a;
}

float compute_distance(Point* a, int first_id, int second_id)
{
    float ans;
    Point first_p, second_p;

    /// Please implement
    /// 1. Get two point from function argument
    first_p = a[first_id];
    second_p = a[second_id];
    /// 2. Compute 2D distance and return ans
    ans = sqrt((double)( (first_p.x-second_p.x)*(first_p.x-second_p.x) +
            (first_p.y-second_p.y)*(first_p.y-second_p.y) ));

    return ans;
}
//
