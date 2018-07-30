#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates {
public:
    Coordinates() = delete;

	class CHA {
	public:
		CHA(double c, double h, double a) : c_(c), h_(h), a_(a)	{}
		double c() const { return c_; }
		double h() const { return h_; }
		double a() const { return a_; }

	private:
		const double c_;
		const double h_;
		const double a_;
	};

	class Q1Q2Q3 {
	public:
		Q1Q2Q3(double q1, double q2, double q3) : q1_(q1), q2_(q2), q3_(q3)	{}
		double q1() const { return q1_; }
		double q2() const { return q2_; }
		double q3() const { return q3_; }

	private:
		const double q1_;
		const double q2_;
		const double q3_;
	};

	static CHA cha(double c, double h, double a) {
		return CHA(c, h, a);
	}
    static Q1Q2Q3 q1q2q3(double q1, double q2, double q3) {
		return Q1Q2Q3(q1, q2, q3);
	}
};

#endif // COORDINATES_H
