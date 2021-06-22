#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 학생들의점수를가지고있는구조체
struct Score
{
       string name;
       int korean;
       int english;
       int math;
       // 출력연산자오버로드. 꼭이렇게할필요는없는데
       // 이방법이좀편리함
       friend ostream& operator <<(ostream& os, const Score& score);
};
// 두개의Score 에대한대소비교함수
// 정렬할때이함수를사용할것임
// 방법은마음대로정해도됨
bool predicate(const Score& s1, const Score& s2)
{
       // 이름으로비교
       return ( s1.name < s2.name );
}
// 벡터내의모든요소를출력
void ShowAll(const vector<Score>& v);

int main()
{
       vector<Score> v;
       Score score;
       int i;
       // 세명의점수를읽어들인다
       for ( i = 0; i < 3; ++i )
       {
             cout << "이름: "; cin >> score.name;
             cout << "국어: "; cin >> score.korean;
             cout << "영어: "; cin >> score.english;
             cout << "수학: "; cin >> score.math;
             v.push_back(score);
       }
       // 입력된값들을전부출력해본다
       ShowAll(v);
       // 벡터내의데이타정렬
       // 여기서는이름순으로정렬
       sort(v.begin(), v.end(), predicate);
       ShowAll(v);

       return 0;
}

void ShowAll(const vector<Score>& v)
{
       // 출력연산자가오버로드되어있기때문에벡터의내용을
       // 쉽게출력가능함
       copy(v.begin(), v.end(), ostream_iterator<Score>(cout, "\n"));
}

ostream& operator <<(ostream& os, const Score& score)
{
       os << "이름: " << score.name << ", 국어: " << score.korean << ", 영어: "
             << score.english << ", 수학: " << score.math;

       return os;
}