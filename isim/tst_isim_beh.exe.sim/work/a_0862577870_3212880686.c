/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/amir_/Desktop/CAL_HW11_B/monitor.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3620187407;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
unsigned char ieee_p_3620187407_sub_2546382208_3965413181(char *, char *, char *, int );
unsigned char ieee_p_3620187407_sub_3908131327_3965413181(char *, char *, char *, int );
char *ieee_p_3620187407_sub_436279890_3965413181(char *, char *, char *, char *, int );
char *ieee_p_3620187407_sub_436351764_3965413181(char *, char *, char *, char *, int );


static void work_a_0862577870_3212880686_p_0(char *t0)
{
    char t10[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int t7;
    int t8;
    unsigned char t9;
    char *t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned char t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;

LAB0:    xsi_set_current_line(81, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 8520);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(82, ng0);
    t3 = (t0 + 2472U);
    t4 = *((char **)t3);
    t3 = (t0 + 12976U);
    t5 = (t0 + 3528U);
    t6 = *((char **)t5);
    t7 = *((int *)t6);
    t8 = (t7 - 1);
    t9 = ieee_p_3620187407_sub_2546382208_3965413181(IEEE_P_3620187407, t4, t3, t8);
    if (t9 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(85, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t1 = (t0 + 12992U);
    t4 = (t0 + 4128U);
    t5 = *((char **)t4);
    t7 = *((int *)t5);
    t8 = (t7 - 1);
    t2 = ieee_p_3620187407_sub_2546382208_3965413181(IEEE_P_3620187407, t3, t1, t8);
    if (t2 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(88, ng0);
    t1 = xsi_get_transient_memory(11U);
    memset(t1, 0, 11U);
    t3 = t1;
    memset(t3, (unsigned char)2, 11U);
    t4 = (t0 + 8840);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t11 = (t6 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 11U);
    xsi_driver_first_trans_fast(t4);

LAB11:    xsi_set_current_line(90, ng0);
    t1 = xsi_get_transient_memory(11U);
    memset(t1, 0, 11U);
    t3 = t1;
    memset(t3, (unsigned char)2, 11U);
    t4 = (t0 + 8776);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t11 = (t6 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 11U);
    xsi_driver_first_trans_fast(t4);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(83, ng0);
    t5 = (t0 + 2472U);
    t11 = *((char **)t5);
    t5 = (t0 + 12976U);
    t12 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t10, t11, t5, 1);
    t13 = (t10 + 12U);
    t14 = *((unsigned int *)t13);
    t15 = (1U * t14);
    t16 = (11U != t15);
    if (t16 == 1)
        goto LAB8;

LAB9:    t17 = (t0 + 8776);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t12, 11U);
    xsi_driver_first_trans_fast(t17);
    goto LAB6;

LAB8:    xsi_size_not_matching(11U, t15, 0);
    goto LAB9;

LAB10:    xsi_set_current_line(86, ng0);
    t4 = (t0 + 2632U);
    t6 = *((char **)t4);
    t4 = (t0 + 12992U);
    t11 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t10, t6, t4, 1);
    t12 = (t10 + 12U);
    t14 = *((unsigned int *)t12);
    t15 = (1U * t14);
    t9 = (11U != t15);
    if (t9 == 1)
        goto LAB13;

LAB14:    t13 = (t0 + 8840);
    t17 = (t13 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t11, 11U);
    xsi_driver_first_trans_fast(t13);
    goto LAB11;

LAB13:    xsi_size_not_matching(11U, t15, 0);
    goto LAB14;

}

static void work_a_0862577870_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    int t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(96, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t1 = (t0 + 12976U);
    t3 = (t0 + 3888U);
    t4 = *((char **)t3);
    t5 = *((int *)t4);
    t6 = ieee_p_3620187407_sub_2546382208_3965413181(IEEE_P_3620187407, t2, t1, t5);
    if (t6 != 0)
        goto LAB3;

LAB4:
LAB5:    t11 = (t0 + 8904);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t11);

LAB2:    t16 = (t0 + 8536);
    *((int *)t16) = 1;

LAB1:    return;
LAB3:    t3 = (t0 + 8904);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t3);
    goto LAB2;

