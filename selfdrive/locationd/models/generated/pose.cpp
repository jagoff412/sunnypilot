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
void err_fun(double *nom_x, double *delta_x, double *out_2996101941373283621) {
   out_2996101941373283621[0] = delta_x[0] + nom_x[0];
   out_2996101941373283621[1] = delta_x[1] + nom_x[1];
   out_2996101941373283621[2] = delta_x[2] + nom_x[2];
   out_2996101941373283621[3] = delta_x[3] + nom_x[3];
   out_2996101941373283621[4] = delta_x[4] + nom_x[4];
   out_2996101941373283621[5] = delta_x[5] + nom_x[5];
   out_2996101941373283621[6] = delta_x[6] + nom_x[6];
   out_2996101941373283621[7] = delta_x[7] + nom_x[7];
   out_2996101941373283621[8] = delta_x[8] + nom_x[8];
   out_2996101941373283621[9] = delta_x[9] + nom_x[9];
   out_2996101941373283621[10] = delta_x[10] + nom_x[10];
   out_2996101941373283621[11] = delta_x[11] + nom_x[11];
   out_2996101941373283621[12] = delta_x[12] + nom_x[12];
   out_2996101941373283621[13] = delta_x[13] + nom_x[13];
   out_2996101941373283621[14] = delta_x[14] + nom_x[14];
   out_2996101941373283621[15] = delta_x[15] + nom_x[15];
   out_2996101941373283621[16] = delta_x[16] + nom_x[16];
   out_2996101941373283621[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4501170633989036006) {
   out_4501170633989036006[0] = -nom_x[0] + true_x[0];
   out_4501170633989036006[1] = -nom_x[1] + true_x[1];
   out_4501170633989036006[2] = -nom_x[2] + true_x[2];
   out_4501170633989036006[3] = -nom_x[3] + true_x[3];
   out_4501170633989036006[4] = -nom_x[4] + true_x[4];
   out_4501170633989036006[5] = -nom_x[5] + true_x[5];
   out_4501170633989036006[6] = -nom_x[6] + true_x[6];
   out_4501170633989036006[7] = -nom_x[7] + true_x[7];
   out_4501170633989036006[8] = -nom_x[8] + true_x[8];
   out_4501170633989036006[9] = -nom_x[9] + true_x[9];
   out_4501170633989036006[10] = -nom_x[10] + true_x[10];
   out_4501170633989036006[11] = -nom_x[11] + true_x[11];
   out_4501170633989036006[12] = -nom_x[12] + true_x[12];
   out_4501170633989036006[13] = -nom_x[13] + true_x[13];
   out_4501170633989036006[14] = -nom_x[14] + true_x[14];
   out_4501170633989036006[15] = -nom_x[15] + true_x[15];
   out_4501170633989036006[16] = -nom_x[16] + true_x[16];
   out_4501170633989036006[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_8502712302344637749) {
   out_8502712302344637749[0] = 1.0;
   out_8502712302344637749[1] = 0.0;
   out_8502712302344637749[2] = 0.0;
   out_8502712302344637749[3] = 0.0;
   out_8502712302344637749[4] = 0.0;
   out_8502712302344637749[5] = 0.0;
   out_8502712302344637749[6] = 0.0;
   out_8502712302344637749[7] = 0.0;
   out_8502712302344637749[8] = 0.0;
   out_8502712302344637749[9] = 0.0;
   out_8502712302344637749[10] = 0.0;
   out_8502712302344637749[11] = 0.0;
   out_8502712302344637749[12] = 0.0;
   out_8502712302344637749[13] = 0.0;
   out_8502712302344637749[14] = 0.0;
   out_8502712302344637749[15] = 0.0;
   out_8502712302344637749[16] = 0.0;
   out_8502712302344637749[17] = 0.0;
   out_8502712302344637749[18] = 0.0;
   out_8502712302344637749[19] = 1.0;
   out_8502712302344637749[20] = 0.0;
   out_8502712302344637749[21] = 0.0;
   out_8502712302344637749[22] = 0.0;
   out_8502712302344637749[23] = 0.0;
   out_8502712302344637749[24] = 0.0;
   out_8502712302344637749[25] = 0.0;
   out_8502712302344637749[26] = 0.0;
   out_8502712302344637749[27] = 0.0;
   out_8502712302344637749[28] = 0.0;
   out_8502712302344637749[29] = 0.0;
   out_8502712302344637749[30] = 0.0;
   out_8502712302344637749[31] = 0.0;
   out_8502712302344637749[32] = 0.0;
   out_8502712302344637749[33] = 0.0;
   out_8502712302344637749[34] = 0.0;
   out_8502712302344637749[35] = 0.0;
   out_8502712302344637749[36] = 0.0;
   out_8502712302344637749[37] = 0.0;
   out_8502712302344637749[38] = 1.0;
   out_8502712302344637749[39] = 0.0;
   out_8502712302344637749[40] = 0.0;
   out_8502712302344637749[41] = 0.0;
   out_8502712302344637749[42] = 0.0;
   out_8502712302344637749[43] = 0.0;
   out_8502712302344637749[44] = 0.0;
   out_8502712302344637749[45] = 0.0;
   out_8502712302344637749[46] = 0.0;
   out_8502712302344637749[47] = 0.0;
   out_8502712302344637749[48] = 0.0;
   out_8502712302344637749[49] = 0.0;
   out_8502712302344637749[50] = 0.0;
   out_8502712302344637749[51] = 0.0;
   out_8502712302344637749[52] = 0.0;
   out_8502712302344637749[53] = 0.0;
   out_8502712302344637749[54] = 0.0;
   out_8502712302344637749[55] = 0.0;
   out_8502712302344637749[56] = 0.0;
   out_8502712302344637749[57] = 1.0;
   out_8502712302344637749[58] = 0.0;
   out_8502712302344637749[59] = 0.0;
   out_8502712302344637749[60] = 0.0;
   out_8502712302344637749[61] = 0.0;
   out_8502712302344637749[62] = 0.0;
   out_8502712302344637749[63] = 0.0;
   out_8502712302344637749[64] = 0.0;
   out_8502712302344637749[65] = 0.0;
   out_8502712302344637749[66] = 0.0;
   out_8502712302344637749[67] = 0.0;
   out_8502712302344637749[68] = 0.0;
   out_8502712302344637749[69] = 0.0;
   out_8502712302344637749[70] = 0.0;
   out_8502712302344637749[71] = 0.0;
   out_8502712302344637749[72] = 0.0;
   out_8502712302344637749[73] = 0.0;
   out_8502712302344637749[74] = 0.0;
   out_8502712302344637749[75] = 0.0;
   out_8502712302344637749[76] = 1.0;
   out_8502712302344637749[77] = 0.0;
   out_8502712302344637749[78] = 0.0;
   out_8502712302344637749[79] = 0.0;
   out_8502712302344637749[80] = 0.0;
   out_8502712302344637749[81] = 0.0;
   out_8502712302344637749[82] = 0.0;
   out_8502712302344637749[83] = 0.0;
   out_8502712302344637749[84] = 0.0;
   out_8502712302344637749[85] = 0.0;
   out_8502712302344637749[86] = 0.0;
   out_8502712302344637749[87] = 0.0;
   out_8502712302344637749[88] = 0.0;
   out_8502712302344637749[89] = 0.0;
   out_8502712302344637749[90] = 0.0;
   out_8502712302344637749[91] = 0.0;
   out_8502712302344637749[92] = 0.0;
   out_8502712302344637749[93] = 0.0;
   out_8502712302344637749[94] = 0.0;
   out_8502712302344637749[95] = 1.0;
   out_8502712302344637749[96] = 0.0;
   out_8502712302344637749[97] = 0.0;
   out_8502712302344637749[98] = 0.0;
   out_8502712302344637749[99] = 0.0;
   out_8502712302344637749[100] = 0.0;
   out_8502712302344637749[101] = 0.0;
   out_8502712302344637749[102] = 0.0;
   out_8502712302344637749[103] = 0.0;
   out_8502712302344637749[104] = 0.0;
   out_8502712302344637749[105] = 0.0;
   out_8502712302344637749[106] = 0.0;
   out_8502712302344637749[107] = 0.0;
   out_8502712302344637749[108] = 0.0;
   out_8502712302344637749[109] = 0.0;
   out_8502712302344637749[110] = 0.0;
   out_8502712302344637749[111] = 0.0;
   out_8502712302344637749[112] = 0.0;
   out_8502712302344637749[113] = 0.0;
   out_8502712302344637749[114] = 1.0;
   out_8502712302344637749[115] = 0.0;
   out_8502712302344637749[116] = 0.0;
   out_8502712302344637749[117] = 0.0;
   out_8502712302344637749[118] = 0.0;
   out_8502712302344637749[119] = 0.0;
   out_8502712302344637749[120] = 0.0;
   out_8502712302344637749[121] = 0.0;
   out_8502712302344637749[122] = 0.0;
   out_8502712302344637749[123] = 0.0;
   out_8502712302344637749[124] = 0.0;
   out_8502712302344637749[125] = 0.0;
   out_8502712302344637749[126] = 0.0;
   out_8502712302344637749[127] = 0.0;
   out_8502712302344637749[128] = 0.0;
   out_8502712302344637749[129] = 0.0;
   out_8502712302344637749[130] = 0.0;
   out_8502712302344637749[131] = 0.0;
   out_8502712302344637749[132] = 0.0;
   out_8502712302344637749[133] = 1.0;
   out_8502712302344637749[134] = 0.0;
   out_8502712302344637749[135] = 0.0;
   out_8502712302344637749[136] = 0.0;
   out_8502712302344637749[137] = 0.0;
   out_8502712302344637749[138] = 0.0;
   out_8502712302344637749[139] = 0.0;
   out_8502712302344637749[140] = 0.0;
   out_8502712302344637749[141] = 0.0;
   out_8502712302344637749[142] = 0.0;
   out_8502712302344637749[143] = 0.0;
   out_8502712302344637749[144] = 0.0;
   out_8502712302344637749[145] = 0.0;
   out_8502712302344637749[146] = 0.0;
   out_8502712302344637749[147] = 0.0;
   out_8502712302344637749[148] = 0.0;
   out_8502712302344637749[149] = 0.0;
   out_8502712302344637749[150] = 0.0;
   out_8502712302344637749[151] = 0.0;
   out_8502712302344637749[152] = 1.0;
   out_8502712302344637749[153] = 0.0;
   out_8502712302344637749[154] = 0.0;
   out_8502712302344637749[155] = 0.0;
   out_8502712302344637749[156] = 0.0;
   out_8502712302344637749[157] = 0.0;
   out_8502712302344637749[158] = 0.0;
   out_8502712302344637749[159] = 0.0;
   out_8502712302344637749[160] = 0.0;
   out_8502712302344637749[161] = 0.0;
   out_8502712302344637749[162] = 0.0;
   out_8502712302344637749[163] = 0.0;
   out_8502712302344637749[164] = 0.0;
   out_8502712302344637749[165] = 0.0;
   out_8502712302344637749[166] = 0.0;
   out_8502712302344637749[167] = 0.0;
   out_8502712302344637749[168] = 0.0;
   out_8502712302344637749[169] = 0.0;
   out_8502712302344637749[170] = 0.0;
   out_8502712302344637749[171] = 1.0;
   out_8502712302344637749[172] = 0.0;
   out_8502712302344637749[173] = 0.0;
   out_8502712302344637749[174] = 0.0;
   out_8502712302344637749[175] = 0.0;
   out_8502712302344637749[176] = 0.0;
   out_8502712302344637749[177] = 0.0;
   out_8502712302344637749[178] = 0.0;
   out_8502712302344637749[179] = 0.0;
   out_8502712302344637749[180] = 0.0;
   out_8502712302344637749[181] = 0.0;
   out_8502712302344637749[182] = 0.0;
   out_8502712302344637749[183] = 0.0;
   out_8502712302344637749[184] = 0.0;
   out_8502712302344637749[185] = 0.0;
   out_8502712302344637749[186] = 0.0;
   out_8502712302344637749[187] = 0.0;
   out_8502712302344637749[188] = 0.0;
   out_8502712302344637749[189] = 0.0;
   out_8502712302344637749[190] = 1.0;
   out_8502712302344637749[191] = 0.0;
   out_8502712302344637749[192] = 0.0;
   out_8502712302344637749[193] = 0.0;
   out_8502712302344637749[194] = 0.0;
   out_8502712302344637749[195] = 0.0;
   out_8502712302344637749[196] = 0.0;
   out_8502712302344637749[197] = 0.0;
   out_8502712302344637749[198] = 0.0;
   out_8502712302344637749[199] = 0.0;
   out_8502712302344637749[200] = 0.0;
   out_8502712302344637749[201] = 0.0;
   out_8502712302344637749[202] = 0.0;
   out_8502712302344637749[203] = 0.0;
   out_8502712302344637749[204] = 0.0;
   out_8502712302344637749[205] = 0.0;
   out_8502712302344637749[206] = 0.0;
   out_8502712302344637749[207] = 0.0;
   out_8502712302344637749[208] = 0.0;
   out_8502712302344637749[209] = 1.0;
   out_8502712302344637749[210] = 0.0;
   out_8502712302344637749[211] = 0.0;
   out_8502712302344637749[212] = 0.0;
   out_8502712302344637749[213] = 0.0;
   out_8502712302344637749[214] = 0.0;
   out_8502712302344637749[215] = 0.0;
   out_8502712302344637749[216] = 0.0;
   out_8502712302344637749[217] = 0.0;
   out_8502712302344637749[218] = 0.0;
   out_8502712302344637749[219] = 0.0;
   out_8502712302344637749[220] = 0.0;
   out_8502712302344637749[221] = 0.0;
   out_8502712302344637749[222] = 0.0;
   out_8502712302344637749[223] = 0.0;
   out_8502712302344637749[224] = 0.0;
   out_8502712302344637749[225] = 0.0;
   out_8502712302344637749[226] = 0.0;
   out_8502712302344637749[227] = 0.0;
   out_8502712302344637749[228] = 1.0;
   out_8502712302344637749[229] = 0.0;
   out_8502712302344637749[230] = 0.0;
   out_8502712302344637749[231] = 0.0;
   out_8502712302344637749[232] = 0.0;
   out_8502712302344637749[233] = 0.0;
   out_8502712302344637749[234] = 0.0;
   out_8502712302344637749[235] = 0.0;
   out_8502712302344637749[236] = 0.0;
   out_8502712302344637749[237] = 0.0;
   out_8502712302344637749[238] = 0.0;
   out_8502712302344637749[239] = 0.0;
   out_8502712302344637749[240] = 0.0;
   out_8502712302344637749[241] = 0.0;
   out_8502712302344637749[242] = 0.0;
   out_8502712302344637749[243] = 0.0;
   out_8502712302344637749[244] = 0.0;
   out_8502712302344637749[245] = 0.0;
   out_8502712302344637749[246] = 0.0;
   out_8502712302344637749[247] = 1.0;
   out_8502712302344637749[248] = 0.0;
   out_8502712302344637749[249] = 0.0;
   out_8502712302344637749[250] = 0.0;
   out_8502712302344637749[251] = 0.0;
   out_8502712302344637749[252] = 0.0;
   out_8502712302344637749[253] = 0.0;
   out_8502712302344637749[254] = 0.0;
   out_8502712302344637749[255] = 0.0;
   out_8502712302344637749[256] = 0.0;
   out_8502712302344637749[257] = 0.0;
   out_8502712302344637749[258] = 0.0;
   out_8502712302344637749[259] = 0.0;
   out_8502712302344637749[260] = 0.0;
   out_8502712302344637749[261] = 0.0;
   out_8502712302344637749[262] = 0.0;
   out_8502712302344637749[263] = 0.0;
   out_8502712302344637749[264] = 0.0;
   out_8502712302344637749[265] = 0.0;
   out_8502712302344637749[266] = 1.0;
   out_8502712302344637749[267] = 0.0;
   out_8502712302344637749[268] = 0.0;
   out_8502712302344637749[269] = 0.0;
   out_8502712302344637749[270] = 0.0;
   out_8502712302344637749[271] = 0.0;
   out_8502712302344637749[272] = 0.0;
   out_8502712302344637749[273] = 0.0;
   out_8502712302344637749[274] = 0.0;
   out_8502712302344637749[275] = 0.0;
   out_8502712302344637749[276] = 0.0;
   out_8502712302344637749[277] = 0.0;
   out_8502712302344637749[278] = 0.0;
   out_8502712302344637749[279] = 0.0;
   out_8502712302344637749[280] = 0.0;
   out_8502712302344637749[281] = 0.0;
   out_8502712302344637749[282] = 0.0;
   out_8502712302344637749[283] = 0.0;
   out_8502712302344637749[284] = 0.0;
   out_8502712302344637749[285] = 1.0;
   out_8502712302344637749[286] = 0.0;
   out_8502712302344637749[287] = 0.0;
   out_8502712302344637749[288] = 0.0;
   out_8502712302344637749[289] = 0.0;
   out_8502712302344637749[290] = 0.0;
   out_8502712302344637749[291] = 0.0;
   out_8502712302344637749[292] = 0.0;
   out_8502712302344637749[293] = 0.0;
   out_8502712302344637749[294] = 0.0;
   out_8502712302344637749[295] = 0.0;
   out_8502712302344637749[296] = 0.0;
   out_8502712302344637749[297] = 0.0;
   out_8502712302344637749[298] = 0.0;
   out_8502712302344637749[299] = 0.0;
   out_8502712302344637749[300] = 0.0;
   out_8502712302344637749[301] = 0.0;
   out_8502712302344637749[302] = 0.0;
   out_8502712302344637749[303] = 0.0;
   out_8502712302344637749[304] = 1.0;
   out_8502712302344637749[305] = 0.0;
   out_8502712302344637749[306] = 0.0;
   out_8502712302344637749[307] = 0.0;
   out_8502712302344637749[308] = 0.0;
   out_8502712302344637749[309] = 0.0;
   out_8502712302344637749[310] = 0.0;
   out_8502712302344637749[311] = 0.0;
   out_8502712302344637749[312] = 0.0;
   out_8502712302344637749[313] = 0.0;
   out_8502712302344637749[314] = 0.0;
   out_8502712302344637749[315] = 0.0;
   out_8502712302344637749[316] = 0.0;
   out_8502712302344637749[317] = 0.0;
   out_8502712302344637749[318] = 0.0;
   out_8502712302344637749[319] = 0.0;
   out_8502712302344637749[320] = 0.0;
   out_8502712302344637749[321] = 0.0;
   out_8502712302344637749[322] = 0.0;
   out_8502712302344637749[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_3812607681717002176) {
   out_3812607681717002176[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_3812607681717002176[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_3812607681717002176[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_3812607681717002176[3] = dt*state[12] + state[3];
   out_3812607681717002176[4] = dt*state[13] + state[4];
   out_3812607681717002176[5] = dt*state[14] + state[5];
   out_3812607681717002176[6] = state[6];
   out_3812607681717002176[7] = state[7];
   out_3812607681717002176[8] = state[8];
   out_3812607681717002176[9] = state[9];
   out_3812607681717002176[10] = state[10];
   out_3812607681717002176[11] = state[11];
   out_3812607681717002176[12] = state[12];
   out_3812607681717002176[13] = state[13];
   out_3812607681717002176[14] = state[14];
   out_3812607681717002176[15] = state[15];
   out_3812607681717002176[16] = state[16];
   out_3812607681717002176[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2792835002777004096) {
   out_2792835002777004096[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2792835002777004096[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2792835002777004096[2] = 0;
   out_2792835002777004096[3] = 0;
   out_2792835002777004096[4] = 0;
   out_2792835002777004096[5] = 0;
   out_2792835002777004096[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2792835002777004096[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2792835002777004096[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2792835002777004096[9] = 0;
   out_2792835002777004096[10] = 0;
   out_2792835002777004096[11] = 0;
   out_2792835002777004096[12] = 0;
   out_2792835002777004096[13] = 0;
   out_2792835002777004096[14] = 0;
   out_2792835002777004096[15] = 0;
   out_2792835002777004096[16] = 0;
   out_2792835002777004096[17] = 0;
   out_2792835002777004096[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2792835002777004096[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2792835002777004096[20] = 0;
   out_2792835002777004096[21] = 0;
   out_2792835002777004096[22] = 0;
   out_2792835002777004096[23] = 0;
   out_2792835002777004096[24] = 0;
   out_2792835002777004096[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2792835002777004096[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2792835002777004096[27] = 0;
   out_2792835002777004096[28] = 0;
   out_2792835002777004096[29] = 0;
   out_2792835002777004096[30] = 0;
   out_2792835002777004096[31] = 0;
   out_2792835002777004096[32] = 0;
   out_2792835002777004096[33] = 0;
   out_2792835002777004096[34] = 0;
   out_2792835002777004096[35] = 0;
   out_2792835002777004096[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2792835002777004096[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2792835002777004096[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2792835002777004096[39] = 0;
   out_2792835002777004096[40] = 0;
   out_2792835002777004096[41] = 0;
   out_2792835002777004096[42] = 0;
   out_2792835002777004096[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2792835002777004096[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2792835002777004096[45] = 0;
   out_2792835002777004096[46] = 0;
   out_2792835002777004096[47] = 0;
   out_2792835002777004096[48] = 0;
   out_2792835002777004096[49] = 0;
   out_2792835002777004096[50] = 0;
   out_2792835002777004096[51] = 0;
   out_2792835002777004096[52] = 0;
   out_2792835002777004096[53] = 0;
   out_2792835002777004096[54] = 0;
   out_2792835002777004096[55] = 0;
   out_2792835002777004096[56] = 0;
   out_2792835002777004096[57] = 1;
   out_2792835002777004096[58] = 0;
   out_2792835002777004096[59] = 0;
   out_2792835002777004096[60] = 0;
   out_2792835002777004096[61] = 0;
   out_2792835002777004096[62] = 0;
   out_2792835002777004096[63] = 0;
   out_2792835002777004096[64] = 0;
   out_2792835002777004096[65] = 0;
   out_2792835002777004096[66] = dt;
   out_2792835002777004096[67] = 0;
   out_2792835002777004096[68] = 0;
   out_2792835002777004096[69] = 0;
   out_2792835002777004096[70] = 0;
   out_2792835002777004096[71] = 0;
   out_2792835002777004096[72] = 0;
   out_2792835002777004096[73] = 0;
   out_2792835002777004096[74] = 0;
   out_2792835002777004096[75] = 0;
   out_2792835002777004096[76] = 1;
   out_2792835002777004096[77] = 0;
   out_2792835002777004096[78] = 0;
   out_2792835002777004096[79] = 0;
   out_2792835002777004096[80] = 0;
   out_2792835002777004096[81] = 0;
   out_2792835002777004096[82] = 0;
   out_2792835002777004096[83] = 0;
   out_2792835002777004096[84] = 0;
   out_2792835002777004096[85] = dt;
   out_2792835002777004096[86] = 0;
   out_2792835002777004096[87] = 0;
   out_2792835002777004096[88] = 0;
   out_2792835002777004096[89] = 0;
   out_2792835002777004096[90] = 0;
   out_2792835002777004096[91] = 0;
   out_2792835002777004096[92] = 0;
   out_2792835002777004096[93] = 0;
   out_2792835002777004096[94] = 0;
   out_2792835002777004096[95] = 1;
   out_2792835002777004096[96] = 0;
   out_2792835002777004096[97] = 0;
   out_2792835002777004096[98] = 0;
   out_2792835002777004096[99] = 0;
   out_2792835002777004096[100] = 0;
   out_2792835002777004096[101] = 0;
   out_2792835002777004096[102] = 0;
   out_2792835002777004096[103] = 0;
   out_2792835002777004096[104] = dt;
   out_2792835002777004096[105] = 0;
   out_2792835002777004096[106] = 0;
   out_2792835002777004096[107] = 0;
   out_2792835002777004096[108] = 0;
   out_2792835002777004096[109] = 0;
   out_2792835002777004096[110] = 0;
   out_2792835002777004096[111] = 0;
   out_2792835002777004096[112] = 0;
   out_2792835002777004096[113] = 0;
   out_2792835002777004096[114] = 1;
   out_2792835002777004096[115] = 0;
   out_2792835002777004096[116] = 0;
   out_2792835002777004096[117] = 0;
   out_2792835002777004096[118] = 0;
   out_2792835002777004096[119] = 0;
   out_2792835002777004096[120] = 0;
   out_2792835002777004096[121] = 0;
   out_2792835002777004096[122] = 0;
   out_2792835002777004096[123] = 0;
   out_2792835002777004096[124] = 0;
   out_2792835002777004096[125] = 0;
   out_2792835002777004096[126] = 0;
   out_2792835002777004096[127] = 0;
   out_2792835002777004096[128] = 0;
   out_2792835002777004096[129] = 0;
   out_2792835002777004096[130] = 0;
   out_2792835002777004096[131] = 0;
   out_2792835002777004096[132] = 0;
   out_2792835002777004096[133] = 1;
   out_2792835002777004096[134] = 0;
   out_2792835002777004096[135] = 0;
   out_2792835002777004096[136] = 0;
   out_2792835002777004096[137] = 0;
   out_2792835002777004096[138] = 0;
   out_2792835002777004096[139] = 0;
   out_2792835002777004096[140] = 0;
   out_2792835002777004096[141] = 0;
   out_2792835002777004096[142] = 0;
   out_2792835002777004096[143] = 0;
   out_2792835002777004096[144] = 0;
   out_2792835002777004096[145] = 0;
   out_2792835002777004096[146] = 0;
   out_2792835002777004096[147] = 0;
   out_2792835002777004096[148] = 0;
   out_2792835002777004096[149] = 0;
   out_2792835002777004096[150] = 0;
   out_2792835002777004096[151] = 0;
   out_2792835002777004096[152] = 1;
   out_2792835002777004096[153] = 0;
   out_2792835002777004096[154] = 0;
   out_2792835002777004096[155] = 0;
   out_2792835002777004096[156] = 0;
   out_2792835002777004096[157] = 0;
   out_2792835002777004096[158] = 0;
   out_2792835002777004096[159] = 0;
   out_2792835002777004096[160] = 0;
   out_2792835002777004096[161] = 0;
   out_2792835002777004096[162] = 0;
   out_2792835002777004096[163] = 0;
   out_2792835002777004096[164] = 0;
   out_2792835002777004096[165] = 0;
   out_2792835002777004096[166] = 0;
   out_2792835002777004096[167] = 0;
   out_2792835002777004096[168] = 0;
   out_2792835002777004096[169] = 0;
   out_2792835002777004096[170] = 0;
   out_2792835002777004096[171] = 1;
   out_2792835002777004096[172] = 0;
   out_2792835002777004096[173] = 0;
   out_2792835002777004096[174] = 0;
   out_2792835002777004096[175] = 0;
   out_2792835002777004096[176] = 0;
   out_2792835002777004096[177] = 0;
   out_2792835002777004096[178] = 0;
   out_2792835002777004096[179] = 0;
   out_2792835002777004096[180] = 0;
   out_2792835002777004096[181] = 0;
   out_2792835002777004096[182] = 0;
   out_2792835002777004096[183] = 0;
   out_2792835002777004096[184] = 0;
   out_2792835002777004096[185] = 0;
   out_2792835002777004096[186] = 0;
   out_2792835002777004096[187] = 0;
   out_2792835002777004096[188] = 0;
   out_2792835002777004096[189] = 0;
   out_2792835002777004096[190] = 1;
   out_2792835002777004096[191] = 0;
   out_2792835002777004096[192] = 0;
   out_2792835002777004096[193] = 0;
   out_2792835002777004096[194] = 0;
   out_2792835002777004096[195] = 0;
   out_2792835002777004096[196] = 0;
   out_2792835002777004096[197] = 0;
   out_2792835002777004096[198] = 0;
   out_2792835002777004096[199] = 0;
   out_2792835002777004096[200] = 0;
   out_2792835002777004096[201] = 0;
   out_2792835002777004096[202] = 0;
   out_2792835002777004096[203] = 0;
   out_2792835002777004096[204] = 0;
   out_2792835002777004096[205] = 0;
   out_2792835002777004096[206] = 0;
   out_2792835002777004096[207] = 0;
   out_2792835002777004096[208] = 0;
   out_2792835002777004096[209] = 1;
   out_2792835002777004096[210] = 0;
   out_2792835002777004096[211] = 0;
   out_2792835002777004096[212] = 0;
   out_2792835002777004096[213] = 0;
   out_2792835002777004096[214] = 0;
   out_2792835002777004096[215] = 0;
   out_2792835002777004096[216] = 0;
   out_2792835002777004096[217] = 0;
   out_2792835002777004096[218] = 0;
   out_2792835002777004096[219] = 0;
   out_2792835002777004096[220] = 0;
   out_2792835002777004096[221] = 0;
   out_2792835002777004096[222] = 0;
   out_2792835002777004096[223] = 0;
   out_2792835002777004096[224] = 0;
   out_2792835002777004096[225] = 0;
   out_2792835002777004096[226] = 0;
   out_2792835002777004096[227] = 0;
   out_2792835002777004096[228] = 1;
   out_2792835002777004096[229] = 0;
   out_2792835002777004096[230] = 0;
   out_2792835002777004096[231] = 0;
   out_2792835002777004096[232] = 0;
   out_2792835002777004096[233] = 0;
   out_2792835002777004096[234] = 0;
   out_2792835002777004096[235] = 0;
   out_2792835002777004096[236] = 0;
   out_2792835002777004096[237] = 0;
   out_2792835002777004096[238] = 0;
   out_2792835002777004096[239] = 0;
   out_2792835002777004096[240] = 0;
   out_2792835002777004096[241] = 0;
   out_2792835002777004096[242] = 0;
   out_2792835002777004096[243] = 0;
   out_2792835002777004096[244] = 0;
   out_2792835002777004096[245] = 0;
   out_2792835002777004096[246] = 0;
   out_2792835002777004096[247] = 1;
   out_2792835002777004096[248] = 0;
   out_2792835002777004096[249] = 0;
   out_2792835002777004096[250] = 0;
   out_2792835002777004096[251] = 0;
   out_2792835002777004096[252] = 0;
   out_2792835002777004096[253] = 0;
   out_2792835002777004096[254] = 0;
   out_2792835002777004096[255] = 0;
   out_2792835002777004096[256] = 0;
   out_2792835002777004096[257] = 0;
   out_2792835002777004096[258] = 0;
   out_2792835002777004096[259] = 0;
   out_2792835002777004096[260] = 0;
   out_2792835002777004096[261] = 0;
   out_2792835002777004096[262] = 0;
   out_2792835002777004096[263] = 0;
   out_2792835002777004096[264] = 0;
   out_2792835002777004096[265] = 0;
   out_2792835002777004096[266] = 1;
   out_2792835002777004096[267] = 0;
   out_2792835002777004096[268] = 0;
   out_2792835002777004096[269] = 0;
   out_2792835002777004096[270] = 0;
   out_2792835002777004096[271] = 0;
   out_2792835002777004096[272] = 0;
   out_2792835002777004096[273] = 0;
   out_2792835002777004096[274] = 0;
   out_2792835002777004096[275] = 0;
   out_2792835002777004096[276] = 0;
   out_2792835002777004096[277] = 0;
   out_2792835002777004096[278] = 0;
   out_2792835002777004096[279] = 0;
   out_2792835002777004096[280] = 0;
   out_2792835002777004096[281] = 0;
   out_2792835002777004096[282] = 0;
   out_2792835002777004096[283] = 0;
   out_2792835002777004096[284] = 0;
   out_2792835002777004096[285] = 1;
   out_2792835002777004096[286] = 0;
   out_2792835002777004096[287] = 0;
   out_2792835002777004096[288] = 0;
   out_2792835002777004096[289] = 0;
   out_2792835002777004096[290] = 0;
   out_2792835002777004096[291] = 0;
   out_2792835002777004096[292] = 0;
   out_2792835002777004096[293] = 0;
   out_2792835002777004096[294] = 0;
   out_2792835002777004096[295] = 0;
   out_2792835002777004096[296] = 0;
   out_2792835002777004096[297] = 0;
   out_2792835002777004096[298] = 0;
   out_2792835002777004096[299] = 0;
   out_2792835002777004096[300] = 0;
   out_2792835002777004096[301] = 0;
   out_2792835002777004096[302] = 0;
   out_2792835002777004096[303] = 0;
   out_2792835002777004096[304] = 1;
   out_2792835002777004096[305] = 0;
   out_2792835002777004096[306] = 0;
   out_2792835002777004096[307] = 0;
   out_2792835002777004096[308] = 0;
   out_2792835002777004096[309] = 0;
   out_2792835002777004096[310] = 0;
   out_2792835002777004096[311] = 0;
   out_2792835002777004096[312] = 0;
   out_2792835002777004096[313] = 0;
   out_2792835002777004096[314] = 0;
   out_2792835002777004096[315] = 0;
   out_2792835002777004096[316] = 0;
   out_2792835002777004096[317] = 0;
   out_2792835002777004096[318] = 0;
   out_2792835002777004096[319] = 0;
   out_2792835002777004096[320] = 0;
   out_2792835002777004096[321] = 0;
   out_2792835002777004096[322] = 0;
   out_2792835002777004096[323] = 1;
}
void h_4(double *state, double *unused, double *out_1436781500686272226) {
   out_1436781500686272226[0] = state[6] + state[9];
   out_1436781500686272226[1] = state[7] + state[10];
   out_1436781500686272226[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_5228490223553688496) {
   out_5228490223553688496[0] = 0;
   out_5228490223553688496[1] = 0;
   out_5228490223553688496[2] = 0;
   out_5228490223553688496[3] = 0;
   out_5228490223553688496[4] = 0;
   out_5228490223553688496[5] = 0;
   out_5228490223553688496[6] = 1;
   out_5228490223553688496[7] = 0;
   out_5228490223553688496[8] = 0;
   out_5228490223553688496[9] = 1;
   out_5228490223553688496[10] = 0;
   out_5228490223553688496[11] = 0;
   out_5228490223553688496[12] = 0;
   out_5228490223553688496[13] = 0;
   out_5228490223553688496[14] = 0;
   out_5228490223553688496[15] = 0;
   out_5228490223553688496[16] = 0;
   out_5228490223553688496[17] = 0;
   out_5228490223553688496[18] = 0;
   out_5228490223553688496[19] = 0;
   out_5228490223553688496[20] = 0;
   out_5228490223553688496[21] = 0;
   out_5228490223553688496[22] = 0;
   out_5228490223553688496[23] = 0;
   out_5228490223553688496[24] = 0;
   out_5228490223553688496[25] = 1;
   out_5228490223553688496[26] = 0;
   out_5228490223553688496[27] = 0;
   out_5228490223553688496[28] = 1;
   out_5228490223553688496[29] = 0;
   out_5228490223553688496[30] = 0;
   out_5228490223553688496[31] = 0;
   out_5228490223553688496[32] = 0;
   out_5228490223553688496[33] = 0;
   out_5228490223553688496[34] = 0;
   out_5228490223553688496[35] = 0;
   out_5228490223553688496[36] = 0;
   out_5228490223553688496[37] = 0;
   out_5228490223553688496[38] = 0;
   out_5228490223553688496[39] = 0;
   out_5228490223553688496[40] = 0;
   out_5228490223553688496[41] = 0;
   out_5228490223553688496[42] = 0;
   out_5228490223553688496[43] = 0;
   out_5228490223553688496[44] = 1;
   out_5228490223553688496[45] = 0;
   out_5228490223553688496[46] = 0;
   out_5228490223553688496[47] = 1;
   out_5228490223553688496[48] = 0;
   out_5228490223553688496[49] = 0;
   out_5228490223553688496[50] = 0;
   out_5228490223553688496[51] = 0;
   out_5228490223553688496[52] = 0;
   out_5228490223553688496[53] = 0;
}
void h_10(double *state, double *unused, double *out_5194169306934239483) {
   out_5194169306934239483[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5194169306934239483[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5194169306934239483[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_5423213404703357435) {
   out_5423213404703357435[0] = 0;
   out_5423213404703357435[1] = 9.8100000000000005*cos(state[1]);
   out_5423213404703357435[2] = 0;
   out_5423213404703357435[3] = 0;
   out_5423213404703357435[4] = -state[8];
   out_5423213404703357435[5] = state[7];
   out_5423213404703357435[6] = 0;
   out_5423213404703357435[7] = state[5];
   out_5423213404703357435[8] = -state[4];
   out_5423213404703357435[9] = 0;
   out_5423213404703357435[10] = 0;
   out_5423213404703357435[11] = 0;
   out_5423213404703357435[12] = 1;
   out_5423213404703357435[13] = 0;
   out_5423213404703357435[14] = 0;
   out_5423213404703357435[15] = 1;
   out_5423213404703357435[16] = 0;
   out_5423213404703357435[17] = 0;
   out_5423213404703357435[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_5423213404703357435[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_5423213404703357435[20] = 0;
   out_5423213404703357435[21] = state[8];
   out_5423213404703357435[22] = 0;
   out_5423213404703357435[23] = -state[6];
   out_5423213404703357435[24] = -state[5];
   out_5423213404703357435[25] = 0;
   out_5423213404703357435[26] = state[3];
   out_5423213404703357435[27] = 0;
   out_5423213404703357435[28] = 0;
   out_5423213404703357435[29] = 0;
   out_5423213404703357435[30] = 0;
   out_5423213404703357435[31] = 1;
   out_5423213404703357435[32] = 0;
   out_5423213404703357435[33] = 0;
   out_5423213404703357435[34] = 1;
   out_5423213404703357435[35] = 0;
   out_5423213404703357435[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_5423213404703357435[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_5423213404703357435[38] = 0;
   out_5423213404703357435[39] = -state[7];
   out_5423213404703357435[40] = state[6];
   out_5423213404703357435[41] = 0;
   out_5423213404703357435[42] = state[4];
   out_5423213404703357435[43] = -state[3];
   out_5423213404703357435[44] = 0;
   out_5423213404703357435[45] = 0;
   out_5423213404703357435[46] = 0;
   out_5423213404703357435[47] = 0;
   out_5423213404703357435[48] = 0;
   out_5423213404703357435[49] = 0;
   out_5423213404703357435[50] = 1;
   out_5423213404703357435[51] = 0;
   out_5423213404703357435[52] = 0;
   out_5423213404703357435[53] = 1;
}
void h_13(double *state, double *unused, double *out_5070288323570698443) {
   out_5070288323570698443[0] = state[3];
   out_5070288323570698443[1] = state[4];
   out_5070288323570698443[2] = state[5];
}
void H_13(double *state, double *unused, double *out_5607622641839162191) {
   out_5607622641839162191[0] = 0;
   out_5607622641839162191[1] = 0;
   out_5607622641839162191[2] = 0;
   out_5607622641839162191[3] = 1;
   out_5607622641839162191[4] = 0;
   out_5607622641839162191[5] = 0;
   out_5607622641839162191[6] = 0;
   out_5607622641839162191[7] = 0;
   out_5607622641839162191[8] = 0;
   out_5607622641839162191[9] = 0;
   out_5607622641839162191[10] = 0;
   out_5607622641839162191[11] = 0;
   out_5607622641839162191[12] = 0;
   out_5607622641839162191[13] = 0;
   out_5607622641839162191[14] = 0;
   out_5607622641839162191[15] = 0;
   out_5607622641839162191[16] = 0;
   out_5607622641839162191[17] = 0;
   out_5607622641839162191[18] = 0;
   out_5607622641839162191[19] = 0;
   out_5607622641839162191[20] = 0;
   out_5607622641839162191[21] = 0;
   out_5607622641839162191[22] = 1;
   out_5607622641839162191[23] = 0;
   out_5607622641839162191[24] = 0;
   out_5607622641839162191[25] = 0;
   out_5607622641839162191[26] = 0;
   out_5607622641839162191[27] = 0;
   out_5607622641839162191[28] = 0;
   out_5607622641839162191[29] = 0;
   out_5607622641839162191[30] = 0;
   out_5607622641839162191[31] = 0;
   out_5607622641839162191[32] = 0;
   out_5607622641839162191[33] = 0;
   out_5607622641839162191[34] = 0;
   out_5607622641839162191[35] = 0;
   out_5607622641839162191[36] = 0;
   out_5607622641839162191[37] = 0;
   out_5607622641839162191[38] = 0;
   out_5607622641839162191[39] = 0;
   out_5607622641839162191[40] = 0;
   out_5607622641839162191[41] = 1;
   out_5607622641839162191[42] = 0;
   out_5607622641839162191[43] = 0;
   out_5607622641839162191[44] = 0;
   out_5607622641839162191[45] = 0;
   out_5607622641839162191[46] = 0;
   out_5607622641839162191[47] = 0;
   out_5607622641839162191[48] = 0;
   out_5607622641839162191[49] = 0;
   out_5607622641839162191[50] = 0;
   out_5607622641839162191[51] = 0;
   out_5607622641839162191[52] = 0;
   out_5607622641839162191[53] = 0;
}
void h_14(double *state, double *unused, double *out_2853207577681860036) {
   out_2853207577681860036[0] = state[6];
   out_2853207577681860036[1] = state[7];
   out_2853207577681860036[2] = state[8];
}
void H_14(double *state, double *unused, double *out_9191731079893173025) {
   out_9191731079893173025[0] = 0;
   out_9191731079893173025[1] = 0;
   out_9191731079893173025[2] = 0;
   out_9191731079893173025[3] = 0;
   out_9191731079893173025[4] = 0;
   out_9191731079893173025[5] = 0;
   out_9191731079893173025[6] = 1;
   out_9191731079893173025[7] = 0;
   out_9191731079893173025[8] = 0;
   out_9191731079893173025[9] = 0;
   out_9191731079893173025[10] = 0;
   out_9191731079893173025[11] = 0;
   out_9191731079893173025[12] = 0;
   out_9191731079893173025[13] = 0;
   out_9191731079893173025[14] = 0;
   out_9191731079893173025[15] = 0;
   out_9191731079893173025[16] = 0;
   out_9191731079893173025[17] = 0;
   out_9191731079893173025[18] = 0;
   out_9191731079893173025[19] = 0;
   out_9191731079893173025[20] = 0;
   out_9191731079893173025[21] = 0;
   out_9191731079893173025[22] = 0;
   out_9191731079893173025[23] = 0;
   out_9191731079893173025[24] = 0;
   out_9191731079893173025[25] = 1;
   out_9191731079893173025[26] = 0;
   out_9191731079893173025[27] = 0;
   out_9191731079893173025[28] = 0;
   out_9191731079893173025[29] = 0;
   out_9191731079893173025[30] = 0;
   out_9191731079893173025[31] = 0;
   out_9191731079893173025[32] = 0;
   out_9191731079893173025[33] = 0;
   out_9191731079893173025[34] = 0;
   out_9191731079893173025[35] = 0;
   out_9191731079893173025[36] = 0;
   out_9191731079893173025[37] = 0;
   out_9191731079893173025[38] = 0;
   out_9191731079893173025[39] = 0;
   out_9191731079893173025[40] = 0;
   out_9191731079893173025[41] = 0;
   out_9191731079893173025[42] = 0;
   out_9191731079893173025[43] = 0;
   out_9191731079893173025[44] = 1;
   out_9191731079893173025[45] = 0;
   out_9191731079893173025[46] = 0;
   out_9191731079893173025[47] = 0;
   out_9191731079893173025[48] = 0;
   out_9191731079893173025[49] = 0;
   out_9191731079893173025[50] = 0;
   out_9191731079893173025[51] = 0;
   out_9191731079893173025[52] = 0;
   out_9191731079893173025[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_2996101941373283621) {
  err_fun(nom_x, delta_x, out_2996101941373283621);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4501170633989036006) {
  inv_err_fun(nom_x, true_x, out_4501170633989036006);
}
void pose_H_mod_fun(double *state, double *out_8502712302344637749) {
  H_mod_fun(state, out_8502712302344637749);
}
void pose_f_fun(double *state, double dt, double *out_3812607681717002176) {
  f_fun(state,  dt, out_3812607681717002176);
}
void pose_F_fun(double *state, double dt, double *out_2792835002777004096) {
  F_fun(state,  dt, out_2792835002777004096);
}
void pose_h_4(double *state, double *unused, double *out_1436781500686272226) {
  h_4(state, unused, out_1436781500686272226);
}
void pose_H_4(double *state, double *unused, double *out_5228490223553688496) {
  H_4(state, unused, out_5228490223553688496);
}
void pose_h_10(double *state, double *unused, double *out_5194169306934239483) {
  h_10(state, unused, out_5194169306934239483);
}
void pose_H_10(double *state, double *unused, double *out_5423213404703357435) {
  H_10(state, unused, out_5423213404703357435);
}
void pose_h_13(double *state, double *unused, double *out_5070288323570698443) {
  h_13(state, unused, out_5070288323570698443);
}
void pose_H_13(double *state, double *unused, double *out_5607622641839162191) {
  H_13(state, unused, out_5607622641839162191);
}
void pose_h_14(double *state, double *unused, double *out_2853207577681860036) {
  h_14(state, unused, out_2853207577681860036);
}
void pose_H_14(double *state, double *unused, double *out_9191731079893173025) {
  H_14(state, unused, out_9191731079893173025);
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
