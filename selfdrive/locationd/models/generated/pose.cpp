#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_6709246404097224651) {
   out_6709246404097224651[0] = delta_x[0] + nom_x[0];
   out_6709246404097224651[1] = delta_x[1] + nom_x[1];
   out_6709246404097224651[2] = delta_x[2] + nom_x[2];
   out_6709246404097224651[3] = delta_x[3] + nom_x[3];
   out_6709246404097224651[4] = delta_x[4] + nom_x[4];
   out_6709246404097224651[5] = delta_x[5] + nom_x[5];
   out_6709246404097224651[6] = delta_x[6] + nom_x[6];
   out_6709246404097224651[7] = delta_x[7] + nom_x[7];
   out_6709246404097224651[8] = delta_x[8] + nom_x[8];
   out_6709246404097224651[9] = delta_x[9] + nom_x[9];
   out_6709246404097224651[10] = delta_x[10] + nom_x[10];
   out_6709246404097224651[11] = delta_x[11] + nom_x[11];
   out_6709246404097224651[12] = delta_x[12] + nom_x[12];
   out_6709246404097224651[13] = delta_x[13] + nom_x[13];
   out_6709246404097224651[14] = delta_x[14] + nom_x[14];
   out_6709246404097224651[15] = delta_x[15] + nom_x[15];
   out_6709246404097224651[16] = delta_x[16] + nom_x[16];
   out_6709246404097224651[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7403843722919659409) {
   out_7403843722919659409[0] = -nom_x[0] + true_x[0];
   out_7403843722919659409[1] = -nom_x[1] + true_x[1];
   out_7403843722919659409[2] = -nom_x[2] + true_x[2];
   out_7403843722919659409[3] = -nom_x[3] + true_x[3];
   out_7403843722919659409[4] = -nom_x[4] + true_x[4];
   out_7403843722919659409[5] = -nom_x[5] + true_x[5];
   out_7403843722919659409[6] = -nom_x[6] + true_x[6];
   out_7403843722919659409[7] = -nom_x[7] + true_x[7];
   out_7403843722919659409[8] = -nom_x[8] + true_x[8];
   out_7403843722919659409[9] = -nom_x[9] + true_x[9];
   out_7403843722919659409[10] = -nom_x[10] + true_x[10];
   out_7403843722919659409[11] = -nom_x[11] + true_x[11];
   out_7403843722919659409[12] = -nom_x[12] + true_x[12];
   out_7403843722919659409[13] = -nom_x[13] + true_x[13];
   out_7403843722919659409[14] = -nom_x[14] + true_x[14];
   out_7403843722919659409[15] = -nom_x[15] + true_x[15];
   out_7403843722919659409[16] = -nom_x[16] + true_x[16];
   out_7403843722919659409[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5064661352953409354) {
   out_5064661352953409354[0] = 1.0;
   out_5064661352953409354[1] = 0.0;
   out_5064661352953409354[2] = 0.0;
   out_5064661352953409354[3] = 0.0;
   out_5064661352953409354[4] = 0.0;
   out_5064661352953409354[5] = 0.0;
   out_5064661352953409354[6] = 0.0;
   out_5064661352953409354[7] = 0.0;
   out_5064661352953409354[8] = 0.0;
   out_5064661352953409354[9] = 0.0;
   out_5064661352953409354[10] = 0.0;
   out_5064661352953409354[11] = 0.0;
   out_5064661352953409354[12] = 0.0;
   out_5064661352953409354[13] = 0.0;
   out_5064661352953409354[14] = 0.0;
   out_5064661352953409354[15] = 0.0;
   out_5064661352953409354[16] = 0.0;
   out_5064661352953409354[17] = 0.0;
   out_5064661352953409354[18] = 0.0;
   out_5064661352953409354[19] = 1.0;
   out_5064661352953409354[20] = 0.0;
   out_5064661352953409354[21] = 0.0;
   out_5064661352953409354[22] = 0.0;
   out_5064661352953409354[23] = 0.0;
   out_5064661352953409354[24] = 0.0;
   out_5064661352953409354[25] = 0.0;
   out_5064661352953409354[26] = 0.0;
   out_5064661352953409354[27] = 0.0;
   out_5064661352953409354[28] = 0.0;
   out_5064661352953409354[29] = 0.0;
   out_5064661352953409354[30] = 0.0;
   out_5064661352953409354[31] = 0.0;
   out_5064661352953409354[32] = 0.0;
   out_5064661352953409354[33] = 0.0;
   out_5064661352953409354[34] = 0.0;
   out_5064661352953409354[35] = 0.0;
   out_5064661352953409354[36] = 0.0;
   out_5064661352953409354[37] = 0.0;
   out_5064661352953409354[38] = 1.0;
   out_5064661352953409354[39] = 0.0;
   out_5064661352953409354[40] = 0.0;
   out_5064661352953409354[41] = 0.0;
   out_5064661352953409354[42] = 0.0;
   out_5064661352953409354[43] = 0.0;
   out_5064661352953409354[44] = 0.0;
   out_5064661352953409354[45] = 0.0;
   out_5064661352953409354[46] = 0.0;
   out_5064661352953409354[47] = 0.0;
   out_5064661352953409354[48] = 0.0;
   out_5064661352953409354[49] = 0.0;
   out_5064661352953409354[50] = 0.0;
   out_5064661352953409354[51] = 0.0;
   out_5064661352953409354[52] = 0.0;
   out_5064661352953409354[53] = 0.0;
   out_5064661352953409354[54] = 0.0;
   out_5064661352953409354[55] = 0.0;
   out_5064661352953409354[56] = 0.0;
   out_5064661352953409354[57] = 1.0;
   out_5064661352953409354[58] = 0.0;
   out_5064661352953409354[59] = 0.0;
   out_5064661352953409354[60] = 0.0;
   out_5064661352953409354[61] = 0.0;
   out_5064661352953409354[62] = 0.0;
   out_5064661352953409354[63] = 0.0;
   out_5064661352953409354[64] = 0.0;
   out_5064661352953409354[65] = 0.0;
   out_5064661352953409354[66] = 0.0;
   out_5064661352953409354[67] = 0.0;
   out_5064661352953409354[68] = 0.0;
   out_5064661352953409354[69] = 0.0;
   out_5064661352953409354[70] = 0.0;
   out_5064661352953409354[71] = 0.0;
   out_5064661352953409354[72] = 0.0;
   out_5064661352953409354[73] = 0.0;
   out_5064661352953409354[74] = 0.0;
   out_5064661352953409354[75] = 0.0;
   out_5064661352953409354[76] = 1.0;
   out_5064661352953409354[77] = 0.0;
   out_5064661352953409354[78] = 0.0;
   out_5064661352953409354[79] = 0.0;
   out_5064661352953409354[80] = 0.0;
   out_5064661352953409354[81] = 0.0;
   out_5064661352953409354[82] = 0.0;
   out_5064661352953409354[83] = 0.0;
   out_5064661352953409354[84] = 0.0;
   out_5064661352953409354[85] = 0.0;
   out_5064661352953409354[86] = 0.0;
   out_5064661352953409354[87] = 0.0;
   out_5064661352953409354[88] = 0.0;
   out_5064661352953409354[89] = 0.0;
   out_5064661352953409354[90] = 0.0;
   out_5064661352953409354[91] = 0.0;
   out_5064661352953409354[92] = 0.0;
   out_5064661352953409354[93] = 0.0;
   out_5064661352953409354[94] = 0.0;
   out_5064661352953409354[95] = 1.0;
   out_5064661352953409354[96] = 0.0;
   out_5064661352953409354[97] = 0.0;
   out_5064661352953409354[98] = 0.0;
   out_5064661352953409354[99] = 0.0;
   out_5064661352953409354[100] = 0.0;
   out_5064661352953409354[101] = 0.0;
   out_5064661352953409354[102] = 0.0;
   out_5064661352953409354[103] = 0.0;
   out_5064661352953409354[104] = 0.0;
   out_5064661352953409354[105] = 0.0;
   out_5064661352953409354[106] = 0.0;
   out_5064661352953409354[107] = 0.0;
   out_5064661352953409354[108] = 0.0;
   out_5064661352953409354[109] = 0.0;
   out_5064661352953409354[110] = 0.0;
   out_5064661352953409354[111] = 0.0;
   out_5064661352953409354[112] = 0.0;
   out_5064661352953409354[113] = 0.0;
   out_5064661352953409354[114] = 1.0;
   out_5064661352953409354[115] = 0.0;
   out_5064661352953409354[116] = 0.0;
   out_5064661352953409354[117] = 0.0;
   out_5064661352953409354[118] = 0.0;
   out_5064661352953409354[119] = 0.0;
   out_5064661352953409354[120] = 0.0;
   out_5064661352953409354[121] = 0.0;
   out_5064661352953409354[122] = 0.0;
   out_5064661352953409354[123] = 0.0;
   out_5064661352953409354[124] = 0.0;
   out_5064661352953409354[125] = 0.0;
   out_5064661352953409354[126] = 0.0;
   out_5064661352953409354[127] = 0.0;
   out_5064661352953409354[128] = 0.0;
   out_5064661352953409354[129] = 0.0;
   out_5064661352953409354[130] = 0.0;
   out_5064661352953409354[131] = 0.0;
   out_5064661352953409354[132] = 0.0;
   out_5064661352953409354[133] = 1.0;
   out_5064661352953409354[134] = 0.0;
   out_5064661352953409354[135] = 0.0;
   out_5064661352953409354[136] = 0.0;
   out_5064661352953409354[137] = 0.0;
   out_5064661352953409354[138] = 0.0;
   out_5064661352953409354[139] = 0.0;
   out_5064661352953409354[140] = 0.0;
   out_5064661352953409354[141] = 0.0;
   out_5064661352953409354[142] = 0.0;
   out_5064661352953409354[143] = 0.0;
   out_5064661352953409354[144] = 0.0;
   out_5064661352953409354[145] = 0.0;
   out_5064661352953409354[146] = 0.0;
   out_5064661352953409354[147] = 0.0;
   out_5064661352953409354[148] = 0.0;
   out_5064661352953409354[149] = 0.0;
   out_5064661352953409354[150] = 0.0;
   out_5064661352953409354[151] = 0.0;
   out_5064661352953409354[152] = 1.0;
   out_5064661352953409354[153] = 0.0;
   out_5064661352953409354[154] = 0.0;
   out_5064661352953409354[155] = 0.0;
   out_5064661352953409354[156] = 0.0;
   out_5064661352953409354[157] = 0.0;
   out_5064661352953409354[158] = 0.0;
   out_5064661352953409354[159] = 0.0;
   out_5064661352953409354[160] = 0.0;
   out_5064661352953409354[161] = 0.0;
   out_5064661352953409354[162] = 0.0;
   out_5064661352953409354[163] = 0.0;
   out_5064661352953409354[164] = 0.0;
   out_5064661352953409354[165] = 0.0;
   out_5064661352953409354[166] = 0.0;
   out_5064661352953409354[167] = 0.0;
   out_5064661352953409354[168] = 0.0;
   out_5064661352953409354[169] = 0.0;
   out_5064661352953409354[170] = 0.0;
   out_5064661352953409354[171] = 1.0;
   out_5064661352953409354[172] = 0.0;
   out_5064661352953409354[173] = 0.0;
   out_5064661352953409354[174] = 0.0;
   out_5064661352953409354[175] = 0.0;
   out_5064661352953409354[176] = 0.0;
   out_5064661352953409354[177] = 0.0;
   out_5064661352953409354[178] = 0.0;
   out_5064661352953409354[179] = 0.0;
   out_5064661352953409354[180] = 0.0;
   out_5064661352953409354[181] = 0.0;
   out_5064661352953409354[182] = 0.0;
   out_5064661352953409354[183] = 0.0;
   out_5064661352953409354[184] = 0.0;
   out_5064661352953409354[185] = 0.0;
   out_5064661352953409354[186] = 0.0;
   out_5064661352953409354[187] = 0.0;
   out_5064661352953409354[188] = 0.0;
   out_5064661352953409354[189] = 0.0;
   out_5064661352953409354[190] = 1.0;
   out_5064661352953409354[191] = 0.0;
   out_5064661352953409354[192] = 0.0;
   out_5064661352953409354[193] = 0.0;
   out_5064661352953409354[194] = 0.0;
   out_5064661352953409354[195] = 0.0;
   out_5064661352953409354[196] = 0.0;
   out_5064661352953409354[197] = 0.0;
   out_5064661352953409354[198] = 0.0;
   out_5064661352953409354[199] = 0.0;
   out_5064661352953409354[200] = 0.0;
   out_5064661352953409354[201] = 0.0;
   out_5064661352953409354[202] = 0.0;
   out_5064661352953409354[203] = 0.0;
   out_5064661352953409354[204] = 0.0;
   out_5064661352953409354[205] = 0.0;
   out_5064661352953409354[206] = 0.0;
   out_5064661352953409354[207] = 0.0;
   out_5064661352953409354[208] = 0.0;
   out_5064661352953409354[209] = 1.0;
   out_5064661352953409354[210] = 0.0;
   out_5064661352953409354[211] = 0.0;
   out_5064661352953409354[212] = 0.0;
   out_5064661352953409354[213] = 0.0;
   out_5064661352953409354[214] = 0.0;
   out_5064661352953409354[215] = 0.0;
   out_5064661352953409354[216] = 0.0;
   out_5064661352953409354[217] = 0.0;
   out_5064661352953409354[218] = 0.0;
   out_5064661352953409354[219] = 0.0;
   out_5064661352953409354[220] = 0.0;
   out_5064661352953409354[221] = 0.0;
   out_5064661352953409354[222] = 0.0;
   out_5064661352953409354[223] = 0.0;
   out_5064661352953409354[224] = 0.0;
   out_5064661352953409354[225] = 0.0;
   out_5064661352953409354[226] = 0.0;
   out_5064661352953409354[227] = 0.0;
   out_5064661352953409354[228] = 1.0;
   out_5064661352953409354[229] = 0.0;
   out_5064661352953409354[230] = 0.0;
   out_5064661352953409354[231] = 0.0;
   out_5064661352953409354[232] = 0.0;
   out_5064661352953409354[233] = 0.0;
   out_5064661352953409354[234] = 0.0;
   out_5064661352953409354[235] = 0.0;
   out_5064661352953409354[236] = 0.0;
   out_5064661352953409354[237] = 0.0;
   out_5064661352953409354[238] = 0.0;
   out_5064661352953409354[239] = 0.0;
   out_5064661352953409354[240] = 0.0;
   out_5064661352953409354[241] = 0.0;
   out_5064661352953409354[242] = 0.0;
   out_5064661352953409354[243] = 0.0;
   out_5064661352953409354[244] = 0.0;
   out_5064661352953409354[245] = 0.0;
   out_5064661352953409354[246] = 0.0;
   out_5064661352953409354[247] = 1.0;
   out_5064661352953409354[248] = 0.0;
   out_5064661352953409354[249] = 0.0;
   out_5064661352953409354[250] = 0.0;
   out_5064661352953409354[251] = 0.0;
   out_5064661352953409354[252] = 0.0;
   out_5064661352953409354[253] = 0.0;
   out_5064661352953409354[254] = 0.0;
   out_5064661352953409354[255] = 0.0;
   out_5064661352953409354[256] = 0.0;
   out_5064661352953409354[257] = 0.0;
   out_5064661352953409354[258] = 0.0;
   out_5064661352953409354[259] = 0.0;
   out_5064661352953409354[260] = 0.0;
   out_5064661352953409354[261] = 0.0;
   out_5064661352953409354[262] = 0.0;
   out_5064661352953409354[263] = 0.0;
   out_5064661352953409354[264] = 0.0;
   out_5064661352953409354[265] = 0.0;
   out_5064661352953409354[266] = 1.0;
   out_5064661352953409354[267] = 0.0;
   out_5064661352953409354[268] = 0.0;
   out_5064661352953409354[269] = 0.0;
   out_5064661352953409354[270] = 0.0;
   out_5064661352953409354[271] = 0.0;
   out_5064661352953409354[272] = 0.0;
   out_5064661352953409354[273] = 0.0;
   out_5064661352953409354[274] = 0.0;
   out_5064661352953409354[275] = 0.0;
   out_5064661352953409354[276] = 0.0;
   out_5064661352953409354[277] = 0.0;
   out_5064661352953409354[278] = 0.0;
   out_5064661352953409354[279] = 0.0;
   out_5064661352953409354[280] = 0.0;
   out_5064661352953409354[281] = 0.0;
   out_5064661352953409354[282] = 0.0;
   out_5064661352953409354[283] = 0.0;
   out_5064661352953409354[284] = 0.0;
   out_5064661352953409354[285] = 1.0;
   out_5064661352953409354[286] = 0.0;
   out_5064661352953409354[287] = 0.0;
   out_5064661352953409354[288] = 0.0;
   out_5064661352953409354[289] = 0.0;
   out_5064661352953409354[290] = 0.0;
   out_5064661352953409354[291] = 0.0;
   out_5064661352953409354[292] = 0.0;
   out_5064661352953409354[293] = 0.0;
   out_5064661352953409354[294] = 0.0;
   out_5064661352953409354[295] = 0.0;
   out_5064661352953409354[296] = 0.0;
   out_5064661352953409354[297] = 0.0;
   out_5064661352953409354[298] = 0.0;
   out_5064661352953409354[299] = 0.0;
   out_5064661352953409354[300] = 0.0;
   out_5064661352953409354[301] = 0.0;
   out_5064661352953409354[302] = 0.0;
   out_5064661352953409354[303] = 0.0;
   out_5064661352953409354[304] = 1.0;
   out_5064661352953409354[305] = 0.0;
   out_5064661352953409354[306] = 0.0;
   out_5064661352953409354[307] = 0.0;
   out_5064661352953409354[308] = 0.0;
   out_5064661352953409354[309] = 0.0;
   out_5064661352953409354[310] = 0.0;
   out_5064661352953409354[311] = 0.0;
   out_5064661352953409354[312] = 0.0;
   out_5064661352953409354[313] = 0.0;
   out_5064661352953409354[314] = 0.0;
   out_5064661352953409354[315] = 0.0;
   out_5064661352953409354[316] = 0.0;
   out_5064661352953409354[317] = 0.0;
   out_5064661352953409354[318] = 0.0;
   out_5064661352953409354[319] = 0.0;
   out_5064661352953409354[320] = 0.0;
   out_5064661352953409354[321] = 0.0;
   out_5064661352953409354[322] = 0.0;
   out_5064661352953409354[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_658190897925549930) {
   out_658190897925549930[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_658190897925549930[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_658190897925549930[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_658190897925549930[3] = dt*state[12] + state[3];
   out_658190897925549930[4] = dt*state[13] + state[4];
   out_658190897925549930[5] = dt*state[14] + state[5];
   out_658190897925549930[6] = state[6];
   out_658190897925549930[7] = state[7];
   out_658190897925549930[8] = state[8];
   out_658190897925549930[9] = state[9];
   out_658190897925549930[10] = state[10];
   out_658190897925549930[11] = state[11];
   out_658190897925549930[12] = state[12];
   out_658190897925549930[13] = state[13];
   out_658190897925549930[14] = state[14];
   out_658190897925549930[15] = state[15];
   out_658190897925549930[16] = state[16];
   out_658190897925549930[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7779532396122618518) {
   out_7779532396122618518[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7779532396122618518[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7779532396122618518[2] = 0;
   out_7779532396122618518[3] = 0;
   out_7779532396122618518[4] = 0;
   out_7779532396122618518[5] = 0;
   out_7779532396122618518[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7779532396122618518[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7779532396122618518[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7779532396122618518[9] = 0;
   out_7779532396122618518[10] = 0;
   out_7779532396122618518[11] = 0;
   out_7779532396122618518[12] = 0;
   out_7779532396122618518[13] = 0;
   out_7779532396122618518[14] = 0;
   out_7779532396122618518[15] = 0;
   out_7779532396122618518[16] = 0;
   out_7779532396122618518[17] = 0;
   out_7779532396122618518[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7779532396122618518[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7779532396122618518[20] = 0;
   out_7779532396122618518[21] = 0;
   out_7779532396122618518[22] = 0;
   out_7779532396122618518[23] = 0;
   out_7779532396122618518[24] = 0;
   out_7779532396122618518[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7779532396122618518[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7779532396122618518[27] = 0;
   out_7779532396122618518[28] = 0;
   out_7779532396122618518[29] = 0;
   out_7779532396122618518[30] = 0;
   out_7779532396122618518[31] = 0;
   out_7779532396122618518[32] = 0;
   out_7779532396122618518[33] = 0;
   out_7779532396122618518[34] = 0;
   out_7779532396122618518[35] = 0;
   out_7779532396122618518[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7779532396122618518[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7779532396122618518[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7779532396122618518[39] = 0;
   out_7779532396122618518[40] = 0;
   out_7779532396122618518[41] = 0;
   out_7779532396122618518[42] = 0;
   out_7779532396122618518[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7779532396122618518[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7779532396122618518[45] = 0;
   out_7779532396122618518[46] = 0;
   out_7779532396122618518[47] = 0;
   out_7779532396122618518[48] = 0;
   out_7779532396122618518[49] = 0;
   out_7779532396122618518[50] = 0;
   out_7779532396122618518[51] = 0;
   out_7779532396122618518[52] = 0;
   out_7779532396122618518[53] = 0;
   out_7779532396122618518[54] = 0;
   out_7779532396122618518[55] = 0;
   out_7779532396122618518[56] = 0;
   out_7779532396122618518[57] = 1;
   out_7779532396122618518[58] = 0;
   out_7779532396122618518[59] = 0;
   out_7779532396122618518[60] = 0;
   out_7779532396122618518[61] = 0;
   out_7779532396122618518[62] = 0;
   out_7779532396122618518[63] = 0;
   out_7779532396122618518[64] = 0;
   out_7779532396122618518[65] = 0;
   out_7779532396122618518[66] = dt;
   out_7779532396122618518[67] = 0;
   out_7779532396122618518[68] = 0;
   out_7779532396122618518[69] = 0;
   out_7779532396122618518[70] = 0;
   out_7779532396122618518[71] = 0;
   out_7779532396122618518[72] = 0;
   out_7779532396122618518[73] = 0;
   out_7779532396122618518[74] = 0;
   out_7779532396122618518[75] = 0;
   out_7779532396122618518[76] = 1;
   out_7779532396122618518[77] = 0;
   out_7779532396122618518[78] = 0;
   out_7779532396122618518[79] = 0;
   out_7779532396122618518[80] = 0;
   out_7779532396122618518[81] = 0;
   out_7779532396122618518[82] = 0;
   out_7779532396122618518[83] = 0;
   out_7779532396122618518[84] = 0;
   out_7779532396122618518[85] = dt;
   out_7779532396122618518[86] = 0;
   out_7779532396122618518[87] = 0;
   out_7779532396122618518[88] = 0;
   out_7779532396122618518[89] = 0;
   out_7779532396122618518[90] = 0;
   out_7779532396122618518[91] = 0;
   out_7779532396122618518[92] = 0;
   out_7779532396122618518[93] = 0;
   out_7779532396122618518[94] = 0;
   out_7779532396122618518[95] = 1;
   out_7779532396122618518[96] = 0;
   out_7779532396122618518[97] = 0;
   out_7779532396122618518[98] = 0;
   out_7779532396122618518[99] = 0;
   out_7779532396122618518[100] = 0;
   out_7779532396122618518[101] = 0;
   out_7779532396122618518[102] = 0;
   out_7779532396122618518[103] = 0;
   out_7779532396122618518[104] = dt;
   out_7779532396122618518[105] = 0;
   out_7779532396122618518[106] = 0;
   out_7779532396122618518[107] = 0;
   out_7779532396122618518[108] = 0;
   out_7779532396122618518[109] = 0;
   out_7779532396122618518[110] = 0;
   out_7779532396122618518[111] = 0;
   out_7779532396122618518[112] = 0;
   out_7779532396122618518[113] = 0;
   out_7779532396122618518[114] = 1;
   out_7779532396122618518[115] = 0;
   out_7779532396122618518[116] = 0;
   out_7779532396122618518[117] = 0;
   out_7779532396122618518[118] = 0;
   out_7779532396122618518[119] = 0;
   out_7779532396122618518[120] = 0;
   out_7779532396122618518[121] = 0;
   out_7779532396122618518[122] = 0;
   out_7779532396122618518[123] = 0;
   out_7779532396122618518[124] = 0;
   out_7779532396122618518[125] = 0;
   out_7779532396122618518[126] = 0;
   out_7779532396122618518[127] = 0;
   out_7779532396122618518[128] = 0;
   out_7779532396122618518[129] = 0;
   out_7779532396122618518[130] = 0;
   out_7779532396122618518[131] = 0;
   out_7779532396122618518[132] = 0;
   out_7779532396122618518[133] = 1;
   out_7779532396122618518[134] = 0;
   out_7779532396122618518[135] = 0;
   out_7779532396122618518[136] = 0;
   out_7779532396122618518[137] = 0;
   out_7779532396122618518[138] = 0;
   out_7779532396122618518[139] = 0;
   out_7779532396122618518[140] = 0;
   out_7779532396122618518[141] = 0;
   out_7779532396122618518[142] = 0;
   out_7779532396122618518[143] = 0;
   out_7779532396122618518[144] = 0;
   out_7779532396122618518[145] = 0;
   out_7779532396122618518[146] = 0;
   out_7779532396122618518[147] = 0;
   out_7779532396122618518[148] = 0;
   out_7779532396122618518[149] = 0;
   out_7779532396122618518[150] = 0;
   out_7779532396122618518[151] = 0;
   out_7779532396122618518[152] = 1;
   out_7779532396122618518[153] = 0;
   out_7779532396122618518[154] = 0;
   out_7779532396122618518[155] = 0;
   out_7779532396122618518[156] = 0;
   out_7779532396122618518[157] = 0;
   out_7779532396122618518[158] = 0;
   out_7779532396122618518[159] = 0;
   out_7779532396122618518[160] = 0;
   out_7779532396122618518[161] = 0;
   out_7779532396122618518[162] = 0;
   out_7779532396122618518[163] = 0;
   out_7779532396122618518[164] = 0;
   out_7779532396122618518[165] = 0;
   out_7779532396122618518[166] = 0;
   out_7779532396122618518[167] = 0;
   out_7779532396122618518[168] = 0;
   out_7779532396122618518[169] = 0;
   out_7779532396122618518[170] = 0;
   out_7779532396122618518[171] = 1;
   out_7779532396122618518[172] = 0;
   out_7779532396122618518[173] = 0;
   out_7779532396122618518[174] = 0;
   out_7779532396122618518[175] = 0;
   out_7779532396122618518[176] = 0;
   out_7779532396122618518[177] = 0;
   out_7779532396122618518[178] = 0;
   out_7779532396122618518[179] = 0;
   out_7779532396122618518[180] = 0;
   out_7779532396122618518[181] = 0;
   out_7779532396122618518[182] = 0;
   out_7779532396122618518[183] = 0;
   out_7779532396122618518[184] = 0;
   out_7779532396122618518[185] = 0;
   out_7779532396122618518[186] = 0;
   out_7779532396122618518[187] = 0;
   out_7779532396122618518[188] = 0;
   out_7779532396122618518[189] = 0;
   out_7779532396122618518[190] = 1;
   out_7779532396122618518[191] = 0;
   out_7779532396122618518[192] = 0;
   out_7779532396122618518[193] = 0;
   out_7779532396122618518[194] = 0;
   out_7779532396122618518[195] = 0;
   out_7779532396122618518[196] = 0;
   out_7779532396122618518[197] = 0;
   out_7779532396122618518[198] = 0;
   out_7779532396122618518[199] = 0;
   out_7779532396122618518[200] = 0;
   out_7779532396122618518[201] = 0;
   out_7779532396122618518[202] = 0;
   out_7779532396122618518[203] = 0;
   out_7779532396122618518[204] = 0;
   out_7779532396122618518[205] = 0;
   out_7779532396122618518[206] = 0;
   out_7779532396122618518[207] = 0;
   out_7779532396122618518[208] = 0;
   out_7779532396122618518[209] = 1;
   out_7779532396122618518[210] = 0;
   out_7779532396122618518[211] = 0;
   out_7779532396122618518[212] = 0;
   out_7779532396122618518[213] = 0;
   out_7779532396122618518[214] = 0;
   out_7779532396122618518[215] = 0;
   out_7779532396122618518[216] = 0;
   out_7779532396122618518[217] = 0;
   out_7779532396122618518[218] = 0;
   out_7779532396122618518[219] = 0;
   out_7779532396122618518[220] = 0;
   out_7779532396122618518[221] = 0;
   out_7779532396122618518[222] = 0;
   out_7779532396122618518[223] = 0;
   out_7779532396122618518[224] = 0;
   out_7779532396122618518[225] = 0;
   out_7779532396122618518[226] = 0;
   out_7779532396122618518[227] = 0;
   out_7779532396122618518[228] = 1;
   out_7779532396122618518[229] = 0;
   out_7779532396122618518[230] = 0;
   out_7779532396122618518[231] = 0;
   out_7779532396122618518[232] = 0;
   out_7779532396122618518[233] = 0;
   out_7779532396122618518[234] = 0;
   out_7779532396122618518[235] = 0;
   out_7779532396122618518[236] = 0;
   out_7779532396122618518[237] = 0;
   out_7779532396122618518[238] = 0;
   out_7779532396122618518[239] = 0;
   out_7779532396122618518[240] = 0;
   out_7779532396122618518[241] = 0;
   out_7779532396122618518[242] = 0;
   out_7779532396122618518[243] = 0;
   out_7779532396122618518[244] = 0;
   out_7779532396122618518[245] = 0;
   out_7779532396122618518[246] = 0;
   out_7779532396122618518[247] = 1;
   out_7779532396122618518[248] = 0;
   out_7779532396122618518[249] = 0;
   out_7779532396122618518[250] = 0;
   out_7779532396122618518[251] = 0;
   out_7779532396122618518[252] = 0;
   out_7779532396122618518[253] = 0;
   out_7779532396122618518[254] = 0;
   out_7779532396122618518[255] = 0;
   out_7779532396122618518[256] = 0;
   out_7779532396122618518[257] = 0;
   out_7779532396122618518[258] = 0;
   out_7779532396122618518[259] = 0;
   out_7779532396122618518[260] = 0;
   out_7779532396122618518[261] = 0;
   out_7779532396122618518[262] = 0;
   out_7779532396122618518[263] = 0;
   out_7779532396122618518[264] = 0;
   out_7779532396122618518[265] = 0;
   out_7779532396122618518[266] = 1;
   out_7779532396122618518[267] = 0;
   out_7779532396122618518[268] = 0;
   out_7779532396122618518[269] = 0;
   out_7779532396122618518[270] = 0;
   out_7779532396122618518[271] = 0;
   out_7779532396122618518[272] = 0;
   out_7779532396122618518[273] = 0;
   out_7779532396122618518[274] = 0;
   out_7779532396122618518[275] = 0;
   out_7779532396122618518[276] = 0;
   out_7779532396122618518[277] = 0;
   out_7779532396122618518[278] = 0;
   out_7779532396122618518[279] = 0;
   out_7779532396122618518[280] = 0;
   out_7779532396122618518[281] = 0;
   out_7779532396122618518[282] = 0;
   out_7779532396122618518[283] = 0;
   out_7779532396122618518[284] = 0;
   out_7779532396122618518[285] = 1;
   out_7779532396122618518[286] = 0;
   out_7779532396122618518[287] = 0;
   out_7779532396122618518[288] = 0;
   out_7779532396122618518[289] = 0;
   out_7779532396122618518[290] = 0;
   out_7779532396122618518[291] = 0;
   out_7779532396122618518[292] = 0;
   out_7779532396122618518[293] = 0;
   out_7779532396122618518[294] = 0;
   out_7779532396122618518[295] = 0;
   out_7779532396122618518[296] = 0;
   out_7779532396122618518[297] = 0;
   out_7779532396122618518[298] = 0;
   out_7779532396122618518[299] = 0;
   out_7779532396122618518[300] = 0;
   out_7779532396122618518[301] = 0;
   out_7779532396122618518[302] = 0;
   out_7779532396122618518[303] = 0;
   out_7779532396122618518[304] = 1;
   out_7779532396122618518[305] = 0;
   out_7779532396122618518[306] = 0;
   out_7779532396122618518[307] = 0;
   out_7779532396122618518[308] = 0;
   out_7779532396122618518[309] = 0;
   out_7779532396122618518[310] = 0;
   out_7779532396122618518[311] = 0;
   out_7779532396122618518[312] = 0;
   out_7779532396122618518[313] = 0;
   out_7779532396122618518[314] = 0;
   out_7779532396122618518[315] = 0;
   out_7779532396122618518[316] = 0;
   out_7779532396122618518[317] = 0;
   out_7779532396122618518[318] = 0;
   out_7779532396122618518[319] = 0;
   out_7779532396122618518[320] = 0;
   out_7779532396122618518[321] = 0;
   out_7779532396122618518[322] = 0;
   out_7779532396122618518[323] = 1;
}
void h_4(double *state, double *unused, double *out_7839754906802398998) {
   out_7839754906802398998[0] = state[6] + state[9];
   out_7839754906802398998[1] = state[7] + state[10];
   out_7839754906802398998[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_7594826649659762032) {
   out_7594826649659762032[0] = 0;
   out_7594826649659762032[1] = 0;
   out_7594826649659762032[2] = 0;
   out_7594826649659762032[3] = 0;
   out_7594826649659762032[4] = 0;
   out_7594826649659762032[5] = 0;
   out_7594826649659762032[6] = 1;
   out_7594826649659762032[7] = 0;
   out_7594826649659762032[8] = 0;
   out_7594826649659762032[9] = 1;
   out_7594826649659762032[10] = 0;
   out_7594826649659762032[11] = 0;
   out_7594826649659762032[12] = 0;
   out_7594826649659762032[13] = 0;
   out_7594826649659762032[14] = 0;
   out_7594826649659762032[15] = 0;
   out_7594826649659762032[16] = 0;
   out_7594826649659762032[17] = 0;
   out_7594826649659762032[18] = 0;
   out_7594826649659762032[19] = 0;
   out_7594826649659762032[20] = 0;
   out_7594826649659762032[21] = 0;
   out_7594826649659762032[22] = 0;
   out_7594826649659762032[23] = 0;
   out_7594826649659762032[24] = 0;
   out_7594826649659762032[25] = 1;
   out_7594826649659762032[26] = 0;
   out_7594826649659762032[27] = 0;
   out_7594826649659762032[28] = 1;
   out_7594826649659762032[29] = 0;
   out_7594826649659762032[30] = 0;
   out_7594826649659762032[31] = 0;
   out_7594826649659762032[32] = 0;
   out_7594826649659762032[33] = 0;
   out_7594826649659762032[34] = 0;
   out_7594826649659762032[35] = 0;
   out_7594826649659762032[36] = 0;
   out_7594826649659762032[37] = 0;
   out_7594826649659762032[38] = 0;
   out_7594826649659762032[39] = 0;
   out_7594826649659762032[40] = 0;
   out_7594826649659762032[41] = 0;
   out_7594826649659762032[42] = 0;
   out_7594826649659762032[43] = 0;
   out_7594826649659762032[44] = 1;
   out_7594826649659762032[45] = 0;
   out_7594826649659762032[46] = 0;
   out_7594826649659762032[47] = 1;
   out_7594826649659762032[48] = 0;
   out_7594826649659762032[49] = 0;
   out_7594826649659762032[50] = 0;
   out_7594826649659762032[51] = 0;
   out_7594826649659762032[52] = 0;
   out_7594826649659762032[53] = 0;
}
void h_10(double *state, double *unused, double *out_4273521298662950069) {
   out_4273521298662950069[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4273521298662950069[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4273521298662950069[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4363264211248572010) {
   out_4363264211248572010[0] = 0;
   out_4363264211248572010[1] = 9.8100000000000005*cos(state[1]);
   out_4363264211248572010[2] = 0;
   out_4363264211248572010[3] = 0;
   out_4363264211248572010[4] = -state[8];
   out_4363264211248572010[5] = state[7];
   out_4363264211248572010[6] = 0;
   out_4363264211248572010[7] = state[5];
   out_4363264211248572010[8] = -state[4];
   out_4363264211248572010[9] = 0;
   out_4363264211248572010[10] = 0;
   out_4363264211248572010[11] = 0;
   out_4363264211248572010[12] = 1;
   out_4363264211248572010[13] = 0;
   out_4363264211248572010[14] = 0;
   out_4363264211248572010[15] = 1;
   out_4363264211248572010[16] = 0;
   out_4363264211248572010[17] = 0;
   out_4363264211248572010[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4363264211248572010[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4363264211248572010[20] = 0;
   out_4363264211248572010[21] = state[8];
   out_4363264211248572010[22] = 0;
   out_4363264211248572010[23] = -state[6];
   out_4363264211248572010[24] = -state[5];
   out_4363264211248572010[25] = 0;
   out_4363264211248572010[26] = state[3];
   out_4363264211248572010[27] = 0;
   out_4363264211248572010[28] = 0;
   out_4363264211248572010[29] = 0;
   out_4363264211248572010[30] = 0;
   out_4363264211248572010[31] = 1;
   out_4363264211248572010[32] = 0;
   out_4363264211248572010[33] = 0;
   out_4363264211248572010[34] = 1;
   out_4363264211248572010[35] = 0;
   out_4363264211248572010[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4363264211248572010[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4363264211248572010[38] = 0;
   out_4363264211248572010[39] = -state[7];
   out_4363264211248572010[40] = state[6];
   out_4363264211248572010[41] = 0;
   out_4363264211248572010[42] = state[4];
   out_4363264211248572010[43] = -state[3];
   out_4363264211248572010[44] = 0;
   out_4363264211248572010[45] = 0;
   out_4363264211248572010[46] = 0;
   out_4363264211248572010[47] = 0;
   out_4363264211248572010[48] = 0;
   out_4363264211248572010[49] = 0;
   out_4363264211248572010[50] = 1;
   out_4363264211248572010[51] = 0;
   out_4363264211248572010[52] = 0;
   out_4363264211248572010[53] = 1;
}
void h_13(double *state, double *unused, double *out_6483622955021563467) {
   out_6483622955021563467[0] = state[3];
   out_6483622955021563467[1] = state[4];
   out_6483622955021563467[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3761071186357238008) {
   out_3761071186357238008[0] = 0;
   out_3761071186357238008[1] = 0;
   out_3761071186357238008[2] = 0;
   out_3761071186357238008[3] = 1;
   out_3761071186357238008[4] = 0;
   out_3761071186357238008[5] = 0;
   out_3761071186357238008[6] = 0;
   out_3761071186357238008[7] = 0;
   out_3761071186357238008[8] = 0;
   out_3761071186357238008[9] = 0;
   out_3761071186357238008[10] = 0;
   out_3761071186357238008[11] = 0;
   out_3761071186357238008[12] = 0;
   out_3761071186357238008[13] = 0;
   out_3761071186357238008[14] = 0;
   out_3761071186357238008[15] = 0;
   out_3761071186357238008[16] = 0;
   out_3761071186357238008[17] = 0;
   out_3761071186357238008[18] = 0;
   out_3761071186357238008[19] = 0;
   out_3761071186357238008[20] = 0;
   out_3761071186357238008[21] = 0;
   out_3761071186357238008[22] = 1;
   out_3761071186357238008[23] = 0;
   out_3761071186357238008[24] = 0;
   out_3761071186357238008[25] = 0;
   out_3761071186357238008[26] = 0;
   out_3761071186357238008[27] = 0;
   out_3761071186357238008[28] = 0;
   out_3761071186357238008[29] = 0;
   out_3761071186357238008[30] = 0;
   out_3761071186357238008[31] = 0;
   out_3761071186357238008[32] = 0;
   out_3761071186357238008[33] = 0;
   out_3761071186357238008[34] = 0;
   out_3761071186357238008[35] = 0;
   out_3761071186357238008[36] = 0;
   out_3761071186357238008[37] = 0;
   out_3761071186357238008[38] = 0;
   out_3761071186357238008[39] = 0;
   out_3761071186357238008[40] = 0;
   out_3761071186357238008[41] = 1;
   out_3761071186357238008[42] = 0;
   out_3761071186357238008[43] = 0;
   out_3761071186357238008[44] = 0;
   out_3761071186357238008[45] = 0;
   out_3761071186357238008[46] = 0;
   out_3761071186357238008[47] = 0;
   out_3761071186357238008[48] = 0;
   out_3761071186357238008[49] = 0;
   out_3761071186357238008[50] = 0;
   out_3761071186357238008[51] = 0;
   out_3761071186357238008[52] = 0;
   out_3761071186357238008[53] = 0;
}
void h_14(double *state, double *unused, double *out_5686874737032609739) {
   out_5686874737032609739[0] = state[6];
   out_5686874737032609739[1] = state[7];
   out_5686874737032609739[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4512038217364389736) {
   out_4512038217364389736[0] = 0;
   out_4512038217364389736[1] = 0;
   out_4512038217364389736[2] = 0;
   out_4512038217364389736[3] = 0;
   out_4512038217364389736[4] = 0;
   out_4512038217364389736[5] = 0;
   out_4512038217364389736[6] = 1;
   out_4512038217364389736[7] = 0;
   out_4512038217364389736[8] = 0;
   out_4512038217364389736[9] = 0;
   out_4512038217364389736[10] = 0;
   out_4512038217364389736[11] = 0;
   out_4512038217364389736[12] = 0;
   out_4512038217364389736[13] = 0;
   out_4512038217364389736[14] = 0;
   out_4512038217364389736[15] = 0;
   out_4512038217364389736[16] = 0;
   out_4512038217364389736[17] = 0;
   out_4512038217364389736[18] = 0;
   out_4512038217364389736[19] = 0;
   out_4512038217364389736[20] = 0;
   out_4512038217364389736[21] = 0;
   out_4512038217364389736[22] = 0;
   out_4512038217364389736[23] = 0;
   out_4512038217364389736[24] = 0;
   out_4512038217364389736[25] = 1;
   out_4512038217364389736[26] = 0;
   out_4512038217364389736[27] = 0;
   out_4512038217364389736[28] = 0;
   out_4512038217364389736[29] = 0;
   out_4512038217364389736[30] = 0;
   out_4512038217364389736[31] = 0;
   out_4512038217364389736[32] = 0;
   out_4512038217364389736[33] = 0;
   out_4512038217364389736[34] = 0;
   out_4512038217364389736[35] = 0;
   out_4512038217364389736[36] = 0;
   out_4512038217364389736[37] = 0;
   out_4512038217364389736[38] = 0;
   out_4512038217364389736[39] = 0;
   out_4512038217364389736[40] = 0;
   out_4512038217364389736[41] = 0;
   out_4512038217364389736[42] = 0;
   out_4512038217364389736[43] = 0;
   out_4512038217364389736[44] = 1;
   out_4512038217364389736[45] = 0;
   out_4512038217364389736[46] = 0;
   out_4512038217364389736[47] = 0;
   out_4512038217364389736[48] = 0;
   out_4512038217364389736[49] = 0;
   out_4512038217364389736[50] = 0;
   out_4512038217364389736[51] = 0;
   out_4512038217364389736[52] = 0;
   out_4512038217364389736[53] = 0;
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

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_6709246404097224651) {
  err_fun(nom_x, delta_x, out_6709246404097224651);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7403843722919659409) {
  inv_err_fun(nom_x, true_x, out_7403843722919659409);
}
void pose_H_mod_fun(double *state, double *out_5064661352953409354) {
  H_mod_fun(state, out_5064661352953409354);
}
void pose_f_fun(double *state, double dt, double *out_658190897925549930) {
  f_fun(state,  dt, out_658190897925549930);
}
void pose_F_fun(double *state, double dt, double *out_7779532396122618518) {
  F_fun(state,  dt, out_7779532396122618518);
}
void pose_h_4(double *state, double *unused, double *out_7839754906802398998) {
  h_4(state, unused, out_7839754906802398998);
}
void pose_H_4(double *state, double *unused, double *out_7594826649659762032) {
  H_4(state, unused, out_7594826649659762032);
}
void pose_h_10(double *state, double *unused, double *out_4273521298662950069) {
  h_10(state, unused, out_4273521298662950069);
}
void pose_H_10(double *state, double *unused, double *out_4363264211248572010) {
  H_10(state, unused, out_4363264211248572010);
}
void pose_h_13(double *state, double *unused, double *out_6483622955021563467) {
  h_13(state, unused, out_6483622955021563467);
}
void pose_H_13(double *state, double *unused, double *out_3761071186357238008) {
  H_13(state, unused, out_3761071186357238008);
}
void pose_h_14(double *state, double *unused, double *out_5686874737032609739) {
  h_14(state, unused, out_5686874737032609739);
}
void pose_H_14(double *state, double *unused, double *out_4512038217364389736) {
  H_14(state, unused, out_4512038217364389736);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
