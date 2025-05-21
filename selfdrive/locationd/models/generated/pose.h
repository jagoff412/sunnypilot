#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_2996101941373283621);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4501170633989036006);
void pose_H_mod_fun(double *state, double *out_8502712302344637749);
void pose_f_fun(double *state, double dt, double *out_3812607681717002176);
void pose_F_fun(double *state, double dt, double *out_2792835002777004096);
void pose_h_4(double *state, double *unused, double *out_1436781500686272226);
void pose_H_4(double *state, double *unused, double *out_5228490223553688496);
void pose_h_10(double *state, double *unused, double *out_5194169306934239483);
void pose_H_10(double *state, double *unused, double *out_5423213404703357435);
void pose_h_13(double *state, double *unused, double *out_5070288323570698443);
void pose_H_13(double *state, double *unused, double *out_5607622641839162191);
void pose_h_14(double *state, double *unused, double *out_2853207577681860036);
void pose_H_14(double *state, double *unused, double *out_9191731079893173025);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}