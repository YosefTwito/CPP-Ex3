#include "solver.hpp"
#include <iostream>
#include <exception>

using namespace std;
using namespace solver;

double solver:: solve (RealVariable x) {
	if (x.a==0 && x.b==0 && x.c!=0) { throw runtime_error("False equation"); }
    double result=0; 
    double dis = (x.b*x.b)-(4*x.a*x.c);
	
	if (dis < 0 ){ throw runtime_error("There is no real solution"); }
	
    if ( x.a == 0 ) result = (-1*x.c)/x.b;
    
	else{
		dis = sqrt(dis);
		result =(-1*x.b + dis)/(2*x.a);   
    }
	
    return result;
}

RealVariable solver::operator+ (const RealVariable& x , const RealVariable& y){
	return RealVariable(x.a + y.a, x.b + y.b, x.c + y.c);
}
RealVariable solver::operator+ (const RealVariable& x , const double c){
	return RealVariable(x.a , x.b , x.c + c);
}
RealVariable solver::operator+ ( const double c , const RealVariable& x){
	return RealVariable(x.a , x.b , x.c + c);
}

RealVariable solver::operator- (const RealVariable& x , const RealVariable& y){
	return RealVariable(x.a - y.a, x.b - y.b, x.c - y.c);
}
RealVariable solver::operator- (const RealVariable& x , const double c){
	return RealVariable(x.a , x.b , x.c - c);
}
RealVariable solver::operator- ( const double c , const RealVariable& x){
	return RealVariable(-x.a , -x.b , c-x.c);
}
			
RealVariable solver::operator* (const double c , const RealVariable& x){
	return RealVariable(x.a*c , x.b*c , x.c*c);
}
RealVariable solver::operator* (const RealVariable& x , const double c){
	return RealVariable(x.a*c , x.b*c , x.c*c);
}

RealVariable solver::operator/ (const RealVariable& x , const RealVariable& y){
	RealVariable z(x.a, x.b, x.c);
	if (z.a!=0 && y.a!=0) { z.a = 0; z.c+=z.a/y.a; }
	if (z.a!=0 && y.b!=0) { z.a = 0; z.b+=z.a/y.b; }
	if (z.b!=0 && y.b!=0) { z.b = 0; z.c+=z.b/y.b; }
	return z;
}
RealVariable solver::operator/ (const RealVariable& x , const double c){
	if (c==0) throw runtime_error("Can't divide by 0");
	RealVariable z(x.a, x.b, x.c);
	if (x.a!=0) z.a = z.a/c;
	if (x.b!=0) z.b = z.b/c;
	if (x.c!=0) z.c = z.c/c;
	return z;
}
RealVariable solver::operator/ ( const double c , const RealVariable& x){
	RealVariable z(x.a, x.b, x.c);
	if (x.a!=0) z.a = c/z.a;
	if (x.b!=0) z.b = c/z.b;
	if (x.c!=0) z.c = c/z.c;
	return z;
}

RealVariable solver::operator^ (const RealVariable& x , int n){
	if (n==0) return RealVariable(0, 0, 1);
	if (n==1) return x;
	if (n==2) return RealVariable(x.a+(x.b*x.b), 0, x.c);
	else throw runtime_error("Too big Power");
}

RealVariable solver::operator== (const RealVariable& x , const RealVariable& y){
	RealVariable z(x.a, x.b, x.c);
	
	if (y.a!=0) z.a = x.a+(-1*y.a);
	if (y.b!=0) z.b = x.b+(-1*y.b);
	if (y.c!=0) z.c = x.c+(-1*y.c);
	
	return z;
}
RealVariable solver::operator== (const RealVariable& x , const double c){
	RealVariable z(x.a, x.b, x.c);
	z.c+= (-1*c);
	return z;
}
RealVariable solver::operator== ( const double c , const RealVariable& x){
	RealVariable z(x.a, x.b, x.c);
	z.c+= (-1*c);
	return z;
}

/*
*ComplexVariable
*/

complex<double> solver:: solve (ComplexVariable x){
	complex<double> dis = (x.b * x.b) - (complex<double> (4, 0) *x.a*x.c);
	complex<double> ans = 0;
	if (x.a == complex<double> (0,0)){ ans = (-x.c)/x.b; }
	else {
		dis = sqrt(dis);
		ans = ((complex<double>(-1)*x.b)+dis)/(complex<double>(2, 0)*x.a);
	}
	return ans;
}

ComplexVariable solver::operator+ (const ComplexVariable &x , const ComplexVariable &y){
	return ComplexVariable(x.a+y.a, x.b+y.b, x.c+y.c);
}
ComplexVariable solver::operator+ (const ComplexVariable &x , std::complex<double> c){
	return ComplexVariable(x.a, x.b, x.c+c);
}
ComplexVariable solver::operator+ ( std::complex<double> c ,const ComplexVariable &x){
	return ComplexVariable(x.a, x.b, x.c+c);
}
ComplexVariable solver::operator+ (const ComplexVariable &x , double c){
	return ComplexVariable(x.a, x.b, x.c+c);
}
ComplexVariable solver::operator+ ( double c ,const ComplexVariable &x){
	return ComplexVariable(x.a, x.b, x.c+c);
}

