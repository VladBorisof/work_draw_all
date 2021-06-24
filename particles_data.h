//
// Created by vlad on 16.12.2020.
//


#ifndef PARTICLES_DATA
#define PARTICLES_DATA

#include "FormatOfEverything.h"

// 0 - cuau, 1 - uu, 2 - heau, 3 - pau, 4 - pal, 5 - cucu, 6 - dau;

const int num_of_syst = 7;
double typec_kstar[num_of_syst][5] = {
        {0.1,   0.1,   0.125, 0.2,  0.11},
        {0.085, 0.120, 0.150, 0.185},
        {0.1,   0.135, 0.12,  0.2,  0.11},
        {0.075, 0.08,  0.75,  0.1,  0.06},
        {0.06,  0.07,  0.09,  0.06, 0.05},
        {0.085, 0.09,  0.09,  0.09},
        {}
};

TString abcd[] = {"(a)", "(b)", "(c)", "(d)"};

TString centrality[num_of_syst][5] = {
        {"0-20%", "20-40%", "40-60%", "60-80%", "0-90%"},
        {"0-20%", "20-40%", "40-80%", "0-80%"},
        {"0-20%", "20-40%", "40-60%", "60-88%", "0-88%"},
        {"0-20%", "20-40%", "40-84%", "0-84%"},
        {"0-20%", "20-40%", "40-72%", "0-72%"},
};

double pt_kstar[num_of_syst][15] = {
        {2.00, 2.20, 2.45, 2.75, 3.15, 3.70, 4.25, 4.75, 5.75},
        {1.55, 1.80, 2.00, 2.20, 2.45, 2.75, 3.15, 3.70, 4.25},
        {1.55, 1.80, 2.00, 2.20, 2.45, 2.75, 3.15, 3.70, 4.25, 4.75, 5.75},
        {1.55, 1.80, 2.00, 2.20, 2.45, 2.75, 3.15, 3.70, 4.25},
        {1.55, 1.80, 2.00, 2.20, 2.45, 2.75, 3.15},
        {1.55, 1.80, 2.00, 2.20, 2.45, 2.75, 3.15, 3.70, 4.25, 4.75, 5.5,  7.0},
        {1.3,  1.55, 1.80, 2.00, 2.20, 2.45, 2.75, 3.15, 3.70, 4.25, 4.75, 5.75, 7.50},
};

double pt_phi[num_of_syst][12] = {
        {1.45, 1.95, 2.45, 2.95, 3.45, 3.95, 4.45, 5.5, 7.0}, // cuau
        {1,1,1,1,1,1,11}, // uu
        {1.1, 1.45, 1.95, 2.45, 2.95, 3.45, 3.95, 4.45, 5.50, 7.00}, //heau
        {1.1, 1.45, 1.95, 2.45, 2.95, 3.45, 3.95}, // pau
        {1.45, 1.95, 2.45, 2.95, 3.45, 3.95}, // pal

};


double pt_pi0[num_of_syst][14] = {
        {1.25, 1.75, 2.25, 2.75, 3.25, 3.75, 4.25, 4.75, 5.25, 5.75, 6.25}, // cuau
        {1.25, 1.75, 2.25, 2.75, 3.25, 3.75, 4.25, 4.75, 5.25, 5.75, 6.25}, // uu
        {1.25, 1.75, 2.25, 2.75, 3.25, 3.75, 4.25, 4.75, 5.25, 5.75, 6.25, 6.75, 7.25, 7.75}, // heau
        {1.25, 1.75, 2.25, 2.75, 3.25, 3.75, 4.25}, // pau
        {1.25, 1.75, 2.25, 2.75, 3.25, 3.75, 4.25, 4.75}, // pal

};

double pt_eta[2][15] = {
        {2.25, 2.75, 3.25, 3.75, 4.25, 4.75, 5.5, 6.5, 7.5, 8.5}, // cuau
        {2.25, 2.75, 3.25, 3.75, 4.25, 4.75, 5.5, 6.5, 7.5}, //uu
};

double npart_kstar[num_of_syst][5] = {
        {154.8, 80.37, 34.92, 11.54, 61.3},
        {330,   159,   41,    165},
        {86,    45,    24,    6,     35},
        {}
};

const int n_kstar_cuau = 9;
double yields_kstar_cuau[3][5][n_kstar_cuau] = {
        {
                {0.0487772,  0.0324595,  0.0135841,  0.00695873,  0.00294224,  0.000922384, 0.000235366, 0.000112359, 1.09823e-05},
                {0.0200749,  0.0138134,  0.00571338,  0.00318633,  0.00128835,  0.000450369, 0.000112463, 5.83839e-05, 5.35731e-06},
                {0.00806967,  0.00558784,  0.00225338,  0.00119335,  0.00045572,  0.000167206, 4.42279e-05, 2.3941e-05,  2.24711e-06},
                {0.00179607,  0.00126872,  0.000516295, 0.000266019, 0.00010487,  3.89084e-05, 1.13817e-05, 6.18369e-06, 6.02321e-07},
                {0.0165274,  0.0112309,  0.00497922,  0.00273041,  0.00110788,  0.000389731, 0.00011368,  5.44544e-05, 5.39507e-06}
        },
        {
                {0.00363355, 0.00197619, 0.00123179, 0.000588042, 0.00013519,  5.17408e-05, 2.08896e-05, 1.14314e-05, 1.4745e-06},
                {0.00180691, 0.00120673, 0.000899718, 0.000172188, 6.54827e-05, 2.32249e-05, 1.03938e-05, 5.67847e-06, 7.49344e-07},
                {0.000444546, 0.000321674, 0.000239479, 7.8591e-05,  3.04309e-05, 9.68493e-06, 4.72885e-06, 2.54338e-06, 4.43114e-07},
                {0.000200592, 0.00011367,  8.477e-05,   2.98982e-05, 9.55981e-06, 3.6041e-06,  1.73904e-06, 9.30146e-07, 1.47508e-07},
                {0.00154191, 0.00155967, 0.000330734, 8.0905e-05,  4.09714e-05, 1.49389e-05, 9.95392e-06, 4.92365e-06, 6.31313e-07}
        },
        {
                {0.00467873, 0.00325009, 0.00143776, 0.000788063, 0.000348507, 0.000122214, 3.45515e-05, 1.7931e-05,  2.03333e-06},
                {0.0018538,  0.00127504, 0.000531897, 0.000303478, 0.000120147, 4.54789e-05, 1.2559e-05,  7.21194e-06, 8.28236e-07},
                {0.000734468, 0.000533757, 0.000229598, 0.000131851, 5.37356e-05, 2.2814e-05,  6.92852e-06, 4.21566e-06, 4.91079e-07},
                {0.000213847, 0.000155342, 6.5831e-05,  3.58542e-05, 1.48764e-05, 6.22296e-06, 2.06362e-06, 1.25709e-06, 1.537e-07},
                {0.0014333,  0.0010057,  0.000469611, 0.000277989, 0.000120618, 5.09227e-05, 1.79574e-05, 1.01973e-05, 1.39946e-06}
        }
};
double rab_kstar_cuau[3][5][n_kstar_cuau] = {
        {
                {0.930, 0.972, 1.021, 0.998, 0.949, 0.721, 0.647, 0.575, 0.464},
                {0.929, 1.004, 1.042, 1.109, 1.008, 0.855, 0.751, 0.725, 0.550},
                {1.154, 1.255, 1.270, 1.283, 1.102, 0.980, 0.912, 0.918, 0.713},
                {1.064, 1.181, 1.205, 1.185, 1.051, 0.945, 0.973, 0.982, 0.791},
                {0.915, 0.976, 1.086, 1.136, 1.037, 0.885, 0.908, 0.808, 0.662}
        },
        {
                {0.070, 0.059, 0.093, 0.084, 0.044, 0.040, 0.057, 0.058, 0.062},
                {0.084, 0.088, 0.164, 0.060, 0.051, 0.044, 0.069, 0.070, 0.077},
                {0.064, 0.072, 0.135, 0.085, 0.074, 0.057, 0.098, 0.098, 0.141},
                {0.119, 0.106, 0.198, 0.133, 0.096, 0.088, 0.149, 0.148, 0.194},
                {0.086, 0.136, 0.072, 0.034, 0.038, 0.034, 0.079, 0.073, 0.078}
        },
        {
                {0.160, 0.151, 0.168, 0.166, 0.159, 0.132, 0.131, 0.131, 0.155},
                {0.158, 0.151, 0.163, 0.171, 0.152, 0.138, 0.133, 0.148, 0.174},
                {0.195, 0.191, 0.206, 0.211, 0.184, 0.182, 0.191, 0.220, 0.252},
                {0.198, 0.201, 0.216, 0.215, 0.194, 0.193, 0.222, 0.256, 0.298},
                {0.153, 0.145, 0.171, 0.180, 0.166, 0.161, 0.191, 0.201, 0.251}
        }
};


