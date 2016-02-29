// Chapter12.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void stringReverse(char* str){
	char *start = str;
	char *end = str;
	char temp;

	while (*end != '\0'){
		++end;
	}
	end--;

	while (start<end){
		temp = *start;
		*start = *end;
		*end = temp;
		++start;
		--end;
	}
}
int main(){
	char c[] = "A string example";
	stringReverse(c);

	system("pause");
	return 0;
}

