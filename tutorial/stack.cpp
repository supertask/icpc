#include <iostream>
#include <stack>
using namespace std;

int main ()
{
	stack<int> a_stack;
	
	a_stack.push(1);
	a_stack.push(2);
	a_stack.push(3);
	
	while (!a_stack.empty())
	{
		cout << a_stack.top() << endl;
		a_stack.pop();
	}

	return 0;
}

