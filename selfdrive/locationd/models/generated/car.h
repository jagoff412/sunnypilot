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
void car_err_fun(double *nom_x, double *delta_x, double *out_1224536389569361641);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2776236859002423232);
void car_H_mod_fun(double *state, double *out_4769418283143954001);
void car_f_fun(double *state, double dt, double *out_767929196737671988);
void car_F_fun(double *state, double dt, double *out_5174465854823281756);
void car_h_25(double *state, double *unused, double *out_6755757252480835042);
void car_H_25(double *state, double *unused, double *out_3151919749829905804);
void car_h_24(double *state, double *unused, double *out_346552983762474288);
void car_H_24(double *state, double *unused, double *out_6066759137810450587);
void car_h_30(double *state, double *unused, double *out_4920151594878365638);
void car_H_30(double *state, double *unused, double *out_1375776580297702394);
void car_h_26(double *state, double *unused, double *out_5863661447780028073);
void car_H_26(double *state, double *unused, double *out_589583569044150420);
void car_h_27(double *state, double *unused, double *out_1754083984819989397);
void car_H_27(double *state, double *unused, double *out_3550539892098127305);
void car_h_29(double *state, double *unused, double *out_1883365543434032953);
void car_H_29(double *state, double *unused, double *out_865545235983310210);
void car_h_28(double *state, double *unused, double *out_3247589282840856248);
void car_H_28(double *state, double *unused, double *out_5947944253052840784);
void car_h_31(double *state, double *unused, double *out_1007508004339837399);
void car_H_31(double *state, double *unused, double *out_1215791671277501896);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}