#include <iostream>
class stack{
public:
	stack(int x){
		num=x;
	}
	int num;
	stack * p;
};


class mystack{
public:
	stack *head;
	stack *tail;
};

class myqueue{
public:
	stack *head;
	stack *tail;


};
int is_mul_overflow(int a, int b) {
	if( a >= 0 && b >=0  ) {
		return INT_MAX / a < b;
	}
	else if( a < 0 && b < 0 ) {
		return INT_MAX / a > b;
	}
	else if( a * b == INT_MIN ) {
		return 0;
	}
	else {
		return a < 0 ? is_mul_overflow(-a, b) : is_mul_overflow(a, -b);
	}
}
int is_plus_overflow(int a, int b){
	if(a>=0&&b>=0){

		return INT_MAX-a<b;

	}else if(a<=0&&b<=0){
		return INT_MIN-a>b;
	}


}


int reverse(int x) {

	mystack s;
	myqueue q;
	s.tail=new stack(-1);
	s.head=s.tail;
	q.head=new stack(-1);
	q.tail=q.head;
	if(x>2147483647||x<-2147483648||x==0){

		return 0;
	} else{
		int i=1000000000;
		bool judge=true;
		if(i<0){
			judge=false;
		}
		bool flage=true;
		while(i!=1){
			if(((int)x/i)==0){

				if(flage){
					i/=10;
					continue;
				}else{
					stack *temp=new stack(0);
					temp->p=s.head;
					s.head=temp;
					i/=10;
					continue;
				}


			}else{
				flage=false;
				int z=(int)x/i;
				stack *temp=new stack(z);
				temp->p=s.head;
				s.head=temp;
				if(judge==true)
					x-=(z*i);
				else
					x+=(-z*i);
				i/=10;
			}
		}
		if(x!=0){
			stack *temp=new stack(x);
			temp->p=s.head;
			s.head=temp;
		}
		int count=0;
while(s.head->num==0)
	s.head=s.head->p;
		while(s.head!=s.tail){
			q.tail->p=s.head;
			q.tail=q.tail->p;
			++count;
			s.head=s.head->p;
		}
		int ji=1;
		for(int ml=0;ml<count-1;ml++){
			ji*=10;
		}
		int ttt=0;
		q.head=q.head->p;
		if(q.head==NULL)
			return 0;
		else{
			while(q.head!=q.tail){

				int temp=q.head->num;
				if(is_mul_overflow(temp,ji))
					return 0;
				if(is_plus_overflow(ttt,temp*ji))
					return 0;
				ttt+=temp*ji;
				std::cout<<temp*ji<<std::endl;
				ji/=10;
				q.head=q.head->p;
			}
			ttt+=q.head->num;
			return ttt;
		}

	}


}
int main()
{
	std::cout <<reverse(-2147483648) << std::endl;


	return 0;
}
