/*
 * optipng.h
 * The OptiPNG programming interface.
 *
 * Copyright (C) 2001-2012 Cosmin Truta and the Contributing Authors.
 *
 * This software is distributed under the zlib license.
 * Please see the attached LICENSE for more information.
 */

#ifndef OPTIPNG_H
#define OPTIPNG_H

#include "cbitset.h"


#ifdef __cplusplus
extern "C" {
#endif


/*
 * User options (e.g. extracted from the command line)
 */
struct opng_options
{
    /* general options */
    int backup;
    int clobber;
    int debug;
    int fix;
    int force;
    int full;
    int preserve;
    int quiet;
    int simulate;
    int verbose;
    const char *out_name;
    const char *dir_name;
    const char *log_name;

    /* optimization options */
    int interlace;
    int nb, nc, np, nz;
    int optim_level;
    int compr_level;
    bitset_t filter_set;

    /* editing options */
    int snip;
    int strip_all;
};


/*
 * User interface callbacks
 */
struct opng_ui
{
    void (*printf_fn)(const char *fmt, ...);
    void (*print_cntrl_fn)(int cntrl_code);
    void (*progress_fn)(unsigned long current_step, unsigned long total_steps);
    void (*panic_fn)(const char *msg);
};


/*
 * Engine initialization
 */
int opng_initialize(const struct opng_options *options,
                    const struct opng_ui *ui);

/*
 * Engine execution
 */
int opng_optimize(const char *infile_name);

/*
 * Engine finalization
 */
int opng_finalize(void);


/*
 * Encoder limits and default values
 */
#define OPNG_OPTIM_LEVEL_DEFAULT    2
#define OPNG_OPTIM_LEVEL_MIN        0
#define OPNG_OPTIM_LEVEL_MAX        7

#define OPNG_FILTER_MIN             0
#define OPNG_FILTER_MAX             5
#define OPNG_FILTER_SET_MASK        ((1 << (5+1)) - (1 << 0))  /* 0x003f */


#ifdef __cplusplus
}  /* extern "C" */
#endif


#endif  /* OPTIPNG_H */