const int n_kstar_uu = 9;
double yields_kstar_uu[3][4][n_kstar_uu] = {
        {
                {0.339864,   0.174682,  0.0893304, 0.0578612,  0.0243289,  0.0127775,  0.00509868,  0.0017544},
                {0.162549,   0.0695873,  0.0475506,  0.0376859,  0.0125204,  0.00651688,  0.00273448,  0.00096583},
                {0.0202896,  0.00938723, 0.00680324,  0.00501687,  0.00173849,  0.000872239, 0.000362232, 0.00012638},
                {0.150024,   0.0603164,  0.0487331,  0.0374728,  0.0120245,   0.00620503,  0.00244338,  0.000981053, 0.000308}
        },
        {
                {0.00950526, 0.0178791, 0.0112035, 0.0040282,  0.00214856, 0.00116181, 0.000597341, 0.000423468},
                {0.00838748, 0.00803629, 0.0047578,  0.00424074, 0.00141366, 0.000632937, 0.000225036, 0.000113004},
                {0.00343814, 0.00101116, 0.000717422, 0.000507281, 0.000180225, 0.000100185, 5.17405e-05, 1.99341e-05},
                {0.00718961, 0.00371917, 0.00335868, 0.00235362, 0.000951368, 0.000699244, 0.000327585, 7.05086e-05, 3.61086e-05},
        },
        {
                {0.0518363,  0.0240144, 0.0116234, 0.00734808, 0.00301076, 0.0016994,  0.00080762,  0.000383761},
                {0.0254202,  0.00904934, 0.00552938, 0.00410453, 0.00127597, 0.000723542, 0.000389931, 0.000218067},
                {0.00261729, 0.00101917, 0.000668395, 0.000467207, 0.000149762, 8.1728e-05,  4.2973e-05,  2.33537e-05},
                {0.0149839,  0.00544808, 0.00423669, 0.00327131, 0.00102796,  0.000609076, 0.00031191,  0.000190619, 0.0000490619},
        }
};
double rab_kstar_uu[3][4][n_kstar_uu] = {
        {
                {0.6135, 0.6257, 0.5718, 0.5816, 0.6134, 0.6148, 0.5518, 0.4603},
                {0.819,  0.8619, 0.8496, 0.8421, 0.8811, 0.8751, 0.826,  0.7073},
                {0.714, 0.838, 0.848, 0.745, 0.854, 0.818,  0.764, 0.646},
                {0.745, 0.774, 0.858, 0.803, 0.834, 0.821, 0.727, 0.708, 0.781}
        },
        {
                {0.0459, 0.0651, 0.0719, 0.0405, 0.0541, 0.0559, 0.0646, 0.1111},
                {0.072,  0.1007, 0.0853, 0.0938, 0.0994, 0.085,  0.0679, 0.0827},
                {0.13,  0.081, 0.09,  0.087, 0.089, 0.0939, 0.109, 0.102},
                {0.062, 0.050, 0.060, 0.050, 0.066, 0.093, 0.098, 0.051, 0.092}
        },
        {
                {0.1296, 0.1155, 0.1312, 0.12,   0.1214, 0.1314, 0.1368, 0.1795},
                {0.1281, 0.1137, 0.1035, 0.1022, 0.1048, 0.1128, 0.116,  0.1256},
                {0.137, 0.135, 0.135, 0.114, 0.125, 0.1289, 0.139, 0.159},
                {0.130, 0.116, 0.131, 0.120, 0.121, 0.131, 0.137, 0.180, 0.238}
        }
};

