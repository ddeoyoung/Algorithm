// 2024.06.29
// 2024.07.01

#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		char arr[101];
		cin.getline(arr, 101, '\n');
		stack<char> s;

		if (arr[0] == '.' || arr[0] == '\n') // 프로그램 종료
		{ 
			break; 
		}

		for (int i = 0; i < 100; i++)
		{
			char c = arr[i];
			if (c == '.') { break; } // 문장의 끝
			if (c == '(' || c == ')' || c == '[' || c == ']')
			{
				s.push(c); // 괄호만 스택에 저장
			}
		}

		// 탐색
		if (s.empty())
		{
			cout << "yes" << "\n";
			continue;
		}

		else if (s.size() % 2 == 1) // 빠른 예외처리
		{
			cout << "no" << "\n";
			continue;
		}

		else if (s.top() == '(' || s.top() == '[')
		{
			cout << "no" << "\n";
			continue;
		}

		stack<char> temp;
		while (s.size() > 0)
		{
			char c = s.top();
			if (c == ')' || c == ']')
			{
				temp.push(c);
				s.pop();
			}

			else if (c == '(' || c == '[')
			{
				if (temp.empty())
				{
					break;
				}

				if (c == '(' && temp.top() == ')')
				{
					s.pop();
					temp.pop();
				}
				else if (c == '[' && temp.top() == ']')
				{
					s.pop();
					temp.pop();
				}
				else
				{
					break;
				}
			}

			if (s.empty())
			{
				break;
			}
		}

		if (s.empty() && temp.empty())
		{
			cout << "yes" << "\n";
			continue;
		}

		else
		{
			cout << "no" << "\n";
			continue;
		}
	}

	return 0;
}