#include<string>
#include<iostream>
#include<map>
using namespace std;
/**
 *第四范式一面
 *
 * 有贪心思想：不需要全部记住需要删除的字符，只需要记住需要删除的最大字符
 * 
 * 给一个字符串s，k，任务是删掉k个字母。
 * 删除的规则是，按字典许最小的开始删，有相同的，先删左边的，
 * 返回删除k字母之后的字符串，
 * s只包含小写字母，s和k的输入都是合法的。
 *
 * s = 'aabccba'，k = 4
 * ans = 'ccb'
 */


void solution(string s, int k){
    
    map<char, int> m;
    for(auto i:s){
        m[i]++;
    }
    char target;
    int count=0;
    for(auto i:m){
        count+=i.second;
        if(count>=k){
            target=i.first;
            break;
        }
    }
    int i=0;
    while(i<s.size()){
        if(s[i]<target && k>0){
            s.erase(i,1);
            k--;
        }
        else
            i++;
    }
    if(k>0){
        i=0;
        while(i<s.size()){
            if(s[i]<=target && k>0){
                s.erase(i,1);
                k--;
            }
            else
                i++;
        }
    }
    cout<<s<<endl;
    
}

int main() {
    string s="aba";
    solution(s,1);
}