const int n_kstar_cucu = 12;
double rab_kstar_cucu[3][5][n_kstar_cucu] = {
        {
                {0.808,    1.0,    8.74e-01,  8.60e-01, 1.10e+00, 1.14e+00, 9.19e-01,  9.76e-01, 8.04e-01, 8.19e-01,  6.81e-01,  0.735},
                {0.97,     0.799,    1.19,     1.32,     1.16,     1.30,    1.22,     1.25,     1.11,     9.78e-01, 7.39e-01, 0.749},
                {0.513,    0.951,    0.94,     1.02,     1.25,     1.48,     1.39,     1.15,     1.40,    1.27,     0.888,    1.14},
                {0.912,    1.04,     0.977,    1.23,     1.11,     1.05,     1.08,     0.994,    1.16,     1.18,     1.13,     1.09},
                {0.862,     0.926,     0.918,     1.0,    0.993,     1.31,     1.08,     0.976,     0.96,     0.8,     0.596,     0.595},
        },
        {
                {0.09494,  0.0913, 0.0780482, 0.098298, 0.09559,  0.158916, 0.0884078, 0.08784,  0.061908, 0.0788697, 0.0890748, 0.139944},
                {0.119601, 0.100434, 0.094605, 0.119592, 0.109504, 0.11258, 0.103944, 0.115,    0.085137, 0.106309, 0.102721, 0.163057},
                {0.133226, 0.114786, 0.101614, 0.1275,   0.126125, 0.157768, 0.128297, 0.14168,  0.14378, 0.179578, 0.176002, 0.291384},
                {0.143275, 0.130728, 0.106591, 0.144156, 0.128649, 0.150465, 0.141048, 0.149001, 0.155788, 0.20591,  0.211875, 0.330924},
                {0.0743906, 0.0669498, 0.0640764, 0.0815, 0.0719925, 0.094713, 0.074412, 0.0742736, 0.052704, 0.06264, 0.0570372, 0.104958}
        },
        {
                {0.218887, 0.2602, 0.222433,  0.216462, 0.27258,  0.282492, 0.225339,  0.238437, 0.231713, 0.241032,  0.206752,  0.236964},
                {0.226689, 0.185048, 0.270963, 0.299244, 0.262392, 0.28925, 0.272914, 0.280625, 0.267954, 0.238632, 0.189627, 0.247994},
                {0.154208, 0.230618, 0.220618, 0.233784, 0.280625, 0.327672, 0.306356, 0.255415, 0.32942, 0.300355, 0.215162, 0.321708},
                {0.207389, 0.228384, 0.212497, 0.266541, 0.240759, 0.22953,  0.23868,  0.22703,  0.26564,  0.268686, 0.258657, 0.268467},
                {0.212397,  0.224185,  0.219861,  0.2348, 0.228092,  0.295798, 0.244188, 0.222333,  0.246528, 0.21416, 0.174986,  0.232169}
        }
};


const int n_kstar_heau = 11;
double yields_kstar_heau[3][5][n_kstar_heau] = {
        {
                {0.0103715,   0.00565737,  0.00334621,  0.00232781,  0.00101637,  0.000582561, 0.000242703, 9.48531e-05, 2.90813e-05, 1.58443e-05, 1.64984e-06},
                {0.00523498,  0.00295043,  0.00181635,  0.00129779,  0.000564261, 0.000363506, 0.000156944, 6.11649e-05, 1.92656e-05, 9.96274e-06, 1.24354e-06},
                {0.00389068,  0.00222525,  0.00138857,  0.000932137, 0.000374119, 0.000202915, 7.71721e-05, 3.31367e-05, 8.77447e-06, 5.53679e-06, 6.6088e-07},
                {0.00128262,  0.000790034, 0.000476806, 0.000294147, 0.000136995, 7.26666e-05, 3.1345e-05,  1.30295e-05, 4.18985e-06, 2.35237e-06, 2.40788e-07},
                {0.0047116,   0.00224852,  0.00144108,  0.000958461, 0.000489983, 0.000287644, 0.000124734, 4.84739e-05, 1.53017e-05, 8.04273e-06, 9.38447e-07},
        },
        {
                {0.000420719, 0.000256695, 0.000186775, 0.000137612, 7.50748e-05, 2.55131e-05, 1.84396e-05, 9.14401e-06, 3.9348e-06,  2.2237e-06,  4.05947e-07},
                {0.000154953, 0.000189351, 9.93678e-05, 9.49082e-05, 4.31556e-05, 2.23546e-05, 1.65332e-05, 7.4433e-06,  1.85011e-06, 1.55643e-06, 3.00688e-07},
                {0.000165169, 0.000138929, 0.000106438, 7.02592e-05, 2.05864e-05, 6.14171e-06, 6.44871e-06, 4.83339e-06, 1.38442e-06, 8.44782e-07, 1.7528e-07},
                {9.33399e-05, 5.86537e-05, 3.07895e-05, 1.6413e-05,  8.60598e-06, 6.18799e-06, 2.85893e-06, 2.12812e-06, 6.41826e-07, 4.22878e-07, 7.46974e-08},
                {4.2946e-05,  0.000101234, 9.31048e-05, 5.18813e-05, 2.73405e-05, 1.38591e-05, 7.05681e-06, 2.58053e-06, 1.73256e-06, 1.19782e-06, 2.26983e-07}
        },
        {
                {0.00160043,  0.000828127, 0.000471869, 0.000317544, 0.000133529, 6.98392e-05, 2.6762e-05,  1.0127e-05,  3.12753e-06, 1.77243e-06, 2.15508e-07},
                {0.000974472, 0.000501568, 0.000288283, 0.0001933,   7.81909e-05, 4.4321e-05,  1.68273e-05, 6.13099e-06, 1.95469e-06, 1.08696e-06, 1.82122e-07},
                {0.00061621,  0.000323157, 0.000189247, 0.000120203, 4.53843e-05, 2.16968e-05, 7.35578e-06, 3.07958e-06, 8.61302e-07, 6.05024e-07, 8.95316e-08},
                {0.000240785, 0.000136614, 7.74742e-05, 4.51053e-05, 1.96051e-05, 9.19456e-06, 3.4784e-06,  1.3194e-06,  4.1063e-07,  2.3524e-07,  2.8891e-08},
                {0.000807808, 0.000347068, 0.000206018, 0.000128045, 6.08293e-05, 3.12209e-05, 1.2071e-05,  4.68904e-06, 1.64523e-06, 1.02376e-06, 1.51393e-07}
        }
};
double rab_kstar_heau[3][5][n_kstar_heau] = {
        {
                {0.74036,   0.808915,  0.85601,   0.935239, 1.0263,   1.09689,   1.05176,   0.999555,  1.08533,  1.09757,  0.957989},
                {0.623256,  0.677672,  0.744478,  0.83671,   0.913056,  1.10856,   1.09371,  1.03688,  1.14252,  1.11218,  1.1466},
                {0.809, 0.908, 1.015, 1.070, 1.074, 1.102, 0.955, 1.005, 0.941, 1.099, 1.093},
                {0.665501,  0.806327,  0.868031,  0.840067,  0.982264,  0.990533,  0.968627,  0.990987, 1.11556,  1.16979,  1.0065},
                {0.628172,  0.646286,  0.741081,  0.773047,  0.991611,  1.06276,   1.08338,   1.02033,   1.14102,  1.12359,  1.09529}
        },
        {
                {0.0471338, 0.0382153, 0.0479447, 0.055121, 0.075405, 0.0758325, 0.0816807, 0.0955407, 0.143161, 0.150246, 0.223427},
                {0.0400975, 0.0445019, 0.0409622, 0.0608921, 0.0694378, 0.0732815, 0.115249, 0.123983, 0.108343, 0.16795,  0.262194},
                {0.053, 0.058, 0.078, 0.080, 0.059, 0.070, 0.077, 0.134, 0.139, 0.158, 0.181},
                {0.0580929, 0.0605422, 0.0560985, 0.0467608, 0.0614706, 0.0954637, 0.0891784, 0.156416, 0.165442, 0.201198, 0.286768},
                {0.0363289, 0.0303584, 0.0479223, 0.0417508, 0.0551678, 0.0721756, 0.0643507, 0.0548564, 0.12693,  0.162248, 0.249184}
        },
        {
                {0.121579,  0.126537,  0.129556,  0.134399, 0.142653, 0.140514,  0.125398,  0.11609,   0.126975, 0.133461, 0.248285},
                {0.121157,  0.121084,  0.125007,  0.130191,  0.133086,  0.143994,  0.127295, 0.114201, 0.127136, 0.132442, 0.305754},
                {0.196, 0.190, 0.200, 0.188, 0.188, 0.180, 0.147, 0.161, 0.163, 0.220, 0.340},
                {0.130372,  0.146307,  0.14884,   0.134243,  0.147402,  0.132947,  0.116071,  0.110199, 0.120699, 0.129617, 0.258567},
                {0.113311,  0.10591,   0.113474,  0.10899,   0.131025,  0.124811,  0.115672,  0.109006,  0.133352, 0.152764, 0.300368}
        }
};


