/*
 * Copyright (c) 1997-1999, 2003 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Mon Mar 24 02:08:53 EST 2003 */

#include "fftw-int.h"
#include "fftw.h"

/* Generated by: /homee/stevenj/cvs/fftw/gensrc/genfft -magic-alignment-check -magic-twiddle-load-all -magic-variables 4 -magic-loopi -hc2hc-backward 5 */

/*
 * This function contains 64 FP additions, 42 FP multiplications,
 * (or, 42 additions, 20 multiplications, 22 fused multiply/add),
 * 25 stack variables, and 40 memory accesses
 */
static const fftw_real K250000000 =
FFTW_KONST(+0.250000000000000000000000000000000000000000000);
static const fftw_real K559016994 =
FFTW_KONST(+0.559016994374947424102293417182819058860154590);
static const fftw_real K951056516 =
FFTW_KONST(+0.951056516295153572116439333379382143405698634);
static const fftw_real K587785252 =
FFTW_KONST(+0.587785252292473129168705954639072768597652438);
static const fftw_real K2_000000000 =
FFTW_KONST(+2.000000000000000000000000000000000000000000000);
static const fftw_real K500000000 =
FFTW_KONST(+0.500000000000000000000000000000000000000000000);
static const fftw_real K1_118033988 =
FFTW_KONST(+1.118033988749894848204586834365638117720309180);
static const fftw_real K1_175570504 =
FFTW_KONST(+1.175570504584946258337411909278145537195304875);
static const fftw_real K1_902113032 =
FFTW_KONST(+1.902113032590307144232878666758764286811397268);

/*
 * Generator Id's : 
 * $Id: exprdag.ml,v 1.43 2003/03/16 23:43:46 stevenj Exp $
 * $Id: fft.ml,v 1.44 2003/03/16 23:43:46 stevenj Exp $
 * $Id: to_c.ml,v 1.26 2003/03/16 23:43:46 stevenj Exp $
 */

