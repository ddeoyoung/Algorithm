// 2024.06.28

#include <iostream>

using namespace std;

int arr[1000001] = { 0, };
int s = 1000000;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;

	// 1. 배열 생성 후 초기화
	for (int i = 2; i < s; i++)
	{
		arr[i] = i;
	}

	// 2. 배수인 수 제거
	for (int i = 2; i <= s; i++)
	{
		if (arr[i] == 0)
		{
			continue;
		}

		for (int j = 2 * i; j <= s; j += i)
		{
			arr[j] = 0;
		}
	}

	// 3. 0이 아닌 수 출력 
	for (int i = M; i <= N; i++)
	{
		if (arr[i] != 0)
		{
			cout << i << "\n";
		}
	}

	return 0;
}