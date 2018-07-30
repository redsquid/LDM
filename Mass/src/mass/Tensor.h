#ifndef TENSOR_H
#define TENSOR_H

class Tensor {
public:
	Tensor(double _cc, double _hh, double _aa, double _ca, double _ch, double _ha) :
		cc_(_cc),
		hh_(_hh),
		aa_(_aa),
		ca_(_ca),
		ch_(_ch),
		ha_(_ha)
	{
	}

	virtual ~Tensor() {}

	double cc() const { return cc_; }
	double hh() const { return hh_; }
	double aa() const { return aa_; }
	
	double ch() const { return ch_; }
	double ca() const { return ca_; }
	double ha() const { return ha_; }

private:
	const double cc_;
	const double hh_;
	const double aa_;
	const double ca_;
	const double ch_;
	const double ha_;

};

#endif //TENSOR_H

