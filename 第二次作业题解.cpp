//A - A + B Problem
/*#include<iostream>
 using namespace std;

 int main(){
    double a, b;
    while(cin >> a >> b){
        cout << a+b << endl;
    }
    return 0;
 }*/

 //B - Sum Problem
 //需要注意的是每次输出时输出两个回车
 /*#include<iostream>
using namespace std;
int n, sum;
int Add(int n){
   int i;
   for(i = 0; i <= n; i++){
    sum += i;
   }
    return sum;
}
 int main(){
    while(cin >> n){
        sum = 0;
        cout << Add(n) << endl << endl;
    }
    return 0;
 } */

//C - Let the Balloon Rise
//
/*#include<iostream>
#include<string>
#include<cstring>
#define maxn 1000+10
using namespace std;
int n;
int ind[maxn];
string str[maxn];

 int main(){
    while(cin >> n && n){
        memset(ind, 0, sizeof(ind));
        cin >> str[0];
        ind[0] = 1;
        for(int i = 1; i < n; i++){
            string temp;
            cin >> temp;
            for(int j = 0; j < i; j++){
                if(temp == str[j]){
                    ind[j]++;
                    break;
                }else if(j == i-1){
                    ind[i]++;
                    str[i] = temp;
                }
            }
        }
        int maxind = 0;
        for(int i = 1; i < n; i++){
            maxind = ind[i] > ind[maxind] ? i : maxind;
        }
        cout << str[maxind] << endl;
    }
    return 0;
 }*/


 //D - Number Sequence
/*#include<iostream>

using namespace std;
int A, B, n;
int arr[3];

int main(){

    while(cin >> A >> B >> n, A || B || n){
        //n %= 49;
        arr[0] = 1, arr[1] = 1;
        for(int i = 2; i < n; i++)
            arr[i % 3] = (A * arr[(i-1) % 3] + B * arr[(i-2) % 3]) % 7;
        cout << arr[(n-1) % 3] << endl;
    }
    return 0;
} */


//E - Elevator
/*#include<iostream>
#include<cmath>
#define maxn 100+10

using namespace std;
int n, sum;
int arr[maxn], ind[maxn];

int main(){
    while(cin >> n && n){
        sum = 5*n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(i) ind[i] = arr[i] - arr[i-1];
            else ind[0] = arr[0];
        }
        for(int i = 0; i < n; i++){
            if(ind[i] > 0) sum += 6 * ind[i];
            else  sum += 4 * fabs(ind[i]);
        }
        cout << sum << endl;
    }
    return 0;
}*/

//F - u Calculate e
/*#include<iostream>
#include<cstdio>

using namespace std;
int n;
double e;

int main(){
	cout << "n" << " " << "e" << endl;
	cout << "-" << " " << "-----------" << endl;
    for(int k = 0; k <= 9; k++){
        e = 1;
        double temp = 1;
        for(int i = 1; i <= k; i++){
        temp *= i;
        e += 1 / temp;
    }
        if(k < 3) printf("%d %g\n", k, e);
        else printf("%d %.9f\n", k, e);
    }
   return 0;
}*/

 //J - find the nth digit
/*#include<iostream>
#include<cmath>
using namespace std;

int n, s;

int Find(){
   //int i;
   //for(i = (sqrt(s) - 1) ; s > ((i + i*i) >> 1); i++);
   //return i;
   int a = 1;
   while(s > a){
			s -= a;
			a++;
		}
}

void solve(){
    //int temp = s - ((i + i*i) >> 1);
    //if(temp == 9 * (temp / 9)) cout << 9  << endl;
    //else cout << temp - 9 * (temp / 9) << endl;
    s %= 9;
    if(s == 0) s = 9;
    cout << s << endl;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        Find();
        solve();
    }
}
*/

 //G - Rightmost Digit
/*#include<iostream>
#include<cstring>

using namespace std;
int n, num, num_r;
int arr[10][50];

void calculet(){
    int i, j;
    memset(arr, 0, sizeof(arr));
    for(i = 2; i < 10; i++){
        arr[i][0] = i;
        if(i != 5)
            for(j = 1; j < 32 ; j++){
                arr[i][j] = (arr[i][j-1] * arr[i][j-1]) % 10;
            }
    }
}

int main(){
    cin >> n;
    calculet();
    while(n--){
        cin >> num;
        num_r = num % 10;
        if(num_r == 0) cout << 0 << endl;
        else if(num_r == 1) cout << 1 << endl;
        else if(num_r == 5) cout << 5 << endl;
        else {
            int i = 0, r = 1;
            while(num){
                if(num & 1) r = (r * arr[num_r][i]) % 10;
                num = num >> 1;
                i++;
            }
            cout << r << endl;
        }
    }
    return 0;
}*/

//H - Tr A   矩阵快速幂
/*#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int mod=9973;
int n,k;
struct Matrix{
    int arr[12][12];
};
Matrix init,unit;

Matrix Mul(Matrix a,Matrix b){
    Matrix c;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            c.arr[i][j]=0;
            for(int k=0;k<n;k++)
                c.arr[i][j]=(c.arr[i][j]+a.arr[i][k]*b.arr[k][j]%mod)%mod;
            c.arr[i][j]%=mod;
        }
    return c;
}

Matrix Pow(Matrix a,Matrix b,int x){
    while(x){
        if(x&1){
            b=Mul(b,a);
        }
        x>>=1;
        a=Mul(a,a);
    }
    return b;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                scanf("%d",&init.arr[i][j]);
                unit.arr[i][j]=init.arr[i][j];
            }
        Matrix res=Pow(init,unit,k-1);
        int ans=0;
        for(int i=0;i<n;i++)
            ans=(ans+res.arr[i][i])%mod;
        printf("%d\n",ans%mod);
    }
    return 0;
}*/


//贪心
#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 1000+10

using namespace std;
struct node{
     int day;
     int num;
     bool operator < (const node &a)const{
         if(num != a.num)
             return num > a.num;
         else
             return day < a.day;
     }
 };
node arr[maxn];
int indx[maxn];
int T, n,sum=0, ans=0;

int main()
{
    cin >> T;
    while(T--)
    {
        memset(indx, 0, sizeof(indx));
        cin >> n;
        int i, j, k;
        for(i = 1; i <= n; i++) cin >> arr[i].day;
        for(i = 1; i <= n; i++) cin >> arr[i].num;
        sort(arr+1, arr+n+1);
        for(i = 1; i <= n; i++){
            for(j = arr[i].day; j > 0; j--)
            {
                if(!indx[j])
                {
                    indx[j] = 1;
                    break;
                }
            }
            if(j==0)
                 ans+=arr[i].num;
         }
         cout << ans << endl;
     }
     return 0;
 }










