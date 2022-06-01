# 基础模板

## 手写快排
```c++
// 0 ~ (n - 1)
function<void(int, int)> quick_sort = [&](int l, int r){
        if(l >= r) return;
        
        int i = l - 1, j = r + 1, mid = arr[l + r >> 1];
        while(i < j){
            do i++; while(arr[i] < mid);
            do j--; while(arr[j] > mid);
            if(i < j) swap(arr[i], arr[j]);
        }
        
        quick_sort(l, j); quick_sort(j + 1, r);
    };
    
    quick_sort(0, n - 1);
```

## 归并排序
```c++
void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int mid = l + r >> 1;

    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];// cnt += mid - i + 1;
    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}
```


## 区间合并

```c++
void merge(vector<pii> &segs)
{
    if(segs.size() <= 1) return; //只有一个区间或者为0，直接返回
    
    vector<pii> res; //定义答案：合并之后结果
    sort(segs.begin(), segs.end()); //所有区间排序
    
    auto [st, ed] = segs[0]; //定义初始区间
    for(int i = 1; i < segs.size(); i++){ //从前往后扫描所有线段
        if(ed < segs[i].first){ //当前区间右端点严格小于枚举区间左边
            res.push_back({st, ed});
            st = segs[i].first, ed = segs[i].second;
        }else // 当前区间和维护区间有交集，则求并集
            ed = max(ed, segs[i].second); 
    }
    res.push_back({st, ed}); //加入最后一个区间
    
    segs = res; //区间更新
```

## 二分

```c++
bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

/*      浮点数二分算法模板    */
bool check(double x) {/* ... */} // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
```

## 高精度乘法(高*高)

```c++
// A, B 个位开始
vector<int> mul(vector<int> &A, vector<int> &B) {
    vector<int> C(A.size() + B.size(), 0); // 初始化为 0，且999*99最多 5 位

    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j++)
            C[i + j] += A[i] * B[j];

    int t = 0;
    for (int i = 0; i < C.size(); i++) { // i = C.size() - 1时 t 一定小于 10
        t += C[i];
        C[i] = t % 10;
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back(); // 必须要去前导 0，因为最高位很可能是 0
    reverse(C.begin(), C.end());
    return C;
}
```

## 高精度加法

```c++
// C = A + B, A >= 0, B >= 0
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size()) return add(B, A);

    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++ )
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(t);
    return C;
}
```

## 高精度减法

```c++
// C = A - B, 满足A >= B, A >= 0, B >= 0
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i ++ )
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
```

## 高精度除法

```c++
// A / b = C ... r, A >= 0, b > 0
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
```



## 线性筛

```c++
//以下为欧拉筛,复杂度O(n)
bool isPrime[100000010];
//isPrime[i] == 1表示：i是素数
int Prime[6000010], cnt = 0;
//Prime存质数

void getPrime(int n){//筛到n
	memset(isPrime, 1, sizeof(isPrime));
	//以“每个数都是素数”为初始状态，逐个删去
	isPrime[1] = 0;//1不是素数
	
	for(int i = 2; i <= n; i++){
		if(isPrime[i])//没筛掉 
			Prime[++cnt] = i; //i成为下一个素数
			
		for(int j = 1; j <= cnt && i*Prime[j] <= n/*不超上限*/; j++) {
        	//从Prime[1]，即最小质数2开始，逐个枚举已知的质数，并期望Prime[j]是(i*Prime[j])的最小质因数
            //当然，i肯定比Prime[j]大，因为Prime[j]是在i之前得出的
			isPrime[i*Prime[j]] = 0;
            
			if(i % Prime[j] == 0)//i中也含有Prime[j]这个因子
				break; //重要步骤。见原理
		}
	}
}
```

# 计算几何

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
/**
基础操作
*/
double Dot(Point A, Point B)//点乘(内积， 点积)
{
    return A.x * B.x + A.y * B.y;
}
double Cross(Point A, Point B)//叉积（外积， 叉积）（有向面积， A逆时针至B为正面积，否则为负面积）
{
    return A.x * B.y - A.y * B.x;
}
double rotate(Point A, double angle) // 向量A顺时针旋转C角度
{
    return Point(A.x * cos(angle) + A.y * sin(angle), -A.x * sin(angle) + A.y * cos(angle));
}


double xmult(Point p1, Point p2, Point p3)//叉乘(xmult(b, v.p1, v.p2) * xmult(c, v.p1, v.p2) > eps）两点在直线同一边
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}
double Area(Point A, Point B, Point C)//三角形面积*2
{
    return Cross(B - A, C - A);
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
    //叉积（面积）判断
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

## 三角形

### 面积
1. 叉积
2. 海伦公式

    $p = (a + b + c) / 2$

    $s = sqrt(p * (p - a) *(p - b) * (p - c))$

### 三角形四心
1. 外心， 外接圆圆心

    三边中垂线交点。到三角形三个顶点的距离相等

2. 内心， 内切圆圆心

    角平分线交点，到三边距离相等

3. 垂心

    三条垂线交点

4. 重心

    三条中线交点（到三角形三顶点距离的平方和最小的点， 三角形内到三边距离之积最大的点）

## 普通多边形

:::info
通常按逆时针存储所有点
:::

### 定义
1. 多边形

    由在同一平面且不在同一直线上的多条线段首尾连接且不相交所组成的多边形

2. 简单多边形

    指除相邻边外其它边不相交的多边形

3. 凸多边形
    
    过多边形的任意一边做一条直线， 如果其他各个顶点都在这条直线的同侧，则把这个多边形叫做凸多边形。

    任意凸多边形外角和均为$360°$

    任意凸多边形内角和为$(n - 2) * 180°$

### 常用函数

1. 求多边形面积（不一定是凸多边形）

    我们可以任选一个顶点（一般选第一个顶点 ）出发，吧凸多边形分成`n - 2`个三角形，然后把面积加起来

```c++
    double polygon_area(Point p[], int n)
    {
        double s = 0;
        for(int i = 1; i + 1 < n; i ++)
            s += cross(p[i] - p[0], p[i + 1] - p[i]);
        return s / 2;
    }
``` 