#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {

	stack<int> s;

	for (int ast : asteroids) {

		if (ast < 0 and !s.empty() and s.top() > 0) {

			// collision will happen

			bool flag = true; // assume 'ast' will destroyed all the positive asteroids on the top of the stack

			while (!s.empty() and s.top() > 0) {

				if (abs(ast) > s.top()) {
					// asteroid at the top of the stack will be destroyed, and we will continue (more collisions are possible)
					s.pop();
				} else if (abs(ast) < s.top()) {
					// 'ast' will be destroyed, we can stop (no more collisions possible)
					flag = false;
					break;
				} else {
					// 'ast' and asteroid on top of the stack are both destroyed, we can stop (no more collisions are possible)
					flag = false;
					s.pop();
					break;
				}

			}

			if (flag == true) {
				s.push(ast);
			}


		} else {

			s.push(ast);

		}

	}

	vector<int> state;

	while (!s.empty()) {
		state.push_back(s.top());
		s.pop();
	}

	reverse(state.begin(), state.end());

	return state;

}

int main() {

	vector<int> asteroids = {7, 3, -4, 5, 2, -8, 2, 4, 1, -4};

	vector<int> state = asteroidCollision(asteroids);

	for (int ast : state) {
		cout << ast << " ";
	}

	cout << endl;

	return 0;
}