LAB6:    goto LAB2;

}

static void work_a_0862577870_3212880686_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    int t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(99, ng0);
    t1 = (t0 + 2632U);
    t2 = *((char **)t1);
    t1 = (t0 + 12992U);
    t3 = (t0 + 4488U);
    t4 = *((char **)t3);
    t5 = *((int *)t4);
    t6 = ieee_p_3620187407_sub_2546382208_3965413181(IEEE_P_3620187407, t2, t1, t5);
    if (t6 != 0)
        goto LAB3;

LAB4:
LAB5:    t11 = (t0 + 8968);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t11);

LAB2:    t16 = (t0 + 8552);
    *((int *)t16) = 1;

LAB1:    return;
LAB3:    t3 = (t0 + 8968);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t3);
    goto LAB2;

LAB6:    goto LAB2;

}

static void work_a_0862577870_3212880686_p_3(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    int t8;
    int t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    int t14;
    char *t15;
    int t16;
    int t17;
    char *t18;
    int t19;
    int t20;
    unsigned char t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;

LAB0:    xsi_set_current_line(102, ng0);
    t2 = (t0 + 2472U);
    t3 = *((char **)t2);
    t2 = (t0 + 12976U);
    t4 = (t0 + 3888U);
    t5 = *((char **)t4);
    t6 = *((int *)t5);
    t4 = (t0 + 3648U);
    t7 = *((char **)t4);
    t8 = *((int *)t7);
    t9 = (t6 + t8);
    t10 = ieee_p_3620187407_sub_3908131327_3965413181(IEEE_P_3620187407, t3, t2, t9);
    if (t10 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB8:    t26 = (t0 + 9032);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = (unsigned char)3;
    xsi_driver_first_trans_fast(t26);

LAB2:    t31 = (t0 + 8568);
    *((int *)t31) = 1;

LAB1:    return;
LAB3:    t12 = (t0 + 9032);
    t22 = (t12 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    *((unsigned char *)t25) = (unsigned char)2;
    xsi_driver_first_trans_fast(t12);
    goto LAB2;

LAB5:    t4 = (t0 + 2472U);
    t11 = *((char **)t4);
    t4 = (t0 + 12976U);
    t12 = (t0 + 3888U);
    t13 = *((char **)t12);
    t14 = *((int *)t13);
    t12 = (t0 + 3648U);
    t15 = *((char **)t12);
    t16 = *((int *)t15);
    t17 = (t14 + t16);
    t12 = (t0 + 3408U);
    t18 = *((char **)t12);
    t19 = *((int *)t18);
    t20 = (t17 + t19);
    t21 = ieee_p_3620187407_sub_2546382208_3965413181(IEEE_P_3620187407, t11, t4, t20);
    t1 = t21;
    goto LAB7;

LAB9:    goto LAB2;

}

static void work_a_0862577870_3212880686_p_4(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    int t8;
    int t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    int t14;
    char *t15;
    int t16;
    int t17;
    char *t18;
    int t19;
    int t20;
    unsigned char t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;

LAB0:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 2632U);
    t3 = *((char **)t2);
    t2 = (t0 + 12992U);
    t4 = (t0 + 4488U);
    t5 = *((char **)t4);
    t6 = *((int *)t5);
    t4 = (t0 + 4248U);
    t7 = *((char **)t4);
    t8 = *((int *)t7);
    t9 = (t6 + t8);
    t10 = ieee_p_3620187407_sub_3908131327_3965413181(IEEE_P_3620187407, t3, t2, t9);
    if (t10 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB8:    t26 = (t0 + 9096);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = (unsigned char)3;
    xsi_driver_first_trans_fast(t26);

LAB2:    t31 = (t0 + 8584);
    *((int *)t31) = 1;

LAB1:    return;
LAB3:    t12 = (t0 + 9096);
    t22 = (t12 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    *((unsigned char *)t25) = (unsigned char)2;
    xsi_driver_first_trans_fast(t12);
    goto LAB2;

LAB5:    t4 = (t0 + 2632U);
    t11 = *((char **)t4);
    t4 = (t0 + 12992U);
    t12 = (t0 + 4488U);
    t13 = *((char **)t12);
    t14 = *((int *)t13);
    t12 = (t0 + 4248U);
    t15 = *((char **)t12);
    t16 = *((int *)t15);
    t17 = (t14 + t16);
    t12 = (t0 + 4008U);
    t18 = *((char **)t12);
    t19 = *((int *)t18);
    t20 = (t17 + t19);
    t21 = ieee_p_3620187407_sub_2546382208_3965413181(IEEE_P_3620187407, t11, t4, t20);
    t1 = t21;
    goto LAB7;

LAB9:    goto LAB2;

}

static void work_a_0862577870_3212880686_p_5(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    char *t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;

LAB0:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 1992U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)3);
    if (t5 == 1)
        goto LAB5;

LAB6:    t2 = (t0 + 2152U);
    t6 = *((char **)t2);
    t7 = *((unsigned char *)t6);
    t8 = (t7 == (unsigned char)3);
    t1 = t8;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB8:    t13 = (t0 + 9160);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    *((unsigned char *)t17) = (unsigned char)2;
    xsi_driver_first_trans_fast(t13);

LAB2:    t18 = (t0 + 8600);
    *((int *)t18) = 1;

LAB1:    return;
LAB3:    t2 = (t0 + 9160);
    t9 = (t2 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    goto LAB2;

LAB5:    t1 = (unsigned char)1;
    goto LAB7;

LAB9:    goto LAB2;

}

static void work_a_0862577870_3212880686_p_6(char *t0)
{
    char t5[16];
    char t6[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t7;
    char *t8;
    char *t9;
    int t10;
    char *t11;
    char *t12;
    int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned char t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;

LAB0:    xsi_set_current_line(111, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB3;

LAB4:
LAB7:    t23 = xsi_get_transient_memory(11U);
    memset(t23, 0, 11U);
    t24 = t23;
    memset(t24, (unsigned char)2, 11U);
    t25 = (t0 + 9224);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    memcpy(t29, t23, 11U);
    xsi_driver_first_trans_fast(t25);

LAB2:    t30 = (t0 + 8616);
    *((int *)t30) = 1;

LAB1:    return;
LAB3:    t1 = (t0 + 2472U);
    t7 = *((char **)t1);
    t1 = (t0 + 12976U);
    t8 = (t0 + 3888U);
    t9 = *((char **)t8);
    t10 = *((int *)t9);
    t8 = ieee_p_3620187407_sub_436351764_3965413181(IEEE_P_3620187407, t6, t7, t1, t10);
    t11 = (t0 + 3648U);
    t12 = *((char **)t11);
    t13 = *((int *)t12);
    t11 = ieee_p_3620187407_sub_436351764_3965413181(IEEE_P_3620187407, t5, t8, t6, t13);
    t14 = (t5 + 12U);
    t15 = *((unsigned int *)t14);
    t16 = (1U * t15);
    t17 = (11U != t16);
    if (t17 == 1)
        goto LAB5;

LAB6:    t18 = (t0 + 9224);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t11, 11U);
    xsi_driver_first_trans_fast(t18);
    goto LAB2;

LAB5:    xsi_size_not_matching(11U, t16, 0);
    goto LAB6;

LAB8:    goto LAB2;

}

static void work_a_0862577870_3212880686_p_7(char *t0)
{
    char t5[16];
    char t6[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t7;
    char *t8;
    char *t9;
    int t10;
    char *t11;
    char *t12;
    int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned char t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;

LAB0:    xsi_set_current_line(113, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB3;

LAB4:
LAB7:    t23 = xsi_get_transient_memory(11U);
    memset(t23, 0, 11U);
    t24 = t23;
    memset(t24, (unsigned char)2, 11U);
    t25 = (t0 + 9288);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    memcpy(t29, t23, 11U);
    xsi_driver_first_trans_fast(t25);

LAB2:    t30 = (t0 + 8632);
    *((int *)t30) = 1;

LAB1:    return;
LAB3:    t1 = (t0 + 2632U);
    t7 = *((char **)t1);
    t1 = (t0 + 12992U);
    t8 = (t0 + 4488U);
    t9 = *((char **)t8);
    t10 = *((int *)t9);
    t8 = ieee_p_3620187407_sub_436351764_3965413181(IEEE_P_3620187407, t6, t7, t1, t10);
    t11 = (t0 + 4248U);
    t12 = *((char **)t11);
    t13 = *((int *)t12);
    t11 = ieee_p_3620187407_sub_436351764_3965413181(IEEE_P_3620187407, t5, t8, t6, t13);
    t14 = (t5 + 12U);
    t15 = *((unsigned int *)t14);
    t16 = (1U * t15);
    t17 = (11U != t16);
    if (t17 == 1)
        goto LAB5;

LAB6:    t18 = (t0 + 9288);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t11, 11U);
    xsi_driver_first_trans_fast(t18);
    goto LAB2;

LAB5:    xsi_size_not_matching(11U, t16, 0);
    goto LAB6;

LAB8:    goto LAB2;

}

static void work_a_0862577870_3212880686_p_8(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;

LAB0:    xsi_set_current_line(117, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB3;

LAB4:
LAB5:    t14 = (t0 + 13145);
    t16 = (t0 + 9352);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t14, 2U);
    xsi_driver_first_trans_fast_port(t16);

LAB2:    t21 = (t0 + 8648);
    *((int *)t21) = 1;

LAB1:    return;
LAB3:    t1 = (t0 + 3112U);
    t5 = *((char **)t1);
    t6 = (5 - 5);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t5 + t8);
    t9 = (t0 + 9352);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t1, 2U);
    xsi_driver_first_trans_fast_port(t9);
    goto LAB2;

LAB6:    goto LAB2;

}

static void work_a_0862577870_3212880686_p_9(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;

LAB0:    xsi_set_current_line(119, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB3;

LAB4:
LAB5:    t14 = (t0 + 13147);
    t16 = (t0 + 9416);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t14, 2U);
    xsi_driver_first_trans_fast_port(t16);

LAB2:    t21 = (t0 + 8664);
    *((int *)t21) = 1;

LAB1:    return;
LAB3:    t1 = (t0 + 3112U);
    t5 = *((char **)t1);
    t6 = (5 - 3);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t5 + t8);
    t9 = (t0 + 9416);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t1, 2U);
    xsi_driver_first_trans_fast_port(t9);
    goto LAB2;

LAB6:    goto LAB2;

}

