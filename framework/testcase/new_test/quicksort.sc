int a[1000];
int num;

struct we{int b;} ee,ddd;


int dfjaskljflk(){
	return 0;
}

int divide(int low, int high)
{
	int temp=a[low];
	for(;low!=high;)
	{
		for(;low<high && a[high]>=temp;)
		{
			--high;
		}
		if(low<high)
		{
			a[low]=a[high];
			++low;
		}
		for(;low<high && a[low]<=temp;)
		{
			++low;
		}
		if(low<high)
		{
			a[high]=a[low];
			--high;
		}
	}
	a[low]=temp;
	return low;
}

int qsort(int low, int high)
{
	int mid;
	if(low>=high)
	{
		return 0;
	}
	mid=divide(low,high);
	qsort(low,mid-1);
	qsort(mid+1,high);
	return 0;
}

int main()
{
	int i;
	read(num);
	for(i=0;i<num;++i)
	{
		read(a[i]);
	}
	qsort(0,num-1);
	write(num);
	for(i=0;i<num;++i)
	{
		write(a[i]);
	}
	return 0;
}
