#include <iostream>

/*The main method to solve the problem is to judge the low half (first reverse the low half) of
 * integer whether equals to high half of integer,lick we should
 * divide 1213 to 12 31 then compare this two integer.
 * */

bool isPalindrome(int x) {
	//Judge whether x follow rule
	if(x<0||(x%10==0 && x!=0))
		return false;

	int re=0;
	//when re greater than x mean we finish the reverse
	while(re<x){

		re=re*10+x%10;
		x/=10;
	}
	// the first condition is used when x is  odd number ,
	//the Second condition is used when x is even number
	return x==re || x==(re/10);
}
int main()
{
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