static void work_a_0862577870_3212880686_p_10(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;

LAB0:    xsi_set_current_line(121, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB3;

LAB4:
LAB5:    t14 = (t0 + 13149);
    t16 = (t0 + 9480);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t14, 2U);
    xsi_driver_first_trans_fast_port(t16);

LAB2:    t21 = (t0 + 8680);
    *((int *)t21) = 1;

LAB1:    return;
LAB3:    t1 = (t0 + 3112U);
    t5 = *((char **)t1);
    t6 = (5 - 1);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t5 + t8);
    t9 = (t0 + 9480);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t1, 2U);
    xsi_driver_first_trans_fast_port(t9);
    goto LAB2;

LAB6:    goto LAB2;

}

static void work_a_0862577870_3212880686_p_11(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned char t11;
    char *t12;
    char *t13;
    unsigned char t14;
    char *t15;
    char *t16;
    int t17;
    unsigned char t18;
    char *t19;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    unsigned char t26;
    char *t27;
    char *t28;
    int t29;
    unsigned char t30;
    char *t31;
    char *t32;
    int t33;
    int t34;
    unsigned char t35;
    char *t36;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;

LAB0:    xsi_set_current_line(127, ng0);
    t1 = (t0 + 2792U);
    t2 = *((char **)t1);
    t1 = (t0 + 13008U);
    t3 = ieee_p_3620187407_sub_2546382208_3965413181(IEEE_P_3620187407, t2, t1, 213);
    if (t3 != 0)
        goto LAB3;

LAB4:    t12 = (t0 + 2792U);
    t13 = *((char **)t12);
    t12 = (t0 + 13008U);
    t14 = ieee_p_3620187407_sub_3908131327_3965413181(IEEE_P_3620187407, t13, t12, 213);
    if (t14 == 1)
        goto LAB7;

LAB8:    t11 = (unsigned char)0;

LAB9:    if (t11 != 0)
        goto LAB5;

LAB6:    t27 = (t0 + 2792U);
    t28 = *((char **)t27);
    t27 = (t0 + 13008U);
    t29 = (213 + 213);
    t30 = ieee_p_3620187407_sub_3908131327_3965413181(IEEE_P_3620187407, t28, t27, t29);
    if (t30 == 1)
        goto LAB12;

LAB13:    t26 = (unsigned char)0;

LAB14:    if (t26 != 0)
        goto LAB10;

LAB11:
LAB15:    t43 = (t0 + 13169);
    t45 = (t0 + 9544);
    t46 = (t45 + 56U);
    t47 = *((char **)t46);
    t48 = (t47 + 56U);
    t49 = *((char **)t48);
    memcpy(t49, t43, 6U);
    xsi_driver_first_trans_fast(t45);

LAB2:    t50 = (t0 + 8696);
    *((int *)t50) = 1;

LAB1:    return;
LAB3:    t4 = (t0 + 13151);
    t6 = (t0 + 9544);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t4, 6U);
    xsi_driver_first_trans_fast(t6);
    goto LAB2;

