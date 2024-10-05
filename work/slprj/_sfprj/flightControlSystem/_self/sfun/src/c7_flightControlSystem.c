/* Include files */

#include "flightControlSystem_sfun.h"
#include "c7_flightControlSystem.h"
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c7_emlrtMCI = { 163,/* lineNo */
  1,                                   /* colNo */
  "imadjust",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imadjust.m"/* pName */
};

static emlrtMCInfo c7_b_emlrtMCI = { 161,/* lineNo */
  1,                                   /* colNo */
  "imadjust",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imadjust.m"/* pName */
};

static emlrtMCInfo c7_c_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtMCInfo c7_d_emlrtMCI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtMCInfo c7_e_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c7_f_emlrtMCI = { 60,/* lineNo */
  23,                                  /* colNo */
  "bitset",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\bitset.m"/* pName */
};

static emlrtRSInfo c7_emlrtRSI = { 2,  /* lineNo */
  "Image Processing System/MATLAB Function2",/* fcnName */
  "#flightControlSystem:2757"          /* pathName */
};

static emlrtRSInfo c7_b_emlrtRSI = { 3,/* lineNo */
  "Image Processing System/MATLAB Function2",/* fcnName */
  "#flightControlSystem:2757"          /* pathName */
};

static emlrtRSInfo c7_c_emlrtRSI = { 4,/* lineNo */
  "Image Processing System/MATLAB Function2",/* fcnName */
  "#flightControlSystem:2757"          /* pathName */
};

static emlrtRSInfo c7_d_emlrtRSI = { 6,/* lineNo */
  "Image Processing System/MATLAB Function2",/* fcnName */
  "#flightControlSystem:2757"          /* pathName */
};

static emlrtRSInfo c7_e_emlrtRSI = { 7,/* lineNo */
  "Image Processing System/MATLAB Function2",/* fcnName */
  "#flightControlSystem:2757"          /* pathName */
};

static emlrtRSInfo c7_f_emlrtRSI = { 8,/* lineNo */
  "Image Processing System/MATLAB Function2",/* fcnName */
  "#flightControlSystem:2757"          /* pathName */
};

static emlrtRSInfo c7_g_emlrtRSI = { 43,/* lineNo */
  "Image Processing System/MATLAB Function2",/* fcnName */
  "#flightControlSystem:2757"          /* pathName */
};

static emlrtRSInfo c7_h_emlrtRSI = { 45,/* lineNo */
  "Image Processing System/MATLAB Function2",/* fcnName */
  "#flightControlSystem:2757"          /* pathName */
};

static emlrtRSInfo c7_i_emlrtRSI = { 48,/* lineNo */
  "Image Processing System/MATLAB Function2",/* fcnName */
  "#flightControlSystem:2757"          /* pathName */
};

static emlrtRSInfo c7_j_emlrtRSI = { 49,/* lineNo */
  "Image Processing System/MATLAB Function2",/* fcnName */
  "#flightControlSystem:2757"          /* pathName */
};

static emlrtRSInfo c7_k_emlrtRSI = { 14,/* lineNo */
  "imgaussfilt",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imgaussfilt.m"/* pathName */
};

static emlrtRSInfo c7_l_emlrtRSI = { 23,/* lineNo */
  "imgaussfilt",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imgaussfilt.m"/* pathName */
};

static emlrtRSInfo c7_m_emlrtRSI = { 24,/* lineNo */
  "imgaussfilt",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imgaussfilt.m"/* pathName */
};

static emlrtRSInfo c7_n_emlrtRSI = { 109,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c7_o_emlrtRSI = { 121,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c7_p_emlrtRSI = { 875,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c7_q_emlrtRSI = { 877,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c7_r_emlrtRSI = { 879,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c7_s_emlrtRSI = { 881,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c7_t_emlrtRSI = { 91,/* lineNo */
  "padarray",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m"/* pathName */
};

static emlrtRSInfo c7_u_emlrtRSI = { 950,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c7_v_emlrtRSI = { 1021,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c7_w_emlrtRSI = { 1049,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c7_x_emlrtRSI = { 1061,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c7_y_emlrtRSI = { 23,/* lineNo */
  "imadjust",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imadjust.m"/* pathName */
};

static emlrtRSInfo c7_ab_emlrtRSI = { 278,/* lineNo */
  "imadjust",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imadjust.m"/* pathName */
};

static emlrtRSInfo c7_bb_emlrtRSI = { 281,/* lineNo */
  "imadjust",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imadjust.m"/* pathName */
};

static emlrtRSInfo c7_cb_emlrtRSI = { 22,/* lineNo */
  "imadjust",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imadjust.m"/* pathName */
};

static emlrtRSInfo c7_db_emlrtRSI = { 24,/* lineNo */
  "imadjust",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imadjust.m"/* pathName */
};

static emlrtRSInfo c7_eb_emlrtRSI = { 54,/* lineNo */
  "stretchlim",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\stretchlim.m"/* pathName */
};

static emlrtRSInfo c7_fb_emlrtRSI = { 133,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c7_gb_emlrtRSI = { 170,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c7_hb_emlrtRSI = { 207,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c7_ib_emlrtRSI = { 452,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c7_jb_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c7_kb_emlrtRSI = { 297,/* lineNo */
  "imadjust",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imadjust.m"/* pathName */
};

static emlrtRSInfo c7_lb_emlrtRSI = { 333,/* lineNo */
  "imadjust",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imadjust.m"/* pathName */
};

static emlrtRSInfo c7_mb_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo c7_nb_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo c7_ob_emlrtRSI = { 14,/* lineNo */
  "changeClass",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\changeClass.m"/* pathName */
};

static emlrtRSInfo c7_pb_emlrtRSI = { 41,/* lineNo */
  "im2uint8",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\im2uint8.m"/* pathName */
};

static emlrtRSInfo c7_qb_emlrtRSI = { 197,/* lineNo */
  "im2uint8",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\im2uint8.m"/* pathName */
};

static emlrtRSInfo c7_rb_emlrtRSI = { 19,/* lineNo */
  "grayto8",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\grayto8.m"/* pathName */
};

static emlrtRSInfo c7_sb_emlrtRSI = { 344,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c7_tb_emlrtRSI = { 346,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c7_ub_emlrtRSI = { 350,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c7_vb_emlrtRSI = { 352,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c7_wb_emlrtRSI = { 45,/* lineNo */
  "bwareaopen",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m"/* pathName */
};

static emlrtRSInfo c7_xb_emlrtRSI = { 49,/* lineNo */
  "bwareaopen",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m"/* pathName */
};

static emlrtRSInfo c7_yb_emlrtRSI = { 63,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c7_ac_emlrtRSI = { 197,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c7_bc_emlrtRSI = { 198,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c7_cc_emlrtRSI = { 199,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c7_dc_emlrtRSI = { 201,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c7_ec_emlrtRSI = { 202,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c7_fc_emlrtRSI = { 204,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c7_gc_emlrtRSI = { 205,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c7_hc_emlrtRSI = { 217,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c7_ic_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c7_jc_emlrtRSI = { 157,/* lineNo */
  "imfill",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pathName */
};

static emlrtRSInfo c7_kc_emlrtRSI = { 197,/* lineNo */
  "imfill",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pathName */
};

static emlrtRSInfo c7_lc_emlrtRSI = { 198,/* lineNo */
  "imfill",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pathName */
};

static emlrtRSInfo c7_mc_emlrtRSI = { 211,/* lineNo */
  "imfill",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pathName */
};

static emlrtRSInfo c7_nc_emlrtRSI = { 11,/* lineNo */
  "bwfloodfillGetConnectivity",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\bwfloodfillGetConnectivity.m"/* pathName */
};

static emlrtRSInfo c7_oc_emlrtRSI = { 80,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo c7_pc_emlrtRSI = { 80,/* lineNo */
  "imclose",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\imclose.m"/* pathName */
};

static emlrtRSInfo c7_qc_emlrtRSI = { 85,/* lineNo */
  "imclose",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\imclose.m"/* pathName */
};

static emlrtRSInfo c7_rc_emlrtRSI = { 86,/* lineNo */
  "imclose",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\imclose.m"/* pathName */
};

static emlrtRSInfo c7_sc_emlrtRSI = { 87,/* lineNo */
  "imclose",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\imclose.m"/* pathName */
};

static emlrtRSInfo c7_tc_emlrtRSI = { 37,/* lineNo */
  "bwpack",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwpack.m"/* pathName */
};

static emlrtRSInfo c7_uc_emlrtRSI = { 98,/* lineNo */
  "imdilate",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\imdilate.m"/* pathName */
};

static emlrtRSInfo c7_vc_emlrtRSI = { 17,/* lineNo */
  "morphop",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\morphop.m"/* pathName */
};

static emlrtRSInfo c7_wc_emlrtRSI = { 22,/* lineNo */
  "morphop",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphop.m"/* pathName */
};

static emlrtRSInfo c7_xc_emlrtRSI = { 235,/* lineNo */
  "morphopConstantFoldingImpl",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphopConstantFoldingImpl.m"/* pathName */
};

static emlrtRSInfo c7_yc_emlrtRSI = { 272,/* lineNo */
  "morphopConstantFoldingImpl",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphopConstantFoldingImpl.m"/* pathName */
};

static emlrtRSInfo c7_ad_emlrtRSI = { 273,/* lineNo */
  "morphopConstantFoldingImpl",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphopConstantFoldingImpl.m"/* pathName */
};

static emlrtRSInfo c7_bd_emlrtRSI = { 491,/* lineNo */
  "morphopConstantFoldingImpl",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphopConstantFoldingImpl.m"/* pathName */
};

static emlrtRSInfo c7_cd_emlrtRSI = { 30,/* lineNo */
  "setPackedFillBits",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\setPackedFillBits.m"/* pathName */
};

static emlrtRSInfo c7_dd_emlrtRSI = { 12,/* lineNo */
  "bitset",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\bitset.m"/* pathName */
};

static emlrtRSInfo c7_ed_emlrtRSI = { 88,/* lineNo */
  "bitset",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\bitset.m"/* pathName */
};

static emlrtRSInfo c7_fd_emlrtRSI = { 726,/* lineNo */
  "morphopConstantFoldingImpl",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphopConstantFoldingImpl.m"/* pathName */
};

static emlrtRSInfo c7_gd_emlrtRSI = { 87,/* lineNo */
  "imerode",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\imerode.m"/* pathName */
};

static emlrtRSInfo c7_hd_emlrtRSI = { 732,/* lineNo */
  "morphopConstantFoldingImpl",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphopConstantFoldingImpl.m"/* pathName */
};

static emlrtRSInfo c7_id_emlrtRSI = { 37,/* lineNo */
  "bwunpack",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwunpack.m"/* pathName */
};

static emlrtRSInfo c7_jd_emlrtRSI = { 73,/* lineNo */
  "imopen",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\imopen.m"/* pathName */
};

static emlrtRSInfo c7_kd_emlrtRSI = { 74,/* lineNo */
  "imopen",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\imopen.m"/* pathName */
};

static emlrtRSInfo c7_ld_emlrtRSI = { 75,/* lineNo */
  "imopen",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\imopen.m"/* pathName */
};

static emlrtRTEInfo c7_emlrtRTEI = { 49,/* lineNo */
  1,                                   /* colNo */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m"/* pName */
};

static emlrtRTEInfo c7_b_emlrtRTEI = { 205,/* lineNo */
  13,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c7_c_emlrtRTEI = { 205,/* lineNo */
  22,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c7_d_emlrtRTEI = { 205,/* lineNo */
  9,                                   /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtBCInfo c7_emlrtBCI = { 1,  /* iFirst */
  162,                                 /* iLast */
  701,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_emlrtDCI = { 701,/* lineNo */
  21,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_b_emlrtBCI = { 1,/* iFirst */
  162,                                 /* iLast */
  694,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_b_emlrtDCI = { 694,/* lineNo */
  21,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_c_emlrtBCI = { 1,/* iFirst */
  122,                                 /* iLast */
  687,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_c_emlrtDCI = { 687,/* lineNo */
  19,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_d_emlrtBCI = { 1,/* iFirst */
  122,                                 /* iLast */
  680,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_d_emlrtDCI = { 680,/* lineNo */
  19,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo c7_e_emlrtRTEI = { 229,/* lineNo */
  21,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c7_f_emlrtRTEI = { 228,/* lineNo */
  17,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtECInfo c7_emlrtECI = { -1, /* nDims */
  205,                                 /* lineNo */
  9,                                   /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtBCInfo c7_e_emlrtBCI = { 1,/* iFirst */
  2,                                   /* iLast */
  205,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_e_emlrtDCI = { 205,/* lineNo */
  17,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_f_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  205,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_f_emlrtDCI = { 205,/* lineNo */
  15,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_g_emlrtBCI = { 1,/* iFirst */
  2,                                   /* iLast */
  205,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_g_emlrtDCI = { 205,/* lineNo */
  40,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_h_emlrtBCI = { 1,/* iFirst */
  2,                                   /* iLast */
  204,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_h_emlrtDCI = { 204,/* lineNo */
  28,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_i_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  58,                                  /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_i_emlrtDCI = { 58,/* lineNo */
  23,                                  /* colNo */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_j_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  58,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_j_emlrtDCI = { 58,/* lineNo */
  21,                                  /* colNo */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_k_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  724,                                 /* lineNo */
  102,                                 /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_k_emlrtDCI = { 724,/* lineNo */
  102,                                 /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_l_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  724,                                 /* lineNo */
  104,                                 /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_l_emlrtDCI = { 724,/* lineNo */
  104,                                 /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c7_m_emlrtDCI = { 49,/* lineNo */
  1,                                   /* colNo */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c7_n_emlrtDCI = { 49,/* lineNo */
  1,                                   /* colNo */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c7_m_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  41,                                  /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "computeConnectedComponentAreas",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\computeConnectedComponentAreas.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_o_emlrtDCI = { 41,/* lineNo */
  42,                                  /* colNo */
  "computeConnectedComponentAreas",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\computeConnectedComponentAreas.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_n_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  62,                                  /* colNo */
  "",                                  /* aName */
  "computeConnectedComponentAreas",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\computeConnectedComponentAreas.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_p_emlrtDCI = { 45,/* lineNo */
  62,                                  /* colNo */
  "computeConnectedComponentAreas",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\computeConnectedComponentAreas.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_o_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "computeConnectedComponentAreas",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\computeConnectedComponentAreas.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_q_emlrtDCI = { 45,/* lineNo */
  17,                                  /* colNo */
  "computeConnectedComponentAreas",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\computeConnectedComponentAreas.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_p_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  57,                                  /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_r_emlrtDCI = { 57,/* lineNo */
  20,                                  /* colNo */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_q_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  57,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_s_emlrtDCI = { 57,/* lineNo */
  22,                                  /* colNo */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_t_emlrtDCI = { 57,/* lineNo */
  42,                                  /* colNo */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_s_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  57,                                  /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_u_emlrtDCI = { 57,/* lineNo */
  44,                                  /* colNo */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_t_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  57,                                  /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_v_emlrtDCI = { 57,/* lineNo */
  46,                                  /* colNo */
  "bwareaopen",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwareaopen.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_u_emlrtBCI = { 1,/* iFirst */
  122,                                 /* iLast */
  724,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_w_emlrtDCI = { 724,/* lineNo */
  19,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_v_emlrtBCI = { 1,/* iFirst */
  162,                                 /* iLast */
  724,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_x_emlrtDCI = { 724,/* lineNo */
  58,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_w_emlrtBCI = { 1,/* iFirst */
  122,                                 /* iLast */
  230,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_y_emlrtDCI = { 230,/* lineNo */
  30,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_x_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  230,                                 /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ab_emlrtDCI = { 230,/* lineNo */
  34,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_y_emlrtBCI = { 1,/* iFirst */
  162,                                 /* iLast */
  230,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_bb_emlrtDCI = { 230,/* lineNo */
  39,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ab_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  230,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_cb_emlrtDCI = { 230,/* lineNo */
  43,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_bb_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  230,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_db_emlrtDCI = { 230,/* lineNo */
  20,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_cb_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  230,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_eb_emlrtDCI = { 230,/* lineNo */
  22,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_db_emlrtBCI = { 1,/* iFirst */
  2,                                   /* iLast */
  996,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "imfilter",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_fb_emlrtDCI = { 996,/* lineNo */
  32,                                  /* colNo */
  "imfilter",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_eb_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  156,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_gb_emlrtDCI = { 156,/* lineNo */
  36,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_fb_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  156,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_hb_emlrtDCI = { 156,/* lineNo */
  41,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_gb_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  156,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ib_emlrtDCI = { 156,/* lineNo */
  47,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_hb_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  156,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_jb_emlrtDCI = { 156,/* lineNo */
  52,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ib_emlrtBCI = { 1,/* iFirst */
  128,                                 /* iLast */
  156,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_kb_emlrtDCI = { 156,/* lineNo */
  27,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_jb_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  156,                                 /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_lb_emlrtDCI = { 156,/* lineNo */
  29,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_kb_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1055,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_mb_emlrtDCI = { 1055,/* lineNo */
  48,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_lb_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1056,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_nb_emlrtDCI = { 1056,/* lineNo */
  48,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_mb_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1070,                                /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ob_emlrtDCI = { 1070,/* lineNo */
  47,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_nb_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1057,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_pb_emlrtDCI = { 1057,/* lineNo */
  48,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ob_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1058,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_qb_emlrtDCI = { 1058,/* lineNo */
  48,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_pb_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  1134,                                /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_rb_emlrtDCI = { 1134,/* lineNo */
  18,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_qb_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  1134,                                /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_sb_emlrtDCI = { 1134,/* lineNo */
  34,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_rb_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  1134,                                /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_tb_emlrtDCI = { 1134,/* lineNo */
  50,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_sb_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  1134,                                /* lineNo */
  66,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ub_emlrtDCI = { 1134,/* lineNo */
  66,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_tb_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  1134,                                /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_vb_emlrtDCI = { 1134,/* lineNo */
  11,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ub_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  1072,                                /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_wb_emlrtDCI = { 1072,/* lineNo */
  52,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_vb_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  1072,                                /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_xb_emlrtDCI = { 1072,/* lineNo */
  15,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_wb_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  1060,                                /* lineNo */
  71,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_yb_emlrtDCI = { 1060,/* lineNo */
  71,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_xb_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  1060,                                /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_ac_emlrtDCI = { 1060,/* lineNo */
  24,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_yb_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  1061,                                /* lineNo */
  71,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_bc_emlrtDCI = { 1061,/* lineNo */
  71,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ac_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  1061,                                /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_cc_emlrtDCI = { 1061,/* lineNo */
  24,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_bc_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  1062,                                /* lineNo */
  71,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_dc_emlrtDCI = { 1062,/* lineNo */
  71,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_cc_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  1062,                                /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_ec_emlrtDCI = { 1062,/* lineNo */
  24,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_dc_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  63,                                  /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "stretchlim",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\stretchlim.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_fc_emlrtDCI = { 63,/* lineNo */
  36,                                  /* colNo */
  "stretchlim",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\stretchlim.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ec_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  1063,                                /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_gc_emlrtDCI = { 1063,/* lineNo */
  53,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_fc_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  1063,                                /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_hc_emlrtDCI = { 1063,/* lineNo */
  15,                                  /* colNo */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_gc_emlrtBCI = { 1,/* iFirst */
  256,                                 /* iLast */
  68,                                  /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "stretchlim",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\stretchlim.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ic_emlrtDCI = { 68,/* lineNo */
  37,                                  /* colNo */
  "stretchlim",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\stretchlim.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_hc_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  333,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "imadjust",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imadjust.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_jc_emlrtDCI = { 333,/* lineNo */
  46,                                  /* colNo */
  "imadjust",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imadjust.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ic_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  333,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "imadjust",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imadjust.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_kc_emlrtDCI = { 333,/* lineNo */
  13,                                  /* colNo */
  "imadjust",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imadjust.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo c7_g_emlrtRTEI = { 95,/* lineNo */
  21,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pName */
};

static emlrtDCInfo c7_lc_emlrtDCI = { 115,/* lineNo */
  47,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_jc_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  115,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_mc_emlrtDCI = { 115,/* lineNo */
  49,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_kc_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  115,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_nc_emlrtDCI = { 120,/* lineNo */
  47,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_lc_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  120,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_oc_emlrtDCI = { 120,/* lineNo */
  51,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_mc_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  120,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_pc_emlrtDCI = { 127,/* lineNo */
  43,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_nc_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  127,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_qc_emlrtDCI = { 127,/* lineNo */
  47,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_oc_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  127,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_rc_emlrtDCI = { 144,/* lineNo */
  51,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_pc_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  144,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_sc_emlrtDCI = { 144,/* lineNo */
  53,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_qc_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  144,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_tc_emlrtDCI = { 149,/* lineNo */
  51,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_rc_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  149,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_uc_emlrtDCI = { 149,/* lineNo */
  55,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_sc_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  149,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_vc_emlrtDCI = { 156,/* lineNo */
  47,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_tc_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  156,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_wc_emlrtDCI = { 156,/* lineNo */
  51,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_uc_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  156,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_xc_emlrtDCI = { 171,/* lineNo */
  43,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_vc_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  171,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_yc_emlrtDCI = { 171,/* lineNo */
  45,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_wc_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  171,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_ad_emlrtDCI = { 172,/* lineNo */
  43,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_xc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  172,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_bd_emlrtDCI = { 179,/* lineNo */
  27,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_yc_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  179,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_cd_emlrtDCI = { 179,/* lineNo */
  29,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ad_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  179,                                 /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_dd_emlrtDCI = { 91,/* lineNo */
  33,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_bd_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  91,                                  /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_ed_emlrtDCI = { 183,/* lineNo */
  33,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_cd_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  183,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_fd_emlrtDCI = { 199,/* lineNo */
  30,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_dd_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  199,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_gd_emlrtDCI = { 199,/* lineNo */
  32,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ed_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  199,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_hd_emlrtDCI = { 202,/* lineNo */
  30,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_fd_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  202,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_id_emlrtDCI = { 202,/* lineNo */
  32,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_gd_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  202,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_jd_emlrtDCI = { 205,/* lineNo */
  30,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_hd_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  205,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_kd_emlrtDCI = { 205,/* lineNo */
  32,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_id_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  205,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_ld_emlrtDCI = { 221,/* lineNo */
  23,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_jd_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  221,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_md_emlrtDCI = { 367,/* lineNo */
  11,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_kd_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  367,                                 /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_nd_emlrtDCI = { 370,/* lineNo */
  7,                                   /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ld_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  370,                                 /* lineNo */
  7,                                   /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c7_md_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  209,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_od_emlrtDCI = { 209,/* lineNo */
  37,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_nd_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  197,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_pd_emlrtDCI = { 197,/* lineNo */
  22,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_od_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  197,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_qd_emlrtDCI = { 197,/* lineNo */
  24,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_pd_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  336,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_rd_emlrtDCI = { 336,/* lineNo */
  24,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_qd_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  336,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_sd_emlrtDCI = { 336,/* lineNo */
  26,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_rd_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  336,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_td_emlrtDCI = { 336,/* lineNo */
  28,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_sd_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  336,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_ud_emlrtDCI = { 336,/* lineNo */
  15,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_td_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  336,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_vd_emlrtDCI = { 336,/* lineNo */
  17,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ud_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  198,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_wd_emlrtDCI = { 198,/* lineNo */
  33,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_vd_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  198,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_xd_emlrtDCI = { 198,/* lineNo */
  38,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_wd_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  201,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_yd_emlrtDCI = { 201,/* lineNo */
  33,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_xd_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  201,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ae_emlrtDCI = { 201,/* lineNo */
  38,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_yd_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  217,                                 /* lineNo */
  75,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_be_emlrtDCI = { 217,/* lineNo */
  75,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ae_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  204,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ce_emlrtDCI = { 204,/* lineNo */
  26,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_be_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  204,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_de_emlrtDCI = { 204,/* lineNo */
  28,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ce_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  199,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ee_emlrtDCI = { 199,/* lineNo */
  53,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_de_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  199,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_fe_emlrtDCI = { 199,/* lineNo */
  57,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ee_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  199,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ge_emlrtDCI = { 199,/* lineNo */
  65,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_fe_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  199,                                 /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_he_emlrtDCI = { 199,/* lineNo */
  67,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ge_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  202,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ie_emlrtDCI = { 202,/* lineNo */
  53,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_he_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  202,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_je_emlrtDCI = { 202,/* lineNo */
  57,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ie_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  202,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ke_emlrtDCI = { 202,/* lineNo */
  65,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_je_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  202,                                 /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_le_emlrtDCI = { 202,/* lineNo */
  67,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ke_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  205,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_me_emlrtDCI = { 205,/* lineNo */
  53,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_le_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  205,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ne_emlrtDCI = { 205,/* lineNo */
  55,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_me_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  205,                                 /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_oe_emlrtDCI = { 205,/* lineNo */
  63,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ne_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  205,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_pe_emlrtDCI = { 205,/* lineNo */
  65,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_oe_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  358,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_qe_emlrtDCI = { 358,/* lineNo */
  13,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_pe_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  359,                                 /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_re_emlrtDCI = { 359,/* lineNo */
  18,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_qe_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  225,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_se_emlrtDCI = { 225,/* lineNo */
  37,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_re_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  218,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_te_emlrtDCI = { 218,/* lineNo */
  22,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_se_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  219,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ue_emlrtDCI = { 219,/* lineNo */
  30,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_te_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  219,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ve_emlrtDCI = { 219,/* lineNo */
  32,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ue_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  219,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_we_emlrtDCI = { 219,/* lineNo */
  23,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ve_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  97,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_xe_emlrtDCI = { 97,/* lineNo */
  27,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_we_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  97,                                  /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ye_emlrtDCI = { 97,/* lineNo */
  29,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_xe_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  98,                                  /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_af_emlrtDCI = { 98,/* lineNo */
  43,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ye_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  98,                                  /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_bf_emlrtDCI = { 98,/* lineNo */
  45,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_af_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  99,                                  /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_cf_emlrtDCI = { 99,/* lineNo */
  40,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_bf_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  99,                                  /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_df_emlrtDCI = { 99,/* lineNo */
  42,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_cf_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  99,                                  /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_ef_emlrtDCI = { 99,/* lineNo */
  31,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_df_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  99,                                  /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_ff_emlrtDCI = { 99,/* lineNo */
  33,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ef_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  365,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_gf_emlrtDCI = { 365,/* lineNo */
  13,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ff_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  101,                                 /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_hf_emlrtDCI = { 101,/* lineNo */
  54,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_gf_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  101,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_if_emlrtDCI = { 101,/* lineNo */
  58,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_hf_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  366,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_jf_emlrtDCI = { 366,/* lineNo */
  15,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_if_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  165,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_kf_emlrtDCI = { 165,/* lineNo */
  58,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_jf_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  165,                                 /* lineNo */
  62,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_lf_emlrtDCI = { 165,/* lineNo */
  62,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_kf_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  102,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_mf_emlrtDCI = { 102,/* lineNo */
  58,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_lf_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  102,                                 /* lineNo */
  62,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_nf_emlrtDCI = { 102,/* lineNo */
  62,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_mf_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  166,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_of_emlrtDCI = { 166,/* lineNo */
  48,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_nf_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  166,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_pf_emlrtDCI = { 166,/* lineNo */
  52,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_of_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  166,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_qf_emlrtDCI = { 166,/* lineNo */
  39,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_pf_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  166,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_rf_emlrtDCI = { 166,/* lineNo */
  41,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_qf_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  105,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_sf_emlrtDCI = { 105,/* lineNo */
  48,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_rf_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  105,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_tf_emlrtDCI = { 105,/* lineNo */
  52,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_sf_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  105,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_uf_emlrtDCI = { 105,/* lineNo */
  39,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_tf_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  105,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_vf_emlrtDCI = { 105,/* lineNo */
  41,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_uf_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  168,                                 /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_wf_emlrtDCI = { 168,/* lineNo */
  50,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_vf_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  168,                                 /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_xf_emlrtDCI = { 168,/* lineNo */
  54,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_wf_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  131,                                 /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_yf_emlrtDCI = { 131,/* lineNo */
  50,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_xf_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  131,                                 /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ag_emlrtDCI = { 131,/* lineNo */
  54,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_yf_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  169,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_bg_emlrtDCI = { 169,/* lineNo */
  52,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ag_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  169,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_cg_emlrtDCI = { 169,/* lineNo */
  56,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_bg_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  169,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_dg_emlrtDCI = { 169,/* lineNo */
  43,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_cg_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  169,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_eg_emlrtDCI = { 169,/* lineNo */
  45,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_dg_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  161,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_fg_emlrtDCI = { 161,/* lineNo */
  52,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_eg_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  161,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_gg_emlrtDCI = { 161,/* lineNo */
  56,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_fg_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  161,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_hg_emlrtDCI = { 161,/* lineNo */
  43,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_gg_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  161,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_ig_emlrtDCI = { 161,/* lineNo */
  45,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_hg_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  134,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_jg_emlrtDCI = { 134,/* lineNo */
  52,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ig_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  134,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_kg_emlrtDCI = { 134,/* lineNo */
  56,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_jg_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  134,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_lg_emlrtDCI = { 134,/* lineNo */
  43,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_kg_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  134,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_mg_emlrtDCI = { 134,/* lineNo */
  45,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_lg_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  106,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ng_emlrtDCI = { 106,/* lineNo */
  45,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_mg_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  106,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_og_emlrtDCI = { 106,/* lineNo */
  47,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ng_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  106,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_pg_emlrtDCI = { 106,/* lineNo */
  49,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_og_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  106,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_qg_emlrtDCI = { 106,/* lineNo */
  57,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_pg_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  106,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_rg_emlrtDCI = { 106,/* lineNo */
  59,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_qg_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  109,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_sg_emlrtDCI = { 109,/* lineNo */
  42,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_rg_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  109,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_tg_emlrtDCI = { 109,/* lineNo */
  46,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_sg_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  109,                                 /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ug_emlrtDCI = { 109,/* lineNo */
  54,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_tg_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  109,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_vg_emlrtDCI = { 109,/* lineNo */
  58,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ug_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  107,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_wg_emlrtDCI = { 107,/* lineNo */
  52,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_vg_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  107,                                 /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_xg_emlrtDCI = { 107,/* lineNo */
  54,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_wg_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  107,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_yg_emlrtDCI = { 107,/* lineNo */
  56,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_xg_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  107,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_ah_emlrtDCI = { 107,/* lineNo */
  43,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_yg_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  107,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_bh_emlrtDCI = { 107,/* lineNo */
  45,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ah_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  135,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ch_emlrtDCI = { 135,/* lineNo */
  49,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_bh_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  135,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_dh_emlrtDCI = { 135,/* lineNo */
  51,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ch_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  135,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_eh_emlrtDCI = { 135,/* lineNo */
  53,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_dh_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  135,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_fh_emlrtDCI = { 135,/* lineNo */
  61,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_eh_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  135,                                 /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_gh_emlrtDCI = { 135,/* lineNo */
  63,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_fh_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  110,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_hh_emlrtDCI = { 110,/* lineNo */
  51,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_gh_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  110,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ih_emlrtDCI = { 110,/* lineNo */
  55,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_hh_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  138,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_jh_emlrtDCI = { 138,/* lineNo */
  46,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ih_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  138,                                 /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_kh_emlrtDCI = { 138,/* lineNo */
  50,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_jh_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  138,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_lh_emlrtDCI = { 138,/* lineNo */
  56,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_kh_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  138,                                 /* lineNo */
  60,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_mh_emlrtDCI = { 138,/* lineNo */
  60,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_lh_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  136,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_nh_emlrtDCI = { 136,/* lineNo */
  56,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_mh_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  136,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_oh_emlrtDCI = { 136,/* lineNo */
  58,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_nh_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  136,                                 /* lineNo */
  60,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ph_emlrtDCI = { 136,/* lineNo */
  60,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_oh_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  136,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_qh_emlrtDCI = { 136,/* lineNo */
  47,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ph_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  136,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_rh_emlrtDCI = { 136,/* lineNo */
  49,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_qh_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  139,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_sh_emlrtDCI = { 139,/* lineNo */
  55,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_rh_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  139,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_th_emlrtDCI = { 139,/* lineNo */
  59,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_sh_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  124,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_uh_emlrtDCI = { 124,/* lineNo */
  45,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_th_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  124,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_vh_emlrtDCI = { 124,/* lineNo */
  47,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_uh_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  124,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_wh_emlrtDCI = { 124,/* lineNo */
  51,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_vh_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  124,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_xh_emlrtDCI = { 124,/* lineNo */
  61,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_wh_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  124,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_yh_emlrtDCI = { 124,/* lineNo */
  65,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_xh_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  111,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ai_emlrtDCI = { 111,/* lineNo */
  49,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_yh_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  129,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_bi_emlrtDCI = { 129,/* lineNo */
  57,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ai_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  129,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ci_emlrtDCI = { 129,/* lineNo */
  59,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_bi_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  129,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_di_emlrtDCI = { 129,/* lineNo */
  39,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ci_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  129,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ei_emlrtDCI = { 129,/* lineNo */
  41,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_di_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  129,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_fi_emlrtDCI = { 129,/* lineNo */
  45,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ei_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  125,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_gi_emlrtDCI = { 125,/* lineNo */
  47,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_fi_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  125,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_hi_emlrtDCI = { 125,/* lineNo */
  49,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_gi_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  125,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ii_emlrtDCI = { 125,/* lineNo */
  53,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_hi_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  114,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ji_emlrtDCI = { 114,/* lineNo */
  46,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ii_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  114,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ki_emlrtDCI = { 114,/* lineNo */
  48,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ji_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  112,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_li_emlrtDCI = { 112,/* lineNo */
  55,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ki_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  153,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_mi_emlrtDCI = { 153,/* lineNo */
  49,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_li_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  153,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ni_emlrtDCI = { 153,/* lineNo */
  51,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_mi_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  153,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_oi_emlrtDCI = { 153,/* lineNo */
  55,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ni_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  153,                                 /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_pi_emlrtDCI = { 153,/* lineNo */
  63,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_oi_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  153,                                 /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_qi_emlrtDCI = { 153,/* lineNo */
  67,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_pi_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  140,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ri_emlrtDCI = { 140,/* lineNo */
  53,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_qi_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  126,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_si_emlrtDCI = { 126,/* lineNo */
  61,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ri_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  126,                                 /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ti_emlrtDCI = { 126,/* lineNo */
  63,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_si_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  126,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_ui_emlrtDCI = { 126,/* lineNo */
  43,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ti_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  126,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_vi_emlrtDCI = { 126,/* lineNo */
  45,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ui_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  126,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_wi_emlrtDCI = { 126,/* lineNo */
  49,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_vi_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  158,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_xi_emlrtDCI = { 158,/* lineNo */
  59,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_wi_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  158,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_yi_emlrtDCI = { 158,/* lineNo */
  61,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_xi_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  158,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_aj_emlrtDCI = { 158,/* lineNo */
  43,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_yi_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  158,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_bj_emlrtDCI = { 158,/* lineNo */
  45,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_aj_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  158,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_cj_emlrtDCI = { 158,/* lineNo */
  49,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_bj_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  154,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_dj_emlrtDCI = { 154,/* lineNo */
  51,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_cj_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  154,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ej_emlrtDCI = { 154,/* lineNo */
  53,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_dj_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  154,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_fj_emlrtDCI = { 154,/* lineNo */
  57,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ej_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  143,                                 /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_gj_emlrtDCI = { 143,/* lineNo */
  50,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_fj_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  143,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_hj_emlrtDCI = { 143,/* lineNo */
  52,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_gj_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  141,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ij_emlrtDCI = { 141,/* lineNo */
  59,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_hj_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  155,                                 /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_jj_emlrtDCI = { 155,/* lineNo */
  63,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ij_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  155,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_kj_emlrtDCI = { 155,/* lineNo */
  65,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_jj_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  155,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_lj_emlrtDCI = { 155,/* lineNo */
  47,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_kj_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  155,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_mj_emlrtDCI = { 155,/* lineNo */
  49,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_lj_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  155,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_nj_emlrtDCI = { 155,/* lineNo */
  53,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_mj_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  117,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_oj_emlrtDCI = { 117,/* lineNo */
  49,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_nj_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  117,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_pj_emlrtDCI = { 117,/* lineNo */
  51,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_oj_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  117,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_qj_emlrtDCI = { 117,/* lineNo */
  55,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_pj_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  117,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_rj_emlrtDCI = { 117,/* lineNo */
  65,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_qj_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  117,                                 /* lineNo */
  69,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_sj_emlrtDCI = { 117,/* lineNo */
  69,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_rj_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  122,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_tj_emlrtDCI = { 122,/* lineNo */
  61,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_sj_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  122,                                 /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_uj_emlrtDCI = { 122,/* lineNo */
  63,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_tj_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  122,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_vj_emlrtDCI = { 122,/* lineNo */
  43,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_uj_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  122,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_wj_emlrtDCI = { 122,/* lineNo */
  45,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_vj_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  122,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_xj_emlrtDCI = { 122,/* lineNo */
  49,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_wj_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  118,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_yj_emlrtDCI = { 118,/* lineNo */
  51,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_xj_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  118,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ak_emlrtDCI = { 118,/* lineNo */
  53,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_yj_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  118,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_bk_emlrtDCI = { 118,/* lineNo */
  57,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ak_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  146,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ck_emlrtDCI = { 146,/* lineNo */
  53,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_bk_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  146,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_dk_emlrtDCI = { 146,/* lineNo */
  55,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ck_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  146,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ek_emlrtDCI = { 146,/* lineNo */
  59,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_dk_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  146,                                 /* lineNo */
  69,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_fk_emlrtDCI = { 146,/* lineNo */
  69,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ek_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  146,                                 /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_gk_emlrtDCI = { 146,/* lineNo */
  73,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_fk_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  119,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_hk_emlrtDCI = { 119,/* lineNo */
  65,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_gk_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  119,                                 /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ik_emlrtDCI = { 119,/* lineNo */
  67,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_hk_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  119,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_jk_emlrtDCI = { 119,/* lineNo */
  47,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ik_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  119,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_kk_emlrtDCI = { 119,/* lineNo */
  49,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_jk_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  119,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_lk_emlrtDCI = { 119,/* lineNo */
  53,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_kk_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  151,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_mk_emlrtDCI = { 151,/* lineNo */
  65,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_lk_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  151,                                 /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_nk_emlrtDCI = { 151,/* lineNo */
  67,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_mk_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  151,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_ok_emlrtDCI = { 151,/* lineNo */
  47,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_nk_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  151,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_pk_emlrtDCI = { 151,/* lineNo */
  49,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ok_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  151,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_qk_emlrtDCI = { 151,/* lineNo */
  53,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_pk_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  147,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_rk_emlrtDCI = { 147,/* lineNo */
  55,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_qk_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  147,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_sk_emlrtDCI = { 147,/* lineNo */
  57,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_rk_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  147,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_tk_emlrtDCI = { 147,/* lineNo */
  61,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_sk_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  148,                                 /* lineNo */
  69,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_uk_emlrtDCI = { 148,/* lineNo */
  69,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_tk_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  148,                                 /* lineNo */
  71,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_vk_emlrtDCI = { 148,/* lineNo */
  71,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_uk_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  148,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_wk_emlrtDCI = { 148,/* lineNo */
  51,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_vk_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  148,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_xk_emlrtDCI = { 148,/* lineNo */
  53,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_wk_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  148,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_yk_emlrtDCI = { 148,/* lineNo */
  57,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_xk_emlrtBCI = { 1,/* iFirst */
  170,                                 /* iLast */
  715,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_al_emlrtDCI = { 715,/* lineNo */
  21,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_yk_emlrtBCI = { 1,/* iFirst */
  170,                                 /* iLast */
  709,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_bl_emlrtDCI = { 709,/* lineNo */
  21,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_al_emlrtBCI = { 1,/* iFirst */
  6,                                   /* iLast */
  709,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_cl_emlrtDCI = { 709,/* lineNo */
  19,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_bl_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  673,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_dl_emlrtDCI = { 673,/* lineNo */
  21,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_cl_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  667,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_el_emlrtDCI = { 667,/* lineNo */
  21,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_dl_emlrtBCI = { 1,/* iFirst */
  5,                                   /* iLast */
  667,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_fl_emlrtDCI = { 667,/* lineNo */
  19,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_el_emlrtBCI = { 1,/* iFirst */
  30,                                  /* iLast */
  30,                                  /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "setPackedFillBits",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\setPackedFillBits.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_gl_emlrtDCI = { 30,/* lineNo */
  50,                                  /* colNo */
  "setPackedFillBits",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\setPackedFillBits.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_fl_emlrtBCI = { 1,/* iFirst */
  166,                                 /* iLast */
  701,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c7_gl_emlrtBCI = { 1,/* iFirst */
  126,                                 /* iLast */
  701,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_hl_emlrtDCI = { 701,/* lineNo */
  19,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_hl_emlrtBCI = { 1,/* iFirst */
  166,                                 /* iLast */
  694,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c7_il_emlrtBCI = { 1,/* iFirst */
  126,                                 /* iLast */
  694,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_il_emlrtDCI = { 694,/* lineNo */
  19,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_jl_emlrtBCI = { 1,/* iFirst */
  166,                                 /* iLast */
  687,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_jl_emlrtDCI = { 687,/* lineNo */
  21,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_kl_emlrtBCI = { 1,/* iFirst */
  126,                                 /* iLast */
  687,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c7_ll_emlrtBCI = { 1,/* iFirst */
  166,                                 /* iLast */
  680,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_kl_emlrtDCI = { 680,/* lineNo */
  21,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ml_emlrtBCI = { 1,/* iFirst */
  126,                                 /* iLast */
  680,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c7_nl_emlrtBCI = { 1,/* iFirst */
  126,                                 /* iLast */
  724,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c7_ol_emlrtBCI = { 1,/* iFirst */
  166,                                 /* iLast */
  724,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c7_pl_emlrtBCI = { 1,/* iFirst */
  4,                                   /* iLast */
  724,                                 /* lineNo */
  102,                                 /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c7_ql_emlrtBCI = { 1,/* iFirst */
  166,                                 /* iLast */
  724,                                 /* lineNo */
  104,                                 /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c7_rl_emlrtBCI = { 1,/* iFirst */
  5,                                   /* iLast */
  724,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c7_sl_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  724,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c7_tl_emlrtBCI = { 1,/* iFirst */
  5,                                   /* iLast */
  730,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ll_emlrtDCI = { 730,/* lineNo */
  28,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_ul_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  730,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c7_ml_emlrtDCI = { 730,/* lineNo */
  30,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_vl_emlrtBCI = { 1,/* iFirst */
  6,                                   /* iLast */
  730,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_nl_emlrtDCI = { 730,/* lineNo */
  19,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_wl_emlrtBCI = { 1,/* iFirst */
  170,                                 /* iLast */
  730,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c7_ol_emlrtDCI = { 730,/* lineNo */
  21,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_xl_emlrtBCI = { 0,/* iFirst */
  31,                                  /* iLast */
  143,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "bitset",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\bitset.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c7_yl_emlrtBCI = { 1,/* iFirst */
  164,                                 /* iLast */
  715,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c7_am_emlrtBCI = { 1,/* iFirst */
  164,                                 /* iLast */
  709,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c7_bm_emlrtBCI = { 1,/* iFirst */
  162,                                 /* iLast */
  673,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c7_cm_emlrtBCI = { 1,/* iFirst */
  162,                                 /* iLast */
  667,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c7_dm_emlrtBCI = { 1,/* iFirst */
  24,                                  /* iLast */
  30,                                  /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "setPackedFillBits",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\setPackedFillBits.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c7_em_emlrtBCI = { 1,/* iFirst */
  162,                                 /* iLast */
  730,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c7_fm_emlrtBCI = { 1,/* iFirst */
  164,                                 /* iLast */
  730,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static char_T c7_cv[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
  'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

/* Function Declarations */
static void initialize_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void enable_c7_flightControlSystem(SFc7_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void c7_update_jit_animation_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void c7_do_animation_call_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance, const mxArray *c7_st);
static void c7_imgaussfilt(SFc7_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c7_sp, uint8_T c7_A[19200], uint8_T c7_d_B[19200]);
static void c7_imadjust(SFc7_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c7_sp, uint8_T c7_varargin_1[19200], uint8_T c7_out[19200]);
static real_T c7_sumColumnB(SFc7_flightControlSystemInstanceStruct
  *chartInstance, real_T c7_x[256], int32_T c7_col);
static void c7_bwlabel(SFc7_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c7_sp, boolean_T c7_varargin_1[19200], real_T c7_b_L[19200],
  real_T *c7_numComponents);
static void c7_check_forloop_overflow_error
  (SFc7_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c7_sp, boolean_T c7_overflow);
static boolean_T c7_isequal(SFc7_flightControlSystemInstanceStruct
  *chartInstance, real_T c7_varargin_1[9], real_T c7_varargin_2[9]);
static void c7_imclose(SFc7_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c7_sp, boolean_T c7_A[19200], boolean_T c7_d_B[19200]);
static uint32_T c7_bitset(SFc7_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c7_sp, uint32_T c7_b_a, real_T c7_bit);
static void c7_imerode(SFc7_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c7_sp, uint32_T c7_A[664], uint32_T c7_d_B[664]);
static void c7_imopen(SFc7_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c7_sp, boolean_T c7_A[19200], boolean_T
                      c7_d_B[19200]);
static void c7_b_imerode(SFc7_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c7_sp, uint32_T c7_A[640], uint32_T c7_d_B[640]);
static void c7_emlrt_marshallIn(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c7_nullptr, const char_T *c7_identifier,
  boolean_T c7_y[19200]);
static void c7_b_emlrt_marshallIn(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  boolean_T c7_y[19200]);
static void c7_slStringInitializeDynamicBuffers
  (SFc7_flightControlSystemInstanceStruct *chartInstance);
static void c7_chart_data_browse_helper(SFc7_flightControlSystemInstanceStruct
  *chartInstance, int32_T c7_ssIdNumber, const mxArray **c7_mxData, uint8_T
  *c7_isValueTooBig);
static const mxArray *c7_warning(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c7_sp, const mxArray *c7_input0, const
  mxArray *c7_input1);
static const mxArray *c7_b_warning(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c7_sp, const mxArray *c7_input0);
static void c7_array_int32_T_SetSize(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c7_sp, c7_coder_array_int32_T *c7_coderArray,
  const emlrtRTEInfo *c7_srcLocation, int32_T c7_size0);
static void c7_array_real_T_2D_SetSize(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c7_sp, c7_coder_array_real_T_2D
  *c7_coderArray, const emlrtRTEInfo *c7_srcLocation, int32_T c7_size0, int32_T
  c7_size1);
static void c7_array_int32_T_Constructor(SFc7_flightControlSystemInstanceStruct *
  chartInstance, c7_coder_array_int32_T *c7_coderArray);
static void c7_array_real_T_2D_Constructor
  (SFc7_flightControlSystemInstanceStruct *chartInstance,
   c7_coder_array_real_T_2D *c7_coderArray);
static void c7_array_int32_T_Destructor(SFc7_flightControlSystemInstanceStruct
  *chartInstance, c7_coder_array_int32_T *c7_coderArray);
static void c7_array_real_T_2D_Destructor(SFc7_flightControlSystemInstanceStruct
  *chartInstance, c7_coder_array_real_T_2D *c7_coderArray);
static void init_dsm_address_info(SFc7_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc7_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c7_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c7_st.tls = chartInstance->c7_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c7_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c7_doneDoubleBufferReInit = false;
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c7_decisionTxtEndIdx = 0U;
  static const uint32_T c7_decisionTxtStartIdx = 0U;
  setDataBrowseFcn(chartInstance->S, (void *)&c7_chart_data_browse_helper);
  chartInstance->c7_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c7_RuntimeVar,
    &chartInstance->c7_IsDebuggerActive,
    &chartInstance->c7_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c7_mlFcnLineNumber, &chartInstance->c7_IsHeatMapPresent, 0);
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c7_JITStateAnimation[0],
                        &chartInstance->c7_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c7_covrtInstance, 1U, 0U, 1U,
    46U);
  covrtChartInitFcn(chartInstance->c7_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c7_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c7_decisionTxtStartIdx, &c7_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c7_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c7_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  1U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c7_covrtInstance, 4U, 0U, 0U,
                     "c7_flightControlSystem", 0, -1, 1436);
  covrtEmlSaturationInitFcn(chartInstance->c7_covrtInstance, 4U, 0U, 0U, 1228,
    -1, 1247);
}

static void mdl_cleanup_runtime_resources_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c7_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c7_covrtInstance);
}

static void enable_c7_flightControlSystem(SFc7_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  static real_T c7_dv[9] = { 0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0 };

  c7_coder_array_int32_T c7_regionLengths;
  c7_coder_array_real_T_2D c7_c_r;
  emlrtStack c7_b_st;
  emlrtStack c7_c_st;
  emlrtStack c7_d_st;
  emlrtStack c7_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c7_b_y = NULL;
  const mxArray *c7_y = NULL;
  real_T c7_idx[320];
  real_T c7_imSizeT[2];
  real_T c7_M;
  real_T c7_b_c;
  real_T c7_b_d;
  real_T c7_b_k;
  real_T c7_b_numComponents;
  real_T c7_b_r;
  real_T c7_c_a;
  real_T c7_c_j;
  real_T c7_c_x;
  real_T c7_d;
  real_T c7_d1;
  real_T c7_d10;
  real_T c7_d11;
  real_T c7_d12;
  real_T c7_d13;
  real_T c7_d14;
  real_T c7_d15;
  real_T c7_d16;
  real_T c7_d17;
  real_T c7_d18;
  real_T c7_d19;
  real_T c7_d2;
  real_T c7_d3;
  real_T c7_d4;
  real_T c7_d5;
  real_T c7_d6;
  real_T c7_d7;
  real_T c7_d8;
  real_T c7_d9;
  real_T c7_d_a;
  real_T c7_d_i;
  real_T c7_d_k;
  real_T c7_e_a;
  real_T c7_e_b;
  real_T c7_f_a;
  real_T c7_g_a;
  real_T c7_g_j;
  real_T c7_h_a;
  real_T c7_h_i;
  real_T c7_i_a;
  real_T c7_idx1;
  real_T c7_idx2;
  real_T c7_j_a;
  real_T c7_j_j;
  real_T c7_k_i;
  real_T c7_numComponents;
  real_T c7_x;
  int32_T c7_b_regionLengths[1];
  int32_T c7_c_regionLengths[1];
  int32_T c7_b_a;
  int32_T c7_b_i;
  int32_T c7_b_ix;
  int32_T c7_b_j;
  int32_T c7_b_loop_ub;
  int32_T c7_b_nz;
  int32_T c7_b_pixelIdx;
  int32_T c7_b_xoffset;
  int32_T c7_c;
  int32_T c7_c_b;
  int32_T c7_c_c;
  int32_T c7_c_i;
  int32_T c7_c_k;
  int32_T c7_c_loop_ub;
  int32_T c7_d_b;
  int32_T c7_d_c;
  int32_T c7_d_j;
  int32_T c7_d_loop_ub;
  int32_T c7_e_c;
  int32_T c7_e_i;
  int32_T c7_e_j;
  int32_T c7_e_k;
  int32_T c7_f_c;
  int32_T c7_f_i;
  int32_T c7_f_j;
  int32_T c7_f_k;
  int32_T c7_g_c;
  int32_T c7_g_i;
  int32_T c7_h_c;
  int32_T c7_h_j;
  int32_T c7_i;
  int32_T c7_i1;
  int32_T c7_i10;
  int32_T c7_i11;
  int32_T c7_i12;
  int32_T c7_i13;
  int32_T c7_i14;
  int32_T c7_i15;
  int32_T c7_i16;
  int32_T c7_i17;
  int32_T c7_i18;
  int32_T c7_i19;
  int32_T c7_i2;
  int32_T c7_i20;
  int32_T c7_i21;
  int32_T c7_i22;
  int32_T c7_i23;
  int32_T c7_i24;
  int32_T c7_i25;
  int32_T c7_i26;
  int32_T c7_i27;
  int32_T c7_i28;
  int32_T c7_i29;
  int32_T c7_i3;
  int32_T c7_i30;
  int32_T c7_i31;
  int32_T c7_i32;
  int32_T c7_i33;
  int32_T c7_i34;
  int32_T c7_i35;
  int32_T c7_i36;
  int32_T c7_i37;
  int32_T c7_i38;
  int32_T c7_i39;
  int32_T c7_i4;
  int32_T c7_i40;
  int32_T c7_i41;
  int32_T c7_i42;
  int32_T c7_i43;
  int32_T c7_i44;
  int32_T c7_i45;
  int32_T c7_i46;
  int32_T c7_i47;
  int32_T c7_i48;
  int32_T c7_i49;
  int32_T c7_i5;
  int32_T c7_i50;
  int32_T c7_i51;
  int32_T c7_i52;
  int32_T c7_i53;
  int32_T c7_i54;
  int32_T c7_i55;
  int32_T c7_i56;
  int32_T c7_i57;
  int32_T c7_i58;
  int32_T c7_i59;
  int32_T c7_i6;
  int32_T c7_i60;
  int32_T c7_i61;
  int32_T c7_i62;
  int32_T c7_i63;
  int32_T c7_i64;
  int32_T c7_i65;
  int32_T c7_i66;
  int32_T c7_i67;
  int32_T c7_i68;
  int32_T c7_i69;
  int32_T c7_i7;
  int32_T c7_i70;
  int32_T c7_i71;
  int32_T c7_i72;
  int32_T c7_i73;
  int32_T c7_i74;
  int32_T c7_i75;
  int32_T c7_i76;
  int32_T c7_i77;
  int32_T c7_i78;
  int32_T c7_i79;
  int32_T c7_i8;
  int32_T c7_i80;
  int32_T c7_i81;
  int32_T c7_i82;
  int32_T c7_i83;
  int32_T c7_i84;
  int32_T c7_i85;
  int32_T c7_i86;
  int32_T c7_i87;
  int32_T c7_i9;
  int32_T c7_i_c;
  int32_T c7_i_i;
  int32_T c7_i_j;
  int32_T c7_ix;
  int32_T c7_j;
  int32_T c7_j_c;
  int32_T c7_j_i;
  int32_T c7_k;
  int32_T c7_k_c;
  int32_T c7_loop_ub;
  int32_T c7_nz;
  int32_T c7_pixelIdx;
  int32_T c7_pixelVal;
  int32_T c7_r;
  int32_T c7_xoffset;
  uint32_T c7_b_q0;
  uint32_T c7_b_qY;
  uint32_T c7_c_q0;
  uint32_T c7_c_qY;
  uint32_T c7_q0;
  uint32_T c7_qY;
  uint32_T c7_u;
  uint32_T c7_u1;
  uint32_T c7_u2;
  uint8_T c7_d_B[19200];
  boolean_T c7_bv[19200];
  boolean_T c7_bv1[19200];
  boolean_T c7_bv2[19200];
  boolean_T c7_bv3[19200];
  boolean_T c7_bv4[19200];
  boolean_T c7_bv5[19200];
  boolean_T c7_b_x[160];
  boolean_T c7_b;
  boolean_T c7_b1;
  boolean_T c7_b2;
  boolean_T c7_b3;
  boolean_T c7_b_b;
  boolean_T c7_covSaturation = false;
  boolean_T c7_f_b;
  c7_st.tls = chartInstance->c7_fEmlrtCtx;
  c7_b_st.prev = &c7_st;
  c7_b_st.tls = c7_st.tls;
  c7_c_st.prev = &c7_b_st;
  c7_c_st.tls = c7_b_st.tls;
  c7_d_st.prev = &c7_c_st;
  c7_d_st.tls = c7_c_st.tls;
  for (c7_i = 0; c7_i < 19200; c7_i++) {
    covrtSigUpdateFcn(chartInstance->c7_covrtInstance, 2U, (real_T)
                      (*chartInstance->c7_c_B)[c7_i]);
  }

  for (c7_i1 = 0; c7_i1 < 19200; c7_i1++) {
    covrtSigUpdateFcn(chartInstance->c7_covrtInstance, 1U, (real_T)
                      (*chartInstance->c7_d_G)[c7_i1]);
  }

  for (c7_i2 = 0; c7_i2 < 19200; c7_i2++) {
    covrtSigUpdateFcn(chartInstance->c7_covrtInstance, 0U, (real_T)
                      (*chartInstance->c7_R)[c7_i2]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_JITTransitionAnimation[0] = 0U;
  chartInstance->c7_sfEvent = CALL_EVENT;
  for (c7_i3 = 0; c7_i3 < 19200; c7_i3++) {
    chartInstance->c7_mask[c7_i3] = (*chartInstance->c7_R)[c7_i3];
  }

  for (c7_i4 = 0; c7_i4 < 19200; c7_i4++) {
    chartInstance->c7_G[c7_i4] = (*chartInstance->c7_d_G)[c7_i4];
  }

  for (c7_i5 = 0; c7_i5 < 19200; c7_i5++) {
    chartInstance->c7_B[c7_i5] = (*chartInstance->c7_c_B)[c7_i5];
  }

  covrtEmlFcnEval(chartInstance->c7_covrtInstance, 4U, 0, 0);
  for (c7_i6 = 0; c7_i6 < 19200; c7_i6++) {
    chartInstance->c7_b_mask[c7_i6] = chartInstance->c7_mask[c7_i6];
  }

  c7_b_st.site = &c7_emlrtRSI;
  c7_imgaussfilt(chartInstance, &c7_b_st, chartInstance->c7_b_mask,
                 chartInstance->c7_mask);
  for (c7_i7 = 0; c7_i7 < 19200; c7_i7++) {
    chartInstance->c7_b_G[c7_i7] = chartInstance->c7_G[c7_i7];
  }

  c7_b_st.site = &c7_b_emlrtRSI;
  c7_imgaussfilt(chartInstance, &c7_b_st, chartInstance->c7_b_G,
                 chartInstance->c7_G);
  for (c7_i8 = 0; c7_i8 < 19200; c7_i8++) {
    chartInstance->c7_b_B[c7_i8] = chartInstance->c7_B[c7_i8];
  }

  c7_b_st.site = &c7_c_emlrtRSI;
  c7_imgaussfilt(chartInstance, &c7_b_st, chartInstance->c7_b_B,
                 chartInstance->c7_B);
  for (c7_i9 = 0; c7_i9 < 19200; c7_i9++) {
    chartInstance->c7_c_mask[c7_i9] = chartInstance->c7_mask[c7_i9];
  }

  c7_b_st.site = &c7_d_emlrtRSI;
  c7_imadjust(chartInstance, &c7_b_st, chartInstance->c7_c_mask,
              chartInstance->c7_mask);
  for (c7_i10 = 0; c7_i10 < 19200; c7_i10++) {
    chartInstance->c7_c_G[c7_i10] = chartInstance->c7_G[c7_i10];
  }

  c7_b_st.site = &c7_e_emlrtRSI;
  c7_imadjust(chartInstance, &c7_b_st, chartInstance->c7_c_G,
              chartInstance->c7_G);
  for (c7_i11 = 0; c7_i11 < 19200; c7_i11++) {
    c7_d_B[c7_i11] = chartInstance->c7_B[c7_i11];
  }

  c7_b_st.site = &c7_f_emlrtRSI;
  c7_imadjust(chartInstance, &c7_b_st, c7_d_B, chartInstance->c7_B);
  for (c7_i12 = 0; c7_i12 < 19200; c7_i12++) {
    (*chartInstance->c7_BW)[c7_i12] = ((real_T)chartInstance->c7_mask[c7_i12] >=
      135.0);
  }

  for (c7_i13 = 0; c7_i13 < 19200; c7_i13++) {
    c7_bv[c7_i13] = ((real_T)chartInstance->c7_mask[c7_i13] <= 255.0);
  }

  for (c7_i14 = 0; c7_i14 < 19200; c7_i14++) {
    (*chartInstance->c7_BW)[c7_i14] = ((*chartInstance->c7_BW)[c7_i14] &&
      c7_bv[c7_i14]);
  }

  for (c7_i15 = 0; c7_i15 < 19200; c7_i15++) {
    c7_bv[c7_i15] = ((real_T)chartInstance->c7_G[c7_i15] >= 0.0);
  }

  for (c7_i16 = 0; c7_i16 < 19200; c7_i16++) {
    (*chartInstance->c7_BW)[c7_i16] = ((*chartInstance->c7_BW)[c7_i16] &&
      c7_bv[c7_i16]);
  }

  for (c7_i17 = 0; c7_i17 < 19200; c7_i17++) {
    c7_bv[c7_i17] = ((real_T)chartInstance->c7_G[c7_i17] <= 112.0);
  }

  for (c7_i18 = 0; c7_i18 < 19200; c7_i18++) {
    (*chartInstance->c7_BW)[c7_i18] = ((*chartInstance->c7_BW)[c7_i18] &&
      c7_bv[c7_i18]);
  }

  for (c7_i19 = 0; c7_i19 < 19200; c7_i19++) {
    c7_bv[c7_i19] = ((real_T)chartInstance->c7_B[c7_i19] >= 0.0);
  }

  for (c7_i20 = 0; c7_i20 < 19200; c7_i20++) {
    (*chartInstance->c7_BW)[c7_i20] = ((*chartInstance->c7_BW)[c7_i20] &&
      c7_bv[c7_i20]);
  }

  for (c7_i21 = 0; c7_i21 < 19200; c7_i21++) {
    c7_bv[c7_i21] = ((real_T)chartInstance->c7_B[c7_i21] <= 255.0);
  }

  for (c7_i22 = 0; c7_i22 < 19200; c7_i22++) {
    (*chartInstance->c7_BW)[c7_i22] = ((*chartInstance->c7_BW)[c7_i22] &&
      c7_bv[c7_i22]);
  }

  c7_b_st.site = &c7_g_emlrtRSI;
  c7_c_st.site = &c7_wb_emlrtRSI;
  for (c7_i23 = 0; c7_i23 < 19200; c7_i23++) {
    c7_bv1[c7_i23] = (*chartInstance->c7_BW)[c7_i23];
  }

  c7_bwlabel(chartInstance, &c7_c_st, c7_bv1, chartInstance->c7_L,
             &c7_numComponents);
  c7_c_st.site = &c7_xb_emlrtRSI;
  c7_b_numComponents = c7_numComponents;
  c7_array_int32_T_Constructor(chartInstance, &c7_regionLengths);
  if (!(c7_b_numComponents >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c7_b_numComponents, &c7_n_emlrtDCI, &c7_c_st);
  }

  c7_d = c7_b_numComponents;
  if (c7_d != (real_T)(int32_T)muDoubleScalarFloor(c7_d)) {
    emlrtIntegerCheckR2012b(c7_d, &c7_m_emlrtDCI, &c7_c_st);
  }

  c7_array_int32_T_SetSize(chartInstance, &c7_c_st, &c7_regionLengths,
    &c7_emlrtRTEI, (int32_T)c7_d);
  if (!(c7_b_numComponents >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c7_b_numComponents, &c7_n_emlrtDCI, &c7_c_st);
  }

  c7_d1 = c7_b_numComponents;
  if (c7_d1 != (real_T)(int32_T)muDoubleScalarFloor(c7_d1)) {
    emlrtIntegerCheckR2012b(c7_d1, &c7_m_emlrtDCI, &c7_c_st);
  }

  c7_loop_ub = (int32_T)c7_d1 - 1;
  for (c7_i24 = 0; c7_i24 <= c7_loop_ub; c7_i24++) {
    c7_regionLengths.vector.data[c7_i24] = 0;
  }

  for (c7_pixelIdx = 0; c7_pixelIdx < 19200; c7_pixelIdx++) {
    c7_b_pixelIdx = c7_pixelIdx;
    c7_d2 = (real_T)(c7_b_pixelIdx + 1);
    if (c7_d2 != (real_T)(int32_T)muDoubleScalarFloor(c7_d2)) {
      emlrtIntegerCheckR2012b(c7_d2, &c7_o_emlrtDCI, &c7_c_st);
    }

    c7_i25 = (int32_T)muDoubleScalarFloor(c7_d2);
    if ((c7_i25 < 1) || (c7_i25 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c7_i25, 1, 19200, &c7_m_emlrtBCI, &c7_c_st);
    }

    c7_pixelVal = (int32_T)chartInstance->c7_L[c7_i25 - 1];
    if (c7_pixelVal > 0) {
      c7_i28 = c7_regionLengths.size[0];
      c7_d3 = (real_T)c7_pixelVal;
      if (c7_d3 != (real_T)(int32_T)muDoubleScalarFloor(c7_d3)) {
        emlrtIntegerCheckR2012b(c7_d3, &c7_p_emlrtDCI, &c7_c_st);
      }

      c7_i30 = (int32_T)muDoubleScalarFloor(c7_d3);
      if ((c7_i30 < 1) || (c7_i30 > c7_i28)) {
        emlrtDynamicBoundsCheckR2012b(c7_i30, 1, c7_i28, &c7_n_emlrtBCI,
          &c7_c_st);
      }

      c7_b_a = c7_regionLengths.vector.data[c7_i30 - 1] + 1;
      c7_c_c = c7_b_a;
      c7_i34 = c7_regionLengths.size[0];
      c7_d4 = (real_T)c7_pixelVal;
      if (c7_d4 != (real_T)(int32_T)muDoubleScalarFloor(c7_d4)) {
        emlrtIntegerCheckR2012b(c7_d4, &c7_q_emlrtDCI, &c7_c_st);
      }

      c7_i36 = (int32_T)muDoubleScalarFloor(c7_d4);
      if ((c7_i36 < 1) || (c7_i36 > c7_i34)) {
        emlrtDynamicBoundsCheckR2012b(c7_i36, 1, c7_i34, &c7_o_emlrtBCI,
          &c7_c_st);
      }

      c7_regionLengths.vector.data[c7_i36 - 1] = c7_c_c;
    }
  }

  for (c7_c = 0; c7_c < 160; c7_c++) {
    c7_b_c = 1.0 + (real_T)c7_c;
    for (c7_r = 0; c7_r < 120; c7_r++) {
      c7_b_r = 1.0 + (real_T)c7_r;
      if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
        emlrtIntegerCheckR2012b(c7_b_r, &c7_r_emlrtDCI, &c7_b_st);
      }

      c7_i27 = (int32_T)c7_b_r;
      if ((c7_i27 < 1) || (c7_i27 > 120)) {
        emlrtDynamicBoundsCheckR2012b(c7_i27, 1, 120, &c7_p_emlrtBCI, &c7_b_st);
      }

      if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
        emlrtIntegerCheckR2012b(c7_b_c, &c7_s_emlrtDCI, &c7_b_st);
      }

      c7_i29 = (int32_T)c7_b_c;
      if ((c7_i29 < 1) || (c7_i29 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c7_i29, 1, 160, &c7_q_emlrtBCI, &c7_b_st);
      }

      if ((*chartInstance->c7_BW)[(c7_i27 + 120 * (c7_i29 - 1)) - 1]) {
        c7_i32 = c7_regionLengths.size[0];
        if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
          emlrtIntegerCheckR2012b(c7_b_r, &c7_u_emlrtDCI, &c7_b_st);
        }

        c7_i35 = (int32_T)c7_b_r;
        if ((c7_i35 < 1) || (c7_i35 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c7_i35, 1, 120, &c7_s_emlrtBCI, &c7_b_st);
        }

        if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
          emlrtIntegerCheckR2012b(c7_b_c, &c7_v_emlrtDCI, &c7_b_st);
        }

        c7_i39 = (int32_T)c7_b_c;
        if ((c7_i39 < 1) || (c7_i39 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c7_i39, 1, 160, &c7_t_emlrtBCI, &c7_b_st);
        }

        c7_d7 = chartInstance->c7_L[(c7_i35 + 120 * (c7_i39 - 1)) - 1];
        if (c7_d7 != (real_T)(int32_T)muDoubleScalarFloor(c7_d7)) {
          emlrtIntegerCheckR2012b(c7_d7, &c7_t_emlrtDCI, &c7_b_st);
        }

        c7_i43 = (int32_T)c7_d7;
        if ((c7_i43 < 1) || (c7_i43 > c7_i32)) {
          emlrtDynamicBoundsCheckR2012b(c7_i43, 1, c7_i32, &c7_r_emlrtBCI,
            &c7_b_st);
        }

        if (c7_regionLengths.vector.data[c7_i43 - 1] < 50) {
          if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
            emlrtIntegerCheckR2012b(c7_b_c, &c7_i_emlrtDCI, &c7_b_st);
          }

          c7_i48 = (int32_T)c7_b_c;
          if ((c7_i48 < 1) || (c7_i48 > 160)) {
            emlrtDynamicBoundsCheckR2012b(c7_i48, 1, 160, &c7_i_emlrtBCI,
              &c7_b_st);
          }

          if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
            emlrtIntegerCheckR2012b(c7_b_r, &c7_j_emlrtDCI, &c7_b_st);
          }

          c7_i52 = (int32_T)c7_b_r;
          if ((c7_i52 < 1) || (c7_i52 > 120)) {
            emlrtDynamicBoundsCheckR2012b(c7_i52, 1, 120, &c7_j_emlrtBCI,
              &c7_b_st);
          }

          (*chartInstance->c7_BW)[(c7_i52 + 120 * (c7_i48 - 1)) - 1] = false;
        }
      }
    }
  }

  c7_b_st.site = &c7_h_emlrtRSI;
  c7_c_st.site = &c7_jc_emlrtRSI;
  c7_d_st.site = &c7_nc_emlrtRSI;
  for (c7_k = 0; c7_k < 9; c7_k++) {
    c7_b_k = 1.0 + (real_T)c7_k;
    c7_x = c7_dv[(int32_T)c7_b_k - 1];
    c7_b = muDoubleScalarIsNaN(c7_x);
    if (c7_b) {
      c7_y = NULL;
      sf_mex_assign(&c7_y, sf_mex_create("y", c7_cv, 10, 0U, 1, 0U, 2, 1, 19),
                    false);
      c7_b_y = NULL;
      sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_cv, 10, 0U, 1, 0U, 2, 1, 19),
                    false);
      sf_mex_call(&c7_d_st, &c7_d_emlrtMCI, "error", 0U, 2U, 14, c7_y, 14,
                  sf_mex_call(&c7_d_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c7_d_st, NULL, "message", 1U, 1U, 14, c7_b_y)));
    }
  }

  for (c7_i26 = 0; c7_i26 < 19200; c7_i26++) {
    chartInstance->c7_mask[c7_i26] = (uint8_T)(*chartInstance->c7_BW)[c7_i26];
  }

  c7_c_st.site = &c7_kc_emlrtRSI;
  c7_d_st.site = &c7_t_emlrtRSI;
  for (c7_b_i = 0; c7_b_i < 122; c7_b_i++) {
    c7_d_i = 1.0 + (real_T)c7_b_i;
    if (c7_d_i != (real_T)(int32_T)muDoubleScalarFloor(c7_d_i)) {
      emlrtIntegerCheckR2012b(c7_d_i, &c7_d_emlrtDCI, &c7_d_st);
    }

    c7_i31 = (int32_T)c7_d_i;
    if ((c7_i31 < 1) || (c7_i31 > 122)) {
      emlrtDynamicBoundsCheckR2012b(c7_i31, 1, 122, &c7_d_emlrtBCI, &c7_d_st);
    }

    chartInstance->c7_maskPad[c7_i31 - 1] = 0U;
  }

  for (c7_c_i = 0; c7_c_i < 122; c7_c_i++) {
    c7_d_i = 1.0 + (real_T)c7_c_i;
    if (c7_d_i != (real_T)(int32_T)muDoubleScalarFloor(c7_d_i)) {
      emlrtIntegerCheckR2012b(c7_d_i, &c7_c_emlrtDCI, &c7_d_st);
    }

    c7_i33 = (int32_T)c7_d_i;
    if ((c7_i33 < 1) || (c7_i33 > 122)) {
      emlrtDynamicBoundsCheckR2012b(c7_i33, 1, 122, &c7_c_emlrtBCI, &c7_d_st);
    }

    chartInstance->c7_maskPad[c7_i33 + 19641] = 0U;
  }

  for (c7_j = 0; c7_j < 160; c7_j++) {
    c7_c_j = 1.0 + (real_T)c7_j;
    c7_c_a = c7_c_j;
    c7_d_c = (int32_T)c7_c_a;
    c7_d5 = (real_T)(c7_d_c + 1);
    if (c7_d5 != (real_T)(int32_T)muDoubleScalarFloor(c7_d5)) {
      emlrtIntegerCheckR2012b(c7_d5, &c7_b_emlrtDCI, &c7_d_st);
    }

    c7_i37 = (int32_T)muDoubleScalarFloor(c7_d5);
    if ((c7_i37 < 1) || (c7_i37 > 162)) {
      emlrtDynamicBoundsCheckR2012b(c7_i37, 1, 162, &c7_b_emlrtBCI, &c7_d_st);
    }

    chartInstance->c7_maskPad[122 * (c7_i37 - 1)] = 0U;
  }

  for (c7_b_j = 0; c7_b_j < 160; c7_b_j++) {
    c7_c_j = 1.0 + (real_T)c7_b_j;
    c7_d_a = c7_c_j;
    c7_e_c = (int32_T)c7_d_a;
    c7_d6 = (real_T)(c7_e_c + 1);
    if (c7_d6 != (real_T)(int32_T)muDoubleScalarFloor(c7_d6)) {
      emlrtIntegerCheckR2012b(c7_d6, &c7_emlrtDCI, &c7_d_st);
    }

    c7_i38 = (int32_T)muDoubleScalarFloor(c7_d6);
    if ((c7_i38 < 1) || (c7_i38 > 162)) {
      emlrtDynamicBoundsCheckR2012b(c7_i38, 1, 162, &c7_emlrtBCI, &c7_d_st);
    }

    chartInstance->c7_maskPad[121 + 122 * (c7_i38 - 1)] = 0U;
  }

  for (c7_d_j = 0; c7_d_j < 160; c7_d_j++) {
    c7_c_j = 1.0 + (real_T)c7_d_j;
    for (c7_e_i = 0; c7_e_i < 120; c7_e_i++) {
      c7_d_i = 1.0 + (real_T)c7_e_i;
      c7_e_a = c7_d_i;
      c7_f_c = (int32_T)c7_e_a;
      c7_f_a = c7_c_j;
      c7_g_c = (int32_T)c7_f_a;
      if (c7_d_i != (real_T)(int32_T)muDoubleScalarFloor(c7_d_i)) {
        emlrtIntegerCheckR2012b(c7_d_i, &c7_k_emlrtDCI, &c7_d_st);
      }

      c7_i42 = (int32_T)c7_d_i;
      if ((c7_i42 < 1) || (c7_i42 > 120)) {
        emlrtDynamicBoundsCheckR2012b(c7_i42, 1, 120, &c7_k_emlrtBCI, &c7_d_st);
      }

      if (c7_c_j != (real_T)(int32_T)muDoubleScalarFloor(c7_c_j)) {
        emlrtIntegerCheckR2012b(c7_c_j, &c7_l_emlrtDCI, &c7_d_st);
      }

      c7_i46 = (int32_T)c7_c_j;
      if ((c7_i46 < 1) || (c7_i46 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c7_i46, 1, 160, &c7_l_emlrtBCI, &c7_d_st);
      }

      c7_d10 = (real_T)(c7_f_c + 1);
      if (c7_d10 != (real_T)(int32_T)muDoubleScalarFloor(c7_d10)) {
        emlrtIntegerCheckR2012b(c7_d10, &c7_w_emlrtDCI, &c7_d_st);
      }

      c7_i51 = (int32_T)muDoubleScalarFloor(c7_d10);
      if ((c7_i51 < 1) || (c7_i51 > 122)) {
        emlrtDynamicBoundsCheckR2012b(c7_i51, 1, 122, &c7_u_emlrtBCI, &c7_d_st);
      }

      c7_d13 = (real_T)(c7_g_c + 1);
      if (c7_d13 != (real_T)(int32_T)muDoubleScalarFloor(c7_d13)) {
        emlrtIntegerCheckR2012b(c7_d13, &c7_x_emlrtDCI, &c7_d_st);
      }

      c7_i56 = (int32_T)muDoubleScalarFloor(c7_d13);
      if ((c7_i56 < 1) || (c7_i56 > 162)) {
        emlrtDynamicBoundsCheckR2012b(c7_i56, 1, 162, &c7_v_emlrtBCI, &c7_d_st);
      }

      chartInstance->c7_maskPad[(c7_i51 + 122 * (c7_i56 - 1)) - 1] =
        chartInstance->c7_mask[(c7_i42 + 120 * (c7_i46 - 1)) - 1];
    }
  }

  c7_c_st.site = &c7_lc_emlrtRSI;
  c7_d_st.site = &c7_t_emlrtRSI;
  for (c7_f_i = 0; c7_f_i < 122; c7_f_i++) {
    c7_h_i = 1.0 + (real_T)c7_f_i;
    if (c7_h_i != (real_T)(int32_T)muDoubleScalarFloor(c7_h_i)) {
      emlrtIntegerCheckR2012b(c7_h_i, &c7_d_emlrtDCI, &c7_d_st);
    }

    c7_i40 = (int32_T)c7_h_i;
    if ((c7_i40 < 1) || (c7_i40 > 122)) {
      emlrtDynamicBoundsCheckR2012b(c7_i40, 1, 122, &c7_d_emlrtBCI, &c7_d_st);
    }

    chartInstance->c7_markerPad[c7_i40 - 1] = 0U;
  }

  for (c7_g_i = 0; c7_g_i < 122; c7_g_i++) {
    c7_h_i = 1.0 + (real_T)c7_g_i;
    if (c7_h_i != (real_T)(int32_T)muDoubleScalarFloor(c7_h_i)) {
      emlrtIntegerCheckR2012b(c7_h_i, &c7_c_emlrtDCI, &c7_d_st);
    }

    c7_i41 = (int32_T)c7_h_i;
    if ((c7_i41 < 1) || (c7_i41 > 122)) {
      emlrtDynamicBoundsCheckR2012b(c7_i41, 1, 122, &c7_c_emlrtBCI, &c7_d_st);
    }

    chartInstance->c7_markerPad[c7_i41 + 19641] = 0U;
  }

  for (c7_e_j = 0; c7_e_j < 160; c7_e_j++) {
    c7_g_j = 1.0 + (real_T)c7_e_j;
    c7_g_a = c7_g_j;
    c7_h_c = (int32_T)c7_g_a;
    c7_d8 = (real_T)(c7_h_c + 1);
    if (c7_d8 != (real_T)(int32_T)muDoubleScalarFloor(c7_d8)) {
      emlrtIntegerCheckR2012b(c7_d8, &c7_b_emlrtDCI, &c7_d_st);
    }

    c7_i45 = (int32_T)muDoubleScalarFloor(c7_d8);
    if ((c7_i45 < 1) || (c7_i45 > 162)) {
      emlrtDynamicBoundsCheckR2012b(c7_i45, 1, 162, &c7_b_emlrtBCI, &c7_d_st);
    }

    chartInstance->c7_markerPad[122 * (c7_i45 - 1)] = 0U;
  }

  for (c7_f_j = 0; c7_f_j < 160; c7_f_j++) {
    c7_g_j = 1.0 + (real_T)c7_f_j;
    c7_h_a = c7_g_j;
    c7_i_c = (int32_T)c7_h_a;
    c7_d9 = (real_T)(c7_i_c + 1);
    if (c7_d9 != (real_T)(int32_T)muDoubleScalarFloor(c7_d9)) {
      emlrtIntegerCheckR2012b(c7_d9, &c7_emlrtDCI, &c7_d_st);
    }

    c7_i47 = (int32_T)muDoubleScalarFloor(c7_d9);
    if ((c7_i47 < 1) || (c7_i47 > 162)) {
      emlrtDynamicBoundsCheckR2012b(c7_i47, 1, 162, &c7_emlrtBCI, &c7_d_st);
    }

    chartInstance->c7_markerPad[121 + 122 * (c7_i47 - 1)] = 0U;
  }

  for (c7_h_j = 0; c7_h_j < 160; c7_h_j++) {
    c7_g_j = 1.0 + (real_T)c7_h_j;
    for (c7_i_i = 0; c7_i_i < 120; c7_i_i++) {
      c7_h_i = 1.0 + (real_T)c7_i_i;
      c7_i_a = c7_h_i;
      c7_j_c = (int32_T)c7_i_a;
      c7_j_a = c7_g_j;
      c7_k_c = (int32_T)c7_j_a;
      if (c7_h_i != (real_T)(int32_T)muDoubleScalarFloor(c7_h_i)) {
        emlrtIntegerCheckR2012b(c7_h_i, &c7_k_emlrtDCI, &c7_d_st);
      }

      c7_i54 = (int32_T)c7_h_i;
      if ((c7_i54 < 1) || (c7_i54 > 120)) {
        emlrtDynamicBoundsCheckR2012b(c7_i54, 1, 120, &c7_k_emlrtBCI, &c7_d_st);
      }

      if (c7_h_i != (real_T)(int32_T)muDoubleScalarFloor(c7_h_i)) {
        emlrtIntegerCheckR2012b(c7_h_i, &c7_k_emlrtDCI, &c7_d_st);
      }

      if (c7_g_j != (real_T)(int32_T)muDoubleScalarFloor(c7_g_j)) {
        emlrtIntegerCheckR2012b(c7_g_j, &c7_l_emlrtDCI, &c7_d_st);
      }

      c7_i59 = (int32_T)c7_g_j;
      if ((c7_i59 < 1) || (c7_i59 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c7_i59, 1, 160, &c7_l_emlrtBCI, &c7_d_st);
      }

      if (c7_g_j != (real_T)(int32_T)muDoubleScalarFloor(c7_g_j)) {
        emlrtIntegerCheckR2012b(c7_g_j, &c7_l_emlrtDCI, &c7_d_st);
      }

      if (c7_h_i != (real_T)(int32_T)muDoubleScalarFloor(c7_h_i)) {
        emlrtIntegerCheckR2012b(c7_h_i, &c7_k_emlrtDCI, &c7_d_st);
      }

      c7_i63 = (int32_T)c7_h_i;
      if ((c7_i63 < 1) || (c7_i63 > 120)) {
        emlrtDynamicBoundsCheckR2012b(c7_i63, 1, 120, &c7_k_emlrtBCI, &c7_d_st);
      }

      if (c7_h_i != (real_T)(int32_T)muDoubleScalarFloor(c7_h_i)) {
        emlrtIntegerCheckR2012b(c7_h_i, &c7_k_emlrtDCI, &c7_d_st);
      }

      if (c7_g_j != (real_T)(int32_T)muDoubleScalarFloor(c7_g_j)) {
        emlrtIntegerCheckR2012b(c7_g_j, &c7_l_emlrtDCI, &c7_d_st);
      }

      c7_i68 = (int32_T)c7_g_j;
      if ((c7_i68 < 1) || (c7_i68 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c7_i68, 1, 160, &c7_l_emlrtBCI, &c7_d_st);
      }

      if (c7_g_j != (real_T)(int32_T)muDoubleScalarFloor(c7_g_j)) {
        emlrtIntegerCheckR2012b(c7_g_j, &c7_l_emlrtDCI, &c7_d_st);
      }

      c7_d16 = (real_T)(c7_j_c + 1);
      if (c7_d16 != (real_T)(int32_T)muDoubleScalarFloor(c7_d16)) {
        emlrtIntegerCheckR2012b(c7_d16, &c7_w_emlrtDCI, &c7_d_st);
      }

      c7_i74 = (int32_T)muDoubleScalarFloor(c7_d16);
      if ((c7_i74 < 1) || (c7_i74 > 122)) {
        emlrtDynamicBoundsCheckR2012b(c7_i74, 1, 122, &c7_u_emlrtBCI, &c7_d_st);
      }

      c7_d17 = (real_T)(c7_k_c + 1);
      if (c7_d17 != (real_T)(int32_T)muDoubleScalarFloor(c7_d17)) {
        emlrtIntegerCheckR2012b(c7_d17, &c7_x_emlrtDCI, &c7_d_st);
      }

      c7_i79 = (int32_T)muDoubleScalarFloor(c7_d17);
      if ((c7_i79 < 1) || (c7_i79 > 162)) {
        emlrtDynamicBoundsCheckR2012b(c7_i79, 1, 162, &c7_v_emlrtBCI, &c7_d_st);
      }

      chartInstance->c7_markerPad[(c7_i74 + 122 * (c7_i79 - 1)) - 1] =
        MAX_uint8_T;
    }
  }

  for (c7_i44 = 0; c7_i44 < 320; c7_i44++) {
    c7_idx[c7_i44] = 0.0;
  }

  c7_array_real_T_2D_Constructor(chartInstance, &c7_c_r);
  for (c7_c_k = 0; c7_c_k < 2; c7_c_k++) {
    c7_d_k = 1.0 + (real_T)c7_c_k;
    if (c7_d_k != (real_T)(int32_T)muDoubleScalarFloor(c7_d_k)) {
      emlrtIntegerCheckR2012b(c7_d_k, &c7_h_emlrtDCI, &c7_b_st);
    }

    c7_d11 = c7_d_k;
    if (c7_d11 <= 2.0) {
      c7_i53 = (int32_T)c7_d11;
      if ((c7_i53 < 1) || (c7_i53 > 2)) {
        emlrtDynamicBoundsCheckR2012b(c7_i53, 1, 2, &c7_h_emlrtBCI, &c7_b_st);
      }

      c7_d12 = (real_T)(122 + 40 * (c7_i53 - 1));
    } else {
      c7_d12 = 1.0;
    }

    c7_M = c7_d12 - 2.0;
    if (c7_d_k != (real_T)(int32_T)muDoubleScalarFloor(c7_d_k)) {
      emlrtIntegerCheckR2012b(c7_d_k, &c7_g_emlrtDCI, &c7_b_st);
    }

    c7_d14 = c7_d_k;
    if (c7_d14 <= 2.0) {
      c7_i58 = (int32_T)c7_d14;
      if ((c7_i58 < 1) || (c7_i58 > 2)) {
        emlrtDynamicBoundsCheckR2012b(c7_i58, 1, 2, &c7_g_emlrtBCI, &c7_b_st);
      }

      c7_d15 = (real_T)(122 + 40 * (c7_i58 - 1));
    } else {
      c7_d15 = 1.0;
    }

    c7_b_b = (c7_M < 1.0);
    c7_b1 = c7_b_b;
    c7_b2 = false;
    c7_b3 = (c7_b1 || c7_b2);
    if (c7_b3) {
      c7_i62 = 1;
      c7_i64 = 0;
    } else {
      c7_i62 = 1;
      if (c7_M != (real_T)(int32_T)muDoubleScalarFloor(c7_M)) {
        emlrtIntegerCheckR2012b(c7_M, &c7_f_emlrtDCI, &c7_b_st);
      }

      c7_i65 = (int32_T)c7_M;
      if ((c7_i65 < 1) || (c7_i65 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c7_i65, 1, 160, &c7_f_emlrtBCI, &c7_b_st);
      }

      c7_i64 = c7_i65;
    }

    c7_array_int32_T_SetSize(chartInstance, &c7_b_st, &c7_regionLengths,
      &c7_b_emlrtRTEI, (c7_i64 - c7_i62) + 1);
    c7_b_loop_ub = c7_i64 - c7_i62;
    for (c7_i66 = 0; c7_i66 <= c7_b_loop_ub; c7_i66++) {
      c7_regionLengths.vector.data[c7_i66] = (c7_i62 + c7_i66) - 1;
    }

    if (c7_d_k != (real_T)(int32_T)muDoubleScalarFloor(c7_d_k)) {
      emlrtIntegerCheckR2012b(c7_d_k, &c7_e_emlrtDCI, &c7_b_st);
    }

    c7_i69 = (int32_T)c7_d_k;
    if ((c7_i69 < 1) || (c7_i69 > 2)) {
      emlrtDynamicBoundsCheckR2012b(c7_i69, 1, 2, &c7_e_emlrtBCI, &c7_b_st);
    }

    c7_i72 = c7_i69;
    c7_b_d = c7_d15 - 1.0;
    c7_e_b = c7_b_d;
    c7_c_x = c7_e_b;
    c7_f_b = muDoubleScalarIsNaN(c7_c_x);
    if (c7_f_b) {
      c7_array_real_T_2D_SetSize(chartInstance, &c7_b_st, &c7_c_r,
        &c7_c_emlrtRTEI, 1, 1);
      c7_c_r.vector.data[0] = rtNaN;
    } else if (c7_e_b < 2.0) {
      c7_array_real_T_2D_SetSize(chartInstance, &c7_b_st, &c7_c_r,
        &c7_c_emlrtRTEI, 1, 0);
    } else {
      c7_array_real_T_2D_SetSize(chartInstance, &c7_b_st, &c7_c_r,
        &c7_c_emlrtRTEI, 1, (int32_T)(c7_e_b - 2.0) + 1);
      c7_c_loop_ub = (int32_T)(c7_e_b - 2.0);
      for (c7_i78 = 0; c7_i78 <= c7_c_loop_ub; c7_i78++) {
        c7_c_r.vector.data[c7_i78] = 2.0 + (real_T)c7_i78;
      }
    }

    c7_b_regionLengths[0] = c7_regionLengths.size[0];
    emlrtSubAssignSizeCheckR2012b(&c7_b_regionLengths[0], 1, &c7_c_r.size[0], 2,
      &c7_emlrtECI, &c7_b_st);
    c7_c_regionLengths[0] = c7_regionLengths.size[0];
    c7_i82 = c7_i72 - 1;
    c7_d_loop_ub = c7_c_regionLengths[0] - 1;
    for (c7_i83 = 0; c7_i83 <= c7_d_loop_ub; c7_i83++) {
      c7_idx[c7_regionLengths.vector.data[c7_i83] + 160 * c7_i82] =
        c7_c_r.vector.data[c7_i83];
    }
  }

  c7_array_real_T_2D_Destructor(chartInstance, &c7_c_r);
  c7_array_int32_T_Destructor(chartInstance, &c7_regionLengths);
  for (c7_i49 = 0; c7_i49 < 19764; c7_i49++) {
    c7_q0 = 255U;
    c7_qY = c7_q0 - (uint32_T)chartInstance->c7_maskPad[c7_i49];
    c7_covSaturation = false;
    if (c7_qY > c7_q0) {
      c7_covSaturation = true;
      c7_qY = 0U;
    }

    c7_u = c7_qY;
    if (c7_u > 255U) {
      c7_covSaturation = true;
      c7_u = 255U;
    }

    chartInstance->c7_maskPad[c7_i49] = (uint8_T)c7_u;
  }

  for (c7_i50 = 0; c7_i50 < 19764; c7_i50++) {
    c7_b_q0 = 255U;
    c7_b_qY = c7_b_q0 - (uint32_T)chartInstance->c7_markerPad[c7_i50];
    if (c7_b_qY > c7_b_q0) {
      c7_covSaturation = true;
      c7_b_qY = 0U;
    }

    c7_u1 = c7_b_qY;
    if (c7_u1 > 255U) {
      c7_covSaturation = true;
      c7_u1 = 255U;
    }

    chartInstance->c7_markerPad[c7_i50] = (uint8_T)c7_u1;
  }

  c7_c_st.site = &c7_mc_emlrtRSI;
  c7_d_st.site = &c7_oc_emlrtRSI;
  for (c7_i55 = 0; c7_i55 < 2; c7_i55++) {
    c7_imSizeT[c7_i55] = 122.0 + 40.0 * (real_T)c7_i55;
  }

  ippreconstruct_uint8(&chartInstance->c7_markerPad[0],
                       &chartInstance->c7_maskPad[0], &c7_imSizeT[0], 1.0);
  for (c7_i57 = 0; c7_i57 < 19764; c7_i57++) {
    c7_c_q0 = 255U;
    c7_c_qY = c7_c_q0 - (uint32_T)chartInstance->c7_markerPad[c7_i57];
    if (c7_c_qY > c7_c_q0) {
      c7_covSaturation = true;
      c7_c_qY = 0U;
    }

    c7_u2 = c7_c_qY;
    if (c7_u2 > 255U) {
      c7_covSaturation = true;
      c7_u2 = 255U;
    }

    covrtSaturationUpdateFcn(chartInstance->c7_covrtInstance, 4, 0, 0, 0,
      c7_covSaturation);
    chartInstance->c7_markerPad[c7_i57] = (uint8_T)c7_u2;
  }

  for (c7_i60 = 0; c7_i60 < 160; c7_i60++) {
    c7_b_x[c7_i60] = (c7_idx[c7_i60] != 0.0);
  }

  c7_nz = (int32_T)c7_b_x[0];
  for (c7_e_k = 0; c7_e_k < 159; c7_e_k++) {
    c7_xoffset = c7_e_k;
    c7_ix = c7_xoffset;
    c7_c_b = (int32_T)c7_b_x[c7_ix + 1];
    c7_nz += (c7_c_b != 0);
  }

  c7_idx1 = (real_T)c7_nz;
  for (c7_i61 = 0; c7_i61 < 160; c7_i61++) {
    c7_b_x[c7_i61] = (c7_idx[c7_i61 + 160] != 0.0);
  }

  c7_b_nz = (int32_T)c7_b_x[0];
  for (c7_f_k = 0; c7_f_k < 159; c7_f_k++) {
    c7_b_xoffset = c7_f_k;
    c7_b_ix = c7_b_xoffset;
    c7_d_b = (int32_T)c7_b_x[c7_b_ix + 1];
    c7_b_nz += (c7_d_b != 0);
  }

  c7_idx2 = (real_T)c7_b_nz;
  c7_i67 = (int32_T)c7_idx1;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c7_idx1, mxDOUBLE_CLASS, c7_i67,
    &c7_f_emlrtRTEI, &c7_b_st);
  for (c7_j_i = 0; c7_j_i < c7_i67; c7_j_i++) {
    c7_k_i = 1.0 + (real_T)c7_j_i;
    c7_i71 = (int32_T)c7_idx2;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, c7_idx2, mxDOUBLE_CLASS, c7_i71,
      &c7_e_emlrtRTEI, &c7_b_st);
    for (c7_i_j = 0; c7_i_j < c7_i71; c7_i_j++) {
      c7_j_j = 1.0 + (real_T)c7_i_j;
      if (c7_k_i != (real_T)(int32_T)muDoubleScalarFloor(c7_k_i)) {
        emlrtIntegerCheckR2012b(c7_k_i, &c7_ab_emlrtDCI, &c7_b_st);
      }

      c7_i76 = (int32_T)c7_k_i;
      if ((c7_i76 < 1) || (c7_i76 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c7_i76, 1, 160, &c7_x_emlrtBCI, &c7_b_st);
      }

      c7_d18 = c7_idx[c7_i76 - 1];
      if (c7_d18 != (real_T)(int32_T)muDoubleScalarFloor(c7_d18)) {
        emlrtIntegerCheckR2012b(c7_d18, &c7_y_emlrtDCI, &c7_b_st);
      }

      c7_i81 = (int32_T)c7_d18;
      if ((c7_i81 < 1) || (c7_i81 > 122)) {
        emlrtDynamicBoundsCheckR2012b(c7_i81, 1, 122, &c7_w_emlrtBCI, &c7_b_st);
      }

      if (c7_j_j != (real_T)(int32_T)muDoubleScalarFloor(c7_j_j)) {
        emlrtIntegerCheckR2012b(c7_j_j, &c7_cb_emlrtDCI, &c7_b_st);
      }

      c7_i84 = (int32_T)c7_j_j;
      if ((c7_i84 < 1) || (c7_i84 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c7_i84, 1, 160, &c7_ab_emlrtBCI, &c7_b_st);
      }

      c7_d19 = c7_idx[c7_i84 + 159];
      if (c7_d19 != (real_T)(int32_T)muDoubleScalarFloor(c7_d19)) {
        emlrtIntegerCheckR2012b(c7_d19, &c7_bb_emlrtDCI, &c7_b_st);
      }

      c7_i85 = (int32_T)c7_d19;
      if ((c7_i85 < 1) || (c7_i85 > 162)) {
        emlrtDynamicBoundsCheckR2012b(c7_i85, 1, 162, &c7_y_emlrtBCI, &c7_b_st);
      }

      if (c7_k_i != (real_T)(int32_T)muDoubleScalarFloor(c7_k_i)) {
        emlrtIntegerCheckR2012b(c7_k_i, &c7_db_emlrtDCI, &c7_b_st);
      }

      c7_i86 = (int32_T)c7_k_i;
      if ((c7_i86 < 1) || (c7_i86 > 120)) {
        emlrtDynamicBoundsCheckR2012b(c7_i86, 1, 120, &c7_bb_emlrtBCI, &c7_b_st);
      }

      if (c7_j_j != (real_T)(int32_T)muDoubleScalarFloor(c7_j_j)) {
        emlrtIntegerCheckR2012b(c7_j_j, &c7_eb_emlrtDCI, &c7_b_st);
      }

      c7_i87 = (int32_T)c7_j_j;
      if ((c7_i87 < 1) || (c7_i87 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c7_i87, 1, 160, &c7_cb_emlrtBCI, &c7_b_st);
      }

      (*chartInstance->c7_BW)[(c7_i86 + 120 * (c7_i87 - 1)) - 1] =
        (chartInstance->c7_markerPad[(c7_i81 + 122 * (c7_i85 - 1)) - 1] != 0);
    }
  }

  for (c7_i70 = 0; c7_i70 < 19200; c7_i70++) {
    c7_bv2[c7_i70] = (*chartInstance->c7_BW)[c7_i70];
  }

  c7_b_st.site = &c7_i_emlrtRSI;
  c7_imclose(chartInstance, &c7_b_st, c7_bv2, c7_bv3);
  for (c7_i73 = 0; c7_i73 < 19200; c7_i73++) {
    (*chartInstance->c7_BW)[c7_i73] = c7_bv3[c7_i73];
  }

  for (c7_i75 = 0; c7_i75 < 19200; c7_i75++) {
    c7_bv4[c7_i75] = (*chartInstance->c7_BW)[c7_i75];
  }

  c7_b_st.site = &c7_j_emlrtRSI;
  c7_imopen(chartInstance, &c7_b_st, c7_bv4, c7_bv5);
  for (c7_i77 = 0; c7_i77 < 19200; c7_i77++) {
    (*chartInstance->c7_BW)[c7_i77] = c7_bv5[c7_i77];
  }

  for (c7_i80 = 0; c7_i80 < 19200; c7_i80++) {
    covrtSigUpdateFcn(chartInstance->c7_covrtInstance, 3U, (real_T)
                      (*chartInstance->c7_BW)[c7_i80]);
  }
}

static void ext_mode_exec_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c7_update_jit_animation_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c7_do_animation_call_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c7_b_y = NULL;
  const mxArray *c7_st = NULL;
  const mxArray *c7_y = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellmatrix(1, 1), false);
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", *chartInstance->c7_BW, 11, 0U, 1, 0U,
    2, 120, 160), false);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  sf_mex_assign(&c7_st, c7_y, false);
  return c7_st;
}

static void set_sim_state_c7_flightControlSystem
  (SFc7_flightControlSystemInstanceStruct *chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  int32_T c7_i;
  boolean_T c7_bv[19200];
  chartInstance->c7_doneDoubleBufferReInit = true;
  c7_u = sf_mex_dup(c7_st);
  c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 0)), "BW",
                      c7_bv);
  for (c7_i = 0; c7_i < 19200; c7_i++) {
    (*chartInstance->c7_BW)[c7_i] = c7_bv[c7_i];
  }

  sf_mex_destroy(&c7_u);
  sf_mex_destroy(&c7_st);
}

static void c7_imgaussfilt(SFc7_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c7_sp, uint8_T c7_A[19200], uint8_T c7_d_B[19200])
{
  static real_T c7_kernel[81] = { 0.00076344732860875273, 0.0018314149348447177,
    0.0034215335484046407, 0.0049783019377569017, 0.0056411551396688174,
    0.0049783019377569017, 0.0034215335484046407, 0.0018314149348447177,
    0.00076344732860875273, 0.0018314149348447177, 0.0043933360402013547,
    0.00820783229674747, 0.011942325524393562, 0.013532427693987039,
    0.011942325524393562, 0.00820783229674747, 0.0043933360402013547,
    0.0018314149348447177, 0.0034215335484046407, 0.00820783229674747,
    0.015334249507680094, 0.022311201383287918, 0.025281903333535138,
    0.022311201383287918, 0.015334249507680094, 0.00820783229674747,
    0.0034215335484046407, 0.0049783019377569017, 0.011942325524393562,
    0.022311201383287918, 0.03246260646250166, 0.036784952295500911,
    0.03246260646250166, 0.022311201383287918, 0.011942325524393562,
    0.0049783019377569017, 0.0056411551396688174, 0.013532427693987039,
    0.025281903333535138, 0.036784952295500911, 0.041682811789783857,
    0.036784952295500911, 0.025281903333535138, 0.013532427693987039,
    0.0056411551396688174, 0.0049783019377569017, 0.011942325524393562,
    0.022311201383287918, 0.03246260646250166, 0.036784952295500911,
    0.03246260646250166, 0.022311201383287918, 0.011942325524393562,
    0.0049783019377569017, 0.0034215335484046407, 0.00820783229674747,
    0.015334249507680094, 0.022311201383287918, 0.025281903333535138,
    0.022311201383287918, 0.015334249507680094, 0.00820783229674747,
    0.0034215335484046407, 0.0018314149348447177, 0.0043933360402013547,
    0.00820783229674747, 0.011942325524393562, 0.013532427693987039,
    0.011942325524393562, 0.00820783229674747, 0.0043933360402013547,
    0.0018314149348447177, 0.00076344732860875273, 0.0018314149348447177,
    0.0034215335484046407, 0.0049783019377569017, 0.0056411551396688174,
    0.0049783019377569017, 0.0034215335484046407, 0.0018314149348447177,
    0.00076344732860875273 };

  static real_T c7_nonZeroKernel[81] = { 0.00076344732860875273,
    0.0018314149348447177, 0.0034215335484046407, 0.0049783019377569017,
    0.0056411551396688174, 0.0049783019377569017, 0.0034215335484046407,
    0.0018314149348447177, 0.00076344732860875273, 0.0018314149348447177,
    0.0043933360402013547, 0.00820783229674747, 0.011942325524393562,
    0.013532427693987039, 0.011942325524393562, 0.00820783229674747,
    0.0043933360402013547, 0.0018314149348447177, 0.0034215335484046407,
    0.00820783229674747, 0.015334249507680094, 0.022311201383287918,
    0.025281903333535138, 0.022311201383287918, 0.015334249507680094,
    0.00820783229674747, 0.0034215335484046407, 0.0049783019377569017,
    0.011942325524393562, 0.022311201383287918, 0.03246260646250166,
    0.036784952295500911, 0.03246260646250166, 0.022311201383287918,
    0.011942325524393562, 0.0049783019377569017, 0.0056411551396688174,
    0.013532427693987039, 0.025281903333535138, 0.036784952295500911,
    0.041682811789783857, 0.036784952295500911, 0.025281903333535138,
    0.013532427693987039, 0.0056411551396688174, 0.0049783019377569017,
    0.011942325524393562, 0.022311201383287918, 0.03246260646250166,
    0.036784952295500911, 0.03246260646250166, 0.022311201383287918,
    0.011942325524393562, 0.0049783019377569017, 0.0034215335484046407,
    0.00820783229674747, 0.015334249507680094, 0.022311201383287918,
    0.025281903333535138, 0.022311201383287918, 0.015334249507680094,
    0.00820783229674747, 0.0034215335484046407, 0.0018314149348447177,
    0.0043933360402013547, 0.00820783229674747, 0.011942325524393562,
    0.013532427693987039, 0.011942325524393562, 0.00820783229674747,
    0.0043933360402013547, 0.0018314149348447177, 0.00076344732860875273,
    0.0018314149348447177, 0.0034215335484046407, 0.0049783019377569017,
    0.0056411551396688174, 0.0049783019377569017, 0.0034215335484046407,
    0.0018314149348447177, 0.00076344732860875273 };

  static int32_T c7_idxA[336] = { 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
    12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
    69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87,
    88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105,
    106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
    120, 120, 120, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
    23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41,
    42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
    61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98,
    99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113,
    114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128,
    129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143,
    144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158,
    159, 160, 160, 160, 160, 160 };

  emlrtStack c7_b_st;
  emlrtStack c7_c_st;
  emlrtStack c7_d_st;
  emlrtStack c7_st;
  real_T c7_connDimsT[2];
  real_T c7_outSizeT[2];
  real_T c7_padSizeT[2];
  real_T c7_startT[2];
  real_T c7_b_j;
  real_T c7_c_i;
  real_T c7_d;
  real_T c7_d1;
  real_T c7_d2;
  real_T c7_e_i;
  int32_T c7_b_i;
  int32_T c7_d_i;
  int32_T c7_i;
  int32_T c7_i1;
  int32_T c7_i10;
  int32_T c7_i11;
  int32_T c7_i12;
  int32_T c7_i13;
  int32_T c7_i14;
  int32_T c7_i15;
  int32_T c7_i16;
  int32_T c7_i2;
  int32_T c7_i3;
  int32_T c7_i4;
  int32_T c7_i5;
  int32_T c7_i6;
  int32_T c7_i7;
  int32_T c7_i8;
  int32_T c7_i9;
  int32_T c7_j;
  uint8_T c7_u;
  boolean_T c7_conn[81];
  boolean_T c7_b_modeFlag;
  boolean_T c7_b_tooBig;
  boolean_T c7_c_modeFlag;
  boolean_T c7_modeFlag;
  boolean_T c7_tooBig;
  c7_st.prev = c7_sp;
  c7_st.tls = c7_sp->tls;
  c7_st.site = &c7_k_emlrtRSI;
  c7_b_st.prev = &c7_st;
  c7_b_st.tls = c7_st.tls;
  c7_c_st.prev = &c7_b_st;
  c7_c_st.tls = c7_b_st.tls;
  c7_d_st.prev = &c7_c_st;
  c7_d_st.tls = c7_c_st.tls;
  c7_b_st.site = &c7_l_emlrtRSI;
  c7_b_st.site = &c7_m_emlrtRSI;
  c7_c_st.site = &c7_n_emlrtRSI;
  c7_d_st.site = &c7_q_emlrtRSI;
  for (c7_j = 0; c7_j < 168; c7_j++) {
    c7_b_j = 1.0 + (real_T)c7_j;
    for (c7_b_i = 0; c7_b_i < 128; c7_b_i++) {
      c7_c_i = 1.0 + (real_T)c7_b_i;
      if (c7_c_i != (real_T)(int32_T)muDoubleScalarFloor(c7_c_i)) {
        emlrtIntegerCheckR2012b(c7_c_i, &c7_hb_emlrtDCI, &c7_d_st);
      }

      c7_i1 = (int32_T)c7_c_i;
      if ((c7_i1 < 1) || (c7_i1 > 168)) {
        emlrtDynamicBoundsCheckR2012b(c7_i1, 1, 168, &c7_fb_emlrtBCI, &c7_d_st);
      }

      c7_d = (real_T)c7_idxA[c7_i1 - 1];
      if (c7_d != (real_T)(int32_T)muDoubleScalarFloor(c7_d)) {
        emlrtIntegerCheckR2012b(c7_d, &c7_gb_emlrtDCI, &c7_d_st);
      }

      c7_i3 = (int32_T)muDoubleScalarFloor(c7_d);
      if ((c7_i3 < 1) || (c7_i3 > 120)) {
        emlrtDynamicBoundsCheckR2012b(c7_i3, 1, 120, &c7_eb_emlrtBCI, &c7_d_st);
      }

      if (c7_b_j != (real_T)(int32_T)muDoubleScalarFloor(c7_b_j)) {
        emlrtIntegerCheckR2012b(c7_b_j, &c7_jb_emlrtDCI, &c7_d_st);
      }

      c7_i8 = (int32_T)c7_b_j;
      if ((c7_i8 < 1) || (c7_i8 > 168)) {
        emlrtDynamicBoundsCheckR2012b(c7_i8, 1, 168, &c7_hb_emlrtBCI, &c7_d_st);
      }

      c7_d1 = (real_T)c7_idxA[c7_i8 + 167];
      if (c7_d1 != (real_T)(int32_T)muDoubleScalarFloor(c7_d1)) {
        emlrtIntegerCheckR2012b(c7_d1, &c7_ib_emlrtDCI, &c7_d_st);
      }

      c7_i14 = (int32_T)muDoubleScalarFloor(c7_d1);
      if ((c7_i14 < 1) || (c7_i14 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c7_i14, 1, 160, &c7_gb_emlrtBCI, &c7_d_st);
      }

      if (c7_c_i != (real_T)(int32_T)muDoubleScalarFloor(c7_c_i)) {
        emlrtIntegerCheckR2012b(c7_c_i, &c7_kb_emlrtDCI, &c7_d_st);
      }

      c7_i15 = (int32_T)c7_c_i;
      if ((c7_i15 < 1) || (c7_i15 > 128)) {
        emlrtDynamicBoundsCheckR2012b(c7_i15, 1, 128, &c7_ib_emlrtBCI, &c7_d_st);
      }

      if (c7_b_j != (real_T)(int32_T)muDoubleScalarFloor(c7_b_j)) {
        emlrtIntegerCheckR2012b(c7_b_j, &c7_lb_emlrtDCI, &c7_d_st);
      }

      c7_i16 = (int32_T)c7_b_j;
      if ((c7_i16 < 1) || (c7_i16 > 168)) {
        emlrtDynamicBoundsCheckR2012b(c7_i16, 1, 168, &c7_jb_emlrtBCI, &c7_d_st);
      }

      chartInstance->c7_aTmp[(c7_i15 + ((c7_i16 - 1) << 7)) - 1] = c7_A[(c7_i3 +
        120 * (c7_i14 - 1)) - 1];
    }
  }

  for (c7_i = 0; c7_i < 21504; c7_i++) {
    chartInstance->c7_a[c7_i] = (real_T)chartInstance->c7_aTmp[c7_i];
  }

  c7_c_st.site = &c7_o_emlrtRSI;
  c7_d_st.site = &c7_u_emlrtRSI;
  c7_tooBig = true;
  for (c7_d_i = 0; c7_d_i < 2; c7_d_i++) {
    c7_e_i = 1.0 + (real_T)c7_d_i;
    if (c7_tooBig) {
      if (c7_e_i != (real_T)(int32_T)muDoubleScalarFloor(c7_e_i)) {
        emlrtIntegerCheckR2012b(c7_e_i, &c7_fb_emlrtDCI, &c7_d_st);
      }

      c7_i2 = (int32_T)c7_e_i;
      if ((c7_i2 < 1) || (c7_i2 > 2)) {
        emlrtDynamicBoundsCheckR2012b(c7_i2, 1, 2, &c7_db_emlrtBCI, &c7_d_st);
      }

      if (120.0 + 40.0 * (real_T)(c7_i2 - 1) > 65500.0) {
        c7_b_tooBig = true;
      } else {
        c7_b_tooBig = false;
      }
    } else {
      c7_b_tooBig = false;
    }

    c7_tooBig = c7_b_tooBig;
  }

  if (!c7_tooBig) {
    c7_modeFlag = true;
  } else {
    c7_modeFlag = false;
  }

  if (c7_modeFlag) {
    c7_b_modeFlag = true;
  } else {
    c7_b_modeFlag = false;
  }

  c7_c_modeFlag = c7_b_modeFlag;
  if (c7_c_modeFlag) {
    for (c7_i5 = 0; c7_i5 < 2; c7_i5++) {
      c7_padSizeT[c7_i5] = 128.0 + 40.0 * (real_T)c7_i5;
    }

    for (c7_i7 = 0; c7_i7 < 2; c7_i7++) {
      c7_outSizeT[c7_i7] = 120.0 + 40.0 * (real_T)c7_i7;
    }

    for (c7_i10 = 0; c7_i10 < 2; c7_i10++) {
      c7_connDimsT[c7_i10] = 9.0;
    }

    ippfilter_real64(&chartInstance->c7_a[0], &chartInstance->c7_bTmp[0],
                     &c7_outSizeT[0], 2.0, &c7_padSizeT[0], &c7_kernel[0],
                     &c7_connDimsT[0], false);
  } else {
    for (c7_i4 = 0; c7_i4 < 81; c7_i4++) {
      c7_conn[c7_i4] = true;
    }

    for (c7_i6 = 0; c7_i6 < 2; c7_i6++) {
      c7_padSizeT[c7_i6] = 128.0 + 40.0 * (real_T)c7_i6;
    }

    for (c7_i9 = 0; c7_i9 < 2; c7_i9++) {
      c7_outSizeT[c7_i9] = 120.0 + 40.0 * (real_T)c7_i9;
    }

    for (c7_i11 = 0; c7_i11 < 2; c7_i11++) {
      c7_connDimsT[c7_i11] = 9.0;
    }

    for (c7_i12 = 0; c7_i12 < 2; c7_i12++) {
      c7_startT[c7_i12] = 4.0;
    }

    imfilter_real64(&chartInstance->c7_a[0], &chartInstance->c7_bTmp[0], 2.0,
                    &c7_outSizeT[0], 2.0, &c7_padSizeT[0], &c7_nonZeroKernel[0],
                    81.0, &c7_conn[0], 2.0, &c7_connDimsT[0], &c7_startT[0], 2.0,
                    true, false);
  }

  for (c7_i13 = 0; c7_i13 < 19200; c7_i13++) {
    c7_d2 = muDoubleScalarRound(chartInstance->c7_bTmp[c7_i13]);
    if (c7_d2 < 256.0) {
      if (c7_d2 >= 0.0) {
        c7_u = (uint8_T)c7_d2;
      } else {
        c7_u = 0U;
      }
    } else if (c7_d2 >= 256.0) {
      c7_u = MAX_uint8_T;
    } else {
      c7_u = 0U;
    }

    c7_d_B[c7_i13] = c7_u;
  }
}

static void c7_imadjust(SFc7_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c7_sp, uint8_T c7_varargin_1[19200], uint8_T c7_out[19200])
{
  static char_T c7_cv2[40] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm', 'a',
    'd', 'j', 'u', 's', 't', ':', 'l', 'o', 'w', 'M', 'u', 's', 't', 'B', 'e',
    'S', 'm', 'a', 'l', 'l', 'e', 'r', 'T', 'h', 'a', 'n', 'H', 'i', 'g', 'h' };

  static char_T c7_cv3[39] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm', 'a',
    'd', 'j', 'u', 's', 't', ':', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r',
    's', 'A', 'r', 'e', 'O', 'u', 't', 'O', 'f', 'R', 'a', 'n', 'g', 'e' };

  static char_T c7_cv1[27] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm', 'h',
    'i', 's', 't', 'c', ':', 'i', 'n', 'p', 'u', 't', 'H', 'a', 's', 'N', 'a',
    'N', 's' };

  static char_T c7_b_cv[3] = { 'o', 'f', 'f' };

  emlrtStack c7_b_st;
  emlrtStack c7_c_st;
  emlrtStack c7_d_st;
  emlrtStack c7_st;
  const mxArray *c7_b_y = NULL;
  const mxArray *c7_e_y = NULL;
  const mxArray *c7_f_y = NULL;
  const mxArray *c7_g_y = NULL;
  const mxArray *c7_h_y = NULL;
  const mxArray *c7_s = NULL;
  const mxArray *c7_y = NULL;
  real_T c7_N[256];
  real_T c7_localBins1[256];
  real_T c7_localBins2[256];
  real_T c7_localBins3[256];
  real_T c7_ilowhigh[2];
  real_T c7_ab_x;
  real_T c7_b_b;
  real_T c7_b_fullRange;
  real_T c7_b_hIn;
  real_T c7_b_lIn;
  real_T c7_b_maxval;
  real_T c7_b_minval;
  real_T c7_b_out;
  real_T c7_b_varargin_1;
  real_T c7_b_varargin_2;
  real_T c7_bb_x;
  real_T c7_c_b;
  real_T c7_c_idx;
  real_T c7_c_maxval;
  real_T c7_c_minval;
  real_T c7_c_varargin_1;
  real_T c7_c_x;
  real_T c7_c_y;
  real_T c7_cb_x;
  real_T c7_d;
  real_T c7_d1;
  real_T c7_d10;
  real_T c7_d11;
  real_T c7_d12;
  real_T c7_d13;
  real_T c7_d14;
  real_T c7_d2;
  real_T c7_d3;
  real_T c7_d4;
  real_T c7_d5;
  real_T c7_d6;
  real_T c7_d7;
  real_T c7_d8;
  real_T c7_d9;
  real_T c7_d_i;
  real_T c7_d_varargin_1;
  real_T c7_d_x;
  real_T c7_db_x;
  real_T c7_e_varargin_1;
  real_T c7_e_x;
  real_T c7_eb_x;
  real_T c7_f_i;
  real_T c7_f_varargin_1;
  real_T c7_f_x;
  real_T c7_fb_x;
  real_T c7_fullRange;
  real_T c7_g_varargin_1;
  real_T c7_g_x;
  real_T c7_gb_x;
  real_T c7_hIn;
  real_T c7_h_x;
  real_T c7_highIn;
  real_T c7_i_x;
  real_T c7_i_y;
  real_T c7_ihigh;
  real_T c7_ilow;
  real_T c7_j_a;
  real_T c7_j_x;
  real_T c7_j_y;
  real_T c7_k_c;
  real_T c7_k_x;
  real_T c7_k_y;
  real_T c7_lIn;
  real_T c7_l_x;
  real_T c7_l_y;
  real_T c7_lowIn;
  real_T c7_m_a;
  real_T c7_m_x;
  real_T c7_m_y;
  real_T c7_maxval;
  real_T c7_minval;
  real_T c7_n_a;
  real_T c7_n_x;
  real_T c7_n_y;
  real_T c7_o_a;
  real_T c7_o_x;
  real_T c7_o_y;
  real_T c7_p_a;
  real_T c7_p_x;
  real_T c7_p_y;
  real_T c7_q_a;
  real_T c7_q_x;
  real_T c7_q_y;
  real_T c7_r_a;
  real_T c7_r_x;
  real_T c7_r_y;
  real_T c7_s_x;
  real_T c7_t_x;
  real_T c7_u_x;
  real_T c7_v_x;
  real_T c7_varargin_2;
  real_T c7_w_x;
  real_T c7_x_x;
  real_T c7_y_x;
  int32_T c7_b_a;
  int32_T c7_b_c;
  int32_T c7_b_i;
  int32_T c7_b_idx;
  int32_T c7_b_k;
  int32_T c7_c;
  int32_T c7_c_a;
  int32_T c7_c_c;
  int32_T c7_c_i;
  int32_T c7_d_a;
  int32_T c7_d_c;
  int32_T c7_e_a;
  int32_T c7_e_c;
  int32_T c7_e_i;
  int32_T c7_f_a;
  int32_T c7_f_c;
  int32_T c7_g_a;
  int32_T c7_g_c;
  int32_T c7_h_a;
  int32_T c7_h_c;
  int32_T c7_i;
  int32_T c7_i1;
  int32_T c7_i10;
  int32_T c7_i11;
  int32_T c7_i12;
  int32_T c7_i13;
  int32_T c7_i14;
  int32_T c7_i15;
  int32_T c7_i16;
  int32_T c7_i17;
  int32_T c7_i18;
  int32_T c7_i19;
  int32_T c7_i2;
  int32_T c7_i20;
  int32_T c7_i21;
  int32_T c7_i22;
  int32_T c7_i23;
  int32_T c7_i24;
  int32_T c7_i25;
  int32_T c7_i26;
  int32_T c7_i27;
  int32_T c7_i28;
  int32_T c7_i29;
  int32_T c7_i3;
  int32_T c7_i30;
  int32_T c7_i31;
  int32_T c7_i32;
  int32_T c7_i4;
  int32_T c7_i5;
  int32_T c7_i6;
  int32_T c7_i7;
  int32_T c7_i8;
  int32_T c7_i9;
  int32_T c7_i_a;
  int32_T c7_i_c;
  int32_T c7_idx;
  int32_T c7_idx1;
  int32_T c7_idx2;
  int32_T c7_idx3;
  int32_T c7_idx4;
  int32_T c7_j_c;
  int32_T c7_k;
  int32_T c7_k_a;
  int32_T c7_l_a;
  boolean_T c7_b;
  boolean_T c7_b1;
  boolean_T c7_b_isInvalid;
  boolean_T c7_b_x;
  boolean_T c7_c_isInvalid;
  boolean_T c7_d_isInvalid;
  boolean_T c7_d_y;
  boolean_T c7_findHighFlag;
  boolean_T c7_findLowFlag;
  boolean_T c7_isInvalid;
  boolean_T c7_x;
  c7_st.prev = c7_sp;
  c7_st.tls = c7_sp->tls;
  c7_b_st.prev = &c7_st;
  c7_b_st.tls = c7_st.tls;
  c7_c_st.prev = &c7_b_st;
  c7_c_st.tls = c7_b_st.tls;
  c7_d_st.prev = &c7_c_st;
  c7_d_st.tls = c7_c_st.tls;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_b_cv, 10, 0U, 1, 0U, 2, 1, 3),
                false);
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_cv1, 10, 0U, 1, 0U, 2, 1, 27),
                false);
  c7_st.site = &c7_cb_emlrtRSI;
  sf_mex_assign(&c7_s, c7_warning(chartInstance, &c7_st, c7_y, c7_b_y), false);
  c7_st.site = &c7_y_emlrtRSI;
  c7_b_st.site = &c7_eb_emlrtRSI;
  c7_c_st.site = &c7_fb_emlrtRSI;
  c7_d_st.site = &c7_gb_emlrtRSI;
  c7_b_out = 1.0;
  getnumcores(&c7_b_out);
  c7_d_st.site = &c7_hb_emlrtRSI;
  for (c7_i = 0; c7_i < 256; c7_i++) {
    c7_N[c7_i] = 0.0;
  }

  for (c7_i1 = 0; c7_i1 < 256; c7_i1++) {
    c7_localBins1[c7_i1] = 0.0;
  }

  for (c7_i2 = 0; c7_i2 < 256; c7_i2++) {
    c7_localBins2[c7_i2] = 0.0;
  }

  for (c7_i3 = 0; c7_i3 < 256; c7_i3++) {
    c7_localBins3[c7_i3] = 0.0;
  }

  for (c7_b_i = 1; c7_b_i + 3 <= 19200; c7_b_i += 4) {
    c7_d = (real_T)c7_b_i;
    if (c7_d != (real_T)(int32_T)muDoubleScalarFloor(c7_d)) {
      emlrtIntegerCheckR2012b(c7_d, &c7_mb_emlrtDCI, &c7_d_st);
    }

    c7_i4 = (int32_T)muDoubleScalarFloor(c7_d);
    if ((c7_i4 < 1) || (c7_i4 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c7_i4, 1, 19200, &c7_kb_emlrtBCI, &c7_d_st);
    }

    c7_idx1 = c7_varargin_1[c7_i4 - 1];
    c7_d2 = (real_T)(c7_b_i + 1);
    if (c7_d2 != (real_T)(int32_T)muDoubleScalarFloor(c7_d2)) {
      emlrtIntegerCheckR2012b(c7_d2, &c7_nb_emlrtDCI, &c7_d_st);
    }

    c7_i9 = (int32_T)muDoubleScalarFloor(c7_d2);
    if ((c7_i9 < 1) || (c7_i9 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c7_i9, 1, 19200, &c7_lb_emlrtBCI, &c7_d_st);
    }

    c7_idx2 = c7_varargin_1[c7_i9 - 1];
    c7_d4 = (real_T)(c7_b_i + 2);
    if (c7_d4 != (real_T)(int32_T)muDoubleScalarFloor(c7_d4)) {
      emlrtIntegerCheckR2012b(c7_d4, &c7_pb_emlrtDCI, &c7_d_st);
    }

    c7_i13 = (int32_T)muDoubleScalarFloor(c7_d4);
    if ((c7_i13 < 1) || (c7_i13 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c7_i13, 1, 19200, &c7_nb_emlrtBCI, &c7_d_st);
    }

    c7_idx3 = c7_varargin_1[c7_i13 - 1];
    c7_d6 = (real_T)(c7_b_i + 3);
    if (c7_d6 != (real_T)(int32_T)muDoubleScalarFloor(c7_d6)) {
      emlrtIntegerCheckR2012b(c7_d6, &c7_qb_emlrtDCI, &c7_d_st);
    }

    c7_i20 = (int32_T)muDoubleScalarFloor(c7_d6);
    if ((c7_i20 < 1) || (c7_i20 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c7_i20, 1, 19200, &c7_ob_emlrtBCI, &c7_d_st);
    }

    c7_idx4 = c7_varargin_1[c7_i20 - 1];
    c7_d_a = c7_idx1 + 1;
    c7_c_c = c7_d_a;
    c7_e_a = c7_idx1 + 1;
    c7_d_c = c7_e_a;
    c7_d7 = (real_T)c7_d_c;
    if (c7_d7 != (real_T)(int32_T)muDoubleScalarFloor(c7_d7)) {
      emlrtIntegerCheckR2012b(c7_d7, &c7_yb_emlrtDCI, &c7_d_st);
    }

    c7_i22 = (int32_T)muDoubleScalarFloor(c7_d7);
    if ((c7_i22 < 1) || (c7_i22 > 256)) {
      emlrtDynamicBoundsCheckR2012b(c7_i22, 1, 256, &c7_wb_emlrtBCI, &c7_d_st);
    }

    c7_d8 = (real_T)c7_c_c;
    if (c7_d8 != (real_T)(int32_T)muDoubleScalarFloor(c7_d8)) {
      emlrtIntegerCheckR2012b(c7_d8, &c7_ac_emlrtDCI, &c7_d_st);
    }

    c7_i23 = (int32_T)muDoubleScalarFloor(c7_d8);
    if ((c7_i23 < 1) || (c7_i23 > 256)) {
      emlrtDynamicBoundsCheckR2012b(c7_i23, 1, 256, &c7_xb_emlrtBCI, &c7_d_st);
    }

    c7_localBins1[c7_i23 - 1] = c7_localBins1[c7_i22 - 1] + 1.0;
    c7_f_a = c7_idx2 + 1;
    c7_e_c = c7_f_a;
    c7_g_a = c7_idx2 + 1;
    c7_f_c = c7_g_a;
    c7_d9 = (real_T)c7_f_c;
    if (c7_d9 != (real_T)(int32_T)muDoubleScalarFloor(c7_d9)) {
      emlrtIntegerCheckR2012b(c7_d9, &c7_bc_emlrtDCI, &c7_d_st);
    }

    c7_i25 = (int32_T)muDoubleScalarFloor(c7_d9);
    if ((c7_i25 < 1) || (c7_i25 > 256)) {
      emlrtDynamicBoundsCheckR2012b(c7_i25, 1, 256, &c7_yb_emlrtBCI, &c7_d_st);
    }

    c7_d10 = (real_T)c7_e_c;
    if (c7_d10 != (real_T)(int32_T)muDoubleScalarFloor(c7_d10)) {
      emlrtIntegerCheckR2012b(c7_d10, &c7_cc_emlrtDCI, &c7_d_st);
    }

    c7_i26 = (int32_T)muDoubleScalarFloor(c7_d10);
    if ((c7_i26 < 1) || (c7_i26 > 256)) {
      emlrtDynamicBoundsCheckR2012b(c7_i26, 1, 256, &c7_ac_emlrtBCI, &c7_d_st);
    }

    c7_localBins2[c7_i26 - 1] = c7_localBins2[c7_i25 - 1] + 1.0;
    c7_h_a = c7_idx3 + 1;
    c7_g_c = c7_h_a;
    c7_i_a = c7_idx3 + 1;
    c7_h_c = c7_i_a;
    c7_d11 = (real_T)c7_h_c;
    if (c7_d11 != (real_T)(int32_T)muDoubleScalarFloor(c7_d11)) {
      emlrtIntegerCheckR2012b(c7_d11, &c7_dc_emlrtDCI, &c7_d_st);
    }

    c7_i28 = (int32_T)muDoubleScalarFloor(c7_d11);
    if ((c7_i28 < 1) || (c7_i28 > 256)) {
      emlrtDynamicBoundsCheckR2012b(c7_i28, 1, 256, &c7_bc_emlrtBCI, &c7_d_st);
    }

    c7_d12 = (real_T)c7_g_c;
    if (c7_d12 != (real_T)(int32_T)muDoubleScalarFloor(c7_d12)) {
      emlrtIntegerCheckR2012b(c7_d12, &c7_ec_emlrtDCI, &c7_d_st);
    }

    c7_i29 = (int32_T)muDoubleScalarFloor(c7_d12);
    if ((c7_i29 < 1) || (c7_i29 > 256)) {
      emlrtDynamicBoundsCheckR2012b(c7_i29, 1, 256, &c7_cc_emlrtBCI, &c7_d_st);
    }

    c7_localBins3[c7_i29 - 1] = c7_localBins3[c7_i28 - 1] + 1.0;
    c7_k_a = c7_idx4 + 1;
    c7_i_c = c7_k_a;
    c7_l_a = c7_idx4 + 1;
    c7_j_c = c7_l_a;
    c7_d13 = (real_T)c7_j_c;
    if (c7_d13 != (real_T)(int32_T)muDoubleScalarFloor(c7_d13)) {
      emlrtIntegerCheckR2012b(c7_d13, &c7_gc_emlrtDCI, &c7_d_st);
    }

    c7_i30 = (int32_T)muDoubleScalarFloor(c7_d13);
    if ((c7_i30 < 1) || (c7_i30 > 256)) {
      emlrtDynamicBoundsCheckR2012b(c7_i30, 1, 256, &c7_ec_emlrtBCI, &c7_d_st);
    }

    c7_d14 = (real_T)c7_i_c;
    if (c7_d14 != (real_T)(int32_T)muDoubleScalarFloor(c7_d14)) {
      emlrtIntegerCheckR2012b(c7_d14, &c7_hc_emlrtDCI, &c7_d_st);
    }

    c7_i31 = (int32_T)muDoubleScalarFloor(c7_d14);
    if ((c7_i31 < 1) || (c7_i31 > 256)) {
      emlrtDynamicBoundsCheckR2012b(c7_i31, 1, 256, &c7_fc_emlrtBCI, &c7_d_st);
    }

    c7_N[c7_i31 - 1] = c7_N[c7_i30 - 1] + 1.0;
  }

  while (c7_b_i <= 19200) {
    c7_d1 = (real_T)c7_b_i;
    if (c7_d1 != (real_T)(int32_T)muDoubleScalarFloor(c7_d1)) {
      emlrtIntegerCheckR2012b(c7_d1, &c7_ob_emlrtDCI, &c7_d_st);
    }

    c7_i6 = (int32_T)muDoubleScalarFloor(c7_d1);
    if ((c7_i6 < 1) || (c7_i6 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c7_i6, 1, 19200, &c7_mb_emlrtBCI, &c7_d_st);
    }

    c7_idx = c7_varargin_1[c7_i6 - 1];
    c7_b_a = c7_idx + 1;
    c7_c = c7_b_a;
    c7_c_a = c7_idx + 1;
    c7_b_c = c7_c_a;
    c7_d3 = (real_T)c7_b_c;
    if (c7_d3 != (real_T)(int32_T)muDoubleScalarFloor(c7_d3)) {
      emlrtIntegerCheckR2012b(c7_d3, &c7_wb_emlrtDCI, &c7_d_st);
    }

    c7_i11 = (int32_T)muDoubleScalarFloor(c7_d3);
    if ((c7_i11 < 1) || (c7_i11 > 256)) {
      emlrtDynamicBoundsCheckR2012b(c7_i11, 1, 256, &c7_ub_emlrtBCI, &c7_d_st);
    }

    c7_d5 = (real_T)c7_c;
    if (c7_d5 != (real_T)(int32_T)muDoubleScalarFloor(c7_d5)) {
      emlrtIntegerCheckR2012b(c7_d5, &c7_xb_emlrtDCI, &c7_d_st);
    }

    c7_i18 = (int32_T)muDoubleScalarFloor(c7_d5);
    if ((c7_i18 < 1) || (c7_i18 > 256)) {
      emlrtDynamicBoundsCheckR2012b(c7_i18, 1, 256, &c7_vb_emlrtBCI, &c7_d_st);
    }

    c7_N[c7_i18 - 1] = c7_N[c7_i11 - 1] + 1.0;
    c7_b_i++;
  }

  for (c7_c_i = 0; c7_c_i < 256; c7_c_i++) {
    c7_d_i = 1.0 + (real_T)c7_c_i;
    if (c7_d_i != (real_T)(int32_T)muDoubleScalarFloor(c7_d_i)) {
      emlrtIntegerCheckR2012b(c7_d_i, &c7_rb_emlrtDCI, &c7_d_st);
    }

    c7_i7 = (int32_T)c7_d_i;
    if ((c7_i7 < 1) || (c7_i7 > 256)) {
      emlrtDynamicBoundsCheckR2012b(c7_i7, 1, 256, &c7_pb_emlrtBCI, &c7_d_st);
    }

    if (c7_d_i != (real_T)(int32_T)muDoubleScalarFloor(c7_d_i)) {
      emlrtIntegerCheckR2012b(c7_d_i, &c7_sb_emlrtDCI, &c7_d_st);
    }

    c7_i10 = (int32_T)c7_d_i;
    if ((c7_i10 < 1) || (c7_i10 > 256)) {
      emlrtDynamicBoundsCheckR2012b(c7_i10, 1, 256, &c7_qb_emlrtBCI, &c7_d_st);
    }

    if (c7_d_i != (real_T)(int32_T)muDoubleScalarFloor(c7_d_i)) {
      emlrtIntegerCheckR2012b(c7_d_i, &c7_tb_emlrtDCI, &c7_d_st);
    }

    c7_i12 = (int32_T)c7_d_i;
    if ((c7_i12 < 1) || (c7_i12 > 256)) {
      emlrtDynamicBoundsCheckR2012b(c7_i12, 1, 256, &c7_rb_emlrtBCI, &c7_d_st);
    }

    if (c7_d_i != (real_T)(int32_T)muDoubleScalarFloor(c7_d_i)) {
      emlrtIntegerCheckR2012b(c7_d_i, &c7_ub_emlrtDCI, &c7_d_st);
    }

    c7_i17 = (int32_T)c7_d_i;
    if ((c7_i17 < 1) || (c7_i17 > 256)) {
      emlrtDynamicBoundsCheckR2012b(c7_i17, 1, 256, &c7_sb_emlrtBCI, &c7_d_st);
    }

    if (c7_d_i != (real_T)(int32_T)muDoubleScalarFloor(c7_d_i)) {
      emlrtIntegerCheckR2012b(c7_d_i, &c7_vb_emlrtDCI, &c7_d_st);
    }

    c7_i21 = (int32_T)c7_d_i;
    if ((c7_i21 < 1) || (c7_i21 > 256)) {
      emlrtDynamicBoundsCheckR2012b(c7_i21, 1, 256, &c7_tb_emlrtBCI, &c7_d_st);
    }

    c7_N[c7_i21 - 1] = ((c7_N[c7_i7 - 1] + c7_localBins1[c7_i10 - 1]) +
                        c7_localBins2[c7_i12 - 1]) + c7_localBins3[c7_i17 - 1];
  }

  for (c7_i5 = 0; c7_i5 < 256; c7_i5++) {
    c7_localBins1[c7_i5] = c7_N[c7_i5];
  }

  for (c7_k = 0; c7_k < 255; c7_k++) {
    c7_b_k = c7_k;
    c7_localBins1[c7_b_k + 1] += c7_localBins1[c7_b_k];
  }

  c7_c_y = c7_sumColumnB(chartInstance, c7_N, 1);
  for (c7_i8 = 0; c7_i8 < 256; c7_i8++) {
    c7_localBins1[c7_i8] /= c7_c_y;
  }

  c7_findLowFlag = true;
  c7_findHighFlag = true;
  c7_ilow = 0.0;
  c7_ihigh = 0.0;
  for (c7_b_idx = 0; c7_b_idx < 256; c7_b_idx++) {
    c7_c_idx = 1.0 + (real_T)c7_b_idx;
    if (c7_findLowFlag) {
      if (c7_c_idx != (real_T)(int32_T)muDoubleScalarFloor(c7_c_idx)) {
        emlrtIntegerCheckR2012b(c7_c_idx, &c7_fc_emlrtDCI, &c7_st);
      }

      c7_i16 = (int32_T)c7_c_idx;
      if ((c7_i16 < 1) || (c7_i16 > 256)) {
        emlrtDynamicBoundsCheckR2012b(c7_i16, 1, 256, &c7_dc_emlrtBCI, &c7_st);
      }

      if (c7_localBins1[c7_i16 - 1] > 0.01) {
        c7_ilow = c7_c_idx;
        c7_findLowFlag = false;
      }
    }

    if (c7_findHighFlag) {
      if (c7_c_idx != (real_T)(int32_T)muDoubleScalarFloor(c7_c_idx)) {
        emlrtIntegerCheckR2012b(c7_c_idx, &c7_ic_emlrtDCI, &c7_st);
      }

      c7_i19 = (int32_T)c7_c_idx;
      if ((c7_i19 < 1) || (c7_i19 > 256)) {
        emlrtDynamicBoundsCheckR2012b(c7_i19, 1, 256, &c7_gc_emlrtBCI, &c7_st);
      }

      if (c7_localBins1[c7_i19 - 1] >= 0.99) {
        c7_ihigh = c7_c_idx;
        c7_findHighFlag = false;
      }
    }
  }

  if (c7_ilow == c7_ihigh) {
    for (c7_i14 = 0; c7_i14 < 2; c7_i14++) {
      c7_ilowhigh[c7_i14] = 1.0 + 255.0 * (real_T)c7_i14;
    }
  } else {
    c7_ilowhigh[0] = c7_ilow;
    c7_ilowhigh[1] = c7_ihigh;
  }

  for (c7_i15 = 0; c7_i15 < 2; c7_i15++) {
    c7_ilowhigh[c7_i15] = (c7_ilowhigh[c7_i15] - 1.0) / 255.0;
  }

  c7_st.site = &c7_db_emlrtRSI;
  c7_b_warning(chartInstance, &c7_st, sf_mex_dup(c7_s));
  c7_lowIn = c7_ilowhigh[0];
  c7_highIn = c7_ilowhigh[1];
  c7_x = (c7_lowIn >= c7_highIn);
  c7_b_x = c7_x;
  if (!c7_b_x) {
    c7_b = true;
  } else {
    c7_b = false;
  }

  c7_d_y = !c7_b;
  if (c7_d_y) {
    c7_e_y = NULL;
    sf_mex_assign(&c7_e_y, sf_mex_create("y", c7_cv2, 10, 0U, 1, 0U, 2, 1, 40),
                  false);
    c7_f_y = NULL;
    sf_mex_assign(&c7_f_y, sf_mex_create("y", c7_cv2, 10, 0U, 1, 0U, 2, 1, 40),
                  false);
    sf_mex_call(c7_sp, &c7_b_emlrtMCI, "error", 0U, 2U, 14, c7_e_y, 14,
                sf_mex_call(c7_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c7_sp, NULL, "message", 1U, 1U, 14, c7_f_y)));
  }

  c7_fullRange = c7_lowIn;
  c7_b_varargin_1 = c7_fullRange;
  c7_c_x = c7_b_varargin_1;
  c7_d_x = c7_c_x;
  c7_e_x = c7_d_x;
  c7_f_x = c7_e_x;
  c7_g_x = c7_f_x;
  c7_minval = c7_g_x;
  if (c7_minval < 0.0) {
    c7_isInvalid = true;
  } else {
    c7_c_varargin_1 = c7_fullRange;
    c7_h_x = c7_c_varargin_1;
    c7_i_x = c7_h_x;
    c7_j_x = c7_i_x;
    c7_k_x = c7_j_x;
    c7_l_x = c7_k_x;
    c7_maxval = c7_l_x;
    if (c7_maxval > 1.0) {
      c7_isInvalid = true;
    } else {
      c7_isInvalid = false;
    }
  }

  c7_b_isInvalid = c7_isInvalid;
  if (c7_b_isInvalid) {
    c7_b1 = true;
  } else {
    c7_b_fullRange = c7_highIn;
    c7_d_varargin_1 = c7_b_fullRange;
    c7_m_x = c7_d_varargin_1;
    c7_n_x = c7_m_x;
    c7_o_x = c7_n_x;
    c7_p_x = c7_o_x;
    c7_q_x = c7_p_x;
    c7_b_minval = c7_q_x;
    if (c7_b_minval < 0.0) {
      c7_c_isInvalid = true;
    } else {
      c7_e_varargin_1 = c7_b_fullRange;
      c7_r_x = c7_e_varargin_1;
      c7_s_x = c7_r_x;
      c7_t_x = c7_s_x;
      c7_u_x = c7_t_x;
      c7_v_x = c7_u_x;
      c7_b_maxval = c7_v_x;
      if (c7_b_maxval > 1.0) {
        c7_c_isInvalid = true;
      } else {
        c7_c_isInvalid = false;
      }
    }

    c7_d_isInvalid = c7_c_isInvalid;
    if (c7_d_isInvalid) {
      c7_b1 = true;
    } else {
      c7_b1 = false;
    }
  }

  if (c7_b1) {
    c7_g_y = NULL;
    sf_mex_assign(&c7_g_y, sf_mex_create("y", c7_cv3, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c7_h_y = NULL;
    sf_mex_assign(&c7_h_y, sf_mex_create("y", c7_cv3, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    sf_mex_call(c7_sp, &c7_emlrtMCI, "error", 0U, 2U, 14, c7_g_y, 14,
                sf_mex_call(c7_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c7_sp, NULL, "message", 1U, 1U, 14, c7_h_y)));
  }

  for (c7_i24 = 0; c7_i24 < 19200; c7_i24++) {
    chartInstance->c7_imgIn[c7_i24] = (real_T)c7_varargin_1[c7_i24] / 255.0;
  }

  c7_st.site = &c7_ab_emlrtRSI;
  c7_lIn = c7_lowIn;
  c7_hIn = c7_highIn;
  c7_b_st.site = &c7_kb_emlrtRSI;
  c7_b_lIn = c7_lIn;
  c7_b_hIn = c7_hIn;
  for (c7_e_i = 0; c7_e_i < 19200; c7_e_i++) {
    c7_f_i = 1.0 + (real_T)c7_e_i;
    c7_f_varargin_1 = c7_b_hIn;
    if (c7_f_i != (real_T)(int32_T)muDoubleScalarFloor(c7_f_i)) {
      emlrtIntegerCheckR2012b(c7_f_i, &c7_jc_emlrtDCI, &c7_b_st);
    }

    c7_i27 = (int32_T)c7_f_i;
    if ((c7_i27 < 1) || (c7_i27 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c7_i27, 1, 19200, &c7_hc_emlrtBCI, &c7_b_st);
    }

    c7_varargin_2 = chartInstance->c7_imgIn[c7_i27 - 1];
    c7_w_x = c7_f_varargin_1;
    c7_i_y = c7_varargin_2;
    c7_x_x = c7_w_x;
    c7_j_y = c7_i_y;
    c7_y_x = c7_x_x;
    c7_k_y = c7_j_y;
    c7_j_a = c7_y_x;
    c7_b_b = c7_k_y;
    c7_ab_x = c7_j_a;
    c7_l_y = c7_b_b;
    c7_bb_x = c7_ab_x;
    c7_m_y = c7_l_y;
    c7_c_minval = muDoubleScalarMin(c7_bb_x, c7_m_y);
    c7_g_varargin_1 = c7_b_lIn;
    c7_b_varargin_2 = c7_c_minval;
    c7_cb_x = c7_g_varargin_1;
    c7_n_y = c7_b_varargin_2;
    c7_db_x = c7_cb_x;
    c7_o_y = c7_n_y;
    c7_eb_x = c7_db_x;
    c7_p_y = c7_o_y;
    c7_m_a = c7_eb_x;
    c7_c_b = c7_p_y;
    c7_fb_x = c7_m_a;
    c7_q_y = c7_c_b;
    c7_gb_x = c7_fb_x;
    c7_r_y = c7_q_y;
    c7_c_maxval = muDoubleScalarMax(c7_gb_x, c7_r_y);
    c7_c_st.site = &c7_lb_emlrtRSI;
    c7_n_a = (c7_c_maxval - c7_b_lIn) / (c7_b_hIn - c7_b_lIn);
    c7_o_a = c7_n_a;
    c7_p_a = c7_o_a;
    c7_q_a = c7_p_a;
    c7_r_a = c7_q_a;
    c7_k_c = c7_r_a;
    if (c7_f_i != (real_T)(int32_T)muDoubleScalarFloor(c7_f_i)) {
      emlrtIntegerCheckR2012b(c7_f_i, &c7_kc_emlrtDCI, &c7_b_st);
    }

    c7_i32 = (int32_T)c7_f_i;
    if ((c7_i32 < 1) || (c7_i32 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c7_i32, 1, 19200, &c7_ic_emlrtBCI, &c7_b_st);
    }

    chartInstance->c7_outImg[c7_i32 - 1] = c7_k_c;
  }

  c7_st.site = &c7_bb_emlrtRSI;
  c7_b_st.site = &c7_ob_emlrtRSI;
  c7_c_st.site = &c7_pb_emlrtRSI;
  grayto8_real64(&chartInstance->c7_outImg[0], &c7_out[0], 19200.0);
  sf_mex_destroy(&c7_s);
}

static real_T c7_sumColumnB(SFc7_flightControlSystemInstanceStruct
  *chartInstance, real_T c7_x[256], int32_T c7_col)
{
  real_T c7_y;
  int32_T c7_b_col;
  int32_T c7_b_k;
  int32_T c7_i0;
  int32_T c7_k;
  (void)chartInstance;
  c7_b_col = c7_col - 1;
  c7_i0 = c7_b_col << 8;
  c7_y = c7_x[c7_i0];
  for (c7_k = 0; c7_k < 255; c7_k++) {
    c7_b_k = c7_k;
    c7_y += c7_x[(c7_i0 + c7_b_k) + 1];
  }

  return c7_y;
}

static void c7_bwlabel(SFc7_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c7_sp, boolean_T c7_varargin_1[19200], real_T c7_b_L[19200],
  real_T *c7_numComponents)
{
  emlrtStack c7_b_st;
  emlrtStack c7_c_st;
  emlrtStack c7_st;
  const mxArray *c7_c_y = NULL;
  const mxArray *c7_e_y = NULL;
  const mxArray *c7_f_y = NULL;
  const mxArray *c7_g_y = NULL;
  const mxArray *c7_h_y = NULL;
  const mxArray *c7_i_y = NULL;
  const mxArray *c7_j_y = NULL;
  const mxArray *c7_y = NULL;
  int64_T c7_i9;
  real_T c7_ab_x;
  real_T c7_b_a;
  real_T c7_b_c;
  real_T c7_b_i;
  real_T c7_b_j;
  real_T c7_b_numComponents;
  real_T c7_b_r;
  real_T c7_b_root;
  real_T c7_b_rootj;
  real_T c7_b_thread;
  real_T c7_b_varargin_1;
  real_T c7_b_x;
  real_T c7_b_y;
  real_T c7_c_i;
  real_T c7_c_j;
  real_T c7_c_root;
  real_T c7_c_rootj;
  real_T c7_c_varargin_1;
  real_T c7_c_x;
  real_T c7_d;
  real_T c7_d1;
  real_T c7_d10;
  real_T c7_d100;
  real_T c7_d101;
  real_T c7_d102;
  real_T c7_d103;
  real_T c7_d104;
  real_T c7_d105;
  real_T c7_d106;
  real_T c7_d107;
  real_T c7_d108;
  real_T c7_d109;
  real_T c7_d11;
  real_T c7_d110;
  real_T c7_d111;
  real_T c7_d112;
  real_T c7_d113;
  real_T c7_d114;
  real_T c7_d115;
  real_T c7_d116;
  real_T c7_d117;
  real_T c7_d118;
  real_T c7_d119;
  real_T c7_d12;
  real_T c7_d120;
  real_T c7_d121;
  real_T c7_d122;
  real_T c7_d123;
  real_T c7_d124;
  real_T c7_d125;
  real_T c7_d126;
  real_T c7_d127;
  real_T c7_d128;
  real_T c7_d129;
  real_T c7_d13;
  real_T c7_d130;
  real_T c7_d131;
  real_T c7_d132;
  real_T c7_d133;
  real_T c7_d134;
  real_T c7_d135;
  real_T c7_d136;
  real_T c7_d137;
  real_T c7_d138;
  real_T c7_d139;
  real_T c7_d14;
  real_T c7_d140;
  real_T c7_d141;
  real_T c7_d142;
  real_T c7_d143;
  real_T c7_d144;
  real_T c7_d145;
  real_T c7_d146;
  real_T c7_d147;
  real_T c7_d148;
  real_T c7_d149;
  real_T c7_d15;
  real_T c7_d150;
  real_T c7_d151;
  real_T c7_d152;
  real_T c7_d153;
  real_T c7_d154;
  real_T c7_d155;
  real_T c7_d156;
  real_T c7_d157;
  real_T c7_d158;
  real_T c7_d159;
  real_T c7_d16;
  real_T c7_d160;
  real_T c7_d161;
  real_T c7_d162;
  real_T c7_d163;
  real_T c7_d164;
  real_T c7_d165;
  real_T c7_d166;
  real_T c7_d167;
  real_T c7_d168;
  real_T c7_d169;
  real_T c7_d17;
  real_T c7_d170;
  real_T c7_d18;
  real_T c7_d19;
  real_T c7_d2;
  real_T c7_d20;
  real_T c7_d21;
  real_T c7_d22;
  real_T c7_d23;
  real_T c7_d24;
  real_T c7_d25;
  real_T c7_d26;
  real_T c7_d27;
  real_T c7_d28;
  real_T c7_d29;
  real_T c7_d3;
  real_T c7_d30;
  real_T c7_d31;
  real_T c7_d32;
  real_T c7_d33;
  real_T c7_d34;
  real_T c7_d35;
  real_T c7_d36;
  real_T c7_d37;
  real_T c7_d38;
  real_T c7_d39;
  real_T c7_d4;
  real_T c7_d40;
  real_T c7_d41;
  real_T c7_d42;
  real_T c7_d43;
  real_T c7_d44;
  real_T c7_d45;
  real_T c7_d46;
  real_T c7_d47;
  real_T c7_d48;
  real_T c7_d49;
  real_T c7_d5;
  real_T c7_d50;
  real_T c7_d51;
  real_T c7_d52;
  real_T c7_d53;
  real_T c7_d54;
  real_T c7_d55;
  real_T c7_d56;
  real_T c7_d57;
  real_T c7_d58;
  real_T c7_d59;
  real_T c7_d6;
  real_T c7_d60;
  real_T c7_d61;
  real_T c7_d62;
  real_T c7_d63;
  real_T c7_d64;
  real_T c7_d65;
  real_T c7_d66;
  real_T c7_d67;
  real_T c7_d68;
  real_T c7_d69;
  real_T c7_d7;
  real_T c7_d70;
  real_T c7_d71;
  real_T c7_d72;
  real_T c7_d73;
  real_T c7_d74;
  real_T c7_d75;
  real_T c7_d76;
  real_T c7_d77;
  real_T c7_d78;
  real_T c7_d79;
  real_T c7_d8;
  real_T c7_d80;
  real_T c7_d81;
  real_T c7_d82;
  real_T c7_d83;
  real_T c7_d84;
  real_T c7_d85;
  real_T c7_d86;
  real_T c7_d87;
  real_T c7_d88;
  real_T c7_d89;
  real_T c7_d9;
  real_T c7_d90;
  real_T c7_d91;
  real_T c7_d92;
  real_T c7_d93;
  real_T c7_d94;
  real_T c7_d95;
  real_T c7_d96;
  real_T c7_d97;
  real_T c7_d98;
  real_T c7_d99;
  real_T c7_d_i;
  real_T c7_d_j;
  real_T c7_d_root;
  real_T c7_d_rootj;
  real_T c7_d_x;
  real_T c7_e_a;
  real_T c7_e_j;
  real_T c7_e_root;
  real_T c7_e_x;
  real_T c7_f_i;
  real_T c7_f_j;
  real_T c7_f_root;
  real_T c7_firstLabel;
  real_T c7_g_i;
  real_T c7_g_j;
  real_T c7_h_i;
  real_T c7_h_j;
  real_T c7_i_i;
  real_T c7_i_j;
  real_T c7_j;
  real_T c7_j_i;
  real_T c7_j_j;
  real_T c7_k_i;
  real_T c7_k_x;
  real_T c7_l_i;
  real_T c7_l_x;
  real_T c7_label;
  real_T c7_m_i;
  real_T c7_m_x;
  real_T c7_minval;
  real_T c7_n_i;
  real_T c7_n_x;
  real_T c7_o_i;
  real_T c7_p_i;
  real_T c7_p_x;
  real_T c7_q_i;
  real_T c7_q_x;
  real_T c7_r_x;
  real_T c7_root;
  real_T c7_rootj;
  real_T c7_s_x;
  real_T c7_startC;
  real_T c7_t_x;
  real_T c7_u_x;
  real_T c7_v_x;
  real_T c7_w_x;
  real_T c7_x;
  real_T c7_x_x;
  real_T c7_y_x;
  real_T c7_z;
  int32_T c7_chunksSizeAndLabels[168];
  int32_T c7_b_q0;
  int32_T c7_b_q1;
  int32_T c7_b_qY;
  int32_T c7_b_z;
  int32_T c7_c;
  int32_T c7_c_a;
  int32_T c7_c_c;
  int32_T c7_c_q0;
  int32_T c7_c_q1;
  int32_T c7_c_qY;
  int32_T c7_c_r;
  int32_T c7_d_a;
  int32_T c7_d_c;
  int32_T c7_d_q0;
  int32_T c7_d_q1;
  int32_T c7_d_qY;
  int32_T c7_d_r;
  int32_T c7_d_y;
  int32_T c7_e_b;
  int32_T c7_e_i;
  int32_T c7_e_q0;
  int32_T c7_e_q1;
  int32_T c7_e_qY;
  int32_T c7_exitg1;
  int32_T c7_f_a;
  int32_T c7_f_b;
  int32_T c7_f_q0;
  int32_T c7_f_q1;
  int32_T c7_f_qY;
  int32_T c7_f_x;
  int32_T c7_g_a;
  int32_T c7_g_q0;
  int32_T c7_g_q1;
  int32_T c7_g_qY;
  int32_T c7_g_x;
  int32_T c7_h_q0;
  int32_T c7_h_q1;
  int32_T c7_h_qY;
  int32_T c7_h_x;
  int32_T c7_i;
  int32_T c7_i1;
  int32_T c7_i10;
  int32_T c7_i100;
  int32_T c7_i101;
  int32_T c7_i102;
  int32_T c7_i103;
  int32_T c7_i104;
  int32_T c7_i105;
  int32_T c7_i106;
  int32_T c7_i107;
  int32_T c7_i108;
  int32_T c7_i109;
  int32_T c7_i11;
  int32_T c7_i110;
  int32_T c7_i111;
  int32_T c7_i112;
  int32_T c7_i113;
  int32_T c7_i114;
  int32_T c7_i115;
  int32_T c7_i116;
  int32_T c7_i117;
  int32_T c7_i118;
  int32_T c7_i119;
  int32_T c7_i12;
  int32_T c7_i120;
  int32_T c7_i121;
  int32_T c7_i122;
  int32_T c7_i123;
  int32_T c7_i124;
  int32_T c7_i125;
  int32_T c7_i126;
  int32_T c7_i127;
  int32_T c7_i128;
  int32_T c7_i129;
  int32_T c7_i13;
  int32_T c7_i130;
  int32_T c7_i131;
  int32_T c7_i132;
  int32_T c7_i133;
  int32_T c7_i134;
  int32_T c7_i135;
  int32_T c7_i136;
  int32_T c7_i137;
  int32_T c7_i138;
  int32_T c7_i139;
  int32_T c7_i14;
  int32_T c7_i140;
  int32_T c7_i141;
  int32_T c7_i142;
  int32_T c7_i143;
  int32_T c7_i144;
  int32_T c7_i145;
  int32_T c7_i146;
  int32_T c7_i147;
  int32_T c7_i148;
  int32_T c7_i149;
  int32_T c7_i15;
  int32_T c7_i150;
  int32_T c7_i151;
  int32_T c7_i152;
  int32_T c7_i153;
  int32_T c7_i154;
  int32_T c7_i155;
  int32_T c7_i156;
  int32_T c7_i157;
  int32_T c7_i158;
  int32_T c7_i159;
  int32_T c7_i16;
  int32_T c7_i160;
  int32_T c7_i161;
  int32_T c7_i162;
  int32_T c7_i163;
  int32_T c7_i164;
  int32_T c7_i165;
  int32_T c7_i166;
  int32_T c7_i167;
  int32_T c7_i168;
  int32_T c7_i169;
  int32_T c7_i17;
  int32_T c7_i170;
  int32_T c7_i171;
  int32_T c7_i172;
  int32_T c7_i173;
  int32_T c7_i174;
  int32_T c7_i175;
  int32_T c7_i176;
  int32_T c7_i177;
  int32_T c7_i178;
  int32_T c7_i179;
  int32_T c7_i18;
  int32_T c7_i180;
  int32_T c7_i181;
  int32_T c7_i182;
  int32_T c7_i183;
  int32_T c7_i184;
  int32_T c7_i185;
  int32_T c7_i186;
  int32_T c7_i187;
  int32_T c7_i188;
  int32_T c7_i189;
  int32_T c7_i19;
  int32_T c7_i190;
  int32_T c7_i191;
  int32_T c7_i192;
  int32_T c7_i193;
  int32_T c7_i194;
  int32_T c7_i195;
  int32_T c7_i196;
  int32_T c7_i197;
  int32_T c7_i198;
  int32_T c7_i199;
  int32_T c7_i2;
  int32_T c7_i20;
  int32_T c7_i200;
  int32_T c7_i201;
  int32_T c7_i202;
  int32_T c7_i203;
  int32_T c7_i204;
  int32_T c7_i205;
  int32_T c7_i206;
  int32_T c7_i207;
  int32_T c7_i208;
  int32_T c7_i209;
  int32_T c7_i21;
  int32_T c7_i210;
  int32_T c7_i211;
  int32_T c7_i212;
  int32_T c7_i213;
  int32_T c7_i214;
  int32_T c7_i215;
  int32_T c7_i216;
  int32_T c7_i217;
  int32_T c7_i218;
  int32_T c7_i219;
  int32_T c7_i22;
  int32_T c7_i220;
  int32_T c7_i221;
  int32_T c7_i222;
  int32_T c7_i223;
  int32_T c7_i224;
  int32_T c7_i225;
  int32_T c7_i226;
  int32_T c7_i227;
  int32_T c7_i228;
  int32_T c7_i229;
  int32_T c7_i23;
  int32_T c7_i230;
  int32_T c7_i231;
  int32_T c7_i232;
  int32_T c7_i233;
  int32_T c7_i234;
  int32_T c7_i235;
  int32_T c7_i236;
  int32_T c7_i237;
  int32_T c7_i238;
  int32_T c7_i239;
  int32_T c7_i24;
  int32_T c7_i240;
  int32_T c7_i241;
  int32_T c7_i242;
  int32_T c7_i243;
  int32_T c7_i244;
  int32_T c7_i245;
  int32_T c7_i246;
  int32_T c7_i25;
  int32_T c7_i26;
  int32_T c7_i27;
  int32_T c7_i28;
  int32_T c7_i29;
  int32_T c7_i3;
  int32_T c7_i30;
  int32_T c7_i31;
  int32_T c7_i32;
  int32_T c7_i33;
  int32_T c7_i34;
  int32_T c7_i35;
  int32_T c7_i36;
  int32_T c7_i37;
  int32_T c7_i38;
  int32_T c7_i39;
  int32_T c7_i4;
  int32_T c7_i40;
  int32_T c7_i41;
  int32_T c7_i42;
  int32_T c7_i43;
  int32_T c7_i44;
  int32_T c7_i45;
  int32_T c7_i46;
  int32_T c7_i47;
  int32_T c7_i48;
  int32_T c7_i49;
  int32_T c7_i5;
  int32_T c7_i50;
  int32_T c7_i51;
  int32_T c7_i52;
  int32_T c7_i53;
  int32_T c7_i54;
  int32_T c7_i55;
  int32_T c7_i56;
  int32_T c7_i57;
  int32_T c7_i58;
  int32_T c7_i59;
  int32_T c7_i6;
  int32_T c7_i60;
  int32_T c7_i61;
  int32_T c7_i62;
  int32_T c7_i63;
  int32_T c7_i64;
  int32_T c7_i65;
  int32_T c7_i66;
  int32_T c7_i67;
  int32_T c7_i68;
  int32_T c7_i69;
  int32_T c7_i7;
  int32_T c7_i70;
  int32_T c7_i71;
  int32_T c7_i72;
  int32_T c7_i73;
  int32_T c7_i74;
  int32_T c7_i75;
  int32_T c7_i76;
  int32_T c7_i77;
  int32_T c7_i78;
  int32_T c7_i79;
  int32_T c7_i8;
  int32_T c7_i80;
  int32_T c7_i81;
  int32_T c7_i82;
  int32_T c7_i83;
  int32_T c7_i84;
  int32_T c7_i85;
  int32_T c7_i86;
  int32_T c7_i87;
  int32_T c7_i88;
  int32_T c7_i89;
  int32_T c7_i90;
  int32_T c7_i91;
  int32_T c7_i92;
  int32_T c7_i93;
  int32_T c7_i94;
  int32_T c7_i95;
  int32_T c7_i96;
  int32_T c7_i97;
  int32_T c7_i98;
  int32_T c7_i99;
  int32_T c7_i_q0;
  int32_T c7_i_q1;
  int32_T c7_i_qY;
  int32_T c7_i_x;
  int32_T c7_j_q0;
  int32_T c7_j_q1;
  int32_T c7_j_qY;
  int32_T c7_j_x;
  int32_T c7_k_q0;
  int32_T c7_k_q1;
  int32_T c7_k_qY;
  int32_T c7_l_q0;
  int32_T c7_l_q1;
  int32_T c7_l_qY;
  int32_T c7_o_x;
  int32_T c7_q0;
  int32_T c7_q1;
  int32_T c7_qY;
  int32_T c7_r;
  int32_T c7_stripeFirstLabel;
  int32_T c7_thread;
  boolean_T c7_b;
  boolean_T c7_b_b;
  boolean_T c7_c_b;
  boolean_T c7_d_b;
  boolean_T c7_guard1;
  boolean_T c7_guard2;
  boolean_T c7_guard3;
  boolean_T c7_guard4;
  boolean_T c7_guard5;
  boolean_T c7_guard6;
  boolean_T c7_overflow;
  c7_st.prev = c7_sp;
  c7_st.tls = c7_sp->tls;
  c7_b_st.prev = &c7_st;
  c7_b_st.tls = c7_st.tls;
  c7_c_st.prev = &c7_b_st;
  c7_c_st.tls = c7_b_st.tls;
  c7_st.site = &c7_yb_emlrtRSI;
  chartInstance->c7_P[0] = 0.0;
  for (c7_thread = 0; c7_thread < 8; c7_thread++) {
    c7_b_thread = (real_T)c7_thread;
    c7_b_c = c7_b_thread * 20.0 + 1.0;
    c7_b_varargin_1 = (c7_b_thread + 1.0) * 20.0 + 1.0;
    c7_x = c7_b_varargin_1;
    c7_b_x = c7_x;
    c7_c_x = c7_b_x;
    c7_b_a = c7_c_x;
    c7_d_x = c7_b_a;
    c7_e_x = c7_d_x;
    c7_minval = muDoubleScalarMin(c7_e_x, 161.0);
    if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
      emlrtIntegerCheckR2012b(c7_b_c, &c7_dd_emlrtDCI, &c7_st);
    }

    c7_i2 = (int32_T)c7_b_c;
    if ((c7_i2 < 1) || (c7_i2 > 168)) {
      emlrtDynamicBoundsCheckR2012b(c7_i2, 1, 168, &c7_bd_emlrtBCI, &c7_st);
    }

    c7_d2 = muDoubleScalarRound(c7_minval);
    if (c7_d2 < 2.147483648E+9) {
      if (c7_d2 >= -2.147483648E+9) {
        c7_i5 = (int32_T)c7_d2;
      } else {
        c7_i5 = MIN_int32_T;
      }
    } else if (c7_d2 >= 2.147483648E+9) {
      c7_i5 = MAX_int32_T;
    } else {
      c7_i5 = 0;
    }

    c7_chunksSizeAndLabels[c7_i2 - 1] = c7_i5;
    c7_m_x = c7_b_c / 2.0;
    c7_n_x = c7_m_x;
    c7_b_y = c7_n_x;
    c7_b_y = muDoubleScalarFloor(c7_b_y);
    c7_label = c7_b_y * 60.0 + 1.0;
    c7_firstLabel = c7_label;
    c7_startC = c7_b_c;
    c7_d8 = c7_b_thread * 20.0 + 1.0;
    c7_c_varargin_1 = (c7_b_thread + 1.0) * 20.0;
    c7_p_x = c7_c_varargin_1;
    c7_q_x = c7_p_x;
    c7_r_x = c7_q_x;
    c7_e_a = c7_r_x;
    c7_s_x = c7_e_a;
    c7_t_x = c7_s_x;
    c7_d10 = muDoubleScalarMin(c7_t_x, 160.0);
    c7_i15 = (int32_T)(c7_d10 + (1.0 - c7_d8));
    emlrtForLoopVectorCheckR2021a(c7_d8, 1.0, c7_d10, mxDOUBLE_CLASS, c7_i15,
      &c7_g_emlrtRTEI, &c7_st);
    for (c7_d_c = 0; c7_d_c < c7_i15; c7_d_c++) {
      c7_b_c = c7_d8 + (real_T)c7_d_c;
      for (c7_d_r = 0; c7_d_r < 120; c7_d_r++) {
        c7_b_r = 1.0 + (real_T)c7_d_r;
        if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
          emlrtIntegerCheckR2012b(c7_b_r, &c7_xe_emlrtDCI, &c7_st);
        }

        c7_i21 = (int32_T)c7_b_r;
        if ((c7_i21 < 1) || (c7_i21 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c7_i21, 1, 120, &c7_ve_emlrtBCI, &c7_st);
        }

        if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
          emlrtIntegerCheckR2012b(c7_b_c, &c7_ye_emlrtDCI, &c7_st);
        }

        c7_i24 = (int32_T)c7_b_c;
        if ((c7_i24 < 1) || (c7_i24 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c7_i24, 1, 160, &c7_we_emlrtBCI, &c7_st);
        }

        if (c7_varargin_1[(c7_i21 + 120 * (c7_i24 - 1)) - 1]) {
          c7_guard1 = false;
          c7_guard2 = false;
          c7_guard3 = false;
          c7_guard4 = false;
          c7_guard5 = false;
          c7_guard6 = false;
          if (c7_b_c > c7_startC) {
            if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
              emlrtIntegerCheckR2012b(c7_b_r, &c7_af_emlrtDCI, &c7_st);
            }

            c7_i32 = (int32_T)c7_b_r;
            if ((c7_i32 < 1) || (c7_i32 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c7_i32, 1, 120, &c7_xe_emlrtBCI,
                &c7_st);
            }

            c7_d25 = c7_b_c - 1.0;
            if (c7_d25 != (real_T)(int32_T)muDoubleScalarFloor(c7_d25)) {
              emlrtIntegerCheckR2012b(c7_d25, &c7_bf_emlrtDCI, &c7_st);
            }

            c7_i37 = (int32_T)c7_d25;
            if ((c7_i37 < 1) || (c7_i37 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c7_i37, 1, 160, &c7_ye_emlrtBCI,
                &c7_st);
            }

            if (c7_varargin_1[(c7_i32 + 120 * (c7_i37 - 1)) - 1]) {
              if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
                emlrtIntegerCheckR2012b(c7_b_r, &c7_cf_emlrtDCI, &c7_st);
              }

              c7_i48 = (int32_T)c7_b_r;
              if ((c7_i48 < 1) || (c7_i48 > 120)) {
                emlrtDynamicBoundsCheckR2012b(c7_i48, 1, 120, &c7_af_emlrtBCI,
                  &c7_st);
              }

              c7_d38 = c7_b_c - 1.0;
              if (c7_d38 != (real_T)(int32_T)muDoubleScalarFloor(c7_d38)) {
                emlrtIntegerCheckR2012b(c7_d38, &c7_df_emlrtDCI, &c7_st);
              }

              c7_i57 = (int32_T)c7_d38;
              if ((c7_i57 < 1) || (c7_i57 > 160)) {
                emlrtDynamicBoundsCheckR2012b(c7_i57, 1, 160, &c7_bf_emlrtBCI,
                  &c7_st);
              }

              if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
                emlrtIntegerCheckR2012b(c7_b_r, &c7_ef_emlrtDCI, &c7_st);
              }

              c7_i64 = (int32_T)c7_b_r;
              if ((c7_i64 < 1) || (c7_i64 > 120)) {
                emlrtDynamicBoundsCheckR2012b(c7_i64, 1, 120, &c7_cf_emlrtBCI,
                  &c7_st);
              }

              if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                emlrtIntegerCheckR2012b(c7_b_c, &c7_ff_emlrtDCI, &c7_st);
              }

              c7_i74 = (int32_T)c7_b_c;
              if ((c7_i74 < 1) || (c7_i74 > 160)) {
                emlrtDynamicBoundsCheckR2012b(c7_i74, 1, 160, &c7_df_emlrtBCI,
                  &c7_st);
              }

              c7_b_L[(c7_i64 + 120 * (c7_i74 - 1)) - 1] = c7_b_L[(c7_i48 + 120 *
                (c7_i57 - 1)) - 1];
            } else {
              c7_guard6 = true;
            }
          } else {
            c7_guard6 = true;
          }

          if (c7_guard6) {
            if ((c7_b_r < 120.0) && (c7_b_c > c7_startC)) {
              c7_d24 = c7_b_r + 1.0;
              if (c7_d24 != (real_T)(int32_T)muDoubleScalarFloor(c7_d24)) {
                emlrtIntegerCheckR2012b(c7_d24, &c7_hf_emlrtDCI, &c7_st);
              }

              c7_i35 = (int32_T)c7_d24;
              if ((c7_i35 < 1) || (c7_i35 > 120)) {
                emlrtDynamicBoundsCheckR2012b(c7_i35, 1, 120, &c7_ff_emlrtBCI,
                  &c7_st);
              }

              c7_d31 = c7_b_c - 1.0;
              if (c7_d31 != (real_T)(int32_T)muDoubleScalarFloor(c7_d31)) {
                emlrtIntegerCheckR2012b(c7_d31, &c7_if_emlrtDCI, &c7_st);
              }

              c7_i45 = (int32_T)c7_d31;
              if ((c7_i45 < 1) || (c7_i45 > 160)) {
                emlrtDynamicBoundsCheckR2012b(c7_i45, 1, 160, &c7_gf_emlrtBCI,
                  &c7_st);
              }

              if (c7_varargin_1[(c7_i35 + 120 * (c7_i45 - 1)) - 1]) {
                if ((c7_b_c > c7_startC) && (c7_b_r > 1.0)) {
                  c7_d39 = c7_b_r - 1.0;
                  if (c7_d39 != (real_T)(int32_T)muDoubleScalarFloor(c7_d39)) {
                    emlrtIntegerCheckR2012b(c7_d39, &c7_mf_emlrtDCI, &c7_st);
                  }

                  c7_i58 = (int32_T)c7_d39;
                  if ((c7_i58 < 1) || (c7_i58 > 120)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i58, 1, 120,
                      &c7_kf_emlrtBCI, &c7_st);
                  }

                  c7_d51 = c7_b_c - 1.0;
                  if (c7_d51 != (real_T)(int32_T)muDoubleScalarFloor(c7_d51)) {
                    emlrtIntegerCheckR2012b(c7_d51, &c7_nf_emlrtDCI, &c7_st);
                  }

                  c7_i68 = (int32_T)c7_d51;
                  if ((c7_i68 < 1) || (c7_i68 > 160)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i68, 1, 160,
                      &c7_lf_emlrtBCI, &c7_st);
                  }

                  if (c7_varargin_1[(c7_i58 + 120 * (c7_i68 - 1)) - 1]) {
                    c7_d57 = c7_b_r - 1.0;
                    if (c7_d57 != (real_T)(int32_T)muDoubleScalarFloor(c7_d57))
                    {
                      emlrtIntegerCheckR2012b(c7_d57, &c7_sf_emlrtDCI, &c7_st);
                    }

                    c7_i80 = (int32_T)c7_d57;
                    if ((c7_i80 < 1) || (c7_i80 > 120)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i80, 1, 120,
                        &c7_qf_emlrtBCI, &c7_st);
                    }

                    c7_d60 = c7_b_c - 1.0;
                    if (c7_d60 != (real_T)(int32_T)muDoubleScalarFloor(c7_d60))
                    {
                      emlrtIntegerCheckR2012b(c7_d60, &c7_tf_emlrtDCI, &c7_st);
                    }

                    c7_i87 = (int32_T)c7_d60;
                    if ((c7_i87 < 1) || (c7_i87 > 160)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i87, 1, 160,
                        &c7_rf_emlrtBCI, &c7_st);
                    }

                    if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r))
                    {
                      emlrtIntegerCheckR2012b(c7_b_r, &c7_uf_emlrtDCI, &c7_st);
                    }

                    c7_i94 = (int32_T)c7_b_r;
                    if ((c7_i94 < 1) || (c7_i94 > 120)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i94, 1, 120,
                        &c7_sf_emlrtBCI, &c7_st);
                    }

                    if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c))
                    {
                      emlrtIntegerCheckR2012b(c7_b_c, &c7_vf_emlrtDCI, &c7_st);
                    }

                    c7_i99 = (int32_T)c7_b_c;
                    if ((c7_i99 < 1) || (c7_i99 > 160)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i99, 1, 160,
                        &c7_tf_emlrtBCI, &c7_st);
                    }

                    c7_b_L[(c7_i94 + 120 * (c7_i99 - 1)) - 1] = c7_b_L[(c7_i80 +
                      120 * (c7_i87 - 1)) - 1];
                    do {
                      c7_exitg1 = 0;
                      if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r))
                      {
                        emlrtIntegerCheckR2012b(c7_b_r, &c7_og_emlrtDCI, &c7_st);
                      }

                      c7_i110 = (int32_T)c7_b_r;
                      if ((c7_i110 < 1) || (c7_i110 > 120)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i110, 1, 120,
                          &c7_mg_emlrtBCI, &c7_st);
                      }

                      if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c))
                      {
                        emlrtIntegerCheckR2012b(c7_b_c, &c7_pg_emlrtDCI, &c7_st);
                      }

                      c7_i119 = (int32_T)c7_b_c;
                      if ((c7_i119 < 1) || (c7_i119 > 160)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i119, 1, 160,
                          &c7_ng_emlrtBCI, &c7_st);
                      }

                      c7_d90 = c7_b_L[(c7_i110 + 120 * (c7_i119 - 1)) - 1] + 1.0;
                      if (c7_d90 != (real_T)(int32_T)muDoubleScalarFloor(c7_d90))
                      {
                        emlrtIntegerCheckR2012b(c7_d90, &c7_ng_emlrtDCI, &c7_st);
                      }

                      c7_i125 = (int32_T)c7_d90;
                      if ((c7_i125 < 1) || (c7_i125 > 9601)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i125, 1, 9601,
                          &c7_lg_emlrtBCI, &c7_st);
                      }

                      if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r))
                      {
                        emlrtIntegerCheckR2012b(c7_b_r, &c7_qg_emlrtDCI, &c7_st);
                      }

                      c7_i131 = (int32_T)c7_b_r;
                      if ((c7_i131 < 1) || (c7_i131 > 120)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i131, 1, 120,
                          &c7_og_emlrtBCI, &c7_st);
                      }

                      if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c))
                      {
                        emlrtIntegerCheckR2012b(c7_b_c, &c7_rg_emlrtDCI, &c7_st);
                      }

                      c7_i135 = (int32_T)c7_b_c;
                      if ((c7_i135 < 1) || (c7_i135 > 160)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i135, 1, 160,
                          &c7_pg_emlrtBCI, &c7_st);
                      }

                      if (chartInstance->c7_P[c7_i125 - 1] < c7_b_L[(c7_i131 +
                           120 * (c7_i135 - 1)) - 1]) {
                        if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_b_r)) {
                          emlrtIntegerCheckR2012b(c7_b_r, &c7_xg_emlrtDCI,
                            &c7_st);
                        }

                        c7_i138 = (int32_T)c7_b_r;
                        if ((c7_i138 < 1) || (c7_i138 > 120)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i138, 1, 120,
                            &c7_vg_emlrtBCI, &c7_st);
                        }

                        if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_b_c)) {
                          emlrtIntegerCheckR2012b(c7_b_c, &c7_yg_emlrtDCI,
                            &c7_st);
                        }

                        c7_i142 = (int32_T)c7_b_c;
                        if ((c7_i142 < 1) || (c7_i142 > 160)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i142, 1, 160,
                            &c7_wg_emlrtBCI, &c7_st);
                        }

                        c7_d102 = c7_b_L[(c7_i138 + 120 * (c7_i142 - 1)) - 1] +
                          1.0;
                        if (c7_d102 != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_d102)) {
                          emlrtIntegerCheckR2012b(c7_d102, &c7_wg_emlrtDCI,
                            &c7_st);
                        }

                        c7_i146 = (int32_T)c7_d102;
                        if ((c7_i146 < 1) || (c7_i146 > 9601)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i146, 1, 9601,
                            &c7_ug_emlrtBCI, &c7_st);
                        }

                        if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_b_r)) {
                          emlrtIntegerCheckR2012b(c7_b_r, &c7_ah_emlrtDCI,
                            &c7_st);
                        }

                        c7_i149 = (int32_T)c7_b_r;
                        if ((c7_i149 < 1) || (c7_i149 > 120)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i149, 1, 120,
                            &c7_xg_emlrtBCI, &c7_st);
                        }

                        if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_b_c)) {
                          emlrtIntegerCheckR2012b(c7_b_c, &c7_bh_emlrtDCI,
                            &c7_st);
                        }

                        c7_i151 = (int32_T)c7_b_c;
                        if ((c7_i151 < 1) || (c7_i151 > 160)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i151, 1, 160,
                            &c7_yg_emlrtBCI, &c7_st);
                        }

                        c7_b_L[(c7_i149 + 120 * (c7_i151 - 1)) - 1] =
                          chartInstance->c7_P[c7_i146 - 1];
                      } else {
                        c7_exitg1 = 1;
                      }
                    } while (c7_exitg1 == 0);

                    c7_d99 = c7_b_r - 1.0;
                    if (c7_d99 != (real_T)(int32_T)muDoubleScalarFloor(c7_d99))
                    {
                      emlrtIntegerCheckR2012b(c7_d99, &c7_sg_emlrtDCI, &c7_st);
                    }

                    c7_i141 = (int32_T)c7_d99;
                    if ((c7_i141 < 1) || (c7_i141 > 120)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i141, 1, 120,
                        &c7_qg_emlrtBCI, &c7_st);
                    }

                    c7_d101 = c7_b_c - 1.0;
                    if (c7_d101 != (real_T)(int32_T)muDoubleScalarFloor(c7_d101))
                    {
                      emlrtIntegerCheckR2012b(c7_d101, &c7_tg_emlrtDCI, &c7_st);
                    }

                    c7_i145 = (int32_T)c7_d101;
                    if ((c7_i145 < 1) || (c7_i145 > 160)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i145, 1, 160,
                        &c7_rg_emlrtBCI, &c7_st);
                    }

                    c7_d104 = c7_b_r + 1.0;
                    if (c7_d104 != (real_T)(int32_T)muDoubleScalarFloor(c7_d104))
                    {
                      emlrtIntegerCheckR2012b(c7_d104, &c7_ug_emlrtDCI, &c7_st);
                    }

                    c7_i148 = (int32_T)c7_d104;
                    if ((c7_i148 < 1) || (c7_i148 > 120)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i148, 1, 120,
                        &c7_sg_emlrtBCI, &c7_st);
                    }

                    c7_d107 = c7_b_c - 1.0;
                    if (c7_d107 != (real_T)(int32_T)muDoubleScalarFloor(c7_d107))
                    {
                      emlrtIntegerCheckR2012b(c7_d107, &c7_vg_emlrtDCI, &c7_st);
                    }

                    c7_i153 = (int32_T)c7_d107;
                    if ((c7_i153 < 1) || (c7_i153 > 160)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i153, 1, 160,
                        &c7_tg_emlrtBCI, &c7_st);
                    }

                    if (c7_b_L[(c7_i141 + 120 * (c7_i145 - 1)) - 1] != c7_b_L
                        [(c7_i148 + 120 * (c7_i153 - 1)) - 1]) {
                      c7_d108 = c7_b_r + 1.0;
                      if (c7_d108 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d108)) {
                        emlrtIntegerCheckR2012b(c7_d108, &c7_hh_emlrtDCI, &c7_st);
                      }

                      c7_i155 = (int32_T)c7_d108;
                      if ((c7_i155 < 1) || (c7_i155 > 120)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i155, 1, 120,
                          &c7_fh_emlrtBCI, &c7_st);
                      }

                      c7_d112 = c7_b_c - 1.0;
                      if (c7_d112 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d112)) {
                        emlrtIntegerCheckR2012b(c7_d112, &c7_ih_emlrtDCI, &c7_st);
                      }

                      c7_i159 = (int32_T)c7_d112;
                      if ((c7_i159 < 1) || (c7_i159 > 160)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i159, 1, 160,
                          &c7_gh_emlrtBCI, &c7_st);
                      }

                      c7_d_rootj = c7_b_L[(c7_i155 + 120 * (c7_i159 - 1)) - 1];
                      do {
                        c7_exitg1 = 0;
                        c7_d117 = c7_d_rootj + 1.0;
                        if (c7_d117 != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_d117)) {
                          emlrtIntegerCheckR2012b(c7_d117, &c7_ai_emlrtDCI,
                            &c7_st);
                        }

                        c7_i166 = (int32_T)c7_d117;
                        if ((c7_i166 < 1) || (c7_i166 > 9601)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i166, 1, 9601,
                            &c7_xh_emlrtBCI, &c7_st);
                        }

                        if (chartInstance->c7_P[c7_i166 - 1] < c7_d_rootj) {
                          c7_d120 = c7_d_rootj + 1.0;
                          if (c7_d120 != (real_T)(int32_T)muDoubleScalarFloor
                              (c7_d120)) {
                            emlrtIntegerCheckR2012b(c7_d120, &c7_li_emlrtDCI,
                              &c7_st);
                          }

                          c7_i172 = (int32_T)c7_d120;
                          if ((c7_i172 < 1) || (c7_i172 > 9601)) {
                            emlrtDynamicBoundsCheckR2012b(c7_i172, 1, 9601,
                              &c7_ji_emlrtBCI, &c7_st);
                          }

                          c7_d_rootj = chartInstance->c7_P[c7_i172 - 1];
                        } else {
                          c7_exitg1 = 1;
                        }
                      } while (c7_exitg1 == 0);

                      if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r))
                      {
                        emlrtIntegerCheckR2012b(c7_b_r, &c7_ji_emlrtDCI, &c7_st);
                      }

                      c7_i174 = (int32_T)c7_b_r;
                      if ((c7_i174 < 1) || (c7_i174 > 120)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i174, 1, 120,
                          &c7_hi_emlrtBCI, &c7_st);
                      }

                      if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c))
                      {
                        emlrtIntegerCheckR2012b(c7_b_c, &c7_ki_emlrtDCI, &c7_st);
                      }

                      c7_i179 = (int32_T)c7_b_c;
                      if ((c7_i179 < 1) || (c7_i179 > 160)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i179, 1, 160,
                          &c7_ii_emlrtBCI, &c7_st);
                      }

                      if (c7_b_L[(c7_i174 + 120 * (c7_i179 - 1)) - 1] >
                          c7_d_rootj) {
                        if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_b_r)) {
                          emlrtIntegerCheckR2012b(c7_b_r, &c7_lc_emlrtDCI,
                            &c7_st);
                        }

                        c7_i184 = (int32_T)c7_b_r;
                        if ((c7_i184 < 1) || (c7_i184 > 120)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i184, 1, 120,
                            &c7_jc_emlrtBCI, &c7_st);
                        }

                        if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_b_c)) {
                          emlrtIntegerCheckR2012b(c7_b_c, &c7_mc_emlrtDCI,
                            &c7_st);
                        }

                        c7_i191 = (int32_T)c7_b_c;
                        if ((c7_i191 < 1) || (c7_i191 > 160)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i191, 1, 160,
                            &c7_kc_emlrtBCI, &c7_st);
                        }

                        c7_b_L[(c7_i184 + 120 * (c7_i191 - 1)) - 1] = c7_d_rootj;
                      }

                      do {
                        c7_exitg1 = 0;
                        c7_d128 = c7_b_r + 1.0;
                        if (c7_d128 != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_d128)) {
                          emlrtIntegerCheckR2012b(c7_d128, &c7_pj_emlrtDCI,
                            &c7_st);
                        }

                        c7_i189 = (int32_T)c7_d128;
                        if ((c7_i189 < 1) || (c7_i189 > 120)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i189, 1, 120,
                            &c7_nj_emlrtBCI, &c7_st);
                        }

                        c7_d132 = c7_b_c - 1.0;
                        if (c7_d132 != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_d132)) {
                          emlrtIntegerCheckR2012b(c7_d132, &c7_qj_emlrtDCI,
                            &c7_st);
                        }

                        c7_i196 = (int32_T)c7_d132;
                        if ((c7_i196 < 1) || (c7_i196 > 160)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i196, 1, 160,
                            &c7_oj_emlrtBCI, &c7_st);
                        }

                        c7_d137 = c7_b_L[(c7_i189 + 120 * (c7_i196 - 1)) - 1] +
                          1.0;
                        if (c7_d137 != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_d137)) {
                          emlrtIntegerCheckR2012b(c7_d137, &c7_oj_emlrtDCI,
                            &c7_st);
                        }

                        c7_i201 = (int32_T)c7_d137;
                        if ((c7_i201 < 1) || (c7_i201 > 9601)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i201, 1, 9601,
                            &c7_mj_emlrtBCI, &c7_st);
                        }

                        c7_d140 = c7_b_r + 1.0;
                        if (c7_d140 != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_d140)) {
                          emlrtIntegerCheckR2012b(c7_d140, &c7_rj_emlrtDCI,
                            &c7_st);
                        }

                        c7_i207 = (int32_T)c7_d140;
                        if ((c7_i207 < 1) || (c7_i207 > 120)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i207, 1, 120,
                            &c7_pj_emlrtBCI, &c7_st);
                        }

                        c7_d145 = c7_b_c - 1.0;
                        if (c7_d145 != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_d145)) {
                          emlrtIntegerCheckR2012b(c7_d145, &c7_sj_emlrtDCI,
                            &c7_st);
                        }

                        c7_i213 = (int32_T)c7_d145;
                        if ((c7_i213 < 1) || (c7_i213 > 160)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i213, 1, 160,
                            &c7_qj_emlrtBCI, &c7_st);
                        }

                        if (chartInstance->c7_P[c7_i201 - 1] < c7_b_L[(c7_i207 +
                             120 * (c7_i213 - 1)) - 1]) {
                          c7_d150 = c7_b_r + 1.0;
                          if (c7_d150 != (real_T)(int32_T)muDoubleScalarFloor
                              (c7_d150)) {
                            emlrtIntegerCheckR2012b(c7_d150, &c7_ak_emlrtDCI,
                              &c7_st);
                          }

                          c7_i220 = (int32_T)c7_d150;
                          if ((c7_i220 < 1) || (c7_i220 > 120)) {
                            emlrtDynamicBoundsCheckR2012b(c7_i220, 1, 120,
                              &c7_xj_emlrtBCI, &c7_st);
                          }

                          c7_d153 = c7_b_c - 1.0;
                          if (c7_d153 != (real_T)(int32_T)muDoubleScalarFloor
                              (c7_d153)) {
                            emlrtIntegerCheckR2012b(c7_d153, &c7_bk_emlrtDCI,
                              &c7_st);
                          }

                          c7_i225 = (int32_T)c7_d153;
                          if ((c7_i225 < 1) || (c7_i225 > 160)) {
                            emlrtDynamicBoundsCheckR2012b(c7_i225, 1, 160,
                              &c7_yj_emlrtBCI, &c7_st);
                          }

                          c7_d156 = c7_b_L[(c7_i220 + 120 * (c7_i225 - 1)) - 1]
                            + 1.0;
                          if (c7_d156 != (real_T)(int32_T)muDoubleScalarFloor
                              (c7_d156)) {
                            emlrtIntegerCheckR2012b(c7_d156, &c7_yj_emlrtDCI,
                              &c7_st);
                          }

                          c7_i230 = (int32_T)c7_d156;
                          if ((c7_i230 < 1) || (c7_i230 > 9601)) {
                            emlrtDynamicBoundsCheckR2012b(c7_i230, 1, 9601,
                              &c7_wj_emlrtBCI, &c7_st);
                          }

                          c7_j_j = chartInstance->c7_P[c7_i230 - 1];
                          if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor
                              (c7_b_r)) {
                            emlrtIntegerCheckR2012b(c7_b_r, &c7_hk_emlrtDCI,
                              &c7_st);
                          }

                          c7_i234 = (int32_T)c7_b_r;
                          if ((c7_i234 < 1) || (c7_i234 > 120)) {
                            emlrtDynamicBoundsCheckR2012b(c7_i234, 1, 120,
                              &c7_fk_emlrtBCI, &c7_st);
                          }

                          if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor
                              (c7_b_c)) {
                            emlrtIntegerCheckR2012b(c7_b_c, &c7_ik_emlrtDCI,
                              &c7_st);
                          }

                          c7_i237 = (int32_T)c7_b_c;
                          if ((c7_i237 < 1) || (c7_i237 > 160)) {
                            emlrtDynamicBoundsCheckR2012b(c7_i237, 1, 160,
                              &c7_gk_emlrtBCI, &c7_st);
                          }

                          c7_d164 = c7_b_r + 1.0;
                          if (c7_d164 != (real_T)(int32_T)muDoubleScalarFloor
                              (c7_d164)) {
                            emlrtIntegerCheckR2012b(c7_d164, &c7_kk_emlrtDCI,
                              &c7_st);
                          }

                          c7_i240 = (int32_T)c7_d164;
                          if ((c7_i240 < 1) || (c7_i240 > 120)) {
                            emlrtDynamicBoundsCheckR2012b(c7_i240, 1, 120,
                              &c7_ik_emlrtBCI, &c7_st);
                          }

                          c7_d166 = c7_b_c - 1.0;
                          if (c7_d166 != (real_T)(int32_T)muDoubleScalarFloor
                              (c7_d166)) {
                            emlrtIntegerCheckR2012b(c7_d166, &c7_lk_emlrtDCI,
                              &c7_st);
                          }

                          c7_i242 = (int32_T)c7_d166;
                          if ((c7_i242 < 1) || (c7_i242 > 160)) {
                            emlrtDynamicBoundsCheckR2012b(c7_i242, 1, 160,
                              &c7_jk_emlrtBCI, &c7_st);
                          }

                          c7_d168 = c7_b_L[(c7_i240 + 120 * (c7_i242 - 1)) - 1]
                            + 1.0;
                          if (c7_d168 != (real_T)(int32_T)muDoubleScalarFloor
                              (c7_d168)) {
                            emlrtIntegerCheckR2012b(c7_d168, &c7_jk_emlrtDCI,
                              &c7_st);
                          }

                          c7_i244 = (int32_T)c7_d168;
                          if ((c7_i244 < 1) || (c7_i244 > 9601)) {
                            emlrtDynamicBoundsCheckR2012b(c7_i244, 1, 9601,
                              &c7_hk_emlrtBCI, &c7_st);
                          }

                          chartInstance->c7_P[c7_i244 - 1] = c7_b_L[(c7_i234 +
                            120 * (c7_i237 - 1)) - 1];
                          c7_d169 = c7_b_r + 1.0;
                          if (c7_d169 != (real_T)(int32_T)muDoubleScalarFloor
                              (c7_d169)) {
                            emlrtIntegerCheckR2012b(c7_d169, &c7_nc_emlrtDCI,
                              &c7_st);
                          }

                          c7_i245 = (int32_T)c7_d169;
                          if ((c7_i245 < 1) || (c7_i245 > 120)) {
                            emlrtDynamicBoundsCheckR2012b(c7_i245, 1, 120,
                              &c7_lc_emlrtBCI, &c7_st);
                          }

                          c7_d170 = c7_b_c - 1.0;
                          if (c7_d170 != (real_T)(int32_T)muDoubleScalarFloor
                              (c7_d170)) {
                            emlrtIntegerCheckR2012b(c7_d170, &c7_oc_emlrtDCI,
                              &c7_st);
                          }

                          c7_i246 = (int32_T)c7_d170;
                          if ((c7_i246 < 1) || (c7_i246 > 160)) {
                            emlrtDynamicBoundsCheckR2012b(c7_i246, 1, 160,
                              &c7_mc_emlrtBCI, &c7_st);
                          }

                          c7_b_L[(c7_i245 + 120 * (c7_i246 - 1)) - 1] = c7_j_j;
                        } else {
                          c7_exitg1 = 1;
                        }
                      } while (c7_exitg1 == 0);

                      if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r))
                      {
                        emlrtIntegerCheckR2012b(c7_b_r, &c7_tj_emlrtDCI, &c7_st);
                      }

                      c7_i221 = (int32_T)c7_b_r;
                      if ((c7_i221 < 1) || (c7_i221 > 120)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i221, 1, 120,
                          &c7_rj_emlrtBCI, &c7_st);
                      }

                      if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c))
                      {
                        emlrtIntegerCheckR2012b(c7_b_c, &c7_uj_emlrtDCI, &c7_st);
                      }

                      c7_i226 = (int32_T)c7_b_c;
                      if ((c7_i226 < 1) || (c7_i226 > 160)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i226, 1, 160,
                          &c7_sj_emlrtBCI, &c7_st);
                      }

                      c7_d157 = c7_b_r + 1.0;
                      if (c7_d157 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d157)) {
                        emlrtIntegerCheckR2012b(c7_d157, &c7_wj_emlrtDCI, &c7_st);
                      }

                      c7_i231 = (int32_T)c7_d157;
                      if ((c7_i231 < 1) || (c7_i231 > 120)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i231, 1, 120,
                          &c7_uj_emlrtBCI, &c7_st);
                      }

                      c7_d160 = c7_b_c - 1.0;
                      if (c7_d160 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d160)) {
                        emlrtIntegerCheckR2012b(c7_d160, &c7_xj_emlrtDCI, &c7_st);
                      }

                      c7_i235 = (int32_T)c7_d160;
                      if ((c7_i235 < 1) || (c7_i235 > 160)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i235, 1, 160,
                          &c7_vj_emlrtBCI, &c7_st);
                      }

                      c7_d162 = c7_b_L[(c7_i231 + 120 * (c7_i235 - 1)) - 1] +
                        1.0;
                      if (c7_d162 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d162)) {
                        emlrtIntegerCheckR2012b(c7_d162, &c7_vj_emlrtDCI, &c7_st);
                      }

                      c7_i238 = (int32_T)c7_d162;
                      if ((c7_i238 < 1) || (c7_i238 > 9601)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i238, 1, 9601,
                          &c7_tj_emlrtBCI, &c7_st);
                      }

                      chartInstance->c7_P[c7_i238 - 1] = c7_b_L[(c7_i221 + 120 *
                        (c7_i226 - 1)) - 1];
                    }

                    do {
                      c7_exitg1 = 0;
                      c7_d111 = c7_b_r - 1.0;
                      if (c7_d111 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d111)) {
                        emlrtIntegerCheckR2012b(c7_d111, &c7_vh_emlrtDCI, &c7_st);
                      }

                      c7_i158 = (int32_T)c7_d111;
                      if ((c7_i158 < 1) || (c7_i158 > 120)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i158, 1, 120,
                          &c7_th_emlrtBCI, &c7_st);
                      }

                      c7_d115 = c7_b_c - 1.0;
                      if (c7_d115 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d115)) {
                        emlrtIntegerCheckR2012b(c7_d115, &c7_wh_emlrtDCI, &c7_st);
                      }

                      c7_i162 = (int32_T)c7_d115;
                      if ((c7_i162 < 1) || (c7_i162 > 160)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i162, 1, 160,
                          &c7_uh_emlrtBCI, &c7_st);
                      }

                      c7_d116 = c7_b_L[(c7_i158 + 120 * (c7_i162 - 1)) - 1] +
                        1.0;
                      if (c7_d116 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d116)) {
                        emlrtIntegerCheckR2012b(c7_d116, &c7_uh_emlrtDCI, &c7_st);
                      }

                      c7_i165 = (int32_T)c7_d116;
                      if ((c7_i165 < 1) || (c7_i165 > 9601)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i165, 1, 9601,
                          &c7_sh_emlrtBCI, &c7_st);
                      }

                      c7_d119 = c7_b_r - 1.0;
                      if (c7_d119 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d119)) {
                        emlrtIntegerCheckR2012b(c7_d119, &c7_xh_emlrtDCI, &c7_st);
                      }

                      c7_i170 = (int32_T)c7_d119;
                      if ((c7_i170 < 1) || (c7_i170 > 120)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i170, 1, 120,
                          &c7_vh_emlrtBCI, &c7_st);
                      }

                      c7_d122 = c7_b_c - 1.0;
                      if (c7_d122 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d122)) {
                        emlrtIntegerCheckR2012b(c7_d122, &c7_yh_emlrtDCI, &c7_st);
                      }

                      c7_i178 = (int32_T)c7_d122;
                      if ((c7_i178 < 1) || (c7_i178 > 160)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i178, 1, 160,
                          &c7_wh_emlrtBCI, &c7_st);
                      }

                      if (chartInstance->c7_P[c7_i165 - 1] < c7_b_L[(c7_i170 +
                           120 * (c7_i178 - 1)) - 1]) {
                        c7_d126 = c7_b_r - 1.0;
                        if (c7_d126 != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_d126)) {
                          emlrtIntegerCheckR2012b(c7_d126, &c7_hi_emlrtDCI,
                            &c7_st);
                        }

                        c7_i183 = (int32_T)c7_d126;
                        if ((c7_i183 < 1) || (c7_i183 > 120)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i183, 1, 120,
                            &c7_fi_emlrtBCI, &c7_st);
                        }

                        c7_d129 = c7_b_c - 1.0;
                        if (c7_d129 != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_d129)) {
                          emlrtIntegerCheckR2012b(c7_d129, &c7_ii_emlrtDCI,
                            &c7_st);
                        }

                        c7_i190 = (int32_T)c7_d129;
                        if ((c7_i190 < 1) || (c7_i190 > 160)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i190, 1, 160,
                            &c7_gi_emlrtBCI, &c7_st);
                        }

                        c7_d133 = c7_b_L[(c7_i183 + 120 * (c7_i190 - 1)) - 1] +
                          1.0;
                        if (c7_d133 != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_d133)) {
                          emlrtIntegerCheckR2012b(c7_d133, &c7_gi_emlrtDCI,
                            &c7_st);
                        }

                        c7_i197 = (int32_T)c7_d133;
                        if ((c7_i197 < 1) || (c7_i197 > 9601)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i197, 1, 9601,
                            &c7_ei_emlrtBCI, &c7_st);
                        }

                        c7_j_j = chartInstance->c7_P[c7_i197 - 1];
                        if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_b_r)) {
                          emlrtIntegerCheckR2012b(c7_b_r, &c7_si_emlrtDCI,
                            &c7_st);
                        }

                        c7_i203 = (int32_T)c7_b_r;
                        if ((c7_i203 < 1) || (c7_i203 > 120)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i203, 1, 120,
                            &c7_qi_emlrtBCI, &c7_st);
                        }

                        if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_b_c)) {
                          emlrtIntegerCheckR2012b(c7_b_c, &c7_ti_emlrtDCI,
                            &c7_st);
                        }

                        c7_i206 = (int32_T)c7_b_c;
                        if ((c7_i206 < 1) || (c7_i206 > 160)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i206, 1, 160,
                            &c7_ri_emlrtBCI, &c7_st);
                        }

                        c7_d144 = c7_b_r - 1.0;
                        if (c7_d144 != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_d144)) {
                          emlrtIntegerCheckR2012b(c7_d144, &c7_vi_emlrtDCI,
                            &c7_st);
                        }

                        c7_i212 = (int32_T)c7_d144;
                        if ((c7_i212 < 1) || (c7_i212 > 120)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i212, 1, 120,
                            &c7_ti_emlrtBCI, &c7_st);
                        }

                        c7_d148 = c7_b_c - 1.0;
                        if (c7_d148 != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_d148)) {
                          emlrtIntegerCheckR2012b(c7_d148, &c7_wi_emlrtDCI,
                            &c7_st);
                        }

                        c7_i217 = (int32_T)c7_d148;
                        if ((c7_i217 < 1) || (c7_i217 > 160)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i217, 1, 160,
                            &c7_ui_emlrtBCI, &c7_st);
                        }

                        c7_d151 = c7_b_L[(c7_i212 + 120 * (c7_i217 - 1)) - 1] +
                          1.0;
                        if (c7_d151 != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_d151)) {
                          emlrtIntegerCheckR2012b(c7_d151, &c7_ui_emlrtDCI,
                            &c7_st);
                        }

                        c7_i223 = (int32_T)c7_d151;
                        if ((c7_i223 < 1) || (c7_i223 > 9601)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i223, 1, 9601,
                            &c7_si_emlrtBCI, &c7_st);
                        }

                        chartInstance->c7_P[c7_i223 - 1] = c7_b_L[(c7_i203 + 120
                          * (c7_i206 - 1)) - 1];
                        c7_d155 = c7_b_r - 1.0;
                        if (c7_d155 != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_d155)) {
                          emlrtIntegerCheckR2012b(c7_d155, &c7_pc_emlrtDCI,
                            &c7_st);
                        }

                        c7_i229 = (int32_T)c7_d155;
                        if ((c7_i229 < 1) || (c7_i229 > 120)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i229, 1, 120,
                            &c7_nc_emlrtBCI, &c7_st);
                        }

                        c7_d159 = c7_b_c - 1.0;
                        if (c7_d159 != (real_T)(int32_T)muDoubleScalarFloor
                            (c7_d159)) {
                          emlrtIntegerCheckR2012b(c7_d159, &c7_qc_emlrtDCI,
                            &c7_st);
                        }

                        c7_i233 = (int32_T)c7_d159;
                        if ((c7_i233 < 1) || (c7_i233 > 160)) {
                          emlrtDynamicBoundsCheckR2012b(c7_i233, 1, 160,
                            &c7_oc_emlrtBCI, &c7_st);
                        }

                        c7_b_L[(c7_i229 + 120 * (c7_i233 - 1)) - 1] = c7_j_j;
                      } else {
                        c7_exitg1 = 1;
                      }
                    } while (c7_exitg1 == 0);

                    if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r))
                    {
                      emlrtIntegerCheckR2012b(c7_b_r, &c7_bi_emlrtDCI, &c7_st);
                    }

                    c7_i186 = (int32_T)c7_b_r;
                    if ((c7_i186 < 1) || (c7_i186 > 120)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i186, 1, 120,
                        &c7_yh_emlrtBCI, &c7_st);
                    }

                    if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c))
                    {
                      emlrtIntegerCheckR2012b(c7_b_c, &c7_ci_emlrtDCI, &c7_st);
                    }

                    c7_i193 = (int32_T)c7_b_c;
                    if ((c7_i193 < 1) || (c7_i193 > 160)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i193, 1, 160,
                        &c7_ai_emlrtBCI, &c7_st);
                    }

                    c7_d135 = c7_b_r - 1.0;
                    if (c7_d135 != (real_T)(int32_T)muDoubleScalarFloor(c7_d135))
                    {
                      emlrtIntegerCheckR2012b(c7_d135, &c7_ei_emlrtDCI, &c7_st);
                    }

                    c7_i199 = (int32_T)c7_d135;
                    if ((c7_i199 < 1) || (c7_i199 > 120)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i199, 1, 120,
                        &c7_ci_emlrtBCI, &c7_st);
                    }

                    c7_d138 = c7_b_c - 1.0;
                    if (c7_d138 != (real_T)(int32_T)muDoubleScalarFloor(c7_d138))
                    {
                      emlrtIntegerCheckR2012b(c7_d138, &c7_fi_emlrtDCI, &c7_st);
                    }

                    c7_i204 = (int32_T)c7_d138;
                    if ((c7_i204 < 1) || (c7_i204 > 160)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i204, 1, 160,
                        &c7_di_emlrtBCI, &c7_st);
                    }

                    c7_d142 = c7_b_L[(c7_i199 + 120 * (c7_i204 - 1)) - 1] + 1.0;
                    if (c7_d142 != (real_T)(int32_T)muDoubleScalarFloor(c7_d142))
                    {
                      emlrtIntegerCheckR2012b(c7_d142, &c7_di_emlrtDCI, &c7_st);
                    }

                    c7_i210 = (int32_T)c7_d142;
                    if ((c7_i210 < 1) || (c7_i210 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i210, 1, 9601,
                        &c7_bi_emlrtBCI, &c7_st);
                    }

                    chartInstance->c7_P[c7_i210 - 1] = c7_b_L[(c7_i186 + 120 *
                      (c7_i193 - 1)) - 1];
                  } else {
                    c7_guard4 = true;
                  }
                } else {
                  c7_guard4 = true;
                }
              } else {
                c7_guard5 = true;
              }
            } else {
              c7_guard5 = true;
            }
          }

          if (c7_guard5) {
            if ((c7_b_c > c7_startC) && (c7_b_r > 1.0)) {
              c7_d26 = c7_b_r - 1.0;
              if (c7_d26 != (real_T)(int32_T)muDoubleScalarFloor(c7_d26)) {
                emlrtIntegerCheckR2012b(c7_d26, &c7_kf_emlrtDCI, &c7_st);
              }

              c7_i39 = (int32_T)c7_d26;
              if ((c7_i39 < 1) || (c7_i39 > 120)) {
                emlrtDynamicBoundsCheckR2012b(c7_i39, 1, 120, &c7_if_emlrtBCI,
                  &c7_st);
              }

              c7_d35 = c7_b_c - 1.0;
              if (c7_d35 != (real_T)(int32_T)muDoubleScalarFloor(c7_d35)) {
                emlrtIntegerCheckR2012b(c7_d35, &c7_lf_emlrtDCI, &c7_st);
              }

              c7_i51 = (int32_T)c7_d35;
              if ((c7_i51 < 1) || (c7_i51 > 160)) {
                emlrtDynamicBoundsCheckR2012b(c7_i51, 1, 160, &c7_jf_emlrtBCI,
                  &c7_st);
              }

              if (c7_varargin_1[(c7_i39 + 120 * (c7_i51 - 1)) - 1]) {
                c7_d40 = c7_b_r - 1.0;
                if (c7_d40 != (real_T)(int32_T)muDoubleScalarFloor(c7_d40)) {
                  emlrtIntegerCheckR2012b(c7_d40, &c7_of_emlrtDCI, &c7_st);
                }

                c7_i59 = (int32_T)c7_d40;
                if ((c7_i59 < 1) || (c7_i59 > 120)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i59, 1, 120, &c7_mf_emlrtBCI,
                    &c7_st);
                }

                c7_d53 = c7_b_c - 1.0;
                if (c7_d53 != (real_T)(int32_T)muDoubleScalarFloor(c7_d53)) {
                  emlrtIntegerCheckR2012b(c7_d53, &c7_pf_emlrtDCI, &c7_st);
                }

                c7_i71 = (int32_T)c7_d53;
                if ((c7_i71 < 1) || (c7_i71 > 160)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i71, 1, 160, &c7_nf_emlrtBCI,
                    &c7_st);
                }

                if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
                  emlrtIntegerCheckR2012b(c7_b_r, &c7_qf_emlrtDCI, &c7_st);
                }

                c7_i78 = (int32_T)c7_b_r;
                if ((c7_i78 < 1) || (c7_i78 > 120)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i78, 1, 120, &c7_of_emlrtBCI,
                    &c7_st);
                }

                if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                  emlrtIntegerCheckR2012b(c7_b_c, &c7_rf_emlrtDCI, &c7_st);
                }

                c7_i85 = (int32_T)c7_b_c;
                if ((c7_i85 < 1) || (c7_i85 > 160)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i85, 1, 160, &c7_pf_emlrtBCI,
                    &c7_st);
                }

                c7_b_L[(c7_i78 + 120 * (c7_i85 - 1)) - 1] = c7_b_L[(c7_i59 + 120
                  * (c7_i71 - 1)) - 1];
              } else {
                c7_guard3 = true;
              }
            } else {
              c7_guard3 = true;
            }
          }

          if (c7_guard4) {
            if (c7_b_r > 1.0) {
              c7_d27 = c7_b_r - 1.0;
              if (c7_d27 != (real_T)(int32_T)muDoubleScalarFloor(c7_d27)) {
                emlrtIntegerCheckR2012b(c7_d27, &c7_yf_emlrtDCI, &c7_st);
              }

              c7_i41 = (int32_T)c7_d27;
              if ((c7_i41 < 1) || (c7_i41 > 120)) {
                emlrtDynamicBoundsCheckR2012b(c7_i41, 1, 120, &c7_wf_emlrtBCI,
                  &c7_st);
              }

              if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                emlrtIntegerCheckR2012b(c7_b_c, &c7_ag_emlrtDCI, &c7_st);
              }

              c7_i53 = (int32_T)c7_b_c;
              if ((c7_i53 < 1) || (c7_i53 > 160)) {
                emlrtDynamicBoundsCheckR2012b(c7_i53, 1, 160, &c7_xf_emlrtBCI,
                  &c7_st);
              }

              if (c7_varargin_1[(c7_i41 + 120 * (c7_i53 - 1)) - 1]) {
                c7_d42 = c7_b_r - 1.0;
                if (c7_d42 != (real_T)(int32_T)muDoubleScalarFloor(c7_d42)) {
                  emlrtIntegerCheckR2012b(c7_d42, &c7_jg_emlrtDCI, &c7_st);
                }

                c7_i60 = (int32_T)c7_d42;
                if ((c7_i60 < 1) || (c7_i60 > 120)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i60, 1, 120, &c7_hg_emlrtBCI,
                    &c7_st);
                }

                if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                  emlrtIntegerCheckR2012b(c7_b_c, &c7_kg_emlrtDCI, &c7_st);
                }

                c7_i70 = (int32_T)c7_b_c;
                if ((c7_i70 < 1) || (c7_i70 > 160)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i70, 1, 160, &c7_ig_emlrtBCI,
                    &c7_st);
                }

                if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
                  emlrtIntegerCheckR2012b(c7_b_r, &c7_lg_emlrtDCI, &c7_st);
                }

                c7_i77 = (int32_T)c7_b_r;
                if ((c7_i77 < 1) || (c7_i77 > 120)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i77, 1, 120, &c7_jg_emlrtBCI,
                    &c7_st);
                }

                if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                  emlrtIntegerCheckR2012b(c7_b_c, &c7_mg_emlrtDCI, &c7_st);
                }

                c7_i84 = (int32_T)c7_b_c;
                if ((c7_i84 < 1) || (c7_i84 > 160)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i84, 1, 160, &c7_kg_emlrtBCI,
                    &c7_st);
                }

                c7_b_L[(c7_i77 + 120 * (c7_i84 - 1)) - 1] = c7_b_L[(c7_i60 + 120
                  * (c7_i70 - 1)) - 1];
                do {
                  c7_exitg1 = 0;
                  if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
                    emlrtIntegerCheckR2012b(c7_b_r, &c7_dh_emlrtDCI, &c7_st);
                  }

                  c7_i95 = (int32_T)c7_b_r;
                  if ((c7_i95 < 1) || (c7_i95 > 120)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i95, 1, 120,
                      &c7_bh_emlrtBCI, &c7_st);
                  }

                  if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                    emlrtIntegerCheckR2012b(c7_b_c, &c7_eh_emlrtDCI, &c7_st);
                  }

                  c7_i102 = (int32_T)c7_b_c;
                  if ((c7_i102 < 1) || (c7_i102 > 160)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i102, 1, 160,
                      &c7_ch_emlrtBCI, &c7_st);
                  }

                  c7_d77 = c7_b_L[(c7_i95 + 120 * (c7_i102 - 1)) - 1] + 1.0;
                  if (c7_d77 != (real_T)(int32_T)muDoubleScalarFloor(c7_d77)) {
                    emlrtIntegerCheckR2012b(c7_d77, &c7_ch_emlrtDCI, &c7_st);
                  }

                  c7_i108 = (int32_T)c7_d77;
                  if ((c7_i108 < 1) || (c7_i108 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i108, 1, 9601,
                      &c7_ah_emlrtBCI, &c7_st);
                  }

                  if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
                    emlrtIntegerCheckR2012b(c7_b_r, &c7_fh_emlrtDCI, &c7_st);
                  }

                  c7_i118 = (int32_T)c7_b_r;
                  if ((c7_i118 < 1) || (c7_i118 > 120)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i118, 1, 120,
                      &c7_dh_emlrtBCI, &c7_st);
                  }

                  if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                    emlrtIntegerCheckR2012b(c7_b_c, &c7_gh_emlrtDCI, &c7_st);
                  }

                  c7_i122 = (int32_T)c7_b_c;
                  if ((c7_i122 < 1) || (c7_i122 > 160)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i122, 1, 160,
                      &c7_eh_emlrtBCI, &c7_st);
                  }

                  if (chartInstance->c7_P[c7_i108 - 1] < c7_b_L[(c7_i118 + 120 *
                       (c7_i122 - 1)) - 1]) {
                    if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r))
                    {
                      emlrtIntegerCheckR2012b(c7_b_r, &c7_oh_emlrtDCI, &c7_st);
                    }

                    c7_i129 = (int32_T)c7_b_r;
                    if ((c7_i129 < 1) || (c7_i129 > 120)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i129, 1, 120,
                        &c7_mh_emlrtBCI, &c7_st);
                    }

                    if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c))
                    {
                      emlrtIntegerCheckR2012b(c7_b_c, &c7_ph_emlrtDCI, &c7_st);
                    }

                    c7_i134 = (int32_T)c7_b_c;
                    if ((c7_i134 < 1) || (c7_i134 > 160)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i134, 1, 160,
                        &c7_nh_emlrtBCI, &c7_st);
                    }

                    c7_d97 = c7_b_L[(c7_i129 + 120 * (c7_i134 - 1)) - 1] + 1.0;
                    if (c7_d97 != (real_T)(int32_T)muDoubleScalarFloor(c7_d97))
                    {
                      emlrtIntegerCheckR2012b(c7_d97, &c7_nh_emlrtDCI, &c7_st);
                    }

                    c7_i137 = (int32_T)c7_d97;
                    if ((c7_i137 < 1) || (c7_i137 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i137, 1, 9601,
                        &c7_lh_emlrtBCI, &c7_st);
                    }

                    if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r))
                    {
                      emlrtIntegerCheckR2012b(c7_b_r, &c7_qh_emlrtDCI, &c7_st);
                    }

                    c7_i140 = (int32_T)c7_b_r;
                    if ((c7_i140 < 1) || (c7_i140 > 120)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i140, 1, 120,
                        &c7_oh_emlrtBCI, &c7_st);
                    }

                    if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c))
                    {
                      emlrtIntegerCheckR2012b(c7_b_c, &c7_rh_emlrtDCI, &c7_st);
                    }

                    c7_i144 = (int32_T)c7_b_c;
                    if ((c7_i144 < 1) || (c7_i144 > 160)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i144, 1, 160,
                        &c7_ph_emlrtBCI, &c7_st);
                    }

                    c7_b_L[(c7_i140 + 120 * (c7_i144 - 1)) - 1] =
                      chartInstance->c7_P[c7_i137 - 1];
                  } else {
                    c7_exitg1 = 1;
                  }
                } while (c7_exitg1 == 0);

                c7_d96 = c7_b_r - 1.0;
                if (c7_d96 != (real_T)(int32_T)muDoubleScalarFloor(c7_d96)) {
                  emlrtIntegerCheckR2012b(c7_d96, &c7_jh_emlrtDCI, &c7_st);
                }

                c7_i133 = (int32_T)c7_d96;
                if ((c7_i133 < 1) || (c7_i133 > 120)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i133, 1, 120, &c7_hh_emlrtBCI,
                    &c7_st);
                }

                if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                  emlrtIntegerCheckR2012b(c7_b_c, &c7_kh_emlrtDCI, &c7_st);
                }

                c7_i136 = (int32_T)c7_b_c;
                if ((c7_i136 < 1) || (c7_i136 > 160)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i136, 1, 160, &c7_ih_emlrtBCI,
                    &c7_st);
                }

                c7_d98 = c7_b_r + 1.0;
                if (c7_d98 != (real_T)(int32_T)muDoubleScalarFloor(c7_d98)) {
                  emlrtIntegerCheckR2012b(c7_d98, &c7_lh_emlrtDCI, &c7_st);
                }

                c7_i139 = (int32_T)c7_d98;
                if ((c7_i139 < 1) || (c7_i139 > 120)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i139, 1, 120, &c7_jh_emlrtBCI,
                    &c7_st);
                }

                c7_d100 = c7_b_c - 1.0;
                if (c7_d100 != (real_T)(int32_T)muDoubleScalarFloor(c7_d100)) {
                  emlrtIntegerCheckR2012b(c7_d100, &c7_mh_emlrtDCI, &c7_st);
                }

                c7_i143 = (int32_T)c7_d100;
                if ((c7_i143 < 1) || (c7_i143 > 160)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i143, 1, 160, &c7_kh_emlrtBCI,
                    &c7_st);
                }

                if (c7_b_L[(c7_i133 + 120 * (c7_i136 - 1)) - 1] != c7_b_L
                    [(c7_i139 + 120 * (c7_i143 - 1)) - 1]) {
                  c7_d103 = c7_b_r + 1.0;
                  if (c7_d103 != (real_T)(int32_T)muDoubleScalarFloor(c7_d103))
                  {
                    emlrtIntegerCheckR2012b(c7_d103, &c7_sh_emlrtDCI, &c7_st);
                  }

                  c7_i147 = (int32_T)c7_d103;
                  if ((c7_i147 < 1) || (c7_i147 > 120)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i147, 1, 120,
                      &c7_qh_emlrtBCI, &c7_st);
                  }

                  c7_d106 = c7_b_c - 1.0;
                  if (c7_d106 != (real_T)(int32_T)muDoubleScalarFloor(c7_d106))
                  {
                    emlrtIntegerCheckR2012b(c7_d106, &c7_th_emlrtDCI, &c7_st);
                  }

                  c7_i152 = (int32_T)c7_d106;
                  if ((c7_i152 < 1) || (c7_i152 > 160)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i152, 1, 160,
                      &c7_rh_emlrtBCI, &c7_st);
                  }

                  c7_d_rootj = c7_b_L[(c7_i147 + 120 * (c7_i152 - 1)) - 1];
                  do {
                    c7_exitg1 = 0;
                    c7_d110 = c7_d_rootj + 1.0;
                    if (c7_d110 != (real_T)(int32_T)muDoubleScalarFloor(c7_d110))
                    {
                      emlrtIntegerCheckR2012b(c7_d110, &c7_ri_emlrtDCI, &c7_st);
                    }

                    c7_i157 = (int32_T)c7_d110;
                    if ((c7_i157 < 1) || (c7_i157 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i157, 1, 9601,
                        &c7_pi_emlrtBCI, &c7_st);
                    }

                    if (chartInstance->c7_P[c7_i157 - 1] < c7_d_rootj) {
                      c7_d114 = c7_d_rootj + 1.0;
                      if (c7_d114 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d114)) {
                        emlrtIntegerCheckR2012b(c7_d114, &c7_ij_emlrtDCI, &c7_st);
                      }

                      c7_i161 = (int32_T)c7_d114;
                      if ((c7_i161 < 1) || (c7_i161 > 9601)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i161, 1, 9601,
                          &c7_gj_emlrtBCI, &c7_st);
                      }

                      c7_d_rootj = chartInstance->c7_P[c7_i161 - 1];
                    } else {
                      c7_exitg1 = 1;
                    }
                  } while (c7_exitg1 == 0);

                  if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
                    emlrtIntegerCheckR2012b(c7_b_r, &c7_gj_emlrtDCI, &c7_st);
                  }

                  c7_i163 = (int32_T)c7_b_r;
                  if ((c7_i163 < 1) || (c7_i163 > 120)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i163, 1, 120,
                      &c7_ej_emlrtBCI, &c7_st);
                  }

                  if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                    emlrtIntegerCheckR2012b(c7_b_c, &c7_hj_emlrtDCI, &c7_st);
                  }

                  c7_i167 = (int32_T)c7_b_c;
                  if ((c7_i167 < 1) || (c7_i167 > 160)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i167, 1, 160,
                      &c7_fj_emlrtBCI, &c7_st);
                  }

                  if (c7_b_L[(c7_i163 + 120 * (c7_i167 - 1)) - 1] > c7_d_rootj)
                  {
                    if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r))
                    {
                      emlrtIntegerCheckR2012b(c7_b_r, &c7_rc_emlrtDCI, &c7_st);
                    }

                    c7_i171 = (int32_T)c7_b_r;
                    if ((c7_i171 < 1) || (c7_i171 > 120)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i171, 1, 120,
                        &c7_pc_emlrtBCI, &c7_st);
                    }

                    if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c))
                    {
                      emlrtIntegerCheckR2012b(c7_b_c, &c7_sc_emlrtDCI, &c7_st);
                    }

                    c7_i177 = (int32_T)c7_b_c;
                    if ((c7_i177 < 1) || (c7_i177 > 160)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i177, 1, 160,
                        &c7_qc_emlrtBCI, &c7_st);
                    }

                    c7_b_L[(c7_i171 + 120 * (c7_i177 - 1)) - 1] = c7_d_rootj;
                  }

                  do {
                    c7_exitg1 = 0;
                    c7_d121 = c7_b_r + 1.0;
                    if (c7_d121 != (real_T)(int32_T)muDoubleScalarFloor(c7_d121))
                    {
                      emlrtIntegerCheckR2012b(c7_d121, &c7_dk_emlrtDCI, &c7_st);
                    }

                    c7_i176 = (int32_T)c7_d121;
                    if ((c7_i176 < 1) || (c7_i176 > 120)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i176, 1, 120,
                        &c7_bk_emlrtBCI, &c7_st);
                    }

                    c7_d125 = c7_b_c - 1.0;
                    if (c7_d125 != (real_T)(int32_T)muDoubleScalarFloor(c7_d125))
                    {
                      emlrtIntegerCheckR2012b(c7_d125, &c7_ek_emlrtDCI, &c7_st);
                    }

                    c7_i182 = (int32_T)c7_d125;
                    if ((c7_i182 < 1) || (c7_i182 > 160)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i182, 1, 160,
                        &c7_ck_emlrtBCI, &c7_st);
                    }

                    c7_d127 = c7_b_L[(c7_i176 + 120 * (c7_i182 - 1)) - 1] + 1.0;
                    if (c7_d127 != (real_T)(int32_T)muDoubleScalarFloor(c7_d127))
                    {
                      emlrtIntegerCheckR2012b(c7_d127, &c7_ck_emlrtDCI, &c7_st);
                    }

                    c7_i188 = (int32_T)c7_d127;
                    if ((c7_i188 < 1) || (c7_i188 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i188, 1, 9601,
                        &c7_ak_emlrtBCI, &c7_st);
                    }

                    c7_d131 = c7_b_r + 1.0;
                    if (c7_d131 != (real_T)(int32_T)muDoubleScalarFloor(c7_d131))
                    {
                      emlrtIntegerCheckR2012b(c7_d131, &c7_fk_emlrtDCI, &c7_st);
                    }

                    c7_i195 = (int32_T)c7_d131;
                    if ((c7_i195 < 1) || (c7_i195 > 120)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i195, 1, 120,
                        &c7_dk_emlrtBCI, &c7_st);
                    }

                    c7_d136 = c7_b_c - 1.0;
                    if (c7_d136 != (real_T)(int32_T)muDoubleScalarFloor(c7_d136))
                    {
                      emlrtIntegerCheckR2012b(c7_d136, &c7_gk_emlrtDCI, &c7_st);
                    }

                    c7_i200 = (int32_T)c7_d136;
                    if ((c7_i200 < 1) || (c7_i200 > 160)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i200, 1, 160,
                        &c7_ek_emlrtBCI, &c7_st);
                    }

                    if (chartInstance->c7_P[c7_i188 - 1] < c7_b_L[(c7_i195 + 120
                         * (c7_i200 - 1)) - 1]) {
                      c7_d139 = c7_b_r + 1.0;
                      if (c7_d139 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d139)) {
                        emlrtIntegerCheckR2012b(c7_d139, &c7_sk_emlrtDCI, &c7_st);
                      }

                      c7_i205 = (int32_T)c7_d139;
                      if ((c7_i205 < 1) || (c7_i205 > 120)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i205, 1, 120,
                          &c7_qk_emlrtBCI, &c7_st);
                      }

                      c7_d143 = c7_b_c - 1.0;
                      if (c7_d143 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d143)) {
                        emlrtIntegerCheckR2012b(c7_d143, &c7_tk_emlrtDCI, &c7_st);
                      }

                      c7_i211 = (int32_T)c7_d143;
                      if ((c7_i211 < 1) || (c7_i211 > 160)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i211, 1, 160,
                          &c7_rk_emlrtBCI, &c7_st);
                      }

                      c7_d147 = c7_b_L[(c7_i205 + 120 * (c7_i211 - 1)) - 1] +
                        1.0;
                      if (c7_d147 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d147)) {
                        emlrtIntegerCheckR2012b(c7_d147, &c7_rk_emlrtDCI, &c7_st);
                      }

                      c7_i216 = (int32_T)c7_d147;
                      if ((c7_i216 < 1) || (c7_i216 > 9601)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i216, 1, 9601,
                          &c7_pk_emlrtBCI, &c7_st);
                      }

                      c7_j_j = chartInstance->c7_P[c7_i216 - 1];
                      if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r))
                      {
                        emlrtIntegerCheckR2012b(c7_b_r, &c7_uk_emlrtDCI, &c7_st);
                      }

                      c7_i222 = (int32_T)c7_b_r;
                      if ((c7_i222 < 1) || (c7_i222 > 120)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i222, 1, 120,
                          &c7_sk_emlrtBCI, &c7_st);
                      }

                      if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c))
                      {
                        emlrtIntegerCheckR2012b(c7_b_c, &c7_vk_emlrtDCI, &c7_st);
                      }

                      c7_i227 = (int32_T)c7_b_c;
                      if ((c7_i227 < 1) || (c7_i227 > 160)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i227, 1, 160,
                          &c7_tk_emlrtBCI, &c7_st);
                      }

                      c7_d158 = c7_b_r + 1.0;
                      if (c7_d158 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d158)) {
                        emlrtIntegerCheckR2012b(c7_d158, &c7_xk_emlrtDCI, &c7_st);
                      }

                      c7_i232 = (int32_T)c7_d158;
                      if ((c7_i232 < 1) || (c7_i232 > 120)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i232, 1, 120,
                          &c7_vk_emlrtBCI, &c7_st);
                      }

                      c7_d161 = c7_b_c - 1.0;
                      if (c7_d161 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d161)) {
                        emlrtIntegerCheckR2012b(c7_d161, &c7_yk_emlrtDCI, &c7_st);
                      }

                      c7_i236 = (int32_T)c7_d161;
                      if ((c7_i236 < 1) || (c7_i236 > 160)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i236, 1, 160,
                          &c7_wk_emlrtBCI, &c7_st);
                      }

                      c7_d163 = c7_b_L[(c7_i232 + 120 * (c7_i236 - 1)) - 1] +
                        1.0;
                      if (c7_d163 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d163)) {
                        emlrtIntegerCheckR2012b(c7_d163, &c7_wk_emlrtDCI, &c7_st);
                      }

                      c7_i239 = (int32_T)c7_d163;
                      if ((c7_i239 < 1) || (c7_i239 > 9601)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i239, 1, 9601,
                          &c7_uk_emlrtBCI, &c7_st);
                      }

                      chartInstance->c7_P[c7_i239 - 1] = c7_b_L[(c7_i222 + 120 *
                        (c7_i227 - 1)) - 1];
                      c7_d165 = c7_b_r + 1.0;
                      if (c7_d165 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d165)) {
                        emlrtIntegerCheckR2012b(c7_d165, &c7_tc_emlrtDCI, &c7_st);
                      }

                      c7_i241 = (int32_T)c7_d165;
                      if ((c7_i241 < 1) || (c7_i241 > 120)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i241, 1, 120,
                          &c7_rc_emlrtBCI, &c7_st);
                      }

                      c7_d167 = c7_b_c - 1.0;
                      if (c7_d167 != (real_T)(int32_T)muDoubleScalarFloor
                          (c7_d167)) {
                        emlrtIntegerCheckR2012b(c7_d167, &c7_uc_emlrtDCI, &c7_st);
                      }

                      c7_i243 = (int32_T)c7_d167;
                      if ((c7_i243 < 1) || (c7_i243 > 160)) {
                        emlrtDynamicBoundsCheckR2012b(c7_i243, 1, 160,
                          &c7_sc_emlrtBCI, &c7_st);
                      }

                      c7_b_L[(c7_i241 + 120 * (c7_i243 - 1)) - 1] = c7_j_j;
                    } else {
                      c7_exitg1 = 1;
                    }
                  } while (c7_exitg1 == 0);

                  if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
                    emlrtIntegerCheckR2012b(c7_b_r, &c7_mk_emlrtDCI, &c7_st);
                  }

                  c7_i209 = (int32_T)c7_b_r;
                  if ((c7_i209 < 1) || (c7_i209 > 120)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i209, 1, 120,
                      &c7_kk_emlrtBCI, &c7_st);
                  }

                  if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                    emlrtIntegerCheckR2012b(c7_b_c, &c7_nk_emlrtDCI, &c7_st);
                  }

                  c7_i214 = (int32_T)c7_b_c;
                  if ((c7_i214 < 1) || (c7_i214 > 160)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i214, 1, 160,
                      &c7_lk_emlrtBCI, &c7_st);
                  }

                  c7_d149 = c7_b_r + 1.0;
                  if (c7_d149 != (real_T)(int32_T)muDoubleScalarFloor(c7_d149))
                  {
                    emlrtIntegerCheckR2012b(c7_d149, &c7_pk_emlrtDCI, &c7_st);
                  }

                  c7_i219 = (int32_T)c7_d149;
                  if ((c7_i219 < 1) || (c7_i219 > 120)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i219, 1, 120,
                      &c7_nk_emlrtBCI, &c7_st);
                  }

                  c7_d152 = c7_b_c - 1.0;
                  if (c7_d152 != (real_T)(int32_T)muDoubleScalarFloor(c7_d152))
                  {
                    emlrtIntegerCheckR2012b(c7_d152, &c7_qk_emlrtDCI, &c7_st);
                  }

                  c7_i224 = (int32_T)c7_d152;
                  if ((c7_i224 < 1) || (c7_i224 > 160)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i224, 1, 160,
                      &c7_ok_emlrtBCI, &c7_st);
                  }

                  c7_d154 = c7_b_L[(c7_i219 + 120 * (c7_i224 - 1)) - 1] + 1.0;
                  if (c7_d154 != (real_T)(int32_T)muDoubleScalarFloor(c7_d154))
                  {
                    emlrtIntegerCheckR2012b(c7_d154, &c7_ok_emlrtDCI, &c7_st);
                  }

                  c7_i228 = (int32_T)c7_d154;
                  if ((c7_i228 < 1) || (c7_i228 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i228, 1, 9601,
                      &c7_mk_emlrtBCI, &c7_st);
                  }

                  chartInstance->c7_P[c7_i228 - 1] = c7_b_L[(c7_i209 + 120 *
                    (c7_i214 - 1)) - 1];
                }

                do {
                  c7_exitg1 = 0;
                  c7_d105 = c7_b_r - 1.0;
                  if (c7_d105 != (real_T)(int32_T)muDoubleScalarFloor(c7_d105))
                  {
                    emlrtIntegerCheckR2012b(c7_d105, &c7_ni_emlrtDCI, &c7_st);
                  }

                  c7_i150 = (int32_T)c7_d105;
                  if ((c7_i150 < 1) || (c7_i150 > 120)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i150, 1, 120,
                      &c7_li_emlrtBCI, &c7_st);
                  }

                  if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                    emlrtIntegerCheckR2012b(c7_b_c, &c7_oi_emlrtDCI, &c7_st);
                  }

                  c7_i154 = (int32_T)c7_b_c;
                  if ((c7_i154 < 1) || (c7_i154 > 160)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i154, 1, 160,
                      &c7_mi_emlrtBCI, &c7_st);
                  }

                  c7_d109 = c7_b_L[(c7_i150 + 120 * (c7_i154 - 1)) - 1] + 1.0;
                  if (c7_d109 != (real_T)(int32_T)muDoubleScalarFloor(c7_d109))
                  {
                    emlrtIntegerCheckR2012b(c7_d109, &c7_mi_emlrtDCI, &c7_st);
                  }

                  c7_i156 = (int32_T)c7_d109;
                  if ((c7_i156 < 1) || (c7_i156 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i156, 1, 9601,
                      &c7_ki_emlrtBCI, &c7_st);
                  }

                  c7_d113 = c7_b_r - 1.0;
                  if (c7_d113 != (real_T)(int32_T)muDoubleScalarFloor(c7_d113))
                  {
                    emlrtIntegerCheckR2012b(c7_d113, &c7_pi_emlrtDCI, &c7_st);
                  }

                  c7_i160 = (int32_T)c7_d113;
                  if ((c7_i160 < 1) || (c7_i160 > 120)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i160, 1, 120,
                      &c7_ni_emlrtBCI, &c7_st);
                  }

                  if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                    emlrtIntegerCheckR2012b(c7_b_c, &c7_qi_emlrtDCI, &c7_st);
                  }

                  c7_i164 = (int32_T)c7_b_c;
                  if ((c7_i164 < 1) || (c7_i164 > 160)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i164, 1, 160,
                      &c7_oi_emlrtBCI, &c7_st);
                  }

                  if (chartInstance->c7_P[c7_i156 - 1] < c7_b_L[(c7_i160 + 120 *
                       (c7_i164 - 1)) - 1]) {
                    c7_d118 = c7_b_r - 1.0;
                    if (c7_d118 != (real_T)(int32_T)muDoubleScalarFloor(c7_d118))
                    {
                      emlrtIntegerCheckR2012b(c7_d118, &c7_ej_emlrtDCI, &c7_st);
                    }

                    c7_i168 = (int32_T)c7_d118;
                    if ((c7_i168 < 1) || (c7_i168 > 120)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i168, 1, 120,
                        &c7_cj_emlrtBCI, &c7_st);
                    }

                    if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c))
                    {
                      emlrtIntegerCheckR2012b(c7_b_c, &c7_fj_emlrtDCI, &c7_st);
                    }

                    c7_i173 = (int32_T)c7_b_c;
                    if ((c7_i173 < 1) || (c7_i173 > 160)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i173, 1, 160,
                        &c7_dj_emlrtBCI, &c7_st);
                    }

                    c7_d123 = c7_b_L[(c7_i168 + 120 * (c7_i173 - 1)) - 1] + 1.0;
                    if (c7_d123 != (real_T)(int32_T)muDoubleScalarFloor(c7_d123))
                    {
                      emlrtIntegerCheckR2012b(c7_d123, &c7_dj_emlrtDCI, &c7_st);
                    }

                    c7_i180 = (int32_T)c7_d123;
                    if ((c7_i180 < 1) || (c7_i180 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i180, 1, 9601,
                        &c7_bj_emlrtBCI, &c7_st);
                    }

                    c7_j_j = chartInstance->c7_P[c7_i180 - 1];
                    if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r))
                    {
                      emlrtIntegerCheckR2012b(c7_b_r, &c7_jj_emlrtDCI, &c7_st);
                    }

                    c7_i185 = (int32_T)c7_b_r;
                    if ((c7_i185 < 1) || (c7_i185 > 120)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i185, 1, 120,
                        &c7_hj_emlrtBCI, &c7_st);
                    }

                    if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c))
                    {
                      emlrtIntegerCheckR2012b(c7_b_c, &c7_kj_emlrtDCI, &c7_st);
                    }

                    c7_i192 = (int32_T)c7_b_c;
                    if ((c7_i192 < 1) || (c7_i192 > 160)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i192, 1, 160,
                        &c7_ij_emlrtBCI, &c7_st);
                    }

                    c7_d134 = c7_b_r - 1.0;
                    if (c7_d134 != (real_T)(int32_T)muDoubleScalarFloor(c7_d134))
                    {
                      emlrtIntegerCheckR2012b(c7_d134, &c7_mj_emlrtDCI, &c7_st);
                    }

                    c7_i198 = (int32_T)c7_d134;
                    if ((c7_i198 < 1) || (c7_i198 > 120)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i198, 1, 120,
                        &c7_kj_emlrtBCI, &c7_st);
                    }

                    if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c))
                    {
                      emlrtIntegerCheckR2012b(c7_b_c, &c7_nj_emlrtDCI, &c7_st);
                    }

                    c7_i202 = (int32_T)c7_b_c;
                    if ((c7_i202 < 1) || (c7_i202 > 160)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i202, 1, 160,
                        &c7_lj_emlrtBCI, &c7_st);
                    }

                    c7_d141 = c7_b_L[(c7_i198 + 120 * (c7_i202 - 1)) - 1] + 1.0;
                    if (c7_d141 != (real_T)(int32_T)muDoubleScalarFloor(c7_d141))
                    {
                      emlrtIntegerCheckR2012b(c7_d141, &c7_lj_emlrtDCI, &c7_st);
                    }

                    c7_i208 = (int32_T)c7_d141;
                    if ((c7_i208 < 1) || (c7_i208 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i208, 1, 9601,
                        &c7_jj_emlrtBCI, &c7_st);
                    }

                    chartInstance->c7_P[c7_i208 - 1] = c7_b_L[(c7_i185 + 120 *
                      (c7_i192 - 1)) - 1];
                    c7_d146 = c7_b_r - 1.0;
                    if (c7_d146 != (real_T)(int32_T)muDoubleScalarFloor(c7_d146))
                    {
                      emlrtIntegerCheckR2012b(c7_d146, &c7_vc_emlrtDCI, &c7_st);
                    }

                    c7_i215 = (int32_T)c7_d146;
                    if ((c7_i215 < 1) || (c7_i215 > 120)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i215, 1, 120,
                        &c7_tc_emlrtBCI, &c7_st);
                    }

                    if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c))
                    {
                      emlrtIntegerCheckR2012b(c7_b_c, &c7_wc_emlrtDCI, &c7_st);
                    }

                    c7_i218 = (int32_T)c7_b_c;
                    if ((c7_i218 < 1) || (c7_i218 > 160)) {
                      emlrtDynamicBoundsCheckR2012b(c7_i218, 1, 160,
                        &c7_uc_emlrtBCI, &c7_st);
                    }

                    c7_b_L[(c7_i215 + 120 * (c7_i218 - 1)) - 1] = c7_j_j;
                  } else {
                    c7_exitg1 = 1;
                  }
                } while (c7_exitg1 == 0);

                if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
                  emlrtIntegerCheckR2012b(c7_b_r, &c7_xi_emlrtDCI, &c7_st);
                }

                c7_i169 = (int32_T)c7_b_r;
                if ((c7_i169 < 1) || (c7_i169 > 120)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i169, 1, 120, &c7_vi_emlrtBCI,
                    &c7_st);
                }

                if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                  emlrtIntegerCheckR2012b(c7_b_c, &c7_yi_emlrtDCI, &c7_st);
                }

                c7_i175 = (int32_T)c7_b_c;
                if ((c7_i175 < 1) || (c7_i175 > 160)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i175, 1, 160, &c7_wi_emlrtBCI,
                    &c7_st);
                }

                c7_d124 = c7_b_r - 1.0;
                if (c7_d124 != (real_T)(int32_T)muDoubleScalarFloor(c7_d124)) {
                  emlrtIntegerCheckR2012b(c7_d124, &c7_bj_emlrtDCI, &c7_st);
                }

                c7_i181 = (int32_T)c7_d124;
                if ((c7_i181 < 1) || (c7_i181 > 120)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i181, 1, 120, &c7_yi_emlrtBCI,
                    &c7_st);
                }

                if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                  emlrtIntegerCheckR2012b(c7_b_c, &c7_cj_emlrtDCI, &c7_st);
                }

                c7_i187 = (int32_T)c7_b_c;
                if ((c7_i187 < 1) || (c7_i187 > 160)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i187, 1, 160, &c7_aj_emlrtBCI,
                    &c7_st);
                }

                c7_d130 = c7_b_L[(c7_i181 + 120 * (c7_i187 - 1)) - 1] + 1.0;
                if (c7_d130 != (real_T)(int32_T)muDoubleScalarFloor(c7_d130)) {
                  emlrtIntegerCheckR2012b(c7_d130, &c7_aj_emlrtDCI, &c7_st);
                }

                c7_i194 = (int32_T)c7_d130;
                if ((c7_i194 < 1) || (c7_i194 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i194, 1, 9601,
                    &c7_xi_emlrtBCI, &c7_st);
                }

                chartInstance->c7_P[c7_i194 - 1] = c7_b_L[(c7_i169 + 120 *
                  (c7_i175 - 1)) - 1];
              } else {
                c7_guard2 = true;
              }
            } else {
              c7_guard2 = true;
            }
          }

          if (c7_guard3) {
            if (c7_b_r > 1.0) {
              c7_d30 = c7_b_r - 1.0;
              if (c7_d30 != (real_T)(int32_T)muDoubleScalarFloor(c7_d30)) {
                emlrtIntegerCheckR2012b(c7_d30, &c7_wf_emlrtDCI, &c7_st);
              }

              c7_i44 = (int32_T)c7_d30;
              if ((c7_i44 < 1) || (c7_i44 > 120)) {
                emlrtDynamicBoundsCheckR2012b(c7_i44, 1, 120, &c7_uf_emlrtBCI,
                  &c7_st);
              }

              if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                emlrtIntegerCheckR2012b(c7_b_c, &c7_xf_emlrtDCI, &c7_st);
              }

              c7_i54 = (int32_T)c7_b_c;
              if ((c7_i54 < 1) || (c7_i54 > 160)) {
                emlrtDynamicBoundsCheckR2012b(c7_i54, 1, 160, &c7_vf_emlrtBCI,
                  &c7_st);
              }

              if (c7_varargin_1[(c7_i44 + 120 * (c7_i54 - 1)) - 1]) {
                c7_d47 = c7_b_r - 1.0;
                if (c7_d47 != (real_T)(int32_T)muDoubleScalarFloor(c7_d47)) {
                  emlrtIntegerCheckR2012b(c7_d47, &c7_bg_emlrtDCI, &c7_st);
                }

                c7_i63 = (int32_T)c7_d47;
                if ((c7_i63 < 1) || (c7_i63 > 120)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i63, 1, 120, &c7_yf_emlrtBCI,
                    &c7_st);
                }

                if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                  emlrtIntegerCheckR2012b(c7_b_c, &c7_cg_emlrtDCI, &c7_st);
                }

                c7_i73 = (int32_T)c7_b_c;
                if ((c7_i73 < 1) || (c7_i73 > 160)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i73, 1, 160, &c7_ag_emlrtBCI,
                    &c7_st);
                }

                if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
                  emlrtIntegerCheckR2012b(c7_b_r, &c7_dg_emlrtDCI, &c7_st);
                }

                c7_i82 = (int32_T)c7_b_r;
                if ((c7_i82 < 1) || (c7_i82 > 120)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i82, 1, 120, &c7_bg_emlrtBCI,
                    &c7_st);
                }

                if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
                  emlrtIntegerCheckR2012b(c7_b_c, &c7_eg_emlrtDCI, &c7_st);
                }

                c7_i86 = (int32_T)c7_b_c;
                if ((c7_i86 < 1) || (c7_i86 > 160)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i86, 1, 160, &c7_cg_emlrtBCI,
                    &c7_st);
                }

                c7_b_L[(c7_i82 + 120 * (c7_i86 - 1)) - 1] = c7_b_L[(c7_i63 + 120
                  * (c7_i73 - 1)) - 1];
              } else {
                c7_guard1 = true;
              }
            } else {
              c7_guard1 = true;
            }
          }

          if (c7_guard2) {
            c7_d33 = c7_b_r + 1.0;
            if (c7_d33 != (real_T)(int32_T)muDoubleScalarFloor(c7_d33)) {
              emlrtIntegerCheckR2012b(c7_d33, &c7_fg_emlrtDCI, &c7_st);
            }

            c7_i47 = (int32_T)c7_d33;
            if ((c7_i47 < 1) || (c7_i47 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c7_i47, 1, 120, &c7_dg_emlrtBCI,
                &c7_st);
            }

            c7_d37 = c7_b_c - 1.0;
            if (c7_d37 != (real_T)(int32_T)muDoubleScalarFloor(c7_d37)) {
              emlrtIntegerCheckR2012b(c7_d37, &c7_gg_emlrtDCI, &c7_st);
            }

            c7_i56 = (int32_T)c7_d37;
            if ((c7_i56 < 1) || (c7_i56 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c7_i56, 1, 160, &c7_eg_emlrtBCI,
                &c7_st);
            }

            if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
              emlrtIntegerCheckR2012b(c7_b_r, &c7_hg_emlrtDCI, &c7_st);
            }

            c7_i62 = (int32_T)c7_b_r;
            if ((c7_i62 < 1) || (c7_i62 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c7_i62, 1, 120, &c7_fg_emlrtBCI,
                &c7_st);
            }

            if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
              emlrtIntegerCheckR2012b(c7_b_c, &c7_ig_emlrtDCI, &c7_st);
            }

            c7_i72 = (int32_T)c7_b_c;
            if ((c7_i72 < 1) || (c7_i72 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c7_i72, 1, 160, &c7_gg_emlrtBCI,
                &c7_st);
            }

            c7_b_L[(c7_i62 + 120 * (c7_i72 - 1)) - 1] = c7_b_L[(c7_i47 + 120 *
              (c7_i56 - 1)) - 1];
          }

          if (c7_guard1) {
            if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
              emlrtIntegerCheckR2012b(c7_b_r, &c7_xc_emlrtDCI, &c7_st);
            }

            c7_i50 = (int32_T)c7_b_r;
            if ((c7_i50 < 1) || (c7_i50 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c7_i50, 1, 120, &c7_vc_emlrtBCI,
                &c7_st);
            }

            if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
              emlrtIntegerCheckR2012b(c7_b_c, &c7_yc_emlrtDCI, &c7_st);
            }

            c7_i55 = (int32_T)c7_b_c;
            if ((c7_i55 < 1) || (c7_i55 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c7_i55, 1, 160, &c7_wc_emlrtBCI,
                &c7_st);
            }

            c7_b_L[(c7_i50 + 120 * (c7_i55 - 1)) - 1] = c7_label;
            c7_d50 = c7_label + 1.0;
            if (c7_d50 != (real_T)(int32_T)muDoubleScalarFloor(c7_d50)) {
              emlrtIntegerCheckR2012b(c7_d50, &c7_ad_emlrtDCI, &c7_st);
            }

            c7_i67 = (int32_T)c7_d50;
            if ((c7_i67 < 1) || (c7_i67 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c7_i67, 1, 9601, &c7_xc_emlrtBCI,
                &c7_st);
            }

            chartInstance->c7_P[c7_i67 - 1] = c7_label;
            c7_label++;
          }
        } else {
          if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
            emlrtIntegerCheckR2012b(c7_b_r, &c7_bd_emlrtDCI, &c7_st);
          }

          c7_i28 = (int32_T)c7_b_r;
          if ((c7_i28 < 1) || (c7_i28 > 120)) {
            emlrtDynamicBoundsCheckR2012b(c7_i28, 1, 120, &c7_yc_emlrtBCI,
              &c7_st);
          }

          if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
            emlrtIntegerCheckR2012b(c7_b_c, &c7_cd_emlrtDCI, &c7_st);
          }

          c7_i30 = (int32_T)c7_b_c;
          if ((c7_i30 < 1) || (c7_i30 > 160)) {
            emlrtDynamicBoundsCheckR2012b(c7_i30, 1, 160, &c7_ad_emlrtBCI,
              &c7_st);
          }

          c7_b_L[(c7_i28 + 120 * (c7_i30 - 1)) - 1] = 0.0;
        }
      }
    }

    c7_d13 = c7_startC + 1.0;
    if (c7_d13 != (real_T)(int32_T)muDoubleScalarFloor(c7_d13)) {
      emlrtIntegerCheckR2012b(c7_d13, &c7_ed_emlrtDCI, &c7_st);
    }

    c7_i20 = (int32_T)c7_d13;
    if ((c7_i20 < 1) || (c7_i20 > 168)) {
      emlrtDynamicBoundsCheckR2012b(c7_i20, 1, 168, &c7_cd_emlrtBCI, &c7_st);
    }

    c7_d17 = muDoubleScalarRound(c7_label - c7_firstLabel);
    if (c7_d17 < 2.147483648E+9) {
      if (c7_d17 >= -2.147483648E+9) {
        c7_i22 = (int32_T)c7_d17;
      } else {
        c7_i22 = MIN_int32_T;
      }
    } else if (c7_d17 >= 2.147483648E+9) {
      c7_i22 = MAX_int32_T;
    } else {
      c7_i22 = 0;
    }

    c7_chunksSizeAndLabels[c7_i20 - 1] = c7_i22;
  }

  c7_c = c7_chunksSizeAndLabels[0];
  while ((real_T)c7_c <= 160.0) {
    for (c7_r = 0; c7_r < 120; c7_r++) {
      c7_b_r = 1.0 + (real_T)c7_r;
      if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
        emlrtIntegerCheckR2012b(c7_b_r, &c7_pd_emlrtDCI, &c7_st);
      }

      c7_i1 = (int32_T)c7_b_r;
      if ((c7_i1 < 1) || (c7_i1 > 120)) {
        emlrtDynamicBoundsCheckR2012b(c7_i1, 1, 120, &c7_nd_emlrtBCI, &c7_st);
      }

      c7_d1 = (real_T)c7_c;
      if (c7_d1 != (real_T)(int32_T)muDoubleScalarFloor(c7_d1)) {
        emlrtIntegerCheckR2012b(c7_d1, &c7_qd_emlrtDCI, &c7_st);
      }

      c7_i3 = (int32_T)muDoubleScalarFloor(c7_d1);
      if ((c7_i3 < 1) || (c7_i3 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c7_i3, 1, 160, &c7_od_emlrtBCI, &c7_st);
      }

      c7_d3 = c7_b_L[(c7_i1 + 120 * (c7_i3 - 1)) - 1];
      c7_b_st.site = &c7_ac_emlrtRSI;
      c7_k_x = c7_d3;
      c7_l_x = c7_k_x;
      c7_b = muDoubleScalarIsNaN(c7_l_x);
      if (c7_b) {
        c7_y = NULL;
        sf_mex_assign(&c7_y, sf_mex_create("y", c7_cv, 10, 0U, 1, 0U, 2, 1, 19),
                      false);
        c7_c_y = NULL;
        sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_cv, 10, 0U, 1, 0U, 2, 1, 19),
                      false);
        sf_mex_call(&c7_b_st, &c7_d_emlrtMCI, "error", 0U, 2U, 14, c7_y, 14,
                    sf_mex_call(&c7_b_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c7_b_st, NULL, "message", 1U, 1U, 14, c7_c_y)));
      }

      if (c7_d3 != 0.0) {
        if (c7_b_r > 1.0) {
          c7_d6 = c7_b_r - 1.0;
          if (c7_d6 != (real_T)(int32_T)muDoubleScalarFloor(c7_d6)) {
            emlrtIntegerCheckR2012b(c7_d6, &c7_wd_emlrtDCI, &c7_st);
          }

          c7_i10 = (int32_T)c7_d6;
          if ((c7_i10 < 1) || (c7_i10 > 120)) {
            emlrtDynamicBoundsCheckR2012b(c7_i10, 1, 120, &c7_ud_emlrtBCI,
              &c7_st);
          }

          c7_b_q0 = c7_c;
          c7_b_q1 = 1;
          if ((c7_b_q1 < 0) && (c7_b_q0 > c7_b_q1 + MAX_int32_T)) {
            c7_b_qY = MAX_int32_T;
          } else if ((c7_b_q1 > 0) && (c7_b_q0 < c7_b_q1 + MIN_int32_T)) {
            c7_b_qY = MIN_int32_T;
          } else {
            c7_b_qY = c7_b_q0 - c7_b_q1;
          }

          c7_d9 = (real_T)c7_b_qY;
          if (c7_d9 != (real_T)(int32_T)muDoubleScalarFloor(c7_d9)) {
            emlrtIntegerCheckR2012b(c7_d9, &c7_xd_emlrtDCI, &c7_st);
          }

          c7_i16 = (int32_T)muDoubleScalarFloor(c7_d9);
          if ((c7_i16 < 1) || (c7_i16 > 160)) {
            emlrtDynamicBoundsCheckR2012b(c7_i16, 1, 160, &c7_vd_emlrtBCI,
              &c7_st);
          }

          c7_d14 = c7_b_L[(c7_i10 + 120 * (c7_i16 - 1)) - 1];
          c7_b_st.site = &c7_bc_emlrtRSI;
          c7_u_x = c7_d14;
          c7_v_x = c7_u_x;
          c7_b_b = muDoubleScalarIsNaN(c7_v_x);
          if (c7_b_b) {
            c7_e_y = NULL;
            sf_mex_assign(&c7_e_y, sf_mex_create("y", c7_cv, 10, 0U, 1, 0U, 2, 1,
              19), false);
            c7_h_y = NULL;
            sf_mex_assign(&c7_h_y, sf_mex_create("y", c7_cv, 10, 0U, 1, 0U, 2, 1,
              19), false);
            sf_mex_call(&c7_b_st, &c7_d_emlrtMCI, "error", 0U, 2U, 14, c7_e_y,
                        14, sf_mex_call(&c7_b_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c7_b_st, NULL, "message", 1U, 1U, 14, c7_h_y)));
          }

          if (c7_d14 != 0.0) {
            c7_b_st.site = &c7_cc_emlrtRSI;
            c7_d19 = c7_b_r - 1.0;
            if (c7_d19 != (real_T)(int32_T)muDoubleScalarFloor(c7_d19)) {
              emlrtIntegerCheckR2012b(c7_d19, &c7_ee_emlrtDCI, &c7_b_st);
            }

            c7_i25 = (int32_T)c7_d19;
            if ((c7_i25 < 1) || (c7_i25 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c7_i25, 1, 120, &c7_ce_emlrtBCI,
                &c7_b_st);
            }

            c7_i_q0 = c7_c;
            c7_i_q1 = 1;
            if ((c7_i_q1 < 0) && (c7_i_q0 > c7_i_q1 + MAX_int32_T)) {
              c7_i_qY = MAX_int32_T;
            } else if ((c7_i_q1 > 0) && (c7_i_q0 < c7_i_q1 + MIN_int32_T)) {
              c7_i_qY = MIN_int32_T;
            } else {
              c7_i_qY = c7_i_q0 - c7_i_q1;
            }

            c7_d21 = (real_T)c7_i_qY;
            if (c7_d21 != (real_T)(int32_T)muDoubleScalarFloor(c7_d21)) {
              emlrtIntegerCheckR2012b(c7_d21, &c7_fe_emlrtDCI, &c7_b_st);
            }

            c7_i31 = (int32_T)muDoubleScalarFloor(c7_d21);
            if ((c7_i31 < 1) || (c7_i31 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c7_i31, 1, 160, &c7_de_emlrtBCI,
                &c7_b_st);
            }

            c7_b_i = c7_b_L[(c7_i25 + 120 * (c7_i31 - 1)) - 1];
            if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
              emlrtIntegerCheckR2012b(c7_b_r, &c7_ge_emlrtDCI, &c7_b_st);
            }

            c7_i36 = (int32_T)c7_b_r;
            if ((c7_i36 < 1) || (c7_i36 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c7_i36, 1, 120, &c7_ee_emlrtBCI,
                &c7_b_st);
            }

            c7_d32 = (real_T)c7_c;
            if (c7_d32 != (real_T)(int32_T)muDoubleScalarFloor(c7_d32)) {
              emlrtIntegerCheckR2012b(c7_d32, &c7_he_emlrtDCI, &c7_b_st);
            }

            c7_i46 = (int32_T)muDoubleScalarFloor(c7_d32);
            if ((c7_i46 < 1) || (c7_i46 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c7_i46, 1, 160, &c7_fe_emlrtBCI,
                &c7_b_st);
            }

            c7_j = c7_b_L[(c7_i36 + 120 * (c7_i46 - 1)) - 1];
            c7_c_st.site = &c7_sb_emlrtRSI;
            c7_f_i = c7_b_i;
            c7_d41 = c7_f_i;
            do {
              c7_exitg1 = 0;
              c7_d48 = c7_d41 + 1.0;
              if (c7_d48 != (real_T)(int32_T)muDoubleScalarFloor(c7_d48)) {
                emlrtIntegerCheckR2012b(c7_d48, &c7_qe_emlrtDCI, &c7_c_st);
              }

              c7_i65 = (int32_T)c7_d48;
              if ((c7_i65 < 1) || (c7_i65 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c7_i65, 1, 9601, &c7_oe_emlrtBCI,
                  &c7_c_st);
              }

              if (chartInstance->c7_P[c7_i65 - 1] < c7_d41) {
                c7_d55 = c7_d41 + 1.0;
                if (c7_d55 != (real_T)(int32_T)muDoubleScalarFloor(c7_d55)) {
                  emlrtIntegerCheckR2012b(c7_d55, &c7_re_emlrtDCI, &c7_c_st);
                }

                c7_i76 = (int32_T)c7_d55;
                if ((c7_i76 < 1) || (c7_i76 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i76, 1, 9601, &c7_pe_emlrtBCI,
                    &c7_c_st);
                }

                c7_d41 = chartInstance->c7_P[c7_i76 - 1];
              } else {
                c7_exitg1 = 1;
              }
            } while (c7_exitg1 == 0);

            if (c7_b_i != c7_j) {
              c7_c_st.site = &c7_tb_emlrtRSI;
              c7_i_i = c7_j;
              c7_rootj = c7_i_i;
              do {
                c7_exitg1 = 0;
                c7_d61 = c7_rootj + 1.0;
                if (c7_d61 != (real_T)(int32_T)muDoubleScalarFloor(c7_d61)) {
                  emlrtIntegerCheckR2012b(c7_d61, &c7_qe_emlrtDCI, &c7_c_st);
                }

                c7_i88 = (int32_T)c7_d61;
                if ((c7_i88 < 1) || (c7_i88 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i88, 1, 9601, &c7_oe_emlrtBCI,
                    &c7_c_st);
                }

                if (chartInstance->c7_P[c7_i88 - 1] < c7_rootj) {
                  c7_d67 = c7_rootj + 1.0;
                  if (c7_d67 != (real_T)(int32_T)muDoubleScalarFloor(c7_d67)) {
                    emlrtIntegerCheckR2012b(c7_d67, &c7_re_emlrtDCI, &c7_c_st);
                  }

                  c7_i96 = (int32_T)c7_d67;
                  if ((c7_i96 < 1) || (c7_i96 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i96, 1, 9601,
                      &c7_pe_emlrtBCI, &c7_c_st);
                  }

                  c7_rootj = chartInstance->c7_P[c7_i96 - 1];
                } else {
                  c7_exitg1 = 1;
                }
              } while (c7_exitg1 == 0);

              if (c7_d41 > c7_rootj) {
                c7_d41 = c7_rootj;
              }

              c7_c_st.site = &c7_ub_emlrtRSI;
              c7_o_i = c7_j;
              c7_d_root = c7_d41;
              do {
                c7_exitg1 = 0;
                c7_d80 = c7_o_i + 1.0;
                if (c7_d80 != (real_T)(int32_T)muDoubleScalarFloor(c7_d80)) {
                  emlrtIntegerCheckR2012b(c7_d80, &c7_gf_emlrtDCI, &c7_c_st);
                }

                c7_i113 = (int32_T)c7_d80;
                if ((c7_i113 < 1) || (c7_i113 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i113, 1, 9601,
                    &c7_ef_emlrtBCI, &c7_c_st);
                }

                if (chartInstance->c7_P[c7_i113 - 1] < c7_o_i) {
                  c7_d85 = c7_o_i + 1.0;
                  if (c7_d85 != (real_T)(int32_T)muDoubleScalarFloor(c7_d85)) {
                    emlrtIntegerCheckR2012b(c7_d85, &c7_jf_emlrtDCI, &c7_c_st);
                  }

                  c7_i120 = (int32_T)c7_d85;
                  if ((c7_i120 < 1) || (c7_i120 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i120, 1, 9601,
                      &c7_hf_emlrtBCI, &c7_c_st);
                  }

                  c7_g_j = chartInstance->c7_P[c7_i120 - 1];
                  c7_d93 = c7_o_i + 1.0;
                  if (c7_d93 != (real_T)(int32_T)muDoubleScalarFloor(c7_d93)) {
                    emlrtIntegerCheckR2012b(c7_d93, &c7_md_emlrtDCI, &c7_c_st);
                  }

                  c7_i128 = (int32_T)c7_d93;
                  if ((c7_i128 < 1) || (c7_i128 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i128, 1, 9601,
                      &c7_kd_emlrtBCI, &c7_c_st);
                  }

                  chartInstance->c7_P[c7_i128 - 1] = c7_d_root;
                  c7_o_i = c7_g_j;
                } else {
                  c7_exitg1 = 1;
                }
              } while (c7_exitg1 == 0);

              c7_d89 = c7_o_i + 1.0;
              if (c7_d89 != (real_T)(int32_T)muDoubleScalarFloor(c7_d89)) {
                emlrtIntegerCheckR2012b(c7_d89, &c7_nd_emlrtDCI, &c7_c_st);
              }

              c7_i124 = (int32_T)c7_d89;
              if ((c7_i124 < 1) || (c7_i124 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c7_i124, 1, 9601, &c7_ld_emlrtBCI,
                  &c7_c_st);
              }

              chartInstance->c7_P[c7_i124 - 1] = c7_d_root;
            }

            c7_c_st.site = &c7_vb_emlrtRSI;
            c7_k_i = c7_b_i;
            c7_root = c7_d41;
            do {
              c7_exitg1 = 0;
              c7_d63 = c7_k_i + 1.0;
              if (c7_d63 != (real_T)(int32_T)muDoubleScalarFloor(c7_d63)) {
                emlrtIntegerCheckR2012b(c7_d63, &c7_gf_emlrtDCI, &c7_c_st);
              }

              c7_i90 = (int32_T)c7_d63;
              if ((c7_i90 < 1) || (c7_i90 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c7_i90, 1, 9601, &c7_ef_emlrtBCI,
                  &c7_c_st);
              }

              if (chartInstance->c7_P[c7_i90 - 1] < c7_k_i) {
                c7_d69 = c7_k_i + 1.0;
                if (c7_d69 != (real_T)(int32_T)muDoubleScalarFloor(c7_d69)) {
                  emlrtIntegerCheckR2012b(c7_d69, &c7_jf_emlrtDCI, &c7_c_st);
                }

                c7_i98 = (int32_T)c7_d69;
                if ((c7_i98 < 1) || (c7_i98 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i98, 1, 9601, &c7_hf_emlrtBCI,
                    &c7_c_st);
                }

                c7_d_j = chartInstance->c7_P[c7_i98 - 1];
                c7_d76 = c7_k_i + 1.0;
                if (c7_d76 != (real_T)(int32_T)muDoubleScalarFloor(c7_d76)) {
                  emlrtIntegerCheckR2012b(c7_d76, &c7_md_emlrtDCI, &c7_c_st);
                }

                c7_i107 = (int32_T)c7_d76;
                if ((c7_i107 < 1) || (c7_i107 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i107, 1, 9601,
                    &c7_kd_emlrtBCI, &c7_c_st);
                }

                chartInstance->c7_P[c7_i107 - 1] = c7_root;
                c7_k_i = c7_d_j;
              } else {
                c7_exitg1 = 1;
              }
            } while (c7_exitg1 == 0);

            c7_d73 = c7_k_i + 1.0;
            if (c7_d73 != (real_T)(int32_T)muDoubleScalarFloor(c7_d73)) {
              emlrtIntegerCheckR2012b(c7_d73, &c7_nd_emlrtDCI, &c7_c_st);
            }

            c7_i104 = (int32_T)c7_d73;
            if ((c7_i104 < 1) || (c7_i104 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c7_i104, 1, 9601, &c7_ld_emlrtBCI,
                &c7_c_st);
            }

            chartInstance->c7_P[c7_i104 - 1] = c7_root;
            if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
              emlrtIntegerCheckR2012b(c7_b_r, &c7_fd_emlrtDCI, &c7_st);
            }

            c7_i112 = (int32_T)c7_b_r;
            if ((c7_i112 < 1) || (c7_i112 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c7_i112, 1, 120, &c7_dd_emlrtBCI,
                &c7_st);
            }

            c7_d83 = (real_T)c7_c;
            if (c7_d83 != (real_T)(int32_T)muDoubleScalarFloor(c7_d83)) {
              emlrtIntegerCheckR2012b(c7_d83, &c7_gd_emlrtDCI, &c7_st);
            }

            if (((int32_T)muDoubleScalarFloor(c7_d83) < 1) || ((int32_T)
                 muDoubleScalarFloor(c7_d83) > 160)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)muDoubleScalarFloor(c7_d83),
                1, 160, &c7_ed_emlrtBCI, &c7_st);
            }

            c7_b_L[(c7_i112 + 120 * ((int32_T)muDoubleScalarFloor(c7_d83) - 1))
              - 1] = c7_d41;
          }
        }

        if (c7_b_r < 120.0) {
          c7_d7 = c7_b_r + 1.0;
          if (c7_d7 != (real_T)(int32_T)muDoubleScalarFloor(c7_d7)) {
            emlrtIntegerCheckR2012b(c7_d7, &c7_yd_emlrtDCI, &c7_st);
          }

          c7_i12 = (int32_T)c7_d7;
          if ((c7_i12 < 1) || (c7_i12 > 120)) {
            emlrtDynamicBoundsCheckR2012b(c7_i12, 1, 120, &c7_wd_emlrtBCI,
              &c7_st);
          }

          c7_e_q0 = c7_c;
          c7_e_q1 = 1;
          if ((c7_e_q1 < 0) && (c7_e_q0 > c7_e_q1 + MAX_int32_T)) {
            c7_e_qY = MAX_int32_T;
          } else if ((c7_e_q1 > 0) && (c7_e_q0 < c7_e_q1 + MIN_int32_T)) {
            c7_e_qY = MIN_int32_T;
          } else {
            c7_e_qY = c7_e_q0 - c7_e_q1;
          }

          c7_d12 = (real_T)c7_e_qY;
          if (c7_d12 != (real_T)(int32_T)muDoubleScalarFloor(c7_d12)) {
            emlrtIntegerCheckR2012b(c7_d12, &c7_ae_emlrtDCI, &c7_st);
          }

          c7_i18 = (int32_T)muDoubleScalarFloor(c7_d12);
          if ((c7_i18 < 1) || (c7_i18 > 160)) {
            emlrtDynamicBoundsCheckR2012b(c7_i18, 1, 160, &c7_xd_emlrtBCI,
              &c7_st);
          }

          c7_d16 = c7_b_L[(c7_i12 + 120 * (c7_i18 - 1)) - 1];
          c7_b_st.site = &c7_dc_emlrtRSI;
          c7_x_x = c7_d16;
          c7_ab_x = c7_x_x;
          c7_d_b = muDoubleScalarIsNaN(c7_ab_x);
          if (c7_d_b) {
            c7_g_y = NULL;
            sf_mex_assign(&c7_g_y, sf_mex_create("y", c7_cv, 10, 0U, 1, 0U, 2, 1,
              19), false);
            c7_j_y = NULL;
            sf_mex_assign(&c7_j_y, sf_mex_create("y", c7_cv, 10, 0U, 1, 0U, 2, 1,
              19), false);
            sf_mex_call(&c7_b_st, &c7_d_emlrtMCI, "error", 0U, 2U, 14, c7_g_y,
                        14, sf_mex_call(&c7_b_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c7_b_st, NULL, "message", 1U, 1U, 14, c7_j_y)));
          }

          if (c7_d16 != 0.0) {
            c7_b_st.site = &c7_ec_emlrtRSI;
            c7_d20 = c7_b_r + 1.0;
            if (c7_d20 != (real_T)(int32_T)muDoubleScalarFloor(c7_d20)) {
              emlrtIntegerCheckR2012b(c7_d20, &c7_ie_emlrtDCI, &c7_b_st);
            }

            c7_i27 = (int32_T)c7_d20;
            if ((c7_i27 < 1) || (c7_i27 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c7_i27, 1, 120, &c7_ge_emlrtBCI,
                &c7_b_st);
            }

            c7_k_q0 = c7_c;
            c7_k_q1 = 1;
            if ((c7_k_q1 < 0) && (c7_k_q0 > c7_k_q1 + MAX_int32_T)) {
              c7_k_qY = MAX_int32_T;
            } else if ((c7_k_q1 > 0) && (c7_k_q0 < c7_k_q1 + MIN_int32_T)) {
              c7_k_qY = MIN_int32_T;
            } else {
              c7_k_qY = c7_k_q0 - c7_k_q1;
            }

            c7_d23 = (real_T)c7_k_qY;
            if (c7_d23 != (real_T)(int32_T)muDoubleScalarFloor(c7_d23)) {
              emlrtIntegerCheckR2012b(c7_d23, &c7_je_emlrtDCI, &c7_b_st);
            }

            c7_i34 = (int32_T)muDoubleScalarFloor(c7_d23);
            if ((c7_i34 < 1) || (c7_i34 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c7_i34, 1, 160, &c7_he_emlrtBCI,
                &c7_b_st);
            }

            c7_d_i = c7_b_L[(c7_i27 + 120 * (c7_i34 - 1)) - 1];
            if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
              emlrtIntegerCheckR2012b(c7_b_r, &c7_ke_emlrtDCI, &c7_b_st);
            }

            c7_i40 = (int32_T)c7_b_r;
            if ((c7_i40 < 1) || (c7_i40 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c7_i40, 1, 120, &c7_ie_emlrtBCI,
                &c7_b_st);
            }

            c7_d36 = (real_T)c7_c;
            if (c7_d36 != (real_T)(int32_T)muDoubleScalarFloor(c7_d36)) {
              emlrtIntegerCheckR2012b(c7_d36, &c7_le_emlrtDCI, &c7_b_st);
            }

            c7_i52 = (int32_T)muDoubleScalarFloor(c7_d36);
            if ((c7_i52 < 1) || (c7_i52 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c7_i52, 1, 160, &c7_je_emlrtBCI,
                &c7_b_st);
            }

            c7_c_j = c7_b_L[(c7_i40 + 120 * (c7_i52 - 1)) - 1];
            c7_c_st.site = &c7_sb_emlrtRSI;
            c7_h_i = c7_d_i;
            c7_d46 = c7_h_i;
            do {
              c7_exitg1 = 0;
              c7_d52 = c7_d46 + 1.0;
              if (c7_d52 != (real_T)(int32_T)muDoubleScalarFloor(c7_d52)) {
                emlrtIntegerCheckR2012b(c7_d52, &c7_qe_emlrtDCI, &c7_c_st);
              }

              c7_i69 = (int32_T)c7_d52;
              if ((c7_i69 < 1) || (c7_i69 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c7_i69, 1, 9601, &c7_oe_emlrtBCI,
                  &c7_c_st);
              }

              if (chartInstance->c7_P[c7_i69 - 1] < c7_d46) {
                c7_d58 = c7_d46 + 1.0;
                if (c7_d58 != (real_T)(int32_T)muDoubleScalarFloor(c7_d58)) {
                  emlrtIntegerCheckR2012b(c7_d58, &c7_re_emlrtDCI, &c7_c_st);
                }

                c7_i81 = (int32_T)c7_d58;
                if ((c7_i81 < 1) || (c7_i81 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i81, 1, 9601, &c7_pe_emlrtBCI,
                    &c7_c_st);
                }

                c7_d46 = chartInstance->c7_P[c7_i81 - 1];
              } else {
                c7_exitg1 = 1;
              }
            } while (c7_exitg1 == 0);

            if (c7_d_i != c7_c_j) {
              c7_c_st.site = &c7_tb_emlrtRSI;
              c7_m_i = c7_c_j;
              c7_c_rootj = c7_m_i;
              do {
                c7_exitg1 = 0;
                c7_d65 = c7_c_rootj + 1.0;
                if (c7_d65 != (real_T)(int32_T)muDoubleScalarFloor(c7_d65)) {
                  emlrtIntegerCheckR2012b(c7_d65, &c7_qe_emlrtDCI, &c7_c_st);
                }

                c7_i92 = (int32_T)c7_d65;
                if ((c7_i92 < 1) || (c7_i92 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i92, 1, 9601, &c7_oe_emlrtBCI,
                    &c7_c_st);
                }

                if (chartInstance->c7_P[c7_i92 - 1] < c7_c_rootj) {
                  c7_d71 = c7_c_rootj + 1.0;
                  if (c7_d71 != (real_T)(int32_T)muDoubleScalarFloor(c7_d71)) {
                    emlrtIntegerCheckR2012b(c7_d71, &c7_re_emlrtDCI, &c7_c_st);
                  }

                  c7_i101 = (int32_T)c7_d71;
                  if ((c7_i101 < 1) || (c7_i101 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i101, 1, 9601,
                      &c7_pe_emlrtBCI, &c7_c_st);
                  }

                  c7_c_rootj = chartInstance->c7_P[c7_i101 - 1];
                } else {
                  c7_exitg1 = 1;
                }
              } while (c7_exitg1 == 0);

              if (c7_d46 > c7_c_rootj) {
                c7_d46 = c7_c_rootj;
              }

              c7_c_st.site = &c7_ub_emlrtRSI;
              c7_q_i = c7_c_j;
              c7_f_root = c7_d46;
              do {
                c7_exitg1 = 0;
                c7_d82 = c7_q_i + 1.0;
                if (c7_d82 != (real_T)(int32_T)muDoubleScalarFloor(c7_d82)) {
                  emlrtIntegerCheckR2012b(c7_d82, &c7_gf_emlrtDCI, &c7_c_st);
                }

                c7_i117 = (int32_T)c7_d82;
                if ((c7_i117 < 1) || (c7_i117 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i117, 1, 9601,
                    &c7_ef_emlrtBCI, &c7_c_st);
                }

                if (chartInstance->c7_P[c7_i117 - 1] < c7_q_i) {
                  c7_d88 = c7_q_i + 1.0;
                  if (c7_d88 != (real_T)(int32_T)muDoubleScalarFloor(c7_d88)) {
                    emlrtIntegerCheckR2012b(c7_d88, &c7_jf_emlrtDCI, &c7_c_st);
                  }

                  c7_i123 = (int32_T)c7_d88;
                  if ((c7_i123 < 1) || (c7_i123 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i123, 1, 9601,
                      &c7_hf_emlrtBCI, &c7_c_st);
                  }

                  c7_i_j = chartInstance->c7_P[c7_i123 - 1];
                  c7_d95 = c7_q_i + 1.0;
                  if (c7_d95 != (real_T)(int32_T)muDoubleScalarFloor(c7_d95)) {
                    emlrtIntegerCheckR2012b(c7_d95, &c7_md_emlrtDCI, &c7_c_st);
                  }

                  c7_i132 = (int32_T)c7_d95;
                  if ((c7_i132 < 1) || (c7_i132 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c7_i132, 1, 9601,
                      &c7_kd_emlrtBCI, &c7_c_st);
                  }

                  chartInstance->c7_P[c7_i132 - 1] = c7_f_root;
                  c7_q_i = c7_i_j;
                } else {
                  c7_exitg1 = 1;
                }
              } while (c7_exitg1 == 0);

              c7_d92 = c7_q_i + 1.0;
              if (c7_d92 != (real_T)(int32_T)muDoubleScalarFloor(c7_d92)) {
                emlrtIntegerCheckR2012b(c7_d92, &c7_nd_emlrtDCI, &c7_c_st);
              }

              c7_i127 = (int32_T)c7_d92;
              if ((c7_i127 < 1) || (c7_i127 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c7_i127, 1, 9601, &c7_ld_emlrtBCI,
                  &c7_c_st);
              }

              chartInstance->c7_P[c7_i127 - 1] = c7_f_root;
            }

            c7_c_st.site = &c7_vb_emlrtRSI;
            c7_n_i = c7_d_i;
            c7_c_root = c7_d46;
            do {
              c7_exitg1 = 0;
              c7_d66 = c7_n_i + 1.0;
              if (c7_d66 != (real_T)(int32_T)muDoubleScalarFloor(c7_d66)) {
                emlrtIntegerCheckR2012b(c7_d66, &c7_gf_emlrtDCI, &c7_c_st);
              }

              c7_i93 = (int32_T)c7_d66;
              if ((c7_i93 < 1) || (c7_i93 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c7_i93, 1, 9601, &c7_ef_emlrtBCI,
                  &c7_c_st);
              }

              if (chartInstance->c7_P[c7_i93 - 1] < c7_n_i) {
                c7_d72 = c7_n_i + 1.0;
                if (c7_d72 != (real_T)(int32_T)muDoubleScalarFloor(c7_d72)) {
                  emlrtIntegerCheckR2012b(c7_d72, &c7_jf_emlrtDCI, &c7_c_st);
                }

                c7_i103 = (int32_T)c7_d72;
                if ((c7_i103 < 1) || (c7_i103 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i103, 1, 9601,
                    &c7_hf_emlrtBCI, &c7_c_st);
                }

                c7_f_j = chartInstance->c7_P[c7_i103 - 1];
                c7_d79 = c7_n_i + 1.0;
                if (c7_d79 != (real_T)(int32_T)muDoubleScalarFloor(c7_d79)) {
                  emlrtIntegerCheckR2012b(c7_d79, &c7_md_emlrtDCI, &c7_c_st);
                }

                c7_i111 = (int32_T)c7_d79;
                if ((c7_i111 < 1) || (c7_i111 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i111, 1, 9601,
                    &c7_kd_emlrtBCI, &c7_c_st);
                }

                chartInstance->c7_P[c7_i111 - 1] = c7_c_root;
                c7_n_i = c7_f_j;
              } else {
                c7_exitg1 = 1;
              }
            } while (c7_exitg1 == 0);

            c7_d75 = c7_n_i + 1.0;
            if (c7_d75 != (real_T)(int32_T)muDoubleScalarFloor(c7_d75)) {
              emlrtIntegerCheckR2012b(c7_d75, &c7_nd_emlrtDCI, &c7_c_st);
            }

            c7_i106 = (int32_T)c7_d75;
            if ((c7_i106 < 1) || (c7_i106 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c7_i106, 1, 9601, &c7_ld_emlrtBCI,
                &c7_c_st);
            }

            chartInstance->c7_P[c7_i106 - 1] = c7_c_root;
            if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
              emlrtIntegerCheckR2012b(c7_b_r, &c7_hd_emlrtDCI, &c7_st);
            }

            c7_i116 = (int32_T)c7_b_r;
            if ((c7_i116 < 1) || (c7_i116 > 120)) {
              emlrtDynamicBoundsCheckR2012b(c7_i116, 1, 120, &c7_fd_emlrtBCI,
                &c7_st);
            }

            c7_d87 = (real_T)c7_c;
            if (c7_d87 != (real_T)(int32_T)muDoubleScalarFloor(c7_d87)) {
              emlrtIntegerCheckR2012b(c7_d87, &c7_id_emlrtDCI, &c7_st);
            }

            if (((int32_T)muDoubleScalarFloor(c7_d87) < 1) || ((int32_T)
                 muDoubleScalarFloor(c7_d87) > 160)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)muDoubleScalarFloor(c7_d87),
                1, 160, &c7_gd_emlrtBCI, &c7_st);
            }

            c7_b_L[(c7_i116 + 120 * ((int32_T)muDoubleScalarFloor(c7_d87) - 1))
              - 1] = c7_d46;
          }
        }

        if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
          emlrtIntegerCheckR2012b(c7_b_r, &c7_ce_emlrtDCI, &c7_st);
        }

        c7_i11 = (int32_T)c7_b_r;
        if ((c7_i11 < 1) || (c7_i11 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c7_i11, 1, 120, &c7_ae_emlrtBCI, &c7_st);
        }

        c7_d_q0 = c7_c;
        c7_d_q1 = 1;
        if ((c7_d_q1 < 0) && (c7_d_q0 > c7_d_q1 + MAX_int32_T)) {
          c7_d_qY = MAX_int32_T;
        } else if ((c7_d_q1 > 0) && (c7_d_q0 < c7_d_q1 + MIN_int32_T)) {
          c7_d_qY = MIN_int32_T;
        } else {
          c7_d_qY = c7_d_q0 - c7_d_q1;
        }

        c7_d11 = (real_T)c7_d_qY;
        if (c7_d11 != (real_T)(int32_T)muDoubleScalarFloor(c7_d11)) {
          emlrtIntegerCheckR2012b(c7_d11, &c7_de_emlrtDCI, &c7_st);
        }

        c7_i17 = (int32_T)muDoubleScalarFloor(c7_d11);
        if ((c7_i17 < 1) || (c7_i17 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c7_i17, 1, 160, &c7_be_emlrtBCI, &c7_st);
        }

        c7_d15 = c7_b_L[(c7_i11 + 120 * (c7_i17 - 1)) - 1];
        c7_b_st.site = &c7_fc_emlrtRSI;
        c7_w_x = c7_d15;
        c7_y_x = c7_w_x;
        c7_c_b = muDoubleScalarIsNaN(c7_y_x);
        if (c7_c_b) {
          c7_f_y = NULL;
          sf_mex_assign(&c7_f_y, sf_mex_create("y", c7_cv, 10, 0U, 1, 0U, 2, 1,
            19), false);
          c7_i_y = NULL;
          sf_mex_assign(&c7_i_y, sf_mex_create("y", c7_cv, 10, 0U, 1, 0U, 2, 1,
            19), false);
          sf_mex_call(&c7_b_st, &c7_d_emlrtMCI, "error", 0U, 2U, 14, c7_f_y, 14,
                      sf_mex_call(&c7_b_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c7_b_st, NULL, "message", 1U, 1U, 14, c7_i_y)));
        }

        if (c7_d15 != 0.0) {
          c7_b_st.site = &c7_gc_emlrtRSI;
          if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
            emlrtIntegerCheckR2012b(c7_b_r, &c7_me_emlrtDCI, &c7_b_st);
          }

          c7_i26 = (int32_T)c7_b_r;
          if ((c7_i26 < 1) || (c7_i26 > 120)) {
            emlrtDynamicBoundsCheckR2012b(c7_i26, 1, 120, &c7_ke_emlrtBCI,
              &c7_b_st);
          }

          c7_j_q0 = c7_c;
          c7_j_q1 = 1;
          if ((c7_j_q1 < 0) && (c7_j_q0 > c7_j_q1 + MAX_int32_T)) {
            c7_j_qY = MAX_int32_T;
          } else if ((c7_j_q1 > 0) && (c7_j_q0 < c7_j_q1 + MIN_int32_T)) {
            c7_j_qY = MIN_int32_T;
          } else {
            c7_j_qY = c7_j_q0 - c7_j_q1;
          }

          c7_d22 = (real_T)c7_j_qY;
          if (c7_d22 != (real_T)(int32_T)muDoubleScalarFloor(c7_d22)) {
            emlrtIntegerCheckR2012b(c7_d22, &c7_ne_emlrtDCI, &c7_b_st);
          }

          c7_i33 = (int32_T)muDoubleScalarFloor(c7_d22);
          if ((c7_i33 < 1) || (c7_i33 > 160)) {
            emlrtDynamicBoundsCheckR2012b(c7_i33, 1, 160, &c7_le_emlrtBCI,
              &c7_b_st);
          }

          c7_c_i = c7_b_L[(c7_i26 + 120 * (c7_i33 - 1)) - 1];
          if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
            emlrtIntegerCheckR2012b(c7_b_r, &c7_oe_emlrtDCI, &c7_b_st);
          }

          c7_i38 = (int32_T)c7_b_r;
          if ((c7_i38 < 1) || (c7_i38 > 120)) {
            emlrtDynamicBoundsCheckR2012b(c7_i38, 1, 120, &c7_me_emlrtBCI,
              &c7_b_st);
          }

          c7_d34 = (real_T)c7_c;
          if (c7_d34 != (real_T)(int32_T)muDoubleScalarFloor(c7_d34)) {
            emlrtIntegerCheckR2012b(c7_d34, &c7_pe_emlrtDCI, &c7_b_st);
          }

          c7_i49 = (int32_T)muDoubleScalarFloor(c7_d34);
          if ((c7_i49 < 1) || (c7_i49 > 160)) {
            emlrtDynamicBoundsCheckR2012b(c7_i49, 1, 160, &c7_ne_emlrtBCI,
              &c7_b_st);
          }

          c7_b_j = c7_b_L[(c7_i38 + 120 * (c7_i49 - 1)) - 1];
          c7_c_st.site = &c7_sb_emlrtRSI;
          c7_g_i = c7_c_i;
          c7_d43 = c7_g_i;
          do {
            c7_exitg1 = 0;
            c7_d49 = c7_d43 + 1.0;
            if (c7_d49 != (real_T)(int32_T)muDoubleScalarFloor(c7_d49)) {
              emlrtIntegerCheckR2012b(c7_d49, &c7_qe_emlrtDCI, &c7_c_st);
            }

            c7_i66 = (int32_T)c7_d49;
            if ((c7_i66 < 1) || (c7_i66 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c7_i66, 1, 9601, &c7_oe_emlrtBCI,
                &c7_c_st);
            }

            if (chartInstance->c7_P[c7_i66 - 1] < c7_d43) {
              c7_d56 = c7_d43 + 1.0;
              if (c7_d56 != (real_T)(int32_T)muDoubleScalarFloor(c7_d56)) {
                emlrtIntegerCheckR2012b(c7_d56, &c7_re_emlrtDCI, &c7_c_st);
              }

              c7_i79 = (int32_T)c7_d56;
              if ((c7_i79 < 1) || (c7_i79 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c7_i79, 1, 9601, &c7_pe_emlrtBCI,
                  &c7_c_st);
              }

              c7_d43 = chartInstance->c7_P[c7_i79 - 1];
            } else {
              c7_exitg1 = 1;
            }
          } while (c7_exitg1 == 0);

          if (c7_c_i != c7_b_j) {
            c7_c_st.site = &c7_tb_emlrtRSI;
            c7_j_i = c7_b_j;
            c7_b_rootj = c7_j_i;
            do {
              c7_exitg1 = 0;
              c7_d62 = c7_b_rootj + 1.0;
              if (c7_d62 != (real_T)(int32_T)muDoubleScalarFloor(c7_d62)) {
                emlrtIntegerCheckR2012b(c7_d62, &c7_qe_emlrtDCI, &c7_c_st);
              }

              c7_i89 = (int32_T)c7_d62;
              if ((c7_i89 < 1) || (c7_i89 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c7_i89, 1, 9601, &c7_oe_emlrtBCI,
                  &c7_c_st);
              }

              if (chartInstance->c7_P[c7_i89 - 1] < c7_b_rootj) {
                c7_d68 = c7_b_rootj + 1.0;
                if (c7_d68 != (real_T)(int32_T)muDoubleScalarFloor(c7_d68)) {
                  emlrtIntegerCheckR2012b(c7_d68, &c7_re_emlrtDCI, &c7_c_st);
                }

                c7_i97 = (int32_T)c7_d68;
                if ((c7_i97 < 1) || (c7_i97 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i97, 1, 9601, &c7_pe_emlrtBCI,
                    &c7_c_st);
                }

                c7_b_rootj = chartInstance->c7_P[c7_i97 - 1];
              } else {
                c7_exitg1 = 1;
              }
            } while (c7_exitg1 == 0);

            if (c7_d43 > c7_b_rootj) {
              c7_d43 = c7_b_rootj;
            }

            c7_c_st.site = &c7_ub_emlrtRSI;
            c7_p_i = c7_b_j;
            c7_e_root = c7_d43;
            do {
              c7_exitg1 = 0;
              c7_d81 = c7_p_i + 1.0;
              if (c7_d81 != (real_T)(int32_T)muDoubleScalarFloor(c7_d81)) {
                emlrtIntegerCheckR2012b(c7_d81, &c7_gf_emlrtDCI, &c7_c_st);
              }

              c7_i115 = (int32_T)c7_d81;
              if ((c7_i115 < 1) || (c7_i115 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c7_i115, 1, 9601, &c7_ef_emlrtBCI,
                  &c7_c_st);
              }

              if (chartInstance->c7_P[c7_i115 - 1] < c7_p_i) {
                c7_d86 = c7_p_i + 1.0;
                if (c7_d86 != (real_T)(int32_T)muDoubleScalarFloor(c7_d86)) {
                  emlrtIntegerCheckR2012b(c7_d86, &c7_jf_emlrtDCI, &c7_c_st);
                }

                c7_i121 = (int32_T)c7_d86;
                if ((c7_i121 < 1) || (c7_i121 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i121, 1, 9601,
                    &c7_hf_emlrtBCI, &c7_c_st);
                }

                c7_h_j = chartInstance->c7_P[c7_i121 - 1];
                c7_d94 = c7_p_i + 1.0;
                if (c7_d94 != (real_T)(int32_T)muDoubleScalarFloor(c7_d94)) {
                  emlrtIntegerCheckR2012b(c7_d94, &c7_md_emlrtDCI, &c7_c_st);
                }

                c7_i130 = (int32_T)c7_d94;
                if ((c7_i130 < 1) || (c7_i130 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c7_i130, 1, 9601,
                    &c7_kd_emlrtBCI, &c7_c_st);
                }

                chartInstance->c7_P[c7_i130 - 1] = c7_e_root;
                c7_p_i = c7_h_j;
              } else {
                c7_exitg1 = 1;
              }
            } while (c7_exitg1 == 0);

            c7_d91 = c7_p_i + 1.0;
            if (c7_d91 != (real_T)(int32_T)muDoubleScalarFloor(c7_d91)) {
              emlrtIntegerCheckR2012b(c7_d91, &c7_nd_emlrtDCI, &c7_c_st);
            }

            c7_i126 = (int32_T)c7_d91;
            if ((c7_i126 < 1) || (c7_i126 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c7_i126, 1, 9601, &c7_ld_emlrtBCI,
                &c7_c_st);
            }

            chartInstance->c7_P[c7_i126 - 1] = c7_e_root;
          }

          c7_c_st.site = &c7_vb_emlrtRSI;
          c7_l_i = c7_c_i;
          c7_b_root = c7_d43;
          do {
            c7_exitg1 = 0;
            c7_d64 = c7_l_i + 1.0;
            if (c7_d64 != (real_T)(int32_T)muDoubleScalarFloor(c7_d64)) {
              emlrtIntegerCheckR2012b(c7_d64, &c7_gf_emlrtDCI, &c7_c_st);
            }

            c7_i91 = (int32_T)c7_d64;
            if ((c7_i91 < 1) || (c7_i91 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c7_i91, 1, 9601, &c7_ef_emlrtBCI,
                &c7_c_st);
            }

            if (chartInstance->c7_P[c7_i91 - 1] < c7_l_i) {
              c7_d70 = c7_l_i + 1.0;
              if (c7_d70 != (real_T)(int32_T)muDoubleScalarFloor(c7_d70)) {
                emlrtIntegerCheckR2012b(c7_d70, &c7_jf_emlrtDCI, &c7_c_st);
              }

              c7_i100 = (int32_T)c7_d70;
              if ((c7_i100 < 1) || (c7_i100 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c7_i100, 1, 9601, &c7_hf_emlrtBCI,
                  &c7_c_st);
              }

              c7_e_j = chartInstance->c7_P[c7_i100 - 1];
              c7_d78 = c7_l_i + 1.0;
              if (c7_d78 != (real_T)(int32_T)muDoubleScalarFloor(c7_d78)) {
                emlrtIntegerCheckR2012b(c7_d78, &c7_md_emlrtDCI, &c7_c_st);
              }

              c7_i109 = (int32_T)c7_d78;
              if ((c7_i109 < 1) || (c7_i109 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c7_i109, 1, 9601, &c7_kd_emlrtBCI,
                  &c7_c_st);
              }

              chartInstance->c7_P[c7_i109 - 1] = c7_b_root;
              c7_l_i = c7_e_j;
            } else {
              c7_exitg1 = 1;
            }
          } while (c7_exitg1 == 0);

          c7_d74 = c7_l_i + 1.0;
          if (c7_d74 != (real_T)(int32_T)muDoubleScalarFloor(c7_d74)) {
            emlrtIntegerCheckR2012b(c7_d74, &c7_nd_emlrtDCI, &c7_c_st);
          }

          c7_i105 = (int32_T)c7_d74;
          if ((c7_i105 < 1) || (c7_i105 > 9601)) {
            emlrtDynamicBoundsCheckR2012b(c7_i105, 1, 9601, &c7_ld_emlrtBCI,
              &c7_c_st);
          }

          chartInstance->c7_P[c7_i105 - 1] = c7_b_root;
          if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
            emlrtIntegerCheckR2012b(c7_b_r, &c7_jd_emlrtDCI, &c7_st);
          }

          c7_i114 = (int32_T)c7_b_r;
          if ((c7_i114 < 1) || (c7_i114 > 120)) {
            emlrtDynamicBoundsCheckR2012b(c7_i114, 1, 120, &c7_hd_emlrtBCI,
              &c7_st);
          }

          c7_d84 = (real_T)c7_c;
          if (c7_d84 != (real_T)(int32_T)muDoubleScalarFloor(c7_d84)) {
            emlrtIntegerCheckR2012b(c7_d84, &c7_kd_emlrtDCI, &c7_st);
          }

          if (((int32_T)muDoubleScalarFloor(c7_d84) < 1) || ((int32_T)
               muDoubleScalarFloor(c7_d84) > 160)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)muDoubleScalarFloor(c7_d84),
              1, 160, &c7_id_emlrtBCI, &c7_st);
          }

          c7_b_L[(c7_i114 + 120 * ((int32_T)muDoubleScalarFloor(c7_d84) - 1)) -
            1] = c7_d43;
        }
      }
    }

    c7_d = (real_T)c7_c;
    if (c7_d != (real_T)(int32_T)muDoubleScalarFloor(c7_d)) {
      emlrtIntegerCheckR2012b(c7_d, &c7_od_emlrtDCI, &c7_st);
    }

    c7_i = (int32_T)muDoubleScalarFloor(c7_d);
    if ((c7_i < 1) || (c7_i > 168)) {
      emlrtDynamicBoundsCheckR2012b(c7_i, 1, 168, &c7_md_emlrtBCI, &c7_st);
    }

    c7_c = c7_chunksSizeAndLabels[c7_i - 1];
  }

  c7_b_numComponents = 1.0;
  c7_c = 1;
  while ((real_T)c7_c <= 160.0) {
    c7_q0 = c7_c;
    c7_q1 = 1;
    if ((c7_q1 < 0) && (c7_q0 > c7_q1 + MAX_int32_T)) {
      c7_qY = MAX_int32_T;
    } else if ((c7_q1 > 0) && (c7_q0 < c7_q1 + MIN_int32_T)) {
      c7_qY = MIN_int32_T;
    } else {
      c7_qY = c7_q0 - c7_q1;
    }

    c7_f_x = c7_qY;
    c7_g_x = c7_f_x;
    c7_h_x = c7_g_x;
    c7_i_x = c7_h_x;
    c7_c_a = c7_i_x;
    c7_j_x = c7_c_a;
    c7_z = (real_T)c7_j_x / 2.0;
    c7_d4 = muDoubleScalarRound(c7_z);
    if (c7_d4 < 2.147483648E+9) {
      if (c7_d4 >= -2.147483648E+9) {
        c7_i7 = (int32_T)c7_d4;
      } else {
        c7_i7 = MIN_int32_T;
      }
    } else if (c7_d4 >= 2.147483648E+9) {
      c7_i7 = MAX_int32_T;
    } else {
      c7_i7 = 0;
    }

    c7_b_z = c7_i7;
    c7_o_x = c7_b_z;
    c7_d_a = c7_o_x;
    c7_i9 = (int64_T)c7_d_a * 60LL;
    if (c7_i9 > 2147483647LL) {
      c7_i9 = 2147483647LL;
    } else if (c7_i9 < -2147483648LL) {
      c7_i9 = -2147483648LL;
    }

    c7_d_y = (int32_T)c7_i9;
    c7_c_q0 = c7_d_y;
    c7_c_q1 = 1;
    if ((c7_c_q1 < 0) && (c7_c_q0 < MIN_int32_T - c7_c_q1)) {
      c7_c_qY = MIN_int32_T;
    } else if ((c7_c_q1 > 0) && (c7_c_q0 > MAX_int32_T - c7_c_q1)) {
      c7_c_qY = MAX_int32_T;
    } else {
      c7_c_qY = c7_c_q0 + c7_c_q1;
    }

    c7_stripeFirstLabel = c7_c_qY;
    c7_f_q0 = c7_stripeFirstLabel;
    c7_f_q1 = 1;
    if ((c7_f_q1 < 0) && (c7_f_q0 < MIN_int32_T - c7_f_q1)) {
      c7_f_qY = MIN_int32_T;
    } else if ((c7_f_q1 > 0) && (c7_f_q0 > MAX_int32_T - c7_f_q1)) {
      c7_f_qY = MAX_int32_T;
    } else {
      c7_f_qY = c7_f_q0 + c7_f_q1;
    }

    c7_i19 = c7_f_qY;
    c7_g_q0 = c7_c;
    c7_g_q1 = 1;
    if ((c7_g_q1 < 0) && (c7_g_q0 < MIN_int32_T - c7_g_q1)) {
      c7_g_qY = MIN_int32_T;
    } else if ((c7_g_q1 > 0) && (c7_g_q0 > MAX_int32_T - c7_g_q1)) {
      c7_g_qY = MAX_int32_T;
    } else {
      c7_g_qY = c7_g_q0 + c7_g_q1;
    }

    c7_d18 = (real_T)c7_g_qY;
    if (c7_d18 != (real_T)(int32_T)muDoubleScalarFloor(c7_d18)) {
      emlrtIntegerCheckR2012b(c7_d18, &c7_be_emlrtDCI, &c7_st);
    }

    c7_i23 = (int32_T)muDoubleScalarFloor(c7_d18);
    if ((c7_i23 < 1) || (c7_i23 > 168)) {
      emlrtDynamicBoundsCheckR2012b(c7_i23, 1, 168, &c7_yd_emlrtBCI, &c7_st);
    }

    c7_h_q0 = c7_stripeFirstLabel;
    c7_h_q1 = c7_chunksSizeAndLabels[c7_i23 - 1];
    if ((c7_h_q0 < 0) && (c7_h_q1 < MIN_int32_T - c7_h_q0)) {
      c7_h_qY = MIN_int32_T;
    } else if ((c7_h_q0 > 0) && (c7_h_q1 > MAX_int32_T - c7_h_q0)) {
      c7_h_qY = MAX_int32_T;
    } else {
      c7_h_qY = c7_h_q0 + c7_h_q1;
    }

    c7_i29 = c7_h_qY;
    c7_b_st.site = &c7_hc_emlrtRSI;
    c7_f_a = c7_i19;
    c7_e_b = c7_i29;
    c7_g_a = c7_f_a;
    c7_f_b = c7_e_b;
    if (c7_g_a > c7_f_b) {
      c7_overflow = false;
    } else {
      c7_overflow = (c7_f_b > 2147483646);
    }

    if (c7_overflow) {
      c7_c_st.site = &c7_ic_emlrtRSI;
      c7_check_forloop_overflow_error(chartInstance, &c7_c_st, c7_overflow);
    }

    for (c7_e_i = c7_i19; c7_e_i <= c7_i29; c7_e_i++) {
      c7_d29 = (real_T)c7_e_i;
      if (c7_d29 != (real_T)(int32_T)muDoubleScalarFloor(c7_d29)) {
        emlrtIntegerCheckR2012b(c7_d29, &c7_te_emlrtDCI, &c7_st);
      }

      c7_i43 = (int32_T)muDoubleScalarFloor(c7_d29);
      if ((c7_i43 < 1) || (c7_i43 > 9601)) {
        emlrtDynamicBoundsCheckR2012b(c7_i43, 1, 9601, &c7_re_emlrtBCI, &c7_st);
      }

      c7_l_q0 = c7_e_i;
      c7_l_q1 = 1;
      if ((c7_l_q1 < 0) && (c7_l_q0 > c7_l_q1 + MAX_int32_T)) {
        c7_l_qY = MAX_int32_T;
      } else if ((c7_l_q1 > 0) && (c7_l_q0 < c7_l_q1 + MIN_int32_T)) {
        c7_l_qY = MIN_int32_T;
      } else {
        c7_l_qY = c7_l_q0 - c7_l_q1;
      }

      if (chartInstance->c7_P[c7_i43 - 1] < (real_T)c7_l_qY) {
        c7_d45 = (real_T)c7_e_i;
        if (c7_d45 != (real_T)(int32_T)muDoubleScalarFloor(c7_d45)) {
          emlrtIntegerCheckR2012b(c7_d45, &c7_ve_emlrtDCI, &c7_st);
        }

        c7_i61 = (int32_T)muDoubleScalarFloor(c7_d45);
        if ((c7_i61 < 1) || (c7_i61 > 9601)) {
          emlrtDynamicBoundsCheckR2012b(c7_i61, 1, 9601, &c7_te_emlrtBCI, &c7_st);
        }

        c7_d54 = chartInstance->c7_P[c7_i61 - 1] + 1.0;
        if (c7_d54 != (real_T)(int32_T)muDoubleScalarFloor(c7_d54)) {
          emlrtIntegerCheckR2012b(c7_d54, &c7_ue_emlrtDCI, &c7_st);
        }

        c7_i75 = (int32_T)c7_d54;
        if ((c7_i75 < 1) || (c7_i75 > 9601)) {
          emlrtDynamicBoundsCheckR2012b(c7_i75, 1, 9601, &c7_se_emlrtBCI, &c7_st);
        }

        c7_d59 = (real_T)c7_e_i;
        if (c7_d59 != (real_T)(int32_T)muDoubleScalarFloor(c7_d59)) {
          emlrtIntegerCheckR2012b(c7_d59, &c7_we_emlrtDCI, &c7_st);
        }

        c7_i83 = (int32_T)muDoubleScalarFloor(c7_d59);
        if ((c7_i83 < 1) || (c7_i83 > 9601)) {
          emlrtDynamicBoundsCheckR2012b(c7_i83, 1, 9601, &c7_ue_emlrtBCI, &c7_st);
        }

        chartInstance->c7_P[c7_i83 - 1] = chartInstance->c7_P[c7_i75 - 1];
      } else {
        c7_d44 = (real_T)c7_e_i;
        if (c7_d44 != (real_T)(int32_T)muDoubleScalarFloor(c7_d44)) {
          emlrtIntegerCheckR2012b(c7_d44, &c7_ld_emlrtDCI, &c7_st);
        }

        if (((int32_T)muDoubleScalarFloor(c7_d44) < 1) || ((int32_T)
             muDoubleScalarFloor(c7_d44) > 9601)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)muDoubleScalarFloor(c7_d44), 1,
            9601, &c7_jd_emlrtBCI, &c7_st);
        }

        chartInstance->c7_P[(int32_T)muDoubleScalarFloor(c7_d44) - 1] =
          c7_b_numComponents;
        c7_b_numComponents++;
      }
    }

    c7_d28 = (real_T)c7_c;
    if (c7_d28 != (real_T)(int32_T)muDoubleScalarFloor(c7_d28)) {
      emlrtIntegerCheckR2012b(c7_d28, &c7_se_emlrtDCI, &c7_st);
    }

    c7_i42 = (int32_T)muDoubleScalarFloor(c7_d28);
    if ((c7_i42 < 1) || (c7_i42 > 168)) {
      emlrtDynamicBoundsCheckR2012b(c7_i42, 1, 168, &c7_qe_emlrtBCI, &c7_st);
    }

    c7_c = c7_chunksSizeAndLabels[c7_i42 - 1];
  }

  c7_b_numComponents--;
  for (c7_c_c = 0; c7_c_c < 160; c7_c_c++) {
    c7_b_c = 1.0 + (real_T)c7_c_c;
    for (c7_c_r = 0; c7_c_r < 120; c7_c_r++) {
      c7_b_r = 1.0 + (real_T)c7_c_r;
      if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
        emlrtIntegerCheckR2012b(c7_b_r, &c7_sd_emlrtDCI, &c7_st);
      }

      c7_i4 = (int32_T)c7_b_r;
      if ((c7_i4 < 1) || (c7_i4 > 120)) {
        emlrtDynamicBoundsCheckR2012b(c7_i4, 1, 120, &c7_qd_emlrtBCI, &c7_st);
      }

      if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
        emlrtIntegerCheckR2012b(c7_b_c, &c7_td_emlrtDCI, &c7_st);
      }

      c7_i6 = (int32_T)c7_b_c;
      if ((c7_i6 < 1) || (c7_i6 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c7_i6, 1, 160, &c7_rd_emlrtBCI, &c7_st);
      }

      c7_d5 = c7_b_L[(c7_i4 + 120 * (c7_i6 - 1)) - 1] + 1.0;
      if (c7_d5 != (real_T)(int32_T)muDoubleScalarFloor(c7_d5)) {
        emlrtIntegerCheckR2012b(c7_d5, &c7_rd_emlrtDCI, &c7_st);
      }

      c7_i8 = (int32_T)c7_d5;
      if ((c7_i8 < 1) || (c7_i8 > 9601)) {
        emlrtDynamicBoundsCheckR2012b(c7_i8, 1, 9601, &c7_pd_emlrtBCI, &c7_st);
      }

      if (c7_b_r != (real_T)(int32_T)muDoubleScalarFloor(c7_b_r)) {
        emlrtIntegerCheckR2012b(c7_b_r, &c7_ud_emlrtDCI, &c7_st);
      }

      c7_i13 = (int32_T)c7_b_r;
      if ((c7_i13 < 1) || (c7_i13 > 120)) {
        emlrtDynamicBoundsCheckR2012b(c7_i13, 1, 120, &c7_sd_emlrtBCI, &c7_st);
      }

      if (c7_b_c != (real_T)(int32_T)muDoubleScalarFloor(c7_b_c)) {
        emlrtIntegerCheckR2012b(c7_b_c, &c7_vd_emlrtDCI, &c7_st);
      }

      c7_i14 = (int32_T)c7_b_c;
      if ((c7_i14 < 1) || (c7_i14 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c7_i14, 1, 160, &c7_td_emlrtBCI, &c7_st);
      }

      c7_b_L[(c7_i13 + 120 * (c7_i14 - 1)) - 1] = chartInstance->c7_P[c7_i8 - 1];
    }
  }

  *c7_numComponents = c7_b_numComponents;
}

static void c7_check_forloop_overflow_error
  (SFc7_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c7_sp, boolean_T c7_overflow)
{
  static char_T c7_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c7_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c7_b_y = NULL;
  const mxArray *c7_c_y = NULL;
  const mxArray *c7_y = NULL;
  (void)chartInstance;
  if (c7_overflow) {
    c7_y = NULL;
    sf_mex_assign(&c7_y, sf_mex_create("y", c7_b_cv, 10, 0U, 1, 0U, 2, 1, 34),
                  false);
    c7_b_y = NULL;
    sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_cv, 10, 0U, 1, 0U, 2, 1, 34),
                  false);
    c7_c_y = NULL;
    sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(c7_sp, &c7_e_emlrtMCI, "error", 0U, 2U, 14, c7_y, 14,
                sf_mex_call(c7_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c7_sp, NULL, "message", 1U, 2U, 14, c7_b_y, 14, c7_c_y)));
  }
}

static boolean_T c7_isequal(SFc7_flightControlSystemInstanceStruct
  *chartInstance, real_T c7_varargin_1[9], real_T c7_varargin_2[9])
{
  real_T c7_b_k;
  real_T c7_x1;
  real_T c7_x2;
  int32_T c7_k;
  boolean_T c7_b_p;
  boolean_T c7_c_p;
  boolean_T c7_exitg1;
  boolean_T c7_p;
  (void)chartInstance;
  c7_p = false;
  c7_b_p = true;
  c7_k = 0;
  c7_exitg1 = false;
  while ((!c7_exitg1) && (c7_k < 9)) {
    c7_b_k = 1.0 + (real_T)c7_k;
    c7_x1 = c7_varargin_1[(int32_T)c7_b_k - 1];
    c7_x2 = c7_varargin_2[(int32_T)c7_b_k - 1];
    c7_c_p = (c7_x1 == c7_x2);
    if (!c7_c_p) {
      c7_b_p = false;
      c7_exitg1 = true;
    } else {
      c7_k++;
    }
  }

  if (c7_b_p) {
    c7_p = true;
  }

  return c7_p;
}

static void c7_imclose(SFc7_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c7_sp, boolean_T c7_A[19200], boolean_T c7_d_B[19200])
{
  emlrtStack c7_b_st;
  emlrtStack c7_c_st;
  emlrtStack c7_d_st;
  emlrtStack c7_e_st;
  emlrtStack c7_f_st;
  emlrtStack c7_st;
  real_T c7_asizeT[2];
  real_T c7_nsizeT[2];
  real_T c7_b_a;
  real_T c7_b_k;
  real_T c7_c_a;
  real_T c7_c_i;
  real_T c7_c_j;
  real_T c7_d;
  real_T c7_d1;
  real_T c7_d2;
  real_T c7_d3;
  real_T c7_d4;
  real_T c7_d5;
  real_T c7_d6;
  real_T c7_d7;
  real_T c7_d8;
  real_T c7_d9;
  real_T c7_d_a;
  real_T c7_e_a;
  real_T c7_h_a;
  real_T c7_i_a;
  real_T c7_i_i;
  real_T c7_i_j;
  real_T c7_l_i;
  real_T c7_n_j;
  int32_T c7_b_c;
  int32_T c7_b_i;
  int32_T c7_b_j;
  int32_T c7_c;
  int32_T c7_c_c;
  int32_T c7_c_k;
  int32_T c7_d_c;
  int32_T c7_d_i;
  int32_T c7_d_j;
  int32_T c7_d_k;
  int32_T c7_e_c;
  int32_T c7_e_i;
  int32_T c7_e_j;
  int32_T c7_f_c;
  int32_T c7_f_i;
  int32_T c7_f_j;
  int32_T c7_g_i;
  int32_T c7_g_j;
  int32_T c7_h_i;
  int32_T c7_h_j;
  int32_T c7_i;
  int32_T c7_i1;
  int32_T c7_i10;
  int32_T c7_i11;
  int32_T c7_i12;
  int32_T c7_i13;
  int32_T c7_i14;
  int32_T c7_i15;
  int32_T c7_i16;
  int32_T c7_i17;
  int32_T c7_i18;
  int32_T c7_i19;
  int32_T c7_i2;
  int32_T c7_i20;
  int32_T c7_i21;
  int32_T c7_i22;
  int32_T c7_i23;
  int32_T c7_i24;
  int32_T c7_i25;
  int32_T c7_i26;
  int32_T c7_i27;
  int32_T c7_i28;
  int32_T c7_i29;
  int32_T c7_i3;
  int32_T c7_i30;
  int32_T c7_i31;
  int32_T c7_i32;
  int32_T c7_i33;
  int32_T c7_i34;
  int32_T c7_i35;
  int32_T c7_i36;
  int32_T c7_i37;
  int32_T c7_i38;
  int32_T c7_i39;
  int32_T c7_i4;
  int32_T c7_i40;
  int32_T c7_i41;
  int32_T c7_i42;
  int32_T c7_i43;
  int32_T c7_i44;
  int32_T c7_i45;
  int32_T c7_i46;
  int32_T c7_i47;
  int32_T c7_i48;
  int32_T c7_i49;
  int32_T c7_i5;
  int32_T c7_i50;
  int32_T c7_i51;
  int32_T c7_i52;
  int32_T c7_i53;
  int32_T c7_i54;
  int32_T c7_i55;
  int32_T c7_i56;
  int32_T c7_i57;
  int32_T c7_i58;
  int32_T c7_i59;
  int32_T c7_i6;
  int32_T c7_i60;
  int32_T c7_i61;
  int32_T c7_i62;
  int32_T c7_i63;
  int32_T c7_i7;
  int32_T c7_i8;
  int32_T c7_i9;
  int32_T c7_j;
  int32_T c7_j_i;
  int32_T c7_j_j;
  int32_T c7_k;
  int32_T c7_k_i;
  int32_T c7_k_j;
  int32_T c7_l_j;
  int32_T c7_m_i;
  int32_T c7_m_j;
  uint32_T c7_Apad[1020];
  uint32_T c7_e_B[1020];
  uint32_T c7_Apadpre[840];
  uint32_T c7_inputImage[664];
  uint32_T c7_outputImage[664];
  uint32_T c7_last_row[166];
  uint32_T c7_modified_last_row[166];
  uint32_T c7_b;
  uint32_T c7_b_b;
  uint32_T c7_b_varargin_2;
  uint32_T c7_b_y;
  uint32_T c7_c_b;
  uint32_T c7_d_b;
  uint32_T c7_f_a;
  uint32_T c7_g_a;
  uint32_T c7_mask_value;
  uint32_T c7_varargin_1;
  uint32_T c7_varargin_2;
  uint32_T c7_varargout_1;
  uint32_T c7_y;
  boolean_T c7_Ap[20916];
  boolean_T c7_nhood[3];
  boolean_T c7_b_nhood;
  boolean_T c7_c_nhood;
  c7_st.prev = c7_sp;
  c7_st.tls = c7_sp->tls;
  c7_st.site = &c7_pc_emlrtRSI;
  c7_b_st.prev = &c7_st;
  c7_b_st.tls = c7_st.tls;
  c7_c_st.prev = &c7_b_st;
  c7_c_st.tls = c7_b_st.tls;
  c7_d_st.prev = &c7_c_st;
  c7_d_st.tls = c7_c_st.tls;
  c7_e_st.prev = &c7_d_st;
  c7_e_st.tls = c7_d_st.tls;
  c7_f_st.prev = &c7_e_st;
  c7_f_st.tls = c7_e_st.tls;
  c7_b_st.site = &c7_t_emlrtRSI;
  for (c7_j = 0; c7_j < 3; c7_j++) {
    c7_c_j = 1.0 + (real_T)c7_j;
    for (c7_i = 0; c7_i < 126; c7_i++) {
      c7_c_i = 1.0 + (real_T)c7_i;
      if (c7_c_j != (real_T)(int32_T)muDoubleScalarFloor(c7_c_j)) {
        emlrtIntegerCheckR2012b(c7_c_j, &c7_kl_emlrtDCI, &c7_b_st);
      }

      c7_e_i = (int32_T)c7_c_j;
      if ((c7_e_i < 1) || (c7_e_i > 166)) {
        emlrtDynamicBoundsCheckR2012b(c7_e_i, 1, 166, &c7_ll_emlrtBCI, &c7_b_st);
      }

      if (c7_c_i != (real_T)(int32_T)muDoubleScalarFloor(c7_c_i)) {
        emlrtIntegerCheckR2012b(c7_c_i, &c7_d_emlrtDCI, &c7_b_st);
      }

      c7_i3 = (int32_T)c7_c_i;
      if ((c7_i3 < 1) || (c7_i3 > 126)) {
        emlrtDynamicBoundsCheckR2012b(c7_i3, 1, 126, &c7_ml_emlrtBCI, &c7_b_st);
      }

      c7_Ap[(c7_i3 + 126 * (c7_e_i - 1)) - 1] = false;
    }
  }

  for (c7_b_j = 0; c7_b_j < 3; c7_b_j++) {
    for (c7_b_i = 0; c7_b_i < 126; c7_b_i++) {
      c7_c_i = 1.0 + (real_T)c7_b_i;
      c7_d = (real_T)(c7_b_j + 164);
      if (c7_d != (real_T)(int32_T)muDoubleScalarFloor(c7_d)) {
        emlrtIntegerCheckR2012b(c7_d, &c7_jl_emlrtDCI, &c7_b_st);
      }

      c7_i1 = (int32_T)muDoubleScalarFloor(c7_d);
      if ((c7_i1 < 1) || (c7_i1 > 166)) {
        emlrtDynamicBoundsCheckR2012b(c7_i1, 1, 166, &c7_jl_emlrtBCI, &c7_b_st);
      }

      if (c7_c_i != (real_T)(int32_T)muDoubleScalarFloor(c7_c_i)) {
        emlrtIntegerCheckR2012b(c7_c_i, &c7_c_emlrtDCI, &c7_b_st);
      }

      c7_i6 = (int32_T)c7_c_i;
      if ((c7_i6 < 1) || (c7_i6 > 126)) {
        emlrtDynamicBoundsCheckR2012b(c7_i6, 1, 126, &c7_kl_emlrtBCI, &c7_b_st);
      }

      c7_Ap[(c7_i6 + 126 * (c7_i1 - 1)) - 1] = false;
    }
  }

  for (c7_d_j = 0; c7_d_j < 160; c7_d_j++) {
    c7_c_j = 1.0 + (real_T)c7_d_j;
    for (c7_d_i = 0; c7_d_i < 3; c7_d_i++) {
      c7_c_i = 1.0 + (real_T)c7_d_i;
      c7_b_a = c7_c_j;
      c7_c = (int32_T)c7_b_a;
      c7_d1 = (real_T)(c7_c + 3);
      if (c7_d1 != (real_T)(int32_T)muDoubleScalarFloor(c7_d1)) {
        emlrtIntegerCheckR2012b(c7_d1, &c7_b_emlrtDCI, &c7_b_st);
      }

      c7_i5 = (int32_T)muDoubleScalarFloor(c7_d1);
      if ((c7_i5 < 1) || (c7_i5 > 166)) {
        emlrtDynamicBoundsCheckR2012b(c7_i5, 1, 166, &c7_hl_emlrtBCI, &c7_b_st);
      }

      if (c7_c_i != (real_T)(int32_T)muDoubleScalarFloor(c7_c_i)) {
        emlrtIntegerCheckR2012b(c7_c_i, &c7_il_emlrtDCI, &c7_b_st);
      }

      c7_i9 = (int32_T)c7_c_i;
      if ((c7_i9 < 1) || (c7_i9 > 126)) {
        emlrtDynamicBoundsCheckR2012b(c7_i9, 1, 126, &c7_il_emlrtBCI, &c7_b_st);
      }

      c7_Ap[(c7_i9 + 126 * (c7_i5 - 1)) - 1] = false;
    }
  }

  for (c7_e_j = 0; c7_e_j < 160; c7_e_j++) {
    c7_c_j = 1.0 + (real_T)c7_e_j;
    for (c7_f_i = 0; c7_f_i < 3; c7_f_i++) {
      c7_c_a = c7_c_j;
      c7_b_c = (int32_T)c7_c_a;
      c7_d2 = (real_T)(c7_b_c + 3);
      if (c7_d2 != (real_T)(int32_T)muDoubleScalarFloor(c7_d2)) {
        emlrtIntegerCheckR2012b(c7_d2, &c7_emlrtDCI, &c7_b_st);
      }

      c7_i7 = (int32_T)muDoubleScalarFloor(c7_d2);
      if ((c7_i7 < 1) || (c7_i7 > 166)) {
        emlrtDynamicBoundsCheckR2012b(c7_i7, 1, 166, &c7_fl_emlrtBCI, &c7_b_st);
      }

      c7_d3 = (real_T)(c7_f_i + 124);
      if (c7_d3 != (real_T)(int32_T)muDoubleScalarFloor(c7_d3)) {
        emlrtIntegerCheckR2012b(c7_d3, &c7_hl_emlrtDCI, &c7_b_st);
      }

      c7_i10 = (int32_T)muDoubleScalarFloor(c7_d3);
      if ((c7_i10 < 1) || (c7_i10 > 126)) {
        emlrtDynamicBoundsCheckR2012b(c7_i10, 1, 126, &c7_gl_emlrtBCI, &c7_b_st);
      }

      c7_Ap[(c7_i10 + 126 * (c7_i7 - 1)) - 1] = false;
    }
  }

  for (c7_f_j = 0; c7_f_j < 160; c7_f_j++) {
    c7_c_j = 1.0 + (real_T)c7_f_j;
    for (c7_g_i = 0; c7_g_i < 120; c7_g_i++) {
      c7_c_i = 1.0 + (real_T)c7_g_i;
      c7_d_a = c7_c_i;
      c7_c_c = (int32_T)c7_d_a;
      c7_e_a = c7_c_j;
      c7_d_c = (int32_T)c7_e_a;
      if (c7_c_i != (real_T)(int32_T)muDoubleScalarFloor(c7_c_i)) {
        emlrtIntegerCheckR2012b(c7_c_i, &c7_k_emlrtDCI, &c7_b_st);
      }

      c7_i8 = (int32_T)c7_c_i;
      if ((c7_i8 < 1) || (c7_i8 > 120)) {
        emlrtDynamicBoundsCheckR2012b(c7_i8, 1, 120, &c7_k_emlrtBCI, &c7_b_st);
      }

      if (c7_c_j != (real_T)(int32_T)muDoubleScalarFloor(c7_c_j)) {
        emlrtIntegerCheckR2012b(c7_c_j, &c7_l_emlrtDCI, &c7_b_st);
      }

      c7_i12 = (int32_T)c7_c_j;
      if ((c7_i12 < 1) || (c7_i12 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c7_i12, 1, 160, &c7_l_emlrtBCI, &c7_b_st);
      }

      c7_d4 = (real_T)(c7_c_c + 3);
      if (c7_d4 != (real_T)(int32_T)muDoubleScalarFloor(c7_d4)) {
        emlrtIntegerCheckR2012b(c7_d4, &c7_w_emlrtDCI, &c7_b_st);
      }

      c7_i15 = (int32_T)muDoubleScalarFloor(c7_d4);
      if ((c7_i15 < 1) || (c7_i15 > 126)) {
        emlrtDynamicBoundsCheckR2012b(c7_i15, 1, 126, &c7_nl_emlrtBCI, &c7_b_st);
      }

      c7_d5 = (real_T)(c7_d_c + 3);
      if (c7_d5 != (real_T)(int32_T)muDoubleScalarFloor(c7_d5)) {
        emlrtIntegerCheckR2012b(c7_d5, &c7_x_emlrtDCI, &c7_b_st);
      }

      c7_i18 = (int32_T)muDoubleScalarFloor(c7_d5);
      if ((c7_i18 < 1) || (c7_i18 > 166)) {
        emlrtDynamicBoundsCheckR2012b(c7_i18, 1, 166, &c7_ol_emlrtBCI, &c7_b_st);
      }

      c7_Ap[(c7_i15 + 126 * (c7_i18 - 1)) - 1] = c7_A[(c7_i8 + 120 * (c7_i12 - 1))
        - 1];
    }
  }

  c7_st.site = &c7_qc_emlrtRSI;
  c7_b_st.site = &c7_tc_emlrtRSI;
  for (c7_i2 = 0; c7_i2 < 2; c7_i2++) {
    c7_asizeT[c7_i2] = 126.0 + 40.0 * (real_T)c7_i2;
  }

  for (c7_i4 = 0; c7_i4 < 2; c7_i4++) {
    c7_nsizeT[c7_i4] = 4.0 + 162.0 * (real_T)c7_i4;
  }

  bwPackingtbb(&c7_Ap[0], &c7_asizeT[0], &c7_inputImage[0], &c7_nsizeT[0], true);
  c7_st.site = &c7_rc_emlrtRSI;
  c7_b_st.site = &c7_uc_emlrtRSI;
  c7_c_st.site = &c7_vc_emlrtRSI;
  c7_d_st.site = &c7_wc_emlrtRSI;
  c7_e_st.site = &c7_xc_emlrtRSI;
  c7_mask_value = 0U;
  for (c7_k = 0; c7_k < 30; c7_k++) {
    c7_b_k = 1.0 + (real_T)c7_k;
    if (c7_b_k != (real_T)(int32_T)muDoubleScalarFloor(c7_b_k)) {
      emlrtIntegerCheckR2012b(c7_b_k, &c7_gl_emlrtDCI, &c7_e_st);
    }

    c7_i14 = (int32_T)c7_b_k;
    if ((c7_i14 < 1) || (c7_i14 > 30)) {
      emlrtDynamicBoundsCheckR2012b(c7_i14, 1, 30, &c7_el_emlrtBCI, &c7_e_st);
    }

    c7_f_st.site = &c7_cd_emlrtRSI;
    c7_mask_value = c7_bitset(chartInstance, &c7_f_st, c7_mask_value, 1.0 +
      (real_T)(c7_i14 - 1));
  }

  c7_i11 = 0;
  for (c7_i13 = 0; c7_i13 < 166; c7_i13++) {
    c7_last_row[c7_i13] = c7_inputImage[c7_i11 + 3];
    c7_i11 += 4;
  }

  c7_varargin_2 = c7_mask_value;
  c7_b = c7_varargin_2;
  c7_b_b = c7_b;
  c7_y = c7_b_b;
  c7_b_y = c7_y;
  for (c7_c_k = 0; c7_c_k < 166; c7_c_k++) {
    c7_d_k = c7_c_k;
    c7_varargin_1 = c7_last_row[c7_d_k];
    c7_b_varargin_2 = c7_b_y;
    c7_f_a = c7_varargin_1;
    c7_c_b = c7_b_varargin_2;
    c7_g_a = c7_f_a;
    c7_d_b = c7_c_b;
    c7_varargout_1 = c7_g_a & c7_d_b;
    c7_modified_last_row[c7_d_k] = c7_varargout_1;
  }

  c7_i16 = 0;
  for (c7_i17 = 0; c7_i17 < 166; c7_i17++) {
    c7_inputImage[c7_i16 + 3] = c7_modified_last_row[c7_i17];
    c7_i16 += 4;
  }

  c7_e_st.site = &c7_yc_emlrtRSI;
  c7_f_st.site = &c7_t_emlrtRSI;
  for (c7_g_j = 0; c7_g_j < 2; c7_g_j++) {
    c7_i_j = 1.0 + (real_T)c7_g_j;
    for (c7_h_i = 0; c7_h_i < 5; c7_h_i++) {
      c7_i_i = 1.0 + (real_T)c7_h_i;
      if (c7_i_j != (real_T)(int32_T)muDoubleScalarFloor(c7_i_j)) {
        emlrtIntegerCheckR2012b(c7_i_j, &c7_el_emlrtDCI, &c7_f_st);
      }

      c7_i20 = (int32_T)c7_i_j;
      if ((c7_i20 < 1) || (c7_i20 > 168)) {
        emlrtDynamicBoundsCheckR2012b(c7_i20, 1, 168, &c7_cl_emlrtBCI, &c7_f_st);
      }

      if (c7_i_i != (real_T)(int32_T)muDoubleScalarFloor(c7_i_i)) {
        emlrtIntegerCheckR2012b(c7_i_i, &c7_fl_emlrtDCI, &c7_f_st);
      }

      c7_i21 = (int32_T)c7_i_i;
      if ((c7_i21 < 1) || (c7_i21 > 5)) {
        emlrtDynamicBoundsCheckR2012b(c7_i21, 1, 5, &c7_dl_emlrtBCI, &c7_f_st);
      }

      c7_Apadpre[(c7_i21 + 5 * (c7_i20 - 1)) - 1] = 0U;
    }
  }

  for (c7_h_j = 0; c7_h_j < 166; c7_h_j++) {
    c7_d6 = (real_T)(c7_h_j + 3);
    if (c7_d6 != (real_T)(int32_T)muDoubleScalarFloor(c7_d6)) {
      emlrtIntegerCheckR2012b(c7_d6, &c7_dl_emlrtDCI, &c7_f_st);
    }

    c7_i19 = (int32_T)muDoubleScalarFloor(c7_d6);
    if ((c7_i19 < 1) || (c7_i19 > 168)) {
      emlrtDynamicBoundsCheckR2012b(c7_i19, 1, 168, &c7_bl_emlrtBCI, &c7_f_st);
    }

    c7_Apadpre[5 * (c7_i19 - 1)] = 0U;
  }

  for (c7_j_j = 0; c7_j_j < 166; c7_j_j++) {
    c7_i_j = 1.0 + (real_T)c7_j_j;
    for (c7_j_i = 0; c7_j_i < 4; c7_j_i++) {
      c7_i_i = 1.0 + (real_T)c7_j_i;
      c7_h_a = c7_i_i;
      c7_e_c = (int32_T)c7_h_a;
      c7_i_a = c7_i_j;
      c7_f_c = (int32_T)c7_i_a;
      if (c7_i_i != (real_T)(int32_T)muDoubleScalarFloor(c7_i_i)) {
        emlrtIntegerCheckR2012b(c7_i_i, &c7_k_emlrtDCI, &c7_f_st);
      }

      c7_i25 = (int32_T)c7_i_i;
      if ((c7_i25 < 1) || (c7_i25 > 4)) {
        emlrtDynamicBoundsCheckR2012b(c7_i25, 1, 4, &c7_pl_emlrtBCI, &c7_f_st);
      }

      if (c7_i_j != (real_T)(int32_T)muDoubleScalarFloor(c7_i_j)) {
        emlrtIntegerCheckR2012b(c7_i_j, &c7_l_emlrtDCI, &c7_f_st);
      }

      c7_i30 = (int32_T)c7_i_j;
      if ((c7_i30 < 1) || (c7_i30 > 166)) {
        emlrtDynamicBoundsCheckR2012b(c7_i30, 1, 166, &c7_ql_emlrtBCI, &c7_f_st);
      }

      c7_d8 = (real_T)(c7_e_c + 1);
      if (c7_d8 != (real_T)(int32_T)muDoubleScalarFloor(c7_d8)) {
        emlrtIntegerCheckR2012b(c7_d8, &c7_w_emlrtDCI, &c7_f_st);
      }

      c7_i34 = (int32_T)muDoubleScalarFloor(c7_d8);
      if ((c7_i34 < 1) || (c7_i34 > 5)) {
        emlrtDynamicBoundsCheckR2012b(c7_i34, 1, 5, &c7_rl_emlrtBCI, &c7_f_st);
      }

      c7_d9 = (real_T)(c7_f_c + 2);
      if (c7_d9 != (real_T)(int32_T)muDoubleScalarFloor(c7_d9)) {
        emlrtIntegerCheckR2012b(c7_d9, &c7_x_emlrtDCI, &c7_f_st);
      }

      c7_i38 = (int32_T)muDoubleScalarFloor(c7_d9);
      if ((c7_i38 < 1) || (c7_i38 > 168)) {
        emlrtDynamicBoundsCheckR2012b(c7_i38, 1, 168, &c7_sl_emlrtBCI, &c7_f_st);
      }

      c7_Apadpre[(c7_i34 + 5 * (c7_i38 - 1)) - 1] = c7_inputImage[(c7_i25 +
        ((c7_i30 - 1) << 2)) - 1];
    }
  }

  c7_e_st.site = &c7_ad_emlrtRSI;
  c7_f_st.site = &c7_t_emlrtRSI;
  for (c7_k_j = 0; c7_k_j < 2; c7_k_j++) {
    for (c7_k_i = 0; c7_k_i < 6; c7_k_i++) {
      c7_l_i = 1.0 + (real_T)c7_k_i;
      c7_d7 = (real_T)(c7_k_j + 169);
      if (c7_d7 != (real_T)(int32_T)muDoubleScalarFloor(c7_d7)) {
        emlrtIntegerCheckR2012b(c7_d7, &c7_bl_emlrtDCI, &c7_f_st);
      }

      c7_i24 = (int32_T)muDoubleScalarFloor(c7_d7);
      if ((c7_i24 < 1) || (c7_i24 > 170)) {
        emlrtDynamicBoundsCheckR2012b(c7_i24, 1, 170, &c7_yk_emlrtBCI, &c7_f_st);
      }

      if (c7_l_i != (real_T)(int32_T)muDoubleScalarFloor(c7_l_i)) {
        emlrtIntegerCheckR2012b(c7_l_i, &c7_cl_emlrtDCI, &c7_f_st);
      }

      c7_i29 = (int32_T)c7_l_i;
      if ((c7_i29 < 1) || (c7_i29 > 6)) {
        emlrtDynamicBoundsCheckR2012b(c7_i29, 1, 6, &c7_al_emlrtBCI, &c7_f_st);
      }

      c7_Apad[(c7_i29 + 6 * (c7_i24 - 1)) - 1] = 0U;
    }
  }

  for (c7_l_j = 0; c7_l_j < 168; c7_l_j++) {
    c7_n_j = 1.0 + (real_T)c7_l_j;
    if (c7_n_j != (real_T)(int32_T)muDoubleScalarFloor(c7_n_j)) {
      emlrtIntegerCheckR2012b(c7_n_j, &c7_al_emlrtDCI, &c7_f_st);
    }

    c7_i23 = (int32_T)c7_n_j;
    if ((c7_i23 < 1) || (c7_i23 > 170)) {
      emlrtDynamicBoundsCheckR2012b(c7_i23, 1, 170, &c7_xk_emlrtBCI, &c7_f_st);
    }

    c7_Apad[5 + 6 * (c7_i23 - 1)] = 0U;
  }

  for (c7_m_j = 0; c7_m_j < 168; c7_m_j++) {
    c7_n_j = 1.0 + (real_T)c7_m_j;
    for (c7_m_i = 0; c7_m_i < 5; c7_m_i++) {
      c7_l_i = 1.0 + (real_T)c7_m_i;
      if (c7_l_i != (real_T)(int32_T)muDoubleScalarFloor(c7_l_i)) {
        emlrtIntegerCheckR2012b(c7_l_i, &c7_ll_emlrtDCI, &c7_f_st);
      }

      c7_i28 = (int32_T)c7_l_i;
      if ((c7_i28 < 1) || (c7_i28 > 5)) {
        emlrtDynamicBoundsCheckR2012b(c7_i28, 1, 5, &c7_tl_emlrtBCI, &c7_f_st);
      }

      if (c7_n_j != (real_T)(int32_T)muDoubleScalarFloor(c7_n_j)) {
        emlrtIntegerCheckR2012b(c7_n_j, &c7_ml_emlrtDCI, &c7_f_st);
      }

      c7_i32 = (int32_T)c7_n_j;
      if ((c7_i32 < 1) || (c7_i32 > 168)) {
        emlrtDynamicBoundsCheckR2012b(c7_i32, 1, 168, &c7_ul_emlrtBCI, &c7_f_st);
      }

      if (c7_l_i != (real_T)(int32_T)muDoubleScalarFloor(c7_l_i)) {
        emlrtIntegerCheckR2012b(c7_l_i, &c7_nl_emlrtDCI, &c7_f_st);
      }

      c7_i36 = (int32_T)c7_l_i;
      if ((c7_i36 < 1) || (c7_i36 > 6)) {
        emlrtDynamicBoundsCheckR2012b(c7_i36, 1, 6, &c7_vl_emlrtBCI, &c7_f_st);
      }

      if (c7_n_j != (real_T)(int32_T)muDoubleScalarFloor(c7_n_j)) {
        emlrtIntegerCheckR2012b(c7_n_j, &c7_ol_emlrtDCI, &c7_f_st);
      }

      c7_i40 = (int32_T)c7_n_j;
      if ((c7_i40 < 1) || (c7_i40 > 170)) {
        emlrtDynamicBoundsCheckR2012b(c7_i40, 1, 170, &c7_wl_emlrtBCI, &c7_f_st);
      }

      c7_Apad[(c7_i36 + 6 * (c7_i40 - 1)) - 1] = c7_Apadpre[(c7_i28 + 5 *
        (c7_i32 - 1)) - 1];
    }
  }

  c7_e_st.site = &c7_bd_emlrtRSI;
  for (c7_i22 = 0; c7_i22 < 3; c7_i22++) {
    c7_nhood[c7_i22] = true;
  }

  for (c7_i26 = 0; c7_i26 < 2; c7_i26++) {
    c7_asizeT[c7_i26] = 6.0 + 164.0 * (real_T)c7_i26;
  }

  for (c7_i27 = 0; c7_i27 < 2; c7_i27++) {
    c7_nsizeT[c7_i27] = 3.0 + -2.0 * (real_T)c7_i27;
  }

  dilate_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0],
                       &c7_nsizeT[0], 2.0, &c7_e_B[0], true);
  c7_e_st.site = &c7_bd_emlrtRSI;
  for (c7_i31 = 0; c7_i31 < 1020; c7_i31++) {
    c7_Apad[c7_i31] = c7_e_B[c7_i31];
  }

  c7_b_nhood = true;
  for (c7_i33 = 0; c7_i33 < 2; c7_i33++) {
    c7_asizeT[c7_i33] = 6.0 + 164.0 * (real_T)c7_i33;
  }

  for (c7_i35 = 0; c7_i35 < 2; c7_i35++) {
    c7_nsizeT[c7_i35] = 1.0;
  }

  dilate_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_b_nhood, &c7_nsizeT
                       [0], 2.0, &c7_e_B[0], true);
  c7_e_st.site = &c7_bd_emlrtRSI;
  for (c7_i37 = 0; c7_i37 < 1020; c7_i37++) {
    c7_Apad[c7_i37] = c7_e_B[c7_i37];
  }

  for (c7_i39 = 0; c7_i39 < 3; c7_i39++) {
    c7_nhood[c7_i39] = true;
  }

  for (c7_i41 = 0; c7_i41 < 2; c7_i41++) {
    c7_asizeT[c7_i41] = 6.0 + 164.0 * (real_T)c7_i41;
  }

  for (c7_i42 = 0; c7_i42 < 2; c7_i42++) {
    c7_nsizeT[c7_i42] = 1.0 + 2.0 * (real_T)c7_i42;
  }

  dilate_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0],
                       &c7_nsizeT[0], 2.0, &c7_e_B[0], true);
  c7_e_st.site = &c7_bd_emlrtRSI;
  for (c7_i43 = 0; c7_i43 < 1020; c7_i43++) {
    c7_Apad[c7_i43] = c7_e_B[c7_i43];
  }

  c7_c_nhood = true;
  for (c7_i44 = 0; c7_i44 < 2; c7_i44++) {
    c7_asizeT[c7_i44] = 6.0 + 164.0 * (real_T)c7_i44;
  }

  for (c7_i45 = 0; c7_i45 < 2; c7_i45++) {
    c7_nsizeT[c7_i45] = 1.0;
  }

  dilate_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_c_nhood, &c7_nsizeT
                       [0], 2.0, &c7_e_B[0], true);
  c7_e_st.site = &c7_bd_emlrtRSI;
  for (c7_i46 = 0; c7_i46 < 1020; c7_i46++) {
    c7_Apad[c7_i46] = c7_e_B[c7_i46];
  }

  for (c7_i47 = 0; c7_i47 < 3; c7_i47++) {
    c7_nhood[c7_i47] = true;
  }

  for (c7_i48 = 0; c7_i48 < 2; c7_i48++) {
    c7_asizeT[c7_i48] = 6.0 + 164.0 * (real_T)c7_i48;
  }

  for (c7_i49 = 0; c7_i49 < 2; c7_i49++) {
    c7_nsizeT[c7_i49] = 1.0 + 2.0 * (real_T)c7_i49;
  }

  dilate_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0],
                       &c7_nsizeT[0], 2.0, &c7_e_B[0], true);
  c7_e_st.site = &c7_bd_emlrtRSI;
  for (c7_i50 = 0; c7_i50 < 1020; c7_i50++) {
    c7_Apad[c7_i50] = c7_e_B[c7_i50];
  }

  for (c7_i51 = 0; c7_i51 < 3; c7_i51++) {
    c7_nhood[c7_i51] = true;
  }

  for (c7_i52 = 0; c7_i52 < 2; c7_i52++) {
    c7_asizeT[c7_i52] = 6.0 + 164.0 * (real_T)c7_i52;
  }

  for (c7_i53 = 0; c7_i53 < 2; c7_i53++) {
    c7_nsizeT[c7_i53] = 3.0 + -2.0 * (real_T)c7_i53;
  }

  dilate_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0],
                       &c7_nsizeT[0], 2.0, &c7_e_B[0], true);
  c7_i54 = 0;
  c7_i55 = 0;
  for (c7_i56 = 0; c7_i56 < 166; c7_i56++) {
    for (c7_i57 = 0; c7_i57 < 4; c7_i57++) {
      c7_inputImage[c7_i57 + c7_i54] = c7_e_B[(c7_i57 + c7_i55) + 13];
    }

    c7_i54 += 4;
    c7_i55 += 6;
  }

  c7_st.site = &c7_rc_emlrtRSI;
  c7_imerode(chartInstance, &c7_st, c7_inputImage, c7_outputImage);
  c7_st.site = &c7_sc_emlrtRSI;
  c7_b_st.site = &c7_id_emlrtRSI;
  for (c7_i58 = 0; c7_i58 < 2; c7_i58++) {
    c7_nsizeT[c7_i58] = 4.0 + 162.0 * (real_T)c7_i58;
  }

  for (c7_i59 = 0; c7_i59 < 2; c7_i59++) {
    c7_asizeT[c7_i59] = 126.0 + 40.0 * (real_T)c7_i59;
  }

  bwUnpackingtbb(&c7_outputImage[0], &c7_nsizeT[0], &c7_Ap[0], &c7_asizeT[0],
                 true);
  c7_i60 = 0;
  c7_i61 = 0;
  for (c7_i62 = 0; c7_i62 < 160; c7_i62++) {
    for (c7_i63 = 0; c7_i63 < 120; c7_i63++) {
      c7_d_B[c7_i63 + c7_i60] = c7_Ap[(c7_i63 + c7_i61) + 381];
    }

    c7_i60 += 120;
    c7_i61 += 126;
  }
}

static uint32_T c7_bitset(SFc7_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c7_sp, uint32_T c7_b_a, real_T c7_bit)
{
  static char_T c7_b_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'b', 'i', 't',
    'S', 'e', 't', 'G', 'e', 't', ':', 'B', 'I', 'T', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  emlrtStack c7_b_st;
  emlrtStack c7_st;
  const mxArray *c7_b_y = NULL;
  const mxArray *c7_c_y = NULL;
  real_T c7_b_bit;
  real_T c7_b_x;
  real_T c7_c_bit;
  real_T c7_c_x;
  real_T c7_x;
  real_T c7_y;
  uint32_T c7_c_a;
  uint32_T c7_d_a;
  uint32_T c7_d_mask;
  uint8_T c7_b1;
  uint8_T c7_bm1;
  boolean_T c7_b;
  boolean_T c7_p;
  (void)chartInstance;
  c7_st.prev = c7_sp;
  c7_st.tls = c7_sp->tls;
  c7_b_st.prev = &c7_st;
  c7_b_st.tls = c7_st.tls;
  c7_st.site = &c7_dd_emlrtRSI;
  c7_c_a = c7_b_a;
  c7_b_bit = c7_bit;
  c7_x = c7_b_bit;
  c7_p = true;
  if ((c7_x >= 1.0) && (c7_x <= 32.0)) {
    c7_b_x = c7_x;
    c7_c_x = c7_b_x;
    c7_y = c7_c_x;
    c7_y = muDoubleScalarFloor(c7_y);
    if (c7_x == c7_y) {
      c7_b = true;
    } else {
      c7_b = false;
    }
  } else {
    c7_b = false;
  }

  if (!c7_b) {
    c7_p = false;
  }

  if (!c7_p) {
    c7_b_y = NULL;
    sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c7_c_y = NULL;
    sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c7_st, &c7_f_emlrtMCI, "error", 0U, 2U, 14, c7_b_y, 14,
                sf_mex_call(&c7_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c7_st, NULL, "message", 1U, 1U, 14, c7_c_y)));
  }

  c7_b_st.site = &c7_ed_emlrtRSI;
  c7_d_a = c7_c_a;
  c7_c_bit = c7_b_bit;
  c7_b1 = (uint8_T)((uint32_T)(uint8_T)c7_c_bit + 255U);
  c7_bm1 = c7_b1;
  if (c7_bm1 > 31) {
    emlrtDynamicBoundsCheckR2012b((int32_T)c7_bm1, 0, 31, &c7_xl_emlrtBCI,
      &c7_b_st);
  }

  c7_d_mask = 1U << c7_bm1;
  return c7_d_a | c7_d_mask;
}

static void c7_imerode(SFc7_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c7_sp, uint32_T c7_A[664], uint32_T c7_d_B[664])
{
  emlrtStack c7_b_st;
  emlrtStack c7_c_st;
  emlrtStack c7_d_st;
  emlrtStack c7_e_st;
  emlrtStack c7_st;
  real_T c7_asizeT[2];
  real_T c7_nsizeT[2];
  real_T c7_b_k;
  real_T c7_c_i;
  real_T c7_c_j;
  real_T c7_d;
  real_T c7_d1;
  real_T c7_d2;
  real_T c7_d3;
  real_T c7_f_a;
  real_T c7_f_i;
  real_T c7_g_a;
  real_T c7_h_j;
  int32_T c7_b_c;
  int32_T c7_b_i;
  int32_T c7_b_j;
  int32_T c7_c_c;
  int32_T c7_c_k;
  int32_T c7_d_i;
  int32_T c7_d_j;
  int32_T c7_d_k;
  int32_T c7_e_i;
  int32_T c7_e_j;
  int32_T c7_f_j;
  int32_T c7_g_i;
  int32_T c7_g_j;
  int32_T c7_i;
  int32_T c7_i1;
  int32_T c7_i10;
  int32_T c7_i11;
  int32_T c7_i12;
  int32_T c7_i13;
  int32_T c7_i14;
  int32_T c7_i15;
  int32_T c7_i16;
  int32_T c7_i17;
  int32_T c7_i18;
  int32_T c7_i19;
  int32_T c7_i2;
  int32_T c7_i20;
  int32_T c7_i21;
  int32_T c7_i22;
  int32_T c7_i23;
  int32_T c7_i24;
  int32_T c7_i25;
  int32_T c7_i26;
  int32_T c7_i27;
  int32_T c7_i28;
  int32_T c7_i29;
  int32_T c7_i3;
  int32_T c7_i30;
  int32_T c7_i31;
  int32_T c7_i32;
  int32_T c7_i33;
  int32_T c7_i34;
  int32_T c7_i35;
  int32_T c7_i36;
  int32_T c7_i37;
  int32_T c7_i38;
  int32_T c7_i39;
  int32_T c7_i4;
  int32_T c7_i40;
  int32_T c7_i41;
  int32_T c7_i42;
  int32_T c7_i43;
  int32_T c7_i44;
  int32_T c7_i5;
  int32_T c7_i6;
  int32_T c7_i7;
  int32_T c7_i8;
  int32_T c7_i9;
  int32_T c7_j;
  int32_T c7_k;
  uint32_T c7_Apad[1020];
  uint32_T c7_e_B[1020];
  uint32_T c7_Apadpre[840];
  uint32_T c7_b_A[664];
  uint32_T c7_last_row[166];
  uint32_T c7_modified_last_row[166];
  uint32_T c7_b;
  uint32_T c7_b_a;
  uint32_T c7_b_b;
  uint32_T c7_b_varargin_2;
  uint32_T c7_b_y;
  uint32_T c7_c;
  uint32_T c7_c_a;
  uint32_T c7_c_b;
  uint32_T c7_d_a;
  uint32_T c7_d_b;
  uint32_T c7_e_a;
  uint32_T c7_mask_value;
  uint32_T c7_varargin_1;
  uint32_T c7_varargin_2;
  uint32_T c7_varargout_1;
  uint32_T c7_y;
  boolean_T c7_nhood[3];
  boolean_T c7_b_nhood;
  boolean_T c7_c_nhood;
  c7_st.prev = c7_sp;
  c7_st.tls = c7_sp->tls;
  c7_st.site = &c7_gd_emlrtRSI;
  c7_b_st.prev = &c7_st;
  c7_b_st.tls = c7_st.tls;
  c7_c_st.prev = &c7_b_st;
  c7_c_st.tls = c7_b_st.tls;
  c7_d_st.prev = &c7_c_st;
  c7_d_st.tls = c7_c_st.tls;
  c7_e_st.prev = &c7_d_st;
  c7_e_st.tls = c7_d_st.tls;
  c7_b_st.site = &c7_vc_emlrtRSI;
  c7_c_st.site = &c7_wc_emlrtRSI;
  for (c7_i = 0; c7_i < 664; c7_i++) {
    c7_b_A[c7_i] = c7_A[c7_i];
  }

  c7_d_st.site = &c7_xc_emlrtRSI;
  c7_mask_value = 0U;
  for (c7_k = 0; c7_k < 30; c7_k++) {
    c7_b_k = 1.0 + (real_T)c7_k;
    if (c7_b_k != (real_T)(int32_T)muDoubleScalarFloor(c7_b_k)) {
      emlrtIntegerCheckR2012b(c7_b_k, &c7_gl_emlrtDCI, &c7_d_st);
    }

    c7_i3 = (int32_T)c7_b_k;
    if ((c7_i3 < 1) || (c7_i3 > 30)) {
      emlrtDynamicBoundsCheckR2012b(c7_i3, 1, 30, &c7_el_emlrtBCI, &c7_d_st);
    }

    c7_e_st.site = &c7_cd_emlrtRSI;
    c7_mask_value = c7_bitset(chartInstance, &c7_e_st, c7_mask_value, 1.0 +
      (real_T)(c7_i3 - 1));
  }

  c7_i1 = 0;
  for (c7_i2 = 0; c7_i2 < 166; c7_i2++) {
    c7_last_row[c7_i2] = c7_b_A[c7_i1 + 3];
    c7_i1 += 4;
  }

  c7_b_a = c7_mask_value;
  c7_c_a = c7_b_a;
  c7_c = ~c7_c_a;
  c7_varargin_2 = c7_c;
  c7_b = c7_varargin_2;
  c7_b_b = c7_b;
  c7_y = c7_b_b;
  c7_b_y = c7_y;
  for (c7_c_k = 0; c7_c_k < 166; c7_c_k++) {
    c7_d_k = c7_c_k;
    c7_varargin_1 = c7_last_row[c7_d_k];
    c7_b_varargin_2 = c7_b_y;
    c7_d_a = c7_varargin_1;
    c7_c_b = c7_b_varargin_2;
    c7_e_a = c7_d_a;
    c7_d_b = c7_c_b;
    c7_varargout_1 = c7_e_a | c7_d_b;
    c7_modified_last_row[c7_d_k] = c7_varargout_1;
  }

  c7_i4 = 0;
  for (c7_i5 = 0; c7_i5 < 166; c7_i5++) {
    c7_b_A[c7_i4 + 3] = c7_modified_last_row[c7_i5];
    c7_i4 += 4;
  }

  c7_d_st.site = &c7_yc_emlrtRSI;
  c7_e_st.site = &c7_t_emlrtRSI;
  for (c7_j = 0; c7_j < 2; c7_j++) {
    c7_c_j = 1.0 + (real_T)c7_j;
    for (c7_b_i = 0; c7_b_i < 5; c7_b_i++) {
      c7_c_i = 1.0 + (real_T)c7_b_i;
      if (c7_c_j != (real_T)(int32_T)muDoubleScalarFloor(c7_c_j)) {
        emlrtIntegerCheckR2012b(c7_c_j, &c7_el_emlrtDCI, &c7_e_st);
      }

      c7_i7 = (int32_T)c7_c_j;
      if ((c7_i7 < 1) || (c7_i7 > 168)) {
        emlrtDynamicBoundsCheckR2012b(c7_i7, 1, 168, &c7_cl_emlrtBCI, &c7_e_st);
      }

      if (c7_c_i != (real_T)(int32_T)muDoubleScalarFloor(c7_c_i)) {
        emlrtIntegerCheckR2012b(c7_c_i, &c7_fl_emlrtDCI, &c7_e_st);
      }

      c7_i8 = (int32_T)c7_c_i;
      if ((c7_i8 < 1) || (c7_i8 > 5)) {
        emlrtDynamicBoundsCheckR2012b(c7_i8, 1, 5, &c7_dl_emlrtBCI, &c7_e_st);
      }

      c7_Apadpre[(c7_i8 + 5 * (c7_i7 - 1)) - 1] = MAX_uint32_T;
    }
  }

  for (c7_b_j = 0; c7_b_j < 166; c7_b_j++) {
    c7_d = (real_T)(c7_b_j + 3);
    if (c7_d != (real_T)(int32_T)muDoubleScalarFloor(c7_d)) {
      emlrtIntegerCheckR2012b(c7_d, &c7_dl_emlrtDCI, &c7_e_st);
    }

    c7_i6 = (int32_T)muDoubleScalarFloor(c7_d);
    if ((c7_i6 < 1) || (c7_i6 > 168)) {
      emlrtDynamicBoundsCheckR2012b(c7_i6, 1, 168, &c7_bl_emlrtBCI, &c7_e_st);
    }

    c7_Apadpre[5 * (c7_i6 - 1)] = MAX_uint32_T;
  }

  for (c7_d_j = 0; c7_d_j < 166; c7_d_j++) {
    c7_c_j = 1.0 + (real_T)c7_d_j;
    for (c7_d_i = 0; c7_d_i < 4; c7_d_i++) {
      c7_c_i = 1.0 + (real_T)c7_d_i;
      c7_f_a = c7_c_i;
      c7_b_c = (int32_T)c7_f_a;
      c7_g_a = c7_c_j;
      c7_c_c = (int32_T)c7_g_a;
      if (c7_c_i != (real_T)(int32_T)muDoubleScalarFloor(c7_c_i)) {
        emlrtIntegerCheckR2012b(c7_c_i, &c7_k_emlrtDCI, &c7_e_st);
      }

      c7_i12 = (int32_T)c7_c_i;
      if ((c7_i12 < 1) || (c7_i12 > 4)) {
        emlrtDynamicBoundsCheckR2012b(c7_i12, 1, 4, &c7_pl_emlrtBCI, &c7_e_st);
      }

      if (c7_c_j != (real_T)(int32_T)muDoubleScalarFloor(c7_c_j)) {
        emlrtIntegerCheckR2012b(c7_c_j, &c7_l_emlrtDCI, &c7_e_st);
      }

      c7_i17 = (int32_T)c7_c_j;
      if ((c7_i17 < 1) || (c7_i17 > 166)) {
        emlrtDynamicBoundsCheckR2012b(c7_i17, 1, 166, &c7_ql_emlrtBCI, &c7_e_st);
      }

      c7_d2 = (real_T)(c7_b_c + 1);
      if (c7_d2 != (real_T)(int32_T)muDoubleScalarFloor(c7_d2)) {
        emlrtIntegerCheckR2012b(c7_d2, &c7_w_emlrtDCI, &c7_e_st);
      }

      c7_i21 = (int32_T)muDoubleScalarFloor(c7_d2);
      if ((c7_i21 < 1) || (c7_i21 > 5)) {
        emlrtDynamicBoundsCheckR2012b(c7_i21, 1, 5, &c7_rl_emlrtBCI, &c7_e_st);
      }

      c7_d3 = (real_T)(c7_c_c + 2);
      if (c7_d3 != (real_T)(int32_T)muDoubleScalarFloor(c7_d3)) {
        emlrtIntegerCheckR2012b(c7_d3, &c7_x_emlrtDCI, &c7_e_st);
      }

      c7_i25 = (int32_T)muDoubleScalarFloor(c7_d3);
      if ((c7_i25 < 1) || (c7_i25 > 168)) {
        emlrtDynamicBoundsCheckR2012b(c7_i25, 1, 168, &c7_sl_emlrtBCI, &c7_e_st);
      }

      c7_Apadpre[(c7_i21 + 5 * (c7_i25 - 1)) - 1] = c7_b_A[(c7_i12 + ((c7_i17 -
        1) << 2)) - 1];
    }
  }

  c7_d_st.site = &c7_ad_emlrtRSI;
  c7_e_st.site = &c7_t_emlrtRSI;
  for (c7_e_j = 0; c7_e_j < 2; c7_e_j++) {
    for (c7_e_i = 0; c7_e_i < 6; c7_e_i++) {
      c7_f_i = 1.0 + (real_T)c7_e_i;
      c7_d1 = (real_T)(c7_e_j + 169);
      if (c7_d1 != (real_T)(int32_T)muDoubleScalarFloor(c7_d1)) {
        emlrtIntegerCheckR2012b(c7_d1, &c7_bl_emlrtDCI, &c7_e_st);
      }

      c7_i11 = (int32_T)muDoubleScalarFloor(c7_d1);
      if ((c7_i11 < 1) || (c7_i11 > 170)) {
        emlrtDynamicBoundsCheckR2012b(c7_i11, 1, 170, &c7_yk_emlrtBCI, &c7_e_st);
      }

      if (c7_f_i != (real_T)(int32_T)muDoubleScalarFloor(c7_f_i)) {
        emlrtIntegerCheckR2012b(c7_f_i, &c7_cl_emlrtDCI, &c7_e_st);
      }

      c7_i16 = (int32_T)c7_f_i;
      if ((c7_i16 < 1) || (c7_i16 > 6)) {
        emlrtDynamicBoundsCheckR2012b(c7_i16, 1, 6, &c7_al_emlrtBCI, &c7_e_st);
      }

      c7_Apad[(c7_i16 + 6 * (c7_i11 - 1)) - 1] = MAX_uint32_T;
    }
  }

  for (c7_f_j = 0; c7_f_j < 168; c7_f_j++) {
    c7_h_j = 1.0 + (real_T)c7_f_j;
    if (c7_h_j != (real_T)(int32_T)muDoubleScalarFloor(c7_h_j)) {
      emlrtIntegerCheckR2012b(c7_h_j, &c7_al_emlrtDCI, &c7_e_st);
    }

    c7_i10 = (int32_T)c7_h_j;
    if ((c7_i10 < 1) || (c7_i10 > 170)) {
      emlrtDynamicBoundsCheckR2012b(c7_i10, 1, 170, &c7_xk_emlrtBCI, &c7_e_st);
    }

    c7_Apad[5 + 6 * (c7_i10 - 1)] = MAX_uint32_T;
  }

  for (c7_g_j = 0; c7_g_j < 168; c7_g_j++) {
    c7_h_j = 1.0 + (real_T)c7_g_j;
    for (c7_g_i = 0; c7_g_i < 5; c7_g_i++) {
      c7_f_i = 1.0 + (real_T)c7_g_i;
      if (c7_f_i != (real_T)(int32_T)muDoubleScalarFloor(c7_f_i)) {
        emlrtIntegerCheckR2012b(c7_f_i, &c7_ll_emlrtDCI, &c7_e_st);
      }

      c7_i15 = (int32_T)c7_f_i;
      if ((c7_i15 < 1) || (c7_i15 > 5)) {
        emlrtDynamicBoundsCheckR2012b(c7_i15, 1, 5, &c7_tl_emlrtBCI, &c7_e_st);
      }

      if (c7_h_j != (real_T)(int32_T)muDoubleScalarFloor(c7_h_j)) {
        emlrtIntegerCheckR2012b(c7_h_j, &c7_ml_emlrtDCI, &c7_e_st);
      }

      c7_i19 = (int32_T)c7_h_j;
      if ((c7_i19 < 1) || (c7_i19 > 168)) {
        emlrtDynamicBoundsCheckR2012b(c7_i19, 1, 168, &c7_ul_emlrtBCI, &c7_e_st);
      }

      if (c7_f_i != (real_T)(int32_T)muDoubleScalarFloor(c7_f_i)) {
        emlrtIntegerCheckR2012b(c7_f_i, &c7_nl_emlrtDCI, &c7_e_st);
      }

      c7_i23 = (int32_T)c7_f_i;
      if ((c7_i23 < 1) || (c7_i23 > 6)) {
        emlrtDynamicBoundsCheckR2012b(c7_i23, 1, 6, &c7_vl_emlrtBCI, &c7_e_st);
      }

      if (c7_h_j != (real_T)(int32_T)muDoubleScalarFloor(c7_h_j)) {
        emlrtIntegerCheckR2012b(c7_h_j, &c7_ol_emlrtDCI, &c7_e_st);
      }

      c7_i27 = (int32_T)c7_h_j;
      if ((c7_i27 < 1) || (c7_i27 > 170)) {
        emlrtDynamicBoundsCheckR2012b(c7_i27, 1, 170, &c7_wl_emlrtBCI, &c7_e_st);
      }

      c7_Apad[(c7_i23 + 6 * (c7_i27 - 1)) - 1] = c7_Apadpre[(c7_i15 + 5 *
        (c7_i19 - 1)) - 1];
    }
  }

  c7_d_st.site = &c7_bd_emlrtRSI;
  for (c7_i9 = 0; c7_i9 < 3; c7_i9++) {
    c7_nhood[c7_i9] = true;
  }

  for (c7_i13 = 0; c7_i13 < 2; c7_i13++) {
    c7_asizeT[c7_i13] = 6.0 + 164.0 * (real_T)c7_i13;
  }

  for (c7_i14 = 0; c7_i14 < 2; c7_i14++) {
    c7_nsizeT[c7_i14] = 3.0 + -2.0 * (real_T)c7_i14;
  }

  erode_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0], &c7_nsizeT
                      [0], 2.0, 126.0, &c7_e_B[0], true);
  c7_d_st.site = &c7_bd_emlrtRSI;
  for (c7_i18 = 0; c7_i18 < 1020; c7_i18++) {
    c7_Apad[c7_i18] = c7_e_B[c7_i18];
  }

  c7_b_nhood = true;
  for (c7_i20 = 0; c7_i20 < 2; c7_i20++) {
    c7_asizeT[c7_i20] = 6.0 + 164.0 * (real_T)c7_i20;
  }

  for (c7_i22 = 0; c7_i22 < 2; c7_i22++) {
    c7_nsizeT[c7_i22] = 1.0;
  }

  erode_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_b_nhood, &c7_nsizeT[0],
                      2.0, 126.0, &c7_e_B[0], true);
  c7_d_st.site = &c7_bd_emlrtRSI;
  for (c7_i24 = 0; c7_i24 < 1020; c7_i24++) {
    c7_Apad[c7_i24] = c7_e_B[c7_i24];
  }

  for (c7_i26 = 0; c7_i26 < 3; c7_i26++) {
    c7_nhood[c7_i26] = true;
  }

  for (c7_i28 = 0; c7_i28 < 2; c7_i28++) {
    c7_asizeT[c7_i28] = 6.0 + 164.0 * (real_T)c7_i28;
  }

  for (c7_i29 = 0; c7_i29 < 2; c7_i29++) {
    c7_nsizeT[c7_i29] = 1.0 + 2.0 * (real_T)c7_i29;
  }

  erode_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0], &c7_nsizeT
                      [0], 2.0, 126.0, &c7_e_B[0], true);
  c7_d_st.site = &c7_bd_emlrtRSI;
  for (c7_i30 = 0; c7_i30 < 1020; c7_i30++) {
    c7_Apad[c7_i30] = c7_e_B[c7_i30];
  }

  c7_c_nhood = true;
  for (c7_i31 = 0; c7_i31 < 2; c7_i31++) {
    c7_asizeT[c7_i31] = 6.0 + 164.0 * (real_T)c7_i31;
  }

  for (c7_i32 = 0; c7_i32 < 2; c7_i32++) {
    c7_nsizeT[c7_i32] = 1.0;
  }

  erode_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_c_nhood, &c7_nsizeT[0],
                      2.0, 126.0, &c7_e_B[0], true);
  c7_d_st.site = &c7_bd_emlrtRSI;
  for (c7_i33 = 0; c7_i33 < 1020; c7_i33++) {
    c7_Apad[c7_i33] = c7_e_B[c7_i33];
  }

  for (c7_i34 = 0; c7_i34 < 3; c7_i34++) {
    c7_nhood[c7_i34] = true;
  }

  for (c7_i35 = 0; c7_i35 < 2; c7_i35++) {
    c7_asizeT[c7_i35] = 6.0 + 164.0 * (real_T)c7_i35;
  }

  for (c7_i36 = 0; c7_i36 < 2; c7_i36++) {
    c7_nsizeT[c7_i36] = 1.0 + 2.0 * (real_T)c7_i36;
  }

  erode_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0], &c7_nsizeT
                      [0], 2.0, 126.0, &c7_e_B[0], true);
  c7_d_st.site = &c7_bd_emlrtRSI;
  for (c7_i37 = 0; c7_i37 < 1020; c7_i37++) {
    c7_Apad[c7_i37] = c7_e_B[c7_i37];
  }

  for (c7_i38 = 0; c7_i38 < 3; c7_i38++) {
    c7_nhood[c7_i38] = true;
  }

  for (c7_i39 = 0; c7_i39 < 2; c7_i39++) {
    c7_asizeT[c7_i39] = 6.0 + 164.0 * (real_T)c7_i39;
  }

  for (c7_i40 = 0; c7_i40 < 2; c7_i40++) {
    c7_nsizeT[c7_i40] = 3.0 + -2.0 * (real_T)c7_i40;
  }

  erode_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0], &c7_nsizeT
                      [0], 2.0, 126.0, &c7_e_B[0], true);
  c7_i41 = 0;
  c7_i42 = 0;
  for (c7_i43 = 0; c7_i43 < 166; c7_i43++) {
    for (c7_i44 = 0; c7_i44 < 4; c7_i44++) {
      c7_d_B[c7_i44 + c7_i41] = c7_e_B[(c7_i44 + c7_i42) + 13];
    }

    c7_i41 += 4;
    c7_i42 += 6;
  }
}

static void c7_imopen(SFc7_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c7_sp, boolean_T c7_A[19200], boolean_T
                      c7_d_B[19200])
{
  emlrtStack c7_b_st;
  emlrtStack c7_c_st;
  emlrtStack c7_d_st;
  emlrtStack c7_e_st;
  emlrtStack c7_f_st;
  emlrtStack c7_st;
  real_T c7_asizeT[2];
  real_T c7_nsizeT[2];
  real_T c7_b_k;
  real_T c7_c_i;
  real_T c7_c_j;
  real_T c7_d;
  real_T c7_d1;
  real_T c7_d2;
  real_T c7_d3;
  real_T c7_d_a;
  real_T c7_e_a;
  real_T c7_f_i;
  real_T c7_h_j;
  int32_T c7_b_c;
  int32_T c7_b_i;
  int32_T c7_b_j;
  int32_T c7_c;
  int32_T c7_c_k;
  int32_T c7_d_i;
  int32_T c7_d_j;
  int32_T c7_d_k;
  int32_T c7_e_i;
  int32_T c7_e_j;
  int32_T c7_f_j;
  int32_T c7_g_i;
  int32_T c7_g_j;
  int32_T c7_i;
  int32_T c7_i1;
  int32_T c7_i10;
  int32_T c7_i11;
  int32_T c7_i12;
  int32_T c7_i13;
  int32_T c7_i14;
  int32_T c7_i15;
  int32_T c7_i16;
  int32_T c7_i17;
  int32_T c7_i18;
  int32_T c7_i19;
  int32_T c7_i2;
  int32_T c7_i20;
  int32_T c7_i21;
  int32_T c7_i22;
  int32_T c7_i23;
  int32_T c7_i24;
  int32_T c7_i25;
  int32_T c7_i26;
  int32_T c7_i27;
  int32_T c7_i28;
  int32_T c7_i29;
  int32_T c7_i3;
  int32_T c7_i30;
  int32_T c7_i31;
  int32_T c7_i32;
  int32_T c7_i33;
  int32_T c7_i34;
  int32_T c7_i35;
  int32_T c7_i36;
  int32_T c7_i37;
  int32_T c7_i38;
  int32_T c7_i39;
  int32_T c7_i4;
  int32_T c7_i40;
  int32_T c7_i41;
  int32_T c7_i42;
  int32_T c7_i43;
  int32_T c7_i44;
  int32_T c7_i45;
  int32_T c7_i46;
  int32_T c7_i47;
  int32_T c7_i5;
  int32_T c7_i6;
  int32_T c7_i7;
  int32_T c7_i8;
  int32_T c7_i9;
  int32_T c7_j;
  int32_T c7_k;
  uint32_T c7_Apad[984];
  uint32_T c7_e_B[984];
  uint32_T c7_Apadpre[810];
  uint32_T c7_b_A[640];
  uint32_T c7_inputImage[640];
  uint32_T c7_last_row[160];
  uint32_T c7_modified_last_row[160];
  uint32_T c7_b;
  uint32_T c7_b_a;
  uint32_T c7_b_b;
  uint32_T c7_b_varargin_2;
  uint32_T c7_b_y;
  uint32_T c7_c_a;
  uint32_T c7_c_b;
  uint32_T c7_d_b;
  uint32_T c7_mask_value;
  uint32_T c7_varargin_1;
  uint32_T c7_varargin_2;
  uint32_T c7_varargout_1;
  uint32_T c7_y;
  boolean_T c7_nhood[3];
  boolean_T c7_b_nhood;
  boolean_T c7_c_nhood;
  c7_st.prev = c7_sp;
  c7_st.tls = c7_sp->tls;
  c7_st.site = &c7_jd_emlrtRSI;
  c7_b_st.prev = &c7_st;
  c7_b_st.tls = c7_st.tls;
  c7_c_st.prev = &c7_b_st;
  c7_c_st.tls = c7_b_st.tls;
  c7_d_st.prev = &c7_c_st;
  c7_d_st.tls = c7_c_st.tls;
  c7_e_st.prev = &c7_d_st;
  c7_e_st.tls = c7_d_st.tls;
  c7_f_st.prev = &c7_e_st;
  c7_f_st.tls = c7_e_st.tls;
  c7_b_st.site = &c7_tc_emlrtRSI;
  for (c7_i = 0; c7_i < 2; c7_i++) {
    c7_asizeT[c7_i] = 120.0 + 40.0 * (real_T)c7_i;
  }

  for (c7_i1 = 0; c7_i1 < 2; c7_i1++) {
    c7_nsizeT[c7_i1] = 4.0 + 156.0 * (real_T)c7_i1;
  }

  bwPackingtbb(&c7_A[0], &c7_asizeT[0], &c7_inputImage[0], &c7_nsizeT[0], true);
  c7_st.site = &c7_kd_emlrtRSI;
  c7_b_st.site = &c7_kd_emlrtRSI;
  c7_b_imerode(chartInstance, &c7_b_st, c7_inputImage, c7_b_A);
  c7_b_st.site = &c7_uc_emlrtRSI;
  c7_c_st.site = &c7_vc_emlrtRSI;
  c7_d_st.site = &c7_wc_emlrtRSI;
  c7_e_st.site = &c7_xc_emlrtRSI;
  c7_mask_value = 0U;
  for (c7_k = 0; c7_k < 24; c7_k++) {
    c7_b_k = 1.0 + (real_T)c7_k;
    if (c7_b_k != (real_T)(int32_T)muDoubleScalarFloor(c7_b_k)) {
      emlrtIntegerCheckR2012b(c7_b_k, &c7_gl_emlrtDCI, &c7_e_st);
    }

    c7_i4 = (int32_T)c7_b_k;
    if ((c7_i4 < 1) || (c7_i4 > 24)) {
      emlrtDynamicBoundsCheckR2012b(c7_i4, 1, 24, &c7_dm_emlrtBCI, &c7_e_st);
    }

    c7_f_st.site = &c7_cd_emlrtRSI;
    c7_mask_value = c7_bitset(chartInstance, &c7_f_st, c7_mask_value, 1.0 +
      (real_T)(c7_i4 - 1));
  }

  c7_i2 = 0;
  for (c7_i3 = 0; c7_i3 < 160; c7_i3++) {
    c7_last_row[c7_i3] = c7_b_A[c7_i2 + 3];
    c7_i2 += 4;
  }

  c7_varargin_2 = c7_mask_value;
  c7_b = c7_varargin_2;
  c7_b_b = c7_b;
  c7_y = c7_b_b;
  c7_b_y = c7_y;
  for (c7_c_k = 0; c7_c_k < 160; c7_c_k++) {
    c7_d_k = c7_c_k;
    c7_varargin_1 = c7_last_row[c7_d_k];
    c7_b_varargin_2 = c7_b_y;
    c7_b_a = c7_varargin_1;
    c7_c_b = c7_b_varargin_2;
    c7_c_a = c7_b_a;
    c7_d_b = c7_c_b;
    c7_varargout_1 = c7_c_a & c7_d_b;
    c7_modified_last_row[c7_d_k] = c7_varargout_1;
  }

  c7_i5 = 0;
  for (c7_i6 = 0; c7_i6 < 160; c7_i6++) {
    c7_b_A[c7_i5 + 3] = c7_modified_last_row[c7_i6];
    c7_i5 += 4;
  }

  c7_e_st.site = &c7_yc_emlrtRSI;
  c7_f_st.site = &c7_t_emlrtRSI;
  for (c7_j = 0; c7_j < 2; c7_j++) {
    c7_c_j = 1.0 + (real_T)c7_j;
    for (c7_b_i = 0; c7_b_i < 5; c7_b_i++) {
      c7_c_i = 1.0 + (real_T)c7_b_i;
      if (c7_c_j != (real_T)(int32_T)muDoubleScalarFloor(c7_c_j)) {
        emlrtIntegerCheckR2012b(c7_c_j, &c7_el_emlrtDCI, &c7_f_st);
      }

      c7_i8 = (int32_T)c7_c_j;
      if ((c7_i8 < 1) || (c7_i8 > 162)) {
        emlrtDynamicBoundsCheckR2012b(c7_i8, 1, 162, &c7_cm_emlrtBCI, &c7_f_st);
      }

      if (c7_c_i != (real_T)(int32_T)muDoubleScalarFloor(c7_c_i)) {
        emlrtIntegerCheckR2012b(c7_c_i, &c7_fl_emlrtDCI, &c7_f_st);
      }

      c7_i9 = (int32_T)c7_c_i;
      if ((c7_i9 < 1) || (c7_i9 > 5)) {
        emlrtDynamicBoundsCheckR2012b(c7_i9, 1, 5, &c7_dl_emlrtBCI, &c7_f_st);
      }

      c7_Apadpre[(c7_i9 + 5 * (c7_i8 - 1)) - 1] = 0U;
    }
  }

  for (c7_b_j = 0; c7_b_j < 160; c7_b_j++) {
    c7_d = (real_T)(c7_b_j + 3);
    if (c7_d != (real_T)(int32_T)muDoubleScalarFloor(c7_d)) {
      emlrtIntegerCheckR2012b(c7_d, &c7_dl_emlrtDCI, &c7_f_st);
    }

    c7_i7 = (int32_T)muDoubleScalarFloor(c7_d);
    if ((c7_i7 < 1) || (c7_i7 > 162)) {
      emlrtDynamicBoundsCheckR2012b(c7_i7, 1, 162, &c7_bm_emlrtBCI, &c7_f_st);
    }

    c7_Apadpre[5 * (c7_i7 - 1)] = 0U;
  }

  for (c7_d_j = 0; c7_d_j < 160; c7_d_j++) {
    c7_c_j = 1.0 + (real_T)c7_d_j;
    for (c7_d_i = 0; c7_d_i < 4; c7_d_i++) {
      c7_c_i = 1.0 + (real_T)c7_d_i;
      c7_d_a = c7_c_i;
      c7_c = (int32_T)c7_d_a;
      c7_e_a = c7_c_j;
      c7_b_c = (int32_T)c7_e_a;
      if (c7_c_i != (real_T)(int32_T)muDoubleScalarFloor(c7_c_i)) {
        emlrtIntegerCheckR2012b(c7_c_i, &c7_k_emlrtDCI, &c7_f_st);
      }

      c7_i13 = (int32_T)c7_c_i;
      if ((c7_i13 < 1) || (c7_i13 > 4)) {
        emlrtDynamicBoundsCheckR2012b(c7_i13, 1, 4, &c7_pl_emlrtBCI, &c7_f_st);
      }

      if (c7_c_j != (real_T)(int32_T)muDoubleScalarFloor(c7_c_j)) {
        emlrtIntegerCheckR2012b(c7_c_j, &c7_l_emlrtDCI, &c7_f_st);
      }

      c7_i18 = (int32_T)c7_c_j;
      if ((c7_i18 < 1) || (c7_i18 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c7_i18, 1, 160, &c7_l_emlrtBCI, &c7_f_st);
      }

      c7_d2 = (real_T)(c7_c + 1);
      if (c7_d2 != (real_T)(int32_T)muDoubleScalarFloor(c7_d2)) {
        emlrtIntegerCheckR2012b(c7_d2, &c7_w_emlrtDCI, &c7_f_st);
      }

      c7_i22 = (int32_T)muDoubleScalarFloor(c7_d2);
      if ((c7_i22 < 1) || (c7_i22 > 5)) {
        emlrtDynamicBoundsCheckR2012b(c7_i22, 1, 5, &c7_rl_emlrtBCI, &c7_f_st);
      }

      c7_d3 = (real_T)(c7_b_c + 2);
      if (c7_d3 != (real_T)(int32_T)muDoubleScalarFloor(c7_d3)) {
        emlrtIntegerCheckR2012b(c7_d3, &c7_x_emlrtDCI, &c7_f_st);
      }

      c7_i26 = (int32_T)muDoubleScalarFloor(c7_d3);
      if ((c7_i26 < 1) || (c7_i26 > 162)) {
        emlrtDynamicBoundsCheckR2012b(c7_i26, 1, 162, &c7_v_emlrtBCI, &c7_f_st);
      }

      c7_Apadpre[(c7_i22 + 5 * (c7_i26 - 1)) - 1] = c7_b_A[(c7_i13 + ((c7_i18 -
        1) << 2)) - 1];
    }
  }

  c7_e_st.site = &c7_ad_emlrtRSI;
  c7_f_st.site = &c7_t_emlrtRSI;
  for (c7_e_j = 0; c7_e_j < 2; c7_e_j++) {
    for (c7_e_i = 0; c7_e_i < 6; c7_e_i++) {
      c7_f_i = 1.0 + (real_T)c7_e_i;
      c7_d1 = (real_T)(c7_e_j + 163);
      if (c7_d1 != (real_T)(int32_T)muDoubleScalarFloor(c7_d1)) {
        emlrtIntegerCheckR2012b(c7_d1, &c7_bl_emlrtDCI, &c7_f_st);
      }

      c7_i12 = (int32_T)muDoubleScalarFloor(c7_d1);
      if ((c7_i12 < 1) || (c7_i12 > 164)) {
        emlrtDynamicBoundsCheckR2012b(c7_i12, 1, 164, &c7_am_emlrtBCI, &c7_f_st);
      }

      if (c7_f_i != (real_T)(int32_T)muDoubleScalarFloor(c7_f_i)) {
        emlrtIntegerCheckR2012b(c7_f_i, &c7_cl_emlrtDCI, &c7_f_st);
      }

      c7_i17 = (int32_T)c7_f_i;
      if ((c7_i17 < 1) || (c7_i17 > 6)) {
        emlrtDynamicBoundsCheckR2012b(c7_i17, 1, 6, &c7_al_emlrtBCI, &c7_f_st);
      }

      c7_Apad[(c7_i17 + 6 * (c7_i12 - 1)) - 1] = 0U;
    }
  }

  for (c7_f_j = 0; c7_f_j < 162; c7_f_j++) {
    c7_h_j = 1.0 + (real_T)c7_f_j;
    if (c7_h_j != (real_T)(int32_T)muDoubleScalarFloor(c7_h_j)) {
      emlrtIntegerCheckR2012b(c7_h_j, &c7_al_emlrtDCI, &c7_f_st);
    }

    c7_i11 = (int32_T)c7_h_j;
    if ((c7_i11 < 1) || (c7_i11 > 164)) {
      emlrtDynamicBoundsCheckR2012b(c7_i11, 1, 164, &c7_yl_emlrtBCI, &c7_f_st);
    }

    c7_Apad[5 + 6 * (c7_i11 - 1)] = 0U;
  }

  for (c7_g_j = 0; c7_g_j < 162; c7_g_j++) {
    c7_h_j = 1.0 + (real_T)c7_g_j;
    for (c7_g_i = 0; c7_g_i < 5; c7_g_i++) {
      c7_f_i = 1.0 + (real_T)c7_g_i;
      if (c7_f_i != (real_T)(int32_T)muDoubleScalarFloor(c7_f_i)) {
        emlrtIntegerCheckR2012b(c7_f_i, &c7_ll_emlrtDCI, &c7_f_st);
      }

      c7_i16 = (int32_T)c7_f_i;
      if ((c7_i16 < 1) || (c7_i16 > 5)) {
        emlrtDynamicBoundsCheckR2012b(c7_i16, 1, 5, &c7_tl_emlrtBCI, &c7_f_st);
      }

      if (c7_h_j != (real_T)(int32_T)muDoubleScalarFloor(c7_h_j)) {
        emlrtIntegerCheckR2012b(c7_h_j, &c7_ml_emlrtDCI, &c7_f_st);
      }

      c7_i20 = (int32_T)c7_h_j;
      if ((c7_i20 < 1) || (c7_i20 > 162)) {
        emlrtDynamicBoundsCheckR2012b(c7_i20, 1, 162, &c7_em_emlrtBCI, &c7_f_st);
      }

      if (c7_f_i != (real_T)(int32_T)muDoubleScalarFloor(c7_f_i)) {
        emlrtIntegerCheckR2012b(c7_f_i, &c7_nl_emlrtDCI, &c7_f_st);
      }

      c7_i24 = (int32_T)c7_f_i;
      if ((c7_i24 < 1) || (c7_i24 > 6)) {
        emlrtDynamicBoundsCheckR2012b(c7_i24, 1, 6, &c7_vl_emlrtBCI, &c7_f_st);
      }

      if (c7_h_j != (real_T)(int32_T)muDoubleScalarFloor(c7_h_j)) {
        emlrtIntegerCheckR2012b(c7_h_j, &c7_ol_emlrtDCI, &c7_f_st);
      }

      c7_i28 = (int32_T)c7_h_j;
      if ((c7_i28 < 1) || (c7_i28 > 164)) {
        emlrtDynamicBoundsCheckR2012b(c7_i28, 1, 164, &c7_fm_emlrtBCI, &c7_f_st);
      }

      c7_Apad[(c7_i24 + 6 * (c7_i28 - 1)) - 1] = c7_Apadpre[(c7_i16 + 5 *
        (c7_i20 - 1)) - 1];
    }
  }

  c7_e_st.site = &c7_bd_emlrtRSI;
  for (c7_i10 = 0; c7_i10 < 3; c7_i10++) {
    c7_nhood[c7_i10] = true;
  }

  for (c7_i14 = 0; c7_i14 < 2; c7_i14++) {
    c7_asizeT[c7_i14] = 6.0 + 158.0 * (real_T)c7_i14;
  }

  for (c7_i15 = 0; c7_i15 < 2; c7_i15++) {
    c7_nsizeT[c7_i15] = 3.0 + -2.0 * (real_T)c7_i15;
  }

  dilate_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0],
                       &c7_nsizeT[0], 2.0, &c7_e_B[0], true);
  c7_e_st.site = &c7_bd_emlrtRSI;
  for (c7_i19 = 0; c7_i19 < 984; c7_i19++) {
    c7_Apad[c7_i19] = c7_e_B[c7_i19];
  }

  c7_b_nhood = true;
  for (c7_i21 = 0; c7_i21 < 2; c7_i21++) {
    c7_asizeT[c7_i21] = 6.0 + 158.0 * (real_T)c7_i21;
  }

  for (c7_i23 = 0; c7_i23 < 2; c7_i23++) {
    c7_nsizeT[c7_i23] = 1.0;
  }

  dilate_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_b_nhood, &c7_nsizeT
                       [0], 2.0, &c7_e_B[0], true);
  c7_e_st.site = &c7_bd_emlrtRSI;
  for (c7_i25 = 0; c7_i25 < 984; c7_i25++) {
    c7_Apad[c7_i25] = c7_e_B[c7_i25];
  }

  for (c7_i27 = 0; c7_i27 < 3; c7_i27++) {
    c7_nhood[c7_i27] = true;
  }

  for (c7_i29 = 0; c7_i29 < 2; c7_i29++) {
    c7_asizeT[c7_i29] = 6.0 + 158.0 * (real_T)c7_i29;
  }

  for (c7_i30 = 0; c7_i30 < 2; c7_i30++) {
    c7_nsizeT[c7_i30] = 1.0 + 2.0 * (real_T)c7_i30;
  }

  dilate_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0],
                       &c7_nsizeT[0], 2.0, &c7_e_B[0], true);
  c7_e_st.site = &c7_bd_emlrtRSI;
  for (c7_i31 = 0; c7_i31 < 984; c7_i31++) {
    c7_Apad[c7_i31] = c7_e_B[c7_i31];
  }

  c7_c_nhood = true;
  for (c7_i32 = 0; c7_i32 < 2; c7_i32++) {
    c7_asizeT[c7_i32] = 6.0 + 158.0 * (real_T)c7_i32;
  }

  for (c7_i33 = 0; c7_i33 < 2; c7_i33++) {
    c7_nsizeT[c7_i33] = 1.0;
  }

  dilate_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_c_nhood, &c7_nsizeT
                       [0], 2.0, &c7_e_B[0], true);
  c7_e_st.site = &c7_bd_emlrtRSI;
  for (c7_i34 = 0; c7_i34 < 984; c7_i34++) {
    c7_Apad[c7_i34] = c7_e_B[c7_i34];
  }

  for (c7_i35 = 0; c7_i35 < 3; c7_i35++) {
    c7_nhood[c7_i35] = true;
  }

  for (c7_i36 = 0; c7_i36 < 2; c7_i36++) {
    c7_asizeT[c7_i36] = 6.0 + 158.0 * (real_T)c7_i36;
  }

  for (c7_i37 = 0; c7_i37 < 2; c7_i37++) {
    c7_nsizeT[c7_i37] = 1.0 + 2.0 * (real_T)c7_i37;
  }

  dilate_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0],
                       &c7_nsizeT[0], 2.0, &c7_e_B[0], true);
  c7_e_st.site = &c7_bd_emlrtRSI;
  for (c7_i38 = 0; c7_i38 < 984; c7_i38++) {
    c7_Apad[c7_i38] = c7_e_B[c7_i38];
  }

  for (c7_i39 = 0; c7_i39 < 3; c7_i39++) {
    c7_nhood[c7_i39] = true;
  }

  for (c7_i40 = 0; c7_i40 < 2; c7_i40++) {
    c7_asizeT[c7_i40] = 6.0 + 158.0 * (real_T)c7_i40;
  }

  for (c7_i41 = 0; c7_i41 < 2; c7_i41++) {
    c7_nsizeT[c7_i41] = 3.0 + -2.0 * (real_T)c7_i41;
  }

  dilate_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0],
                       &c7_nsizeT[0], 2.0, &c7_e_B[0], true);
  c7_i42 = 0;
  c7_i43 = 0;
  for (c7_i44 = 0; c7_i44 < 160; c7_i44++) {
    for (c7_i45 = 0; c7_i45 < 4; c7_i45++) {
      c7_inputImage[c7_i45 + c7_i42] = c7_e_B[(c7_i45 + c7_i43) + 13];
    }

    c7_i42 += 4;
    c7_i43 += 6;
  }

  c7_st.site = &c7_ld_emlrtRSI;
  c7_b_st.site = &c7_id_emlrtRSI;
  for (c7_i46 = 0; c7_i46 < 2; c7_i46++) {
    c7_nsizeT[c7_i46] = 4.0 + 156.0 * (real_T)c7_i46;
  }

  for (c7_i47 = 0; c7_i47 < 2; c7_i47++) {
    c7_asizeT[c7_i47] = 120.0 + 40.0 * (real_T)c7_i47;
  }

  bwUnpackingtbb(&c7_inputImage[0], &c7_nsizeT[0], &c7_d_B[0], &c7_asizeT[0],
                 true);
}

static void c7_b_imerode(SFc7_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c7_sp, uint32_T c7_A[640], uint32_T c7_d_B[640])
{
  emlrtStack c7_b_st;
  emlrtStack c7_c_st;
  emlrtStack c7_d_st;
  emlrtStack c7_e_st;
  emlrtStack c7_st;
  real_T c7_asizeT[2];
  real_T c7_nsizeT[2];
  real_T c7_b_k;
  real_T c7_c_i;
  real_T c7_c_j;
  real_T c7_d;
  real_T c7_d1;
  real_T c7_d2;
  real_T c7_d3;
  real_T c7_f_a;
  real_T c7_f_i;
  real_T c7_g_a;
  real_T c7_h_j;
  int32_T c7_b_c;
  int32_T c7_b_i;
  int32_T c7_b_j;
  int32_T c7_c_c;
  int32_T c7_c_k;
  int32_T c7_d_i;
  int32_T c7_d_j;
  int32_T c7_d_k;
  int32_T c7_e_i;
  int32_T c7_e_j;
  int32_T c7_f_j;
  int32_T c7_g_i;
  int32_T c7_g_j;
  int32_T c7_i;
  int32_T c7_i1;
  int32_T c7_i10;
  int32_T c7_i11;
  int32_T c7_i12;
  int32_T c7_i13;
  int32_T c7_i14;
  int32_T c7_i15;
  int32_T c7_i16;
  int32_T c7_i17;
  int32_T c7_i18;
  int32_T c7_i19;
  int32_T c7_i2;
  int32_T c7_i20;
  int32_T c7_i21;
  int32_T c7_i22;
  int32_T c7_i23;
  int32_T c7_i24;
  int32_T c7_i25;
  int32_T c7_i26;
  int32_T c7_i27;
  int32_T c7_i28;
  int32_T c7_i29;
  int32_T c7_i3;
  int32_T c7_i30;
  int32_T c7_i31;
  int32_T c7_i32;
  int32_T c7_i33;
  int32_T c7_i34;
  int32_T c7_i35;
  int32_T c7_i36;
  int32_T c7_i37;
  int32_T c7_i38;
  int32_T c7_i39;
  int32_T c7_i4;
  int32_T c7_i40;
  int32_T c7_i41;
  int32_T c7_i42;
  int32_T c7_i43;
  int32_T c7_i44;
  int32_T c7_i5;
  int32_T c7_i6;
  int32_T c7_i7;
  int32_T c7_i8;
  int32_T c7_i9;
  int32_T c7_j;
  int32_T c7_k;
  uint32_T c7_Apad[984];
  uint32_T c7_e_B[984];
  uint32_T c7_Apadpre[810];
  uint32_T c7_b_A[640];
  uint32_T c7_last_row[160];
  uint32_T c7_modified_last_row[160];
  uint32_T c7_b;
  uint32_T c7_b_a;
  uint32_T c7_b_b;
  uint32_T c7_b_varargin_2;
  uint32_T c7_b_y;
  uint32_T c7_c;
  uint32_T c7_c_a;
  uint32_T c7_c_b;
  uint32_T c7_d_a;
  uint32_T c7_d_b;
  uint32_T c7_e_a;
  uint32_T c7_mask_value;
  uint32_T c7_varargin_1;
  uint32_T c7_varargin_2;
  uint32_T c7_varargout_1;
  uint32_T c7_y;
  boolean_T c7_nhood[3];
  boolean_T c7_b_nhood;
  boolean_T c7_c_nhood;
  c7_st.prev = c7_sp;
  c7_st.tls = c7_sp->tls;
  c7_st.site = &c7_gd_emlrtRSI;
  c7_b_st.prev = &c7_st;
  c7_b_st.tls = c7_st.tls;
  c7_c_st.prev = &c7_b_st;
  c7_c_st.tls = c7_b_st.tls;
  c7_d_st.prev = &c7_c_st;
  c7_d_st.tls = c7_c_st.tls;
  c7_e_st.prev = &c7_d_st;
  c7_e_st.tls = c7_d_st.tls;
  c7_b_st.site = &c7_vc_emlrtRSI;
  c7_c_st.site = &c7_wc_emlrtRSI;
  for (c7_i = 0; c7_i < 640; c7_i++) {
    c7_b_A[c7_i] = c7_A[c7_i];
  }

  c7_d_st.site = &c7_xc_emlrtRSI;
  c7_mask_value = 0U;
  for (c7_k = 0; c7_k < 24; c7_k++) {
    c7_b_k = 1.0 + (real_T)c7_k;
    if (c7_b_k != (real_T)(int32_T)muDoubleScalarFloor(c7_b_k)) {
      emlrtIntegerCheckR2012b(c7_b_k, &c7_gl_emlrtDCI, &c7_d_st);
    }

    c7_i3 = (int32_T)c7_b_k;
    if ((c7_i3 < 1) || (c7_i3 > 24)) {
      emlrtDynamicBoundsCheckR2012b(c7_i3, 1, 24, &c7_dm_emlrtBCI, &c7_d_st);
    }

    c7_e_st.site = &c7_cd_emlrtRSI;
    c7_mask_value = c7_bitset(chartInstance, &c7_e_st, c7_mask_value, 1.0 +
      (real_T)(c7_i3 - 1));
  }

  c7_i1 = 0;
  for (c7_i2 = 0; c7_i2 < 160; c7_i2++) {
    c7_last_row[c7_i2] = c7_b_A[c7_i1 + 3];
    c7_i1 += 4;
  }

  c7_b_a = c7_mask_value;
  c7_c_a = c7_b_a;
  c7_c = ~c7_c_a;
  c7_varargin_2 = c7_c;
  c7_b = c7_varargin_2;
  c7_b_b = c7_b;
  c7_y = c7_b_b;
  c7_b_y = c7_y;
  for (c7_c_k = 0; c7_c_k < 160; c7_c_k++) {
    c7_d_k = c7_c_k;
    c7_varargin_1 = c7_last_row[c7_d_k];
    c7_b_varargin_2 = c7_b_y;
    c7_d_a = c7_varargin_1;
    c7_c_b = c7_b_varargin_2;
    c7_e_a = c7_d_a;
    c7_d_b = c7_c_b;
    c7_varargout_1 = c7_e_a | c7_d_b;
    c7_modified_last_row[c7_d_k] = c7_varargout_1;
  }

  c7_i4 = 0;
  for (c7_i5 = 0; c7_i5 < 160; c7_i5++) {
    c7_b_A[c7_i4 + 3] = c7_modified_last_row[c7_i5];
    c7_i4 += 4;
  }

  c7_d_st.site = &c7_yc_emlrtRSI;
  c7_e_st.site = &c7_t_emlrtRSI;
  for (c7_j = 0; c7_j < 2; c7_j++) {
    c7_c_j = 1.0 + (real_T)c7_j;
    for (c7_b_i = 0; c7_b_i < 5; c7_b_i++) {
      c7_c_i = 1.0 + (real_T)c7_b_i;
      if (c7_c_j != (real_T)(int32_T)muDoubleScalarFloor(c7_c_j)) {
        emlrtIntegerCheckR2012b(c7_c_j, &c7_el_emlrtDCI, &c7_e_st);
      }

      c7_i7 = (int32_T)c7_c_j;
      if ((c7_i7 < 1) || (c7_i7 > 162)) {
        emlrtDynamicBoundsCheckR2012b(c7_i7, 1, 162, &c7_cm_emlrtBCI, &c7_e_st);
      }

      if (c7_c_i != (real_T)(int32_T)muDoubleScalarFloor(c7_c_i)) {
        emlrtIntegerCheckR2012b(c7_c_i, &c7_fl_emlrtDCI, &c7_e_st);
      }

      c7_i8 = (int32_T)c7_c_i;
      if ((c7_i8 < 1) || (c7_i8 > 5)) {
        emlrtDynamicBoundsCheckR2012b(c7_i8, 1, 5, &c7_dl_emlrtBCI, &c7_e_st);
      }

      c7_Apadpre[(c7_i8 + 5 * (c7_i7 - 1)) - 1] = MAX_uint32_T;
    }
  }

  for (c7_b_j = 0; c7_b_j < 160; c7_b_j++) {
    c7_d = (real_T)(c7_b_j + 3);
    if (c7_d != (real_T)(int32_T)muDoubleScalarFloor(c7_d)) {
      emlrtIntegerCheckR2012b(c7_d, &c7_dl_emlrtDCI, &c7_e_st);
    }

    c7_i6 = (int32_T)muDoubleScalarFloor(c7_d);
    if ((c7_i6 < 1) || (c7_i6 > 162)) {
      emlrtDynamicBoundsCheckR2012b(c7_i6, 1, 162, &c7_bm_emlrtBCI, &c7_e_st);
    }

    c7_Apadpre[5 * (c7_i6 - 1)] = MAX_uint32_T;
  }

  for (c7_d_j = 0; c7_d_j < 160; c7_d_j++) {
    c7_c_j = 1.0 + (real_T)c7_d_j;
    for (c7_d_i = 0; c7_d_i < 4; c7_d_i++) {
      c7_c_i = 1.0 + (real_T)c7_d_i;
      c7_f_a = c7_c_i;
      c7_b_c = (int32_T)c7_f_a;
      c7_g_a = c7_c_j;
      c7_c_c = (int32_T)c7_g_a;
      if (c7_c_i != (real_T)(int32_T)muDoubleScalarFloor(c7_c_i)) {
        emlrtIntegerCheckR2012b(c7_c_i, &c7_k_emlrtDCI, &c7_e_st);
      }

      c7_i12 = (int32_T)c7_c_i;
      if ((c7_i12 < 1) || (c7_i12 > 4)) {
        emlrtDynamicBoundsCheckR2012b(c7_i12, 1, 4, &c7_pl_emlrtBCI, &c7_e_st);
      }

      if (c7_c_j != (real_T)(int32_T)muDoubleScalarFloor(c7_c_j)) {
        emlrtIntegerCheckR2012b(c7_c_j, &c7_l_emlrtDCI, &c7_e_st);
      }

      c7_i17 = (int32_T)c7_c_j;
      if ((c7_i17 < 1) || (c7_i17 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c7_i17, 1, 160, &c7_l_emlrtBCI, &c7_e_st);
      }

      c7_d2 = (real_T)(c7_b_c + 1);
      if (c7_d2 != (real_T)(int32_T)muDoubleScalarFloor(c7_d2)) {
        emlrtIntegerCheckR2012b(c7_d2, &c7_w_emlrtDCI, &c7_e_st);
      }

      c7_i21 = (int32_T)muDoubleScalarFloor(c7_d2);
      if ((c7_i21 < 1) || (c7_i21 > 5)) {
        emlrtDynamicBoundsCheckR2012b(c7_i21, 1, 5, &c7_rl_emlrtBCI, &c7_e_st);
      }

      c7_d3 = (real_T)(c7_c_c + 2);
      if (c7_d3 != (real_T)(int32_T)muDoubleScalarFloor(c7_d3)) {
        emlrtIntegerCheckR2012b(c7_d3, &c7_x_emlrtDCI, &c7_e_st);
      }

      c7_i25 = (int32_T)muDoubleScalarFloor(c7_d3);
      if ((c7_i25 < 1) || (c7_i25 > 162)) {
        emlrtDynamicBoundsCheckR2012b(c7_i25, 1, 162, &c7_v_emlrtBCI, &c7_e_st);
      }

      c7_Apadpre[(c7_i21 + 5 * (c7_i25 - 1)) - 1] = c7_b_A[(c7_i12 + ((c7_i17 -
        1) << 2)) - 1];
    }
  }

  c7_d_st.site = &c7_ad_emlrtRSI;
  c7_e_st.site = &c7_t_emlrtRSI;
  for (c7_e_j = 0; c7_e_j < 2; c7_e_j++) {
    for (c7_e_i = 0; c7_e_i < 6; c7_e_i++) {
      c7_f_i = 1.0 + (real_T)c7_e_i;
      c7_d1 = (real_T)(c7_e_j + 163);
      if (c7_d1 != (real_T)(int32_T)muDoubleScalarFloor(c7_d1)) {
        emlrtIntegerCheckR2012b(c7_d1, &c7_bl_emlrtDCI, &c7_e_st);
      }

      c7_i11 = (int32_T)muDoubleScalarFloor(c7_d1);
      if ((c7_i11 < 1) || (c7_i11 > 164)) {
        emlrtDynamicBoundsCheckR2012b(c7_i11, 1, 164, &c7_am_emlrtBCI, &c7_e_st);
      }

      if (c7_f_i != (real_T)(int32_T)muDoubleScalarFloor(c7_f_i)) {
        emlrtIntegerCheckR2012b(c7_f_i, &c7_cl_emlrtDCI, &c7_e_st);
      }

      c7_i16 = (int32_T)c7_f_i;
      if ((c7_i16 < 1) || (c7_i16 > 6)) {
        emlrtDynamicBoundsCheckR2012b(c7_i16, 1, 6, &c7_al_emlrtBCI, &c7_e_st);
      }

      c7_Apad[(c7_i16 + 6 * (c7_i11 - 1)) - 1] = MAX_uint32_T;
    }
  }

  for (c7_f_j = 0; c7_f_j < 162; c7_f_j++) {
    c7_h_j = 1.0 + (real_T)c7_f_j;
    if (c7_h_j != (real_T)(int32_T)muDoubleScalarFloor(c7_h_j)) {
      emlrtIntegerCheckR2012b(c7_h_j, &c7_al_emlrtDCI, &c7_e_st);
    }

    c7_i10 = (int32_T)c7_h_j;
    if ((c7_i10 < 1) || (c7_i10 > 164)) {
      emlrtDynamicBoundsCheckR2012b(c7_i10, 1, 164, &c7_yl_emlrtBCI, &c7_e_st);
    }

    c7_Apad[5 + 6 * (c7_i10 - 1)] = MAX_uint32_T;
  }

  for (c7_g_j = 0; c7_g_j < 162; c7_g_j++) {
    c7_h_j = 1.0 + (real_T)c7_g_j;
    for (c7_g_i = 0; c7_g_i < 5; c7_g_i++) {
      c7_f_i = 1.0 + (real_T)c7_g_i;
      if (c7_f_i != (real_T)(int32_T)muDoubleScalarFloor(c7_f_i)) {
        emlrtIntegerCheckR2012b(c7_f_i, &c7_ll_emlrtDCI, &c7_e_st);
      }

      c7_i15 = (int32_T)c7_f_i;
      if ((c7_i15 < 1) || (c7_i15 > 5)) {
        emlrtDynamicBoundsCheckR2012b(c7_i15, 1, 5, &c7_tl_emlrtBCI, &c7_e_st);
      }

      if (c7_h_j != (real_T)(int32_T)muDoubleScalarFloor(c7_h_j)) {
        emlrtIntegerCheckR2012b(c7_h_j, &c7_ml_emlrtDCI, &c7_e_st);
      }

      c7_i19 = (int32_T)c7_h_j;
      if ((c7_i19 < 1) || (c7_i19 > 162)) {
        emlrtDynamicBoundsCheckR2012b(c7_i19, 1, 162, &c7_em_emlrtBCI, &c7_e_st);
      }

      if (c7_f_i != (real_T)(int32_T)muDoubleScalarFloor(c7_f_i)) {
        emlrtIntegerCheckR2012b(c7_f_i, &c7_nl_emlrtDCI, &c7_e_st);
      }

      c7_i23 = (int32_T)c7_f_i;
      if ((c7_i23 < 1) || (c7_i23 > 6)) {
        emlrtDynamicBoundsCheckR2012b(c7_i23, 1, 6, &c7_vl_emlrtBCI, &c7_e_st);
      }

      if (c7_h_j != (real_T)(int32_T)muDoubleScalarFloor(c7_h_j)) {
        emlrtIntegerCheckR2012b(c7_h_j, &c7_ol_emlrtDCI, &c7_e_st);
      }

      c7_i27 = (int32_T)c7_h_j;
      if ((c7_i27 < 1) || (c7_i27 > 164)) {
        emlrtDynamicBoundsCheckR2012b(c7_i27, 1, 164, &c7_fm_emlrtBCI, &c7_e_st);
      }

      c7_Apad[(c7_i23 + 6 * (c7_i27 - 1)) - 1] = c7_Apadpre[(c7_i15 + 5 *
        (c7_i19 - 1)) - 1];
    }
  }

  c7_d_st.site = &c7_bd_emlrtRSI;
  for (c7_i9 = 0; c7_i9 < 3; c7_i9++) {
    c7_nhood[c7_i9] = true;
  }

  for (c7_i13 = 0; c7_i13 < 2; c7_i13++) {
    c7_asizeT[c7_i13] = 6.0 + 158.0 * (real_T)c7_i13;
  }

  for (c7_i14 = 0; c7_i14 < 2; c7_i14++) {
    c7_nsizeT[c7_i14] = 3.0 + -2.0 * (real_T)c7_i14;
  }

  erode_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0], &c7_nsizeT
                      [0], 2.0, 120.0, &c7_e_B[0], true);
  c7_d_st.site = &c7_bd_emlrtRSI;
  for (c7_i18 = 0; c7_i18 < 984; c7_i18++) {
    c7_Apad[c7_i18] = c7_e_B[c7_i18];
  }

  c7_b_nhood = true;
  for (c7_i20 = 0; c7_i20 < 2; c7_i20++) {
    c7_asizeT[c7_i20] = 6.0 + 158.0 * (real_T)c7_i20;
  }

  for (c7_i22 = 0; c7_i22 < 2; c7_i22++) {
    c7_nsizeT[c7_i22] = 1.0;
  }

  erode_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_b_nhood, &c7_nsizeT[0],
                      2.0, 120.0, &c7_e_B[0], true);
  c7_d_st.site = &c7_bd_emlrtRSI;
  for (c7_i24 = 0; c7_i24 < 984; c7_i24++) {
    c7_Apad[c7_i24] = c7_e_B[c7_i24];
  }

  for (c7_i26 = 0; c7_i26 < 3; c7_i26++) {
    c7_nhood[c7_i26] = true;
  }

  for (c7_i28 = 0; c7_i28 < 2; c7_i28++) {
    c7_asizeT[c7_i28] = 6.0 + 158.0 * (real_T)c7_i28;
  }

  for (c7_i29 = 0; c7_i29 < 2; c7_i29++) {
    c7_nsizeT[c7_i29] = 1.0 + 2.0 * (real_T)c7_i29;
  }

  erode_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0], &c7_nsizeT
                      [0], 2.0, 120.0, &c7_e_B[0], true);
  c7_d_st.site = &c7_bd_emlrtRSI;
  for (c7_i30 = 0; c7_i30 < 984; c7_i30++) {
    c7_Apad[c7_i30] = c7_e_B[c7_i30];
  }

  c7_c_nhood = true;
  for (c7_i31 = 0; c7_i31 < 2; c7_i31++) {
    c7_asizeT[c7_i31] = 6.0 + 158.0 * (real_T)c7_i31;
  }

  for (c7_i32 = 0; c7_i32 < 2; c7_i32++) {
    c7_nsizeT[c7_i32] = 1.0;
  }

  erode_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_c_nhood, &c7_nsizeT[0],
                      2.0, 120.0, &c7_e_B[0], true);
  c7_d_st.site = &c7_bd_emlrtRSI;
  for (c7_i33 = 0; c7_i33 < 984; c7_i33++) {
    c7_Apad[c7_i33] = c7_e_B[c7_i33];
  }

  for (c7_i34 = 0; c7_i34 < 3; c7_i34++) {
    c7_nhood[c7_i34] = true;
  }

  for (c7_i35 = 0; c7_i35 < 2; c7_i35++) {
    c7_asizeT[c7_i35] = 6.0 + 158.0 * (real_T)c7_i35;
  }

  for (c7_i36 = 0; c7_i36 < 2; c7_i36++) {
    c7_nsizeT[c7_i36] = 1.0 + 2.0 * (real_T)c7_i36;
  }

  erode_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0], &c7_nsizeT
                      [0], 2.0, 120.0, &c7_e_B[0], true);
  c7_d_st.site = &c7_bd_emlrtRSI;
  for (c7_i37 = 0; c7_i37 < 984; c7_i37++) {
    c7_Apad[c7_i37] = c7_e_B[c7_i37];
  }

  for (c7_i38 = 0; c7_i38 < 3; c7_i38++) {
    c7_nhood[c7_i38] = true;
  }

  for (c7_i39 = 0; c7_i39 < 2; c7_i39++) {
    c7_asizeT[c7_i39] = 6.0 + 158.0 * (real_T)c7_i39;
  }

  for (c7_i40 = 0; c7_i40 < 2; c7_i40++) {
    c7_nsizeT[c7_i40] = 3.0 + -2.0 * (real_T)c7_i40;
  }

  erode_packed_uint32(&c7_Apad[0], &c7_asizeT[0], 2.0, &c7_nhood[0], &c7_nsizeT
                      [0], 2.0, 120.0, &c7_e_B[0], true);
  c7_i41 = 0;
  c7_i42 = 0;
  for (c7_i43 = 0; c7_i43 < 160; c7_i43++) {
    for (c7_i44 = 0; c7_i44 < 4; c7_i44++) {
      c7_d_B[c7_i44 + c7_i41] = c7_e_B[(c7_i44 + c7_i42) + 13];
    }

    c7_i41 += 4;
    c7_i42 += 6;
  }
}

const mxArray *sf_c7_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c7_nameCaptureInfo;
}

static void c7_emlrt_marshallIn(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c7_nullptr, const char_T *c7_identifier,
  boolean_T c7_y[19200])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = (const char_T *)c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_nullptr), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_nullptr);
}

static void c7_b_emlrt_marshallIn(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  boolean_T c7_y[19200])
{
  int32_T c7_i;
  boolean_T c7_bv[19200];
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_bv, 1, 11, 0U, 1, 0U, 2, 120,
                160);
  for (c7_i = 0; c7_i < 19200; c7_i++) {
    c7_y[c7_i] = c7_bv[c7_i];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_slStringInitializeDynamicBuffers
  (SFc7_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c7_chart_data_browse_helper(SFc7_flightControlSystemInstanceStruct
  *chartInstance, int32_T c7_ssIdNumber, const mxArray **c7_mxData, uint8_T
  *c7_isValueTooBig)
{
  *c7_mxData = NULL;
  *c7_mxData = NULL;
  *c7_isValueTooBig = 0U;
  switch (c7_ssIdNumber) {
   case 4U:
    sf_mex_assign(c7_mxData, sf_mex_create("mxData", *chartInstance->c7_R, 3, 0U,
      1, 0U, 2, 120, 160), false);
    break;

   case 5U:
    sf_mex_assign(c7_mxData, sf_mex_create("mxData", *chartInstance->c7_BW, 11,
      0U, 1, 0U, 2, 120, 160), false);
    break;

   case 6U:
    sf_mex_assign(c7_mxData, sf_mex_create("mxData", *chartInstance->c7_d_G, 3,
      0U, 1, 0U, 2, 120, 160), false);
    break;

   case 7U:
    sf_mex_assign(c7_mxData, sf_mex_create("mxData", *chartInstance->c7_c_B, 3,
      0U, 1, 0U, 2, 120, 160), false);
    break;
  }
}

static const mxArray *c7_warning(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c7_sp, const mxArray *c7_input0, const
  mxArray *c7_input1)
{
  const mxArray *c7_m = NULL;
  (void)chartInstance;
  c7_m = NULL;
  sf_mex_assign(&c7_m, sf_mex_call(c7_sp, NULL, "warning", 1U, 2U, 14,
    sf_mex_dup(c7_input0), 14, sf_mex_dup(c7_input1)), false);
  sf_mex_destroy(&c7_input0);
  sf_mex_destroy(&c7_input1);
  return c7_m;
}

static const mxArray *c7_b_warning(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c7_sp, const mxArray *c7_input0)
{
  const mxArray *c7_m = NULL;
  (void)chartInstance;
  c7_m = NULL;
  sf_mex_assign(&c7_m, sf_mex_call(c7_sp, NULL, "warning", 0U, 1U, 14,
    sf_mex_dup(c7_input0)), false);
  sf_mex_destroy(&c7_input0);
  return c7_m;
}

static void c7_array_int32_T_SetSize(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c7_sp, c7_coder_array_int32_T *c7_coderArray,
  const emlrtRTEInfo *c7_srcLocation, int32_T c7_size0)
{
  int32_T c7_newCapacity;
  int32_T c7_newNumel;
  int32_T *c7_newData;
  (void)chartInstance;
  c7_coderArray->size[0] = c7_size0;
  c7_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c7_coderArray->size[0], c7_srcLocation, (void *)c7_sp);
  if (c7_newNumel > c7_coderArray->vector.allocated) {
    c7_newCapacity = c7_coderArray->vector.allocated;
    if (c7_newCapacity < 16) {
      c7_newCapacity = 16;
    }

    while (c7_newCapacity < c7_newNumel) {
      if (c7_newCapacity > 1073741823) {
        c7_newCapacity = MAX_int32_T;
      } else {
        c7_newCapacity <<= 1;
      }
    }

    c7_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c7_newCapacity);
    if ((void *)c7_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c7_srcLocation, (void *)c7_sp);
    }

    if ((void *)c7_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c7_srcLocation, (void *)c7_sp);
    }

    if (c7_coderArray->vector.data != NULL) {
      memcpy(c7_newData, c7_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c7_coderArray->vector.numel);
      if (c7_coderArray->vector.owner) {
        emlrtFreeMex(c7_coderArray->vector.data);
      }
    }

    c7_coderArray->vector.data = c7_newData;
    c7_coderArray->vector.allocated = c7_newCapacity;
    c7_coderArray->vector.owner = true;
  }

  c7_coderArray->vector.numel = c7_newNumel;
}

static void c7_array_real_T_2D_SetSize(SFc7_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c7_sp, c7_coder_array_real_T_2D
  *c7_coderArray, const emlrtRTEInfo *c7_srcLocation, int32_T c7_size0, int32_T
  c7_size1)
{
  real_T *c7_newData;
  int32_T c7_newCapacity;
  int32_T c7_newNumel;
  (void)chartInstance;
  c7_coderArray->size[0] = c7_size0;
  c7_coderArray->size[1] = c7_size1;
  c7_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c7_coderArray->size[0],
                       c7_srcLocation, (void *)c7_sp), (size_t)(uint32_T)
    c7_coderArray->size[1], c7_srcLocation, (void *)c7_sp);
  if (c7_newNumel > c7_coderArray->vector.allocated) {
    c7_newCapacity = c7_coderArray->vector.allocated;
    if (c7_newCapacity < 16) {
      c7_newCapacity = 16;
    }

    while (c7_newCapacity < c7_newNumel) {
      if (c7_newCapacity > 1073741823) {
        c7_newCapacity = MAX_int32_T;
      } else {
        c7_newCapacity <<= 1;
      }
    }

    c7_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c7_newCapacity);
    if ((void *)c7_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c7_srcLocation, (void *)c7_sp);
    }

    if ((void *)c7_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c7_srcLocation, (void *)c7_sp);
    }

    if (c7_coderArray->vector.data != NULL) {
      memcpy(c7_newData, c7_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c7_coderArray->vector.numel);
      if (c7_coderArray->vector.owner) {
        emlrtFreeMex(c7_coderArray->vector.data);
      }
    }

    c7_coderArray->vector.data = c7_newData;
    c7_coderArray->vector.allocated = c7_newCapacity;
    c7_coderArray->vector.owner = true;
  }

  c7_coderArray->vector.numel = c7_newNumel;
}

static void c7_array_int32_T_Constructor(SFc7_flightControlSystemInstanceStruct *
  chartInstance, c7_coder_array_int32_T *c7_coderArray)
{
  (void)chartInstance;
  c7_coderArray->vector.data = (int32_T *)NULL;
  c7_coderArray->vector.numel = 0;
  c7_coderArray->vector.allocated = 0;
  c7_coderArray->vector.owner = true;
  c7_coderArray->size[0] = 0;
}

static void c7_array_real_T_2D_Constructor
  (SFc7_flightControlSystemInstanceStruct *chartInstance,
   c7_coder_array_real_T_2D *c7_coderArray)
{
  (void)chartInstance;
  c7_coderArray->vector.data = (real_T *)NULL;
  c7_coderArray->vector.numel = 0;
  c7_coderArray->vector.allocated = 0;
  c7_coderArray->vector.owner = true;
  c7_coderArray->size[0] = 0;
  c7_coderArray->size[1] = 0;
}

static void c7_array_int32_T_Destructor(SFc7_flightControlSystemInstanceStruct
  *chartInstance, c7_coder_array_int32_T *c7_coderArray)
{
  (void)chartInstance;
  if (c7_coderArray->vector.owner && (c7_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c7_coderArray->vector.data);
  }
}

static void c7_array_real_T_2D_Destructor(SFc7_flightControlSystemInstanceStruct
  *chartInstance, c7_coder_array_real_T_2D *c7_coderArray)
{
  (void)chartInstance;
  if (c7_coderArray->vector.owner && (c7_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c7_coderArray->vector.data);
  }
}

static void init_dsm_address_info(SFc7_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc7_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c7_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c7_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c7_R = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c7_BW = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c7_d_G = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c7_c_B = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c7_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2421789986U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2303631629U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(826816851U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(985392025U);
}

mxArray *sf_c7_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,8);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.IppfilterBuildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.ImfilterBuildable"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "images.internal.coder.buildable.GetnumcoresBuildable"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "images.internal.coder.buildable.Grayto8Buildable"));
  mxSetCell(mxcell3p, 4, mxCreateString(
             "images.internal.coder.buildable.IppreconstructBuildable"));
  mxSetCell(mxcell3p, 5, mxCreateString(
             "images.internal.coder.buildable.BwpacktbbBuildable"));
  mxSetCell(mxcell3p, 6, mxCreateString(
             "images.internal.coder.buildable.Morphop_packed_Buildable"));
  mxSetCell(mxcell3p, 7, mxCreateString(
             "images.internal.coder.buildable.BwunpacktbbBuildable"));
  return(mxcell3p);
}

mxArray *sf_c7_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("ippfilter_real64");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c7_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c7_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiCWYGRgYAPSHEDMxAABrFA+IxKGiLPAxRWAuKSyIBUkXlyU7JkCpPMSc8H8xNI"
    "Kz7y0fLD5FgwI89kImM8JFYeAD/aU6RdxAOk3QNLPgkU/E5J+ASDPKRwSLiAAAC2fDNY="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sgRMmah8GsqPU5Gkxn4YVDF";
}

static void sf_opaque_initialize_c7_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c7_flightControlSystem
    ((SFc7_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c7_flightControlSystem(void *chartInstanceVar)
{
  enable_c7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c7_flightControlSystem(void *chartInstanceVar)
{
  disable_c7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c7_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c7_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c7_flightControlSystem
    ((SFc7_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c7_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c7_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c7_flightControlSystem
      ((SFc7_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c7_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc7_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c7_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c7_flightControlSystem((SFc7_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_flightControlSystem(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_flightControlSystem
      ((SFc7_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c7_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [21] = {
    "eNrdWE2P20QYnmSXVYtKVSTUVhUSHJEQCLpU7aGC3c3HEmnDRnV2K7igif3GHmU89s5HPvhBPXD",
    "hwoULZ44c+RlckDjyjuNk0yRsPA5oFyw5zth55n3nmef9cEil1SZ43MWz84CQPbzewrNKpscb+b",
    "iycE7v75Ln+bjzJiF+RKVuiX5C3A8/CSAE4Zl+n40dscLEHSpprErYFTSGF6ASbjRLhJvzTPRBg",
    "vBxgjSR2smuYrHhTAyaRvjWsnoZMT/yosTw4AgnpMGp4JO/s5sa3UGLdSbB102AQEcyMWHU5DS8",
    "mgWpR7UI/IEysTNXCrRnUrtU1TZcs5RDYwx+SyhNkQW1Yb2ephpqeuysEKa8GTqJU86oKM51RJU",
    "HKapDw1ka4Oep0cheQbtor8cE1YlklDdiXrMKL4jtcPSzjbLmzjzrWNehZ8KQidCyK00MAtePOi",
    "nAVb+WDEHSEE6FYwza1TXG2QbPdVk8BltWlqVi0MTTXVGlsJndxhAZUiXtNn1Ro5wrN2w3SU9gC",
    "DyzX6ealsBO7TuAlWJBNzmn0kaBYyQZwS4M5NhaIgJWfIeHS6gs4X6FybMAnMVWUhAgzXPX5xNt",
    "0qRROolrGEb1k5OC9laxLaFB9qkPhXOfpEwBOpzpytFuwBTtcYtGlnS2ysIzgCgNJapvRH2UyAF",
    "y7JpkL7mykeCGhiCEOmjIEkYD1X1OuSnoc6www1l5nCnMWG52EWvjpxTYp34Ega0njEMblJ1AFc",
    "7PWEcOcbVDpid1UL5kadFIMgoCLCSWpe4khTMxEMlINGUSe3lHcIWuADBrUCmwLBxhWZKTJjpfz",
    "GsJF12rrDLtWUw1pz2rjWMQWFnsWm0lpD5GVUNg64YObYP12HdY2oViSmM7NWlkMRBk/ejDils/",
    "+nY+3p/HUkt1Je4UxTIssFM67GXNHnRZDNkNj2JPMR3mh7X7Cbm0e7t6td0qfquUxJEtcV8u4Hb",
    "X8HN/AXcvH/tPv+1zFkY2CWuZcG+CvMerftwpwPc6/5dxZAV3yfPs+sECvrLGLlm4buJrZ4WvHV",
    "KpVDLcwQLurSU7u0u4vZyz1h8/Pvr41/1X37/64acPmz/vbqOPXxz1fDcfvzvrz+YVbLiS5Ivo4",
    "cGSHuxYhS/aMY2eHauLztmT48FYfPb1eb1ZKv5m99/HU2OCy/Kl9FtB/q5lx9RM3wHs/M8W/N3b",
    "MP/tBT0R8vsX2+HfOVjex3V8VV/jq0qOXr6u25ueJ64rL12nn0Xy1k5JXIX8e3nyn8Rtuz7XfPx",
    "f//1VeYAs/f7eDV7H8rVsXb5p6/qNuNWh9/Lx5/N35lrEeLCma88fY2PdX/f0f6LvPx35m/UJDc",
    "tf/qffN/uHgvIJtunT16D8dkfa/5vmjyRQtf5d6Drq0Ox6sKHO31mKbzseMREkI/XRp4+fPN6mr",
    "v0FzOMAxg==",
    ""
  };

  static char newstr [1437] = "";
  newstr[0] = '\0';
  for (i = 0; i < 21; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c7_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c7_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(448066889U));
  ssSetChecksum1(S,(2788413486U));
  ssSetChecksum2(S,(3115296426U));
  ssSetChecksum3(S,(79578667U));
}

static void mdlRTW_c7_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c7_flightControlSystem(SimStruct *S)
{
  SFc7_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc7_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc7_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc7_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c7_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c7_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c7_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c7_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_flightControlSystem;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c7_flightControlSystem(chartInstance);
}

void c7_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c7_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
