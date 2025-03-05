#include <stdlib.h>
#include <math.h>
enum state {_Rii, _cAMP, _RiiP, _Rii_C, _RiiP_cAMP, _RiiP_C, _RiiP_C_cAMP, _C, _Rii_cAMP, _Rii_C_cAMP, _CaN, _RiiP_CaN, _RiiP_cAMP_CaN, _AKAR4, _AKAR4_C, _AKAR4p, numStateVariables};
enum parameter {_kf_Rii_C__RiiP_C, _kf_RiiP_CxcAMP__RiiP_C_cAMP, _kf_RiiP_cAMPxC__RiiP_C_cAMP, _kb_RiiP_cAMPxC__RiiP_C_cAMP, _kb_RiiPXcAMP__RiiP_cAMP, _kf_RiiPXcAMP__RiiP_cAMP, _kf_RiiPxC__RiiP_C, _kb_RiiPxC__RiiP_C, _kf_cAMPxRii__Rii_cAMP, _kb_cAMPxRii__Rii_cAMP, _kf_Rii_CxcAMP__Rii_C_cAMP, _kb_Rii_CxcAMP__Rii_C_cAMP, _kf_RiixC__Rii_C, _kf_Rii_cAMPxC__Rii_C_cAMP, _kb_Rii_cAMPxC__Rii_C_cAMP, _kf_Rii_C_cAMP__RiiP_C_cAMP, _kb_RiixC__Rii_C, _AKAPoff_1, _AKAPoff_3, _AKAPon_1, _AKAPon_3, _kf_C_AKAR4, _kb_C_AKAR4, _kcat_AKARp, _kmOFF, _kmON, _KD_T, _b_AKAP, numParameters};
enum reaction {_reaction_51_fwd, _reaction_14_fwd, _reaction_12_fwd, _reaction_43_fwd, _reaction_23_fwd, _reaction_78_fwd, _reaction_56_fwd, _reaction_76_fwd, _reaction_62_fwd, _reaction_58_fwd, _reaction_44_fwd, _reaction_33_fwd, _reaction_48_fwd, _reaction_37_fwd, _reaction_1_fwd, _reaction_2_fwd, _reaction_51_bwd, _reaction_14_bwd, _reaction_12_bwd, _reaction_43_bwd, _reaction_23_bwd, _reaction_78_bwd, _reaction_56_bwd, _reaction_76_bwd, _reaction_62_bwd, _reaction_58_bwd, _reaction_44_bwd, _reaction_33_bwd, _reaction_48_bwd, _reaction_37_bwd, _reaction_1_bwd, _reaction_2_bwd, numReactions};
enum outputFunctions {_AKAR4pOUT, numFunctions};
int model_effects(double t, int *x, int j){
	if (!x) return numStateVariables;
	switch(j){
	case _reaction_51_fwd:
		x[_Rii_C] -= 1;
		x[_RiiP_C] += 1;
		break;
	case _reaction_14_fwd:
		x[_RiiP] -= 1;
		x[_C] -= 1;
		x[_RiiP_C] += 1;
		break;
	case _reaction_12_fwd:
		x[_RiiP_C] -= 1;
		x[_cAMP] -= 1;
		x[_RiiP_C_cAMP] += 1;
		break;
	case _reaction_43_fwd:
		x[_cAMP] -= 1;
		x[_RiiP] -= 1;
		x[_RiiP_cAMP] += 1;
		break;
	case _reaction_23_fwd:
		x[_RiiP_cAMP] -= 1;
		x[_C] -= 1;
		x[_RiiP_C_cAMP] += 1;
		break;
	case _reaction_78_fwd:
		x[_cAMP] -= 1;
		x[_Rii] -= 1;
		x[_Rii_cAMP] += 1;
		break;
	case _reaction_56_fwd:
		x[_Rii_C] -= 1;
		x[_cAMP] -= 1;
		x[_Rii_C_cAMP] += 1;
		break;
	case _reaction_76_fwd:
		x[_Rii_cAMP] -= 1;
		x[_C] -= 1;
		x[_Rii_C_cAMP] += 1;
		break;
	case _reaction_62_fwd:
		x[_Rii_C_cAMP] -= 1;
		x[_RiiP_C_cAMP] += 1;
		break;
	case _reaction_58_fwd:
		x[_Rii] -= 1;
		x[_C] -= 1;
		x[_Rii_C] += 1;
		break;
	case _reaction_44_fwd:
		x[_RiiP] -= 1;
		x[_CaN] -= 1;
		x[_RiiP_CaN] += 1;
		break;
	case _reaction_33_fwd:
		x[_CaN] -= 1;
		x[_RiiP_cAMP] -= 1;
		x[_RiiP_cAMP_CaN] += 1;
		break;
	case _reaction_48_fwd:
		x[_RiiP_CaN] -= 1;
		x[_Rii] += 1;
		x[_CaN] += 1;
		break;
	case _reaction_37_fwd:
		x[_RiiP_cAMP_CaN] -= 1;
		x[_CaN] += 1;
		x[_Rii_cAMP] += 1;
		break;
	case _reaction_1_fwd:
		x[_C] -= 1;
		x[_AKAR4] -= 1;
		x[_AKAR4_C] += 1;
		break;
	case _reaction_2_fwd:
		x[_AKAR4_C] -= 1;
		x[_AKAR4p] += 1;
		x[_C] += 1;
		break;
	case _reaction_51_bwd:
		x[_RiiP_C] -= 1;
		x[_Rii_C] += 1;
		break;
	case _reaction_14_bwd:
		x[_RiiP_C] -= 1;
		x[_RiiP] += 1;
		x[_C] += 1;
		break;
	case _reaction_12_bwd:
		x[_RiiP_C_cAMP] -= 1;
		x[_RiiP_C] += 1;
		x[_cAMP] += 1;
		break;
	case _reaction_43_bwd:
		x[_RiiP_cAMP] -= 1;
		x[_cAMP] += 1;
		x[_RiiP] += 1;
		break;
	case _reaction_23_bwd:
		x[_RiiP_C_cAMP] -= 1;
		x[_RiiP_cAMP] += 1;
		x[_C] += 1;
		break;
	case _reaction_78_bwd:
		x[_Rii_cAMP] -= 1;
		x[_cAMP] += 1;
		x[_Rii] += 1;
		break;
	case _reaction_56_bwd:
		x[_Rii_C_cAMP] -= 1;
		x[_Rii_C] += 1;
		x[_cAMP] += 1;
		break;
	case _reaction_76_bwd:
		x[_Rii_C_cAMP] -= 1;
		x[_Rii_cAMP] += 1;
		x[_C] += 1;
		break;
	case _reaction_62_bwd:
		x[_RiiP_C_cAMP] -= 1;
		x[_Rii_C_cAMP] += 1;
		break;
	case _reaction_58_bwd:
		x[_Rii_C] -= 1;
		x[_Rii] += 1;
		x[_C] += 1;
		break;
	case _reaction_44_bwd:
		x[_RiiP_CaN] -= 1;
		x[_RiiP] += 1;
		x[_CaN] += 1;
		break;
	case _reaction_33_bwd:
		x[_RiiP_cAMP_CaN] -= 1;
		x[_CaN] += 1;
		x[_RiiP_cAMP] += 1;
		break;
	case _reaction_48_bwd:
		x[_Rii] -= 1;
		x[_CaN] -= 1;
		x[_RiiP_CaN] += 1;
		break;
	case _reaction_37_bwd:
		x[_CaN] -= 1;
		x[_Rii_cAMP] -= 1;
		x[_RiiP_cAMP_CaN] += 1;
		break;
	case _reaction_1_bwd:
		x[_AKAR4_C] -= 1;
		x[_C] += 1;
		x[_AKAR4] += 1;
		break;
	case _reaction_2_bwd:
		x[_AKAR4p] -= 1;
		x[_C] -= 1;
		x[_AKAR4_C] += 1;
		break;
	}
	return 0;
}
int model_propensities(double t, int *x, double *c, double *a){
	if (!x || !a) return numReactions;
	/* forward parameters */
	double kf_Rii_C__RiiP_C = 1 * c[_kf_Rii_C__RiiP_C]; // per second
	double kf_RiiP_CxcAMP__RiiP_C_cAMP = 0.00166054 * c[_kf_RiiP_CxcAMP__RiiP_C_cAMP]; // per second
	double kf_RiiP_cAMPxC__RiiP_C_cAMP = 0.00166054 * c[_kf_RiiP_cAMPxC__RiiP_C_cAMP]; // per second
	double kf_RiiPXcAMP__RiiP_cAMP = 0.00166054 * c[_kf_RiiPXcAMP__RiiP_cAMP]; // per second
	double kf_RiiPxC__RiiP_C = 0.00166054 * c[_kf_RiiPxC__RiiP_C]; // per second
	double kf_cAMPxRii__Rii_cAMP = 0.00166054 * c[_kf_cAMPxRii__Rii_cAMP]; // per second
	double kf_Rii_CxcAMP__Rii_C_cAMP = 0.00166054 * c[_kf_Rii_CxcAMP__Rii_C_cAMP]; // per second
	double kf_RiixC__Rii_C = 0.00166054 * c[_kf_RiixC__Rii_C]; // per second
	double kf_Rii_cAMPxC__Rii_C_cAMP = 0.00166054 * c[_kf_Rii_cAMPxC__Rii_C_cAMP]; // per second
	double kf_Rii_C_cAMP__RiiP_C_cAMP = 1 * c[_kf_Rii_C_cAMP__RiiP_C_cAMP]; // per second
	double kf_C_AKAR4 = 0.00166054 * c[_kf_C_AKAR4]; // per second
	double kcat_AKARp = 1 * c[_kcat_AKARp]; // per second
	/* backward parameters */
	double kb_RiiP_cAMPxC__RiiP_C_cAMP = 1 * c[_kb_RiiP_cAMPxC__RiiP_C_cAMP]; // per second
	double kb_RiiPXcAMP__RiiP_cAMP = 1 * c[_kb_RiiPXcAMP__RiiP_cAMP]; // per second
	double kb_RiiPxC__RiiP_C = 1 * c[_kb_RiiPxC__RiiP_C]; // per second
	double kb_cAMPxRii__Rii_cAMP = 1 * c[_kb_cAMPxRii__Rii_cAMP]; // per second
	double kb_Rii_CxcAMP__Rii_C_cAMP = 1 * c[_kb_Rii_CxcAMP__Rii_C_cAMP]; // per second
	double kb_Rii_cAMPxC__Rii_C_cAMP = 1 * c[_kb_Rii_cAMPxC__Rii_C_cAMP]; // per second
	double kb_RiixC__Rii_C = 1 * c[_kb_RiixC__Rii_C]; // per second
	double kb_C_AKAR4 = 1 * c[_kb_C_AKAR4]; // per second
	/* parameters that do not appear in kinetric laws */
	double AKAPoff_1 = 1 * c[_AKAPoff_1]; // per second
	double AKAPoff_3 = 1 * c[_AKAPoff_3]; // per second
	double AKAPon_1 = 1 * c[_AKAPon_1]; // per second
	double AKAPon_3 = 1 * c[_AKAPon_3]; // per second
	double kmOFF = 602.214 * c[_kmOFF]; // per second
	double kmON = 602.214 * c[_kmON]; // per second
	double KD_T = 602.214 * c[_KD_T]; // per second
	double b_AKAP = 1 * c[_b_AKAP]; // per second
	/*state variables */
	double Rii = x[_Rii];
	double cAMP = x[_cAMP];
	double RiiP = x[_RiiP];
	double Rii_C = x[_Rii_C];
	double RiiP_cAMP = x[_RiiP_cAMP];
	double RiiP_C = x[_RiiP_C];
	double RiiP_C_cAMP = x[_RiiP_C_cAMP];
	double C = x[_C];
	double Rii_cAMP = x[_Rii_cAMP];
	double Rii_C_cAMP = x[_Rii_C_cAMP];
	double CaN = x[_CaN];
	double RiiP_CaN = x[_RiiP_CaN];
	double RiiP_cAMP_CaN = x[_RiiP_cAMP_CaN];
	double AKAR4 = x[_AKAR4];
	double AKAR4_C = x[_AKAR4_C];
	double AKAR4p = x[_AKAR4p];
	double kf_RiiP_cAMP_CaN__CaNXRii_cAMP = b_AKAP * AKAPon_1 + (1 - b_AKAP) * AKAPoff_1;
	double kb_RiiPxCaN__RiiP_CaN = b_AKAP*AKAPon_3  +  (1 - b_AKAP)* AKAPoff_3;
	double kf_RiiP_CaN__RiixCaN = b_AKAP * AKAPon_1 + (1 - b_AKAP) * AKAPoff_1;
	double kb_CaNxRiiP_cAMP__RiiP_cAMP_CaN = b_AKAP*AKAPon_3  +  (1 - b_AKAP)* AKAPoff_3;
	double kf_RiiPxCaN__RiiP_CaN = b_AKAP * ((kb_RiiPxCaN__RiiP_CaN + kf_RiiP_cAMP_CaN__CaNXRii_cAMP)/kmON ) + (1 - b_AKAP) * (kb_RiiPxCaN__RiiP_CaN + kf_RiiP_cAMP_CaN__CaNXRii_cAMP) / kmOFF;
	double kf_CaNxRiiP_cAMP__RiiP_cAMP_CaN = b_AKAP * ((kb_CaNxRiiP_cAMP__RiiP_cAMP_CaN + kf_RiiP_CaN__RiixCaN)/kmON) + (1 - b_AKAP) * (kb_CaNxRiiP_cAMP__RiiP_cAMP_CaN + kf_RiiP_CaN__RiixCaN)/kmOFF;
	double kb_RiiP_CxcAMP__RiiP_C_cAMP = kf_RiiP_CxcAMP__RiiP_C_cAMP * KD_T;
	a[_reaction_51_fwd] = kf_Rii_C__RiiP_C*Rii_C;
	a[_reaction_14_fwd] = kf_RiiPxC__RiiP_C*RiiP*C;
	a[_reaction_12_fwd] = kf_RiiP_CxcAMP__RiiP_C_cAMP*RiiP_C*cAMP;
	a[_reaction_43_fwd] = kf_RiiPXcAMP__RiiP_cAMP*cAMP*RiiP;
	a[_reaction_23_fwd] = kf_RiiP_cAMPxC__RiiP_C_cAMP*RiiP_cAMP*C;
	a[_reaction_78_fwd] = kf_cAMPxRii__Rii_cAMP*cAMP*Rii;
	a[_reaction_56_fwd] = kf_Rii_CxcAMP__Rii_C_cAMP*Rii_C*cAMP;
	a[_reaction_76_fwd] = kf_Rii_cAMPxC__Rii_C_cAMP*Rii_cAMP*C;
	a[_reaction_62_fwd] = kf_Rii_C_cAMP__RiiP_C_cAMP*Rii_C_cAMP;
	a[_reaction_58_fwd] = kf_RiixC__Rii_C*Rii*C;
	a[_reaction_44_fwd] = kf_RiiPxCaN__RiiP_CaN*RiiP*CaN;
	a[_reaction_33_fwd] = kf_CaNxRiiP_cAMP__RiiP_cAMP_CaN*CaN*RiiP_cAMP;
	a[_reaction_48_fwd] = kf_RiiP_CaN__RiixCaN*RiiP_CaN;
	a[_reaction_37_fwd] = kf_RiiP_cAMP_CaN__CaNXRii_cAMP*RiiP_cAMP_CaN;
	a[_reaction_1_fwd] = kf_C_AKAR4*C*AKAR4;
	a[_reaction_2_fwd] = kcat_AKARp*AKAR4_C;
	a[_reaction_51_bwd] = 0.0;
	a[_reaction_14_bwd] = kb_RiiPxC__RiiP_C*RiiP_C;
	a[_reaction_12_bwd] = kb_RiiP_CxcAMP__RiiP_C_cAMP*RiiP_C_cAMP;
	a[_reaction_43_bwd] = kb_RiiPXcAMP__RiiP_cAMP*RiiP_cAMP;
	a[_reaction_23_bwd] = kb_RiiP_cAMPxC__RiiP_C_cAMP*RiiP_C_cAMP;
	a[_reaction_78_bwd] = kb_cAMPxRii__Rii_cAMP*Rii_cAMP;
	a[_reaction_56_bwd] = kb_Rii_CxcAMP__Rii_C_cAMP*Rii_C_cAMP;
	a[_reaction_76_bwd] = kb_Rii_cAMPxC__Rii_C_cAMP*Rii_C_cAMP;
	a[_reaction_62_bwd] = 0.0;
	a[_reaction_58_bwd] = kb_RiixC__Rii_C*Rii_C;
	a[_reaction_44_bwd] = kb_RiiPxCaN__RiiP_CaN*RiiP_CaN;
	a[_reaction_33_bwd] = kb_CaNxRiiP_cAMP__RiiP_cAMP_CaN*RiiP_cAMP_CaN;
	a[_reaction_48_bwd] = 0.0;
	a[_reaction_37_bwd] = 0.0;
	a[_reaction_1_bwd] = kb_C_AKAR4*AKAR4_C;
	a[_reaction_2_bwd] = 0.0;
	return 0;
}
int model_reaction_coefficients(double *c){
	if (!c) return numParameters;
	c[_kf_Rii_C__RiiP_C] = 33;
	c[_kf_RiiP_CxcAMP__RiiP_C_cAMP] = 0.496;
	c[_kf_RiiP_cAMPxC__RiiP_C_cAMP] = 0.00545;
	c[_kb_RiiP_cAMPxC__RiiP_C_cAMP] = 0.0156;
	c[_kb_RiiPXcAMP__RiiP_cAMP] = 0.0016;
	c[_kf_RiiPXcAMP__RiiP_cAMP] = 0.015;
	c[_kf_RiiPxC__RiiP_C] = 0.038;
	c[_kb_RiiPxC__RiiP_C] = 0.0026;
	c[_kf_cAMPxRii__Rii_cAMP] = 0.015;
	c[_kb_cAMPxRii__Rii_cAMP] = 0.0016;
	c[_kf_Rii_CxcAMP__Rii_C_cAMP] = 0.496;
	c[_kb_Rii_CxcAMP__Rii_C_cAMP] = 1.413;
	c[_kf_RiixC__Rii_C] = 2.1;
	c[_kf_Rii_cAMPxC__Rii_C_cAMP] = 0.2984;
	c[_kb_Rii_cAMPxC__Rii_C_cAMP] = 0.018;
	c[_kf_Rii_C_cAMP__RiiP_C_cAMP] = 33;
	c[_kb_RiixC__Rii_C] = 3e-04;
	c[_AKAPoff_1] = 2.6;
	c[_AKAPoff_3] = 20;
	c[_AKAPon_1] = 0.45;
	c[_AKAPon_3] = 2;
	c[_kf_C_AKAR4] = 0.018;
	c[_kb_C_AKAR4] = 0.106;
	c[_kcat_AKARp] = 10.2;
	c[_kmOFF] = 100;
	c[_kmON] = 1;
	c[_KD_T] = 0.7;
	c[_b_AKAP] = 0;
	return 0;
}
int model_initial_counts(int *x){
	if(!x) return numStateVariables;
	x[_Rii] = 3794; // 3793.95
	x[_cAMP] = 0; // 0
	x[_RiiP] = 0; // 0
	x[_Rii_C] = 379; // 379.395
	x[_RiiP_cAMP] = 0; // 0
	x[_RiiP_C] = 0; // 0
	x[_RiiP_C_cAMP] = 0; // 0
	x[_C] = 0; // 0
	x[_Rii_cAMP] = 0; // 0
	x[_Rii_C_cAMP] = 0; // 0
	x[_CaN] = 903; // 903.321
	x[_RiiP_CaN] = 0; // 0
	x[_RiiP_cAMP_CaN] = 0; // 0
	x[_AKAR4] = 120; // 120.443
	x[_AKAR4_C] = 0; // 0
	x[_AKAR4p] = 0; // 0
	return 0;
}
int model_func(double t, int *x, double *c, double *func){
	if(!func) return numFunctions;
	/* forward parameters */
	double kf_Rii_C__RiiP_C = 1 * c[_kf_Rii_C__RiiP_C]; // per second
	double kf_RiiP_CxcAMP__RiiP_C_cAMP = 0.00166054 * c[_kf_RiiP_CxcAMP__RiiP_C_cAMP]; // per second
	double kf_RiiP_cAMPxC__RiiP_C_cAMP = 0.00166054 * c[_kf_RiiP_cAMPxC__RiiP_C_cAMP]; // per second
	double kf_RiiPXcAMP__RiiP_cAMP = 0.00166054 * c[_kf_RiiPXcAMP__RiiP_cAMP]; // per second
	double kf_RiiPxC__RiiP_C = 0.00166054 * c[_kf_RiiPxC__RiiP_C]; // per second
	double kf_cAMPxRii__Rii_cAMP = 0.00166054 * c[_kf_cAMPxRii__Rii_cAMP]; // per second
	double kf_Rii_CxcAMP__Rii_C_cAMP = 0.00166054 * c[_kf_Rii_CxcAMP__Rii_C_cAMP]; // per second
	double kf_RiixC__Rii_C = 0.00166054 * c[_kf_RiixC__Rii_C]; // per second
	double kf_Rii_cAMPxC__Rii_C_cAMP = 0.00166054 * c[_kf_Rii_cAMPxC__Rii_C_cAMP]; // per second
	double kf_Rii_C_cAMP__RiiP_C_cAMP = 1 * c[_kf_Rii_C_cAMP__RiiP_C_cAMP]; // per second
	double kf_C_AKAR4 = 0.00166054 * c[_kf_C_AKAR4]; // per second
	double kcat_AKARp = 1 * c[_kcat_AKARp]; // per second
	/* backward parameters */
	double kb_RiiP_cAMPxC__RiiP_C_cAMP = 1 * c[_kb_RiiP_cAMPxC__RiiP_C_cAMP]; // per second
	double kb_RiiPXcAMP__RiiP_cAMP = 1 * c[_kb_RiiPXcAMP__RiiP_cAMP]; // per second
	double kb_RiiPxC__RiiP_C = 1 * c[_kb_RiiPxC__RiiP_C]; // per second
	double kb_cAMPxRii__Rii_cAMP = 1 * c[_kb_cAMPxRii__Rii_cAMP]; // per second
	double kb_Rii_CxcAMP__Rii_C_cAMP = 1 * c[_kb_Rii_CxcAMP__Rii_C_cAMP]; // per second
	double kb_Rii_cAMPxC__Rii_C_cAMP = 1 * c[_kb_Rii_cAMPxC__Rii_C_cAMP]; // per second
	double kb_RiixC__Rii_C = 1 * c[_kb_RiixC__Rii_C]; // per second
	double kb_C_AKAR4 = 1 * c[_kb_C_AKAR4]; // per second
	/* parameters that do not appear in kinetric laws */
	double AKAPoff_1 = 1 * c[_AKAPoff_1]; // per second
	double AKAPoff_3 = 1 * c[_AKAPoff_3]; // per second
	double AKAPon_1 = 1 * c[_AKAPon_1]; // per second
	double AKAPon_3 = 1 * c[_AKAPon_3]; // per second
	double kmOFF = 602.214 * c[_kmOFF]; // per second
	double kmON = 602.214 * c[_kmON]; // per second
	double KD_T = 602.214 * c[_KD_T]; // per second
	double b_AKAP = 1 * c[_b_AKAP]; // per second
	/*state variables */
	double Rii = x[_Rii];
	double cAMP = x[_cAMP];
	double RiiP = x[_RiiP];
	double Rii_C = x[_Rii_C];
	double RiiP_cAMP = x[_RiiP_cAMP];
	double RiiP_C = x[_RiiP_C];
	double RiiP_C_cAMP = x[_RiiP_C_cAMP];
	double C = x[_C];
	double Rii_cAMP = x[_Rii_cAMP];
	double Rii_C_cAMP = x[_Rii_C_cAMP];
	double CaN = x[_CaN];
	double RiiP_CaN = x[_RiiP_CaN];
	double RiiP_cAMP_CaN = x[_RiiP_cAMP_CaN];
	double AKAR4 = x[_AKAR4];
	double AKAR4_C = x[_AKAR4_C];
	double AKAR4p = x[_AKAR4p];
	double kf_RiiP_cAMP_CaN__CaNXRii_cAMP = b_AKAP * AKAPon_1 + (1 - b_AKAP) * AKAPoff_1;
	double kb_RiiPxCaN__RiiP_CaN = b_AKAP*AKAPon_3  +  (1 - b_AKAP)* AKAPoff_3;
	double kf_RiiP_CaN__RiixCaN = b_AKAP * AKAPon_1 + (1 - b_AKAP) * AKAPoff_1;
	double kb_CaNxRiiP_cAMP__RiiP_cAMP_CaN = b_AKAP*AKAPon_3  +  (1 - b_AKAP)* AKAPoff_3;
	double kf_RiiPxCaN__RiiP_CaN = b_AKAP * ((kb_RiiPxCaN__RiiP_CaN + kf_RiiP_cAMP_CaN__CaNXRii_cAMP)/kmON ) + (1 - b_AKAP) * (kb_RiiPxCaN__RiiP_CaN + kf_RiiP_cAMP_CaN__CaNXRii_cAMP) / kmOFF;
	double kf_CaNxRiiP_cAMP__RiiP_cAMP_CaN = b_AKAP * ((kb_CaNxRiiP_cAMP__RiiP_cAMP_CaN + kf_RiiP_CaN__RiixCaN)/kmON) + (1 - b_AKAP) * (kb_CaNxRiiP_cAMP__RiiP_cAMP_CaN + kf_RiiP_CaN__RiixCaN)/kmOFF;
	double kb_RiiP_CxcAMP__RiiP_C_cAMP = kf_RiiP_CxcAMP__RiiP_C_cAMP * KD_T;
	func[_AKAR4pOUT] = (AKAR4p*5)*71.67+100;
	return 0;
}
int model_particle_count(double t, double *molarity, int *x){
	if(!molarity || !x) return numStateVariables;
	x[_Rii] = lround(602.214 * molarity[_Rii]);
	x[_cAMP] = lround(602.214 * molarity[_cAMP]);
	x[_RiiP] = lround(602.214 * molarity[_RiiP]);
	x[_Rii_C] = lround(602.214 * molarity[_Rii_C]);
	x[_RiiP_cAMP] = lround(602.214 * molarity[_RiiP_cAMP]);
	x[_RiiP_C] = lround(602.214 * molarity[_RiiP_C]);
	x[_RiiP_C_cAMP] = lround(602.214 * molarity[_RiiP_C_cAMP]);
	x[_C] = lround(602.214 * molarity[_C]);
	x[_Rii_cAMP] = lround(602.214 * molarity[_Rii_cAMP]);
	x[_Rii_C_cAMP] = lround(602.214 * molarity[_Rii_C_cAMP]);
	x[_CaN] = lround(602.214 * molarity[_CaN]);
	x[_RiiP_CaN] = lround(602.214 * molarity[_RiiP_CaN]);
	x[_RiiP_cAMP_CaN] = lround(602.214 * molarity[_RiiP_cAMP_CaN]);
	x[_AKAR4] = lround(602.214 * molarity[_AKAR4]);
	x[_AKAR4_C] = lround(602.214 * molarity[_AKAR4_C]);
	x[_AKAR4p] = lround(602.214 * molarity[_AKAR4p]);
	return 0;
}
