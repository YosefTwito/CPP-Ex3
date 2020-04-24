#pragma once
#include <complex>

using namespace std;

namespace solver{
	
	class RealVariable{
		public:
			double x;

		public:
			RealVariable(): x(0){};
	};

	class ComplexVariable{
		public:
			complex<double> c;

		public:
			ComplexVariable(): c(0){};
	};

	double solve();
	
};