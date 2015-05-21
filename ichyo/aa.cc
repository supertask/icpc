#include<bits/stdc++.h>
#define dump(a) cout << #a << "=" << a << endl
using namespace std;

int main()
{
	int N,R;
	int p,c;
	while(cin >> N >> R)
	{
		if (N == 0 && R == 0) break;

		vector<int> cards(N,0);

		for(int i=0; i<N; i++)
		{
			cards[i]=i+1; //カード番号を割り振る
		}

		for(int i=0; i<R; i++) {
			cin >> p >> c;
			//cout << p << " " << c << endl;

			vector<int> p_cards;
			vector<int> c_cards;

			int end_p = N;
			int begin_p = N-(p-1);
			int end_c = begin_p;
			int begin_c = end_c - c;

			dump(begin_c);
			dump(end_c);
			dump(begin_p);
			dump(end_p);

			for(int i=0; i<N; i++) {
				if (begin_c <= i && i < end_c) {
					c_cards.push_back(cards[i]);
				}
				else if (begin_p <= i && i < end_p) {
					p_cards.push_back(cards[i]);
				}
			}

			//show
			/*
			cout << "c: ";
			for(int i=0; i<c_cards.size(); i++) {
				cout << c_cards[i] << " ";
			}
			cout << endl;
			cout << "p: ";
			for(int i=0; i<p_cards.size(); i++) {
				cout << p_cards[i] << " ";
			}
			cout << endl;
			*/

			//trans
			for(int i=0; i<p_cards.size(); i++) {
				//dump(begin_c+i);
				//dump(p_cards[i]);
				cards[begin_c+i] = p_cards[i];
			}
			for(int i=0; i<c_cards.size(); i++) {
				int k = begin_c+(p-1);
				assert((k+i) > 0);
				//dump(k+i);
				dump(p_cards[i]);
				cards[k+i] = p_cards[i];
			}

			//show
			for(int i=0; i<cards.size(); i++) {
				cout << cards[i] << " ";
			}
			cout << endl;


		}

		cout << "card[0]" << cards[cards.size()-1] << endl;
		
	}

	return EXIT_SUCCESS;
}
