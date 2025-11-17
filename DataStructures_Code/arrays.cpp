// Static 2D Array

#include <iostream>
using namespace std;
int main(){
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) 
        { 
            cout<<a[i][j]<<" ";
        };
        cout<<"\n";
    }
    return 0;
}

// Dynamic 2D Array

#include <iostream>
using namespace std;
int main(){
    int r=3,c=3;
    int **a=new int*[r];
    for(int i=0;i<r;i++){
        a[i]=new int[c];
        for(int j=0;j<c;j++) { 
            a[i][j]=i+j;
        };
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
             cout<<a[i][j]<<" ";
        };
        cout<<"\n";
    }
    return 0;
}
  
// Recursion – Factorial

#include <iostream>
using namespace std;
int f(int n){ 
        if(n<=1) {
            return 1; 
        }
         return n*f(n-1);
     }
int main(){
    int n;
    cin>>n;
    cout << f(n);
    return 0;
}

// Recursion – Fibonacci

#include <iostream>
using namespace std;
int f(int n){
     if(n<=1) {
        return n;
    } 
    return f(n-1)+f(n-2); 
}
int main(){
    int n; 
    cin>>n;
    cout << f(n);
    return 0;
}

// Tower of Hanoi

#include <iostream>
using namespace std;
void h(int n,char a,char b,char c){
    if(n==0) {
        return;
    };
    h(n-1,a,c,b);
    cout << a << "->" << c << "\n";
    h(n-1,b,a,c);
}
int main(){
    int n;
    cin>>n;
    h(n,'A','B','C');
    return 0;
}

// Row-Major Mapping using 2D Array

#include <iostream>
using namespace std;
int main()
{
    int r;
    int c;
    cin >> r;
    cin >> c;

    int a[10][10];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin >> a[i][j];
        }
    }

    int k = 0;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout << "a[" << i << "][" << j << "]=";
            cout << a[i][j];
            cout << " -> ";
            cout << k;
            cout << "\n";
            k = k + 1;
        }
    }
    return 0;
}

// Column-Major Mapping using 2D Array

#include <iostream>
using namespace std;
int main()
{
    int r;
    int c;
    cin >> r;
    cin >> c;

    int a[10][10];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin >> a[i][j];
        }
    }

    int k = 0;

    for(int j=0;j<c;j++)
    {
        for(int i=0;i<r;i++)
        {
            cout << "a[" << i << "][" << j << "]=";
            cout << a[i][j];
            cout << " -> ";
            cout << k;
            cout << "\n";
            k = k + 1;
        }
    }
    return 0;
}

// Reverse Row-Major

#include <iostream>
using namespace std;
int main()
{
    int r;
    int c;
    int k;

    cin >> r;
    cin >> c;
    cin >> k;

    int a[10][10];
    int x = 0;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            a[i][j] = x;
            x = x + 1;
        }
    }

    int i = k / c;
    int j = k % c;

    cout << i << " " << j << " " << a[i][j];
    return 0;
}

// Reverse Column-Major

#include <iostream>
using namespace std;
int main()
{
    int r;
    int c;
    int k;

    cin >> r;
    cin >> c;
    cin >> k;

    int a[10][10];
    int x = 0;

    for(int j=0;j<c;j++)
    {
        for(int i=0;i<r;i++)
        {
            a[i][j] = x;
            x = x + 1;
        }
    }

    int j = k / r;
    int i = k % r;

    cout << i << " " << j << " " << a[i][j];
    return 0;
}

// Lower Triangular Mapping using 2D Array

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[10][10];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }

    int k = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout << "a[" << i << "][" << j << "]=";
            cout << a[i][j];
            cout << " -> ";
            cout << k;
            cout << "\n";
            k = k + 1;
        }
    }
    return 0;
}

// Upper Triangular Mapping using 2D Array

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[10][10];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }

    int k = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            cout << "a[" << i << "][" << j << "]=";
            cout << a[i][j];
            cout << " -> ";
            cout << k;
            cout << "\n";
            k = k + 1;
        }
    }
    return 0;
}

// Diagonal Matrix Mapping using 2D Array

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[10][10];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        cout << "a[" << i << "][" << i << "]=";
        cout << a[i][i];
        cout << " -> ";
        cout << i;
        cout << "\n";
    }
    return 0;
}

// Symmetric Matrix Mapping using 2D Array

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[10][10];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }

    int k = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout << "a[" << i << "][" << j << "]=";
            cout << a[i][j];
            cout << " -> ";
            cout << k;
            cout << "\n";
            k = k + 1;
        }
    }
    return 0;
}








