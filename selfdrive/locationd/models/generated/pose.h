#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_6709246404097224651);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7403843722919659409);
void pose_H_mod_fun(double *state, double *out_5064661352953409354);
void pose_f_fun(double *state, double dt, double *out_658190897925549930);
void pose_F_fun(double *state, double dt, double *out_7779532396122618518);
void pose_h_4(double *state, double *unused, double *out_7839754906802398998);
void pose_H_4(double *state, double *unused, double *out_7594826649659762032);
void pose_h_10(double *state, double *unused, double *out_4273521298662950069);
void pose_H_10(double *state, double *unused, double *out_4363264211248572010);
void pose_h_13(double *state, double *unused, double *out_6483622955021563467);
void pose_H_13(double *state, double *unused, double *out_3761071186357238008);
void pose_h_14(double *state, double *unused, double *out_5686874737032609739);
void pose_H_14(double *state, double *unused, double *out_4512038217364389736);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}