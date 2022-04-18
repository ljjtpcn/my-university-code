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

