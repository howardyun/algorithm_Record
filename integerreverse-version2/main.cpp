#include <iostream>

int reverse(int x){
	if(x>INT_MAX||x<INT_MIN||x==0)
		return 0;
	int temp1=0;
	int temp2=0;
	while (x!=0){
		temp1=x%10;
		x=x/10;
		if(temp2>INT_MAX/10||(temp2==INT_MAX&&temp1>7))return 0;
		if(temp2<INT_MIN/10||(temp2==INT_MIN&&temp1<-8))return 0;

		temp2=(temp2*10+temp1);
	}

return temp2;

}

int main()
{


	std::cout << reverse(0) << std::endl;
	return 0;
}
