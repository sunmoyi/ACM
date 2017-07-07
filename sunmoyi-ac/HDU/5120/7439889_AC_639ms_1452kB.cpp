#include<stdio.h>
#include<cmath>
const double PI = acos(-1.0);
using namespace std;
double Inters(double x1 , double y1 , double r1 , double x2 , double y2 , double r2)
{
    double ans = 0;
    double sector1 , sector2;
    double  dis = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

            if(r1 + r2 <= dis || r1 == 0 || r2 == 0)
                   double ans = 0.0;

            else if(fabs(r1-r2) >= dis)
                   ans = ( r1 < r2 ? PI*r1*r1 : r2*r2*PI);
            else
              {
                  double a1 = acos((r1*r1 + dis*dis - r2*r2)/(2*r1*dis));
                  double a2 = acos((r2*r2 + dis*dis - r1*r1)/(2*r2*dis));
                  sector1 = a1*r1*r1;
                  sector2 = a2*r2*r2;
                  double tri1 = r1*r1*sin(a1)*cos(a1);
                  double tri2 = r2*r2*sin(a2)*cos(a2);

                  ans = sector1 + sector2 - tri1 -  tri2;
              }

              return ans;

}
int main()
{
       double x1,y1,r1;
       double x2,y2,r2;
       double x3,y3,r3;
       double x4,y4,r4;
       double r , R;
       double x , y;


       int t;
       scanf("%d", &t);
       int tt = 1;
       while(t--)
        {
          scanf("%lf%lf",&r , &R);
             r1 = r;
             r2 = R;
             r3 = r;
             r4 = R;
            scanf("%lf%lf" , &x , &y);
               x1 = x;x2 = x;
               y1 = y;y2 = y;
            scanf("%lf%lf" , &x , &y);
               x3 = x;x4 = x;
               y3 = y;y4 = y;

            double s1 = Inters(x2 , y2 , r2 , x4 , y4 , r4);//大大
            double s2 = Inters(x2 , y2 , r2 , x3 , y3 , r3);//大小
            double s3 = Inters(x1 , y1 , r1 , x4 , y4 , r4);//大小
            double s4 = Inters(x1 , y1 , r1 , x3 , y3 , r3);//小小

            double s = s1 - s2 - s3 + s4;
            printf("Case #%d: %.6lf\n" ,tt++ , s);

        }
}
