#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<climits>
#include<ctime>
#include<cstring>
#include<sstream>
#include<cassert>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define dump(a) cerr << #a << "=" << (a) << endl
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
#define MAX_SIZE 10000

using namespace std;


struct Panel {
	string name;
	int x1,y1,x2,y2;
	vector<Panel> unders;
};

Panel ans_panel;

bool in_range(Panel &aPanel, int &x, int &y) {
	return aPanel.x1 <= x && x <= aPanel.x2 && aPanel.y1 <= y && y <= aPanel.y2;
}

void search(Panel &aPanel, int &x, int &y)
{
	if (!in_range(aPanel,x,y)) { return; }
	ans_panel=aPanel;

	rep(i,aPanel.unders.size()) {
		search(aPanel.unders[i], x, y);
	}
}

void show(Panel &aPanel) {
	cout << aPanel.name << endl;
	cout << aPanel.x1 << "," << aPanel.y1 << "," <<
			aPanel.x2 << "," << aPanel.y2 << endl;

	rep(i,aPanel.unders.size()) {
		show(aPanel.unders[i]);
	}
}

vector<int> tag_value(const string &line, int &i)
{
	vector<int> nums;
	string num_str="";
	while(true) {
		if ('0' <= line[i] && line[i] <= '9') {
			num_str += line[i];
		}
		else if (line[i] == ',') {
			nums.push_back(stoi(num_str));
			num_str="";
		}
		else {
			break;
		}
		i++;
	}
	nums.push_back(stoi(num_str));

	return nums;
}

//OK
string tag_name(const string &line, int &i)
{
	string a_str="";
	while(true) {
		if ((('a' <= line[i]) && (line[i] <= 'z')) ||
			(('A' <= line[i]) && (line[i] <= 'Z')) ) {
			a_str += line[i];
		}
		else {
			break;
		}
		i++;
	}
	return a_str;
}


string start_tag(const string &line, int &i)
{
	assert(line[i] == '<');
	i++; //開始<
	string name = tag_name(line,i);

	assert(line[i] == '>');
	i++; //終了>
	return name;
}


bool try_end_tag(const string &line, int i)
{
	if(line[i] != '<') { return false; }
	i++; //開始<
	if(line[i] != '/') { return false; }
	i++; //開始/
	string name = tag_name(line,i);
	if(line[i] != '>') { return false; }
	i++; //終了>
	return true; //全部満たせば
}

string end_tag(const string &line, int &i)
{
	assert(line[i] == '<');
	i++; //開始<
	assert(line[i] == '/');
	i++; //開始/
	string name = tag_name(line,i);
	assert(line[i] == '>');
	i++; //終了>
	return name;
}


/*
 * ここからはじまる.
 */
Panel tag_struct(const string &line, int &i, Panel &aPanel)
{
	aPanel.name = start_tag(line,i);
	vector<int> values = tag_value(line,i);

	assert(values.size() == 4);
	aPanel.x1 = values[0];
	aPanel.y1 = values[1];
	aPanel.x2 = values[2];
	aPanel.y2 = values[3];

	while(true) {
		bool is_end = try_end_tag(line,i);
		//文字があるとき
		if (is_end) { break; } 
		Panel underPanel;
		aPanel.unders.push_back(tag_struct(line,i, underPanel));
	}
	end_tag(line,i);

	return aPanel;
}


int main() {
	int N;
	int x,y;
	string line;


	while(cin >> N) {
		if (N == 0) { break; }
		Panel mainPanel;

		cin >> line;
		int i=0;
		int level=0;
		tag_struct(line, i, mainPanel);

		rep(i,N) {
			cin >> x >> y;
			ans_panel = Panel();
			search(mainPanel,x,y);
			if (in_range(mainPanel,x,y)) {
				cout << ans_panel.name << " " << ans_panel.unders.size() << endl;
			}
			else {
				cout << "OUT OF MAIN PANEL 1" << endl;
			}
		}
	}

	return EXIT_SUCCESS;
}
