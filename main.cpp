#include<iostream>
#include<optional>
#include"monad/optional.hpp"

std::optional<int> divide_by_two(int value){
	if(value%2!=0) return std::nullopt;
	return std::optional<int>(value/2);
	
}
int main(){
	std::cout<<"hello world"<<std::endl;

	std::optional<int> value(10);

	auto ans = value >> fmap(divided_by);
	return 0;
}