const int n_kstar_dau = 13;
double rab_kstar_dau[3][5][n_kstar_dau] = {
        {
                {0.915, 1.127, 1.039, 1.041, 1.030, 1.065, 1.005, 1.154, 1.129, 1.153, 0.912, 0.750, 0.644},
                {0.804, 0.828, 1.019, 0.897, 0.915, 0.898, 1.159, 1.363, 1.108, 1.036, 1.065, 0.882, 0.859},
                {1.338, 1.297, 1.504, 1.111, 1.070, 1.180, 1.538, 1.948, 1.480, 1.345, 1.248, 0.826, 0.597},
                {1.034, 0.886, 1.038, 0.849, 1.092, 1.207, 1.384, 1.683, 1.271, 1.380, 1.240, 1.056, 1.056},
                {1.107, 1.096, 0.913, 0.886, 0.897, 0.909, 1.010, 1.207, 0.945, 0.930, 0.868, 0.873, 0.697}
        },
        {
                {0.110, 0.045, 0.056, 0.053, 0.061, 0.029, 0.035, 0.040, 0.049, 0.076, 0.097, 0.098, 0.193},
                {0.111, 0.054, 0.067, 0.057, 0.068, 0.031, 0.039, 0.045, 0.052, 0.082, 0.114, 0.114, 0.234},
                {0.129, 0.071, 0.088, 0.073, 0.081, 0.041, 0.050, 0.057, 0.066, 0.101, 0.136, 0.138, 0.277},
                {0.133, 0.080, 0.097, 0.079, 0.091, 0.036, 0.045, 0.053, 0.063, 0.108, 0.140, 0.148, 0.148},
                {0.086, 0.039, 0.046, 0.042, 0.049, 0.023, 0.028, 0.033, 0.037, 0.060, 0.077, 0.083, 0.151}
        },
        {
                {0.124, 0.168, 0.150, 0.128, 0.183, 0.133, 0.195, 0.171, 0.159, 0.155, 0.174, 0.160, 0.108},
                {0.109, 0.171, 0.136, 0.101, 0.169, 0.127, 0.104, 0.212, 0.247, 0.196, 0.204, 0.188, 0.144},
                {0.181, 0.207, 0.212, 0.124, 0.257, 0.223, 0.134, 0.217, 0.283, 0.239, 0.239, 0.176, 0.100},
                {0.140, 0.167, 0.178, 0.188, 0.352, 0.248, 0.284, 0.348, 0.268, 0.310, 0.237, 0.225, 0.225},
                {0.150, 0.180, 0.142, 0.092, 0.124, 0.134, 0.171, 0.233, 0.218, 0.194, 0.166, 0.186, 0.117}
        }
};


