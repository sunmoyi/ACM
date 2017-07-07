#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 1005
#define sqr(x) ((x) * (x))
int n;
const double eps = 1e-8;
const double pi = acos(-1.0);
int sgn(double x)
{
    return fabs(x) < eps ? 0 : x < -eps ? -1: 1;
}
struct point
{
    double x,y;
    point(){}
    point(double a,double b):x(a),y(b){}
    point operator - (point p){return point(x - p.x,y - p.y);}
    point operator + (point p){return point(x + p.x,y + p.y);}
    double norm(){return sqrt(sqr(x) + sqr(y));}
    double norm2(){return sqr(x) + sqr(y);}
    double operator * (point p){return x * p.x + y * p.y;}
    point operator * (double a){return point(x * a,y * a);}
    double operator ^ (point p){return x * p.y - y * p.x;}
    bool operator == (point p){return sgn(x-p.x)==0&&sgn(y-p.y)==0;}
    bool operator < (const point &p){return sgn(x - p.x) < 0 || (sgn(x - p.x) == 0 && sgn(y - p.y) < 0);}
    point rev(){return point(-x,-y);}
    point ver(){return point(y,-x);}
    point unit(){return point(x / norm(),y / norm());}
    point rotate(double theta)//the rotate function for vector to rotate
    {//in counter-clockwise direction
        return point(x*cos(theta)-y*sin(theta),x*sin(theta)+y*cos(theta));
    }
}p[maxn];
struct line
{
    point p,k;
    line(){}
    //MIND THIS!!!!!
    line(point a,point b):p(a),k(b){}//a is the fixed point,k is the directed vector
    line rotate(double theta){line l;l.p=p;l.k=k.rotate(theta);return l;}
    bool on(point q){return sgn((q-p) ^ k) == 0;}
    //move the line acording to the parpendicular-direction with offset distance
    line move(double offset)//to which direction??
    {//every time we use this,we can try the bi-direction
        point vec = k.ver();
        vec = vec.unit() * offset;
        point q = p + vec;
        return line(q,k);
    }
    //distance from a point to a line
    double dis(point q)
    {
        point a = p,b = a + k;
        return fabs((a - q) ^ (b - q)) / k.norm();
    }
    //cast the point to the line and find the pedal
    /*
       by construct the line through the 'q' parallel to the origin line
       calc the lq.p 's vector to 'q'
       add it onto the origin line's p
     */
    point cast(point q)//something wrong
    {
        double d = line(p,k).dis(q);
        line lq = line(p,k).move(d);
        point vec;
        if(!lq.on(q))
            lq = line(p,k).move(-d);
        vec = q - lq.p;
        return p + vec;
    }
    //calc the symmetrical point of the given one againt the given line
    point sym(point q)
    {
        point c = line(p,k).cast(q);
        point vec = c - q;
        return c + vec;
    }
    //copied from some big cow
    //by vector product and "division point"
    int cross(line q,point &ans)
    {
        point a = p,b = p + k,c = q.p,d = q.p + q.k;
        ans = d;
        double rate = ((b-a)^(a-d)) / ((b-a)^(c-d));
        ans = ans + ((c - d) * rate);
    }
};
struct circle
{
    point o;
    double r;
    circle(){}
    circle(point _o,double _r):o(_o),r(_r){}
    //by two points to calc the minimum circle
    circle(point a,point b)
    {
        o = (a + b) * 0.5;
        r = (a - o).norm();
    }
    //give three points (not on the same line)to calc the decided circle
    circle(point a,point b,point c)
    {
        point m1 = (a + b) * 0.5,m2 = (b + c) * 0.5;
        line l1 = line(m1,(b-a).ver()),l2 = line(m2,(c-b).ver());
        l1.cross(l2,o);
        r = (a-o).norm();
    }
    //judge a point in or on the circle or not
    bool in(point x)
    {
        return sgn((x - o).norm() - r) <= 0;
    }
    //judge a point on the circular of the circle or not
    bool inandon(point x)
    {
        return sgn((x - o).norm() - r) == 0;
    }
    //give a point and a cirlce,calc the two tangent line (just angles)
    //by rotation ::mode 1
    //if the point p is on the circular of the circle
    //just output one tangentline ::mode 2
    void tangentline(point p,double &th1,double &th2,int mode)
    {
        double alpha = atan2(o.y - p.y,o.x - p.x);
        if(mode == 1)
        {
            th1 = alpha + pi * 0.5;
            if(sgn(th1 - pi) >= 0)
                th1 -= pi;
            else if(sgn(th1) < 0)
                th1 += pi;
            th1 = th1 / pi * 180.0;
        }
        else
        {
            //circle center and point p 's connected line 's angle
            double theta = asin(r / (p - o).norm());
            th1 = alpha + theta;
            while(sgn(th1 - pi) >= 0)
                th1 -= pi;
            while(sgn(th1) < 0)
                th1 += pi;
            th2 = alpha - theta;
            while(sgn(th2 - pi) >= 0)
                th2 -= pi;
            while(sgn(th2) < 0)
                th2 += pi;
            th1 = th1 / pi * 180.0;
            th2 = th2 / pi * 180.0;
        }
    }
};
//copied from some big cow
//to calculate the insribed circle of a triangle
circle inscribed(point a,point b,point c)
{
    point a1 = a + (b-a).unit() + (c - a).unit(),b1 = b + (a-b).unit()+(c-b).unit();
    point ans;
    line(a,a1-a).cross(line(b,b1-b),ans);
    double r = line(a,b-a).dis(ans);
    return circle(ans,r);
}
int onelineonepoint(point p,line l,double r,circle &a,circle &b)
{
    double d = l.dis(p);
    if(sgn(d - 2.0 * r) > 0)
        return 0;
    else if(sgn(d - 2.0 * r) == 0)
    {
        point c = l.cast(p);
        a = circle((c + p) * 0.5,r);
        return 1;
    }
    else if(sgn(d - 2.0 * r) < 0 && sgn(d) > 0)
    {
        double det,theta;
        det = d - r;
        theta = acos(det / r);
        point c = l.cast(p);
        point to = c - p;
        to = to.unit() * r;
        point vec1 = to.rotate(theta),vec2 = to.rotate(-theta);
        a = circle(p + vec1,r);
        b = circle(p + vec2,r);
        return 2;
    }
    else if(sgn(d) == 0)//the point is on the line
    {
        point per = l.k.ver();
        per = per.unit() * r;
        a = circle(p + per,r);
        b = circle(p + per.rev(),r);
        return 2;
    }
}
//use two cross lines and one radius to calc four circles
//circle - answer array
circle four[10];
//use the center of circle to compare circles
bool cmpcircle(circle a,circle b)
{
    return a.o < b.o;
}
void twolineoneradius(line a,line b,double r)
{
    line A[2],B[2];
    A[0] = a.move(r),A[1] = a.move(-r);
    B[0] = b.move(r),B[1] = b.move(-r);
    int cnt = 1;
    for(int i = 0;i < 2;i++)
        for(int j = 0;j < 2;j++)
        {
            point temp;
            A[i].cross(B[j],temp);
            four[cnt++] = circle(temp,r);
        }
}
//use two disjoint circle to calc one or two new circles tangent to them with given 'r'
//not in the middle line !!!!
int twocircle(circle a,circle b,double r,circle &c,circle &d)
{
    point dir = (b.o - a.o);
    double dis = dir.norm();
    double len = dis - a.r - b.r;
    double ra = r + a.r,rb = r + b.r;
    if(sgn(len - 2.0 * r) > 0)
        return 0;
    else if(sgn(len - 2.0 * r) == 0)
    {
        point to = dir * (ra / (ra + rb));
        c = circle(a.o + to,r);
        return 1;
    }
    else
    {
        //r1^2 - l1^2 = r2^2 - l2^2
        //l1 + l2 = l
        //wtf
        double tempto = (sqr(ra) - sqr(rb) + sqr(dis)) / (2.0 * dis);
        point to = dir * (tempto / dis);
        point temp = (a.o + to);
        point per = to.ver();
        double rate = sqrt(sqr(ra) - to.norm2())/ per.norm();
        per = per * rate;
        point per2 = per.rev();
        c = circle(temp + per,r);
        d = circle(temp + per2,r);
        return 2;
    }
}
//we judge three points on the same line or not
bool oneline(point a,point b,point c){return sgn((a - b) ^ (a - c)) == 0;}
char opt[1000];
char type[][1000] = {"CircumscribedCircle","InscribedCircle","TangentLineThroughPoint","CircleThroughAPointAndTangentToALineWithRadius","CircleTangentToTwoLinesWithRadius","CircleTangentToTwoDisjointCirclesWithRadius"};
int main()
{
    while(scanf("%s",opt) == 1)
    {
        int mark = -1;
        for(int i = 0;i < 6;i++)
        {
            if(strcmp(opt,type[i]) == 0)
            {
                mark = i;
                break;
            }
        }
        if(mark == 0)
        {
            for(int i = 0;i < 3;i++)
            {
                double x,y;
                scanf("%lf %lf",&x,&y);
                p[i] = point(x,y);
            }
            circle ans = circle(p[0],p[1],p[2]);
            printf("(%.6lf,%.6lf,%.6lf)\n",ans.o.x+1e-10,ans.o.y+1e-10,ans.r+1e-10);
        }
        else if(mark == 1)
        {
            for(int i = 0;i < 3;i++)
            {
                double x,y;
                scanf("%lf %lf",&x,&y);
                p[i] = point(x,y);
            }
            circle ans = inscribed(p[0],p[1],p[2]);
            printf("(%.6lf,%.6lf,%.6lf)\n",ans.o.x+1e-10,ans.o.y+1e-10,ans.r+1e-10);
        }
        else if(mark == 2)
        {
            double x,y,r;
            scanf("%lf %lf %lf",&x,&y,&r);
            circle o = circle(point(x,y),r);
            scanf("%lf %lf",&x,&y);
            double t1,t2;
            point p = point(x,y);
            if(o.in(p))
            {
                if(o.inandon(p))
                {
                    o.tangentline(p,t1,t2,1);
                    printf("[%.6lf]\n",t1+1e-10);
                }
                else
                    puts("[]");
            }
            else
            {
                o.tangentline(p,t1,t2,2);
                if(sgn(t1 - t2) > 0)
                    swap(t1,t2);
                printf("[%.6lf,%.6lf]\n",t1+1e-10,t2+1e-10);
            }
        }
        else if(mark == 3)
        {
            double x,y;
            for(int i = 0;i < 3;i++)
            {
                scanf("%lf %lf",&x,&y);
                p[i] = point(x,y);
            }
            double r;
            scanf("%lf",&r);
            circle a,b;
            int mod = onelineonepoint(p[0],line(p[1],p[2]-p[1]),r,a,b);
            if(mod == 0)
                puts("[]");
            else if(mod == 1)
                printf("[(%.6lf,%.6lf)]\n",a.o.x+1e-10,a.o.y+1e-10);
            else
            {
                if(b.o < a.o)
                    swap(a,b);
                printf("[(%.6lf,%.6lf),(%.6lf,%.6lf)]\n",a.o.x+1e-10,a.o.y+1e-10,b.o.x+1e-10,b.o.y+1e-10);
            }
        }
        else if(mark == 4)
        {
            double x,y,r;
            for(int i = 0;i < 4;i++)
            {
                scanf("%lf %lf",&x,&y);
                p[i] = point(x,y);
            }
            scanf("%lf",&r);
            twolineoneradius(line(p[0],p[1]-p[0]),line(p[2],p[3]-p[2]),r);
            sort(four + 1,four + 5,cmpcircle);
            putchar('[');
            for(int i = 1;i <= 4;i++)
                printf("(%.6lf,%.6lf)%c",four[i].o.x+1e-10,four[i].o.y+1e-10,i == 4?']':',');
            puts("");
        }
        else if(mark == 5)
        {
            double x,y,r;
            scanf("%lf %lf %lf",&x,&y,&r);
            circle a(point(x,y),r);
            scanf("%lf %lf %lf",&x,&y,&r);
            circle b(point(x,y),r);
            scanf("%lf",&r);
            circle c,d;
            int mod = twocircle(a,b,r,c,d);
            if(mod == 0)
                puts("[]");
            else if(mod == 1)
                printf("[(%.6lf,%.6lf)]\n",c.o.x+1e-10,c.o.y+1e-10);
            else
            {
                if(d.o < c.o)
                    swap(c,d);
                printf("[(%.6lf,%.6lf),(%.6lf,%.6lf)]\n",c.o.x+1e-10,c.o.y+1e-10,d.o.x+1e-10,d.o.y+1e-10);
            }
        }
    }
}