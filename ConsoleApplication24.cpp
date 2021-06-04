//13.	Из нечетных элементов дека создайте очередь, а из четных элементов создайте стек.
#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	deque<int> deq;
	queue<int, deque<int>> que;
	stack<int> st;
	for (int i = 0; i < 20; i++)
	{
		deq.push_back(rand() % 20);
	}
	cout << "deque:" << endl;
	for (auto it = deq.begin(); it != deq.end(); it++)
	{
		cout << *it << endl;
	}
	for (auto it = deq.begin(); it != deq.end(); it++)
	{
		if (*it % 2 == 0)
		{
			st.emplace(*it);
		}
	}
	for (auto it = deq.begin(); it != deq.end(); it++)
	{
		if (*it % 2 != 0)
		{
			que.emplace(*it);
		}
	}
	cout << endl;
		cout << "queue:" << endl;
		while (!que.empty())
		{
			cout << que.front() << endl;
			que.pop();
		}
		cout << endl;
		cout << "stack:" << endl;
		while (!st.empty())
		{
			cout << st.top() << endl;
			st.pop();
		}	
		system("pause");
}
	