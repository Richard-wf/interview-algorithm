#include <iostream>
#include <stack>

using namespace std;

/*将stack的栈底元素返回并移除*/
int getLastElement(stack<int> &myStack)
{ 
	int result = myStack.top();
	myStack.pop();
	if(myStack.empty())
	{
		return result;
	}
	else
	{
		int last = getLastElement(myStack);
		myStack.push(result);
		return last;
	}
}

/*栈逆序*/
void reverse(stack<int> &myStack)
{
	if(myStack.empty())
	{
		return;
	}
	int i = getLastElement(myStack);
	reverse(myStack);
	myStack.push(i);
}

void show(stack<int> &myStack)
{
	while(!myStack.empty()){
		cout << myStack.top() << " ";
		myStack.pop();
	}

	cout << endl;
}

int main()
{
	stack<int> st;
	
	for(int i = 0; i < 5; ++i)
	{
		st.push(i+1);
	}
	reverse(st);
	show(st);

	return 0;
}
