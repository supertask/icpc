#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	string chipher;

	while(cin >> N)
	{
		if (N == 0) { break; }
		vector<int> keys(N);

		for(int i = 0; i < N; i++) {
			cin >> keys[i];
		}
		cin >> chipher;
		
		for(int i = 0; i < chipher.size(); i++)
		{
			char ans;
			int ii = i % keys.size();
			int diff_i;
			bool upper = true;
			if ('a' <= chipher[i] && chipher[i] <= 'z')
			{
				diff_i = chipher[i] - 'a';
				upper = false;
			}
			else if ('A' <= chipher[i] && chipher[i] <= 'Z')
			{
				diff_i = chipher[i] - 'A';
				upper = true;
			}
			int left_diff_i = diff_i - keys[ii];
			//cout << left_diff_i << " ";
			
			//int left_diff_i = diff_i - keys[ii];
			while(left_diff_i < 0) {
				left_diff_i = 26 + left_diff_i;
				upper = !upper;
			}

			if (upper) {
				cout << (char)('A'+left_diff_i);
			}
			else {
				cout << (char)('a'+left_diff_i);
			}

		}
		cout << endl;
	}
	return EXIT_SUCCESS;
}