const int n_kstar_pau = 9;
double yields_kstar_pau[3][4][n_kstar_pau] = {
        {
                {0.00456613,  0.00255978,  0.00151963,  0.00102379,  0.000416907, 0.000231715, 0.00010874,  4.8562e-05,  1.4751e-05},
                {0.000296789, 0.000165196, 9.40739e-05, 6.4753e-05,  2.75856e-05, 1.5315e-05,  7.28325e-06, 2.99194e-06, 9.29694e-07},
                {1.51355e-05, 8.4398e-06,  4.60105e-06, 3.17729e-06, 1.27786e-06, 7.5091e-07,  3.47454e-07, 1.46029e-07, 4.22924e-08},
                {0.245486,  0.130193,   0.0754235,  0.0520883,  0.0219703,  0.0123829,   0.00561218,  0.00246914,  0.000733822},
        },
        {
                {0.000524555, 0.000394382, 0.000138122, 0.00014413,  6.32187e-05, 1.55352e-05, 8.39889e-06, 4.01503e-06, 2.41053e-06},
                {3.4152e-05,  2.04774e-05, 1.17286e-05, 7.46007e-06, 3.6944e-06,  1.33425e-06, 7.21494e-07, 3.05398e-07, 1.67906e-07},
                {1.7134e-06,  7.237e-07,   5.06891e-07, 4.15957e-07, 1.64406e-07, 5.01056e-08, 2.00136e-08, 1.0199e-08,  6.9364e-09},
                {0.0164489, 0.00963969, 0.0069458,  0.00555564, 0.00233962, 0.000486361, 0.000308311, 0.000199787, 0.000106063},
        },
        {
                {0.000438318, 0.000236197, 0.000137322, 9.17908e-05, 3.72954e-05, 1.87753e-05, 8.30371e-06, 3.9432e-06,  1.34756e-06},
                {2.91402e-05, 1.58902e-05, 8.9647e-06,  6.1697e-06,  2.63724e-06, 1.34831e-06, 6.08636e-07, 2.59194e-07, 8.65847e-08},
                {1.66021e-06, 8.85625e-07, 4.71184e-07, 3.2165e-07,  1.28778e-07, 7.03145e-08, 3.16767e-08, 1.45593e-08, 4.88713e-09},
                {0.0235392, 0.012683,   0.00746985, 0.00527373, 0.00228418, 0.00123435,  0.000553596, 0.000256439, 8.1005e-05},
        }
};
double rab_kstar_pau[3][4][n_kstar_pau] = {
        {
                {0.860392, 0.962979, 1.0066,    1.07648,  1.10276,  1.14297,   1.21505,   1.31579,  1.42706},
                {0.818463, 0.902461, 0.918469, 0.990534, 1.06314,  1.11021,  1.1956,   1.19113,  1.32552},
                {0.77126,  0.845953,  0.827707,  0.90189,  0.90938,  0.998158,  1.04834,   1.06953,  1.11227},
                {0.776698,  0.814899,  0.845978,  0.919986,  0.973383, 1.03075,   1.05904,   1.13313,   1.20006}
        },
        {
                {0.11292,  0.146045, 0.0911775, 0.148666, 0.163532, 0.0854525, 0.0960791, 0.108741, 0.228064},
                {0.107569, 0.111467, 0.113069, 0.112658, 0.139907, 0.107242, 0.119439, 0.120826, 0.232504},
                {0.100219, 0.0737556, 0.0904254, 0.116142, 0.115134, 0.0833839, 0.0633686, 0.074938, 0.177755},
                {0.0735167, 0.0619536, 0.0776287, 0.0970598, 0.102509, 0.0697806, 0.0613711, 0.0916471, 0.170061}
        },
        {
                {0.116878, 0.119607, 0.121745,  0.120268, 0.124764, 0.120627,  0.12289,   0.140644, 0.16778},
                {0.112407, 0.114682, 0.114446, 0.115111, 0.125436, 0.123163, 0.127457, 0.13221,  0.157587},
                {0.112434, 0.113197,  0.1077,    0.109248, 0.111133, 0.115211,  0.1181,    0.129909, 0.152554},
                {0.105414,  0.104326,  0.107868,  0.111472,  0.121551, 0.124104,  0.125823,  0.141552,  0.159432}
        }
};
const int n_kstar_pal = 7;
double yields_kstar_pal[3][4][n_kstar_pal] = {
        {
                {2.134e-03, 1.234e-03, 6.346e-04, 4.513e-04, 1.910e-04, 9.439e-05},
                {1.317e-03, 7.681e-04, 4.173e-04, 2.868e-04, 1.195e-04, 6.137e-05},
                {8.410e-04, 4.900e-04, 2.543e-04, 1.679e-04, 7.592e-05, 4.025e-05},
                {1.188e-03, 6.348e-04, 3.714e-04, 2.288e-04, 1.020e-04, 5.845e-05, 2.563e-05}
        },
        {
                {4.093e-04, 1.783e-04, 1.115e-04, 5.822e-05, 2.968e-05, 1.936e-05},
                {2.496e-04, 1.278e-04, 6.648e-05, 2.986e-05, 1.494e-05, 9.526e-06},
                {1.606e-04, 9.384e-05, 5.656e-05, 2.008e-05, 1.122e-05, 8.052e-06},
                {1.429e-04, 8.959e-05, 4.411e-05, 2.165e-05, 1.017e-05, 6.269e-06, 3.581e-06}
        },
        {
                {2.063e-04, 1.136e-04, 5.766e-05, 4.152e-05, 1.829e-05, 9.074e-06},
                {1.156e-04, 6.360e-05, 3.443e-05, 2.452e-05, 1.115e-05, 6.367e-06},
                {7.760e-05, 4.418e-05, 2.296e-05, 1.550e-05, 7.328e-06, 3.890e-06},
                {1.116e-04, 5.579e-05, 3.181e-05, 1.963e-05, 8.977e-06, 4.978e-06, 2.440e-06}
        }
};
double rab_kstar_pal[3][4][n_kstar_pal] = {
        {
                {0.847, 0.972, 0.894, 0.996, 1.057, 0.999},
                {0.869, 1.007, 0.977, 1.043, 1.075, 1.080},
                {0.843, 0.975, 0.904, 0.942, 1.028, 1.076},
                {0.859, 0.911, 0.953, 0.917, 1.043, 1.127, 1.112}
        },
        {
                {0.172, 0.142, 0.157, 0.182, 0.233, 0.205},
                {0.175, 0.168, 0.156, 0.163, 0.217, 0.168},
                {0.171, 0.188, 0.201, 0.159, 0.236, 0.215},
                {0.119, 0.130, 0.113, 0.124, 0.164, 0.121, 0.155}
        },
        {
                {0.116, 0.121, 0.108, 0.113, 0.125, 0.117},
                {0.113, 0.118, 0.113, 0.113, 0.125, 0.134},
                {0.112, 0.119, 0.109, 0.107, 0.122, 0.127},
                {0.115, 0.110, 0.112, 0.100, 0.117, 0.122, 0.129}
        }
};

// phi
const int n_phi_cuau = 9;
double rab_phi_cuau[3][5][n_phi_cuau] = {
        {
                {0.966601, 1.02036, 0.979795, 0.90227, 0.789803, 0.784705, 0.639701, 0.538802, 0.406308},
                {1.02008, 1.03158, 1.16368, 1.05781, 0.967303, 1.02371, 0.873813, 0.717024, 0.682583},
                {1.19687, 1.27577, 1.16396, 1.09214, 1.08254, 0.988788, 0.975345, 0.956699, 0.817942},
                {1.11886, 1.20935, 1.11651, 1.15797, 1.11593, 1.06788, 0.975399, 1.04619, 0.745047 },
                {1.01473, 1.03002, 1.05234, 0.967846, 0.891857, 0.890557, 0.753598, 0.728182, 0.665597}
        },
        {
                {0.0503373, 0.041729, 0.0369575, 0.0422549, 0.0494007, 0.0662953, 0.0936143, 0.110306, 0.167009},
                {0.0494578, 0.0500488, 0.0433215, 0.0488955, 0.0593537, 0.0876227, 0.124341, 0.14135, 0.224495},
                {0.0797071, 0.0573477, 0.0463206, 0.0536286, 0.0697294, 0.087378, 0.186145, 0.191133, 0.293663},
                {0.100946, 0.123425, 0.0551262, 0.064901, 0.081036, 0.10596, 0.232499, 0.234683, 0.410449},
                {0.0465877, 0.0376794, 0.0366727, 0.0419544, 0.051152, 0.0697368, 0.103707, 0.135365, 0.186482}
        },
        {
                {0.123653, 0.135675, 0.130477, 0.125851, 0.115454, 0.120226, 0.105321, 0.137943, 0.125426},
                {0.132559, 0.137975, 0.154261, 0.145302, 0.137814, 0.151368, 0.137883, 0.178393, 0.203815},
                {0.168856, 0.183797, 0.165653, 0.159521, 0.162439, 0.152543, 0.158842, 0.239671, 0.243577},
                {0.148072, 0.168612, 0.158683, 0.174564, 0.178346, 0.180748, 0.178208, 0.285452, 0.245637},
                {0.12222, 0.127551, 0.128219, 0.122309, 0.117074, 0.121555, 0.110505, 0.17562, 0.194008}
        },
};

