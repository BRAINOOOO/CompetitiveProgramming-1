/*
my approach is the same as here
http://codeforces.com/blog/entry/4769

complexity : O( n*q*t )
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define    vi       vector<int>
#define    vd       vector<double>
#define    vvi      vector< vector<int> >
#define    vvll      vector< vector<long long> >
#define    vvpi     vector< vector< pair<int,int> > >
#define    vvpll     vector< vector< pair<long long,long long> > >
#define    vvd      vector< vector<double> >
#define    vs       vector<string>
#define    vvs      vector< vector<string> >
#define     vpi        vector< pair<int ,int> >
#define      pi        pair<int ,int>
#define      pll       pair<long long ,long long>
#define     vpd        vector< pair<double ,double> >
#define     vpll        vector< pair<long long ,long long> >
#define    vll       vector<long long>
#define    dqi        deque< int >
#define     si         set<int>
#define     spi        set< pair<int ,int > >
#define     row          vector< ll >
#define     matrix            vector< row >
#define     si         set<int>
#define    oo         900000000000000000
#define   angle(n)      atan2((n.imag()),(n.real()))
#define   vec(a,b)       ((b)-(a))
#define   length(a)      hypot( (a.imag()),(a.real()) )
#define   normalize(a)      (a)/(length(a))
#define    dp(a,b)          (((conj(a))*(b)).real())
#define    cp(a,b)          (((conj(a))*(b)).imag())
#define    lengthsqrt(a)       dp(a,a)
#define    rotate0( a,ang)    ((a)*exp( point(0,ang) ))
#define    rotateA(about,p,ang)   (rotate0(vec(about,p),ang)+about)
#define    lcm(a,b)                ((a*b)/(__gcd(a,b)))
#define    reflection0(m,v)         (conj((v)/(m))*(m))
#define     reflectionA(m,v,p0)     (conj( (vec(p0,v))/(vec(p0,m)) ) * (vec(p0,m)) ) + p0
#define     same(p1,p2)               ( dp(  vec(p1,p2),vec(p1,p2)) < eps )
#define     point                    complex<double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
vector < pair< string , vs > > v1,v2;
int ans[1000+9];
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    for(int l=0;l<n;l++)
    {
        string line;
        getline(cin,line);
      int id= line.find("void");
       int idx= id+4;
        string fun="",typ="";
         int fr=0;
         vs v;
        for(int i=idx;i<sz(line);i++)
        {
            if(line[i]==' ')
              continue;
            if(line[i]=='(')
            {
                fr=1;
                continue;
            }
            if(!fr)
            {
                fun+=line[i];
            }
            if(line[i]==',')
            {
                v.pb(typ);
                typ="";
                continue;
            }
            if(line[i]==')')
            {
                v.pb(typ);
                typ="";
                break;
            }
            if(fr)
            {
                typ+=line[i];
            }
        }
        v1.pb(mp(fun,v));
    }
    int m;
    cin>>m;
    map< string , string > mb;
    string t,s;
    for(int i=0;i<m;i++)
    {
        cin>>t>>s;
        mb[s]=t;
    }
    int q;
    cin>>q;
    cin.ignore();
    for(int l=0;l<q;l++)
    {
        string line;
        getline(cin,line);
        string fun="",typ="";
         int fr=0;
         vs v;
        for(int i=0;i<sz(line);i++)
        {
            if(line[i]==' ')
              continue;
            if(line[i]=='(')
            {
                fr=1;
                continue;
            }
            if(!fr)
            {
                fun+=line[i];
            }
            if(line[i]==',')
            {
                v.pb(typ);
                typ="";
                continue;
            }
            if(line[i]==')')
            {
                v.pb(typ);
                typ="";
                break;
            }
            if(fr)
            {
                typ+=line[i];
            }
        }
        v2.pb(mp(fun,v));
    }
    for(int i=0;i<q;i++)
    {
       string rf=v2[i].first;
        for(int j=0;j<n;j++)
        {
           string f=v1[j].first;
            if(f==rf&&sz(v1[j].second)==sz(v2[i].second))
            {
                bool ok=1;
                for(int k=0;k<sz(v1[j].second);k++)
                {
                   if(!( v1[j].second[k]==mb[v2[i].second[k]] || v1[j].second[k]=="T" ))
                   {
                       ok=0;
                       break;
                   }
                }
                if(ok)
                {
                    ans[i]+=1;
                }
            }
        }
    }
    for(int i=0;i<q;i++)
        cout<<ans[i]<<endl;
}
