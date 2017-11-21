// Student name:	ZHOU Zhenghao
// Student ID  :	54381018

// Submission is not required

/*
	Part-1: Implement some simple functions for binary tree.

	Part-2:
	1. Write a function to construct an expression tree from a postfix expression.
	2. Write a function to print the prefix expression for a given expression tree.
	3. Write a function to print the infix expression for a given expression tree.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>
#include <cmath>  // pow(double x, double y), compute the value of x to power y

#define OPERAND 0
#define OPERATOR 1

using namespace std;

template<class Type>
struct treeNode
{
	Type info;
	treeNode<Type> *left, *right;
};

struct infoRec // data record for expression tree
{
	int dataType; // OPERAND or OPERATOR
	union
	{
		char opr;
		double value;
	};
};

ostream& operator<<(ostream& os, infoRec& r)
{
	if (r.dataType == OPERATOR)
		os << r.opr;
	else
		os << r.value;
	return os;
}

// printTree function that can be used for both part-1 and part-2
template <class Type>
void printTree(treeNode<Type> *p, int indent)
{
	if (p != NULL)
	{
		printTree(p->right, indent+4);
		cout << setw(indent) << p->info << endl;
		printTree(p->left, indent+4);
	}	
}

//--------------------------------------------- functions prepared for you (part-1)

treeNode<int> *buildTreeFromArray(const int *a, int n, int i, int nullSymb)
{
	// nullSymb is the value used to represent "null" in the input array.
	// index i represents the location of the root node in the array.

	treeNode<int> *p = NULL;
	if (i < n && a[i] != nullSymb)
	{
		p = new treeNode<int>;
		p->info = a[i];
		p->left = buildTreeFromArray(a, n, 2*i+1, nullSymb);
		p->right = buildTreeFromArray(a, n, 2*i+2, nullSymb);
	}
	return p;
}


//--------------------------------------------- functions prepared for you (part-2)

bool isOperator(char c)
{
   return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
}

double evaluateOperator(char opr, double d1, double d2)
{
	switch (opr) 
	{
		case '+' : return d1 + d2;
		case '-' : return d1 - d2;
		case '*' : return d1 * d2;
		case '/' : return d1 / d2;
		case '$' : return pow(d1, d2);
		default : return 0;
	}
}

double nextOperand(const string& expr, int& i)
{
	int j = i;
	while (j < expr.length() && expr[j] != ' ')
		j++;

	string number = expr.substr(i, j-i);
	i = j;

	return stod(number);
}

int precedentNum(char opr)
{
	switch (opr) 
	{
		case '+' : 
		case '-' : return 1;
		case '*' : 
		case '/' : return 2;
		case '$' : return 3;
		default : return 0;
	}
}

//------------------------------------ functions to be written by you (Part-1)

int levelSum(treeNode<int> *tree, int level)
{
	
	// Return the sum of the nodes on the given level.

	// Your codes
	
	return 0; // dummy return statement
}

int getMax(treeNode<int> *tree)
{
	// Precondition: The tree is not empty.
	// Return the largest number in the binary tree.
	int max=0;
	if(tree !=NULL){
		max=tree->info;
		if(max<getMax(tree->left)){
			max=getMax(tree->left);
		}
		if(max<getMax(tree->right)){
			max=getMax(tree->right);
		}
	}
	else{
		return 0;
	}
	return max; // dummy return statement
}

//------------------------------------ functions to be written by you (Part-2)

treeNode<infoRec>* buildTreeFromPostfixExpr(const string& expr)
{
	// Precondition: The postfix expression is not empty, 
	//               and does not have syntax error.

	// Create an expression tree from the given postfix expression.
	// The algorithm is similar to the algorithm to evaluate a 
	// postfix expression using a stack.

	stack<treeNode<infoRec>*> S; 

	int i = 0;
	while (i < expr.length())
	{
		// Your codes

	}
	return S.top();
}

void printPreorder(const treeNode<infoRec> *tree)
{
	// Recursive function based on preorder traversal.

	// Your codes
}

void printPrefixExpr(const treeNode<infoRec> *tree)
{
	// Print the expression in prefix format.

	cout << "Prefix expression:  ";
	printPreorder(tree);
	cout << endl;
}

void printInorder(const treeNode<infoRec> *tree)
{
	// Recursive function based on inorder traversal.
	// You need to consider when you need to add a bracket in the infix expression.

	// Your codes

}

void printInfixExpr(const treeNode<infoRec> *tree)
{
	// Print the expression in infix format (with brackets, if required)

	cout << "Infix expression:   ";
	printInorder(tree);
	cout << endl;
}

//---------------------------- main and driver functions prepared for you

void testExpr(const string& postfix_expr)
{
	cout << "------------------------------------------------------\n";
	cout << "Postfix expression: " << postfix_expr << endl;

	treeNode<infoRec> *tree = buildTreeFromPostfixExpr(postfix_expr);
	cout << "\nExpression tree:\n\n";
	printTree(tree, 4);
	cout << endl;

	printPrefixExpr(tree);
	printInfixExpr(tree);
	cout << endl;
}

int main()
{	
	// Part-1
	int arrayTree[] = {41, 50, 35, 55, 16, 76, 85, 63, 89, -1, -1, 70, -1, -1, -1, -1, 20};
	int n = 17;
	treeNode<int> *t = buildTreeFromArray(arrayTree, n, 0, -1);  // nullSymb = -1
	printTree(t, 4);
	cout << endl;

	cout << "Max value in the binary tree = " << getMax(t) << endl << endl;

	for (int i = 0; i < 6; i++)
		cout << "Sum of nodes on level " << i << " = " << levelSum(t, i) << endl << endl;	

	// Part-2
	string postfix_expr1 = "12.2 2.5 * 7.2 3.6 / +";
	string postfix_expr2 = "2 2 $ 5 * 3 - 4.2 3.3 / 5.5 2.5 + / +";
	string postfix_expr3 = "1.2 2.3 1.5 4.1 * 1.8 $ 3.3 + / +";
	string postfix_expr4 = "1.9 2.8 3.7 + * 4.6 - 5.5 6.4 7.3 + - /";
	string postfix_expr5 = "1 2 3 4 5 + - * /";
	
	testExpr(postfix_expr1);
	testExpr(postfix_expr2);
	testExpr(postfix_expr3);
	testExpr(postfix_expr4);
	testExpr(postfix_expr5);
	
	system("pause");
	exit(0);
}