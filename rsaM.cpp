#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
 
using namespace std;

long int p, q, r, s, n, m, N, tn, tm, tN, flag,E1, e1[100], e2[100],E[100], d[100], temp[100], j, M[100], en[100], i;
char msg[100];
int prime(long int);
void ce1();
void ce2();
void ce3();
long int cd1(long int);
long int cd2(long int);
long int cd3(long int);
void encrypt();
void decrypt();
int prime(long int pr)
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    cout << "\nENTER FIRST PRIME NUMBER\n";
    cin >> p;
    flag = prime(p);
    if (flag == 0)
    {
        cout << "\nWRONG INPUT\n";
        exit(1);
    }
    cout << "\nENTER SECOND PRIME NUMBER\n";
    cin >> q;
    flag = prime(q);
    if (flag == 0 || p == q)
    {
        cout << "\nWRONG INPUT\n";
        exit(1);
    }
    cout << "\nENTER THIRD PRIME NUMBER\n";
    cin >> r;
    flag = prime(r);
    if (flag == 0 || p == q)
    {
        cout << "\nWRONG INPUT\n";
        exit(1);
    }
    cout << "\nENTER FOURTH PRIME NUMBER\n";
    cin >> s;
    flag = prime(s);
    if (flag == 0 || p == q)
    {
        cout << "\nWRONG INPUT\n";
        exit(1);
    }
    cout << "\nENTER MESSAGE\n";
    fflush(stdin);
    cin >> msg;
    for (i = 0; msg[i] != '\0'; i++)
        M[i] = msg[i];
    n = p * q;
    m= r*s;
    N=m*n;
    tn = (p - 1) * (q - 1);
    tm= (r-1)*(s-1);
    tN= tn*tm;
    ce1();
    ce2();
    cout << "\nPOSSIBLE VALUES OF e2 ARE\n";
    for (i = 0; i < j - 1; i++)
        cout << e1[i] << "\n";
    cout << "\nPOSSIBLE VALUES OF e2 ARE\n";
    for (i = 0; i < j - 1; i++)
        cout << e2[i] <<"\n";   
    E1=1;    
    for(long int i1=0;i1<e2[0];i1++)
        E1= E1*e1[0];
    E1=E1%n;
    ce3();    
    cout << "\nPOSSIBLE VALUES OF E AND D ARE\n";
    for (i = 0; i < j - 1; i++)
        cout << E[i] <<"\t"<< d[i] <<"\n";
    encrypt();
    decrypt();
    return 0;
}
void ce1()
{
    int k;
    k = 0;
    for (i = 2; i < tn; i++)
    {
        if (tn % i == 0)
            continue;
        flag = prime(i);
        if (flag == 1 && i != p && i != q)
        {
            e1[k] = i;
            flag = cd1(e1[k]);
            if (flag > 0)
            {
                //d[k] = flag;
                k++;
            }
            if (k == 99)
                break;
        }
    }
}
void ce2()
{
    int k;
    k = 0;
    for (i = 2; i < tm; i++)
    {
        if (tm % i == 0)
            continue;
        flag = prime(i);
        if (flag == 1 && i != r && i != s)
        {
            e2[k] = i;
            flag = cd2(e2[k]);
            if (flag > 0)
            {
                //d[k] = flag;
                k++;
            }
            if (k == 99)
                break;
        }
    }
}

void ce3()
{
    int k;
    k = 0;
    for (i = 2; i < tN*E1; i++)
    {
        if ((tN*E1) % i == 0)
            continue;
        flag = prime(i);
        if (flag == 1 && i != r && i != s && i != p && i != q)
        {
            E[k] = i;
            flag = cd3(E[k]);
            if (flag > 0)
            {
                d[k] = flag;
                k++;
            }
            if (k == 99)
                break;
        }
    }
}

long int cd1(long int x)
{
    long int k = 1;
    while (1)
    {
        k = k + tn;
        if (k % x == 0)
            return (k / x);
    }
}
long int cd2(long int x)
{
    long int k = 1;
    while (1)
    {
        k = k + tm;
        if (k % x == 0)
            return (k / x);
    }
}

long int cd3(long int x)
{
    long int k = 1;
    while (1)
    {
        k = k + tN*E1;
        if (k % x == 0)
            return (k / x);
    }
}

void encrypt()
{
    long int pt, ct, key = e[0], k, len;
    i = 0;
    len = strlen(msg);
    while (i != len)
    {
        pt = M[i];
        pt = pt - 96;
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    cout << "\nTHE ENCRYPTED MESSAGE IS\n";
    for (i = 0; en[i] != -1; i++)
        printf("%c", en[i]);
}
void decrypt()
{
    long int pt, ct, key = d[0], k;
    i = 0;
    while (en[i] != -1)
    {
        ct = temp[i];
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * ct;
            k = k % n;
        }
        pt = k + 96;
        M[i] = pt;
        i++;
    }
    M[i] = -1;
    cout << "\nTHE DECRYPTED MESSAGE IS\n";
    for (i = 0; M[i] != -1; i++)
        printf("%c", M[i]);
}