#include "model.h"

enum state {_A, _B, _C, numStates};
enum reaction {_R1, _R2, numReactions};

// R1:  A + B -> C
// R2: C -> A + B

/* makes changes to the model according to chosen reaction */
int model_effects(double t, int *x, int j){
	if (!x) return numStates;
	switch(j){
	case _R1:
		x[_A] -= 1;
		x[_B] -= 1;
		x[_C] += 1;
		break;
	case _R2:
		x[_A] += 1;
		x[_B] += 1;
		x[_C] -= 1;
		break;
	}
	return 0;
}

// t: time
// x: counts of molecules
// c: stochastic reaction parameters
// a: propensity of each reaction (output)
int model_propensities(double t, int *x, double *c, double *a){
	if (!x || !a) return numStates;
	a[_R1] = c[_R1]*x[_A]*x[_B];
	a[_R2] = c[_R2]*x[_C];
	return 0;
}

// c: stochastic reaction parameters
int model_reaction_coefficients(double *c){
	if (!c) return numReactions;
	c[_R1] = 2.0;
	c[_R2] = 1.0;
	return 0;
}

// t: time
// x: counts of molecules
// c: stochastic reaction parameters
// a: propensity of each reaction (output)
int model_initial_counts(int *x){
	if (!x) return numStates;
	x[_A] = 100;
	x[_B] = 100;
	x[_C] = 0;
	return 0;
}
