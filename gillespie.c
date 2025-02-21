#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gsl/gsl_rng.h>
#include <math.h>
#include "model.h"

int main(int argc, char *argv[]){
	int i,j;
	size_t n = model_initial_counts(NULL);
	size_t m = model_reaction_coefficients(NULL);
	int *x = malloc(sizeof(int)*n);
	double *c = malloc(sizeof(double)*m);
	double *a = malloc(sizeof(double)*m);
	double sum_a;
	double t0 = 0;
	double tf = 10;
	double tau;
	char *name[] = {"A","B","C",NULL};
	if (argc > 1) t0 = strtod(argv[1],NULL);
	if (argc > 2) tf = strtod(argv[2],NULL);
	double t = t0;
	gsl_rng *RNG = gsl_rng_alloc(gsl_rng_ranlxs0);
	gsl_rng_set(RNG,1337);
	double r, r_sum_a, sum_a_j;
	model_initial_counts(x);
	model_reaction_coefficients(c);
	printf("%10s ","t");
	for (i=0;i<n;i++){
		printf("%10s ",name[i]);
	}
	printf("\n");
	fflush(stdout);
	while (t < tf){
		model_propensities(t,x,c,a);
		// 1. calculate sum(a)
		sum_a = 0.0;
		for (i=0;i<m;i++){
			sum_a+=a[i];
		}
		// 2. pick a tau
		r = gsl_rng_uniform(RNG);
		tau = -log(r)/sum_a;
		// 3. pick a reaction to perform:
		r = gsl_rng_uniform(RNG);
		r_sum_a = r*sum_a;
		for (j=0, sum_a_j = 0.0; j<m; j++){
			sum_a_j += a[j];
			if (sum_a_j > r_sum_a) break;
		}
		model_effects(t,x,j);
		t += tau;
		printf("%10f ",t);
		for (i=0;i<n;i++){
			printf("%10i ",x[i]);
		}
		printf("\n");
	}
	gsl_rng_free(RNG);
	return EXIT_SUCCESS;
}
