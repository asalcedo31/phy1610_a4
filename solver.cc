#include <boost/numeric/odeint.hpp>
#include <math.h> 

const double pi = 3.14159265358979323846264338327950288;
typedef std::vector< double > state_type;


double z_table(double t){
	double A = 0.25; 
	double T = 2;
	return(A*cos((2*pi*t)/T));
}

double f_table(double z,  double t){
	int B = 10;; 
	double C = 2.0;
	return(B*exp(-C*(z-z_table(t))));
}



struct write_state
{
    void operator()( const state_type &x ) const
    {
        std::cout << x[0] << "\t" << x[1] << "\n";
    }
};


//x is the initial value vector and dpdt is a vector of derivatices 
void ball_on_oscillator( const state_type &x , state_type &dpdt , const double  t )
{
	double g = 10;
	int m = 1;
	double table_f = f_table(x[2],t);
    dpdt[0] = x[3]; //dx/dt = u
    dpdt[1] = x[4]; //dy/dt = v
    dpdt[2] = x[5]; //dz/dt = w
    dpdt[3] = 0; //du/dt = 0
    dpdt[4] = 0; //dv/dt = 0
    dpdt[5] = (table_f-g)/m; //dw/dt = (f_table-f_gravity)/m


}



int main(){
	
	// create and populate  initial state vector
	state_type x(6);
	x[0] = 0.0; // value for x
	x[1] = 0.0; //value for y
	x[2] = 10.0; // value for z
	x[3] = 1.0; // value for u
	x[4] = 0.0; //value for v
	x[5] = 0.0; //value for w

	size_t steps = boost::numeric::odeint::integrate( ball_on_oscillator ,
        x , 0.0 , 10.0 , 0.1 );

	std::cout << steps << std::endl;
	return 0;
}



