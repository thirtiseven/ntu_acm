struct point {
	double x, y;
	point() { };
	point(double x, double y) :x(x), y(y) { } 
	point operator - (const point &b) const { 
		return point(x - b.x, y - b.y);
	}
	point operator + (const point &b) const { 
		return point(x + b.x, y + b.y);
	}
	point operator * (const double k) const { 
		return point(k * x, k * y);
	}
	point operator / (const double k) const { 
		return point(x / k, y / k);
	}
	double slope() { 
		return y / x;
	}
};