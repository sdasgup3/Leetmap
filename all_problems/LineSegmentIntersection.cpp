#include<iostream>
using namespace std;
/*
 * To find the orintation of LS S(x1,y1) E(x2,y2) w.r.t X(x,y)
 * slop of LS {(x1,y1) (x2,y2)} > slop of LS (x1,y1) (x,y) --> right (1)
 * y2-y1 / x2-x1 > y-y1 / x - x1 ==> (y2 -y1)(x-x1) > (y-y1)(x2-x1)
 * slop of LS {(x1,y1) (x2,y2)} < slop of LS (x1,y1) (x,y) --> left (-1)
 * else (0)
 */

const int Right = 0;
const int Left = 1;
const int Same = 2;

typedef struct Point
{
    int x;
    int y;
} P;

const int orien(Point S, Point E, Point X) {
  
  int A = (E.y -S.y)*  (X.x-S.x);
  int B = (X.y-S.y)  *  (E.x-S.x);

  if(A > B) { 
    return Right;
  } else if(A< B) {
    return Left;
  } else {
    return Same;
  }
}



bool doIntersect(Point XS, Point XE, Point YS, Point YE) {
  
  int O_xs_xe_ys =  orien(XS, XE, YS);
  int O_xs_xe_ye =  orien(XS, XE, YE);
  int O_ys_ye_xs =  orien(YS, YE, XS);
  int O_ys_ye_xe =  orien(YS, YE, XE);

  if ( (O_xs_xe_ys != O_xs_xe_ye) && (O_ys_ye_xs != O_ys_ye_xe) ) {
    return true;
  } else if((O_xs_xe_ys == O_xs_xe_ye) && O_xs_xe_ye == 0 ){
    //Colinear
    int X_start, X_end; 
    if(XS.x == XE.x) { // so its a line par to y 
      if(XS.y > XE.y) {
        X_start = XE.y;
        X_end   = XS.y;
      } else {
        X_start = XS.y;
        X_end   = XE.y;
      }
    } else {
      if(XS.x > XE.x) {
        X_start = XE.x;
        X_end   = XS.x;
      } else {
        X_start = XS.x;
        X_end   = XE.x;
      }
    }
  
    int Y_start, Y_end; 
    if(YS.x == YE.x) { // so its a line par to y 
      if(XS.y > YE.y) {
        Y_start = YE.y;
        Y_end   = YS.y;
      } else {
        Y_start = YS.y;
        Y_end   = YE.y;
      }
    } else {
      if(YS.x > YE.x) {
        Y_start = YE.x;
        Y_end   = YS.x;
      } else {
        Y_start = YS.x;
        Y_end   = YE.x;
      }
    }


    if(( X_end < Y_start )  || (Y_end < X_start)) {
      return false;
    } else {
      return true;
    }
  } else {    
    return false;
  }
}
int main()
{
  {
    P p1 = {1, 1}, q1 = {10, 1};
    P p2 = {1, 2}, q2 = {10, 2};
 
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
  }
 
  {
    P p1 = {10, 0}, q1 = {0, 10};
    P p2 = {0, 0}, q2 = {10, 10};
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
  }
 
  {
    P p1 = {-5, -5}, q1 = {0, 0};
    P p2 = {1, 1}, q2 = {10, 10};
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
  }
 
    return 0;
}