const int n_phi_uu = 7;
double rab_phi_uu[3][5][n_phi_uu] = {

};

const int n_phi_heau = 10;
double rab_phi_heau[3][5][n_phi_heau] = {
        {
                {0.850389, 0.867106, 0.947406, 0.959286, 0.979399, 0.920135, 0.923946, 1.13267, 1.01939, 0.800403},
                {0.765526, 0.865235, 0.88853, 0.963898, 0.948204, 0.920852, 1.10233, 1.10752, 1.2144, 1.11381},
                {1.02743, 0.969, 0.919078, 0.914206, 0.910971, 0.951042, 0.977929, 1.11329, 1.16601, 0},
                {0, 0, 0.890408, 0.841863, 0.866078, 0.860197, 0.946887, 1.04574, 1.04775, 0},
                {0.894547, 0.971711, 0.960645, 0.982587, 0.984547, 0.92189, 1.0622, 1.07292, 1.15178, 0.981721}
        },
        {
                {0.131015, 0.0623907, 0.0434824, 0.0471299, 0.0584011, 0.0720803, 0.100491, 0.181966, 0.235563, 0.298249},
                {0.135119, 0.0653649, 0.0442998, 0.0492484, 0.0588873, 0.0767704, 0.122729, 0.194857, 0.27446, 0.377581},
                {0.165817, 0.0753947, 0.0490523, 0.0526072, 0.0632004, 0.0834231, 0.119854, 0.203872, 0.291822, 0},
                {0, 0, 0.0977084, 0.0538938, 0.103714, 0.0870035, 0.129471, 0.211894, 0.305744, 0},
                {0.10116, 0.0539677, 0.0369307, 0.0399641, 0.0488042, 0.0626053, 0.093614, 0.159271, 0.22814, 0.288071}
        },
        {
                {0.128859, 0.118685, 0.125774, 0.119488, 0.121029, 0.114077, 0.116115, 0.151451, 0.236111, 0.229324},
                {0.114638, 0.11716, 0.117377, 0.120398, 0.118661, 0.116953, 0.143836, 0.155592, 0.291498, 0.33851},
                {0.148434, 0.12665, 0.118799, 0.113749, 0.116468, 0.127328, 0.139696, 0.177435, 0.312101, 0},
                {0, 0, 0.130738, 0.111955, 0.11193, 0.111592, 0.127089, 0.154384, 0.269892, 0},
                {0.122622, 0.122371, 0.122612, 0.122136, 0.125638, 0.12137, 0.144927, 0.1573, 0.279025, 0.291163}
        }
};

const int n_phi_pau = 7;
double rab_phi_pau[3][5][n_phi_pau] = {
        {
                {1.0286,   1.06502,  1.1227,   1.2543,   1.31483,  1.3361,   1.49543},
                {1.05131,  1.01737,  1.0298,    1.09944,  1.02497,  1.1409,   1.21215},
                {0, 0, 0.897698,  0.944698,  0.90412,  1.00321,  1.04043},
                {0.935967, 0.977156,  1.02801,   1.12626,   1.13104,   1.16683,  1.38315}
        },
        {
                {0.330404, 0.147392, 0.095437, 0.103826, 0.130688, 0.163104, 0.256133},
                {0.331915, 0.155679, 0.0955596, 0.100481, 0.119807, 0.166916, 0.257939},
                {0, 0, 0.0715598, 0.0814613, 0.103831, 0.139981, 0.210025},
                {0.208405, 0.0963808, 0.0651038, 0.0723368, 0.0940636, 0.11219,  0.177351}
        },
        {
                {0.096661, 0.101623, 0.110635, 0.129305, 0.14292,  0.154284, 0.184534},
                {0.121393, 0.113871, 0.113036,  0.122128, 0.118392, 0.140517, 0.162583},
                {0, 0, 0.1018,    0.106441,  0.105593, 0.126288, 0.145811},
                {0.084193, 0.0883663, 0.0943149, 0.105842,  0.109403,  0.116795, 0.143918}
        }
};

const int n_phi_pal = 7;
double rab_phi_pal[3][4][n_phi_pal] = {
        {
                {0.89793, 1.07157, 1.09691, 1.03551, -99, -99},
                {1.03313, 1.19629, 1.02529, 0.97310, -99, -99},
                {0.98189, 0.94331, 1.24078, 0.86103, -99, -99},
                {0.94562, 1.09805, 1.08983, 0.98787, 1.19668, 1.11595}
        },
        {
                {0.21447, 0.15334, 0.17221, 0.21273, -99, -99},
                {0.24183, 0.17101, 0.18984, 0.23930, -99, -99},
                {0.22416, 0.15225, 0.17567, 0.21720, -99, -99},
                {0.13333, 0.09501, 0.10999, 0.13408, 0.19253, 0.26505}
        },
        {
                {0.14239, 0.17038, 0.16568, 0.14951, -99, -99},
                {0.18586, 0.17701, 0.13869, 0.14497, -99, -99},
                {0.20788, 0.16214, 0.19007, 0.13902, -99, -99},
                {0.15314, 0.16567, 0.15310, 0.13863, 0.17381, 0.17356}
        }
};

