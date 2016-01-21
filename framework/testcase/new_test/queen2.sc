int a[100],v[100],c[100],b[100],s=0,n;

int print()
{
     	int i;
     	for(i=1;i<n;++i)
	{
		write(b[i]);
	}
	write(b[n]);
	return 0;
}

int DFS(int x)
{
     int i,j,k;
     if(x>n)
     {
     	if(s<3)
        print();
        ++s;
        return 0;
     }
     for(i=1;i<n+1;++i)
     {
         if(!a[i]&&!v[i+x]&&!c[i-x+15])
         {
             a[i]=1;
             v[i+x]=1;
             c[i-x+15]=1;
             b[x]=i;
             DFS(x+1);
             a[i]=0;
             v[i+x]=0;
             c[i-x+15]=0;
         }
     }
     return 0;
}

int main()
{
    	read(n);
    	DFS(1);
	write(s);
    	return 0;
}
