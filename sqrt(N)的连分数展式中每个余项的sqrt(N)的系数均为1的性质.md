sqrt(N)的连分数展式中每个余项的sqrt(N)的系数均为1的性质
    2014年5月18日

证明，对于sqrt(N)的连分数展式的每一个余项都可以表示为(sqrt(N) -Bx)/Cx，其中Bx和Cx为整数，C!=0，即证明N-B(x-1)*B(x-1)可被C(x-1)整除。
这个问题的证明可以保证对于sqrt(N)的连分数运算可以安全的将每个余项都化为(sqrt(N) - Bx) / Cx的形式。
用于http://projecteuler.net/problem=64。

![alt text](https://goo.gl/0ri1Gh)

其中第三步

![alt text](https://goo.gl/myBOSn)

另附带projecteuler 64题的代码

```

//#define DEBUG
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
const int MAX = 10000;

// present (sqrt(a) - b) / c;
struct triple
{
public:
    triple(int a, int b, int c)
    {
        _sqrt_a = sqrt((double)a);
        _a = a;
        _b = b;
        _c = c;
    }

    triple(const triple& a, int b, int c)
    {
        _sqrt_a = a.sqrt_a();
        _a = a.a();
        _b = b;
        _c = c;
    }

    const int a() const { return _a; }
    const int b() const { return _b; }
    const int c() const { return _c; }
    const int sqrt_a() const { return _sqrt_a; }

private:
    int _a;
    int _b;
    int _c;
    int _sqrt_a;
};

triple next(const triple& c, int& v)
{
    int nc = (c.a() - c.b() * c.b()) / c.c();
    v = (c.sqrt_a() + c.b()) / nc;    // 证明用于此处
    int nb = nc * v - c.b();
    return triple(c, nb, nc);
}

int main()
{
    int count = 0;
    for(int i = 0; i <= MAX; i++)
    {
        if(sqrt((double)i) * sqrt((double)i) != i)
        {
            vector<int> r;
            r.push_back(sqrt((double)i));
            triple c = triple(i, r.front(), 1);
            while(1)
            {
                int v;
                c = next(c, v);
                r.push_back(v);
                if(r.back() == (r.front() << 1)) break;
            }
#ifdef DEBUG
            cout << "sqrt(" << i << ") == [" << r[0] << ";(";
            for(int j = 1; j < r.size(); j++)
            {
                cout << r[j];
                if(j < r.size() - 1) cout << ',';
                else cout << ')';
            }
            cout << ']' << endl;
#endif
            if((r.size() & 1) == 0) count++;
        }
    }
    cout << count << endl;
    return 0;
}

```
