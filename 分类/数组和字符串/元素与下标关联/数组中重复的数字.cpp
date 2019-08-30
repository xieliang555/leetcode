#include<iostream>
#include<vector>
using namespace std;


/**
 * 剑指offer: 3
 *
 * 元素与下标关联
 *
 * 本题易错点在于if判断要在swap之前
 */

bool duplicate(int numbers[], int length, int* duplication) {
    if(numbers==nullptr || length<=0) return false;
    for(int i=0;i<length;i++){
    	while(numbers[i]!=i){
    		if(numbers[i]==numbers[numbers[i]]){
    			*duplication=numbers[i];
    			return true;
    		}
    		swap(numbers[i],numbers[numbers[i]]);
    	}
    }
    return false;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}