LAB5:    t19 = (t0 + 13157);
    t21 = (t0 + 9544);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t19, 6U);
    xsi_driver_first_trans_fast(t21);
    goto LAB2;

LAB7:    t15 = (t0 + 2792U);
    t16 = *((char **)t15);
    t15 = (t0 + 13008U);
    t17 = (213 + 213);
    t18 = ieee_p_3620187407_sub_2546382208_3965413181(IEEE_P_3620187407, t16, t15, t17);
    t11 = t18;
    goto LAB9;

LAB10:    t36 = (t0 + 13163);
    t38 = (t0 + 9544);
    t39 = (t38 + 56U);
    t40 = *((char **)t39);
    t41 = (t40 + 56U);
    t42 = *((char **)t41);
    memcpy(t42, t36, 6U);
    xsi_driver_first_trans_fast(t38);
    goto LAB2;

LAB12:    t31 = (t0 + 2792U);
    t32 = *((char **)t31);
    t31 = (t0 + 13008U);
    t33 = (213 + 213);
    t34 = (t33 + 213);
    t35 = ieee_p_3620187407_sub_2546382208_3965413181(IEEE_P_3620187407, t32, t31, t34);
    t26 = t35;
    goto LAB14;

LAB16:    goto LAB2;

}


extern void work_a_0862577870_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0862577870_3212880686_p_0,(void *)work_a_0862577870_3212880686_p_1,(void *)work_a_0862577870_3212880686_p_2,(void *)work_a_0862577870_3212880686_p_3,(void *)work_a_0862577870_3212880686_p_4,(void *)work_a_0862577870_3212880686_p_5,(void *)work_a_0862577870_3212880686_p_6,(void *)work_a_0862577870_3212880686_p_7,(void *)work_a_0862577870_3212880686_p_8,(void *)work_a_0862577870_3212880686_p_9,(void *)work_a_0862577870_3212880686_p_10,(void *)work_a_0862577870_3212880686_p_11};
	xsi_register_didat("work_a_0862577870_3212880686", "isim/tst_isim_beh.exe.sim/work/a_0862577870_3212880686.didat");
	xsi_register_executes(pe);
}
