/*=============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2012 Andres Goens
    Copyright (C) 2012 Sebastian Pancratz
    Copyright (C) 2013 Mike Hansen

******************************************************************************/

#include "fq_zech_mat.h"

#define FQ_ZECH_POLY_DIVREM_DIVCONQUER_CUTOFF  16
#define FQ_ZECH_COMPOSE_MOD_LENH_CUTOFF 6
#define FQ_ZECH_COMPOSE_MOD_PREINV_LENH_CUTOFF 6
#define FQ_ZECH_SQR_CLASSICAL_CUTOFF 215
#define FQ_ZECH_MUL_CLASSICAL_CUTOFF 150
#define FQ_ZECH_MULLOW_CLASSICAL_CUTOFF 150



static __inline__ int FQ_ZECH_POLY_ITERATED_FROBENIUS_CUTOFF(const fq_zech_ctx_t ctx, slong length)
{
    int result;
    fmpz_t q;
    fmpz_init(q);
    fq_zech_ctx_order(q, ctx);
    if ( 2 * fmpz_sizeinbase(q, 2) < 3 * (n_sqrt(length) + 1))
        result = 1;
    else
        result = 0;
    fmpz_clear(q);
    return result;
}

#ifdef T
#undef T
#endif

#define T fq_zech
#define CAP_T FQ_ZECH
#include "fq_poly_templates.h"
#undef CAP_T
#undef T