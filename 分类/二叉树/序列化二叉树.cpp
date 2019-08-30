#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * 剑指offer: 37
 *
 * 本题易错的点主要在反序列化时将字符转换为数字时可能是多位数
 */

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

void Serialize(TreeNode* root, string& s){

	if(!root){
		s+="$,";
		return;
	}
	s+=to_string(root->val)+",";
	Serialize(root->left,s);
	Serialize(root->right,s);
}

char* Serialize(TreeNode *root) {    
    if(!root) return nullptr;
    string str="";
    Serialize(root, str);
	char* ret=new char[str.length()];
	int i;
	for(i=0;i<str.size();i++){
		ret[i]=str[i];
	}
	//将最后一个逗号改成字符串终止符
	ret[i-1]='\0';
	return ret;
}


TreeNode* Deserialize(char** str){
	if((**str)=='\0') return nullptr;
	if((**str)==',') (*str)++;
	if((**str)=='$'){
		(*str)++;
		return nullptr;
	}

	int num=0;
	while((**str)!=',' && (**str)!='\0'){
		num=num*10+(**str-'0');
		(*str)++;
	}
	TreeNode* root=new TreeNode(num);
	root->left=Deserialize(str);
	root->right=Deserialize(str);
	return root;
}


TreeNode* Deserialize(char *str) {
	if(!str) return nullptr;
	TreeNode* ret=Deserialize(&str);
	return ret;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

