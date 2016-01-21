int divide(int x,int y)
{
	return x%y;
}

int prime(int x)
{
	int i;
	int bool=1;
	if(x<=2)
	{
		return 0;
	}
	else
	{
		for(i=2;i<x;i=i+1)
		{
			if(divide(x,i)==0)
			{
				bool=0;
				continue;
			}
		}
	}
	return bool;
}

int main()
{
	int i=0;
	int temp;
	read(i);
	for(;i>=0;--i)
	{
		read(temp);
		write(prime(temp));
	}
	return 0;
}
