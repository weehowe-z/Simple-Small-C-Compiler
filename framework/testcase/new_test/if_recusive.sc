int main()
{
	int i;
	read(i);
	if(i%2==0)
	{
		write(i);
	}
	else
	{
		i=(i-1)/2;
		if(i%2==0)
		{
			write(i);
		}
		else
		{
			i=(i-1)/2;
			if(i%2==0)
			{
				write(i);
			}
			else
			{
				if(i%2==0)
					write(i);
			}
		}
	}
	return 0;
}
