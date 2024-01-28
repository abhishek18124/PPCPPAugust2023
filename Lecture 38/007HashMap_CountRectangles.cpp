/*
	Given N cartesian points in a 2D plane, count the number of axis parallel rectangles that
	can be formed.

	Example

	Input : {(0, 0), (0, 1), (1, 1), (1, 0), (2, 1), (2, 0), (3, 1), (3, 0)}
	Output: 6

*/

#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	bool operator==(Point other) const {
		return x == other.x && y == other.y;
	}
};

class PointCompare {
public :

	bool operator()(Point p1, Point p2) const {
		if (p1.x == p2.x) {
			return p1.y < p2.y;
		}
		return p1.x < p2.x;
	}

};

class PointHash {

public :

	size_t operator()(Point p) const {

		int x_coor = p.x;
		int y_coor = p.y;

		hash<int> integerHasher;

		return integerHasher(x_coor) ^ integerHasher(y_coor);

	}

};

int main() {

	vector<Point> points{Point(1, 1),
	                     Point(1, 2),
	                     Point(2, 1),
	                     Point(2, 2),
	                     Point(3, 1),
	                     Point(3, 2)};

	set<Point, PointCompare> us(points.begin(), points.end());

	// unordered_set<Point, PointHash> us(points.begin(), points.end());

	// for (Point p : points) {
	// 	us.insert(p);
	// }

	int cnt = 0;
	for (int i = 0; i < points.size() - 1; i++) {
		Point p1 = points[i];
		for (int j = i + 1; j < points.size(); j++) {
			Point p2 = points[j];
			if (p1.x != p2.x && p1.y != p2.y) {
				// p1 and p2 can form a pivot
				Point p3 = Point(p1.x, p2.y);
				Point p4 = Point(p2.x, p1.y);
				// check whether points 'p3' and 'p4' are present in the
				// 2D plane or not
				if (us.find(p3) != us.end() & us.find(p4) != us.end()) {
					cnt++;
				}
			}
		}
	}

	cout << "count : " << cnt / 2 << endl;

	return 0;
}