#include <iostream>
#include <string>
int romanToInt(std::string s) {
	int rezult=0;
	for(int i=0;i<s.length();++i){

		switch(s[i]){
		case 'I':
			if(i==s.length()-1){
				++rezult;
			}
			else if(s[i+1]=='V'){
				rezult+=4;
				++i;
			}else if(s[i+1]=='X'){
				rezult+=9;
				++i;
			}else{
				++rezult;
			}
			break;
		case 'V':
			rezult+=5;
			break;
		case 'X':
			if(i==s.length()-1){
				rezult+=10;
			}
			else if(i==s.length()-1){
				rezult+=10;
			}
			else if(s[i+1]=='L'){
				rezult+=40;
				++i;
			}else if(s[i+1]=='C'){
				rezult+=90;
				++i;
			}else{
				rezult+=10;

			}
			break;
		case 'L':
			rezult+=50;
			break;
		case 'C':
			if(i==s.length()-1){
				rezult+=100;
			}
			else if(s[i+1]=='D'){
				rezult+=400;
				++i;
			}else if(s[i+1]=='M'){
				rezult+=900;
				++i;
			}else{

				rezult+=100;
			}
			break;
		case 'D':
			rezult+=500;
			break;
		case 'M':
			rezult+=1000;
			break;

		}

	}
	return rezult;





}
int main()
{


	std::cout << romanToInt("MMMCC") << std::endl;
	return 0;
}
