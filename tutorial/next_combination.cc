/*
 * すべての組み合わせを列挙する
 * http://www.programming-magic.com/20090123132035/
 *
 * next_permutationは0,1,2の3つから3つの順列の組み合わせが作れる
 * [ 0, 1, 2 ]
 * [ 0, 2, 1 ]
 * [ 1, 0, 2 ]
 * [ 1, 2, 0 ]
 * [ 2, 0, 1 ]
 * [ 2, 1, 0 ]
 * next_combinationは0,1,2,3,4の5つから3つの順列の組み合わせが作れる
 * [ 0, 1, 2 ]
 * [ 0, 1, 3 ]
 * [ 0, 1, 4 ]
 * [ 0, 2, 3 ]
 * [ 0, 2, 4 ]
 * [ 0, 3, 4 ]
 * [ 1, 2, 3 ]
 * [ 1, 2, 4 ]
 * [ 1, 3, 4 ]
 * [ 2, 3, 4 ]
 */

#include<iostream>
#include<vector>

using namespace std; /* 無くてもあっても良い */

/* next_combinationの本体 */
template <class BidirectionalIterator>
bool next_combination (
		BidirectionalIterator first1 ,
		BidirectionalIterator last1 ,
		BidirectionalIterator first2 ,
		BidirectionalIterator last2 )
{
	if (( first1 == last1 ) || ( first2 == last2 )) {
		return false;
	}
	BidirectionalIterator m1 = last1 ;
	BidirectionalIterator m2 = last2 ; --m2;
	while (--m1 != first1 && !(* m1 < *m2 )){
	}
	bool result = (m1 == first1 ) && !(* first1 < *m2 );
	if (! result ) {
		while ( first2 != m2 && !(* m1 < * first2 )) {
			++ first2;
		}
		first1 = m1;
		std :: iter_swap(first1 , first2 );
		++ first1;
		++ first2;
	}
	if (( first1 != last1 ) && ( first2 != last2 )) {
		m1 = last1 ; m2 = first2;
		while (( m1 != first1 ) && (m2 != last2 )) {
			std :: iter_swap (--m1 , m2 );
			++ m2;
		}
		std :: reverse(first1 , m1);
		std :: reverse(first1 , last1);
		std :: reverse(m2, last2);
		std :: reverse(first2, last2);
	}
	return ! result;
}

/* next_combination */
	template <class BidirectionalIterator>
bool next_combination (
		BidirectionalIterator first ,
		BidirectionalIterator middle ,
		BidirectionalIterator last )
{
	return next_combination (first , middle , middle , last );
}


/* next_combinationの逆 */
template < class BidirectionalIterator >
	inline
bool prev_combination (
		BidirectionalIterator first,
		BidirectionalIterator middle,
		BidirectionalIterator last)
{
	return next_combination (middle , last , first , middle );
}


int main(){
	const int n = 5, r = 3;
	vector<int> data;

	for(int i=0; i<n; ++i) {
		data.push_back(i);
	}
	do{
		cout << "[ " << data[0];
		for(unsigned int i=1; i<r; ++i){
			cout << ", " << data[i];
		}
		cout << " ]" << std::endl;
	} while(next_combination(data.begin(), data.begin()+r, data.end()) );

	return 0;
}
