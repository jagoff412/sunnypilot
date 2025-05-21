#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_3683141156686312092);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3809328802223794437);
void car_H_mod_fun(double *state, double *out_7400025595387407524);
void car_f_fun(double *state, double dt, double *out_6123361050254032261);
void car_F_fun(double *state, double dt, double *out_6393607266656482613);
void car_h_25(double *state, double *unused, double *out_6142773839151603091);
void car_H_25(double *state, double *unused, double *out_6450904673358925315);
void car_h_24(double *state, double *unused, double *out_5440698076484210445);
void car_H_24(double *state, double *unused, double *out_2892979074556602179);
void car_h_30(double *state, double *unused, double *out_3807309553294208533);
void car_H_30(double *state, double *unused, double *out_7468143070223018103);
void car_h_26(double *state, double *unused, double *out_3203993668617731016);
void car_H_26(double *state, double *unused, double *out_8254336081476570077);
void car_h_27(double *state, double *unused, double *out_3322001062551107760);
void car_H_27(double *state, double *unused, double *out_8755006932302590296);
void car_h_29(double *state, double *unused, double *out_2591731964119640613);
void car_H_29(double *state, double *unused, double *out_7978374414537410287);
void car_h_28(double *state, double *unused, double *out_8323674330211953405);
void car_H_28(double *state, double *unused, double *out_2895975397467879713);
void car_h_31(double *state, double *unused, double *out_4422697583803899340);
void car_H_31(double *state, double *unused, double *out_7628127979243218601);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}