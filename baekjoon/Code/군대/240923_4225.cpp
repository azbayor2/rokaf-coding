#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define f first
#define s second

using namespace std;

typedef pair<int, int> p;
vector<p> v;
vector<p> temp;
int n;

int ccw(p a, p b, p c)
{
    int ret = a.f*b.s + b.f*c.s + c.f*a.s -
            a.s*b.f - b.s*c.f - c.s*a.f;

    if(ret>0)
        return 1;
    else if(ret<0)
        return -1;

    return 0;
}

int get_dist(p a, p b)
{
    int ret = (a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s);
    return ret;
}

bool sort_small(p a, p b)
{
    if(a.s<b.s)
        return true;
    else if(a.s>b.s)
        return false;
    else if(a.f<b.f)
        return true;

    return false;
}

bool sort_clock(p a, p b)
{
    int ret = ccw(v[0], a, b);
    if(ret>0)
        return true;
    else if(ret<0)
        return false;
    int dist_a = get_dist(v[0], a);
    int dist_b = get_dist(v[0], b);

    if(dist_a < dist_b)
        return true;
    return false;

}

void solve()
{
    sort(v.begin(), v.end(), sort_small);
    sort(v.begin()+1, v.end(), sort_clock);

    for(p pp: v)
    {
        while(1)
        {
            int idx = temp.size()-1;
            if(temp.size()<=1)
            {
                temp.push_back(pp);
                break;
            }

            int ret = ccw(temp[idx-1], temp[idx], pp);
            if(ret>0)
            {
                temp.push_back(pp);
                break;
            }            
            temp.pop_back();
        }
    }

    int mod = temp.size();
    double ans = 0;
    for(int i =0; i<mod; i++)
    {
        double temp_ans = 10000000;
        double a = (double)temp[i].s - temp[(i+1)%mod].s;
        double b = (double)temp[i].f - temp[(i+1)%mod].f;
        double c = (double)b*temp[i].s - a*temp[i].f;
        double down = (double)a*a + b*b;
        down = (double)sqrt(down);
        for(int j =0; j<mod; j++)
        {
            if(j==i || j==(i+1)%mod)
                continue;
            double up = (double)a*temp[j].f - b*temp[j].s + c;
            if(up<0)
                up = (double)-up;
            double temp = (double)up/down;
            temp_ans = (double)max(temp_ans, temp);
        }

        ans = (double)min(ans, temp_ans);

    } 

    double ans_out = (double)ans*1000;
    double ans_out1 = ans_out%10;
    ans_out = (double)ans%100;
    if(ans_out1>0)
    {
        ans_out+=1;
    }
    ans_out%=100;

    cout << "Case "

    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b;
    while(1)
    {
        cin >> n;
        if(n==0)
            break;
            
        for(int i =0; i<n ;i++)
        {
            cin >> a >> b;
            v.push_back(p(a,b));
        }

        solve();
        v.clear();
        temp.clear();
    }

    return 0;
}