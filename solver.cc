#include <boost/numeric/odeint.hpp>

typedef std::vector< double > state_type;

// void ball_on_oscillator( const state_type &x , state_type &dxdt , const double /* t */ )
// {
//     dxdt[0] = x[1];
//     dxdt[1] = -x[0] - gam*x[1];
// }


int main(){
	// define the provided constants to be shared among functions
	int m = 1;
	double A = 0.25;
	double T = 2;
	int g = 10;
	int B = 10;
	double C = 2.0;

	// create and populate  initial state vector
	state_type x(6);
	x[0] = 0.0; // value for x
	x[1] = 0.0; //value for y
	x[2] = 10.0; // value for z
	x[3] = 1.0; // value for u
	x[4] = 0.0; //value for v
	x[5] = 0.0; //value for w


	return 0;
}



