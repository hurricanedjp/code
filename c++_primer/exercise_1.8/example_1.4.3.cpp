#include <iostream>
int main()
{
	int sum =0;
	int value =0;
	while(std::cin>>value)
	{
		sum += value;
		if(sum<100)
			sum++;
	}
	std::cout<<"sum is: "<<sum<<std::endl;
	return 0;
}

