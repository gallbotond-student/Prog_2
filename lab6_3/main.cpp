#include <iostream>
void inter(int *a, int s, int m, int d)
{
    int i,j,k,*c;
//c tömb helyfoglalása
    i=s; j=m+1;k=1;
    while(i<=m && j<=d)
    if(a[i]<a[j]) c[k++]=a[i++];
    else c[k++]=a[j++];
    while(i<=m) c[k++]=a[i++];
    while(j<=d) c[k++]=a[j++];
    k=1;
    for(i=s;i<=d;i++) a[i]=c[k++];
}
void msort(int *a, int s, int d)
{
    int m;
    if(s<d)
    {
        m=(s+d)/2;
        msort(a,s,m);
        msort(a,m+1,d);
        inter(a,s,m,d);
    }
}

int poz(int *a, int s, int d){
    int i,j,di,dj,aux;
    i=s; j=d; di=0; dj=1;
    while(i<j)
    {
        if(a[i]>a[j])
        {
            aux=a[i]; a[i]=a[j]; a[j]=aux;
            di=1-di; dj=1-dj;
        }
        i=i+di;
        j=j-dj;
    }
    return j;
}

void QS(int *a, int s, int d)
{
    int p;
    if(s<d)
    {
        p=poz(a,s,d);
        QS(a,s,p-1);
        QS(a,p+1,d);
    }
}

int main() {
    int a[5] = {3, 4, 5, 2, 3}, b[5] = {4, 5, 6, 7, 4}, c[10] = {0};
    QS(a, 0, 5);
    QS(b, 0, 5);
    for (int i = 0; i < 5; ++i) {
        printf("%d", a[i]);
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d", b[i]);
    }


}
