#include <stdio.h>
 
#define N 7
int cnt=0;

void inverse(int a[],int l,int r)
{
	int m=(l+r)>>1;
	int temp[100];
	int i=l,j=m+1,c=l;

	if(l>=r)return;
	inverse(a,l,m);
	inverse(a,m+1,r);
	while(i<=m||j<=r)
	{
		if(j>r||(i<=m && a[i]<=a[j] ))temp[c++]=a[i++];
		else{temp[c++]=a[j++];cnt+=m-i+1;}
	}

	for(i=l;i<=r;i++) a[i]=temp[i];
}

void main()
{
	int i;
	int a[N]={1,100,85,200,34,92,77};
	for(i=1;i<N;i++)
		printf("%d\t",a[i]);
	printf("\n");
	inverse(a,1,N-1);
	printf("%d\n",cnt);
	for(i=1;i<N;i++)
		printf("%d\t",a[i]);
}