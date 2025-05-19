#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1224536389569361641) {
   out_1224536389569361641[0] = delta_x[0] + nom_x[0];
   out_1224536389569361641[1] = delta_x[1] + nom_x[1];
   out_1224536389569361641[2] = delta_x[2] + nom_x[2];
   out_1224536389569361641[3] = delta_x[3] + nom_x[3];
   out_1224536389569361641[4] = delta_x[4] + nom_x[4];
   out_1224536389569361641[5] = delta_x[5] + nom_x[5];
   out_1224536389569361641[6] = delta_x[6] + nom_x[6];
   out_1224536389569361641[7] = delta_x[7] + nom_x[7];
   out_1224536389569361641[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2776236859002423232) {
   out_2776236859002423232[0] = -nom_x[0] + true_x[0];
   out_2776236859002423232[1] = -nom_x[1] + true_x[1];
   out_2776236859002423232[2] = -nom_x[2] + true_x[2];
   out_2776236859002423232[3] = -nom_x[3] + true_x[3];
   out_2776236859002423232[4] = -nom_x[4] + true_x[4];
   out_2776236859002423232[5] = -nom_x[5] + true_x[5];
   out_2776236859002423232[6] = -nom_x[6] + true_x[6];
   out_2776236859002423232[7] = -nom_x[7] + true_x[7];
   out_2776236859002423232[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_4769418283143954001) {
   out_4769418283143954001[0] = 1.0;
   out_4769418283143954001[1] = 0.0;
   out_4769418283143954001[2] = 0.0;
   out_4769418283143954001[3] = 0.0;
   out_4769418283143954001[4] = 0.0;
   out_4769418283143954001[5] = 0.0;
   out_4769418283143954001[6] = 0.0;
   out_4769418283143954001[7] = 0.0;
   out_4769418283143954001[8] = 0.0;
   out_4769418283143954001[9] = 0.0;
   out_4769418283143954001[10] = 1.0;
   out_4769418283143954001[11] = 0.0;
   out_4769418283143954001[12] = 0.0;
   out_4769418283143954001[13] = 0.0;
   out_4769418283143954001[14] = 0.0;
   out_4769418283143954001[15] = 0.0;
   out_4769418283143954001[16] = 0.0;
   out_4769418283143954001[17] = 0.0;
   out_4769418283143954001[18] = 0.0;
   out_4769418283143954001[19] = 0.0;
   out_4769418283143954001[20] = 1.0;
   out_4769418283143954001[21] = 0.0;
   out_4769418283143954001[22] = 0.0;
   out_4769418283143954001[23] = 0.0;
   out_4769418283143954001[24] = 0.0;
   out_4769418283143954001[25] = 0.0;
   out_4769418283143954001[26] = 0.0;
   out_4769418283143954001[27] = 0.0;
   out_4769418283143954001[28] = 0.0;
   out_4769418283143954001[29] = 0.0;
   out_4769418283143954001[30] = 1.0;
   out_4769418283143954001[31] = 0.0;
   out_4769418283143954001[32] = 0.0;
   out_4769418283143954001[33] = 0.0;
   out_4769418283143954001[34] = 0.0;
   out_4769418283143954001[35] = 0.0;
   out_4769418283143954001[36] = 0.0;
   out_4769418283143954001[37] = 0.0;
   out_4769418283143954001[38] = 0.0;
   out_4769418283143954001[39] = 0.0;
   out_4769418283143954001[40] = 1.0;
   out_4769418283143954001[41] = 0.0;
   out_4769418283143954001[42] = 0.0;
   out_4769418283143954001[43] = 0.0;
   out_4769418283143954001[44] = 0.0;
   out_4769418283143954001[45] = 0.0;
   out_4769418283143954001[46] = 0.0;
   out_4769418283143954001[47] = 0.0;
   out_4769418283143954001[48] = 0.0;
   out_4769418283143954001[49] = 0.0;
   out_4769418283143954001[50] = 1.0;
   out_4769418283143954001[51] = 0.0;
   out_4769418283143954001[52] = 0.0;
   out_4769418283143954001[53] = 0.0;
   out_4769418283143954001[54] = 0.0;
   out_4769418283143954001[55] = 0.0;
   out_4769418283143954001[56] = 0.0;
   out_4769418283143954001[57] = 0.0;
   out_4769418283143954001[58] = 0.0;
   out_4769418283143954001[59] = 0.0;
   out_4769418283143954001[60] = 1.0;
   out_4769418283143954001[61] = 0.0;
   out_4769418283143954001[62] = 0.0;
   out_4769418283143954001[63] = 0.0;
   out_4769418283143954001[64] = 0.0;
   out_4769418283143954001[65] = 0.0;
   out_4769418283143954001[66] = 0.0;
   out_4769418283143954001[67] = 0.0;
   out_4769418283143954001[68] = 0.0;
   out_4769418283143954001[69] = 0.0;
   out_4769418283143954001[70] = 1.0;
   out_4769418283143954001[71] = 0.0;
   out_4769418283143954001[72] = 0.0;
   out_4769418283143954001[73] = 0.0;
   out_4769418283143954001[74] = 0.0;
   out_4769418283143954001[75] = 0.0;
   out_4769418283143954001[76] = 0.0;
   out_4769418283143954001[77] = 0.0;
   out_4769418283143954001[78] = 0.0;
   out_4769418283143954001[79] = 0.0;
   out_4769418283143954001[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_767929196737671988) {
   out_767929196737671988[0] = state[0];
   out_767929196737671988[1] = state[1];
   out_767929196737671988[2] = state[2];
   out_767929196737671988[3] = state[3];
   out_767929196737671988[4] = state[4];
   out_767929196737671988[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_767929196737671988[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_767929196737671988[7] = state[7];
   out_767929196737671988[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5174465854823281756) {
   out_5174465854823281756[0] = 1;
   out_5174465854823281756[1] = 0;
   out_5174465854823281756[2] = 0;
   out_5174465854823281756[3] = 0;
   out_5174465854823281756[4] = 0;
   out_5174465854823281756[5] = 0;
   out_5174465854823281756[6] = 0;
   out_5174465854823281756[7] = 0;
   out_5174465854823281756[8] = 0;
   out_5174465854823281756[9] = 0;
   out_5174465854823281756[10] = 1;
   out_5174465854823281756[11] = 0;
   out_5174465854823281756[12] = 0;
   out_5174465854823281756[13] = 0;
   out_5174465854823281756[14] = 0;
   out_5174465854823281756[15] = 0;
   out_5174465854823281756[16] = 0;
   out_5174465854823281756[17] = 0;
   out_5174465854823281756[18] = 0;
   out_5174465854823281756[19] = 0;
   out_5174465854823281756[20] = 1;
   out_5174465854823281756[21] = 0;
   out_5174465854823281756[22] = 0;
   out_5174465854823281756[23] = 0;
   out_5174465854823281756[24] = 0;
   out_5174465854823281756[25] = 0;
   out_5174465854823281756[26] = 0;
   out_5174465854823281756[27] = 0;
   out_5174465854823281756[28] = 0;
   out_5174465854823281756[29] = 0;
   out_5174465854823281756[30] = 1;
   out_5174465854823281756[31] = 0;
   out_5174465854823281756[32] = 0;
   out_5174465854823281756[33] = 0;
   out_5174465854823281756[34] = 0;
   out_5174465854823281756[35] = 0;
   out_5174465854823281756[36] = 0;
   out_5174465854823281756[37] = 0;
   out_5174465854823281756[38] = 0;
   out_5174465854823281756[39] = 0;
   out_5174465854823281756[40] = 1;
   out_5174465854823281756[41] = 0;
   out_5174465854823281756[42] = 0;
   out_5174465854823281756[43] = 0;
   out_5174465854823281756[44] = 0;
   out_5174465854823281756[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5174465854823281756[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5174465854823281756[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5174465854823281756[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5174465854823281756[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5174465854823281756[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5174465854823281756[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5174465854823281756[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5174465854823281756[53] = -9.8000000000000007*dt;
   out_5174465854823281756[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5174465854823281756[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5174465854823281756[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5174465854823281756[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5174465854823281756[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5174465854823281756[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5174465854823281756[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5174465854823281756[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5174465854823281756[62] = 0;
   out_5174465854823281756[63] = 0;
   out_5174465854823281756[64] = 0;
   out_5174465854823281756[65] = 0;
   out_5174465854823281756[66] = 0;
   out_5174465854823281756[67] = 0;
   out_5174465854823281756[68] = 0;
   out_5174465854823281756[69] = 0;
   out_5174465854823281756[70] = 1;
   out_5174465854823281756[71] = 0;
   out_5174465854823281756[72] = 0;
   out_5174465854823281756[73] = 0;
   out_5174465854823281756[74] = 0;
   out_5174465854823281756[75] = 0;
   out_5174465854823281756[76] = 0;
   out_5174465854823281756[77] = 0;
   out_5174465854823281756[78] = 0;
   out_5174465854823281756[79] = 0;
   out_5174465854823281756[80] = 1;
}
void h_25(double *state, double *unused, double *out_6755757252480835042) {
   out_6755757252480835042[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3151919749829905804) {
   out_3151919749829905804[0] = 0;
   out_3151919749829905804[1] = 0;
   out_3151919749829905804[2] = 0;
   out_3151919749829905804[3] = 0;
   out_3151919749829905804[4] = 0;
   out_3151919749829905804[5] = 0;
   out_3151919749829905804[6] = 1;
   out_3151919749829905804[7] = 0;
   out_3151919749829905804[8] = 0;
}
void h_24(double *state, double *unused, double *out_346552983762474288) {
   out_346552983762474288[0] = state[4];
   out_346552983762474288[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6066759137810450587) {
   out_6066759137810450587[0] = 0;
   out_6066759137810450587[1] = 0;
   out_6066759137810450587[2] = 0;
   out_6066759137810450587[3] = 0;
   out_6066759137810450587[4] = 1;
   out_6066759137810450587[5] = 0;
   out_6066759137810450587[6] = 0;
   out_6066759137810450587[7] = 0;
   out_6066759137810450587[8] = 0;
   out_6066759137810450587[9] = 0;
   out_6066759137810450587[10] = 0;
   out_6066759137810450587[11] = 0;
   out_6066759137810450587[12] = 0;
   out_6066759137810450587[13] = 0;
   out_6066759137810450587[14] = 1;
   out_6066759137810450587[15] = 0;
   out_6066759137810450587[16] = 0;
   out_6066759137810450587[17] = 0;
}
void h_30(double *state, double *unused, double *out_4920151594878365638) {
   out_4920151594878365638[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1375776580297702394) {
   out_1375776580297702394[0] = 0;
   out_1375776580297702394[1] = 0;
   out_1375776580297702394[2] = 0;
   out_1375776580297702394[3] = 0;
   out_1375776580297702394[4] = 1;
   out_1375776580297702394[5] = 0;
   out_1375776580297702394[6] = 0;
   out_1375776580297702394[7] = 0;
   out_1375776580297702394[8] = 0;
}
void h_26(double *state, double *unused, double *out_5863661447780028073) {
   out_5863661447780028073[0] = state[7];
}
void H_26(double *state, double *unused, double *out_589583569044150420) {
   out_589583569044150420[0] = 0;
   out_589583569044150420[1] = 0;
   out_589583569044150420[2] = 0;
   out_589583569044150420[3] = 0;
   out_589583569044150420[4] = 0;
   out_589583569044150420[5] = 0;
   out_589583569044150420[6] = 0;
   out_589583569044150420[7] = 1;
   out_589583569044150420[8] = 0;
}
void h_27(double *state, double *unused, double *out_1754083984819989397) {
   out_1754083984819989397[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3550539892098127305) {
   out_3550539892098127305[0] = 0;
   out_3550539892098127305[1] = 0;
   out_3550539892098127305[2] = 0;
   out_3550539892098127305[3] = 1;
   out_3550539892098127305[4] = 0;
   out_3550539892098127305[5] = 0;
   out_3550539892098127305[6] = 0;
   out_3550539892098127305[7] = 0;
   out_3550539892098127305[8] = 0;
}
void h_29(double *state, double *unused, double *out_1883365543434032953) {
   out_1883365543434032953[0] = state[1];
}
void H_29(double *state, double *unused, double *out_865545235983310210) {
   out_865545235983310210[0] = 0;
   out_865545235983310210[1] = 1;
   out_865545235983310210[2] = 0;
   out_865545235983310210[3] = 0;
   out_865545235983310210[4] = 0;
   out_865545235983310210[5] = 0;
   out_865545235983310210[6] = 0;
   out_865545235983310210[7] = 0;
   out_865545235983310210[8] = 0;
}
void h_28(double *state, double *unused, double *out_3247589282840856248) {
   out_3247589282840856248[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5947944253052840784) {
   out_5947944253052840784[0] = 1;
   out_5947944253052840784[1] = 0;
   out_5947944253052840784[2] = 0;
   out_5947944253052840784[3] = 0;
   out_5947944253052840784[4] = 0;
   out_5947944253052840784[5] = 0;
   out_5947944253052840784[6] = 0;
   out_5947944253052840784[7] = 0;
   out_5947944253052840784[8] = 0;
}
void h_31(double *state, double *unused, double *out_1007508004339837399) {
   out_1007508004339837399[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1215791671277501896) {
   out_1215791671277501896[0] = 0;
   out_1215791671277501896[1] = 0;
   out_1215791671277501896[2] = 0;
   out_1215791671277501896[3] = 0;
   out_1215791671277501896[4] = 0;
   out_1215791671277501896[5] = 0;
   out_1215791671277501896[6] = 0;
   out_1215791671277501896[7] = 0;
   out_1215791671277501896[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_1224536389569361641) {
  err_fun(nom_x, delta_x, out_1224536389569361641);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2776236859002423232) {
  inv_err_fun(nom_x, true_x, out_2776236859002423232);
}
void car_H_mod_fun(double *state, double *out_4769418283143954001) {
  H_mod_fun(state, out_4769418283143954001);
}
void car_f_fun(double *state, double dt, double *out_767929196737671988) {
  f_fun(state,  dt, out_767929196737671988);
}
void car_F_fun(double *state, double dt, double *out_5174465854823281756) {
  F_fun(state,  dt, out_5174465854823281756);
}
void car_h_25(double *state, double *unused, double *out_6755757252480835042) {
  h_25(state, unused, out_6755757252480835042);
}
void car_H_25(double *state, double *unused, double *out_3151919749829905804) {
  H_25(state, unused, out_3151919749829905804);
}
void car_h_24(double *state, double *unused, double *out_346552983762474288) {
  h_24(state, unused, out_346552983762474288);
}
void car_H_24(double *state, double *unused, double *out_6066759137810450587) {
  H_24(state, unused, out_6066759137810450587);
}
void car_h_30(double *state, double *unused, double *out_4920151594878365638) {
  h_30(state, unused, out_4920151594878365638);
}
void car_H_30(double *state, double *unused, double *out_1375776580297702394) {
  H_30(state, unused, out_1375776580297702394);
}
void car_h_26(double *state, double *unused, double *out_5863661447780028073) {
  h_26(state, unused, out_5863661447780028073);
}
void car_H_26(double *state, double *unused, double *out_589583569044150420) {
  H_26(state, unused, out_589583569044150420);
}
void car_h_27(double *state, double *unused, double *out_1754083984819989397) {
  h_27(state, unused, out_1754083984819989397);
}
void car_H_27(double *state, double *unused, double *out_3550539892098127305) {
  H_27(state, unused, out_3550539892098127305);
}
void car_h_29(double *state, double *unused, double *out_1883365543434032953) {
  h_29(state, unused, out_1883365543434032953);
}
void car_H_29(double *state, double *unused, double *out_865545235983310210) {
  H_29(state, unused, out_865545235983310210);
}
void car_h_28(double *state, double *unused, double *out_3247589282840856248) {
  h_28(state, unused, out_3247589282840856248);
}
void car_H_28(double *state, double *unused, double *out_5947944253052840784) {
  H_28(state, unused, out_5947944253052840784);
}
void car_h_31(double *state, double *unused, double *out_1007508004339837399) {
  h_31(state, unused, out_1007508004339837399);
}
void car_H_31(double *state, double *unused, double *out_1215791671277501896) {
  H_31(state, unused, out_1215791671277501896);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
