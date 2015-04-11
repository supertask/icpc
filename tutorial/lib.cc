// vimrc
set autoindent
set number
set ruler
set title
set tabstop=4
set shiftwidth=4
set ttymouse=xterm2 
syntax on


/*
 * アルゴリズムのテンプレート
 */
// ツェラーの公式 (3<=x<=14)
if(month < 3){ year--; month+=12; } //1月 2月の場合はmonthを調整
if(month == 14){ day += 1; } //閏年の処理
int w = ((year + (year/4) - (year/100) + (year/400) + (((13 * month) + 8)/5) + day) % 7);

// アルファベットのmodを取る
#define ALPHAS_LEN 26
char alphas[ALPHAS_LEN];
char get_moder(char a_char, int count) {
	int index = a_char - 'A';
	while(count < 0) { count+= ALPHAS_LEN; }
	return alphas[(index+count) % ALPHAS_LEN];
}

//4近傍と8近傍（マップ探索用）
int dw[4] = {1,0,-1,0};
int dh[4] = {0,1,0,-1};
int dw[8] = {1,1,0,-1,-1,-1,0,1};
int dh[8] = {0,1,1,1,0,-1,-1,-1};

//エラトステネスの篩
bool is_prime[PRIME_MAX];
is_prime[0] = false;
is_prime[1] = false;
REP(i,2,PRIME_MAX) is_prime[i] = true;
REP(i,2,PRIME_MAX) {
	if (is_prime[i]) {
		for (int j=i+i; j<PRIME_MAX; j+=i) is_prime[j] = false;
	}
}

//最大最小（using: chmax(max_cnt,cnt);）
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //t=min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //t=max


/*
 * 覚えること前提ライブラリ
 */
// スプリット
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str()    ,re); tok != NULL; tok = strtok(NULL,re))

// 有効桁数（精度）を調節する．fixedがあると小数のみの調節をしてくれる．
#include <iomanip>
cout << setprecision(8) << fixed;

//vectorの合計値の求め方
#include<numeric>
accumulate(ALL(v),0) //intの場合
accumulate(ALL(v),0.0) //doubleの場合

//多次元配列の初期化
fill_n((int *)array, sizeof(array) / sizeof(int), 0);

int max_value = *max_element(ALL(v)); //最大値を求める
int min_value = *min_element(ALL(v)); //最小値を求める

//string コンストラクタ
string str1("Tasuku",3); //Tas
string str2("Now is the time...", 11 /*index*/, 4 /*len*/); //time

//from string to int
#include<sstream>
stringstream ss;
ss << num;
ss.str();

//アルファベット 大文字 <-> 小文字 変換
char C;
C = (C+‘A’-‘a’); 大文字への変換
C = (C+‘a’-‘A’); 小文字への変換

//from int to string
int num = std::stoi(a_str);

int                stoi  (const string& str, size_t* idx = 0, int base = 10);
long               stol  (const string& str, size_t* idx = 0, int base = 10);
unsigned long      stoul (const string& str, size_t* idx = 0, int base = 10);
long long          stoll (const string& str, size_t* idx = 0, int base = 10);
unsigned long long stoull(const string& str, size_t* idx = 0, int base = 10);


//set（重複削除），setも印刷必要
set<string> _names(ALL(names/*vector*/)); //ハッシュ割当なのでindexアクセスできない，indexアクセスはvectorに直してからする．

// struct sort
struct Hoge {
	int num;
	Hoge(int n): num(n){}
	bool operator<( const Hoge &right ) const {
		return num > right.num;
	}
};



/*
 * 余談
 */
// オーダー
O(n^2) + O(nlog(n)) + O(n^4) = O(n^4)
log(n) < n < nlog(n) < n^2 < 2^n < 3^n < n!

//ビットの扱い方
N桁のビットを用意する : bit = 1 << N
ビット表記の i 桁目が立っているか確認 : ( bit & ( 1<<i ) ) != 0
現在の状態から、i 桁目のビットを１にする : bit = ( bit | ( 1<<i ) )
整数値を2進数で表したときに，1が立っている数を出力 : __builtin_popcount(int)

//クラス
class hoge
{
private:
	int id, number;
	vector<int> list;
public:
	hoge(int ID, int N):id(ID), number(0), list(N, 0){}
	
	void set_number(int num){
		number = num;
	}
	
	int get_number(){
		return number;
	}
	
	bool operator<(const hoge &h)const{
		return id < h.id;
	}
};
