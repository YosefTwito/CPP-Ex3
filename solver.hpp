#pragma once
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <complex>

using namespace std;

namespace solver{
	
	class RealVariable{
		public:
			double a, b, c;

			RealVariable(): a(0), b(1), c(0){};
			RealVariable(double a, double b, double c): a(a), b(b), c(c){};
			
			friend RealVariable operator+ (const RealVariable& x , const RealVariable& y);
			friend RealVariable operator+ (const RealVariable& x , const double c);
			friend RealVariable operator+ ( const double c , const RealVariable& x);
			
			friend RealVariable operator- (const RealVariable& x , const RealVariable& y);
			friend RealVariable operator- (const RealVariable& x , const double c);
			friend RealVariable operator- ( const double c , const RealVariable& x);
			
			friend RealVariable operator* (const double c , const RealVariable& x);
			friend RealVariable operator* (const RealVariable& x , const double c);

			friend RealVariable operator/ (const RealVariable& x , const RealVariable& y);
			friend RealVariable operator/ (const RealVariable& x , const double c);
			friend RealVariable operator/ ( const double c , const RealVariable& x);

			friend RealVariable operator^ (const RealVariable& x , int c);

			friend RealVariable operator== (const RealVariable& x , const RealVariable& y);
			friend RealVariable operator== (const RealVariable& x , const double c);
			friend RealVariable operator== ( const double c , const RealVariable& x);
	};

	class ComplexVariable{
		public:
			complex<double> a, b, c;

			ComplexVariable(): a(0), b(1), c(0){};
			ComplexVariable(complex<double> a, complex<double> b, complex<double> c): a(a), b(b), c(c){};
	
			friend ComplexVariable operator+ (const ComplexVariable &x , const ComplexVariable &y);
			friend ComplexVariable operator+ (const ComplexVariable &x , std::complex<double> c);
			friend ComplexVariable operator+ ( std::complex<double> c ,const ComplexVariable &x);
			friend ComplexVariable operator+ (const ComplexVariable &x , double c);
			friend ComplexVariable operator+ ( double c ,const ComplexVariable &x);

			friend ComplexVariable operator- (const ComplexVariable &x , const ComplexVariable &y);
			friend ComplexVariable operator- (const ComplexVariable &x , std::complex<double> c);
			friend ComplexVariable operator- ( std::complex<double> c ,const ComplexVariable &x);
			friend ComplexVariable operator- (const ComplexVariable &x , double c);
			friend ComplexVariable operator- ( double c ,const ComplexVariable &x);

			friend ComplexVariable operator* (const ComplexVariable &x , std::complex<double> c);
			friend ComplexVariable operator* ( std::complex<double> c ,const ComplexVariable &x);
			friend ComplexVariable operator* (const ComplexVariable &x , double c);
			friend ComplexVariable operator* ( double c ,const ComplexVariable &x);

			friend ComplexVariable operator/ (const ComplexVariable &x , const ComplexVariable &y);
			friend ComplexVariable operator/ (const ComplexVariable &x , std::complex<double> c);
			friend ComplexVariable operator/ ( std::complex<double> c ,const ComplexVariable &x);
			friend ComplexVariable operator/ (const ComplexVariable &x , double c);
			friend ComplexVariable operator/ ( double c ,const ComplexVariable &x);

			friend ComplexVariable operator^ (const ComplexVariable &x , int c);

			friend ComplexVariable operator== (const ComplexVariable &x ,const  ComplexVariable &y);
			friend ComplexVariable operator== (const ComplexVariable &x , std::complex<double> c);
			friend ComplexVariable operator== ( std::complex<double> c ,const ComplexVariable &x);
			friend ComplexVariable operator== (const ComplexVariable &x , double c);
			friend ComplexVariable operator== ( double c ,const ComplexVariable &x);
	};

	double solve (RealVariable x);
	complex<double> solve (ComplexVariable x);	
};