#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_vector.h>
#include <math.h>
#include "model.h"

int pick_reaction(gsl_vector *a, double r_sum_a){
	int j;
	size_t m=a->size;
	double psum = 0.0;
	for (j=0; j<m; j++){
		psum += gsl_vector_get(a,j);
		if (psum > r_sum_a) break;
	}
	return j;
}

void print_counts(double t, gsl_vector_int *x){
	printf("%10f ",t);
	size_t n = x->size;
	int i;
	for (i=0;i<n;i++){
		printf("%10i ",x->data[i]);
	}
	printf("\n");
}

void advance(double *t, gsl_vector_int *x, gsl_vector *c, gsl_vector *a, gsl_rng *RNG){
	double tau;
	double r;
	double sum_a;
	int j;
	model_propensities(*t,x->data,c->data,a->data);
	// 1. calculate sum(a)
	sum_a = gsl_vector_sum(a);
	// 2. pick a tau
	r = gsl_rng_uniform(RNG);
	tau = -log(r)/sum_a;
	// 3. pick a reaction to perform:
	r = gsl_rng_uniform(RNG);
	j = pick_reaction(a,r*sum_a);
	model_effects(*t,x->data,j);
	*t += tau;
}

int main(int argc, char *argv[]){
	int i,j;
	size_t n = model_initial_counts(NULL);
	size_t m = model_reaction_coefficients(NULL);
	gsl_vector_int *x = gsl_vector_int_alloc(n);
	gsl_vector *c = gsl_vector_alloc(m);
	gsl_vector *a = gsl_vector_alloc(m);
	double sum_a;
	double t0 = 0;
	double tf = 10;
	char *name[] = {"A","B","C",NULL};
	size_t l=64;
	ssize_t r;
	char *line = malloc(l);
	if (argc == 2) tf = strtod(argv[1],NULL);
	if (argc > 2) {
		t0 = strtod(argv[1],NULL);
		tf = strtod(argv[2],NULL);
	}
	double t = t0;
	gsl_rng *RNG = gsl_rng_alloc(gsl_rng_ranlxs0);
	gsl_rng_set(RNG,1337);
	model_initial_counts(x->data);
	model_reaction_coefficients(c->data);
	/*for (j=0;j<c->size;j++){
		if ((r=getline(&line,&l,stdin))>=0){
			gsl_vector_set(c,j,strtod(line,NULL));
		} else {
			break;
		}
		}*/
	putchar('#');
	printf("%9s ","t");
	for (i=0;i<n;i++){
		printf("%10s ",name[i]);
	}
	printf("\n");
	print_counts(t,x); /* print initial values */
	/* main solver loop: */
	while (t < tf){
		advance(&t,x,c,a,RNG);
		print_counts(t,x);
	}
	gsl_rng_free(RNG);
	free(line);
	return EXIT_SUCCESS;
}
