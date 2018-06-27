#include <list>
#include <iostream>
namespace hsc {
	using namespace std;
	struct Puntaje {
		int _points;
		string _name;
		bool operator<(const Puntaje &rhs) const { 
			return  _points > rhs._points; 
		}
	};
	class HighScore {
		list<Puntaje>* _Scores;
	public:
		HighScore() 
		:_Scores( new list<Puntaje>())
		{ }
		~HighScore() {
			delete _Scores;
		}
		void maxScore(int &_points, string &_name);
		void minScore(int &_points, string &_name);
		bool addScore(int _points, string _name);
		list<int>* getScore();
		list<string>* getName();
	};
}