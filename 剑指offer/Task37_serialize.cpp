#include<iostream>
#include<string>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Task37_serialize
{
public:
	Task37_serialize(){}
	~Task37_serialize(){}

	char* Serialize(TreeNode* root){

		if(root==nullptr) return nullptr;

		string str;
		serialize(root,str);
		char* ret=new char[str.size()];
		int i;
		for(i=0;i<str.length();i++){
			ret[i]=str[i];
		}
		//将最后一个逗号改成字符串终止符
		ret[i-1]='\0';
		return ret;

	}

	void serialize(TreeNode* root, string& str){

		if(root==nullptr){
			str.push_back('$');
			str.push_back(',');
			return;
		}

		//此处不能用push_back添加字符，因为如果是负数或非个位数则需要添加字符串
		str+=(to_string(root->val));
		str.push_back(',');
		serialize(root->left,str);
		serialize(root->right,str);
	}

	TreeNode* Deserialize(char* str){
		if(str==nullptr) return nullptr;
		return recursionCore(&str);
	}

	TreeNode* recursionCore(char** str){
		// **str是访问指针，使用前应先判断(*str)是否为空指针
		// 正如*p访问p之前先要判断 p==nullptr
		if((**str)=='\0') 
			return nullptr;
		if((**str)==',')
			(*str)++;
		if((**str)=='$'){
			(*str)++;
			return nullptr;
		}
		int num=0;
		while(**(str)!=',' && **(str)!='\0'){
			num=num*10+(**str-'0');
			(*str)++;
		}
		TreeNode* root=new TreeNode(num);
		root->left=recursionCore(str);
		root->right=recursionCore(str);
		return root;
	}
	
};

int main(int argc, char const *argv[])
{
	Task37_serialize t;
	char s[30]="1,2,4,$,$,$,3,5,$,$,6,$,$";
	TreeNode* ret=t.Deserialize(s);
	cout<<ret->val<<endl;
	cout<<ret->left->val<<endl;
	cout<<ret->left->left->val<<endl;
	cout<<t.Serialize(ret);
	return 0;
}