void fftw_hc2hc_backward_5(fftw_real *A, const fftw_complex *W,
			   int iostride, int m, int dist)
{
     int i;
     fftw_real *X;
     fftw_real *Y;
     X = A;
     Y = A + (5 * iostride);
     {
	  fftw_real tmp70;
	  fftw_real tmp72;
	  fftw_real tmp61;
	  fftw_real tmp64;
	  fftw_real tmp65;
	  fftw_real tmp66;
	  fftw_real tmp71;
	  fftw_real tmp67;
	  ASSERT_ALIGNED_DOUBLE;
	  {
	       fftw_real tmp68;
	       fftw_real tmp69;
	       fftw_real tmp62;
	       fftw_real tmp63;
	       ASSERT_ALIGNED_DOUBLE;
	       tmp68 = Y[-iostride];
	       tmp69 = Y[-2 * iostride];
	       tmp70 = (K1_902113032 * tmp68) + (K1_175570504 * tmp69);
	       tmp72 = (K1_902113032 * tmp69) - (K1_175570504 * tmp68);
	       tmp61 = X[0];
	       tmp62 = X[iostride];
	       tmp63 = X[2 * iostride];
	       tmp64 = tmp62 + tmp63;
	       tmp65 = K1_118033988 * (tmp62 - tmp63);
	       tmp66 = tmp61 - (K500000000 * tmp64);
	  }
	  X[0] = tmp61 + (K2_000000000 * tmp64);
	  tmp71 = tmp66 - tmp65;
	  X[3 * iostride] = tmp71 - tmp72;
	  X[2 * iostride] = tmp71 + tmp72;
	  tmp67 = tmp65 + tmp66;
	  X[4 * iostride] = tmp67 + tmp70;
	  X[iostride] = tmp67 - tmp70;
     }
     X = X + dist;
     Y = Y - dist;
     for (i = 2; i < m; i = i + 2, X = X + dist, Y = Y - dist, W = W + 4) {
	  fftw_real tmp13;
	  fftw_real tmp32;
	  fftw_real tmp50;
	  fftw_real tmp39;
	  fftw_real tmp20;
	  fftw_real tmp38;
	  fftw_real tmp21;
	  fftw_real tmp34;
	  fftw_real tmp28;
	  fftw_real tmp33;
	  fftw_real tmp43;
	  fftw_real tmp55;
	  ASSERT_ALIGNED_DOUBLE;
	  {
	       fftw_real tmp19;
	       fftw_real tmp31;
	       fftw_real tmp16;
	       fftw_real tmp30;
	       ASSERT_ALIGNED_DOUBLE;
	       tmp13 = X[0];
	       {
		    fftw_real tmp17;
		    fftw_real tmp18;
		    fftw_real tmp14;
		    fftw_real tmp15;
		    ASSERT_ALIGNED_DOUBLE;
		    tmp17 = X[2 * iostride];
		    tmp18 = Y[-3 * iostride];
		    tmp19 = tmp17 + tmp18;
		    tmp31 = tmp17 - tmp18;
		    tmp14 = X[iostride];
		    tmp15 = Y[-4 * iostride];
		    tmp16 = tmp14 + tmp15;
		    tmp30 = tmp14 - tmp15;
	       }
	       tmp32 = (K587785252 * tmp30) - (K951056516 * tmp31);
	       tmp50 = (K951056516 * tmp30) + (K587785252 * tmp31);
	       tmp39 = K559016994 * (tmp16 - tmp19);
	       tmp20 = tmp16 + tmp19;
	       tmp38 = tmp13 - (K250000000 * tmp20);
	  }
	  {
	       fftw_real tmp27;
	       fftw_real tmp42;
	       fftw_real tmp24;
	       fftw_real tmp41;
	       ASSERT_ALIGNED_DOUBLE;
	       tmp21 = Y[0];
	       {
		    fftw_real tmp25;
		    fftw_real tmp26;
		    fftw_real tmp22;
		    fftw_real tmp23;
		    ASSERT_ALIGNED_DOUBLE;
		    tmp25 = Y[-2 * iostride];
		    tmp26 = X[3 * iostride];
		    tmp27 = tmp25 - tmp26;
		    tmp42 = tmp25 + tmp26;
		    tmp22 = Y[-iostride];
		    tmp23 = X[4 * iostride];
		    tmp24 = tmp22 - tmp23;
		    tmp41 = tmp22 + tmp23;
	       }
	       tmp34 = K559016994 * (tmp24 - tmp27);
	       tmp28 = tmp24 + tmp27;
	       tmp33 = tmp21 - (K250000000 * tmp28);
	       tmp43 = (K587785252 * tmp41) - (K951056516 * tmp42);
	       tmp55 = (K951056516 * tmp41) + (K587785252 * tmp42);
	  }
	  X[0] = tmp13 + tmp20;
	  {
	       fftw_real tmp52;
	       fftw_real tmp58;
	       fftw_real tmp56;
	       fftw_real tmp60;
	       fftw_real tmp51;
	       fftw_real tmp54;
	       ASSERT_ALIGNED_DOUBLE;
	       tmp51 = tmp34 + tmp33;
	       tmp52 = tmp50 + tmp51;
	       tmp58 = tmp51 - tmp50;
	       tmp54 = tmp39 + tmp38;
	       tmp56 = tmp54 - tmp55;
	       tmp60 = tmp54 + tmp55;
	       {
		    fftw_real tmp49;
		    fftw_real tmp53;
		    fftw_real tmp57;
		    fftw_real tmp59;
		    ASSERT_ALIGNED_DOUBLE;
		    tmp49 = c_re(W[0]);
		    tmp53 = c_im(W[0]);
		    Y[-3 * iostride] = (tmp49 * tmp52) - (tmp53 * tmp56);
		    X[iostride] = (tmp53 * tmp52) + (tmp49 * tmp56);
		    tmp57 = c_re(W[3]);
		    tmp59 = c_im(W[3]);
		    Y[0] = (tmp57 * tmp58) - (tmp59 * tmp60);
		    X[4 * iostride] = (tmp59 * tmp58) + (tmp57 * tmp60);
	       }
	  }
	  Y[-4 * iostride] = tmp21 + tmp28;
	  {
	       fftw_real tmp36;
	       fftw_real tmp46;
	       fftw_real tmp44;
	       fftw_real tmp48;
	       fftw_real tmp35;
	       fftw_real tmp40;
	       ASSERT_ALIGNED_DOUBLE;
	       tmp35 = tmp33 - tmp34;
	       tmp36 = tmp32 + tmp35;
	       tmp46 = tmp35 - tmp32;
	       tmp40 = tmp38 - tmp39;
	       tmp44 = tmp40 - tmp43;
	       tmp48 = tmp40 + tmp43;
	       {
		    fftw_real tmp29;
		    fftw_real tmp37;
		    fftw_real tmp45;
		    fftw_real tmp47;
		    ASSERT_ALIGNED_DOUBLE;
		    tmp29 = c_re(W[1]);
		    tmp37 = c_im(W[1]);
		    Y[-2 * iostride] = (tmp29 * tmp36) - (tmp37 * tmp44);
		    X[2 * iostride] = (tmp37 * tmp36) + (tmp29 * tmp44);
		    tmp45 = c_re(W[2]);
		    tmp47 = c_im(W[2]);
		    Y[-iostride] = (tmp45 * tmp46) - (tmp47 * tmp48);
		    X[3 * iostride] = (tmp47 * tmp46) + (tmp45 * tmp48);
	       }
	  }
     }
     if (i == m) {
	  fftw_real tmp10;
	  fftw_real tmp12;
	  fftw_real tmp1;
	  fftw_real tmp4;
	  fftw_real tmp5;
	  fftw_real tmp6;
	  fftw_real tmp11;
	  fftw_real tmp7;
	  ASSERT_ALIGNED_DOUBLE;
	  {
	       fftw_real tmp8;
	       fftw_real tmp9;
	       fftw_real tmp2;
	       fftw_real tmp3;
	       ASSERT_ALIGNED_DOUBLE;
	       tmp8 = Y[-iostride];
	       tmp9 = Y[0];
	       tmp10 = (K1_902113032 * tmp8) + (K1_175570504 * tmp9);
	       tmp12 = (K1_175570504 * tmp8) - (K1_902113032 * tmp9);
	       tmp1 = X[2 * iostride];
	       tmp2 = X[iostride];
	       tmp3 = X[0];
	       tmp4 = tmp2 + tmp3;
	       tmp5 = (K500000000 * tmp4) - tmp1;
	       tmp6 = K1_118033988 * (tmp3 - tmp2);
	  }
	  X[0] = tmp1 + (K2_000000000 * tmp4);
	  tmp11 = tmp6 - tmp5;
	  X[2 * iostride] = tmp11 + tmp12;
	  X[3 * iostride] = tmp12 - tmp11;
	  tmp7 = tmp5 + tmp6;
	  X[iostride] = tmp7 - tmp10;
	  X[4 * iostride] = -(tmp7 + tmp10);
     }
}

static const int twiddle_order[] = { 1, 2, 3, 4 };
fftw_codelet_desc fftw_hc2hc_backward_5_desc = {
     "fftw_hc2hc_backward_5",
     (void (*)()) fftw_hc2hc_backward_5,
     5,
     FFTW_BACKWARD,
     FFTW_HC2HC,
     124,
     4,
     twiddle_order,
};