ComplexVariable solver::operator- (const ComplexVariable &x , const ComplexVariable &y){
	return ComplexVariable(x.a-y.a, x.b-y.b, x.c-y.c);
}
ComplexVariable solver::operator- (const ComplexVariable &x , std::complex<double> c){
	return ComplexVariable(x.a, x.b, x.c-c);
}
ComplexVariable solver::operator- ( std::complex<double> c ,const ComplexVariable &x){
	return ComplexVariable(-x.a, -x.b, c-x.c);
}
ComplexVariable solver::operator- (const ComplexVariable &x , double c){
	return ComplexVariable(x.a, x.b, x.c-c);
}
ComplexVariable solver::operator- ( double c ,const ComplexVariable &x){
	return ComplexVariable(-x.a, -x.b, c-x.c);
}

/* dont know if neccesary...
ComplexVariable solver::operator* (const ComplexVariable &x , const ComplexVariable &y){
	return ComplexVariable(x.a*y.a, x.b*y.b, x.c*y.c);
}*/
ComplexVariable solver::operator* (const ComplexVariable &x , std::complex<double> c){
	return ComplexVariable(x.a*c, x.b*c, x.c*c);
}
ComplexVariable solver::operator* ( std::complex<double> c ,const ComplexVariable &x){
	return ComplexVariable(x.a*c, x.b*c, x.c*c);
}
ComplexVariable solver::operator* (const ComplexVariable &x , double c){
	return ComplexVariable(x.a*c, x.b*c, x.c*c);
}
ComplexVariable solver::operator* ( double c ,const ComplexVariable &x){
	return ComplexVariable(x.a*c, x.b*c, x.c*c);
}

ComplexVariable solver::operator/ (const ComplexVariable &x , const ComplexVariable &y){
	ComplexVariable z(x.a, x.b, x.c);
	if (z.a != std::complex<double> (0) && y.a != std::complex<double> (0) ){
         z.a =0;
         z.c+= z.a/y.a;
     }
     if (z.a != std::complex<double> (0) && y.b != std::complex<double> (0) ){
         z.a =0;
         z.b+= z.a/y.b;   
     }
     if (z.b != std::complex<double> (0) && y.b != std::complex<double> (0)){
         z.c+= z.b/y.b;
         z.b =0;
     }
     return z;
}
ComplexVariable solver::operator/ (const ComplexVariable &x , std::complex<double> c){
	return ComplexVariable(x.a/c, x.b/c, x.c/c);
}
ComplexVariable solver::operator/ ( std::complex<double> c ,const ComplexVariable &x){
	return ComplexVariable(c/x.a, c/x.b, c/x.c);
}
ComplexVariable solver::operator/ (const ComplexVariable &x , double c){
	return ComplexVariable(x.a/c, x.b/c, x.c/c);
}
ComplexVariable solver::operator/ ( double c ,const ComplexVariable &x){
	return ComplexVariable(c/x.a, c/x.b, c/x.c);
}

ComplexVariable solver::operator^ (const ComplexVariable &x , int n){
	if (n==0) return ComplexVariable();
	if (n==1) return x;
	if (n==2) return ComplexVariable(x.a+(x.b*x.b), 0, x.c);
	else throw runtime_error("Too big Power");
}

ComplexVariable solver::operator== (const ComplexVariable &x ,const  ComplexVariable &y){
	ComplexVariable z(x.a, x.b, x.c);
	if (y.a !=std::complex<double> (0)){ z.a = x.a + (std::complex<double> (-1)*y.a); }
	if (y.b !=std::complex<double> (0)){ z.b = x.b + (std::complex<double> (-1)*y.b); }
	if (y.c !=std::complex<double> (0)){ z.c = x.c + (std::complex<double> (-1)*y.c); }
	return z;
}
ComplexVariable solver::operator== (const ComplexVariable &x , std::complex<double> c){
	ComplexVariable z(x.a, x.b, x.c);
	z.c = x.c + (std::complex<double> (-1)*c);
	return z;
}
ComplexVariable solver::operator== ( std::complex<double> c ,const ComplexVariable &x){
	ComplexVariable z(x.a, x.b, x.c);
	z.c = x.c + (std::complex<double> (-1)*c);
	return z;
}
ComplexVariable solver::operator== (const ComplexVariable &x , double c){
	ComplexVariable z(x.a, x.b, x.c);
	z.c = x.c + (std::complex<double> (-1)*c);
	return z;
}
ComplexVariable solver::operator== ( double c ,const ComplexVariable &x){
	ComplexVariable z(x.a, x.b, x.c);
	z.c = x.c + (std::complex<double> (-1)*c);
	return z;
}
