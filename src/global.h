////**********************************************************************
////**********************************************************************
////
////  RANDOM FORESTS FOR SURVIVAL, REGRESSION, AND CLASSIFICATION (RF-SRC)
////  Version 1.0.0
////
////  Copyright 2012, University of Miami
////
////  This program is free software; you can redistribute it and/or
////  modify it under the terms of the GNU General Public License
////  as published by the Free Software Foundation; either version 2
////  of the License, or (at your option) any later version.
////
////  This program is distributed in the hope that it will be useful,
////  but WITHOUT ANY WARRANTY; without even the implied warranty of
////  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
////  GNU General Public License for more details.
////
////  You should have received a copy of the GNU General Public
////  License along with this program; if not, write to the Free
////  Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
////  Boston, MA  02110-1301, USA.
////
////  ----------------------------------------------------------------
////  Project Partially Funded By: 
////  ----------------------------------------------------------------
////  Dr. Ishwaran's work was funded in part by DMS grant 1148991 from the
////  National Science Foundation and grant R01 CA163739 from the National
////  Cancer Institute.
////
////  Dr. Kogalur's work was funded in part by grant R01 CA163739 from the 
////  National Cancer Institute.
////  ----------------------------------------------------------------
////  Written by:
////  ----------------------------------------------------------------
////    Hemant Ishwaran, Ph.D.
////    Director of Statistical Methodology
////    Professor, Division of Biostatistics
////    Clinical Research Building, Room 1058
////    1120 NW 14th Street
////    University of Miami, Miami FL 33136
////
////    email:  hemant.ishwaran@gmail.com
////    URL:    http://web.ccs.miami.edu/~hishwaran
////    --------------------------------------------------------------
////    Udaya B. Kogalur, Ph.D.
////    Adjunct Staff
////    Dept of Quantitative Health Sciences
////    Cleveland Clinic Foundation
////    
////    Kogalur & Company, Inc.
////    5425 Nestleway Drive, Suite L1
////    Clemmons, NC 27012
////
////    email:  kogalurshear@gmail.com
////    URL:    http://www.kogalur-shear.com
////    --------------------------------------------------------------
////
////**********************************************************************
////**********************************************************************


#ifndef GLOBAL_H
#define GLOBAL_H
#include <R_ext/Print.h>
#include <Rdefines.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <time.h>
#ifdef HAVE_OPENMP
#define SUPPORT_OPENMP 1
#else
#undef SUPPORT_OPENMP
#endif
#ifndef NULL
#define NULL 0
#endif
#ifndef TRUE
#define TRUE   0x01
#endif
#ifndef FALSE
#define FALSE  0x00
#endif
#define ACTIVE   0x02
#define INACTIVE 0xFF
#define LEFT      0x01
#define RIGHT     0x00
#define EPSILON 1.0e-7
#define OPT_FENS      0x000001  
#define OPT_OENS      0x000002  
#define OPT_PERF      0x000004  
#define OPT_PROX      0x000008  
#define OPT_LEAF      0x000010  
#define OPT_TREE      0x000020  
#define OPT_SEED      0x000040  
#define OPT_MISS      0x000080  
#define OPT_OMIS      0x000100  
#define OPT_VIMP_TYPE 0x000200  
#define OPT_VIMP_JOIN 0x000400  
#define OPT_MEMB      0x000800  
#define OPT_VUSE_TYPE 0x001000  
#define OPT_VUSE      0x002000  
#define OPT_REST      0x004000  
#define OPT_PERF_CALB 0x008000  
#define OPT_IMPU_ONLY 0x010000  
#define OPT_OUTC_TYPE 0x020000  
#define OPT_SPLT_FAST 0x040000  
#define OPT_BOOT_NODE 0x080000  
#define OPT_BOOT_NONE 0x100000  
#define OPT_COMP_RISK 0x200000  
#define OPT_SPLDPTH_F 0x400000  
#define OPT_SPLDPTH_T 0x800000  
#define OPT_VIMP_LEOB 0x1000000  
#define OPT_VIMP      0x2000000  
#define OPT_MORT_WGHT 0x4000000  
#define RF_OUTP_ID   0  
#define RF_STRG_ID   1  
#define RF_FENS_ID   2  
#define RF_OENS_ID   3  
#define RF_PERF_ID   4  
#define RF_PROX_ID   5  
#define RF_LEAF_ID   6  
#define RF_TREE_ID   7  
#define RF_NODE_ID   8  
#define RF_PARM_ID   9  
#define RF_CONT_PT  10  
#define RF_MWCP_SZ  11  
#define RF_MWCP_PT  12  
#define RF_SEED_ID  13  
#define RF_VIMP_ID  14  
#define RF_MISS_ID  15  
#define RF_OMIS_ID  16  
#define RF_VUSE_ID  17  
#define RF_DPTH_ID  18  
#define RF_FCIF_ID  19  
#define RF_OCIF_ID  20  
#define RF_FSRV_ID  21  
#define RF_OSRV_ID  22  
#define RF_FMRT_ID  23  
#define RF_OMRT_ID  24  
#define RF_NMBR_ID  25  
#define RF_BMBR_ID  26  
#define RF_SEXP_CNT 27  
#define RF_GROW   0x01
#define RF_PRED   0x02
#define RF_REST   0x08
#define SURV_LGRNK  1  
#define SURV_CNSEV  2  
#define SURV_LRSCR  3
#define SURV_CR_LAU 4  
#define SURV_CR_LOG 5  
#define SURV_CR_SCH 6  
#define REGR_SPLIT  7  
#define CLAS_SPLIT  8  
#define RAND_SPLIT  9  
#define APROX 0
#define EXACT 1
#define SIZE_OF_INTEGER sizeof(uint)
#define MAX_EXACT_LEVEL SIZE_OF_INTEGER * 8
#define SAFE_FACTOR_SIZE 8
typedef unsigned int   uint;
typedef unsigned long  ulong; 
typedef unsigned char  uchar; 
#endif