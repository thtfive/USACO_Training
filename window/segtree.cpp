#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define maxn 10000
#define lson l,m,rt << 1
#define rson m + 1,r,rt << 1 | 1
#define eps 1e-15
using namespace std;
struct seg{
    double l,r,y;
    int sign;
    seg(){}
    seg(double a, double b, double h, int s): l(a), r(b),y(h),sign(s) {}
    bool operator < (const seg &cmp) const {
        if(cmp.y == y) return sign > cmp.sign;
        return y < cmp.y;
    }
}p[ (maxn << 1 )+ 1];

//��¼���ǳ�Ԫ�߶εĳ��ȣ�����û�о�����ɢǰ��С�߶Σ�����Ӧ�ö����double
double sum[ (maxn << 2 )+ 7];
int cnt[ (maxn << 2) + 7];
//Ҳ��double
double X[ (maxn << 1) + 9];

void push_up(int rt,int l, int r){
    if(cnt[rt]) sum[rt] = X[r + 1] - X[l];
//ִ�е������ʾ�����߶�û�б����ǵ����ѱ�ɾ����������ǵײ㣬��Ϊ0
    else if(l == r) sum[rt] = 0.0;
//��������߶Σ�Ӧ��Ϊ���߶εı����ǵĺ�/*important*/
    else    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void update(int L, int R, int cc, int l , int r, int rt){
    if(L <= l && r <= R){
        cnt[rt] += cc;
        push_up(rt,l,r);//?
        return ;
    }
    int m = (l + r) >> 1;
    if(L <= m) update(L,R,cc,l,m,rt*2);
    if(R > m)   update(L,R,cc,m+1,r,rt*2+1);
    push_up(rt,l,r);
}
int bin(int low, int high, double key){
    int mid ;
    while(low < high){
        mid = (low + high) >> 1;
        if(X[mid] < key ) low = mid + 1;
//��ע�͵��Ĵ��ˣ�why��
//        if(X[mid] - key < eps) low = mid + 1;
        else high = mid;
    }
    return low;
}
int main2(){
    int n,m,k,pp,ca = 1;
    double a,b,c,d,ret;
    while(scanf("%d",&n) != EOF && n){
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
        m = k = 0;     ret = 0.0;   pp = 1;

        for(int i = 0; i < n; i ++){
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
            X[m ++] = a;
            X[m ++] = c;
        //1��ʾ�±ߣ�����
            p[k ++] = seg(a,c,b,1);
        //-1��ʾ�ϱߣ�ɾ��
            p[k ++] = seg(a,c,d,-1);
        }
        sort(X,X+m);
        sort(p,p+k);
    //��������ɢ��
        for(int i = 1; i < m; i ++)
            if(X[i-1] != X[i]) {
                X[pp ++] = X[i];
            }
    //ɨ����ŵ��߶�
        pp --;
        for(int i = 0; i < k - 1; i ++){
            int l = bin(0, pp , p[i].l);
            int r = bin(0, pp , p[i].r) - 1;
//            cout << l << "      " << r << endl;
            if(l <= r) update(l,r,p[i].sign,0,pp,1);
            ret += (p[i + 1].y - p[i].y) * sum[1];
    //        for(int j = 1; j <= 8; j ++)
    //            cout << sum[j] << "@@@" << endl;    cout << endl;
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",ca++,ret);
    }
    return 0;
}
