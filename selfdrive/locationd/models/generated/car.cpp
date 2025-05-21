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
void err_fun(double *nom_x, double *delta_x, double *out_3683141156686312092) {
   out_3683141156686312092[0] = delta_x[0] + nom_x[0];
   out_3683141156686312092[1] = delta_x[1] + nom_x[1];
   out_3683141156686312092[2] = delta_x[2] + nom_x[2];
   out_3683141156686312092[3] = delta_x[3] + nom_x[3];
   out_3683141156686312092[4] = delta_x[4] + nom_x[4];
   out_3683141156686312092[5] = delta_x[5] + nom_x[5];
   out_3683141156686312092[6] = delta_x[6] + nom_x[6];
   out_3683141156686312092[7] = delta_x[7] + nom_x[7];
   out_3683141156686312092[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3809328802223794437) {
   out_3809328802223794437[0] = -nom_x[0] + true_x[0];
   out_3809328802223794437[1] = -nom_x[1] + true_x[1];
   out_3809328802223794437[2] = -nom_x[2] + true_x[2];
   out_3809328802223794437[3] = -nom_x[3] + true_x[3];
   out_3809328802223794437[4] = -nom_x[4] + true_x[4];
   out_3809328802223794437[5] = -nom_x[5] + true_x[5];
   out_3809328802223794437[6] = -nom_x[6] + true_x[6];
   out_3809328802223794437[7] = -nom_x[7] + true_x[7];
   out_3809328802223794437[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_7400025595387407524) {
   out_7400025595387407524[0] = 1.0;
   out_7400025595387407524[1] = 0.0;
   out_7400025595387407524[2] = 0.0;
   out_7400025595387407524[3] = 0.0;
   out_7400025595387407524[4] = 0.0;
   out_7400025595387407524[5] = 0.0;
   out_7400025595387407524[6] = 0.0;
   out_7400025595387407524[7] = 0.0;
   out_7400025595387407524[8] = 0.0;
   out_7400025595387407524[9] = 0.0;
   out_7400025595387407524[10] = 1.0;
   out_7400025595387407524[11] = 0.0;
   out_7400025595387407524[12] = 0.0;
   out_7400025595387407524[13] = 0.0;
   out_7400025595387407524[14] = 0.0;
   out_7400025595387407524[15] = 0.0;
   out_7400025595387407524[16] = 0.0;
   out_7400025595387407524[17] = 0.0;
   out_7400025595387407524[18] = 0.0;
   out_7400025595387407524[19] = 0.0;
   out_7400025595387407524[20] = 1.0;
   out_7400025595387407524[21] = 0.0;
   out_7400025595387407524[22] = 0.0;
   out_7400025595387407524[23] = 0.0;
   out_7400025595387407524[24] = 0.0;
   out_7400025595387407524[25] = 0.0;
   out_7400025595387407524[26] = 0.0;
   out_7400025595387407524[27] = 0.0;
   out_7400025595387407524[28] = 0.0;
   out_7400025595387407524[29] = 0.0;
   out_7400025595387407524[30] = 1.0;
   out_7400025595387407524[31] = 0.0;
   out_7400025595387407524[32] = 0.0;
   out_7400025595387407524[33] = 0.0;
   out_7400025595387407524[34] = 0.0;
   out_7400025595387407524[35] = 0.0;
   out_7400025595387407524[36] = 0.0;
   out_7400025595387407524[37] = 0.0;
   out_7400025595387407524[38] = 0.0;
   out_7400025595387407524[39] = 0.0;
   out_7400025595387407524[40] = 1.0;
   out_7400025595387407524[41] = 0.0;
   out_7400025595387407524[42] = 0.0;
   out_7400025595387407524[43] = 0.0;
   out_7400025595387407524[44] = 0.0;
   out_7400025595387407524[45] = 0.0;
   out_7400025595387407524[46] = 0.0;
   out_7400025595387407524[47] = 0.0;
   out_7400025595387407524[48] = 0.0;
   out_7400025595387407524[49] = 0.0;
   out_7400025595387407524[50] = 1.0;
   out_7400025595387407524[51] = 0.0;
   out_7400025595387407524[52] = 0.0;
   out_7400025595387407524[53] = 0.0;
   out_7400025595387407524[54] = 0.0;
   out_7400025595387407524[55] = 0.0;
   out_7400025595387407524[56] = 0.0;
   out_7400025595387407524[57] = 0.0;
   out_7400025595387407524[58] = 0.0;
   out_7400025595387407524[59] = 0.0;
   out_7400025595387407524[60] = 1.0;
   out_7400025595387407524[61] = 0.0;
   out_7400025595387407524[62] = 0.0;
   out_7400025595387407524[63] = 0.0;
   out_7400025595387407524[64] = 0.0;
   out_7400025595387407524[65] = 0.0;
   out_7400025595387407524[66] = 0.0;
   out_7400025595387407524[67] = 0.0;
   out_7400025595387407524[68] = 0.0;
   out_7400025595387407524[69] = 0.0;
   out_7400025595387407524[70] = 1.0;
   out_7400025595387407524[71] = 0.0;
   out_7400025595387407524[72] = 0.0;
   out_7400025595387407524[73] = 0.0;
   out_7400025595387407524[74] = 0.0;
   out_7400025595387407524[75] = 0.0;
   out_7400025595387407524[76] = 0.0;
   out_7400025595387407524[77] = 0.0;
   out_7400025595387407524[78] = 0.0;
   out_7400025595387407524[79] = 0.0;
   out_7400025595387407524[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_6123361050254032261) {
   out_6123361050254032261[0] = state[0];
   out_6123361050254032261[1] = state[1];
   out_6123361050254032261[2] = state[2];
   out_6123361050254032261[3] = state[3];
   out_6123361050254032261[4] = state[4];
   out_6123361050254032261[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_6123361050254032261[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6123361050254032261[7] = state[7];
   out_6123361050254032261[8] = state[8];
}
void F_fun(double *state, double dt, double *out_6393607266656482613) {
   out_6393607266656482613[0] = 1;
   out_6393607266656482613[1] = 0;
   out_6393607266656482613[2] = 0;
   out_6393607266656482613[3] = 0;
   out_6393607266656482613[4] = 0;
   out_6393607266656482613[5] = 0;
   out_6393607266656482613[6] = 0;
   out_6393607266656482613[7] = 0;
   out_6393607266656482613[8] = 0;
   out_6393607266656482613[9] = 0;
   out_6393607266656482613[10] = 1;
   out_6393607266656482613[11] = 0;
   out_6393607266656482613[12] = 0;
   out_6393607266656482613[13] = 0;
   out_6393607266656482613[14] = 0;
   out_6393607266656482613[15] = 0;
   out_6393607266656482613[16] = 0;
   out_6393607266656482613[17] = 0;
   out_6393607266656482613[18] = 0;
   out_6393607266656482613[19] = 0;
   out_6393607266656482613[20] = 1;
   out_6393607266656482613[21] = 0;
   out_6393607266656482613[22] = 0;
   out_6393607266656482613[23] = 0;
   out_6393607266656482613[24] = 0;
   out_6393607266656482613[25] = 0;
   out_6393607266656482613[26] = 0;
   out_6393607266656482613[27] = 0;
   out_6393607266656482613[28] = 0;
   out_6393607266656482613[29] = 0;
   out_6393607266656482613[30] = 1;
   out_6393607266656482613[31] = 0;
   out_6393607266656482613[32] = 0;
   out_6393607266656482613[33] = 0;
   out_6393607266656482613[34] = 0;
   out_6393607266656482613[35] = 0;
   out_6393607266656482613[36] = 0;
   out_6393607266656482613[37] = 0;
   out_6393607266656482613[38] = 0;
   out_6393607266656482613[39] = 0;
   out_6393607266656482613[40] = 1;
   out_6393607266656482613[41] = 0;
   out_6393607266656482613[42] = 0;
   out_6393607266656482613[43] = 0;
   out_6393607266656482613[44] = 0;
   out_6393607266656482613[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_6393607266656482613[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_6393607266656482613[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6393607266656482613[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6393607266656482613[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_6393607266656482613[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_6393607266656482613[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_6393607266656482613[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_6393607266656482613[53] = -9.8000000000000007*dt;
   out_6393607266656482613[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_6393607266656482613[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_6393607266656482613[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6393607266656482613[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6393607266656482613[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_6393607266656482613[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_6393607266656482613[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_6393607266656482613[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6393607266656482613[62] = 0;
   out_6393607266656482613[63] = 0;
   out_6393607266656482613[64] = 0;
   out_6393607266656482613[65] = 0;
   out_6393607266656482613[66] = 0;
   out_6393607266656482613[67] = 0;
   out_6393607266656482613[68] = 0;
   out_6393607266656482613[69] = 0;
   out_6393607266656482613[70] = 1;
   out_6393607266656482613[71] = 0;
   out_6393607266656482613[72] = 0;
   out_6393607266656482613[73] = 0;
   out_6393607266656482613[74] = 0;
   out_6393607266656482613[75] = 0;
   out_6393607266656482613[76] = 0;
   out_6393607266656482613[77] = 0;
   out_6393607266656482613[78] = 0;
   out_6393607266656482613[79] = 0;
   out_6393607266656482613[80] = 1;
}
void h_25(double *state, double *unused, double *out_6142773839151603091) {
   out_6142773839151603091[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6450904673358925315) {
   out_6450904673358925315[0] = 0;
   out_6450904673358925315[1] = 0;
   out_6450904673358925315[2] = 0;
   out_6450904673358925315[3] = 0;
   out_6450904673358925315[4] = 0;
   out_6450904673358925315[5] = 0;
   out_6450904673358925315[6] = 1;
   out_6450904673358925315[7] = 0;
   out_6450904673358925315[8] = 0;
}
void h_24(double *state, double *unused, double *out_5440698076484210445) {
   out_5440698076484210445[0] = state[4];
   out_5440698076484210445[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2892979074556602179) {
   out_2892979074556602179[0] = 0;
   out_2892979074556602179[1] = 0;
   out_2892979074556602179[2] = 0;
   out_2892979074556602179[3] = 0;
   out_2892979074556602179[4] = 1;
   out_2892979074556602179[5] = 0;
   out_2892979074556602179[6] = 0;
   out_2892979074556602179[7] = 0;
   out_2892979074556602179[8] = 0;
   out_2892979074556602179[9] = 0;
   out_2892979074556602179[10] = 0;
   out_2892979074556602179[11] = 0;
   out_2892979074556602179[12] = 0;
   out_2892979074556602179[13] = 0;
   out_2892979074556602179[14] = 1;
   out_2892979074556602179[15] = 0;
   out_2892979074556602179[16] = 0;
   out_2892979074556602179[17] = 0;
}
void h_30(double *state, double *unused, double *out_3807309553294208533) {
   out_3807309553294208533[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7468143070223018103) {
   out_7468143070223018103[0] = 0;
   out_7468143070223018103[1] = 0;
   out_7468143070223018103[2] = 0;
   out_7468143070223018103[3] = 0;
   out_7468143070223018103[4] = 1;
   out_7468143070223018103[5] = 0;
   out_7468143070223018103[6] = 0;
   out_7468143070223018103[7] = 0;
   out_7468143070223018103[8] = 0;
}
void h_26(double *state, double *unused, double *out_3203993668617731016) {
   out_3203993668617731016[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8254336081476570077) {
   out_8254336081476570077[0] = 0;
   out_8254336081476570077[1] = 0;
   out_8254336081476570077[2] = 0;
   out_8254336081476570077[3] = 0;
   out_8254336081476570077[4] = 0;
   out_8254336081476570077[5] = 0;
   out_8254336081476570077[6] = 0;
   out_8254336081476570077[7] = 1;
   out_8254336081476570077[8] = 0;
}
void h_27(double *state, double *unused, double *out_3322001062551107760) {
   out_3322001062551107760[0] = state[3];
}
void H_27(double *state, double *unused, double *out_8755006932302590296) {
   out_8755006932302590296[0] = 0;
   out_8755006932302590296[1] = 0;
   out_8755006932302590296[2] = 0;
   out_8755006932302590296[3] = 1;
   out_8755006932302590296[4] = 0;
   out_8755006932302590296[5] = 0;
   out_8755006932302590296[6] = 0;
   out_8755006932302590296[7] = 0;
   out_8755006932302590296[8] = 0;
}
void h_29(double *state, double *unused, double *out_2591731964119640613) {
   out_2591731964119640613[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7978374414537410287) {
   out_7978374414537410287[0] = 0;
   out_7978374414537410287[1] = 1;
   out_7978374414537410287[2] = 0;
   out_7978374414537410287[3] = 0;
   out_7978374414537410287[4] = 0;
   out_7978374414537410287[5] = 0;
   out_7978374414537410287[6] = 0;
   out_7978374414537410287[7] = 0;
   out_7978374414537410287[8] = 0;
}
void h_28(double *state, double *unused, double *out_8323674330211953405) {
   out_8323674330211953405[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2895975397467879713) {
   out_2895975397467879713[0] = 1;
   out_2895975397467879713[1] = 0;
   out_2895975397467879713[2] = 0;
   out_2895975397467879713[3] = 0;
   out_2895975397467879713[4] = 0;
   out_2895975397467879713[5] = 0;
   out_2895975397467879713[6] = 0;
   out_2895975397467879713[7] = 0;
   out_2895975397467879713[8] = 0;
}
void h_31(double *state, double *unused, double *out_4422697583803899340) {
   out_4422697583803899340[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7628127979243218601) {
   out_7628127979243218601[0] = 0;
   out_7628127979243218601[1] = 0;
   out_7628127979243218601[2] = 0;
   out_7628127979243218601[3] = 0;
   out_7628127979243218601[4] = 0;
   out_7628127979243218601[5] = 0;
   out_7628127979243218601[6] = 0;
   out_7628127979243218601[7] = 0;
   out_7628127979243218601[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3683141156686312092) {
  err_fun(nom_x, delta_x, out_3683141156686312092);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3809328802223794437) {
  inv_err_fun(nom_x, true_x, out_3809328802223794437);
}
void car_H_mod_fun(double *state, double *out_7400025595387407524) {
  H_mod_fun(state, out_7400025595387407524);
}
void car_f_fun(double *state, double dt, double *out_6123361050254032261) {
  f_fun(state,  dt, out_6123361050254032261);
}
void car_F_fun(double *state, double dt, double *out_6393607266656482613) {
  F_fun(state,  dt, out_6393607266656482613);
}
void car_h_25(double *state, double *unused, double *out_6142773839151603091) {
  h_25(state, unused, out_6142773839151603091);
}
void car_H_25(double *state, double *unused, double *out_6450904673358925315) {
  H_25(state, unused, out_6450904673358925315);
}
void car_h_24(double *state, double *unused, double *out_5440698076484210445) {
  h_24(state, unused, out_5440698076484210445);
}
void car_H_24(double *state, double *unused, double *out_2892979074556602179) {
  H_24(state, unused, out_2892979074556602179);
}
void car_h_30(double *state, double *unused, double *out_3807309553294208533) {
  h_30(state, unused, out_3807309553294208533);
}
void car_H_30(double *state, double *unused, double *out_7468143070223018103) {
  H_30(state, unused, out_7468143070223018103);
}
void car_h_26(double *state, double *unused, double *out_3203993668617731016) {
  h_26(state, unused, out_3203993668617731016);
}
void car_H_26(double *state, double *unused, double *out_8254336081476570077) {
  H_26(state, unused, out_8254336081476570077);
}
void car_h_27(double *state, double *unused, double *out_3322001062551107760) {
  h_27(state, unused, out_3322001062551107760);
}
void car_H_27(double *state, double *unused, double *out_8755006932302590296) {
  H_27(state, unused, out_8755006932302590296);
}
void car_h_29(double *state, double *unused, double *out_2591731964119640613) {
  h_29(state, unused, out_2591731964119640613);
}
void car_H_29(double *state, double *unused, double *out_7978374414537410287) {
  H_29(state, unused, out_7978374414537410287);
}
void car_h_28(double *state, double *unused, double *out_8323674330211953405) {
  h_28(state, unused, out_8323674330211953405);
}
void car_H_28(double *state, double *unused, double *out_2895975397467879713) {
  H_28(state, unused, out_2895975397467879713);
}
void car_h_31(double *state, double *unused, double *out_4422697583803899340) {
  h_31(state, unused, out_4422697583803899340);
}
void car_H_31(double *state, double *unused, double *out_7628127979243218601) {
  H_31(state, unused, out_7628127979243218601);
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