//pi0
const int n_pi0_cuau = 11;
double rab_pi0_cuau[3][5][n_pi0_cuau] = {
        {
                {0.541, 0.574, 0.521, 0.476, 0.434, 0.401, 0.391, 0.372, 0.383, 0.376, 0.382},
                {0.663, 0.701, 0.659, 0.619, 0.612, 0.57, 0.576, 0.574, 0.568, 0.557, 0.559},
                {0.812, 0.896, 0.873, 0.856, 0.841, 0.831, 0.845, 0.823, 0.856, 0.819, 0.851},
                {1.164, 1.199, 1.196, 1.19, 1.181, 1.145, 1.215, 1.208, 1.2, 1.14, 1.213},
                {0.611, 0.65, 0.603, 0.563, 0.531, 0.499, 0.496, 0.481, 0.491, 0.48, 0.489}
        },
        {
                {0.012, 0.01, 0.008, 0.007, 0.006, 0.006, 0.005, 0.005, 0.005, 0.005, 0.006},
                {0.013, 0.011, 0.009, 0.008, 0.008, 0.008, 0.006, 0.006, 0.007, 0.007, 0.008},
                {0.015, 0.012, 0.01, 0.01, 0.01, 0.01, 0.008, 0.009, 0.01, 0.01, 0.013},
                {0.019, 0.014, 0.012, 0.012, 0.012, 0.014, 0.012, 0.013, 0.015, 0.018, 0.023},
                {0.01, 0.008, 0.006, 0.006, 0.005, 0.006, 0.004, 0.004, 0.004, 0.005, 0.005}
        },
        {
                {0.046, 0.053, 0.052, 0.048, 0.047, 0.045, 0.046, 0.044, 0.048, 0.047, 0.048},
                {0.055, 0.064, 0.065, 0.062, 0.065, 0.064, 0.068, 0.068, 0.070, 0.069, 0.070},
                {0.066, 0.080, 0.085, 0.085, 0.089, 0.093, 0.099, 0.097, 0.105, 0.101, 0.105},
                {0.097, 0.109, 0.118, 0.120, 0.126, 0.129, 0.143, 0.143, 0.149, 0.142, 0.151},
                {0.051, 0.059, 0.059, 0.057, 0.057, 0.056, 0.058, 0.057, 0.061, 0.060, 0.061}
        }
};

const int n_pi0_uu = 11;
double rab_pi0_uu[3][5][n_pi0_uu] = {
        {
                {},

        },
        {

        },
        {

        }
};

const int n_pi0_heau = 14;
double rab_pi0_heau[3][5][n_pi0_heau] = {
        {
                {6.5073e-01, 7.6020e-01, 8.4811e-01, 9.0429e-01, 9.3376e-01, 9.5260e-01, 9.7134e-01, 9.7934e-01, 9.7371e-01, 9.7261e-01, 9.5954e-01, 9.3892e-01, 9.1561e-01, 8.8901e-01},
                {7.8496e-01, 8.7145e-01, 9.1888e-01, 9.8280e-01, 1.0186e+00, 1.0602e+00, 1.0769e+00, 1.0814e+00, 1.0885e+00, 1.0784e+00, 1.0570e+00, 1.0509e+00, 1.0180e+00, 1.0128e+00},
                {8.0401e-01, 8.8775e-01, 9.6293e-01, 1.0267e+00, 1.0501e+00, 1.0785e+00, 1.1017e+00, 1.1150e+00, 1.1099e+00, 1.1376e+00, 1.1329e+00, 1.1614e+00, 1.1769e+00, 1.1458e+00},
                {8.2793e-01, 8.7227e-01, 9.4137e-01, 9.7046e-01, 9.9516e-01, 1.0222e+00, 1.0286e+00, 1.0626e+00, 1.0524e+00, 1.0947e+00, 1.1033e+00, 1.1214e+00, 1.1300e+00, 1.1186e+00},
                {7.2994e-01, 8.1910e-01, 8.8669e-01, 9.4255e-01, 9.6863e-01, 1.0089e+00, 1.0273e+00, 1.0325e+00, 1.0366e+00, 1.0245e+00, 1.0256e+00, 1.0197e+00, 9.9823e-01, 9.6920e-01}
        },
        {
                {1.0252e-01, 1.2917e-01, 1.8726e-01, 2.8321e-01, 4.3385e-01, 6.5440e-01, 8.3695e-01, 1.1787e+00, 1.6586e+00, 1.9693e+00, 1.2579e+00, 1.5169e+00, 1.5474e+00, 1.9367e+00},
                {1.0757e-01, 1.3505e-01, 2.0257e-01, 3.0617e-01, 4.7015e-01, 7.0517e-01, 9.3162e-01, 1.3247e+00, 1.8777e+00, 2.3044e+00, 1.3762e+00, 1.6710e+00, 1.7957e+00, 2.2336e+00},
                {1.2042e-01, 1.5783e-01, 2.3417e-01, 3.5642e-01, 5.5225e-01, 8.3271e-01, 1.1439e+00, 1.6231e+00, 2.3088e+00, 2.9271e+00, 1.6488e+00, 2.0252e+00, 2.2497e+00, 2.8314e+00},
                {1.3694e-01, 1.8971e-01, 2.8561e-01, 4.5128e-01, 7.0492e-01, 1.0663e+00, 1.5266e+00, 2.1637e+00, 3.0991e+00, 4.0629e+00, 2.0816e+00, 2.5850e+00, 3.0160e+00, 3.7904e+00},
                {7.0242e-02, 9.5084e-02, 1.4753e-01, 2.3267e-01, 3.6616e-01, 5.5606e-01, 6.6712e-01, 9.4327e-01, 1.3215e+00, 1.4380e+00, 1.0716e+00, 1.2505e+00, 1.0888e+00, 1.3705e+00}
        },
        {
                {7.6695e+00, 7.4583e+00, 7.3406e+00, 7.1907e+00, 7.2489e+00, 7.2553e+00, 7.4564e+00, 7.4297e+00, 7.6756e+00, 7.7308e+00, 7.8284e+00, 7.9536e+00, 8.0908e+00, 8.0883e+00},
                {7.6695e+00, 7.4595e+00, 7.3410e+00, 7.1885e+00, 7.2496e+00, 7.2552e+00, 7.4562e+00, 7.4299e+00, 7.6758e+00, 7.7308e+00, 7.8269e+00, 7.9515e+00, 8.0907e+00, 8.0881e+00},
                {7.6691e+00, 7.4585e+00, 7.3395e+00, 7.1881e+00, 7.2496e+00, 7.2552e+00, 7.4563e+00, 7.4289e+00, 7.6755e+00, 7.7311e+00, 7.8287e+00, 7.9521e+00, 8.0903e+00, 8.0878e+00},
                {7.6682e+00, 7.4583e+00, 7.3409e+00, 7.1885e+00, 7.2496e+00, 7.2552e+00, 7.4563e+00, 7.4287e+00, 7.6762e+00, 7.7311e+00, 7.8277e+00, 7.9529e+00, 8.0917e+00, 8.0882e+00},
                {7.6696e+00, 7.4587e+00, 7.3408e+00, 7.1886e+00, 7.2492e+00, 7.2550e+00, 7.4558e+00, 7.4297e+00, 7.6754e+00, 7.7314e+00, 7.8291e+00, 7.9520e+00, 8.0905e+00, 8.0884e+00}
        }
};

