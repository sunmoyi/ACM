  #include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

const double PI = acos(-1.0);
double torad(double deg){return deg/180 * PI;}

struct Point{
    double x , y;
    Point (double x = 0 , double y = 0):x(x) , y(y){}
};

typedef Point Vector;

Vector operator +(const Vector &A , const Vector &B){return Vector(A.x+B.x , A.y + B.y);}
Vector operator -(const Vector &A , const Vector &B){return Vector(A.x-B.x , A.y - B.y);}
double Cross(const Vector&A , const Vector &B){return A.x*B.y - A.y*B.x;}

double Dot(const Vector& A, const Vector& B) {
	return A.x*B.x + A.y*B.y;
}

double Length(const Vector& A) {
	return sqrt(Dot(A, A));
}

double Angle(const Vector& A, const Vector& B) {
	return acos(Dot(A, B) / Length(A) / Length(B));
}

Vector Rotate(const Vector&A , double rad)
{
    return Vector(A.x*cos(rad) - A.y*sin(rad) , A.x*sin(rad) + A.y*cos(rad));
}

bool operator <(const Point& p1 , const Point&p2){
   return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}
bool operator ==(const Point &p1 , const Point &p2){
  return p1.x == p2.x && p1.y == p2.y;
}

vector<Point> ConvexHull(vector<Point> p){
  sort(p.begin() , p.end());
  p.erase(unique(p.begin() , p.end()),p.end());

  int n = p .size();
  int m = 0;
  vector<Point> ch(n+1);
  for(int i =0;i < n;i++){
       while(m > 1 && Cross(ch[m-1] - ch[m-2] , p[i] - ch[m-2]) <= 0) m--;
       ch[m++] = p[i];
  }

  int k = m;
  for(int i = n - 2;i >= 0;i--){
     while(m > k && Cross(ch[m-1]-ch[m-2] , p[i] - ch[m-2]) <= 0) m--;
     ch[m++] = p[i];
  }
   if(n > 1) m--;
   ch.resize(m);
   return ch;
}


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int n;
         double area1 = 0;
         scanf("%d",&n);
         vector<Point> P;
         for(int i = 0;i < n;i++){
            double x , y;
            scanf("%lf%lf",&x , &y);
            Point o(x , y);
            P.push_back(o );//w是不旋转水平长度

         }

         vector<Point> Q = ConvexHull(P);
        if(Q.size() != n) printf("NO\n");
        else
        {
               int flag = 1;
              double ang0 = PI*((double)n-2.0) / (double)n;
             // printf("ang0 = %lf\n" , ang0);
              for(int i = 0;i < Q.size();i++)
              {
                   int len = Q.size();
                    double ax = Q[(i-1 + len)%len].x - Q[i].x;
                    double ay = Q[(i-1 + len)%len].y - Q[i].y;
                    Vector a(ax , ay);
                    //printf("%lf %lf\n" , a.x  , a.y);


                    double bx = Q[(i+1 + len)%len].x - Q[i].x;
                    double by = Q[(i+1 + len)%len].y - Q[i].y;
                   Vector b(bx , by);


                    double ang = Angle(a , b);
                    //printf("ang = %lf" ,ang);
                       if(ang != ang0)  {flag = 0;break;}
              }
              if(flag)  printf("YES\n");
              else      printf("NO\n");
        }
        //for(int i = 0;i < Q.size();i++)
              // printf("%lf %lf\n" , Q[i].x , Q[i].y);
    }
}
