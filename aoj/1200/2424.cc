#include<iostream>
#define dump(a) cout << (#a) << "=" << a << endl
using namespace std;

int main() {
	int N;
	string num;

	cin >> N;

	for(int t=0;t<N;t++) {
		cin >> num;

		int cnt=0;
		int back_size=0;
		bool is_infre=false;
		while(true) {
			if (num.size() == 1) {
				is_infre=false;
				break;
			}
			else {
				if (num.size() == back_size) { //サイズが変更しないとき
					if (cnt > 1000000) { 
						//失敗例
						is_infre=true;
						break; 
					}
				}

				int max_num=0;
				for(int i=1;i<num.size();i++) {
					string left = num.substr(0,i);
					string right = num.substr(i,num.size()-i);
					max_num = max(max_num, stoi(left)*stoi(right));
				}
				num = to_string(max_num);
			}
			cnt++;
			back_size = num.size();
		}

		cout <<  (is_infre ? "-1" : to_string(cnt)) << endl;
	}
	
	return EXIT_SUCCESS;
}
