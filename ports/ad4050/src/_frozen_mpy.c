#include "py/mpconfig.h"
#include "py/objint.h"
#include "py/objstr.h"
#include "py/emitglue.h"

#if MICROPY_OPT_CACHE_MAP_LOOKUP_IN_BYTECODE != 0
#error "incompatible MICROPY_OPT_CACHE_MAP_LOOKUP_IN_BYTECODE"
#endif

#if MICROPY_LONGINT_IMPL != 0
#error "incompatible MICROPY_LONGINT_IMPL"
#endif

#if MICROPY_PY_BUILTINS_FLOAT
typedef struct _mp_obj_float_t {
    mp_obj_base_t base;
    mp_float_t value;
} mp_obj_float_t;
#endif

#if MICROPY_PY_BUILTINS_COMPLEX
typedef struct _mp_obj_complex_t {
    mp_obj_base_t base;
    mp_float_t real;
    mp_float_t imag;
} mp_obj_complex_t;
#endif

enum {
    MP_QSTR_frozentest_dot_py = MP_QSTRnumber_of,
    MP_QSTR_uPy,
};

extern const qstr_pool_t mp_qstr_const_pool;
const qstr_pool_t mp_qstr_frozen_const_pool = {
    (qstr_pool_t*)&mp_qstr_const_pool, // previous pool
    MP_QSTRnumber_of, // previous pool size
    2, // allocated entries
    2, // used entries
    {
        (const byte*)"\xfe\x0d" "frozentest.py",
        (const byte*)"\xf9\x03" "uPy",
    },
};

// frozen bytecode for file frozentest.py, scope frozentest_<module>
STATIC const byte bytecode_data_frozentest__lt_module_gt_[25] = {
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_frozentest_dot_py & 0xff, MP_QSTR_frozentest_dot_py >> 8,
    0x00, 0x00, 0xff,
    0x1b, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x16, MP_QSTR_uPy & 0xff, MP_QSTR_uPy >> 8,
    0x64, 0x01, 
    0x32, 
    0x11, 
    0x5b, 
};
const mp_raw_code_t raw_code_frozentest__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_frozentest__lt_module_gt_,
        .const_table = NULL,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 25,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

const char mp_frozen_mpy_names[] = {
"frozentest.py\0"
"\0"};
const mp_raw_code_t *const mp_frozen_mpy_content[] = {
    &raw_code_frozentest__lt_module_gt_,
};
