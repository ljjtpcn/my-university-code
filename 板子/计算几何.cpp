



```c++
#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);//π的较精确值
const double eps = 1e-8; // 
const int maxn=2e5+10;

int sgn(double x) // 浮点数的比较）
{
    if (fabs(x) < eps)return 0;
    else return x < 0 ? -1 : 1;
}
int cmp(double x, double y)  // 比较函数
{
    if (fabs(x - y) < eps) return 0;
    if (x < y) return -1;
    return 1;
}
struct Point //存二维坐标点
{
    double x, y;
    Point() {}
    Point(double x, double y) :x(x), y(y) {}
    Point operator + (Point B) { return Point(x + B.x, y + B.y); }
    Point operator - (Point B) { return Point(x - B.x, y - B.y); }
    Point operator * (double k) { return Point(x * k, y * k); }
    Point operator / (double k) { return Point(x / k, y / k); }
    bool operator == (Point B) { return sgn(x - B.x) == 0 && sgn(y - B.y) == 0; }
    bool operator<(Point B)
    {
        return sgn(x - B.x) < 0 || (sgn(x - B.x) == 0 && sgn(y - B.y) < 0);
    }
};
struct Line {
    Point p1, p2;
    Line() {}
    Line(Point p1, Point p2) :p1(p1), p2(p2) {}
};
double Cross(Point A, Point B)//叉积
{
    return A.x * B.y - A.y * B.x;
}
double xmult(Point p1, Point p2, Point p3)//叉乘(xmult(b, v.p1, v.p2) * xmult(c, v.p1, v.p2) > eps）两点在直线同一边
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}
double Area(Point A, Point B, Point C)//三角形面积*2
{
    return Cross(B - A, C - A);
}
double Dot(Point A, Point B)//点乘
{
    return A.x * B.x + A.y * B.y;
}
double dis(Point A, Point B)//两点间的距离
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
double Dis_point_line(Point p, Line v)//点到直线的距离
{
    return fabs(Cross(p - v.p1, v.p2 - v.p1)) / dis(v.p1, v.p2);
}
double Dis_point_seg(Point p, Line v)//点到线段的距离
{
    if (sgn(Dot(p - v.p1, v.p2 - v.p1)) < 0 || sgn(Dot(p - v.p2, v.p1 - v.p2)) < 0)
        return min(dis(p, v.p1), dis(p, v.p2));
    return Dis_point_line(p, v);
}
double angle(Point O, Point A, Point B) //两向量OA,OB的夹角
{
    return acos(Dot(A - O, B - O) / (dis(O, A) * dis(O, B)));
}
int Point_line_relation(Point p, Line v)//点和直线的位置关系
{
    int c = sgn(Cross(p - v.p1, v.p2 - v.p1));
    if (c < 0)return 1;//p在v的左边
    if (c > 0)return 2;//p在v的右边
    return 0;//p在v上
}
int Line_relation(Line v1, Line v2)//两条直线的位置关系
{
    if (sgn(Cross(v1.p2 - v1.p1, v2.p2 - v2.p1)) == 0)
    {
        if (Point_line_relation(v1.p1, v2) == 0)return 1;//重合
        else return 0;//平行
    }
    return 2;//相交
}
Point Cross_point(Point a, Point b, Point c, Point d)//直线交点
{
    double s1 = Cross(b - a, c - a);
    double s2 = Cross(b - a, d - a);
    return Point(c.x * s2 - d.x * s1, c.y * s2 - d.y * s1) / (s2 - s1);
}
bool segment_intersection(Point a1, Point a2, Point b1, Point b2)//两线段是否相交
{
    double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1);
    double c3 = Cross(b2 - b1, a2 - b1), c4 = Cross(b2 - b1, a1 - b1);
    return sgn(c1) * sgn(c2) <= 0 && sgn(c3) * sgn(c4) <= 0;
}

bool Point_on_seg(Point p, Line v)//点和线段的位置关系，0为不在线段上
{
    return sgn(Cross(p - v.p1, v.p2 - v.p1)) == 0 && sgn(Dot(p - v.p1, p - v.p2)) <= 0;
}
int main()
{
	return 0;
} 	
```



