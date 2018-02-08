#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
double x, y, width, height, res = 0;
struct P {
	double x1, y1, x2, y2;
	P() {}
	P(double _x1, double _y1, double _x2, double _y2) : x1(_x1),y1(_y1),x2(_x2),y2(_y2){}
};
int main() {
	scanf("%d", &n);
	vector<double> x, y;
	vector<P> z;
	for (int i = 0; i < n; i++) {
		double a, b, c, d;
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		x.push_back(a);
		x.push_back(a + c);
		y.push_back(b);
		y.push_back(b + d);
		z.push_back(P(a, b, a+c, b+d));
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	for (int i = 0; i < (int)x.size(); i++) {
		for (int j = 0; j < (int)y.size(); j++) {
			for (int t = 0; t < (int)z.size(); t++) {
				if (x[i] < z[t].x2 &&
					x[i + 1] > z[t].x1 &&
					y[j] < z[t].y2 &&
					y[j + 1] > z[t].y1) {

					res += (x[i + 1] - x[i]) * (y[j + 1] - y[j]);
					break;
				}
			}
		}
	}

	if ((long long)res == res) printf("%0.f", res);
	else printf("%.2lf", res);
}
