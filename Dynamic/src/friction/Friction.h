#include <string>
#include <cstdlib>


class Friction {
public:
	Friction() = delete;
	virtual ~Friction() = delete;

	static void init(std::string path);

	/**
	 *   i,j = 0, 1, 2 (0 - q1, 1 - q2, 2 - q3)
	 */
	static double get(uint i, uint j, double q1, double q2, double q3);



};