const int n_pi0_pau = 7;
double rab_pi0_pau[3][5][n_pi0_pau] = {
        {
                {8.0036e-01, 8.9207e-01, 1.0159e+00, 1.1055e+00, 1.1567e+00, 1.1732e+00, 1.1841e+00},
                {7.8740e-01, 8.6204e-01, 9.7805e-01, 1.0603e+00, 1.1139e+00, 1.1440e+00, 1.1726e+00},
                {7.9356e-01, 8.0031e-01, 8.7058e-01, 9.3309e-01, 9.7994e-01, 1.0003e+00, 1.0029e+00},
                {7.8369e-01, 8.5021e-01, 9.6030e-01, 1.0384e+00, 1.0917e+00, 1.1171e+00, 1.1446e+00}
        },
        {
                {1.2965e-01, 1.6228e-01, 2.4152e-01, 3.7244e-01, 5.7616e-01, 8.7429e-01, 1.2102e+00},
                {1.4490e-01, 1.8653e-01, 2.7991e-01, 4.3545e-01, 6.7242e-01, 1.0189e+00, 1.4336e+00},
                {1.8861e-01, 2.6295e-01, 4.0991e-01, 6.4434e-01, 1.0029e+00, 1.5312e+00, 2.1936e+00},
                {8.5899e-02, 1.1524e-01, 1.7822e-01, 2.8221e-01, 4.4176e-01, 6.7376e-01, 8.7534e-01}
        },
        {
                {7.6168e+00, 7.7850e+00, 7.5014e+00, 7.2198e+00, 7.0045e+00, 6.6305e+00, 6.3657e+00},
                {7.6159e+00, 7.7849e+00, 7.4993e+00, 7.2191e+00, 7.0046e+00, 6.6299e+00, 6.3654e+00},
                {7.6161e+00, 7.7844e+00, 7.5002e+00, 7.2198e+00, 7.0026e+00, 6.6301e+00, 6.3645e+00},
                {7.6167e+00, 7.7860e+00, 7.5001e+00, 7.2203e+00, 7.0014e+00, 6.6301e+00, 6.3657e+00}
        }
};

const int n_pi0_pal = 8;
double rab_pi0_pal[3][4][n_pi0_pal] = {
        {
                {7.8690e-01, 8.3520e-01, 8.9690e-01, 9.5370e-01, 9.8040e-01, 9.5780e-01, 9.5840e-01, 9.4240e-01},
                {8.1903e-01, 8.4804e-01, 9.3138e-01, 9.5881e-01, 1.0026e+00, 9.7328e-01, 9.7411e-01, 9.8851e-01},
                {9.3440e-01, 9.1858e-01, 9.6447e-01, 9.8093e-01, 1.0361e+00, 1.0220e+00, 1.0204e+00, 9.9285e-01},
                {8.2478e-01, 8.5839e-01, 9.2673e-01, 9.7641e-01, 1.0095e+00, 9.9879e-01, 9.9139e-01, 9.7502e-01}
        },
        {
                {2.1531e-01, 2.8625e-01, 4.4380e-01, 6.9857e-01, 1.0904e+00, 1.7006e+00, 2.4465e+00, 3.7014e+00},
                {2.5612e-01, 3.5397e-01, 5.4835e-01, 8.8343e-01, 1.3811e+00, 2.1686e+00, 3.1119e+00, 4.7396e+00},
                {4.5361e-01, 6.6402e-01, 1.0697e+00, 1.7526e+00, 2.7245e+00, 4.0482e+00, 6.5731e+00, 1.0224e+01},
                {1.4316e-01, 1.9745e-01, 3.0982e-01, 4.9393e-01, 7.7556e-01, 1.2022e+00, 1.7106e+00, 2.5678e+00}
        },
        {
                {7.6164e+00, 7.7856e+00, 7.5002e+00, 7.2191e+00, 7.0028e+00, 6.6293e+00, 6.3644e+00, 6.1208e+00},
                {7.6160e+00, 7.7852e+00, 7.5002e+00, 7.2197e+00, 7.0033e+00, 6.6305e+00, 6.3642e+00, 6.1209e+00},
                {7.6167e+00, 7.7877e+00, 7.4997e+00, 7.2202e+00, 7.0021e+00, 6.6301e+00, 6.3644e+00, 6.1205e+00},
                {7.6169e+00, 7.7869e+00, 7.5003e+00, 7.2184e+00, 7.0037e+00, 6.6289e+00, 6.3647e+00, 6.1201e+00}
        }
};

//eta
const int n_eta_cuau = 10;
double rab_eta_cuau[3][5][n_eta_cuau] = {
        {
                {0.601, 0.543, 0.488, 0.406, 0.411, 0.402, 0.392, 0.403, 0.435, 0.401},
                {0.693, 0.69, 0.576, 0.62, 0.661, 0.622, 0.556, 0.543, 0.545, 0.563},
                {0.904, 0.904, 0.784, 0.921, 0.822, 0.844, 0.857, 0.818, 0.945, 0.83},
                {1.2, 1.211, 1.187, 1.146, 1.37, 1.187, 1.26, 1.179, 1.042, 1.145},
                {0.661, 0.624, 0.551, 0.519, 0.524, 0.514, 0.476, 0.494, 0.512, 0.495}
        },
        {
                {0.042, 0.036, 0.031, 0.026, 0.021, 0.022, 0.019, 0.022, 0.028, 0.023},
                {0.046, 0.044, 0.034, 0.034, 0.031, 0.029, 0.022, 0.026, 0.037, 0.033},
                {0.061, 0.058, 0.043, 0.045, 0.04, 0.04, 0.033, 0.043, 0.069, 0.057},
                {0.079, 0.076, 0.062, 0.06, 0.062, 0.066, 0.061, 0.071, 0.106, 0.098},
                {0.04, 0.036, 0.022, 0.02, 0.017, 0.017, 0.013, 0.016, 0.023, 0.021}
        },
        {
                {0.145, 0.099, 0.069, 0.058, 0.058, 0.057, 0.053, 0.054, 0.059, 0.057},
                {0.167, 0.125, 0.079, 0.087, 0.092, 0.087, 0.074, 0.072, 0.072, 0.078},
                {0.217, 0.163, 0.108, 0.130, 0.115, 0.117, 0.114, 0.109, 0.125, 0.116},
                {0.288, 0.219, 0.163, 0.161, 0.192, 0.165, 0.168, 0.157, 0.140, 0.160},
                {0.159, 0.113, 0.076, 0.073, 0.073, 0.071, 0.063, 0.065, 0.067, 0.068},
        }
};

const int n_eta_uu = 7;
double rab_eta_uu[3][5][n_eta_uu] = {

};

#endif //PARTICLES_DATA
