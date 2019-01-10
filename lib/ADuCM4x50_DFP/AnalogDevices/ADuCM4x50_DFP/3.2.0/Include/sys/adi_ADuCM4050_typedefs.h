/* ================================================================================

     Project      :   ADuCM4050
     File         :   ADuCM4050_typedefs.h
     Description  :   C Register Structures

     Date         :   Oct 9, 2017

     Copyright (c) 2014-2017 Analog Devices, Inc.  All Rights Reserved.
     This software is proprietary and confidential to Analog Devices, Inc. and
     its licensors.

     This file was auto-generated. Do not make local changes to this file.

   ================================================================================ */

#ifndef _ADUCM4050_TYPEDEFS_H
#define _ADUCM4050_TYPEDEFS_H

/* pickup integer types */
#if defined(_LANGUAGE_C) || (defined(__GNUC__) && !defined(__ASSEMBLER__))
#include <stdint.h>
#endif /* _LANGUAGE_C */

#if defined ( __CC_ARM   )
#pragma push
#pragma anon_unions
#endif


#if defined (_MISRA_RULES)
/*
  anonymous unions violate ISO 9899:1990 and therefore MISRA Rule 1.1.
  Use of unions violates MISRA Rule 18.4.
  Anonymous unions are required for this implementation.
  Re-use of identifiers violates MISRA Rule 5.7.
  Field names are repeated for the ADuCM4050 register map.
*/
#pragma diag(push)
#pragma diag(suppress:misra_rule_1_1:"Allow anonymous unions")
#pragma diag(suppress:misra_rule_5_1:"Allow names over 32 character limit")
#pragma diag(suppress:misra_rule_5_3:"Header will re-use typedef identifiers")
#pragma diag(suppress:misra_rule_5_6:"Header will re-use identifiers in the same scope")
#pragma diag(suppress:misra_rule_5_7:"Header will re-use identifiers")
#pragma diag(suppress:misra_rule_18_4:"Allow the use of a union")
#endif /* _MISRA_RULES */

/** @defgroup LOAD 16-bit Load Value (LOAD) Register
 *  16-bit Load Value (LOAD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_LOAD_Struct
 *! \brief  16-bit Load Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_LOAD_t__
typedef struct _ADI_TMR_LOAD_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Load Value */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_LOAD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_LOAD_t__ */

/*@}*/

/** @defgroup CURCNT 16-bit Timer Value (CURCNT) Register
 *  16-bit Timer Value (CURCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_CURCNT_Struct
 *! \brief  16-bit Timer Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_CURCNT_t__
typedef struct _ADI_TMR_CURCNT_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Current Count */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_CURCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_CURCNT_t__ */

/*@}*/

/** @defgroup CTL Control (CTL) Register
 *  Control (CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_CTL_Struct
 *! \brief  Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_CTL_t__
typedef struct _ADI_TMR_CTL_t {
  union {
    struct {
      uint16_t PRE        :  2;  /**< Prescaler */
      uint16_t UP         :  1;  /**< Count up */
      uint16_t MODE       :  1;  /**< Timer Mode */
      uint16_t EN         :  1;  /**< Timer Enable */
      uint16_t CLK        :  2;  /**< Clock Select */
      uint16_t RLD        :  1;  /**< Reload Control */
      uint16_t reserved8  :  5;
      uint16_t EVTEN      :  1;  /**< Event Select */
      uint16_t RSTEN      :  1;  /**< Counter and Prescale Reset Enable */
      uint16_t SYNCBYP    :  1;  /**< Synchronization Bypass */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_CTL_t__ */

/*@}*/

/** @defgroup CLRINT Clear Interrupt (CLRINT) Register
 *  Clear Interrupt (CLRINT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_CLRINT_Struct
 *! \brief  Clear Interrupt Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_CLRINT_t__
typedef struct _ADI_TMR_CLRINT_t {
  union {
    struct {
      uint16_t TIMEOUT    :  1;  /**< Clear Timeout Interrupt */
      uint16_t EVTCAPT    :  1;  /**< Clear Captured Event Interrupt */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_TMR_CLRINT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_CLRINT_t__ */

/*@}*/

/** @defgroup CAPTURE Capture (CAPTURE) Register
 *  Capture (CAPTURE) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_CAPTURE_Struct
 *! \brief  Capture Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_CAPTURE_t__
typedef struct _ADI_TMR_CAPTURE_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< 16-bit Captured Value */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_CAPTURE_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_CAPTURE_t__ */

/*@}*/

/** @defgroup ALOAD 16-bit Load Value, Asynchronous (ALOAD) Register
 *  16-bit Load Value, Asynchronous (ALOAD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_ALOAD_Struct
 *! \brief  16-bit Load Value, Asynchronous Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_ALOAD_t__
typedef struct _ADI_TMR_ALOAD_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Load Value, Asynchronous */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_ALOAD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_ALOAD_t__ */

/*@}*/

/** @defgroup ACURCNT 16-bit Timer Value, Asynchronous (ACURCNT) Register
 *  16-bit Timer Value, Asynchronous (ACURCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_ACURCNT_Struct
 *! \brief  16-bit Timer Value, Asynchronous Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_ACURCNT_t__
typedef struct _ADI_TMR_ACURCNT_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Counter Value */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_ACURCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_ACURCNT_t__ */

/*@}*/

/** @defgroup STAT Status (STAT) Register
 *  Status (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_STAT_Struct
 *! \brief  Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_STAT_t__
typedef struct _ADI_TMR_STAT_t {
  union {
    struct {
      uint16_t TIMEOUT    :  1;  /**< Timeout Event Occurred */
      uint16_t CAPTURE    :  1;  /**< Capture Event Pending */
      uint16_t reserved2  :  4;
      uint16_t BUSY       :  1;  /**< Timer Busy */
      uint16_t PDOK       :  1;  /**< Clear Interrupt Register Synchronization */
      uint16_t CNTRST     :  1;  /**< Counter Reset Occurring */
      uint16_t reserved9  :  7;
    };
    uint16_t VALUE16;
  };
} ADI_TMR_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_STAT_t__ */

/*@}*/

/** @defgroup PWMCTL PWM Control Register (PWMCTL) Register
 *  PWM Control Register (PWMCTL) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_TMR_PWMCTL_MATCH
 *! \brief  PWM Match Enabled (MATCH) Enumerations
 *  ========================================================================= */
typedef enum
{
  TMR_PWMCTL_PWM_TOGGLE = 0,  /**< PWM in toggle mode */
  TMR_PWMCTL_PWM_MATCH  = 1   /**< PWM in match mode  */
} ADI_TMR_PWMCTL_MATCH;


/*  =========================================================================
 *! \enum   ADI_TMR_PWMCTL_IDLESTATE
 *! \brief  PWM Idle State (IDLESTATE) Enumerations
 *  ========================================================================= */
typedef enum
{
  TMR_PWMCTL_IDLE_LOW  = 0,  /**< PWM idles low  */
  TMR_PWMCTL_IDLE_HIGH = 1   /**< PWM idles high */
} ADI_TMR_PWMCTL_IDLESTATE;


/* ==========================================================================
 *! \struct ADI_TMR_PWMCTL_Struct
 *! \brief  PWM Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_PWMCTL_t__
typedef struct _ADI_TMR_PWMCTL_t {
  union {
    struct {
      uint16_t MATCH      :  1;  /**< PWM Match Enabled */
      uint16_t IDLESTATE  :  1;  /**< PWM Idle State */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_TMR_PWMCTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_PWMCTL_t__ */

/*@}*/

/** @defgroup PWMMATCH PWM Match Value (PWMMATCH) Register
 *  PWM Match Value (PWMMATCH) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_PWMMATCH_Struct
 *! \brief  PWM Match Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_PWMMATCH_t__
typedef struct _ADI_TMR_PWMMATCH_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< PWM Match Value */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_PWMMATCH_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_PWMMATCH_t__ */

/*@}*/

/** @defgroup EVENTSELECT Timer Event Selection Register (EVENTSELECT) Register
 *  Timer Event Selection Register (EVENTSELECT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_EVENTSELECT_Struct
 *! \brief  Timer Event Selection Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_EVENTSELECT_t__
typedef struct _ADI_TMR_EVENTSELECT_t {
  union {
    struct {
      uint16_t EVTRANGE   :  6;  /**< Event Select Range */
      uint16_t reserved6  : 10;
    };
    uint16_t VALUE16;
  };
} ADI_TMR_EVENTSELECT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_EVENTSELECT_t__ */

/*@}*/

/** @defgroup LOAD 16-bit load value (LOAD) Register
 *  16-bit load value (LOAD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_RGB_LOAD_Struct
 *! \brief  16-bit load value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_RGB_LOAD_t__
typedef struct _ADI_TMR_RGB_LOAD_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Load value */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_RGB_LOAD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_RGB_LOAD_t__ */

/*@}*/

/** @defgroup CURCNT 16-bit timer value (CURCNT) Register
 *  16-bit timer value (CURCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_RGB_CURCNT_Struct
 *! \brief  16-bit timer value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_RGB_CURCNT_t__
typedef struct _ADI_TMR_RGB_CURCNT_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Current count */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_RGB_CURCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_RGB_CURCNT_t__ */

/*@}*/

/** @defgroup CTL Control (CTL) Register
 *  Control (CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_RGB_CTL_Struct
 *! \brief  Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_RGB_CTL_t__
typedef struct _ADI_TMR_RGB_CTL_t {
  union {
    struct {
      uint16_t PRE        :  2;  /**< Prescaler */
      uint16_t UP         :  1;  /**< Count up */
      uint16_t MODE       :  1;  /**< Timer mode */
      uint16_t EN         :  1;  /**< Timer enable */
      uint16_t CLK        :  2;  /**< Clock select */
      uint16_t RLD        :  1;  /**< Reload control */
      uint16_t reserved8  :  5;
      uint16_t EVTEN      :  1;  /**< Event select */
      uint16_t RSTEN      :  1;  /**< Counter and prescale reset enable */
      uint16_t SYNCBYP    :  1;  /**< Synchronization bypass */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_RGB_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_RGB_CTL_t__ */

/*@}*/

/** @defgroup CLRINT Clear interrupt (CLRINT) Register
 *  Clear interrupt (CLRINT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_RGB_CLRINT_Struct
 *! \brief  Clear interrupt Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_RGB_CLRINT_t__
typedef struct _ADI_TMR_RGB_CLRINT_t {
  union {
    struct {
      uint16_t TIMEOUT    :  1;  /**< Clear timeout interrupt */
      uint16_t EVTCAPT    :  1;  /**< Clear captured event interrupt */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_TMR_RGB_CLRINT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_RGB_CLRINT_t__ */

/*@}*/

/** @defgroup CAPTURE Capture (CAPTURE) Register
 *  Capture (CAPTURE) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_RGB_CAPTURE_Struct
 *! \brief  Capture Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_RGB_CAPTURE_t__
typedef struct _ADI_TMR_RGB_CAPTURE_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< 16-bit captured value */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_RGB_CAPTURE_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_RGB_CAPTURE_t__ */

/*@}*/

/** @defgroup ALOAD 16-bit load value, asynchronous (ALOAD) Register
 *  16-bit load value, asynchronous (ALOAD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_RGB_ALOAD_Struct
 *! \brief  16-bit load value, asynchronous Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_RGB_ALOAD_t__
typedef struct _ADI_TMR_RGB_ALOAD_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Load value, asynchronous */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_RGB_ALOAD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_RGB_ALOAD_t__ */

/*@}*/

/** @defgroup ACURCNT 16-bit timer value, asynchronous (ACURCNT) Register
 *  16-bit timer value, asynchronous (ACURCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_RGB_ACURCNT_Struct
 *! \brief  16-bit timer value, asynchronous Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_RGB_ACURCNT_t__
typedef struct _ADI_TMR_RGB_ACURCNT_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Counter value */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_RGB_ACURCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_RGB_ACURCNT_t__ */

/*@}*/

/** @defgroup STAT Status (STAT) Register
 *  Status (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_RGB_STAT_Struct
 *! \brief  Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_RGB_STAT_t__
typedef struct _ADI_TMR_RGB_STAT_t {
  union {
    struct {
      uint16_t TIMEOUT    :  1;  /**< Timeout event occurred */
      uint16_t CAPTURE    :  1;  /**< Capture event pending */
      uint16_t reserved2  :  4;
      uint16_t BUSY       :  1;  /**< Timer Busy */
      uint16_t PDOK       :  1;  /**< Clear Interrupt Register synchronization */
      uint16_t CNTRST     :  1;  /**< Counter reset occurring */
      uint16_t reserved9  :  7;
    };
    uint16_t VALUE16;
  };
} ADI_TMR_RGB_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_RGB_STAT_t__ */

/*@}*/

/** @defgroup PWM0CTL PWM0 Control Register (PWM0CTL) Register
 *  PWM0 Control Register (PWM0CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_RGB_PWM0CTL_Struct
 *! \brief  PWM0 Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_RGB_PWM0CTL_t__
typedef struct _ADI_TMR_RGB_PWM0CTL_t {
  union {
    struct {
      uint16_t MATCH      :  1;  /**< PWM Match enabled */
      uint16_t IDLESTATE  :  1;  /**< PWM Idle State */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_TMR_RGB_PWM0CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_RGB_PWM0CTL_t__ */

/*@}*/

/** @defgroup PWM0MATCH PWM0 Match Value (PWM0MATCH) Register
 *  PWM0 Match Value (PWM0MATCH) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_RGB_PWM0MATCH_Struct
 *! \brief  PWM0 Match Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_RGB_PWM0MATCH_t__
typedef struct _ADI_TMR_RGB_PWM0MATCH_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< PWM Match Value */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_RGB_PWM0MATCH_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_RGB_PWM0MATCH_t__ */

/*@}*/

/** @defgroup EVENTSELECT Timer Event selection Register (EVENTSELECT) Register
 *  Timer Event selection Register (EVENTSELECT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_RGB_EVENTSELECT_Struct
 *! \brief  Timer Event selection Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_RGB_EVENTSELECT_t__
typedef struct _ADI_TMR_RGB_EVENTSELECT_t {
  union {
    struct {
      uint16_t EVTRANGE   :  6;  /**< Event select range */
      uint16_t reserved6  : 10;
    };
    uint16_t VALUE16;
  };
} ADI_TMR_RGB_EVENTSELECT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_RGB_EVENTSELECT_t__ */

/*@}*/

/** @defgroup PWM1CTL PWM1 Control Register (PWM1CTL) Register
 *  PWM1 Control Register (PWM1CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_RGB_PWM1CTL_Struct
 *! \brief  PWM1 Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_RGB_PWM1CTL_t__
typedef struct _ADI_TMR_RGB_PWM1CTL_t {
  union {
    struct {
      uint16_t MATCH      :  1;  /**< PWM Match enabled */
      uint16_t IDLESTATE  :  1;  /**< PWM Idle State */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_TMR_RGB_PWM1CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_RGB_PWM1CTL_t__ */

/*@}*/

/** @defgroup PWM1MATCH PWM1 Match Value (PWM1MATCH) Register
 *  PWM1 Match Value (PWM1MATCH) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_RGB_PWM1MATCH_Struct
 *! \brief  PWM1 Match Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_RGB_PWM1MATCH_t__
typedef struct _ADI_TMR_RGB_PWM1MATCH_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< PWM Match Value */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_RGB_PWM1MATCH_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_RGB_PWM1MATCH_t__ */

/*@}*/

/** @defgroup PWM2CTL PWM2 Control Register (PWM2CTL) Register
 *  PWM2 Control Register (PWM2CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_RGB_PWM2CTL_Struct
 *! \brief  PWM2 Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_RGB_PWM2CTL_t__
typedef struct _ADI_TMR_RGB_PWM2CTL_t {
  union {
    struct {
      uint16_t MATCH      :  1;  /**< PWM Match enabled */
      uint16_t IDLESTATE  :  1;  /**< PWM Idle State */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_TMR_RGB_PWM2CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_RGB_PWM2CTL_t__ */

/*@}*/

/** @defgroup PWM2MATCH PWM2 Match Value (PWM2MATCH) Register
 *  PWM2 Match Value (PWM2MATCH) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_RGB_PWM2MATCH_Struct
 *! \brief  PWM2 Match Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_RGB_PWM2MATCH_t__
typedef struct _ADI_TMR_RGB_PWM2MATCH_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< PWM Match Value */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_RGB_PWM2MATCH_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_RGB_PWM2MATCH_t__ */

/*@}*/

/** @defgroup CR0 RTC Control 0 (CR0) Register
 *  RTC Control 0 (CR0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_CR0_Struct
 *! \brief  RTC Control 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CR0_t__
typedef struct _ADI_RTC_CR0_t {
  union {
    struct {
      uint16_t CNTEN      :  1;  /**< Global Enable for the RTC */
      uint16_t ALMEN      :  1;  /**< Enable the RTC Alarm (Absolute) Operation */
      uint16_t ALMINTEN   :  1;  /**< Enable ALMINT Sourced Alarm Interrupts to the CPU */
      uint16_t TRMEN      :  1;  /**< Enable RTC Digital Trimming */
      uint16_t MOD60ALMEN :  1;  /**< Enable RTC Modulo-60 Counting of Time Past a Modulo-60 Boundary */
      uint16_t MOD60ALM   :  6;  /**< Periodic, Modulo-60 Alarm Time in Prescaled RTC Time Units Beyond a Modulo-60 Boundary */
      uint16_t MOD60ALMINTEN :  1;  /**< Enable Periodic Modulo-60 RTC Alarm  Sourced Interrupts to the CPU */
      uint16_t ISOINTEN      :  1;  /**< Enable ISOINT Sourced Interrupts to the CPU When Isolation of the RTC Power Domain is Activated and Subsequently De-activated */
      uint16_t WPNDERRINTEN  :  1;  /**< Enable Write Pending Error Sourced Interrupts to the CPU When an RTC Register-write Pending Error Occurs */
      uint16_t WSYNCINTEN    :  1;  /**< Enable Write Synchronization Sourced Interrupts to the CPU */
      uint16_t WPNDINTEN     :  1;  /**< Enable Write Pending Sourced Interrupts to the CPU */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CR0_t__ */

/*@}*/

/** @defgroup SR0 RTC Status 0 (SR0) Register
 *  RTC Status 0 (SR0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR0_Struct
 *! \brief  RTC Status 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR0_t__
typedef struct _ADI_RTC_SR0_t {
  union {
    struct {
      uint16_t reserved0  :  1;
      uint16_t ALMINT     :  1;  /**< Alarm Interrupt Source */
      uint16_t MOD60ALMINT :  1;  /**< Modulo-60 RTC Alarm Interrupt Source */
      uint16_t ISOINT      :  1;  /**< RTC Power-Domain Isolation Interrupt Source */
      uint16_t WPNDERRINT  :  1;  /**< Write Pending Error Interrupt Source */
      uint16_t WSYNCINT    :  1;  /**< Write Synchronisation Interrupt */
      uint16_t WPNDINT     :  1;  /**< Write Pending Interrupt */
      uint16_t WSYNCCR0    :  1;  /**< Synchronisation Status of Posted Writes to CR0 */
      uint16_t WSYNCSR0    :  1;  /**< Synchronisation Status of Posted Writes to SR0 */
      uint16_t WSYNCCNT0   :  1;  /**< Synchronisation Status of Posted Writes to CNT0 */
      uint16_t WSYNCCNT1   :  1;  /**< Synchronisation Status of Posted Writes to CNT1 */
      uint16_t WSYNCALM0   :  1;  /**< Synchronisation Status of Posted Writes to ALM0 */
      uint16_t WSYNCALM1   :  1;  /**< Synchronisation Status of Posted Writes to ALM1 */
      uint16_t WSYNCTRM    :  1;  /**< Synchronisation Status of Posted Writes to TRM */
      uint16_t ISOENB      :  1;  /**< Visibility of 32kHz Sourced Registers */
      uint16_t reserved15  :  1;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR0_t__ */

/*@}*/

/** @defgroup SR1 RTC Status 1 (SR1) Register
 *  RTC Status 1 (SR1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR1_Struct
 *! \brief  RTC Status 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR1_t__
typedef struct _ADI_RTC_SR1_t {
  union {
    struct {
      uint16_t reserved0  :  7;
      uint16_t WPNDCR0    :  1;  /**< Pending Status of Posted Writes to CR0 */
      uint16_t WPNDSR0    :  1;  /**< Pending Status of Posted Clearances of Interrupt Sources in SR0 */
      uint16_t WPNDCNT0   :  1;  /**< Pending Status of Posted Writes to CNT0 */
      uint16_t WPNDCNT1   :  1;  /**< Pending Status of Posted Writes to CNT1 */
      uint16_t WPNDALM0   :  1;  /**< Pending Status of Posted Writes to ALM0 */
      uint16_t WPNDALM1   :  1;  /**< Pending Status of Posted Writes to ALM1 */
      uint16_t WPNDTRM    :  1;  /**< Pending Status of Posted Writes to TRM */
      uint16_t reserved14 :  2;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR1_t__ */

/*@}*/

/** @defgroup CNT0 RTC Count 0 (CNT0) Register
 *  RTC Count 0 (CNT0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_CNT0_Struct
 *! \brief  RTC Count 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CNT0_t__
typedef struct _ADI_RTC_CNT0_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Lower 16 Prescaled (Non-Fractional) Bits of the RTC Real-Time Count */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CNT0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CNT0_t__ */

/*@}*/

/** @defgroup CNT1 RTC Count 1 (CNT1) Register
 *  RTC Count 1 (CNT1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_CNT1_Struct
 *! \brief  RTC Count 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CNT1_t__
typedef struct _ADI_RTC_CNT1_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Upper 16 Prescaled (Non-Fractional) Bits of the RTC Real-Time Count */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CNT1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CNT1_t__ */

/*@}*/

/** @defgroup ALM0 RTC Alarm 0 (ALM0) Register
 *  RTC Alarm 0 (ALM0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_ALM0_Struct
 *! \brief  RTC Alarm 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_ALM0_t__
typedef struct _ADI_RTC_ALM0_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Lower 16 Prescaled (i.e. Non-Fractional) Bits of the RTC Alarm Target Time */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_ALM0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_ALM0_t__ */

/*@}*/

/** @defgroup ALM1 RTC Alarm 1 (ALM1) Register
 *  RTC Alarm 1 (ALM1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_ALM1_Struct
 *! \brief  RTC Alarm 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_ALM1_t__
typedef struct _ADI_RTC_ALM1_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Upper 16 Prescaled (Non-Fractional) Bits of the RTC Alarm Target Time */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_ALM1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_ALM1_t__ */

/*@}*/

/** @defgroup TRM RTC Trim (TRM) Register
 *  RTC Trim (TRM) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_TRM_Struct
 *! \brief  RTC Trim Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_TRM_t__
typedef struct _ADI_RTC_TRM_t {
  union {
    struct {
      uint16_t VALUE      :  3;  /**< Trim Value in Prescaled RTC Time Units to Be Added or Subtracted from the RTC Count at the End of a Periodic Interval Selected by TRM:TRMIVL */
      uint16_t ADD        :  1;  /**< Trim Polarity */
      uint16_t IVL        :  2;  /**< Trim Interval in Prescaled RTC Time Units */
      uint16_t IVL2EXPMIN :  4;  /**< Minimum Power-of-two Interval of Prescaled RTC Time Units Which TRM:TRMIVL TRMIVL Can Select */
      uint16_t reserved10 :  6;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_TRM_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_TRM_t__ */

/*@}*/

/** @defgroup GWY RTC Gateway (GWY) Register
 *  RTC Gateway (GWY) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_GWY_Struct
 *! \brief  RTC Gateway Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_GWY_t__
typedef struct _ADI_RTC_GWY_t {
  union {
    struct {
      uint16_t SWKEY      : 16;  /**< Software-keyed Command Issued by the CPU */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_GWY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_GWY_t__ */

/*@}*/

/** @defgroup CR1 RTC Control 1 (CR1) Register
 *  RTC Control 1 (CR1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_CR1_Struct
 *! \brief  RTC Control 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CR1_t__
typedef struct _ADI_RTC_CR1_t {
  union {
    struct {
      uint16_t CNTINTEN   :  1;  /**< Enable for the RTC Count Interrupt Source */
      uint16_t PSINTEN    :  1;  /**< Enable for the Prescaled, Modulo-1 Interrupt Source, in SR2:RTCPSINT */
      uint16_t TRMINTEN   :  1;  /**< Enable for the RTC Trim Interrupt Source, in SR2:RTCTRMINT */
      uint16_t CNTROLLINTEN :  1;  /**< Enable for the RTC Count Roll-Over Interrupt Source, in SR2:RTCCNTROLLINT */
      uint16_t CNTMOD60ROLLINTEN :  1;  /**< Enable for the RTC Modulo-60 Count Roll-Over Interrupt Source */
      uint16_t PRESCALE2EXP      :  4;  /**< Prescale Power of 2 Division Factor for the RTC Base Clock */
      uint16_t reserved9         :  7;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CR1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CR1_t__ */

/*@}*/

/** @defgroup SR2 RTC Status 2 (SR2) Register
 *  RTC Status 2 (SR2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR2_Struct
 *! \brief  RTC Status 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR2_t__
typedef struct _ADI_RTC_SR2_t {
  union {
    struct {
      uint16_t CNTINT     :  1;  /**< RTC Count Interrupt Source */
      uint16_t PSINT      :  1;  /**< RTC Prescaled, Modulo-1 Boundary Interrupt Source */
      uint16_t TRMINT     :  1;  /**< RTC Trim Interrupt Source */
      uint16_t CNTROLLINT :  1;  /**< RTC Count Roll-Over Interrupt Source */
      uint16_t CNTMOD60ROLLINT :  1;  /**< RTC Modulo-60 Count Roll-Over Interrupt Source */
      uint16_t CNTROLL         :  1;  /**< RTC Count Roll-Over */
      uint16_t CNTMOD60ROLL    :  1;  /**< RTC Count Modulo-60 Roll-Over */
      uint16_t TRMBDYMIR       :  1;  /**< Mirror of MOD:RTCTRMBDY */
      uint16_t reserved8       :  4;
      uint16_t WPNDCR1MIR      :  1;  /**< Pending Status of Posted Writes to CR1 */
      uint16_t WPNDALM2MIR     :  1;  /**< Pending Status of Posted Writes to ALM2 */
      uint16_t WSYNCCR1MIR     :  1;  /**< Synchronization Status of Posted Writes to CR1 */
      uint16_t WSYNCALM2MIR    :  1;  /**< Synchronization Status of Posted Writes to ALM2 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR2_t__ */

/*@}*/

/** @defgroup SNAP0 RTC Snapshot 0 (SNAP0) Register
 *  RTC Snapshot 0 (SNAP0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SNAP0_Struct
 *! \brief  RTC Snapshot 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SNAP0_t__
typedef struct _ADI_RTC_SNAP0_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Constituent Part of the 47-bit Input Capture Channel 0, Containing a Sticky Snapshot of  CNT0 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SNAP0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SNAP0_t__ */

/*@}*/

/** @defgroup SNAP1 RTC Snapshot 1 (SNAP1) Register
 *  RTC Snapshot 1 (SNAP1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SNAP1_Struct
 *! \brief  RTC Snapshot 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SNAP1_t__
typedef struct _ADI_RTC_SNAP1_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Part of the 47-bit Input Capture Channel 0 Containing a Sticky Snapshot of  CNT1 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SNAP1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SNAP1_t__ */

/*@}*/

/** @defgroup SNAP2 RTC Snapshot 2 (SNAP2) Register
 *  RTC Snapshot 2 (SNAP2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SNAP2_Struct
 *! \brief  RTC Snapshot 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SNAP2_t__
typedef struct _ADI_RTC_SNAP2_t {
  union {
    struct {
      uint16_t VALUE      : 15;  /**< Part of the 47-bit Input Capture Channel 0 Containing a Sticky Snapshot of CNT2 */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SNAP2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SNAP2_t__ */

/*@}*/

/** @defgroup MOD RTC Modulo (MOD) Register
 *  RTC Modulo (MOD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_MOD_Struct
 *! \brief  RTC Modulo Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_MOD_t__
typedef struct _ADI_RTC_MOD_t {
  union {
    struct {
      uint16_t CNTMOD60   :  6;  /**< Modulo-60 Value of the RTC Count: CNT1 and CNT0 */
      uint16_t INCR       :  4;  /**< Most Recent Increment Value Added to the RTC Count in CNT1 and CNT0 */
      uint16_t TRMBDY     :  1;  /**< Trim Boundary Indicator */
      uint16_t CNT0_4TOZERO :  5;  /**< Mirror of CNT0[4:0] */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_MOD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_MOD_t__ */

/*@}*/

/** @defgroup CNT2 RTC Count 2 (CNT2) Register
 *  RTC Count 2 (CNT2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_CNT2_Struct
 *! \brief  RTC Count 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CNT2_t__
typedef struct _ADI_RTC_CNT2_t {
  union {
    struct {
      uint16_t VALUE      : 15;  /**< Fractional Bits of the RTC Real-Time Count */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CNT2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CNT2_t__ */

/*@}*/

/** @defgroup ALM2 RTC Alarm 2 (ALM2) Register
 *  RTC Alarm 2 (ALM2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_ALM2_Struct
 *! \brief  RTC Alarm 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_ALM2_t__
typedef struct _ADI_RTC_ALM2_t {
  union {
    struct {
      uint16_t VALUE      : 15;  /**< Fractional Bits of the Alarm Target Time */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_ALM2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_ALM2_t__ */

/*@}*/

/** @defgroup SR3 RTC Status 3 (SR3) Register
 *  RTC Status 3 (SR3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR3_Struct
 *! \brief  RTC Status 3 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR3_t__
typedef struct _ADI_RTC_SR3_t {
  union {
    struct {
      uint16_t IC0IRQ     :  1;  /**< Sticky Interrupt Source for the RTC Input Capture Channel 0 */
      uint16_t reserved1  :  1;
      uint16_t IC2IRQ     :  1;  /**< Sticky Interrupt Source for the RTC Input Capture Channel 2 */
      uint16_t IC3IRQ     :  1;  /**< Sticky Interrupt Source for the RTC Input Capture Channel 3 */
      uint16_t IC4IRQ     :  1;  /**< Sticky Interrupt Source for the RTC Input Capture Channel 4 */
      uint16_t SS1FEIRQ   :  1;  /**< Sticky Interrupt Source for the SensorStrobe Channel 1 Falling Edge */
      uint16_t SS2FEIRQ   :  1;  /**< Sticky Interrupt Source for the SensorStrobe Channel 2 Falling Edge */
      uint16_t SS3FEIRQ   :  1;  /**< Sticky Interrupt Source for the SensorStrobe Channel 3 Falling Edge */
      uint16_t SS4FEIRQ   :  1;  /**< Sticky Interrupt Source for the SensorStrobe Channel 4 Falling Edge */
      uint16_t SS1IRQ     :  1;  /**< Sticky Interrupt Source for SensorStrobe Channel 1 */
      uint16_t SS2IRQ     :  1;  /**< Sticky Interrupt Source for the SensorStrobe Channel 2 */
      uint16_t SS3IRQ     :  1;  /**< Sticky Interrupt Source for the SensorStrobe Channel 3 */
      uint16_t SS4IRQ     :  1;  /**< Sticky Interrupt Source for the SensorStrobe Channel 4 */
      uint16_t ALMINTMIR  :  1;  /**< Read-only Mirror of the SR0:ALMINT Interrupt Source */
      uint16_t reserved14 :  2;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR3_t__ */

/*@}*/

/** @defgroup CR2IC RTC Control 2 for Configuring Input Capture Channels (CR2IC) Register
 *  RTC Control 2 for Configuring Input Capture Channels (CR2IC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_CR2IC_Struct
 *! \brief  RTC Control 2 for Configuring Input Capture Channels Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CR2IC_t__
typedef struct _ADI_RTC_CR2IC_t {
  union {
    struct {
      uint16_t IC0EN      :  1;  /**< Enable for the RTC Input Capture Channel 0 */
      uint16_t reserved1  :  1;
      uint16_t IC2EN      :  1;  /**< Enable for the RTC Input Capture Channel 2 */
      uint16_t IC3EN      :  1;  /**< Enable for the RTC Input Capture Channel 3 */
      uint16_t IC4EN      :  1;  /**< Enable for the RTC Input Capture Channel 4 */
      uint16_t IC0LH      :  1;  /**< Polarity of the Active-Going Capture Edge for the RTC Input Capture Channel 0 */
      uint16_t reserved6  :  1;
      uint16_t IC2LH      :  1;  /**< Polarity of the Active-going Capture Edge for the Input Capture Channel 2 */
      uint16_t IC3LH      :  1;  /**< Polarity of the Active-going Capture Edge for the Input Capture Channel 3 */
      uint16_t IC4LH      :  1;  /**< Polarity of the Active-going Capture Edge for the Input Capture Channel 4 */
      uint16_t IC0IRQEN   :  1;  /**< Interrupt Enable for the RTC Input Capture Channel 0 */
      uint16_t reserved11 :  1;
      uint16_t IC2IRQEN   :  1;  /**< Interrupt Enable for the RTC Input Capture Channel 2 */
      uint16_t IC3IRQEN   :  1;  /**< Interrupt Enable for the RTC Input Capture Channel 3 */
      uint16_t IC4IRQEN   :  1;  /**< Interrupt Enable for the RTC Input Capture Channel 4 */
      uint16_t ICOWUSEN   :  1;  /**< Enable Overwrite of Unread Snapshots for All Input Capture Channels */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CR2IC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CR2IC_t__ */

/*@}*/

/** @defgroup CR3SS RTC Control 3 for Configuring SensorStrobe Channel (CR3SS) Register
 *  RTC Control 3 for Configuring SensorStrobe Channel (CR3SS) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_CR3SS_Struct
 *! \brief  RTC Control 3 for Configuring SensorStrobe Channel Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CR3SS_t__
typedef struct _ADI_RTC_CR3SS_t {
  union {
    struct {
      uint16_t reserved0  :  1;
      uint16_t SS1EN      :  1;  /**< Enable for SensorStrobe Channel 1 */
      uint16_t SS2EN      :  1;  /**< Enable for the SensorStrobe Channel 2 */
      uint16_t SS3EN      :  1;  /**< Enable for the SensorStrobe Channel 3 */
      uint16_t SS4EN      :  1;  /**< Enable for the SensorStrobe Channel 4 */
      uint16_t SS1FEIRQEN :  1;  /**< Falling Edge Interrupt Enable for the SensorStrobe Channel 1 */
      uint16_t SS2FEIRQEN :  1;  /**< Falling Edge Interrupt Enable for the SensorStrobe Channel 2 */
      uint16_t SS3FEIRQEN :  1;  /**< Falling Edge Interrupt Enable for the SensorStrobe Channel 3 */
      uint16_t SS4FEIRQEN :  1;  /**< Falling Edge Interrupt Enable for the SensorStrobe Channel 4 */
      uint16_t SS1IRQEN   :  1;  /**< Interrupt Enable for SensorStrobe Channel 1 */
      uint16_t SS2IRQEN   :  1;  /**< Posedge EdgeInterrupt Enable for the SensorStrobe Channel 2 */
      uint16_t SS3IRQEN   :  1;  /**< Posedge EdgeInterrupt Enable for the SensorStrobe Channel 3 */
      uint16_t SS4IRQEN   :  1;  /**< Posedge EdgeInterrupt Enable for the SensorStrobe Channel 4 */
      uint16_t reserved13 :  3;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CR3SS_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CR3SS_t__ */

/*@}*/

/** @defgroup CR4SS RTC Control 4 for Configuring SensorStrobe Channel (CR4SS) Register
 *  RTC Control 4 for Configuring SensorStrobe Channel (CR4SS) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_RTC_CR4SS_SS1MSKEN
 *! \brief  Enable for Thermometer-Code Masking of the SensorStrobe Channel 1 (SS1MSKEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  RTC_CR4SS_NO_MSK    = 0,  /**< Do not apply a mask to SensorStrobe Channel 1 Register */
  RTC_CR4SS_THERM_MSK = 1   /**< Apply thermometer decoded mask                         */
} ADI_RTC_CR4SS_SS1MSKEN;


/* ==========================================================================
 *! \struct ADI_RTC_CR4SS_Struct
 *! \brief  RTC Control 4 for Configuring SensorStrobe Channel Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CR4SS_t__
typedef struct _ADI_RTC_CR4SS_t {
  union {
    struct {
      uint16_t reserved0  :  1;
      uint16_t SS1MSKEN   :  1;  /**< Enable for Thermometer-Code Masking of the SensorStrobe Channel 1 */
      uint16_t SS2MSKEN   :  1;  /**< Enable for Thermometer-Code Masking of the SensorStrobe Channel 2 */
      uint16_t SS3MSKEN   :  1;  /**< Enable for Thermometer-Code Masking of the SensorStrobe Channel 3 */
      uint16_t SS4MSKEN   :  1;  /**< Enable for Thermometer-Code Masking of the SensorStrobe Channel 4 */
      uint16_t SS1POL     :  1;  /**< SensorSTrobe Channel 1 Polarity Control */
      uint16_t SS2POL     :  1;  /**< SensorStrobe Channel 2 Polarity Control */
      uint16_t SS3POL     :  1;  /**< SensorStrobe Channel 3 Polarity Control */
      uint16_t SS4POL     :  1;  /**< SensorStrobe Channel 4 Polarity Control */
      uint16_t SS1ARLEN   :  1;  /**< Enable for Fine Control on SensorStrobe Channel 1 Period and Duty Cycle */
      uint16_t SS2ARLEN   :  1;  /**< Enable for Fine Control on SensorStrobe Channel 2 Period and Duty Cycle */
      uint16_t SS3ARLEN   :  1;  /**< Enable for Fine Control on SensorStrobe Channel 3 Period and Duty Cycle */
      uint16_t reserved12 :  4;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CR4SS_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CR4SS_t__ */

/*@}*/

/** @defgroup SSMSK RTC Mask for SensorStrobe Channel (SSMSK) Register
 *  RTC Mask for SensorStrobe Channel (SSMSK) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SSMSK_Struct
 *! \brief  RTC Mask for SensorStrobe Channel Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SSMSK_t__
typedef struct _ADI_RTC_SSMSK_t {
  union {
    struct {
      uint16_t SS1MSK     :  4;  /**< Concatenation of Thermometer-Encoded Masks for the 16-bit SensorStrobe Channels */
      uint16_t SS2MSK     :  4;  /**< SensorStrobe Channel 2 Period Control */
      uint16_t SS3MSK     :  4;  /**< SensorStrobe Channel 3 Period Control */
      uint16_t SS4MSK     :  4;  /**< SensorStrobe Channel 4 Period Control */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SSMSK_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SSMSK_t__ */

/*@}*/

/** @defgroup IC2 RTC Input Capture Channel 2 (IC2) Register
 *  RTC Input Capture Channel 2 (IC2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_IC2_Struct
 *! \brief  RTC Input Capture Channel 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_IC2_t__
typedef struct _ADI_RTC_IC2_t {
  union {
    struct {
      uint16_t IC2        : 16;  /**< RTC Input Capture Channel 2 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_IC2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_IC2_t__ */

/*@}*/

/** @defgroup IC3 RTC Input Capture Channel 3 (IC3) Register
 *  RTC Input Capture Channel 3 (IC3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_IC3_Struct
 *! \brief  RTC Input Capture Channel 3 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_IC3_t__
typedef struct _ADI_RTC_IC3_t {
  union {
    struct {
      uint16_t IC3        : 16;  /**< RTC Input Capture Channel 3 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_IC3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_IC3_t__ */

/*@}*/

/** @defgroup IC4 RTC Input Capture Channel 4 (IC4) Register
 *  RTC Input Capture Channel 4 (IC4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_IC4_Struct
 *! \brief  RTC Input Capture Channel 4 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_IC4_t__
typedef struct _ADI_RTC_IC4_t {
  union {
    struct {
      uint16_t IC4        : 16;  /**< RTC Input Capture Channel 4 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_IC4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_IC4_t__ */

/*@}*/

/** @defgroup SS1 RTC SensorStrobe Channel 1 (SS1) Register
 *  RTC SensorStrobe Channel 1 (SS1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SS1_Struct
 *! \brief  RTC SensorStrobe Channel 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SS1_t__
typedef struct _ADI_RTC_SS1_t {
  union {
    struct {
      uint16_t SS1        : 16;  /**< SensorStrobe Channel 1 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SS1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SS1_t__ */

/*@}*/

/** @defgroup SS2 RTC SensorStrobe Channel 2 (SS2) Register
 *  RTC SensorStrobe Channel 2 (SS2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SS2_Struct
 *! \brief  RTC SensorStrobe Channel 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SS2_t__
typedef struct _ADI_RTC_SS2_t {
  union {
    struct {
      uint16_t SS2        : 16;  /**< SensorStrobe Channel 2 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SS2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SS2_t__ */

/*@}*/

/** @defgroup SS3 RTC SensorStrobe Channel 3 (SS3) Register
 *  RTC SensorStrobe Channel 3 (SS3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SS3_Struct
 *! \brief  RTC SensorStrobe Channel 3 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SS3_t__
typedef struct _ADI_RTC_SS3_t {
  union {
    struct {
      uint16_t SS3        : 16;  /**< SensorStrobe Channel 3 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SS3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SS3_t__ */

/*@}*/

/** @defgroup SS4 RTC SensorStrobe Channel 4 (SS4) Register
 *  RTC SensorStrobe Channel 4 (SS4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SS4_Struct
 *! \brief  RTC SensorStrobe Channel 4 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SS4_t__
typedef struct _ADI_RTC_SS4_t {
  union {
    struct {
      uint16_t SS4        : 16;  /**< SensorStrobe Channel 4 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SS4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SS4_t__ */

/*@}*/

/** @defgroup SR4 RTC Status 4 (SR4) Register
 *  RTC Status 4 (SR4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR4_Struct
 *! \brief  RTC Status 4 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR4_t__
typedef struct _ADI_RTC_SR4_t {
  union {
    struct {
      uint16_t WSYNCSR3   :  1;  /**< Synchronisation Status of Posted Writes to SR3 */
      uint16_t WSYNCCR2IC :  1;  /**< Synchronization Status of Posted Writes to RTC Control 2 for Configuring Input Capture Channels Register */
      uint16_t WSYNCCR3SS :  1;  /**< Synchronization Status of Posted Writes to RTC Control 3 for Configuring SensorStrobe Channel Register */
      uint16_t WSYNCCR4SS :  1;  /**< Synchronization Status of Posted Writes to RTC Control 4 for Configuring SensorStrobe Channel Register */
      uint16_t WSYNCSSMSK :  1;  /**< Synchronization Status of Posted Writes to Masks for SensorStrobe Channel Register */
      uint16_t reserved5  :  1;
      uint16_t WSYNCSS1   :  1;  /**< Synchronization Status of Posted Writes to SensorStrobe Channel 1 */
      uint16_t WSYNCSS2   :  1;  /**< Synchronization Status of Posted Writes to SensorStrobe Channel 2 */
      uint16_t WSYNCSS3   :  1;  /**< Synchronization Status of Posted Writes to SensorStrobe Channel 3 */
      uint16_t WSYNCSS4   :  1;  /**< Synchronization Status of Posted Writes to SensorStrobe Channel 4 */
      uint16_t RSYNCIC0   :  1;  /**< Synchronization Status of Posted Reads of RTC Input Channel 0 */
      uint16_t reserved11 :  1;
      uint16_t RSYNCIC2   :  1;  /**< Synchronization Status of Posted Reads of RTC Input Channel 2 */
      uint16_t RSYNCIC3   :  1;  /**< Synchronization Status of Posted Reads of RTC Input Channel 3 */
      uint16_t RSYNCIC4   :  1;  /**< Synchronization Status of Posted Reads of RTC Input Channel 4 */
      uint16_t WSYNCSSMSKOT :  1;  /**< Synchronization Status of Posted Reads Writes to Mask for SensorStrobe Channels on Time Control Register */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR4_t__ */

/*@}*/

/** @defgroup SR5 RTC Status 5 (SR5) Register
 *  RTC Status 5 (SR5) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR5_Struct
 *! \brief  RTC Status 5 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR5_t__
typedef struct _ADI_RTC_SR5_t {
  union {
    struct {
      uint16_t WPENDSR3   :  1;  /**< Pending Status of Posted Clearances of Interrupt Sources in RTC Status 3 Register */
      uint16_t WPENDCR2IC :  1;  /**< Pending Status of Posted Writes to RTC Control 2 for Configuring Input Capture Channels Register */
      uint16_t WPENDCR3SS :  1;  /**< Pending Status of Posted Writes to RTC Control 3 for Configuring SensorStrobe Channel Register */
      uint16_t WPENDCR4SS :  1;  /**< Pending Status of Posted Writes to RTC Control 4 for Configuring SensorStrobe Channel Register */
      uint16_t WPENDSSMSK :  1;  /**< Pending Status of Posted Writes to RTC Masks for SensorStrobe Channel Register */
      uint16_t reserved5  :  1;
      uint16_t WPENDSS1   :  1;  /**< Pending Status of Posted Writes to SensorStrobe Channel 1 */
      uint16_t WPENDSS2   :  1;  /**< Pending Status of Posted Writes to SensorStrobe Channel 2 */
      uint16_t WPENDSS3   :  1;  /**< Pending Status of Posted Writes to SensorStrobe Channel 3 */
      uint16_t WPENDSS4   :  1;  /**< Pending Status of Posted Writes to SensorStrobe Channel 4 */
      uint16_t RPENDIC0   :  1;  /**< Pending Status of Posted Reads of Input Capture Channel 0 */
      uint16_t reserved11 :  1;
      uint16_t RPENDIC2   :  1;  /**< Pending Status of Posted Reads of IC2 */
      uint16_t RPENDIC3   :  1;  /**< Pending Status of Posted Reads of IC3 */
      uint16_t RPENDIC4   :  1;  /**< Pending Status of Posted Reads of IC4 */
      uint16_t WPENDSSMSKOT :  1;  /**< Pending Status of Posted Writes to RTC Masks for SensorStrobe Channel Register */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR5_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR5_t__ */

/*@}*/

/** @defgroup SR6 RTC Status 6 (SR6) Register
 *  RTC Status 6 (SR6) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR6_Struct
 *! \brief  RTC Status 6 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR6_t__
typedef struct _ADI_RTC_SR6_t {
  union {
    struct {
      uint16_t IC0UNR     :  1;  /**< Sticky Unread Status of the Input Capture Channel 0 */
      uint16_t reserved1  :  1;
      uint16_t IC2UNR     :  1;  /**< Sticky Unread Status of the Input Capture Channel 2 */
      uint16_t IC3UNR     :  1;  /**< Sticky Unread Status of the Input Capture Channel 3 */
      uint16_t IC4UNR     :  1;  /**< Sticky Unread Status of the Input Capture Channel 4 */
      uint16_t reserved5  :  3;
      uint16_t IC0SNAP    :  1;  /**< Confirmation That RTC Snapshot 0, 1, 2 Registers Reflect the Value of Input-Capture Channel RTC Input Capture Channel 0 */
      uint16_t FRZCNTPTR  :  2;  /**< Pointer for the Triple-Read Sequence of FRZCNT */
      uint16_t reserved11 :  5;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR6_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR6_t__ */

/*@}*/

/** @defgroup SS1TGT RTC SensorStrobe Channel 1 Target (SS1TGT) Register
 *  RTC SensorStrobe Channel 1 Target (SS1TGT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SS1TGT_Struct
 *! \brief  RTC SensorStrobe Channel 1 Target Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SS1TGT_t__
typedef struct _ADI_RTC_SS1TGT_t {
  union {
    struct {
      uint16_t SS1TGT     : 16;  /**< Current Target Value for the SensorStrobe Channel 1 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SS1TGT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SS1TGT_t__ */

/*@}*/

/** @defgroup FRZCNT RTC Freeze Count (FRZCNT) Register
 *  RTC Freeze Count (FRZCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_FRZCNT_Struct
 *! \brief  RTC Freeze Count Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_FRZCNT_t__
typedef struct _ADI_RTC_FRZCNT_t {
  union {
    struct {
      uint16_t FRZCNT     : 16;  /**< RTC Freeze Count. Coherent, Triple 16-Bit Read of the 47-Bit RTC Count */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_FRZCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_FRZCNT_t__ */

/*@}*/

/** @defgroup SS2TGT RTC SensorStrobe Channel 2 Target (SS2TGT) Register
 *  RTC SensorStrobe Channel 2 Target (SS2TGT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SS2TGT_Struct
 *! \brief  RTC SensorStrobe Channel 2 Target Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SS2TGT_t__
typedef struct _ADI_RTC_SS2TGT_t {
  union {
    struct {
      uint16_t SS2TGT     : 16;  /**< Current, Cumulative Target Time for SensorStrobe Channel 2, Taking Account of Any Auto-reloading */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SS2TGT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SS2TGT_t__ */

/*@}*/

/** @defgroup SS3TGT RTC SensorStrobe Channel 3 Target (SS3TGT) Register
 *  RTC SensorStrobe Channel 3 Target (SS3TGT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SS3TGT_Struct
 *! \brief  RTC SensorStrobe Channel 3 Target Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SS3TGT_t__
typedef struct _ADI_RTC_SS3TGT_t {
  union {
    struct {
      uint16_t SS3TGT     : 16;  /**< Current, Cumulative Target Time for SensorStrobe Channel 3, Taking Account of Any Auto-reloading */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SS3TGT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SS3TGT_t__ */

/*@}*/

/** @defgroup SS1LOWDUR RTC Auto-Reload Low Duration for SensorStrobe Channel 1 (SS1LOWDUR) Register
 *  RTC Auto-Reload Low Duration for SensorStrobe Channel 1 (SS1LOWDUR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SS1LOWDUR_Struct
 *! \brief  RTC Auto-Reload Low Duration for SensorStrobe Channel 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SS1LOWDUR_t__
typedef struct _ADI_RTC_SS1LOWDUR_t {
  union {
    struct {
      uint16_t SS1LOWDUR  : 16;  /**< Low Duration for SensorStrobe Channel 1 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SS1LOWDUR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SS1LOWDUR_t__ */

/*@}*/

/** @defgroup SS2LOWDUR RTC Auto-Reload Low Duration for SensorStrobe Channel 2 (SS2LOWDUR) Register
 *  RTC Auto-Reload Low Duration for SensorStrobe Channel 2 (SS2LOWDUR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SS2LOWDUR_Struct
 *! \brief  RTC Auto-Reload Low Duration for SensorStrobe Channel 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SS2LOWDUR_t__
typedef struct _ADI_RTC_SS2LOWDUR_t {
  union {
    struct {
      uint16_t SS2LOWDUR  : 16;  /**< Low Duration for SensorStrobe Channel 2 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SS2LOWDUR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SS2LOWDUR_t__ */

/*@}*/

/** @defgroup SS3LOWDUR RTC Auto-Reload Low Duration for SensorStrobe Channel 3 (SS3LOWDUR) Register
 *  RTC Auto-Reload Low Duration for SensorStrobe Channel 3 (SS3LOWDUR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SS3LOWDUR_Struct
 *! \brief  RTC Auto-Reload Low Duration for SensorStrobe Channel 3 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SS3LOWDUR_t__
typedef struct _ADI_RTC_SS3LOWDUR_t {
  union {
    struct {
      uint16_t SS3LOWDUR  : 16;  /**< Low Duration for SensorStrobe Channel 3 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SS3LOWDUR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SS3LOWDUR_t__ */

/*@}*/

/** @defgroup SS1HIGHDUR RTC Auto-Reload High Duration for SensorStrobe Channel 1 (SS1HIGHDUR) Register
 *  RTC Auto-Reload High Duration for SensorStrobe Channel 1 (SS1HIGHDUR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SS1HIGHDUR_Struct
 *! \brief  RTC Auto-Reload High Duration for SensorStrobe Channel 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SS1HIGHDUR_t__
typedef struct _ADI_RTC_SS1HIGHDUR_t {
  union {
    struct {
      uint16_t SS1HIGHDUR : 16;  /**< High Duration for SensorStrobe Channel 1 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SS1HIGHDUR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SS1HIGHDUR_t__ */

/*@}*/

/** @defgroup SS2HIGHDUR RTC Auto-Reload High Duration for SensorStrobe Channel 2 (SS2HIGHDUR) Register
 *  RTC Auto-Reload High Duration for SensorStrobe Channel 2 (SS2HIGHDUR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SS2HIGHDUR_Struct
 *! \brief  RTC Auto-Reload High Duration for SensorStrobe Channel 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SS2HIGHDUR_t__
typedef struct _ADI_RTC_SS2HIGHDUR_t {
  union {
    struct {
      uint16_t SS2HIGHDUR : 16;  /**< High Duration for SensorStrobe Channel 2 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SS2HIGHDUR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SS2HIGHDUR_t__ */

/*@}*/

/** @defgroup SS3HIGHDUR RTC Auto-Reload High Duration for SensorStrobe Channel 3 (SS3HIGHDUR) Register
 *  RTC Auto-Reload High Duration for SensorStrobe Channel 3 (SS3HIGHDUR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SS3HIGHDUR_Struct
 *! \brief  RTC Auto-Reload High Duration for SensorStrobe Channel 3 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SS3HIGHDUR_t__
typedef struct _ADI_RTC_SS3HIGHDUR_t {
  union {
    struct {
      uint16_t SS3HIGHDUR : 16;  /**< High Duration for SensorStrobe Channel 3 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SS3HIGHDUR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SS3HIGHDUR_t__ */

/*@}*/

/** @defgroup SSMSKOT RTC Masks for SensorStrobe Channels on Time Control (SSMSKOT) Register
 *  RTC Masks for SensorStrobe Channels on Time Control (SSMSKOT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SSMSKOT_Struct
 *! \brief  RTC Masks for SensorStrobe Channels on Time Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SSMSKOT_t__
typedef struct _ADI_RTC_SSMSKOT_t {
  union {
    struct {
      uint16_t SS1MSKOT   :  4;  /**< Concatenation of Thermometer-encoded Masks for the 16-bit SensorStrobe Channels */
      uint16_t SS2MSKOT   :  4;  /**< SensorStrobe Channel 2 on Time Control */
      uint16_t SS3MSKOT   :  4;  /**< SensorStrobe Channel 3 on Time Control */
      uint16_t SS4MSKOT   :  4;  /**< SensorStrobe Channel 4 on Time Control */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SSMSKOT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SSMSKOT_t__ */

/*@}*/

/** @defgroup CR5SSS RTC Control 5 for Configuring SensorStrobe Channel GPIO Sampling (CR5SSS) Register
 *  RTC Control 5 for Configuring SensorStrobe Channel GPIO Sampling (CR5SSS) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_CR5SSS_Struct
 *! \brief  RTC Control 5 for Configuring SensorStrobe Channel GPIO Sampling Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CR5SSS_t__
typedef struct _ADI_RTC_CR5SSS_t {
  union {
    struct {
      uint16_t SS1SMPEN   :  3;  /**< GPIO Input Sample Enable for SensorStrobe Channel 1 */
      uint16_t SS1SMPMTCHIRQEN :  1;  /**< Sample Activity Interrupt Enable for SensorStrobe Channel 1 */
      uint16_t SS2SMPEN        :  3;  /**< GPIO Input Sample Enable for SensorStrobe Channel 2 */
      uint16_t SS2SMPMTCHIRQEN :  1;  /**< Sample Activity Interrupt Enable for SensorStrobe Channel 2 */
      uint16_t SS3SMPEN        :  3;  /**< GPIO Input Sample Enable for SensorStrobe Channel 3 */
      uint16_t SS3SMPMTCHIRQEN :  1;  /**< Sample Activity Interrupt Enable for SensorStrobe Channel 3 */
      uint16_t reserved12      :  4;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CR5SSS_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CR5SSS_t__ */

/*@}*/

/** @defgroup CR6SSS RTC Control 6 for Configuring SensorStrobe Channel GPIO Sampling Edge (CR6SSS) Register
 *  RTC Control 6 for Configuring SensorStrobe Channel GPIO Sampling Edge (CR6SSS) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_RTC_CR6SSS_SS1SMPONFE
 *! \brief  GPIO Sample Around Falling Edge of SensorStrobe Channel 1 (SS1SMPONFE) Enumerations
 *  ========================================================================= */
typedef enum
{
  RTC_CR6SSS_SS1NOFES = 0,  /**< No sampling of input around falling edge                                        */
  RTC_CR6SSS_SS1BFES  = 1,  /**< Input sampled one clock cycle before falling edge of the SensorStrobe channel 1 */
  RTC_CR6SSS_SS1FES   = 2,  /**< Input sampled at falling edge of the SensorStrobe channel 1                     */
  RTC_CR6SSS_SS1AFES  = 3   /**< Input sampled one clock cycle after falling edge of the SensorStrobe channel 1  */
} ADI_RTC_CR6SSS_SS1SMPONFE;


/*  =========================================================================
 *! \enum   ADI_RTC_CR6SSS_SS1SMPONRE
 *! \brief  GPIO Sample Around Rising Edge of SensorStrobe Channel 1 (SS1SMPONRE) Enumerations
 *  ========================================================================= */
typedef enum
{
  RTC_CR6SSS_SS1NORES = 0,  /**< No sampling of input around rising edge                                        */
  RTC_CR6SSS_SS1BRES  = 1,  /**< Input sampled one clock cycle before rising edge of the SensorStrobe channel 1 */
  RTC_CR6SSS_SS1RES   = 2,  /**< Input sampled at rising edge of the SensorStrobe channel 1                     */
  RTC_CR6SSS_SS1ARES  = 3   /**< Input sampled one clock cycle after rising edge of the SensorStrobe channel 1  */
} ADI_RTC_CR6SSS_SS1SMPONRE;


/*  =========================================================================
 *! \enum   ADI_RTC_CR6SSS_SS2SMPONFE
 *! \brief  GPIO Sample Around Falling Edge of SensorStrobe Channel 2 (SS2SMPONFE) Enumerations
 *  ========================================================================= */
typedef enum
{
  RTC_CR6SSS_SS2NOFES = 0,  /**< No sampling of input around falling edge                                        */
  RTC_CR6SSS_SS2BFES  = 1,  /**< Input sampled one clock cycle before falling edge of the SensorStrobe channel 2 */
  RTC_CR6SSS_SS2FES   = 2,  /**< Input sampled at falling edge of the SensorStrobe channel 2                     */
  RTC_CR6SSS_SS2AFES  = 3   /**< Input sampled one clock cycle after falling edge of the SensorStrobe channel 2  */
} ADI_RTC_CR6SSS_SS2SMPONFE;


/*  =========================================================================
 *! \enum   ADI_RTC_CR6SSS_SS2SMPONRE
 *! \brief  GPIO Sample Around Rising Edge of SensorStrobe Channel 2 (SS2SMPONRE) Enumerations
 *  ========================================================================= */
typedef enum
{
  RTC_CR6SSS_SS2NORES = 0,  /**< No sampling of input around rising edge                                        */
  RTC_CR6SSS_SS2BRES  = 1,  /**< Input sampled one clock cycle before rising edge of the SensorStrobe channel 2 */
  RTC_CR6SSS_SS2RES   = 2,  /**< Input sampled at rising edge of the SensorStrobe channel 2                     */
  RTC_CR6SSS_SS2ARES  = 3   /**< Input sampled one clock cycle after rising edge of the SensorStrobe channel 2  */
} ADI_RTC_CR6SSS_SS2SMPONRE;


/*  =========================================================================
 *! \enum   ADI_RTC_CR6SSS_SS3SMPONFE
 *! \brief  GPIO Sample Around Falling Edge of SensorStrobe Channel 3 (SS3SMPONFE) Enumerations
 *  ========================================================================= */
typedef enum
{
  RTC_CR6SSS_SS3NOFES = 0,  /**< No sampling of input around falling edge                                        */
  RTC_CR6SSS_SS3BFES  = 1,  /**< Input sampled one clock cycle before falling edge of the SensorStrobe channel 3 */
  RTC_CR6SSS_SS3FES   = 2,  /**< Input sampled at falling edge of the SensorStrobe channel 3                     */
  RTC_CR6SSS_SS3AFES  = 3   /**< Input sampled one clock cycle after falling edge of the SensorStrobe channel 3  */
} ADI_RTC_CR6SSS_SS3SMPONFE;


/*  =========================================================================
 *! \enum   ADI_RTC_CR6SSS_SS3SMPONRE
 *! \brief  GPIO Sample Around Rising Edge of SensorStrobe Channel 3 (SS3SMPONRE) Enumerations
 *  ========================================================================= */
typedef enum
{
  RTC_CR6SSS_SS3NORES = 0,  /**< No sampling of input around rising edge                                        */
  RTC_CR6SSS_SS3BRES  = 1,  /**< Input sampled one clock cycle before rising edge of the SensorStrobe channel 3 */
  RTC_CR6SSS_SS3RES   = 2,  /**< Input sampled at rising edge of the SensorStrobe channel 3                     */
  RTC_CR6SSS_SS3ARES  = 3   /**< Input sampled one clock cycle after rising edge of the SensorStrobe channel 3  */
} ADI_RTC_CR6SSS_SS3SMPONRE;


/* ==========================================================================
 *! \struct ADI_RTC_CR6SSS_Struct
 *! \brief  RTC Control 6 for Configuring SensorStrobe Channel GPIO Sampling Edge Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CR6SSS_t__
typedef struct _ADI_RTC_CR6SSS_t {
  union {
    struct {
      uint16_t SS1SMPONFE :  2;  /**< GPIO Sample Around Falling Edge of SensorStrobe Channel 1 */
      uint16_t SS1SMPONRE :  2;  /**< GPIO Sample Around Rising Edge of SensorStrobe Channel 1 */
      uint16_t SS2SMPONFE :  2;  /**< GPIO Sample Around Falling Edge of SensorStrobe Channel 2 */
      uint16_t SS2SMPONRE :  2;  /**< GPIO Sample Around Rising Edge of SensorStrobe Channel 2 */
      uint16_t SS3SMPONFE :  2;  /**< GPIO Sample Around Falling Edge of SensorStrobe Channel 3 */
      uint16_t SS3SMPONRE :  2;  /**< GPIO Sample Around Rising Edge of SensorStrobe Channel 3 */
      uint16_t reserved12 :  4;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CR6SSS_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CR6SSS_t__ */

/*@}*/

/** @defgroup CR7SSS RTC Control 7 for Configuring SensorStrobe Channel GPIO Sampling Activity (CR7SSS) Register
 *  RTC Control 7 for Configuring SensorStrobe Channel GPIO Sampling Activity (CR7SSS) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_RTC_CR7SSS_SS1SMPPTRN
 *! \brief  Sample Activity Selection for SensorStrobe Channel 1 (SS1SMPPTRN) Enumerations
 *  ========================================================================= */
typedef enum
{
  RTC_CR7SSS_SS1SMPCHNG   = 0,  /**< Current GPIO sample is not same as previous sample */
  RTC_CR7SSS_SS1SMPSAME   = 1,  /**< Current GPIO sample is same as previous sample     */
  RTC_CR7SSS_SS1SMPMTCH   = 2,  /**< Current GPIO sample is same as expected sample     */
  RTC_CR7SSS_SS1SMPNOMTCH = 3   /**< Current GPIO sample is not same as expected sample */
} ADI_RTC_CR7SSS_SS1SMPPTRN;


/*  =========================================================================
 *! \enum   ADI_RTC_CR7SSS_SS2SMPPTRN
 *! \brief  Sample Activity Selection for SensorStrobe Channel 2 (SS2SMPPTRN) Enumerations
 *  ========================================================================= */
typedef enum
{
  RTC_CR7SSS_SS2SMPCHNG   = 0,  /**< Current GPIO sample is not same as previous sample */
  RTC_CR7SSS_SS2SMPSAME   = 1,  /**< Current GPIO sample is same as previous sample     */
  RTC_CR7SSS_SS2SMPMTCH   = 2,  /**< Current GPIO sample is same as expected sample     */
  RTC_CR7SSS_SS2SMPNOMTCH = 3   /**< Current GPIO sample is not same as expected sample */
} ADI_RTC_CR7SSS_SS2SMPPTRN;


/*  =========================================================================
 *! \enum   ADI_RTC_CR7SSS_SS3SMPPTRN
 *! \brief  Sample Activity Selection for SensorStrobe Channel 3 (SS3SMPPTRN) Enumerations
 *  ========================================================================= */
typedef enum
{
  RTC_CR7SSS_SS3SMPCHNG   = 0,  /**< Current GPIO sample is not same as previous sample */
  RTC_CR7SSS_SS3SMPSAME   = 1,  /**< Current GPIO sample is same as previous sample     */
  RTC_CR7SSS_SS3SMPMTCH   = 2,  /**< Current GPIO sample is same as expected sample     */
  RTC_CR7SSS_SS3SMPNOMTCH = 3   /**< Current GPIO sample is not same as expected sample */
} ADI_RTC_CR7SSS_SS3SMPPTRN;


/* ==========================================================================
 *! \struct ADI_RTC_CR7SSS_Struct
 *! \brief  RTC Control 7 for Configuring SensorStrobe Channel GPIO Sampling Activity Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CR7SSS_t__
typedef struct _ADI_RTC_CR7SSS_t {
  union {
    struct {
      uint16_t SS1SMPEXP  :  3;  /**< Expected GPIO Sample for SensorStrobe Channel 1 */
      uint16_t SS1SMPPTRN :  2;  /**< Sample Activity Selection for SensorStrobe Channel 1 */
      uint16_t SS2SMPEXP  :  3;  /**< Expected GPIO Sample for SensorStrobe Channel 2 */
      uint16_t SS2SMPPTRN :  2;  /**< Sample Activity Selection for SensorStrobe Channel 2 */
      uint16_t SS3SMPEXP  :  3;  /**< Expected GPIO Sample for SensorStrobe Channel 3 */
      uint16_t SS3SMPPTRN :  2;  /**< Sample Activity Selection for SensorStrobe Channel 3 */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CR7SSS_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CR7SSS_t__ */

/*@}*/

/** @defgroup SR7 RTC Status 7 (SR7) Register
 *  RTC Status 7 (SR7) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR7_Struct
 *! \brief  RTC Status 7 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR7_t__
typedef struct _ADI_RTC_SR7_t {
  union {
    struct {
      uint16_t SS1SMP     :  3;  /**< Latest GPIO Sample for SensorStrobe Channel 1 */
      uint16_t SS1SMPMTCHIRQ :  1;  /**< Sticky Status of GPIO Sample Pattern Match for SensorStrobe Channel 1 */
      uint16_t SS2SMP        :  3;  /**< Latest GPIO Sample for SensorStrobe Channel 2 */
      uint16_t SS2SMPMTCHIRQ :  1;  /**< Sticky Status of GPIO Sample Pattern Match for SensorStrobe Channel 2 */
      uint16_t SS3SMP        :  3;  /**< Latest GPIO Sample for SensorStrobe Channel 3 */
      uint16_t SS3SMPMTCHIRQ :  1;  /**< Sticky Status of GPIO Sample Pattern Match for SensorStrobe Channel 3 */
      uint16_t SS1OUT        :  1;  /**< Output Value for SensorStrobe Channel 1 */
      uint16_t SS2OUT        :  1;  /**< Output Value for SensorStrobe Channel 2 */
      uint16_t SS3OUT        :  1;  /**< Output Value for SensorStrobe Channel 3 */
      uint16_t SS4OUT        :  1;  /**< Output Value for SensorStrobe Channel 4 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR7_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR7_t__ */

/*@}*/

/** @defgroup SR8 RTC Status 8 (SR8) Register
 *  RTC Status 8 (SR8) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR8_Struct
 *! \brief  RTC Status 8 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR8_t__
typedef struct _ADI_RTC_SR8_t {
  union {
    struct {
      uint16_t WSYNCSS1LOWDUR :  1;  /**< Synchronisation Status of Posted Writes to SensorStrobe Channel 1 Low Duration Register */
      uint16_t WSYNCSS2LOWDUR :  1;  /**< Synchronisation Status of Posted Writes to SensorStrobe Channel 2 Low Duration Register */
      uint16_t WSYNCSS3LOWDUR :  1;  /**< Synchronisation Status of Posted Writes to SensorStrobe Channel 3 Low Duration Register */
      uint16_t reserved3       :  1;
      uint16_t WSYNCSS1HIGHDUR :  1;  /**< Synchronisation Status of Posted Writes to SensorStrobe Channel 1 High Duration Register */
      uint16_t WSYNCSS2HIGHDUR :  1;  /**< Synchronisation Status of Posted Writes to SensorStrobe Channel 2 High Duration Register */
      uint16_t WSYNCSS3HIGHDUR :  1;  /**< Synchronisation Status of Posted Writes to SensorStrobe Channel 3 High Duration Register */
      uint16_t reserved7       :  1;
      uint16_t WSYNCCR5SSS     :  1;  /**< Synchronisation Status of Posted Writes to Control 5 for Configuring SensorStrobe Channel Register */
      uint16_t WSYNCCR6SSS     :  1;  /**< Synchronisation Status of Posted Writes to Control 6 for Configuring SensorStrobe Channel Register */
      uint16_t WSYNCCR7SSS     :  1;  /**< Synchronisation Status of Posted Writes to Control 7 for Configuring SensorStrobe Channel Register */
      uint16_t WSYNCSR7        :  1;  /**< Synchronisation Status of Posted Writes to Status 7 Register */
      uint16_t WSYNCGPMUX0     :  1;  /**< Synchronisation Status of Posted Writes to GPIO Pin Mux Control Register 0 */
      uint16_t WSYNCGPMUX1     :  1;  /**< Synchronisation Status of Posted Writes to GPIO Pin Mux Control Register 1 */
      uint16_t reserved14      :  2;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR8_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR8_t__ */

/*@}*/

/** @defgroup SR9 RTC Status 9 (SR9) Register
 *  RTC Status 9 (SR9) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR9_Struct
 *! \brief  RTC Status 9 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR9_t__
typedef struct _ADI_RTC_SR9_t {
  union {
    struct {
      uint16_t WPENDSS1LOWDUR :  1;  /**< Pending Status of Posted Writes to SensortStrobe Channel 1 Low Duration Register */
      uint16_t WPENDSS2LOWDUR :  1;  /**< Pending Status of Posted Writes to SensortStrobe Channel 2 Low Duration Register */
      uint16_t WPENDSS3LOWDUR :  1;  /**< Pending Status of Posted Writes to SensortStrobe Channel 3 Low Duration Register */
      uint16_t reserved3       :  1;
      uint16_t WPENDSS1HIGHDUR :  1;  /**< Pending Status of Posted Writes to SensortStrobe Channel 1 High Duration Register */
      uint16_t WPENDSS2HIGHDUR :  1;  /**< Pending Status of Posted Writes to SensortStrobe Channel 2 High Duration Register */
      uint16_t WPENDSS3HIGHDUR :  1;  /**< Pending Status of Posted Writes to SensortStrobe Channel 3 High Duration Register */
      uint16_t reserved7       :  1;
      uint16_t WPENDCR5SSS     :  1;  /**< Pending Status of Posted Writes to Control 5 for Configuring SensorStrobe Channel Register */
      uint16_t WPENDCR6SSS     :  1;  /**< Pending Status of Posted Writes to Control 6 for Configuring SensorStrobe Channel Register */
      uint16_t WPENDCR7SSS     :  1;  /**< Pending Status of Posted Writes to Control 7 for Configuring SensorStrobe Channel Register */
      uint16_t WPENDSR7        :  1;  /**< Pending Status of Posted Writes to SR7 */
      uint16_t WPENDGPMUX0     :  1;  /**< Pending Status of Posted Writes to GPMUX0 */
      uint16_t WPENDGPMUX1     :  1;  /**< Pending Status of Posted Writes to  GPMUX1 */
      uint16_t reserved14      :  2;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR9_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR9_t__ */

/*@}*/

/** @defgroup GPMUX0 RTC GPIO Pin Mux Control Register 0 (GPMUX0) Register
 *  RTC GPIO Pin Mux Control Register 0 (GPMUX0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_GPMUX0_Struct
 *! \brief  RTC GPIO Pin Mux Control Register 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_GPMUX0_t__
typedef struct _ADI_RTC_GPMUX0_t {
  union {
    struct {
      uint16_t SS1GPIN0SEL :  3;  /**< GPIO Mux Selection for SensorStrobe Channel 1 Input0 */
      uint16_t SS1GPIN1SEL :  3;  /**< GPIO Mux Selection for SensorStrobe Channel 1 Input 1 */
      uint16_t SS1GPIN2SEL :  3;  /**< GPIO Mux Selection for SensorStrobe Channel 1 Input 2 */
      uint16_t SS2GPIN0SEL :  3;  /**< GPIO Mux Selection for SensorStrobe Channel 2 Input 0 */
      uint16_t SS2GPIN1SEL :  3;  /**< GPIO Mux Selection for SensorStrobe Channel 2 Input 1 */
      uint16_t reserved15  :  1;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_GPMUX0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_GPMUX0_t__ */

/*@}*/

/** @defgroup GPMUX1 RTC GPIO Pin Mux Control Register 1 (GPMUX1) Register
 *  RTC GPIO Pin Mux Control Register 1 (GPMUX1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_GPMUX1_Struct
 *! \brief  RTC GPIO Pin Mux Control Register 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_GPMUX1_t__
typedef struct _ADI_RTC_GPMUX1_t {
  union {
    struct {
      uint16_t SS2GPIN2SEL :  3;  /**< GPIO Mux Selection for SensorStrobe Channel 2 Input 2 */
      uint16_t SS3GPIN0SEL :  3;  /**< GPIO Mux Selection for SensorStrobe Channel 3 Input 0 */
      uint16_t SS3GPIN1SEL :  3;  /**< GPIO Mux Selection for SensorStrobe Channel 3 Input 1 */
      uint16_t SS3GPIN2SEL :  3;  /**< GPIO Mux Selection for SensorStrobe Channel 3 Input 2 */
      uint16_t reserved12  :  2;
      uint16_t SS1DIFFOUT  :  1;  /**< Differential SensorStrobe Out Option for SensorStrobe Channel 1 */
      uint16_t SS3DIFFOUT  :  1;  /**< Differential SensorStrobe Out Option for SensorStrobe Channel 3 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_GPMUX1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_GPMUX1_t__ */

/*@}*/

/** @defgroup ADIID ADI Identification (ADIID) Register
 *  ADI Identification (ADIID) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SYS_ADIID_Struct
 *! \brief  ADI Identification Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SYS_ADIID_t__
typedef struct _ADI_SYS_ADIID_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Reads a fixed value of 0x4144 to indicate to debuggers that they are connected to an Analog Devices implemented Cortex based part */
    };
    uint16_t VALUE16;
  };
} ADI_SYS_ADIID_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SYS_ADIID_t__ */

/*@}*/

/** @defgroup CHIPID Chip Identifier (CHIPID) Register
 *  Chip Identifier (CHIPID) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SYS_CHIPID_Struct
 *! \brief  Chip Identifier Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SYS_CHIPID_t__
typedef struct _ADI_SYS_CHIPID_t {
  union {
    struct {
      uint16_t REV        :  4;  /**< Silicon revision */
      uint16_t PARTID     : 12;  /**< Part identifier */
    };
    uint16_t VALUE16;
  };
} ADI_SYS_CHIPID_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SYS_CHIPID_t__ */

/*@}*/

/** @defgroup SWDEN Serial Wire Debug Enable (SWDEN) Register
 *  Serial Wire Debug Enable (SWDEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SYS_SWDEN_Struct
 *! \brief  Serial Wire Debug Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SYS_SWDEN_t__
typedef struct _ADI_SYS_SWDEN_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< To enable SWD interface */
    };
    uint16_t VALUE16;
  };
} ADI_SYS_SWDEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SYS_SWDEN_t__ */

/*@}*/

/** @defgroup LOAD Load Value (LOAD) Register
 *  Load Value (LOAD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_WDT_LOAD_Struct
 *! \brief  Load Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_WDT_LOAD_t__
typedef struct _ADI_WDT_LOAD_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Load Value */
    };
    uint16_t VALUE16;
  };
} ADI_WDT_LOAD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_WDT_LOAD_t__ */

/*@}*/

/** @defgroup CCNT Current Count Value (CCNT) Register
 *  Current Count Value (CCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_WDT_CCNT_Struct
 *! \brief  Current Count Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_WDT_CCNT_t__
typedef struct _ADI_WDT_CCNT_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Current Count Value */
    };
    uint16_t VALUE16;
  };
} ADI_WDT_CCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_WDT_CCNT_t__ */

/*@}*/

/** @defgroup CTL Control (CTL) Register
 *  Control (CTL) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_WDT_CTL_IRQ
 *! \brief  Timer Interrupt (IRQ) Enumerations
 *  ========================================================================= */
typedef enum
{
  WDT_CTL_RST = 0,  /**< WDT asserts reset when timed out       */
  WDT_CTL_INT = 1   /**< WDT generates interrupt when timed out */
} ADI_WDT_CTL_IRQ;


/*  =========================================================================
 *! \enum   ADI_WDT_CTL_PRE
 *! \brief  Prescaler (PRE) Enumerations
 *  ========================================================================= */
typedef enum
{
  WDT_CTL_DIV1   = 0,  /**< Source clock/1             */
  WDT_CTL_DIV16  = 1,  /**< Source clock/16            */
  WDT_CTL_DIV256 = 2   /**< Source clock/256 (default) */
} ADI_WDT_CTL_PRE;


/*  =========================================================================
 *! \enum   ADI_WDT_CTL_EN
 *! \brief  Timer Enable (EN) Enumerations
 *  ========================================================================= */
typedef enum
{
  WDT_CTL_WDT_DIS = 0,  /**< WDT not enabled */
  WDT_CTL_WDT_EN  = 1   /**< WDT enabled     */
} ADI_WDT_CTL_EN;


/*  =========================================================================
 *! \enum   ADI_WDT_CTL_MODE
 *! \brief  Timer Mode (MODE) Enumerations
 *  ========================================================================= */
typedef enum
{
  WDT_CTL_FREE_RUN = 0,  /**< Free running mode */
  WDT_CTL_PERIODIC = 1   /**< Periodic mode     */
} ADI_WDT_CTL_MODE;


/* ==========================================================================
 *! \struct ADI_WDT_CTL_Struct
 *! \brief  Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_WDT_CTL_t__
typedef struct _ADI_WDT_CTL_t {
  union {
    struct {
      uint16_t reserved0  :  1;
      uint16_t IRQ        :  1;  /**< Timer Interrupt */
      uint16_t PRE        :  2;  /**< Prescaler */
      uint16_t reserved4  :  1;
      uint16_t EN         :  1;  /**< Timer Enable */
      uint16_t MODE       :  1;  /**< Timer Mode */
      uint16_t SPARE      :  1;  /**< Unused Spare Bit */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_WDT_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_WDT_CTL_t__ */

/*@}*/

/** @defgroup RESTART Clear Interrupt (RESTART) Register
 *  Clear Interrupt (RESTART) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_WDT_RESTART_Struct
 *! \brief  Clear Interrupt Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_WDT_RESTART_t__
typedef struct _ADI_WDT_RESTART_t {
  union {
    struct {
      uint16_t CLRWORD    : 16;  /**< Clear Watchdog */
    };
    uint16_t VALUE16;
  };
} ADI_WDT_RESTART_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_WDT_RESTART_t__ */

/*@}*/

/** @defgroup STAT Status (STAT) Register
 *  Status (STAT) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_WDT_STAT_LOADING
 *! \brief  Load Register Write Sync in Progress (LOADING) Enumerations
 *  ========================================================================= */
typedef enum
{
  WDT_STAT_LOAD_MATCH   = 0,  /**< APB and WDT clock domains LOAD values match.              */
  WDT_STAT_LOAD_SYNCING = 1   /**< APB LOAD value is being synchronized to WDT clock domain. */
} ADI_WDT_STAT_LOADING;


/*  =========================================================================
 *! \enum   ADI_WDT_STAT_COUNTING
 *! \brief  Control Register Write Sync in Progress (COUNTING) Enumerations
 *  ========================================================================= */
typedef enum
{
  WDT_STAT_COUNT_MATCH   = 0,  /**< APB and WDT clock domain CTRL values match                           */
  WDT_STAT_COUNT_SYNCING = 1   /**< APB CTRL register values are being synchronized to WDT clock domain. */
} ADI_WDT_STAT_COUNTING;


/* ==========================================================================
 *! \struct ADI_WDT_STAT_Struct
 *! \brief  Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_WDT_STAT_t__
typedef struct _ADI_WDT_STAT_t {
  union {
    struct {
      uint16_t IRQ        :  1;  /**< WDT Interrupt */
      uint16_t CLRIRQ     :  1;  /**< Clear Interrupt Register Write Sync in Progress */
      uint16_t LOADING    :  1;  /**< Load Register Write Sync in Progress */
      uint16_t COUNTING   :  1;  /**< Control Register Write Sync in Progress */
      uint16_t LOCKED     :  1;  /**< Lock Status Bit */
      uint16_t reserved5  : 11;
    };
    uint16_t VALUE16;
  };
} ADI_WDT_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_WDT_STAT_t__ */

/*@}*/

/** @defgroup MCTL Master Control (MCTL) Register
 *  Master Control (MCTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_MCTL_Struct
 *! \brief  Master Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_MCTL_t__
typedef struct _ADI_I2C_MCTL_t {
  union {
    struct {
      uint16_t MASEN      :  1;  /**< Master Enable */
      uint16_t COMPLETE   :  1;  /**< Start Back-off Disable */
      uint16_t LOOPBACK   :  1;  /**< Internal Loopback Enable */
      uint16_t STRETCHSCL :  1;  /**< Stretch SCL Enable */
      uint16_t IENMRX     :  1;  /**< Receive Request Interrupt Enable */
      uint16_t IENMTX     :  1;  /**< Transmit Request Interrupt Enable */
      uint16_t IENALOST   :  1;  /**< Arbitration Lost Interrupt Enable */
      uint16_t IENACK     :  1;  /**< ACK Not Received Interrupt Enable */
      uint16_t IENCMP     :  1;  /**< Transaction Completed (or Stop Detected) Interrupt Enable */
      uint16_t MXMITDEC   :  1;  /**< Decrement Master Tx FIFO Status When a Byte Txed */
      uint16_t MRXDMA     :  1;  /**< Enable Master Rx DMA Request */
      uint16_t MTXDMA     :  1;  /**< Enable Master Tx DMA Request */
      uint16_t BUSCLR     :  1;  /**< Bus-Clear Enable */
      uint16_t STOPBUSCLR :  1;  /**< Prestop Bus Clear */
      uint16_t reserved14 :  2;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_MCTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_MCTL_t__ */

/*@}*/

/** @defgroup MSTAT Master Status (MSTAT) Register
 *  Master Status (MSTAT) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_I2C_MSTAT_MTXF
 *! \brief  Master Transmit FIFO Status (MTXF) Enumerations
 *  ========================================================================= */
typedef enum
{
  I2C_MSTAT_FIFO_EMPTY = 0,  /**< FIFO Empty.     */
  I2C_MSTAT_FIFO_1BYTE = 2,  /**< 1 byte in FIFO. */
  I2C_MSTAT_FIFO_FULL  = 3   /**< FIFO Full.      */
} ADI_I2C_MSTAT_MTXF;


/* ==========================================================================
 *! \struct ADI_I2C_MSTAT_Struct
 *! \brief  Master Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_MSTAT_t__
typedef struct _ADI_I2C_MSTAT_t {
  union {
    struct {
      uint16_t MTXF       :  2;  /**< Master Transmit FIFO Status */
      uint16_t MTXREQ     :  1;  /**< Master Transmit Request/Clear Master Transmit Interrupt */
      uint16_t MRXREQ     :  1;  /**< Master Receive Request */
      uint16_t NACKADDR   :  1;  /**< ACK Not Received in Response to an Address */
      uint16_t ALOST      :  1;  /**< Arbitration Lost */
      uint16_t MBUSY      :  1;  /**< Master Busy */
      uint16_t NACKDATA   :  1;  /**< ACK Not Received in Response to Data Write */
      uint16_t TCOMP      :  1;  /**< Transaction Complete or Stop Detected */
      uint16_t MRXOVR     :  1;  /**< Master Receive FIFO Overflow */
      uint16_t LINEBUSY   :  1;  /**< Line is Busy */
      uint16_t MSTOP      :  1;  /**< STOP Driven by This I2C Master */
      uint16_t MTXUNDR    :  1;  /**< Master Transmit Underflow */
      uint16_t SDAFILT    :  1;  /**< State of SDA Line */
      uint16_t SCLFILT    :  1;  /**< State of SCL Line */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_MSTAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_MSTAT_t__ */

/*@}*/

/** @defgroup MRX Master Receive Data (MRX) Register
 *  Master Receive Data (MRX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_MRX_Struct
 *! \brief  Master Receive Data Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_MRX_t__
typedef struct _ADI_I2C_MRX_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Master Receive Register */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_MRX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_MRX_t__ */

/*@}*/

/** @defgroup MTX Master Transmit Data (MTX) Register
 *  Master Transmit Data (MTX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_MTX_Struct
 *! \brief  Master Transmit Data Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_MTX_t__
typedef struct _ADI_I2C_MTX_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Master Transmit Register */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_MTX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_MTX_t__ */

/*@}*/

/** @defgroup MRXCNT Master Receive Data Count (MRXCNT) Register
 *  Master Receive Data Count (MRXCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_MRXCNT_Struct
 *! \brief  Master Receive Data Count Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_MRXCNT_t__
typedef struct _ADI_I2C_MRXCNT_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Receive Count */
      uint16_t EXTEND     :  1;  /**< Extended Read */
      uint16_t reserved9  :  7;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_MRXCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_MRXCNT_t__ */

/*@}*/

/** @defgroup MCRXCNT Master Current Receive Data Count (MCRXCNT) Register
 *  Master Current Receive Data Count (MCRXCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_MCRXCNT_Struct
 *! \brief  Master Current Receive Data Count Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_MCRXCNT_t__
typedef struct _ADI_I2C_MCRXCNT_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Current Receive Count */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_MCRXCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_MCRXCNT_t__ */

/*@}*/

/** @defgroup ADDR1 Master Address Byte 1 (ADDR1) Register
 *  Master Address Byte 1 (ADDR1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ADDR1_Struct
 *! \brief  Master Address Byte 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ADDR1_t__
typedef struct _ADI_I2C_ADDR1_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Address Byte 1 */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ADDR1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ADDR1_t__ */

/*@}*/

/** @defgroup ADDR2 Master Address Byte 2 (ADDR2) Register
 *  Master Address Byte 2 (ADDR2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ADDR2_Struct
 *! \brief  Master Address Byte 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ADDR2_t__
typedef struct _ADI_I2C_ADDR2_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Address Byte 2 */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ADDR2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ADDR2_t__ */

/*@}*/

/** @defgroup BYT Start Byte (BYT) Register
 *  Start Byte (BYT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_BYT_Struct
 *! \brief  Start Byte Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_BYT_t__
typedef struct _ADI_I2C_BYT_t {
  union {
    struct {
      uint16_t SBYTE      :  8;  /**< Start Byte */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_BYT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_BYT_t__ */

/*@}*/

/** @defgroup DIV Serial Clock Period Divisor (DIV) Register
 *  Serial Clock Period Divisor (DIV) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_DIV_Struct
 *! \brief  Serial Clock Period Divisor Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_DIV_t__
typedef struct _ADI_I2C_DIV_t {
  union {
    struct {
      uint16_t LOW        :  8;  /**< Serial Clock Low Time */
      uint16_t HIGH       :  8;  /**< Serial Clock High Time */
    };
    uint16_t VALUE16;
  };
} ADI_I2C_DIV_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_DIV_t__ */

/*@}*/

/** @defgroup SCTL Slave Control (SCTL) Register
 *  Slave Control (SCTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_SCTL_Struct
 *! \brief  Slave Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_SCTL_t__
typedef struct _ADI_I2C_SCTL_t {
  union {
    struct {
      uint16_t SLVEN      :  1;  /**< Slave Enable */
      uint16_t ADR10EN    :  1;  /**< Enabled 10-bit Addressing */
      uint16_t GCEN       :  1;  /**< General Call Enable */
      uint16_t HGCEN      :  1;  /**< Hardware General Call Enable */
      uint16_t GCSBCLR    :  1;  /**< General Call Status Bit Clear */
      uint16_t EARLYTXR   :  1;  /**< Early Transmit Request Mode */
      uint16_t reserved6  :  1;
      uint16_t NACK       :  1;  /**< NACK Next Communication */
      uint16_t IENSTOP    :  1;  /**< Stop Condition Detected Interrupt Enable */
      uint16_t IENSRX     :  1;  /**< Slave Receive Request Interrupt Enable */
      uint16_t IENSTX     :  1;  /**< Slave Transmit Request Interrupt Enable */
      uint16_t STXDEC     :  1;  /**< Decrement Slave Tx FIFO Status When a Byte is Txed */
      uint16_t IENREPST   :  1;  /**< Repeated Start Interrupt Enable */
      uint16_t SRXDMA     :  1;  /**< Enable Slave Rx DMA Request */
      uint16_t STXDMA     :  1;  /**< Enable Slave Tx DMA Request */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_SCTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_SCTL_t__ */

/*@}*/

/** @defgroup SSTAT Slave I2C Status/Error/IRQ (SSTAT) Register
 *  Slave I2C Status/Error/IRQ (SSTAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_SSTAT_Struct
 *! \brief  Slave I2C Status/Error/IRQ Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_SSTAT_t__
typedef struct _ADI_I2C_SSTAT_t {
  union {
    struct {
      uint16_t STXFSEREQ  :  1;  /**< Slave Tx FIFO Status or Early Request */
      uint16_t STXUNDR    :  1;  /**< Slave Transmit FIFO Underflow */
      uint16_t STXREQ     :  1;  /**< Slave Transmit Request/Slave Transmit Interrupt */
      uint16_t SRXREQ     :  1;  /**< Slave Receive Request */
      uint16_t SRXOVR     :  1;  /**< Slave Receive FIFO Overflow */
      uint16_t NOACK      :  1;  /**< ACK Not Generated by the Slave */
      uint16_t SBUSY      :  1;  /**< Slave Busy */
      uint16_t GCINT      :  1;  /**< General Call Interrupt */
      uint16_t GCID       :  2;  /**< General ID */
      uint16_t STOP       :  1;  /**< Stop After Start and Matching Address */
      uint16_t IDMAT      :  2;  /**< Device ID Matched */
      uint16_t REPSTART   :  1;  /**< Repeated Start and Matching Address */
      uint16_t START      :  1;  /**< Start and Matching Address */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_SSTAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_SSTAT_t__ */

/*@}*/

/** @defgroup SRX Slave Receive (SRX) Register
 *  Slave Receive (SRX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_SRX_Struct
 *! \brief  Slave Receive Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_SRX_t__
typedef struct _ADI_I2C_SRX_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Slave Receive Register */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_SRX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_SRX_t__ */

/*@}*/

/** @defgroup STX Slave Transmit (STX) Register
 *  Slave Transmit (STX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_STX_Struct
 *! \brief  Slave Transmit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_STX_t__
typedef struct _ADI_I2C_STX_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Slave Transmit Register */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_STX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_STX_t__ */

/*@}*/

/** @defgroup ALT Hardware General Call ID (ALT) Register
 *  Hardware General Call ID (ALT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ALT_Struct
 *! \brief  Hardware General Call ID Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ALT_t__
typedef struct _ADI_I2C_ALT_t {
  union {
    struct {
      uint16_t ID         :  8;  /**< Slave Alt */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ALT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ALT_t__ */

/*@}*/

/** @defgroup ID0 First Slave Address Device ID (ID0) Register
 *  First Slave Address Device ID (ID0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ID0_Struct
 *! \brief  First Slave Address Device ID Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ID0_t__
typedef struct _ADI_I2C_ID0_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Slave Device ID 0 */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ID0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ID0_t__ */

/*@}*/

/** @defgroup ID1 Second Slave Address Device ID (ID1) Register
 *  Second Slave Address Device ID (ID1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ID1_Struct
 *! \brief  Second Slave Address Device ID Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ID1_t__
typedef struct _ADI_I2C_ID1_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Slave Device ID 1 */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ID1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ID1_t__ */

/*@}*/

/** @defgroup ID2 Third Slave Address Device ID (ID2) Register
 *  Third Slave Address Device ID (ID2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ID2_Struct
 *! \brief  Third Slave Address Device ID Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ID2_t__
typedef struct _ADI_I2C_ID2_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Slave Device ID 2 */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ID2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ID2_t__ */

/*@}*/

/** @defgroup ID3 Fourth Slave Address Device ID (ID3) Register
 *  Fourth Slave Address Device ID (ID3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ID3_Struct
 *! \brief  Fourth Slave Address Device ID Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ID3_t__
typedef struct _ADI_I2C_ID3_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Slave Device ID 3 */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ID3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ID3_t__ */

/*@}*/

/** @defgroup STAT Master and Slave FIFO Status (STAT) Register
 *  Master and Slave FIFO Status (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_STAT_Struct
 *! \brief  Master and Slave FIFO Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_STAT_t__
typedef struct _ADI_I2C_STAT_t {
  union {
    struct {
      uint16_t STXF       :  2;  /**< Slave Transmit FIFO Status */
      uint16_t SRXF       :  2;  /**< Slave Receive FIFO Status */
      uint16_t MTXF       :  2;  /**< Master Transmit FIFO Status */
      uint16_t MRXF       :  2;  /**< Master Receive FIFO Status */
      uint16_t SFLUSH     :  1;  /**< Flush the Slave Transmit FIFO */
      uint16_t MFLUSH     :  1;  /**< Flush the Master Transmit FIFO */
      uint16_t reserved10 :  6;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_STAT_t__ */

/*@}*/

/** @defgroup SHCTL Shared Control (SHCTL) Register
 *  Shared Control (SHCTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_SHCTL_Struct
 *! \brief  Shared Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_SHCTL_t__
typedef struct _ADI_I2C_SHCTL_t {
  union {
    struct {
      uint16_t RST        :  1;  /**< Reset START STOP Detect Circuit */
      uint16_t reserved1  : 15;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_SHCTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_SHCTL_t__ */

/*@}*/

/** @defgroup TCTL Timing Control Register (TCTL) Register
 *  Timing Control Register (TCTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_TCTL_Struct
 *! \brief  Timing Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_TCTL_t__
typedef struct _ADI_I2C_TCTL_t {
  union {
    struct {
      uint16_t THDATIN    :  5;  /**< Data in Hold Start */
      uint16_t reserved5  :  3;
      uint16_t FILTEROFF  :  1;  /**< Input Filter Control */
      uint16_t reserved9  :  7;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_TCTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_TCTL_t__ */

/*@}*/

/** @defgroup ASTRETCH_SCL Automatic Stretch SCL (ASTRETCH_SCL) Register
 *  Automatic Stretch SCL (ASTRETCH_SCL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ASTRETCH_SCL_Struct
 *! \brief  Automatic Stretch SCL Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ASTRETCH_SCL_t__
typedef struct _ADI_I2C_ASTRETCH_SCL_t {
  union {
    struct {
      uint16_t MST        :  4;  /**< Master Automatic Stretch Mode */
      uint16_t SLV        :  4;  /**< Slave Automatic Stretch Mode */
      uint16_t MSTTMO     :  1;  /**< Master Automatic Stretch Timeout */
      uint16_t SLVTMO     :  1;  /**< Slave Automatic Stretch Timeout */
      uint16_t reserved10 :  6;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ASTRETCH_SCL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ASTRETCH_SCL_t__ */

/*@}*/

/** @defgroup STAT Status (STAT) Register
 *  Status (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_STAT_Struct
 *! \brief  Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_STAT_t__
typedef struct _ADI_SPI_STAT_t {
  union {
    struct {
      uint16_t IRQ        :  1;  /**< SPI Interrupt Status */
      uint16_t XFRDONE    :  1;  /**< SPI Transfer Completion */
      uint16_t TXEMPTY    :  1;  /**< SPI Tx FIFO Empty Interrupt */
      uint16_t TXDONE     :  1;  /**< SPI Tx Done in Read Command Mode */
      uint16_t TXUNDR     :  1;  /**< SPI Tx FIFO Underflow */
      uint16_t TXIRQ      :  1;  /**< SPI Tx IRQ */
      uint16_t RXIRQ      :  1;  /**< SPI Rx IRQ */
      uint16_t RXOVR      :  1;  /**< SPI Rx FIFO Overflow */
      uint16_t reserved8  :  3;
      uint16_t CS         :  1;  /**< CS Status */
      uint16_t CSERR      :  1;  /**< Detected a CS Error Condition in Slave Mode */
      uint16_t CSRISE     :  1;  /**< Detected a Rising Edge on CS, in Slave CON Mode */
      uint16_t CSFALL     :  1;  /**< Detected a Falling Edge on CS, in Slave CON Mode */
      uint16_t RDY        :  1;  /**< Detected an Edge on Ready Indicator for Flow Control */
    };
    uint16_t VALUE16;
  };
} ADI_SPI_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_STAT_t__ */

/*@}*/

/** @defgroup RX Receive (RX) Register
 *  Receive (RX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_RX_Struct
 *! \brief  Receive Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_RX_t__
typedef struct _ADI_SPI_RX_t {
  union {
    struct {
      uint16_t BYTE1      :  8;  /**< 8-bit Receive Buffer */
      uint16_t BYTE2      :  8;  /**< 8-bit Receive Buffer, Used Only in DMA Modes */
    };
    uint16_t VALUE16;
  };
} ADI_SPI_RX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_RX_t__ */

/*@}*/

/** @defgroup TX Transmit (TX) Register
 *  Transmit (TX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_TX_Struct
 *! \brief  Transmit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_TX_t__
typedef struct _ADI_SPI_TX_t {
  union {
    struct {
      uint16_t BYTE1      :  8;  /**< 8-bit Transmit Buffer */
      uint16_t BYTE2      :  8;  /**< 8-bit Transmit Buffer, Used Only in DMA Modes */
    };
    uint16_t VALUE16;
  };
} ADI_SPI_TX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_TX_t__ */

/*@}*/

/** @defgroup DIV SPI Baud Rate Selection (DIV) Register
 *  SPI Baud Rate Selection (DIV) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_DIV_Struct
 *! \brief  SPI Baud Rate Selection Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_DIV_t__
typedef struct _ADI_SPI_DIV_t {
  union {
    struct {
      uint16_t VALUE      :  6;  /**< SPI Clock Divider */
      uint16_t reserved6  : 10;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_DIV_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_DIV_t__ */

/*@}*/

/** @defgroup CTL SPI Configuration (CTL) Register
 *  SPI Configuration (CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_CTL_Struct
 *! \brief  SPI Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_CTL_t__
typedef struct _ADI_SPI_CTL_t {
  union {
    struct {
      uint16_t SPIEN      :  1;  /**< SPI Enable */
      uint16_t MASEN      :  1;  /**< Master Mode Enable */
      uint16_t CPHA       :  1;  /**< Serial Clock Phase Mode */
      uint16_t CPOL       :  1;  /**< Serial Clock Polarity */
      uint16_t WOM        :  1;  /**< SPI Wired-OR Mode */
      uint16_t LSB        :  1;  /**< LSB First Transfer Enable */
      uint16_t TIM        :  1;  /**< SPI Transfer and Interrupt Mode */
      uint16_t ZEN        :  1;  /**< Transmit Zeros Enable */
      uint16_t RXOF       :  1;  /**< Rx Overflow Overwrite Enable */
      uint16_t OEN        :  1;  /**< Slave MISO Output Enable */
      uint16_t LOOPBACK   :  1;  /**< Loopback Enable */
      uint16_t CON        :  1;  /**< Continuous Transfer Enable */
      uint16_t RFLUSH     :  1;  /**< SPI Rx FIFO Flush Enable */
      uint16_t TFLUSH     :  1;  /**< SPI Tx FIFO Flush Enable */
      uint16_t CSRST      :  1;  /**< Reset Mode for CS Error Bit */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_CTL_t__ */

/*@}*/

/** @defgroup IEN SPI Interrupts Enable (IEN) Register
 *  SPI Interrupts Enable (IEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_IEN_Struct
 *! \brief  SPI Interrupts Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_IEN_t__
typedef struct _ADI_SPI_IEN_t {
  union {
    struct {
      uint16_t IRQMODE    :  3;  /**< SPI IRQ Mode Bits */
      uint16_t reserved3  :  5;
      uint16_t CS         :  1;  /**< Enable Interrupt on Every CS Edge in Slave CON Mode */
      uint16_t TXUNDR     :  1;  /**< Tx Underflow Interrupt Enable */
      uint16_t RXOVR      :  1;  /**< Rx Overflow Interrupt Enable */
      uint16_t RDY        :  1;  /**< Ready Signal Edge Interrupt Enable */
      uint16_t TXDONE     :  1;  /**< SPI Transmit Done Interrupt Enable */
      uint16_t XFRDONE    :  1;  /**< SPI Transfer Completion Interrupt Enable */
      uint16_t TXEMPTY    :  1;  /**< Tx FIFO Empty Interrupt Enable */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_IEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_IEN_t__ */

/*@}*/

/** @defgroup CNT Transfer Byte Count (CNT) Register
 *  Transfer Byte Count (CNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_CNT_Struct
 *! \brief  Transfer Byte Count Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_CNT_t__
typedef struct _ADI_SPI_CNT_t {
  union {
    struct {
      uint16_t VALUE      : 14;  /**< Transfer Byte Count */
      uint16_t reserved14 :  1;
      uint16_t FRAMECONT  :  1;  /**< Continue Frame */
    };
    uint16_t VALUE16;
  };
} ADI_SPI_CNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_CNT_t__ */

/*@}*/

/** @defgroup DMA SPI DMA Enable (DMA) Register
 *  SPI DMA Enable (DMA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_DMA_Struct
 *! \brief  SPI DMA Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_DMA_t__
typedef struct _ADI_SPI_DMA_t {
  union {
    struct {
      uint16_t EN         :  1;  /**< Enable DMA for Data Transfer */
      uint16_t TXEN       :  1;  /**< Enable Transmit DMA Request */
      uint16_t RXEN       :  1;  /**< Enable Receive DMA Request */
      uint16_t reserved3  : 13;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_DMA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_DMA_t__ */

/*@}*/

/** @defgroup FIFO_STAT FIFO Status (FIFO_STAT) Register
 *  FIFO Status (FIFO_STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_FIFO_STAT_Struct
 *! \brief  FIFO Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_FIFO_STAT_t__
typedef struct _ADI_SPI_FIFO_STAT_t {
  union {
    struct {
      uint16_t TX         :  4;  /**< SPI Tx FIFO Status */
      uint16_t reserved4  :  4;
      uint16_t RX         :  4;  /**< SPI Rx FIFO Status */
      uint16_t reserved12 :  4;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_FIFO_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_FIFO_STAT_t__ */

/*@}*/

/** @defgroup RD_CTL Read Control (RD_CTL) Register
 *  Read Control (RD_CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_RD_CTL_Struct
 *! \brief  Read Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_RD_CTL_t__
typedef struct _ADI_SPI_RD_CTL_t {
  union {
    struct {
      uint16_t CMDEN      :  1;  /**< Read Command Enable */
      uint16_t OVERLAP    :  1;  /**< Tx/Rx Overlap Mode */
      uint16_t TXBYTES    :  4;  /**< Transmit Byte Count - 1 (Read Command) */
      uint16_t reserved6  :  2;
      uint16_t THREEPIN   :  1;  /**< Three Pin SPI Mode */
      uint16_t reserved9  :  7;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_RD_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_RD_CTL_t__ */

/*@}*/

/** @defgroup FLOW_CTL Flow Control (FLOW_CTL) Register
 *  Flow Control (FLOW_CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_FLOW_CTL_Struct
 *! \brief  Flow Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_FLOW_CTL_t__
typedef struct _ADI_SPI_FLOW_CTL_t {
  union {
    struct {
      uint16_t MODE       :  2;  /**< Flow Control Mode */
      uint16_t reserved2  :  2;
      uint16_t RDYPOL     :  1;  /**< Polarity of RDY/MISO Line */
      uint16_t reserved5  :  1;
      uint16_t RDBURSTSZ  : 10;  /**< Read Data Burst Size - 1 */
    };
    uint16_t VALUE16;
  };
} ADI_SPI_FLOW_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_FLOW_CTL_t__ */

/*@}*/

/** @defgroup WAIT_TMR Wait Timer for Flow Control (WAIT_TMR) Register
 *  Wait Timer for Flow Control (WAIT_TMR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_WAIT_TMR_Struct
 *! \brief  Wait Timer for Flow Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_WAIT_TMR_t__
typedef struct _ADI_SPI_WAIT_TMR_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Wait Timer */
    };
    uint16_t VALUE16;
  };
} ADI_SPI_WAIT_TMR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_WAIT_TMR_t__ */

/*@}*/

/** @defgroup CS_CTL Chip Select Control for Multi-slave Connections (CS_CTL) Register
 *  Chip Select Control for Multi-slave Connections (CS_CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_CS_CTL_Struct
 *! \brief  Chip Select Control for Multi-slave Connections Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_CS_CTL_t__
typedef struct _ADI_SPI_CS_CTL_t {
  union {
    struct {
      uint16_t SEL        :  4;  /**< Chip Select Control */
      uint16_t reserved4  : 12;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_CS_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_CS_CTL_t__ */

/*@}*/

/** @defgroup CS_OVERRIDE Chip Select Override (CS_OVERRIDE) Register
 *  Chip Select Override (CS_OVERRIDE) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_CS_OVERRIDE_Struct
 *! \brief  Chip Select Override Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_CS_OVERRIDE_t__
typedef struct _ADI_SPI_CS_OVERRIDE_t {
  union {
    struct {
      uint16_t CTL        :  2;  /**< CS Override Control */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_CS_OVERRIDE_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_CS_OVERRIDE_t__ */

/*@}*/

/** @defgroup RX Receive Buffer Register (RX) Register
 *  Receive Buffer Register (RX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_RX_Struct
 *! \brief  Receive Buffer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_RX_t__
typedef struct _ADI_UART_RX_t {
  union {
    struct {
      uint16_t RBR        :  8;  /**< Receive Buffer Register */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_RX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_RX_t__ */

/*@}*/

/** @defgroup TX Transmit Holding Register (TX) Register
 *  Transmit Holding Register (TX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_TX_Struct
 *! \brief  Transmit Holding Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_TX_t__
typedef struct _ADI_UART_TX_t {
  union {
    struct {
      uint16_t THR        :  8;  /**< Transmit Holding Register */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_TX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_TX_t__ */

/*@}*/

/** @defgroup IEN Interrupt Enable (IEN) Register
 *  Interrupt Enable (IEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_IEN_Struct
 *! \brief  Interrupt Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_IEN_t__
typedef struct _ADI_UART_IEN_t {
  union {
    struct {
      uint16_t ERBFI      :  1;  /**< Receive Buffer Full Interrupt */
      uint16_t ETBEI      :  1;  /**< Transmit Buffer Empty Interrupt */
      uint16_t ELSI       :  1;  /**< Rx Status Interrupt */
      uint16_t EDSSI      :  1;  /**< Modem Status Interrupt */
      uint16_t EDMAT      :  1;  /**< DMA Requests in Transmit Mode */
      uint16_t EDMAR      :  1;  /**< DMA Requests in Receive Mode */
      uint16_t reserved6  : 10;
    };
    uint16_t VALUE16;
  };
} ADI_UART_IEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_IEN_t__ */

/*@}*/

/** @defgroup IIR Interrupt ID (IIR) Register
 *  Interrupt ID (IIR) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_UART_IIR_STAT
 *! \brief  Interrupt Status (STAT) Enumerations
 *  ========================================================================= */
typedef enum
{
  UART_IIR_STAT_EDSSI = 0,  /**< Modem status interrupt (Read MSR register to clear)                                  */
  UART_IIR_STAT_ETBEI = 1,  /**< Transmit buffer empty interrupt (Write to Tx register or read IIR register to clear) */
  UART_IIR_STAT_ERBFI = 2,  /**< Receive buffer full interrupt (Read Rx register to clear)                            */
  UART_IIR_STAT_RLSI  = 3,  /**< Receive line status interrupt (Read LSR register to clear)                           */
  UART_IIR_STAT_RFTOI = 6   /**< Receive FIFO time-out interrupt (Read Rx register to clear)                          */
} ADI_UART_IIR_STAT;


/* ==========================================================================
 *! \struct ADI_UART_IIR_Struct
 *! \brief  Interrupt ID Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_IIR_t__
typedef struct _ADI_UART_IIR_t {
  union {
    struct {
      uint16_t NIRQ       :  1;  /**< Interrupt Flag */
      uint16_t STAT       :  3;  /**< Interrupt Status */
      uint16_t reserved4  :  2;
      uint16_t FEND       :  2;  /**< FIFO Enabled */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_IIR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_IIR_t__ */

/*@}*/

/** @defgroup LCR Line Control (LCR) Register
 *  Line Control (LCR) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_UART_LCR_SP
 *! \brief  Stick Parity (SP) Enumerations
 *  ========================================================================= */
typedef enum
{
  UART_LCR_PAR_NOTFORCED = 0,  /**< Parity will not be forced based on Parity Select and Parity Enable bits. */
  UART_LCR_PAR_FORCED    = 1   /**< Parity forced based on Parity Select and Parity Enable bits.             */
} ADI_UART_LCR_SP;


/* ==========================================================================
 *! \struct ADI_UART_LCR_Struct
 *! \brief  Line Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_LCR_t__
typedef struct _ADI_UART_LCR_t {
  union {
    struct {
      uint16_t WLS        :  2;  /**< Word Length Select */
      uint16_t STOP       :  1;  /**< Stop Bit */
      uint16_t PEN        :  1;  /**< Parity Enable */
      uint16_t EPS        :  1;  /**< Parity Select */
      uint16_t SP         :  1;  /**< Stick Parity */
      uint16_t BRK        :  1;  /**< Set Break */
      uint16_t reserved7  :  9;
    };
    uint16_t VALUE16;
  };
} ADI_UART_LCR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_LCR_t__ */

/*@}*/

/** @defgroup MCR Modem Control (MCR) Register
 *  Modem Control (MCR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_MCR_Struct
 *! \brief  Modem Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_MCR_t__
typedef struct _ADI_UART_MCR_t {
  union {
    struct {
      uint16_t DTR        :  1;  /**< Data Terminal Ready */
      uint16_t RTS        :  1;  /**< Request to Send */
      uint16_t OUT1       :  1;  /**< Output 1 */
      uint16_t OUT2       :  1;  /**< Output 2 */
      uint16_t LOOPBACK   :  1;  /**< Loopback Mode */
      uint16_t reserved5  : 11;
    };
    uint16_t VALUE16;
  };
} ADI_UART_MCR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_MCR_t__ */

/*@}*/

/** @defgroup LSR Line Status (LSR) Register
 *  Line Status (LSR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_LSR_Struct
 *! \brief  Line Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_LSR_t__
typedef struct _ADI_UART_LSR_t {
  union {
    struct {
      uint16_t DR         :  1;  /**< Data Ready */
      uint16_t OE         :  1;  /**< Overrun Error */
      uint16_t PE         :  1;  /**< Parity Error */
      uint16_t FE         :  1;  /**< Framing Error */
      uint16_t BI         :  1;  /**< Break Indicator */
      uint16_t THRE       :  1;  /**< Transmit Register Empty */
      uint16_t TEMT       :  1;  /**< Transmit and Shift Register Empty Status */
      uint16_t FIFOERR    :  1;  /**< Rx FIFO Parity Error/Frame Error/Break Indication */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_LSR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_LSR_t__ */

/*@}*/

/** @defgroup MSR Modem Status (MSR) Register
 *  Modem Status (MSR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_MSR_Struct
 *! \brief  Modem Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_MSR_t__
typedef struct _ADI_UART_MSR_t {
  union {
    struct {
      uint16_t DCTS       :  1;  /**< Delta CTS */
      uint16_t DDSR       :  1;  /**< Delta DSR */
      uint16_t TERI       :  1;  /**< Trailing Edge RI */
      uint16_t DDCD       :  1;  /**< Delta DCD */
      uint16_t CTS        :  1;  /**< Clear to Send */
      uint16_t DSR        :  1;  /**< Data Set Ready */
      uint16_t RI         :  1;  /**< Ring Indicator */
      uint16_t DCD        :  1;  /**< Data Carrier Detect */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_MSR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_MSR_t__ */

/*@}*/

/** @defgroup SCR Scratch Buffer (SCR) Register
 *  Scratch Buffer (SCR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_SCR_Struct
 *! \brief  Scratch Buffer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_SCR_t__
typedef struct _ADI_UART_SCR_t {
  union {
    struct {
      uint16_t SCR        :  8;  /**< Scratch */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_SCR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_SCR_t__ */

/*@}*/

/** @defgroup FCR FIFO Control (FCR) Register
 *  FIFO Control (FCR) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_UART_FCR_FDMAMD
 *! \brief  FIFO DMA Mode (FDMAMD) Enumerations
 *  ========================================================================= */
typedef enum
{
  UART_FCR_MODE0 = 0,  /**< In DMA mode 0, RX DMA request will be asserted whenever there's data in RBR or RX FIFO and de-assert whenever RBR or RX FIFO is empty; TX DMA request will be asserted whenever THR or TX FIFO is empty and de-assert whenever data written to.                              */
  UART_FCR_MODE1 = 1   /**< in DMA mode 1, RX DMA request will be asserted whenever RX FIFO trig level or time out reached and de-assert thereafter when RX FIFO is empty; TX DMA request will be asserted whenever TX FIFO is empty and de-assert thereafter when TX FIFO is completely filled up full. */
} ADI_UART_FCR_FDMAMD;


/* ==========================================================================
 *! \struct ADI_UART_FCR_Struct
 *! \brief  FIFO Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_FCR_t__
typedef struct _ADI_UART_FCR_t {
  union {
    struct {
      uint16_t FIFOEN     :  1;  /**< FIFO Enable as to Work in 16550 Mode */
      uint16_t RFCLR      :  1;  /**< Clear Rx FIFO */
      uint16_t TFCLR      :  1;  /**< Clear Tx FIFO */
      uint16_t FDMAMD     :  1;  /**< FIFO DMA Mode */
      uint16_t reserved4  :  2;
      uint16_t RFTRIG     :  2;  /**< Rx FIFO Trigger Level */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_FCR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_FCR_t__ */

/*@}*/

/** @defgroup FBR Fractional Baud Rate (FBR) Register
 *  Fractional Baud Rate (FBR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_FBR_Struct
 *! \brief  Fractional Baud Rate Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_FBR_t__
typedef struct _ADI_UART_FBR_t {
  union {
    struct {
      uint16_t DIVN       : 11;  /**< Fractional Baud Rate N Divide Bits 0 to 2047 */
      uint16_t DIVM       :  2;  /**< Fractional Baud Rate M Divide Bits 1 to 3 */
      uint16_t reserved13 :  2;
      uint16_t FBEN       :  1;  /**< Fractional Baud Rate Generator Enable */
    };
    uint16_t VALUE16;
  };
} ADI_UART_FBR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_FBR_t__ */

/*@}*/

/** @defgroup DIV Baud Rate Divider (DIV) Register
 *  Baud Rate Divider (DIV) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_DIV_Struct
 *! \brief  Baud Rate Divider Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_DIV_t__
typedef struct _ADI_UART_DIV_t {
  union {
    struct {
      uint16_t DIV        : 16;  /**< Baud Rate Divider */
    };
    uint16_t VALUE16;
  };
} ADI_UART_DIV_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_DIV_t__ */

/*@}*/

/** @defgroup LCR2 Second Line Control (LCR2) Register
 *  Second Line Control (LCR2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_LCR2_Struct
 *! \brief  Second Line Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_LCR2_t__
typedef struct _ADI_UART_LCR2_t {
  union {
    struct {
      uint16_t OSR        :  2;  /**< Over Sample Rate */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_UART_LCR2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_LCR2_t__ */

/*@}*/

/** @defgroup CTL UART Control Register (CTL) Register
 *  UART Control Register (CTL) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_UART_CTL_RXINV
 *! \brief  Invert Receiver Line (RXINV) Enumerations
 *  ========================================================================= */
typedef enum
{
  UART_CTL_NOTINV_RX = 0,  /**< Don't invert receiver line (idling high). */
  UART_CTL_INV_RX    = 1   /**< Invert receiver line (idling low).        */
} ADI_UART_CTL_RXINV;


/* ==========================================================================
 *! \struct ADI_UART_CTL_Struct
 *! \brief  UART Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_CTL_t__
typedef struct _ADI_UART_CTL_t {
  union {
    struct {
      uint16_t reserved0  :  1;
      uint16_t FORCECLK   :  1;  /**< Force UCLK on */
      uint16_t reserved2  :  2;
      uint16_t RXINV      :  1;  /**< Invert Receiver Line */
      uint16_t reserved5  :  3;
      uint16_t REV        :  8;  /**< UART Revision ID */
    };
    uint16_t VALUE16;
  };
} ADI_UART_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_CTL_t__ */

/*@}*/

/** @defgroup RFC RX FIFO Byte Count (RFC) Register
 *  RX FIFO Byte Count (RFC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_RFC_Struct
 *! \brief  RX FIFO Byte Count Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_RFC_t__
typedef struct _ADI_UART_RFC_t {
  union {
    struct {
      uint16_t RFC        :  5;  /**< Current Rx FIFO Data Bytes */
      uint16_t reserved5  : 11;
    };
    uint16_t VALUE16;
  };
} ADI_UART_RFC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_RFC_t__ */

/*@}*/

/** @defgroup TFC TX FIFO Byte Count (TFC) Register
 *  TX FIFO Byte Count (TFC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_TFC_Struct
 *! \brief  TX FIFO Byte Count Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_TFC_t__
typedef struct _ADI_UART_TFC_t {
  union {
    struct {
      uint16_t TFC        :  5;  /**< Current Tx FIFO Data Bytes */
      uint16_t reserved5  : 11;
    };
    uint16_t VALUE16;
  };
} ADI_UART_TFC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_TFC_t__ */

/*@}*/

/** @defgroup RSC RS485 Half-duplex Control (RSC) Register
 *  RS485 Half-duplex Control (RSC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_RSC_Struct
 *! \brief  RS485 Half-duplex Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_RSC_t__
typedef struct _ADI_UART_RSC_t {
  union {
    struct {
      uint16_t OENP       :  1;  /**< SOUT_EN Polarity */
      uint16_t OENSP      :  1;  /**< SOUT_EN De-assert Before Full Stop Bit(s) */
      uint16_t DISRX      :  1;  /**< Disable Rx When Transmitting */
      uint16_t DISTX      :  1;  /**< Hold off Tx When Receiving */
      uint16_t reserved4  : 12;
    };
    uint16_t VALUE16;
  };
} ADI_UART_RSC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_RSC_t__ */

/*@}*/

/** @defgroup ACR Auto Baud Control (ACR) Register
 *  Auto Baud Control (ACR) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_UART_ACR_ABE
 *! \brief  Auto Baud Enable (ABE) Enumerations
 *  ========================================================================= */
typedef enum
{
  UART_ACR_DIS_AUTOBAUD = 0,  /**< Disable auto baudrate */
  UART_ACR_EN_AUTOBAUD  = 1   /**< Enable auto baudrate  */
} ADI_UART_ACR_ABE;


/*  =========================================================================
 *! \enum   ADI_UART_ACR_DNIEN
 *! \brief  Enable Done Interrupt (DNIEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  UART_ACR_DIS_DONEINT = 0,  /**< Disable done interrupt */
  UART_ACR_EN_DONEINT  = 1   /**< Enable done interrupt  */
} ADI_UART_ACR_DNIEN;


/*  =========================================================================
 *! \enum   ADI_UART_ACR_TOIEN
 *! \brief  Enable Time-out Interrupt (TOIEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  UART_ACR_DIS_TIMEOUTINT = 0,  /**< Disable timeout interrupt */
  UART_ACR_EN_TIMEOUTINT  = 1   /**< Enable timeout interrupt  */
} ADI_UART_ACR_TOIEN;


/*  =========================================================================
 *! \enum   ADI_UART_ACR_SEC
 *! \brief  Starting Edge Count (SEC) Enumerations
 *  ========================================================================= */
typedef enum
{
  UART_ACR_SEC_EDGE1 = 0,  /**< First edge   */
  UART_ACR_SEC_EDGE2 = 1,  /**< Second edge  */
  UART_ACR_SEC_EDGE3 = 2,  /**< Third edge   */
  UART_ACR_SEC_EDGE4 = 3,  /**< Fourth edge  */
  UART_ACR_SEC_EDGE5 = 4,  /**< Fifth edge   */
  UART_ACR_SEC_EDGE6 = 5,  /**< Sixth edge   */
  UART_ACR_SEC_EDGE7 = 6,  /**< Seventh edge */
  UART_ACR_SEC_EDGE8 = 7   /**< Eighth edge  */
} ADI_UART_ACR_SEC;


/*  =========================================================================
 *! \enum   ADI_UART_ACR_EEC
 *! \brief  Ending Edge Count (EEC) Enumerations
 *  ========================================================================= */
typedef enum
{
  UART_ACR_EEC_EDGE1 = 0,  /**< First edge   */
  UART_ACR_EEC_EDGE2 = 1,  /**< Second edge  */
  UART_ACR_EEC_EDGE3 = 2,  /**< Third edge   */
  UART_ACR_EEC_EDGE4 = 3,  /**< Fourth edge  */
  UART_ACR_EEC_EDGE5 = 4,  /**< Fifth edge   */
  UART_ACR_EEC_EDGE6 = 5,  /**< Sixth edge   */
  UART_ACR_EEC_EDGE7 = 6,  /**< Seventh edge */
  UART_ACR_EEC_EDGE8 = 7,  /**< Eighth edge  */
  UART_ACR_EEC_EDGE9 = 8   /**< Ninth edge   */
} ADI_UART_ACR_EEC;


/* ==========================================================================
 *! \struct ADI_UART_ACR_Struct
 *! \brief  Auto Baud Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_ACR_t__
typedef struct _ADI_UART_ACR_t {
  union {
    struct {
      uint16_t ABE        :  1;  /**< Auto Baud Enable */
      uint16_t DNIEN      :  1;  /**< Enable Done Interrupt */
      uint16_t TOIEN      :  1;  /**< Enable Time-out Interrupt */
      uint16_t reserved3  :  1;
      uint16_t SEC        :  3;  /**< Starting Edge Count */
      uint16_t reserved7  :  1;
      uint16_t EEC        :  4;  /**< Ending Edge Count */
      uint16_t reserved12 :  4;
    };
    uint16_t VALUE16;
  };
} ADI_UART_ACR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_ACR_t__ */

/*@}*/

/** @defgroup ASRL Auto Baud Status (Low) (ASRL) Register
 *  Auto Baud Status (Low) (ASRL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_ASRL_Struct
 *! \brief  Auto Baud Status (Low) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_ASRL_t__
typedef struct _ADI_UART_ASRL_t {
  union {
    struct {
      uint16_t DONE       :  1;  /**< Auto Baud Done Successfully */
      uint16_t BRKTO      :  1;  /**< Timed Out Due to Long Time Break Condition */
      uint16_t NSETO      :  1;  /**< Timed Out Due to No Valid Start Edge Found */
      uint16_t NEETO      :  1;  /**< Timed Out Due to No Valid Ending Edge Found */
      uint16_t CNT        : 12;  /**< CNT[11:0] Auto Baud Counter Value */
    };
    uint16_t VALUE16;
  };
} ADI_UART_ASRL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_ASRL_t__ */

/*@}*/

/** @defgroup ASRH Auto Baud Status (High) (ASRH) Register
 *  Auto Baud Status (High) (ASRH) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_ASRH_Struct
 *! \brief  Auto Baud Status (High) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_ASRH_t__
typedef struct _ADI_UART_ASRH_t {
  union {
    struct {
      uint16_t CNT        :  8;  /**< CNT[19:12] Auto Baud Counter Value */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_ASRH_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_ASRH_t__ */

/*@}*/

/** @defgroup CFG Beeper Configuration (CFG) Register
 *  Beeper Configuration (CFG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_BEEP_CFG_Struct
 *! \brief  Beeper Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_BEEP_CFG_t__
typedef struct _ADI_BEEP_CFG_t {
  union {
    struct {
      uint16_t SEQREPEAT  :  8;  /**< Beeper Sequence Repeat Value */
      uint16_t EN         :  1;  /**< Beeper Enable */
      uint16_t reserved9  :  1;
      uint16_t ASTARTIRQ  :  1;  /**< Tone A Start IRQ */
      uint16_t AENDIRQ    :  1;  /**< Tone A End IRQ */
      uint16_t BSTARTIRQ  :  1;  /**< Tone B Start IRQ */
      uint16_t BENDIRQ    :  1;  /**< Tone B End IRQ */
      uint16_t SEQNEARENDIRQ :  1;  /**< Sequence 1 Cycle from End IRQ */
      uint16_t SEQATENDIRQ   :  1;  /**< Sequence End IRQ */
    };
    uint16_t VALUE16;
  };
} ADI_BEEP_CFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_BEEP_CFG_t__ */

/*@}*/

/** @defgroup STAT Beeper Status (STAT) Register
 *  Beeper Status (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_BEEP_STAT_Struct
 *! \brief  Beeper Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_BEEP_STAT_t__
typedef struct _ADI_BEEP_STAT_t {
  union {
    struct {
      uint16_t SEQREMAIN  :  8;  /**< Remaining Tone-pair Iterations to Play in Sequence Mode */
      uint16_t BUSY       :  1;  /**< Beeper is Busy */
      uint16_t reserved9  :  1;
      uint16_t ASTARTED   :  1;  /**< Tone A Has Started */
      uint16_t AENDED     :  1;  /**< Tone A Has Ended */
      uint16_t BSTARTED   :  1;  /**< Tone B Has Started */
      uint16_t BENDED     :  1;  /**< Tone B Has Ended */
      uint16_t SEQNEAREND :  1;  /**< Sequencer Last Tone-pair Has Started */
      uint16_t SEQENDED   :  1;  /**< Sequencer Has Ended */
    };
    uint16_t VALUE16;
  };
} ADI_BEEP_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_BEEP_STAT_t__ */

/*@}*/

/** @defgroup TONEA Tone A Data (TONEA) Register
 *  Tone A Data (TONEA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_BEEP_TONEA_Struct
 *! \brief  Tone A Data Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_BEEP_TONEA_t__
typedef struct _ADI_BEEP_TONEA_t {
  union {
    struct {
      uint16_t DUR        :  8;  /**< Tone Duration */
      uint16_t FREQ       :  7;  /**< Tone Frequency */
      uint16_t DIS        :  1;  /**< Output Disable */
    };
    uint16_t VALUE16;
  };
} ADI_BEEP_TONEA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_BEEP_TONEA_t__ */

/*@}*/

/** @defgroup TONEB Tone B Data (TONEB) Register
 *  Tone B Data (TONEB) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_BEEP_TONEB_Struct
 *! \brief  Tone B Data Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_BEEP_TONEB_t__
typedef struct _ADI_BEEP_TONEB_t {
  union {
    struct {
      uint16_t DUR        :  8;  /**< Tone Duration */
      uint16_t FREQ       :  7;  /**< Tone Frequency */
      uint16_t DIS        :  1;  /**< Output Disable */
    };
    uint16_t VALUE16;
  };
} ADI_BEEP_TONEB_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_BEEP_TONEB_t__ */

/*@}*/

/** @defgroup CFG ADC Configuration (CFG) Register
 *  ADC Configuration (CFG) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_ADC_CFG_VREFSEL
 *! \brief  To select Vref as 1.25 V or 2.5 V (VREFSEL) Enumerations
 *  ========================================================================= */
typedef enum
{
  ADC_CFG_V_2P5  = 0,  /**< Vref = 2.5 V  */
  ADC_CFG_V_1P25 = 1   /**< Vref = 1.25 V */
} ADI_ADC_CFG_VREFSEL;


/*  =========================================================================
 *! \enum   ADI_ADC_CFG_REFBUFEN
 *! \brief  To enable internal reference buffer (REFBUFEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  ADC_CFG_EXT_REF = 0,  /**< External reference is used  */
  ADC_CFG_BUF_REF = 1   /**< Reference buffer is enabled */
} ADI_ADC_CFG_REFBUFEN;


/* ==========================================================================
 *! \struct ADI_ADC_CFG_Struct
 *! \brief  ADC Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_CFG_t__
typedef struct _ADI_ADC_CFG_t {
  union {
    struct {
      uint16_t PWRUP      :  1;  /**< Powering up ADC */
      uint16_t VREFSEL    :  1;  /**< To select Vref as 1.25 V or 2.5 V */
      uint16_t REFBUFEN   :  1;  /**< To enable internal reference buffer */
      uint16_t VREFVBAT   :  1;  /**< VRef VBAT */
      uint16_t EN         :  1;  /**< To enable ADC subsystem */
      uint16_t STARTCAL   :  1;  /**< To start a new offset calibration cycle */
      uint16_t RST        :  1;  /**< Resets internal buffers and registers when high */
      uint16_t SINKEN     :  1;  /**< To enable additional 50 uA sink current capability @1.25 V, 100 uA current capability @2.5 V */
      uint16_t TMPEN      :  1;  /**< To power up temperature sensor */
      uint16_t FAST_DISCH :  1;  /**< For fast switchover of Vref from 2.5 V to 1.25 V */
      uint16_t VREFVBAT_DEL :  1;  /**< VRef VBAT delayed */
      uint16_t reserved11   :  5;
    };
    uint16_t VALUE16;
  };
} ADI_ADC_CFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_CFG_t__ */

/*@}*/

/** @defgroup PWRUP ADC Power-up Time (PWRUP) Register
 *  ADC Power-up Time (PWRUP) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_PWRUP_Struct
 *! \brief  ADC Power-up Time Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_PWRUP_t__
typedef struct _ADI_ADC_PWRUP_t {
  union {
    struct {
      uint16_t WAIT       : 11;  /**< Program this count to generate 20us wait time with respect to the PCLK frequency */
      uint16_t reserved11 :  5;
    };
    uint16_t VALUE16;
  };
} ADI_ADC_PWRUP_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_PWRUP_t__ */

/*@}*/

/** @defgroup CAL_WORD Calibration Word (CAL_WORD) Register
 *  Calibration Word (CAL_WORD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_CAL_WORD_Struct
 *! \brief  Calibration Word Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_CAL_WORD_t__
typedef struct _ADI_ADC_CAL_WORD_t {
  union {
    struct {
      uint16_t VALUE      :  7;  /**< Offset calibration word */
      uint16_t reserved7  :  9;
    };
    uint16_t VALUE16;
  };
} ADI_ADC_CAL_WORD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_CAL_WORD_t__ */

/*@}*/

/** @defgroup CNV_CFG ADC Conversion Configuration (CNV_CFG) Register
 *  ADC Conversion Configuration (CNV_CFG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_CNV_CFG_Struct
 *! \brief  ADC Conversion Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_CNV_CFG_t__
typedef struct _ADI_ADC_CNV_CFG_t {
  union {
    struct {
      uint16_t SEL        :  8;  /**< To select channel(s) to convert */
      uint16_t BAT        :  1;  /**< Enable Battery Monitoring */
      uint16_t TMP        :  1;  /**< To select temperature measurement 1 */
      uint16_t TMP2       :  1;  /**< To select temperature measurement 2 */
      uint16_t reserved11 :  1;
      uint16_t AUTOMODE   :  1;  /**< Enable Auto Mode */
      uint16_t DMAEN      :  1;  /**< Enable DMA Channel */
      uint16_t SINGLE     :  1;  /**< Set to start single conversion */
      uint16_t MULTI      :  1;  /**< Set to start multiple conversions */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_CNV_CFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_CNV_CFG_t__ */

/*@}*/

/** @defgroup CNV_TIME ADC Conversion Time (CNV_TIME) Register
 *  ADC Conversion Time (CNV_TIME) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_CNV_TIME_Struct
 *! \brief  ADC Conversion Time Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_CNV_TIME_t__
typedef struct _ADI_ADC_CNV_TIME_t {
  union {
    struct {
      uint16_t SAMPTIME   :  8;  /**< Number of clock cycles (ACLK) required for sampling */
      uint16_t DLY        :  8;  /**< Delay between two consecutive conversions in terms of number of ACLK cycles */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_CNV_TIME_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_CNV_TIME_t__ */

/*@}*/

/** @defgroup AVG_CFG Averaging Configuration (AVG_CFG) Register
 *  Averaging Configuration (AVG_CFG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_AVG_CFG_Struct
 *! \brief  Averaging Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_AVG_CFG_t__
typedef struct _ADI_ADC_AVG_CFG_t {
  union {
    struct {
      uint16_t FACTOR     :  8;  /**< Program averaging factor for averaging enabled channels (1-256) */
      uint16_t reserved8  :  6;
      uint16_t OS         :  1;  /**< Enable oversampling */
      uint16_t EN         :  1;  /**< To enable averaging on Channels enabled in enable register */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_AVG_CFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_AVG_CFG_t__ */

/*@}*/

/** @defgroup IRQ_EN Interrupt Enable (IRQ_EN) Register
 *  Interrupt Enable (IRQ_EN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_IRQ_EN_Struct
 *! \brief  Interrupt Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_IRQ_EN_t__
typedef struct _ADI_ADC_IRQ_EN_t {
  union {
    struct {
      uint16_t CNVDONE    :  1;  /**< Set it to enable interrupt after conversion is done */
      uint16_t reserved1  :  9;
      uint16_t CALDONE    :  1;  /**< Set it to enable interrupt for calibration done */
      uint16_t OVF        :  1;  /**< Set to enable interrupt in case of overflow */
      uint16_t ALERT      :  1;  /**< Enable Interrupt on Crossing Lower or Higher Limit */
      uint16_t RDY        :  1;  /**< Set to enable interrupt when ADC is ready to convert */
      uint16_t reserved14 :  2;
    };
    uint16_t VALUE16;
  };
} ADI_ADC_IRQ_EN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_IRQ_EN_t__ */

/*@}*/

/** @defgroup STAT ADC Status (STAT) Register
 *  ADC Status (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_STAT_Struct
 *! \brief  ADC Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_STAT_t__
typedef struct _ADI_ADC_STAT_t {
  union {
    struct {
      uint16_t DONE0      :  1;  /**< Indicates conversion done on Channel 0 */
      uint16_t DONE1      :  1;  /**< Indicates conversion done on Channel 1 */
      uint16_t DONE2      :  1;  /**< Indicates conversion done on Channel 2 */
      uint16_t DONE3      :  1;  /**< Indicates conversion done on Channel 3 */
      uint16_t DONE4      :  1;  /**< Indicates conversion done on Channel 4 */
      uint16_t DONE5      :  1;  /**< Indicates conversion done on Channel 5 */
      uint16_t DONE6      :  1;  /**< Indicates conversion done on Channel 6 */
      uint16_t DONE7      :  1;  /**< Indicates conversion done on Channel 7 */
      uint16_t BATDONE    :  1;  /**< Indicates conversion done for battery monitoring */
      uint16_t TMPDONE    :  1;  /**< Indicates conversion is done for temperature sensing */
      uint16_t TMP2DONE   :  1;  /**< Indicates conversion is done for temperature sensing 2 */
      uint16_t reserved11 :  3;
      uint16_t CALDONE    :  1;  /**< Indicates calibration is done */
      uint16_t RDY        :  1;  /**< Indicates ADC is ready to start converting, when using external reference buffer */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_STAT_t__ */

/*@}*/

/** @defgroup OVF Overflow of Output Registers (OVF) Register
 *  Overflow of Output Registers (OVF) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_OVF_Struct
 *! \brief  Overflow of Output Registers Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_OVF_t__
typedef struct _ADI_ADC_OVF_t {
  union {
    struct {
      uint16_t CH0        :  1;  /**< Indicates overflow in channel 0 output register */
      uint16_t CH1        :  1;  /**< Indicates overflow in channel 1 output register */
      uint16_t CH2        :  1;  /**< Indicates overflow in channel 2 output register */
      uint16_t CH3        :  1;  /**< Indicates overflow in channel 3 output register */
      uint16_t CH4        :  1;  /**< Indicates overflow in channel 4 output register */
      uint16_t CH5        :  1;  /**< Indicates overflow in channel 5 output register */
      uint16_t CH6        :  1;  /**< Indicates overflow in channel 6 output register */
      uint16_t CH7        :  1;  /**< Indicates overflow in channel 7 output register */
      uint16_t BAT        :  1;  /**< Indicates overflow in battery monitoring output register */
      uint16_t TMP        :  1;  /**< Indicates overflow in temperature output register */
      uint16_t TMP2       :  1;  /**< Indicates overflow in temperature 2 output register */
      uint16_t reserved11 :  5;
    };
    uint16_t VALUE16;
  };
} ADI_ADC_OVF_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_OVF_t__ */

/*@}*/

/** @defgroup ALERT Alert Indication (ALERT) Register
 *  Alert Indication (ALERT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_ALERT_Struct
 *! \brief  Alert Indication Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_ALERT_t__
typedef struct _ADI_ADC_ALERT_t {
  union {
    struct {
      uint16_t HI0        :  1;  /**< Channel 0 High alert status */
      uint16_t LO0        :  1;  /**< Channel 0 Low alert status */
      uint16_t HI1        :  1;  /**< Channel 1 High alert status */
      uint16_t LO1        :  1;  /**< Channel 1 Low alert status */
      uint16_t HI2        :  1;  /**< Channel 2 High alert status */
      uint16_t LO2        :  1;  /**< Channel 2 Low alert status */
      uint16_t HI3        :  1;  /**< Channel 3 High alert status */
      uint16_t LO3        :  1;  /**< Channel 3 Low alert status */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_ADC_ALERT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_ALERT_t__ */

/*@}*/

/** @defgroup CH0_OUT Conversion Result Channel 0 (CH0_OUT) Register
 *  Conversion Result Channel 0 (CH0_OUT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_CH0_OUT_Struct
 *! \brief  Conversion Result Channel 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_CH0_OUT_t__
typedef struct _ADI_ADC_CH0_OUT_t {
  union {
    struct {
      uint16_t RESULT     : 16;  /**< Conversion result of channel 0 is stored here */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_CH0_OUT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_CH0_OUT_t__ */

/*@}*/

/** @defgroup CH1_OUT Conversion Result Channel 1 (CH1_OUT) Register
 *  Conversion Result Channel 1 (CH1_OUT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_CH1_OUT_Struct
 *! \brief  Conversion Result Channel 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_CH1_OUT_t__
typedef struct _ADI_ADC_CH1_OUT_t {
  union {
    struct {
      uint16_t RESULT     : 16;  /**< Conversion result of channel 1 is stored here */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_CH1_OUT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_CH1_OUT_t__ */

/*@}*/

/** @defgroup CH2_OUT Conversion Result Channel 2 (CH2_OUT) Register
 *  Conversion Result Channel 2 (CH2_OUT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_CH2_OUT_Struct
 *! \brief  Conversion Result Channel 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_CH2_OUT_t__
typedef struct _ADI_ADC_CH2_OUT_t {
  union {
    struct {
      uint16_t RESULT     : 16;  /**< Conversion result of channel 2 is stored here */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_CH2_OUT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_CH2_OUT_t__ */

/*@}*/

/** @defgroup CH3_OUT Conversion Result Channel 3 (CH3_OUT) Register
 *  Conversion Result Channel 3 (CH3_OUT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_CH3_OUT_Struct
 *! \brief  Conversion Result Channel 3 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_CH3_OUT_t__
typedef struct _ADI_ADC_CH3_OUT_t {
  union {
    struct {
      uint16_t RESULT     : 16;  /**< Conversion result of channel 3 is stored here */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_CH3_OUT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_CH3_OUT_t__ */

/*@}*/

/** @defgroup CH4_OUT Conversion Result Channel 4 (CH4_OUT) Register
 *  Conversion Result Channel 4 (CH4_OUT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_CH4_OUT_Struct
 *! \brief  Conversion Result Channel 4 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_CH4_OUT_t__
typedef struct _ADI_ADC_CH4_OUT_t {
  union {
    struct {
      uint16_t RESULT     : 16;  /**< Conversion result of channel 4 is stored here */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_CH4_OUT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_CH4_OUT_t__ */

/*@}*/

/** @defgroup CH5_OUT Conversion Result Channel 5 (CH5_OUT) Register
 *  Conversion Result Channel 5 (CH5_OUT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_CH5_OUT_Struct
 *! \brief  Conversion Result Channel 5 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_CH5_OUT_t__
typedef struct _ADI_ADC_CH5_OUT_t {
  union {
    struct {
      uint16_t RESULT     : 16;  /**< Conversion result of channel 5 is stored here */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_CH5_OUT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_CH5_OUT_t__ */

/*@}*/

/** @defgroup CH6_OUT Conversion Result Channel 6 (CH6_OUT) Register
 *  Conversion Result Channel 6 (CH6_OUT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_CH6_OUT_Struct
 *! \brief  Conversion Result Channel 6 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_CH6_OUT_t__
typedef struct _ADI_ADC_CH6_OUT_t {
  union {
    struct {
      uint16_t RESULT     : 16;  /**< Conversion result of channel 6 is stored here */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_CH6_OUT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_CH6_OUT_t__ */

/*@}*/

/** @defgroup CH7_OUT Conversion Result Channel 7 (CH7_OUT) Register
 *  Conversion Result Channel 7 (CH7_OUT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_CH7_OUT_Struct
 *! \brief  Conversion Result Channel 7 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_CH7_OUT_t__
typedef struct _ADI_ADC_CH7_OUT_t {
  union {
    struct {
      uint16_t RESULT     : 16;  /**< Conversion result of channel 7 is stored here */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_CH7_OUT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_CH7_OUT_t__ */

/*@}*/

/** @defgroup BAT_OUT Battery Monitoring Result (BAT_OUT) Register
 *  Battery Monitoring Result (BAT_OUT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_BAT_OUT_Struct
 *! \brief  Battery Monitoring Result Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_BAT_OUT_t__
typedef struct _ADI_ADC_BAT_OUT_t {
  union {
    struct {
      uint16_t RESULT     : 16;  /**< Conversion result of battery monitoring is stored here */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_BAT_OUT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_BAT_OUT_t__ */

/*@}*/

/** @defgroup TMP_OUT Temperature Result (TMP_OUT) Register
 *  Temperature Result (TMP_OUT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_TMP_OUT_Struct
 *! \brief  Temperature Result Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_TMP_OUT_t__
typedef struct _ADI_ADC_TMP_OUT_t {
  union {
    struct {
      uint16_t RESULT     : 16;  /**< Conversion result of Temperature measurement 1 is stored here */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_TMP_OUT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_TMP_OUT_t__ */

/*@}*/

/** @defgroup TMP2_OUT Temperature Result 2 (TMP2_OUT) Register
 *  Temperature Result 2 (TMP2_OUT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_TMP2_OUT_Struct
 *! \brief  Temperature Result 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_TMP2_OUT_t__
typedef struct _ADI_ADC_TMP2_OUT_t {
  union {
    struct {
      uint16_t RESULT     : 16;  /**< Conversion result of Temperature measurement 2 is stored here */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_TMP2_OUT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_TMP2_OUT_t__ */

/*@}*/

/** @defgroup DMA_OUT DMA Output Register (DMA_OUT) Register
 *  DMA Output Register (DMA_OUT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_DMA_OUT_Struct
 *! \brief  DMA Output Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_DMA_OUT_t__
typedef struct _ADI_ADC_DMA_OUT_t {
  union {
    struct {
      uint16_t RESULT     : 16;  /**< Register to store conversion result for DMA */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_DMA_OUT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_DMA_OUT_t__ */

/*@}*/

/** @defgroup LIM0_LO Channel 0 Low Limit (LIM0_LO) Register
 *  Channel 0 Low Limit (LIM0_LO) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_LIM0_LO_Struct
 *! \brief  Channel 0 Low Limit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_LIM0_LO_t__
typedef struct _ADI_ADC_LIM0_LO_t {
  union {
    struct {
      uint16_t VALUE      : 12;  /**< Low limit value for channel 0 */
      uint16_t reserved12 :  3;
      uint16_t EN         :  1;  /**< To enable low limit comparison on Channel 0 */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_LIM0_LO_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_LIM0_LO_t__ */

/*@}*/

/** @defgroup LIM0_HI Channel 0 High Limit (LIM0_HI) Register
 *  Channel 0 High Limit (LIM0_HI) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_LIM0_HI_Struct
 *! \brief  Channel 0 High Limit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_LIM0_HI_t__
typedef struct _ADI_ADC_LIM0_HI_t {
  union {
    struct {
      uint16_t VALUE      : 12;  /**< High limit value for channel 0 */
      uint16_t reserved12 :  3;
      uint16_t EN         :  1;  /**< To enable high limit comparison on Channel 0 */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_LIM0_HI_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_LIM0_HI_t__ */

/*@}*/

/** @defgroup HYS0 Channel 0 Hysteresis (HYS0) Register
 *  Channel 0 Hysteresis (HYS0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_HYS0_Struct
 *! \brief  Channel 0 Hysteresis Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_HYS0_t__
typedef struct _ADI_ADC_HYS0_t {
  union {
    struct {
      uint16_t VALUE      :  9;  /**< Hysteresis value for Channel 0 */
      uint16_t reserved9  :  3;
      uint16_t MONCYC     :  3;  /**< Program number of conversion cycles to monitor channel 0 before raising alert */
      uint16_t EN         :  1;  /**< To enable hysteresis for comparison on Channel 0 */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_HYS0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_HYS0_t__ */

/*@}*/

/** @defgroup LIM1_LO Channel 1 Low Limit (LIM1_LO) Register
 *  Channel 1 Low Limit (LIM1_LO) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_LIM1_LO_Struct
 *! \brief  Channel 1 Low Limit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_LIM1_LO_t__
typedef struct _ADI_ADC_LIM1_LO_t {
  union {
    struct {
      uint16_t VALUE      : 12;  /**< Low limit value for channel 1 */
      uint16_t reserved12 :  3;
      uint16_t EN         :  1;  /**< To enable low limit comparison on Channel 1 */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_LIM1_LO_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_LIM1_LO_t__ */

/*@}*/

/** @defgroup LIM1_HI Channel 1 High Limit (LIM1_HI) Register
 *  Channel 1 High Limit (LIM1_HI) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_LIM1_HI_Struct
 *! \brief  Channel 1 High Limit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_LIM1_HI_t__
typedef struct _ADI_ADC_LIM1_HI_t {
  union {
    struct {
      uint16_t VALUE      : 12;  /**< High limit value for channel 1 */
      uint16_t reserved12 :  3;
      uint16_t EN         :  1;  /**< To enable high limit comparison on Channel 1 */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_LIM1_HI_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_LIM1_HI_t__ */

/*@}*/

/** @defgroup HYS1 Channel 1 Hysteresis (HYS1) Register
 *  Channel 1 Hysteresis (HYS1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_HYS1_Struct
 *! \brief  Channel 1 Hysteresis Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_HYS1_t__
typedef struct _ADI_ADC_HYS1_t {
  union {
    struct {
      uint16_t VALUE      :  9;  /**< Hysteresis value for Channel 1 */
      uint16_t reserved9  :  3;
      uint16_t MONCYC     :  3;  /**< Program number of conversion cycles to monitor channel 1 before raising alert */
      uint16_t EN         :  1;  /**< To enable hysteresis for comparison on Channel 1 */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_HYS1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_HYS1_t__ */

/*@}*/

/** @defgroup LIM2_LO Channel 2 Low Limit (LIM2_LO) Register
 *  Channel 2 Low Limit (LIM2_LO) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_LIM2_LO_Struct
 *! \brief  Channel 2 Low Limit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_LIM2_LO_t__
typedef struct _ADI_ADC_LIM2_LO_t {
  union {
    struct {
      uint16_t VALUE      : 12;  /**< Low limit value for channel 2 */
      uint16_t reserved12 :  3;
      uint16_t EN         :  1;  /**< To enable low limit comparison on Channel 2 */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_LIM2_LO_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_LIM2_LO_t__ */

/*@}*/

/** @defgroup LIM2_HI Channel 2 High Limit (LIM2_HI) Register
 *  Channel 2 High Limit (LIM2_HI) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_LIM2_HI_Struct
 *! \brief  Channel 2 High Limit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_LIM2_HI_t__
typedef struct _ADI_ADC_LIM2_HI_t {
  union {
    struct {
      uint16_t VALUE      : 12;  /**< High limit value for channel 2 */
      uint16_t reserved12 :  3;
      uint16_t EN         :  1;  /**< To enable high limit comparison on Channel 2 */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_LIM2_HI_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_LIM2_HI_t__ */

/*@}*/

/** @defgroup HYS2 Channel 2 Hysteresis (HYS2) Register
 *  Channel 2 Hysteresis (HYS2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_HYS2_Struct
 *! \brief  Channel 2 Hysteresis Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_HYS2_t__
typedef struct _ADI_ADC_HYS2_t {
  union {
    struct {
      uint16_t VALUE      :  9;  /**< Hysteresis value for Channel 2 */
      uint16_t reserved9  :  3;
      uint16_t MONCYC     :  3;  /**< Program number of conversion cycles to monitor channel 2 before raising alert */
      uint16_t EN         :  1;  /**< To enable hysteresis for comparison on Channel 2 */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_HYS2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_HYS2_t__ */

/*@}*/

/** @defgroup LIM3_LO Channel 3 Low Limit (LIM3_LO) Register
 *  Channel 3 Low Limit (LIM3_LO) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_LIM3_LO_Struct
 *! \brief  Channel 3 Low Limit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_LIM3_LO_t__
typedef struct _ADI_ADC_LIM3_LO_t {
  union {
    struct {
      uint16_t VALUE      : 12;  /**< Low limit value for channel 3 */
      uint16_t reserved12 :  3;
      uint16_t EN         :  1;  /**< To enable low limit comparison on Channel 3 */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_LIM3_LO_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_LIM3_LO_t__ */

/*@}*/

/** @defgroup LIM3_HI Channel 3 High Limit (LIM3_HI) Register
 *  Channel 3 High Limit (LIM3_HI) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_LIM3_HI_Struct
 *! \brief  Channel 3 High Limit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_LIM3_HI_t__
typedef struct _ADI_ADC_LIM3_HI_t {
  union {
    struct {
      uint16_t VALUE      : 12;  /**< High limit value for channel 3 */
      uint16_t reserved12 :  3;
      uint16_t EN         :  1;  /**< To enable high limit comparison on Channel 3 */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_LIM3_HI_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_LIM3_HI_t__ */

/*@}*/

/** @defgroup HYS3 Channel 3 Hysteresis (HYS3) Register
 *  Channel 3 Hysteresis (HYS3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_HYS3_Struct
 *! \brief  Channel 3 Hysteresis Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_HYS3_t__
typedef struct _ADI_ADC_HYS3_t {
  union {
    struct {
      uint16_t VALUE      :  9;  /**< Hysteresis value for Channel 3 */
      uint16_t reserved9  :  3;
      uint16_t MONCYC     :  3;  /**< Program number of conversion cycles to monitor channel 3 before raising alert */
      uint16_t EN         :  1;  /**< To enable hysteresis for comparison on Channel 3 */
    };
    uint16_t VALUE16;
  };
} ADI_ADC_HYS3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_HYS3_t__ */

/*@}*/

/** @defgroup CFG1 Reference Buffer Low Power Mode (CFG1) Register
 *  Reference Buffer Low Power Mode (CFG1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ADC_CFG1_Struct
 *! \brief  Reference Buffer Low Power Mode Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ADC_CFG1_t__
typedef struct _ADI_ADC_CFG1_t {
  union {
    struct {
      uint16_t RBUFLP     :  1;  /**< Enable low power mode for reference buffer */
      uint16_t reserved1  : 15;
    };
    uint16_t VALUE16;
  };
} ADI_ADC_CFG1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ADC_CFG1_t__ */

/*@}*/

/** @defgroup STAT DMA Status (STAT) Register
 *  DMA Status (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_STAT_Struct
 *! \brief  DMA Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_STAT_t__
typedef struct _ADI_DMA_STAT_t {
  union {
    struct {
      uint32_t MEN        :  1;  /**< Enable Status of the Controller */
      uint32_t reserved1  : 15;
      uint32_t CHANM1     :  5;  /**< Number of Available DMA Channels Minus 1 */
      uint32_t reserved21 : 11;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_STAT_t__ */

/*@}*/

/** @defgroup CFG DMA Configuration (CFG) Register
 *  DMA Configuration (CFG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_CFG_Struct
 *! \brief  DMA Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_CFG_t__
typedef struct _ADI_DMA_CFG_t {
  union {
    struct {
      uint32_t MEN        :  1;  /**< Controller Enable */
      uint32_t reserved1  : 31;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_CFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_CFG_t__ */

/*@}*/

/** @defgroup PDBPTR DMA Channel Primary Control Database Pointer (PDBPTR) Register
 *  DMA Channel Primary Control Database Pointer (PDBPTR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_PDBPTR_Struct
 *! \brief  DMA Channel Primary Control Database Pointer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_PDBPTR_t__
typedef struct _ADI_DMA_PDBPTR_t {
  union {
    struct {
      uint32_t ADDR       : 32;  /**< Pointer to the Base Address of the Primary Data Structure */
    };
    uint32_t VALUE32;
  };
} ADI_DMA_PDBPTR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_PDBPTR_t__ */

/*@}*/

/** @defgroup ADBPTR DMA Channel Alternate Control Database Pointer (ADBPTR) Register
 *  DMA Channel Alternate Control Database Pointer (ADBPTR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_ADBPTR_Struct
 *! \brief  DMA Channel Alternate Control Database Pointer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_ADBPTR_t__
typedef struct _ADI_DMA_ADBPTR_t {
  union {
    struct {
      uint32_t ADDR       : 32;  /**< Base Address of the Alternate Data Structure */
    };
    uint32_t VALUE32;
  };
} ADI_DMA_ADBPTR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_ADBPTR_t__ */

/*@}*/

/** @defgroup SWREQ DMA Channel Software Request (SWREQ) Register
 *  DMA Channel Software Request (SWREQ) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_SWREQ_Struct
 *! \brief  DMA Channel Software Request Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_SWREQ_t__
typedef struct _ADI_DMA_SWREQ_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Generate Software Request */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_SWREQ_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_SWREQ_t__ */

/*@}*/

/** @defgroup RMSK_SET DMA Channel Request Mask Set (RMSK_SET) Register
 *  DMA Channel Request Mask Set (RMSK_SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_RMSK_SET_Struct
 *! \brief  DMA Channel Request Mask Set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_RMSK_SET_t__
typedef struct _ADI_DMA_RMSK_SET_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Mask Requests from DMA Channels */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_RMSK_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_RMSK_SET_t__ */

/*@}*/

/** @defgroup RMSK_CLR DMA Channel Request Mask Clear (RMSK_CLR) Register
 *  DMA Channel Request Mask Clear (RMSK_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_RMSK_CLR_Struct
 *! \brief  DMA Channel Request Mask Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_RMSK_CLR_t__
typedef struct _ADI_DMA_RMSK_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Clear Request Mask Set Bits */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_RMSK_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_RMSK_CLR_t__ */

/*@}*/

/** @defgroup EN_SET DMA Channel Enable Set (EN_SET) Register
 *  DMA Channel Enable Set (EN_SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_EN_SET_Struct
 *! \brief  DMA Channel Enable Set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_EN_SET_t__
typedef struct _ADI_DMA_EN_SET_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Enable DMA Channels */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_EN_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_EN_SET_t__ */

/*@}*/

/** @defgroup EN_CLR DMA Channel Enable Clear (EN_CLR) Register
 *  DMA Channel Enable Clear (EN_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_EN_CLR_Struct
 *! \brief  DMA Channel Enable Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_EN_CLR_t__
typedef struct _ADI_DMA_EN_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Disable DMA Channels */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_EN_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_EN_CLR_t__ */

/*@}*/

/** @defgroup ALT_SET DMA Channel Primary Alternate Set (ALT_SET) Register
 *  DMA Channel Primary Alternate Set (ALT_SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_ALT_SET_Struct
 *! \brief  DMA Channel Primary Alternate Set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_ALT_SET_t__
typedef struct _ADI_DMA_ALT_SET_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Control Structure Status / Select Alternate Structure */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_ALT_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_ALT_SET_t__ */

/*@}*/

/** @defgroup ALT_CLR DMA Channel Primary Alternate Clear (ALT_CLR) Register
 *  DMA Channel Primary Alternate Clear (ALT_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_ALT_CLR_Struct
 *! \brief  DMA Channel Primary Alternate Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_ALT_CLR_t__
typedef struct _ADI_DMA_ALT_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Select Primary Data Structure */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_ALT_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_ALT_CLR_t__ */

/*@}*/

/** @defgroup PRI_SET DMA Channel Priority Set (PRI_SET) Register
 *  DMA Channel Priority Set (PRI_SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_PRI_SET_Struct
 *! \brief  DMA Channel Priority Set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_PRI_SET_t__
typedef struct _ADI_DMA_PRI_SET_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Configure Channel for High Priority */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_PRI_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_PRI_SET_t__ */

/*@}*/

/** @defgroup PRI_CLR DMA Channel Priority Clear (PRI_CLR) Register
 *  DMA Channel Priority Clear (PRI_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_PRI_CLR_Struct
 *! \brief  DMA Channel Priority Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_PRI_CLR_t__
typedef struct _ADI_DMA_PRI_CLR_t {
  union {
    struct {
      uint32_t CHPRICLR   : 27;  /**< Configure Channel for Default Priority Level */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_PRI_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_PRI_CLR_t__ */

/*@}*/

/** @defgroup ERRCHNL_CLR DMA per Channel Error Clear (ERRCHNL_CLR) Register
 *  DMA per Channel Error Clear (ERRCHNL_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_ERRCHNL_CLR_Struct
 *! \brief  DMA per Channel Error Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_ERRCHNL_CLR_t__
typedef struct _ADI_DMA_ERRCHNL_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Per Channel Bus Error Status/Clear */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_ERRCHNL_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_ERRCHNL_CLR_t__ */

/*@}*/

/** @defgroup ERR_CLR DMA Bus Error Clear (ERR_CLR) Register
 *  DMA Bus Error Clear (ERR_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_ERR_CLR_Struct
 *! \brief  DMA Bus Error Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_ERR_CLR_t__
typedef struct _ADI_DMA_ERR_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Bus Error Status */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_ERR_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_ERR_CLR_t__ */

/*@}*/

/** @defgroup INVALIDDESC_CLR DMA per Channel Invalid Descriptor Clear (INVALIDDESC_CLR) Register
 *  DMA per Channel Invalid Descriptor Clear (INVALIDDESC_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_INVALIDDESC_CLR_Struct
 *! \brief  DMA per Channel Invalid Descriptor Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_INVALIDDESC_CLR_t__
typedef struct _ADI_DMA_INVALIDDESC_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Per Channel Invalid Descriptor Status/Clear */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_INVALIDDESC_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_INVALIDDESC_CLR_t__ */

/*@}*/

/** @defgroup BS_SET DMA Channel Bytes Swap Enable Set (BS_SET) Register
 *  DMA Channel Bytes Swap Enable Set (BS_SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_BS_SET_Struct
 *! \brief  DMA Channel Bytes Swap Enable Set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_BS_SET_t__
typedef struct _ADI_DMA_BS_SET_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Byte Swap Status */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_BS_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_BS_SET_t__ */

/*@}*/

/** @defgroup BS_CLR DMA Channel Bytes Swap Enable Clear (BS_CLR) Register
 *  DMA Channel Bytes Swap Enable Clear (BS_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_BS_CLR_Struct
 *! \brief  DMA Channel Bytes Swap Enable Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_BS_CLR_t__
typedef struct _ADI_DMA_BS_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Disable Byte Swap */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_BS_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_BS_CLR_t__ */

/*@}*/

/** @defgroup SRCADDR_SET DMA Channel Source Address Decrement Enable Set (SRCADDR_SET) Register
 *  DMA Channel Source Address Decrement Enable Set (SRCADDR_SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_SRCADDR_SET_Struct
 *! \brief  DMA Channel Source Address Decrement Enable Set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_SRCADDR_SET_t__
typedef struct _ADI_DMA_SRCADDR_SET_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Source Address Decrement Status */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_SRCADDR_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_SRCADDR_SET_t__ */

/*@}*/

/** @defgroup SRCADDR_CLR DMA Channel Source Address Decrement Enable Clear (SRCADDR_CLR) Register
 *  DMA Channel Source Address Decrement Enable Clear (SRCADDR_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_SRCADDR_CLR_Struct
 *! \brief  DMA Channel Source Address Decrement Enable Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_SRCADDR_CLR_t__
typedef struct _ADI_DMA_SRCADDR_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Disable Source Address Decrement */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_SRCADDR_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_SRCADDR_CLR_t__ */

/*@}*/

/** @defgroup DSTADDR_SET DMA Channel Destination Address Decrement Enable Set (DSTADDR_SET) Register
 *  DMA Channel Destination Address Decrement Enable Set (DSTADDR_SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_DSTADDR_SET_Struct
 *! \brief  DMA Channel Destination Address Decrement Enable Set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_DSTADDR_SET_t__
typedef struct _ADI_DMA_DSTADDR_SET_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Destination Address Decrement Status */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_DSTADDR_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_DSTADDR_SET_t__ */

/*@}*/

/** @defgroup DSTADDR_CLR DMA Channel Destination Address Decrement Enable Clear (DSTADDR_CLR) Register
 *  DMA Channel Destination Address Decrement Enable Clear (DSTADDR_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_DSTADDR_CLR_Struct
 *! \brief  DMA Channel Destination Address Decrement Enable Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_DSTADDR_CLR_t__
typedef struct _ADI_DMA_DSTADDR_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 27;  /**< Disable Destination Address Decrement */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_DSTADDR_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_DSTADDR_CLR_t__ */

/*@}*/

/** @defgroup REVID DMA Controller Revision ID (REVID) Register
 *  DMA Controller Revision ID (REVID) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_REVID_Struct
 *! \brief  DMA Controller Revision ID Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_REVID_t__
typedef struct _ADI_DMA_REVID_t {
  union {
    struct {
      uint32_t VALUE      :  8;  /**< DMA Controller Revision ID */
      uint32_t reserved8  : 24;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_REVID_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_REVID_t__ */

/*@}*/

/** @defgroup STAT Status (STAT) Register
 *  Status (STAT) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_FLCC_STAT_ACCESS_MODE
 *! \brief  Access Mode (ACCESS_MODE) Enumerations
 *  ========================================================================= */
typedef enum
{
  FLCC_STAT_DIRECT   = 0,  /**< Flash controller is currently in Direct Access mode; user access to all registers is enabled                                                                                                                                                                                                                                         */
  FLCC_STAT_INDIRECT = 1   /**< Flash Controller is currently in Indirect Access mode; user access to registers is limited to read-only access of the status register. Full register access will be restored when the Cryptographic module releases control of the flash controller (crypto completes the ongoing operation within the protected key storage region) */
} ADI_FLCC_STAT_ACCESS_MODE;


/* ==========================================================================
 *! \struct ADI_FLCC_STAT_Struct
 *! \brief  Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_STAT_t__
typedef struct _ADI_FLCC_STAT_t {
  union {
    struct {
      uint32_t CMDBUSY    :  1;  /**< Command busy */
      uint32_t WRCLOSE    :  1;  /**< WRITE registers are closed */
      uint32_t CMDCOMP    :  1;  /**< Command complete */
      uint32_t WRALCOMP   :  1;  /**< Write almost complete */
      uint32_t CMDFAIL    :  2;  /**< Provides information on command failures */
      uint32_t SLEEPING   :  1;  /**< Flash array is in low power (sleep) mode */
      uint32_t ECCERRCMD  :  2;  /**< ECC errors detected during user issued SIGN command */
      uint32_t ECCRDERR   :  2;  /**< ECC IRQ cause */
      uint32_t OVERLAP    :  1;  /**< Overlapping Command */
      uint32_t reserved12 :  1;
      uint32_t SIGNERR    :  1;  /**< Signature check failure during initialization */
      uint32_t INIT       :  1;  /**< Flash controller initialization in progress */
      uint32_t ECCINFOSIGN :  2;  /**< ECC status of flash initialization */
      uint32_t ECCERRCNT   :  3;  /**< ECC correction counter */
      uint32_t reserved20  :  5;
      uint32_t ECCICODE    :  2;  /**< ICode AHB Bus Error ECC status */
      uint32_t ECCDCODE    :  2;  /**< DCode AHB Bus Error ECC status */
      uint32_t CACHESRAMPERR :  1;  /**< SRAM parity errors in Cache Controller */
      uint32_t reserved30    :  1;
      uint32_t ACCESS_MODE   :  1;  /**< Access Mode */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_STAT_t__ */

/*@}*/

/** @defgroup IEN Interrupt Enable (IEN) Register
 *  Interrupt Enable (IEN) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_FLCC_IEN_ECC_CORRECT
 *! \brief  Control whether to generate bus errors, interrupts, or neither in response to 1-bit ECC Correction events (ECC_CORRECT) Enumerations
 *  ========================================================================= */
typedef enum
{
  FLCC_IEN_NONE_COR    = 0,  /**< Do not generate a response to ECC events      */
  FLCC_IEN_BUS_ERR_COR = 1,  /**< Generate Bus Errors in response to ECC events */
  FLCC_IEN_IRQ_COR     = 2   /**< Generate IRQs in response to ECC events       */
} ADI_FLCC_IEN_ECC_CORRECT;


/*  =========================================================================
 *! \enum   ADI_FLCC_IEN_ECC_ERROR
 *! \brief  Control whether to generate bus errors, interrupts, or neither in response to 2-bit ECC Error events (ECC_ERROR) Enumerations
 *  ========================================================================= */
typedef enum
{
  FLCC_IEN_NONE_ERR    = 0,  /**< Do not generate a response to ECC events      */
  FLCC_IEN_BUS_ERR_ERR = 1,  /**< Generate Bus Errors in response to ECC events */
  FLCC_IEN_IRQ_ERR     = 2   /**< Generate IRQs in response to ECC events       */
} ADI_FLCC_IEN_ECC_ERROR;


/* ==========================================================================
 *! \struct ADI_FLCC_IEN_Struct
 *! \brief  Interrupt Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_IEN_t__
typedef struct _ADI_FLCC_IEN_t {
  union {
    struct {
      uint32_t CMDCMPLT   :  1;  /**< Command complete interrupt enable */
      uint32_t WRALCMPLT  :  1;  /**< Write almost complete interrupt enable */
      uint32_t CMDFAIL    :  1;  /**< Command fail interrupt enable */
      uint32_t reserved3   :  1;
      uint32_t ECC_CORRECT :  2;  /**< Control whether to generate bus errors, interrupts, or neither in response to 1-bit ECC Correction events */
      uint32_t ECC_ERROR   :  2;  /**< Control whether to generate bus errors, interrupts, or neither in response to 2-bit ECC Error events */
      uint32_t reserved8   : 24;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_IEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_IEN_t__ */

/*@}*/

/** @defgroup CMD Command (CMD) Register
 *  Command (CMD) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_FLCC_CMD_VALUE
 *! \brief  Commands (VALUE) Enumerations
 *  ========================================================================= */
typedef enum
{
  FLCC_CMD_IDLE        = 0,  /**< IDLE                                                                  */
  FLCC_CMD_ABORT       = 1,  /**< ABORT                                                                 */
  FLCC_CMD_SLEEP       = 2,  /**< Requests flash to enter Sleep mode                                    */
  FLCC_CMD_SIGN        = 3,  /**< SIGN                                                                  */
  FLCC_CMD_WRITE       = 4,  /**< WRITE                                                                 */
  FLCC_CMD_BLANK_CHECK = 5,  /**< Checks all of User Space; fails if any bits in user space are cleared */
  FLCC_CMD_ERASEPAGE   = 6,  /**< ERASEPAGE                                                             */
  FLCC_CMD_MASSERASE   = 7   /**< MASSERASE                                                             */
} ADI_FLCC_CMD_VALUE;


/* ==========================================================================
 *! \struct ADI_FLCC_CMD_Struct
 *! \brief  Command Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_CMD_t__
typedef struct _ADI_FLCC_CMD_t {
  union {
    struct {
      uint32_t VALUE      :  4;  /**< Commands */
      uint32_t reserved4  : 28;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_CMD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_CMD_t__ */

/*@}*/

/** @defgroup KH_ADDR Write Address (KH_ADDR) Register
 *  Write Address (KH_ADDR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_KH_ADDR_Struct
 *! \brief  Write Address Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_KH_ADDR_t__
typedef struct _ADI_FLCC_KH_ADDR_t {
  union {
    struct {
      uint32_t reserved0  :  3;
      uint32_t VALUE      : 17;  /**< Address to be written on a WRITE command */
      uint32_t reserved20 : 12;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_KH_ADDR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_KH_ADDR_t__ */

/*@}*/

/** @defgroup KH_DATA0 Write Lower Data (KH_DATA0) Register
 *  Write Lower Data (KH_DATA0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_KH_DATA0_Struct
 *! \brief  Write Lower Data Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_KH_DATA0_t__
typedef struct _ADI_FLCC_KH_DATA0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Lower half of 64-bit dual word data to be written on a Write command */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_KH_DATA0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_KH_DATA0_t__ */

/*@}*/

/** @defgroup KH_DATA1 Write Upper Data (KH_DATA1) Register
 *  Write Upper Data (KH_DATA1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_KH_DATA1_Struct
 *! \brief  Write Upper Data Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_KH_DATA1_t__
typedef struct _ADI_FLCC_KH_DATA1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Upper half of 64-bit dual word data to be written on a Write command */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_KH_DATA1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_KH_DATA1_t__ */

/*@}*/

/** @defgroup PAGE_ADDR0 Lower Page Address (PAGE_ADDR0) Register
 *  Lower Page Address (PAGE_ADDR0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_PAGE_ADDR0_Struct
 *! \brief  Lower Page Address Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_PAGE_ADDR0_t__
typedef struct _ADI_FLCC_PAGE_ADDR0_t {
  union {
    struct {
      uint32_t reserved0  : 10;
      uint32_t VALUE      : 10;  /**< Lower address bits of the page address */
      uint32_t reserved20 : 12;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_PAGE_ADDR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_PAGE_ADDR0_t__ */

/*@}*/

/** @defgroup PAGE_ADDR1 Upper Page Address (PAGE_ADDR1) Register
 *  Upper Page Address (PAGE_ADDR1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_PAGE_ADDR1_Struct
 *! \brief  Upper Page Address Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_PAGE_ADDR1_t__
typedef struct _ADI_FLCC_PAGE_ADDR1_t {
  union {
    struct {
      uint32_t reserved0  : 10;
      uint32_t VALUE      : 10;  /**< Upper address bits of the page address */
      uint32_t reserved20 : 12;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_PAGE_ADDR1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_PAGE_ADDR1_t__ */

/*@}*/

/** @defgroup KEY Key (KEY) Register
 *  Key (KEY) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_FLCC_KEY_VALUE
 *! \brief  Key register (VALUE) Enumerations
 *  ========================================================================= */
typedef enum
{
  FLCC_KEY_USERKEY = 1735161189   /**< USERKEY */
} ADI_FLCC_KEY_VALUE;


/* ==========================================================================
 *! \struct ADI_FLCC_KEY_Struct
 *! \brief  Key Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_KEY_t__
typedef struct _ADI_FLCC_KEY_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key register */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_KEY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_KEY_t__ */

/*@}*/

/** @defgroup WR_ABORT_ADDR Write Abort Address (WR_ABORT_ADDR) Register
 *  Write Abort Address (WR_ABORT_ADDR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_WR_ABORT_ADDR_Struct
 *! \brief  Write Abort Address Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_WR_ABORT_ADDR_t__
typedef struct _ADI_FLCC_WR_ABORT_ADDR_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Address of recently aborted write command */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_WR_ABORT_ADDR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_WR_ABORT_ADDR_t__ */

/*@}*/

/** @defgroup WRPROT Write Protection (WRPROT) Register
 *  Write Protection (WRPROT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_WRPROT_Struct
 *! \brief  Write Protection Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_WRPROT_t__
typedef struct _ADI_FLCC_WRPROT_t {
  union {
    struct {
      uint32_t WORD       : 32;  /**< Clear bits to write protect related groups of user space pages */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_WRPROT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_WRPROT_t__ */

/*@}*/

/** @defgroup SIGNATURE Signature (SIGNATURE) Register
 *  Signature (SIGNATURE) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_SIGNATURE_Struct
 *! \brief  Signature Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_SIGNATURE_t__
typedef struct _ADI_FLCC_SIGNATURE_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Read signature */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_SIGNATURE_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_SIGNATURE_t__ */

/*@}*/

/** @defgroup UCFG User Configuration (UCFG) Register
 *  User Configuration (UCFG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_UCFG_Struct
 *! \brief  User Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_UCFG_t__
typedef struct _ADI_FLCC_UCFG_t {
  union {
    struct {
      uint32_t KHDMAEN    :  1;  /**< Key hole DMA enable */
      uint32_t AUTOINCEN  :  1;  /**< Auto Address Increment for Key Hole Access */
      uint32_t reserved2  : 30;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_UCFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_UCFG_t__ */

/*@}*/

/** @defgroup TIME_PARAM0 Time Parameter 0 (TIME_PARAM0) Register
 *  Time Parameter 0 (TIME_PARAM0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_TIME_PARAM0_Struct
 *! \brief  Time Parameter 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_TIME_PARAM0_t__
typedef struct _ADI_FLCC_TIME_PARAM0_t {
  union {
    struct {
      uint32_t DIVREFCLK  :  1;  /**< Divide Reference Clock (by 2) */
      uint32_t reserved1  :  3;
      uint32_t TNVS       :  4;  /**< PROG/ERASE to NVSTR setup time */
      uint32_t TPGS       :  4;  /**< NVSTR to Program setup time */
      uint32_t TPROG      :  4;  /**< Program time */
      uint32_t TNVH       :  4;  /**< NVSTR Hold time */
      uint32_t TRCV       :  4;  /**< Recovery time */
      uint32_t TERASE     :  4;  /**< Erase Time */
      uint32_t TNVH1      :  4;  /**< NVSTR Hold time during Mass Erase */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_TIME_PARAM0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_TIME_PARAM0_t__ */

/*@}*/

/** @defgroup TIME_PARAM1 Time Parameter 1 (TIME_PARAM1) Register
 *  Time Parameter 1 (TIME_PARAM1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_TIME_PARAM1_Struct
 *! \brief  Time Parameter 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_TIME_PARAM1_t__
typedef struct _ADI_FLCC_TIME_PARAM1_t {
  union {
    struct {
      uint32_t TWK        :  4;  /**< Wake up time */
      uint32_t WAITSTATES :  3;  /**< Number of wait states to access flash */
      uint32_t reserved7     :  1;
      uint32_t CURWAITSTATES :  3;  /**< Current wait states [2:0] */
      uint32_t reserved11    : 21;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_TIME_PARAM1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_TIME_PARAM1_t__ */

/*@}*/

/** @defgroup ABORT_EN_LO IRQ Abort Enable (Lower Bits) (ABORT_EN_LO) Register
 *  IRQ Abort Enable (Lower Bits) (ABORT_EN_LO) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_ABORT_EN_LO_Struct
 *! \brief  IRQ Abort Enable (Lower Bits) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_ABORT_EN_LO_t__
typedef struct _ADI_FLCC_ABORT_EN_LO_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< VALUE[31:0] Sys IRQ Abort Enable */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_ABORT_EN_LO_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_ABORT_EN_LO_t__ */

/*@}*/

/** @defgroup ABORT_EN_HI IRQ Abort Enable (Upper Bits) (ABORT_EN_HI) Register
 *  IRQ Abort Enable (Upper Bits) (ABORT_EN_HI) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_ABORT_EN_HI_Struct
 *! \brief  IRQ Abort Enable (Upper Bits) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_ABORT_EN_HI_t__
typedef struct _ADI_FLCC_ABORT_EN_HI_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< VALUE[63:32] Sys IRQ Abort Enable */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_ABORT_EN_HI_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_ABORT_EN_HI_t__ */

/*@}*/

/** @defgroup ECC_CFG ECC Configuration (ECC_CFG) Register
 *  ECC Configuration (ECC_CFG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_ECC_CFG_Struct
 *! \brief  ECC Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_ECC_CFG_t__
typedef struct _ADI_FLCC_ECC_CFG_t {
  union {
    struct {
      uint32_t EN         :  1;  /**< ECC Enable */
      uint32_t INFOEN     :  1;  /**< Info space ECC Enable bit */
      uint32_t reserved2  :  6;
      uint32_t PTR        : 24;  /**< ECC start page pointer */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_ECC_CFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_ECC_CFG_t__ */

/*@}*/

/** @defgroup ECC_ADDR ECC Status (Address) (ECC_ADDR) Register
 *  ECC Status (Address) (ECC_ADDR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_ECC_ADDR_Struct
 *! \brief  ECC Status (Address) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_ECC_ADDR_t__
typedef struct _ADI_FLCC_ECC_ADDR_t {
  union {
    struct {
      uint32_t VALUE      : 20;  /**< This register has the address for which ECC error is detected */
      uint32_t reserved20 : 12;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_ECC_ADDR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_ECC_ADDR_t__ */

/*@}*/

/** @defgroup POR_SEC Flash Security (POR_SEC) Register
 *  Flash Security (POR_SEC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_POR_SEC_Struct
 *! \brief  Flash Security Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_POR_SEC_t__
typedef struct _ADI_FLCC_POR_SEC_t {
  union {
    struct {
      uint32_t SECURE     :  1;  /**< Set this bit to prevent read or write access to User Space (sticky when set) */
      uint32_t reserved1  : 31;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_POR_SEC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_POR_SEC_t__ */

/*@}*/

/** @defgroup VOL_CFG Volatile Flash Configuration (VOL_CFG) Register
 *  Volatile Flash Configuration (VOL_CFG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_VOL_CFG_Struct
 *! \brief  Volatile Flash Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_VOL_CFG_t__
typedef struct _ADI_FLCC_VOL_CFG_t {
  union {
    struct {
      uint32_t INFO_REMAP :  1;  /**< Alias the info space to the base address of user space */
      uint32_t reserved1  : 31;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_VOL_CFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_VOL_CFG_t__ */

/*@}*/

/** @defgroup STAT Cache Status Register (STAT) Register
 *  Cache Status Register (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_CACHE_STAT_Struct
 *! \brief  Cache Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_CACHE_STAT_t__
typedef struct _ADI_FLCC_CACHE_STAT_t {
  union {
    struct {
      uint32_t ICEN       :  1;  /**< If this bit is set,  I-Cache is enabled */
      uint32_t reserved1  : 31;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_CACHE_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_CACHE_STAT_t__ */

/*@}*/

/** @defgroup SETUP Cache Setup Register (SETUP) Register
 *  Cache Setup Register (SETUP) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_CACHE_SETUP_Struct
 *! \brief  Cache Setup Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_CACHE_SETUP_t__
typedef struct _ADI_FLCC_CACHE_SETUP_t {
  union {
    struct {
      uint32_t ICEN       :  1;  /**< If this bit set, I-Cache is enabled for AHB accesses */
      uint32_t LCKIC      :  1;  /**< If this bit is set, I-Cache contents are locked */
      uint32_t reserved2  : 30;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_CACHE_SETUP_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_CACHE_SETUP_t__ */

/*@}*/

/** @defgroup KEY Cache Key Register (KEY) Register
 *  Cache Key Register (KEY) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_CACHE_KEY_Struct
 *! \brief  Cache Key Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_CACHE_KEY_t__
typedef struct _ADI_FLCC_CACHE_KEY_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Cache Key */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_CACHE_KEY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_CACHE_KEY_t__ */

/*@}*/

/** @defgroup CFG Port  Configuration (CFG) Register
 *  Port  Configuration (CFG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_CFG_Struct
 *! \brief  Port  Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_CFG_t__
typedef struct _ADI_GPIO_CFG_t {
  union {
    struct {
      uint32_t PIN00      :  2;  /**< Pin 0 configuration bits */
      uint32_t PIN01      :  2;  /**< Pin 1 configuration bits */
      uint32_t PIN02      :  2;  /**< Pin 2 configuration bits */
      uint32_t PIN03      :  2;  /**< Pin 3 configuration bits */
      uint32_t PIN04      :  2;  /**< Pin 4 configuration bits */
      uint32_t PIN05      :  2;  /**< Pin 5 configuration bits */
      uint32_t PIN06      :  2;  /**< Pin 6 configuration bits */
      uint32_t PIN07      :  2;  /**< Pin 7 configuration bits */
      uint32_t PIN08      :  2;  /**< Pin 8 configuration bits */
      uint32_t PIN09      :  2;  /**< Pin 9 configuration bits */
      uint32_t PIN10      :  2;  /**< Pin 10  configuration bits */
      uint32_t PIN11      :  2;  /**< Pin 11  configuration bits */
      uint32_t PIN12      :  2;  /**< Pin 12  configuration bits */
      uint32_t PIN13      :  2;  /**< Pin 13  configuration bits */
      uint32_t PIN14      :  2;  /**< Pin 14  configuration bits */
      uint32_t PIN15      :  2;  /**< Pin 15  configuration bits */
    };
    uint32_t VALUE32;
  };
} ADI_GPIO_CFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_CFG_t__ */

/*@}*/

/** @defgroup OEN Port Output Enable (OEN) Register
 *  Port Output Enable (OEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_OEN_Struct
 *! \brief  Port Output Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_OEN_t__
typedef struct _ADI_GPIO_OEN_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Pin Output Drive enable */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_OEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_OEN_t__ */

/*@}*/

/** @defgroup PE Port Output Pull-up/Pull-down Enable (PE) Register
 *  Port Output Pull-up/Pull-down Enable (PE) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_PE_Struct
 *! \brief  Port Output Pull-up/Pull-down Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_PE_t__
typedef struct _ADI_GPIO_PE_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Pin Pull enable */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_PE_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_PE_t__ */

/*@}*/

/** @defgroup IEN Port  Input Path Enable (IEN) Register
 *  Port  Input Path Enable (IEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_IEN_Struct
 *! \brief  Port  Input Path Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_IEN_t__
typedef struct _ADI_GPIO_IEN_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Input path enable */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_IEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_IEN_t__ */

/*@}*/

/** @defgroup IN Port  Registered Data Input (IN) Register
 *  Port  Registered Data Input (IN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_IN_Struct
 *! \brief  Port  Registered Data Input Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_IN_t__
typedef struct _ADI_GPIO_IN_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Registered data input */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_IN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_IN_t__ */

/*@}*/

/** @defgroup OUT Port Data Output (OUT) Register
 *  Port Data Output (OUT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_OUT_Struct
 *! \brief  Port Data Output Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_OUT_t__
typedef struct _ADI_GPIO_OUT_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Data out */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_OUT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_OUT_t__ */

/*@}*/

/** @defgroup SET Port Data Out Set (SET) Register
 *  Port Data Out Set (SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_SET_Struct
 *! \brief  Port Data Out Set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_SET_t__
typedef struct _ADI_GPIO_SET_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Set the output HIGH for the pin */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_SET_t__ */

/*@}*/

/** @defgroup CLR Port Data Out Clear (CLR) Register
 *  Port Data Out Clear (CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_CLR_Struct
 *! \brief  Port Data Out Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_CLR_t__
typedef struct _ADI_GPIO_CLR_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Set the output low  for the port pin */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_CLR_t__ */

/*@}*/

/** @defgroup TGL Port Pin Toggle (TGL) Register
 *  Port Pin Toggle (TGL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_TGL_Struct
 *! \brief  Port Pin Toggle Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_TGL_t__
typedef struct _ADI_GPIO_TGL_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Toggle the output of the port pin */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_TGL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_TGL_t__ */

/*@}*/

/** @defgroup POL Port Interrupt Polarity (POL) Register
 *  Port Interrupt Polarity (POL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_POL_Struct
 *! \brief  Port Interrupt Polarity Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_POL_t__
typedef struct _ADI_GPIO_POL_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Interrupt polarity */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_POL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_POL_t__ */

/*@}*/

/** @defgroup IENA Port Interrupt A Enable (IENA) Register
 *  Port Interrupt A Enable (IENA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_IENA_Struct
 *! \brief  Port Interrupt A Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_IENA_t__
typedef struct _ADI_GPIO_IENA_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Interrupt A enable */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_IENA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_IENA_t__ */

/*@}*/

/** @defgroup IENB Port Interrupt B Enable (IENB) Register
 *  Port Interrupt B Enable (IENB) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_IENB_Struct
 *! \brief  Port Interrupt B Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_IENB_t__
typedef struct _ADI_GPIO_IENB_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Interrupt B enable */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_IENB_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_IENB_t__ */

/*@}*/

/** @defgroup INT Port Interrupt Status (INT) Register
 *  Port Interrupt Status (INT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_INT_Struct
 *! \brief  Port Interrupt Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_INT_t__
typedef struct _ADI_GPIO_INT_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Interrupt Status */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_INT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_INT_t__ */

/*@}*/

/** @defgroup DS Port Drive Strength Select (DS) Register
 *  Port Drive Strength Select (DS) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN00
 *! \brief  Drive Strength Pin 00 (PIN00) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN00 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN00 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN00;


/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN01
 *! \brief  Drive Strength Pin 01 (PIN01) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN01 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN01 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN01;


/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN02
 *! \brief  Drive Strength Pin 02 (PIN02) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN02 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN02 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN02;


/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN03
 *! \brief  Drive Strength Pin 03 (PIN03) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN03 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN03 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN03;


/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN04
 *! \brief  Drive Strength Pin 04 (PIN04) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN04 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN04 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN04;


/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN05
 *! \brief  Drive Strength Pin 05 (PIN05) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN05 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN05 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN05;


/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN06
 *! \brief  Drive Strength Pin 06 (PIN06) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN06 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN06 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN06;


/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN07
 *! \brief  Drive Strength Pin 07 (PIN07) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN07 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN07 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN07;


/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN08
 *! \brief  Drive Strength Pin 08 (PIN08) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN08 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN08 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN08;


/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN09
 *! \brief  Drive Strength Pin 09 (PIN09) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN09 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN09 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN09;


/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN10
 *! \brief  Drive Strength Pin 10 (PIN10) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN10 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN10 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN10;


/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN11
 *! \brief  Drive Strength Pin 11 (PIN11) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN11 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN11 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN11;


/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN12
 *! \brief  Drive Strength Pin 12 (PIN12) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN12 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN12 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN12;


/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN13
 *! \brief  Drive Strength Pin 13 (PIN13) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN13 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN13 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN13;


/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN14
 *! \brief  Drive Strength Pin 14 (PIN14) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN14 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN14 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN14;


/*  =========================================================================
 *! \enum   ADI_GPIO_DS_PIN15
 *! \brief  Drive Strength Pin 15 (PIN15) Enumerations
 *  ========================================================================= */
typedef enum
{
  GPIO_DS_SINGLE_PIN15 = 0,  /**< Single Drive Strength */
  GPIO_DS_DOUBLE_PIN15 = 1   /**< Double Drive Strength */
} ADI_GPIO_DS_PIN15;


/* ==========================================================================
 *! \struct ADI_GPIO_DS_Struct
 *! \brief  Port Drive Strength Select Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_DS_t__
typedef struct _ADI_GPIO_DS_t {
  union {
    struct {
      uint16_t PIN00      :  1;  /**< Drive Strength Pin 00 */
      uint16_t PIN01      :  1;  /**< Drive Strength Pin 01 */
      uint16_t PIN02      :  1;  /**< Drive Strength Pin 02 */
      uint16_t PIN03      :  1;  /**< Drive Strength Pin 03 */
      uint16_t PIN04      :  1;  /**< Drive Strength Pin 04 */
      uint16_t PIN05      :  1;  /**< Drive Strength Pin 05 */
      uint16_t PIN06      :  1;  /**< Drive Strength Pin 06 */
      uint16_t PIN07      :  1;  /**< Drive Strength Pin 07 */
      uint16_t PIN08      :  1;  /**< Drive Strength Pin 08 */
      uint16_t PIN09      :  1;  /**< Drive Strength Pin 09 */
      uint16_t PIN10      :  1;  /**< Drive Strength Pin 10 */
      uint16_t PIN11      :  1;  /**< Drive Strength Pin 11 */
      uint16_t PIN12      :  1;  /**< Drive Strength Pin 12 */
      uint16_t PIN13      :  1;  /**< Drive Strength Pin 13 */
      uint16_t PIN14      :  1;  /**< Drive Strength Pin 14 */
      uint16_t PIN15      :  1;  /**< Drive Strength Pin 15 */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_DS_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_DS_t__ */

/*@}*/

/** @defgroup CTL_A Half SPORT 'A' Control Register (CTL_A) Register
 *  Half SPORT 'A' Control Register (CTL_A) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_A_SPEN
 *! \brief  Serial Port Enable (SPEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_A_CTL_DIS = 0,  /**< Disable */
  SPORT_CTL_A_CTL_EN  = 1   /**< Enable  */
} ADI_SPORT_CTL_A_SPEN;


/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_A_FSMUXSEL
 *! \brief  Frame Sync Multiplexer Select (FSMUXSEL) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_A_CTL_FS_MUX_DIS = 0,  /**< Disable frame sync multiplexing */
  SPORT_CTL_A_CTL_FS_MUX_EN  = 1   /**< Enable frame sync multiplexing  */
} ADI_SPORT_CTL_A_FSMUXSEL;


/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_A_CKMUXSEL
 *! \brief  Clock Multiplexer Select (CKMUXSEL) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_A_CTL_CLK_MUX_DIS = 0,  /**< Disable serial clock multiplexing */
  SPORT_CTL_A_CTL_CLK_MUX_EN  = 1   /**< Enable serial clock multiplexing  */
} ADI_SPORT_CTL_A_CKMUXSEL;


/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_A_LSBF
 *! \brief  Least-Significant Bit First (LSBF) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_A_CTL_MSB_FIRST = 0,  /**< MSB first sent/received */
  SPORT_CTL_A_CTL_LSB_FIRST = 1   /**< LSB first sent/received */
} ADI_SPORT_CTL_A_LSBF;


/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_A_ICLK
 *! \brief  Internal Clock (ICLK) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_A_CTL_EXTERNAL_CLK = 0,  /**< External clock */
  SPORT_CTL_A_CTL_INTERNAL_CLK = 1   /**< Internal clock */
} ADI_SPORT_CTL_A_ICLK;


/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_A_OPMODE
 *! \brief  Operation mode (OPMODE) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_A_CTL_SERIAL        = 0,  /**< DSP standard      */
  SPORT_CTL_A_CTL_TIMER_EN_MODE = 1   /**< Timer_enable mode */
} ADI_SPORT_CTL_A_OPMODE;


/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_A_CKRE
 *! \brief  Clock Rising Edge (CKRE) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_A_CTL_CLK_FALL_EDGE = 0,  /**< Clock falling edge */
  SPORT_CTL_A_CTL_CLK_RISE_EDGE = 1   /**< Clock rising edge  */
} ADI_SPORT_CTL_A_CKRE;


/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_A_FSR
 *! \brief  Frame Sync Required (FSR) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_A_CTL_FS_NOT_REQ = 0,  /**< No frame sync required */
  SPORT_CTL_A_CTL_FS_REQ     = 1   /**< Frame sync required    */
} ADI_SPORT_CTL_A_FSR;


/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_A_IFS
 *! \brief  Internal Frame Sync (IFS) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_A_CTL_EXTERNAL_FS = 0,  /**< External frame sync */
  SPORT_CTL_A_CTL_INTERNAL_FS = 1   /**< Internal frame sync */
} ADI_SPORT_CTL_A_IFS;


/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_A_DIFS
 *! \brief  Data-Independent Frame Sync (DIFS) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_A_CTL_DATA_DEP_FS  = 0,  /**< Data-dependent frame sync   */
  SPORT_CTL_A_CTL_DATA_INDP_FS = 1   /**< Data-independent frame sync */
} ADI_SPORT_CTL_A_DIFS;


/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_A_LFS
 *! \brief  Active-Low Frame Sync (LFS) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_A_CTL_FS_LO = 0,  /**< Active high frame sync */
  SPORT_CTL_A_CTL_FS_HI = 1   /**< Active low frame sync  */
} ADI_SPORT_CTL_A_LFS;


/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_A_LAFS
 *! \brief  Late Frame Sync (LAFS) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_A_CTL_EARLY_FS = 0,  /**< Early frame sync */
  SPORT_CTL_A_CTL_LATE_FS  = 1   /**< Late frame sync  */
} ADI_SPORT_CTL_A_LAFS;


/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_A_PACK
 *! \brief  Packing Enable (PACK) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_A_CTL_PACK_DIS   = 0,  /**< Disable               */
  SPORT_CTL_A_CTL_PACK_8BIT  = 1,  /**< 8-bit packing enable  */
  SPORT_CTL_A_CTL_PACK_16BIT = 2   /**< 16-bit packing enable */
} ADI_SPORT_CTL_A_PACK;


/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_A_GCLKEN
 *! \brief  Gated Clock Enable (GCLKEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_A_CTL_GCLK_DIS = 0,  /**< Disable */
  SPORT_CTL_A_CTL_GCLK_EN  = 1   /**< Enable  */
} ADI_SPORT_CTL_A_GCLKEN;


/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_A_SPTRAN
 *! \brief  Serial Port Transfer Direction (SPTRAN) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_A_CTL_RX = 0,  /**< Receive  */
  SPORT_CTL_A_CTL_TX = 1   /**< Transmit */
} ADI_SPORT_CTL_A_SPTRAN;


/* ==========================================================================
 *! \struct ADI_SPORT_CTL_A_Struct
 *! \brief  Half SPORT 'A' Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_CTL_A_t__
typedef struct _ADI_SPORT_CTL_A_t {
  union {
    struct {
      uint32_t SPEN       :  1;  /**< Serial Port Enable */
      uint32_t FSMUXSEL   :  1;  /**< Frame Sync Multiplexer Select */
      uint32_t CKMUXSEL   :  1;  /**< Clock Multiplexer Select */
      uint32_t LSBF       :  1;  /**< Least-Significant Bit First */
      uint32_t SLEN       :  5;  /**< Serial Word Length */
      uint32_t reserved9  :  1;
      uint32_t ICLK       :  1;  /**< Internal Clock */
      uint32_t OPMODE     :  1;  /**< Operation mode */
      uint32_t CKRE       :  1;  /**< Clock Rising Edge */
      uint32_t FSR        :  1;  /**< Frame Sync Required */
      uint32_t IFS        :  1;  /**< Internal Frame Sync */
      uint32_t DIFS       :  1;  /**< Data-Independent Frame Sync */
      uint32_t LFS        :  1;  /**< Active-Low Frame Sync */
      uint32_t LAFS       :  1;  /**< Late Frame Sync */
      uint32_t PACK       :  2;  /**< Packing Enable */
      uint32_t FSERRMODE  :  1;  /**< Frame Sync Error Operation */
      uint32_t GCLKEN     :  1;  /**< Gated Clock Enable */
      uint32_t DATMUXSEL  :  1;  /**< Data Multiplexer select */
      uint32_t reserved23 :  2;
      uint32_t SPTRAN     :  1;  /**< Serial Port Transfer Direction */
      uint32_t DMAEN      :  1;  /**< DMA Enable */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_CTL_A_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_CTL_A_t__ */

/*@}*/

/** @defgroup DIV_A Half SPORT 'A' Divisor Register (DIV_A) Register
 *  Half SPORT 'A' Divisor Register (DIV_A) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPORT_DIV_A_Struct
 *! \brief  Half SPORT 'A' Divisor Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_DIV_A_t__
typedef struct _ADI_SPORT_DIV_A_t {
  union {
    struct {
      uint32_t CLKDIV     : 16;  /**< Clock Divisor */
      uint32_t FSDIV      :  8;  /**< Frame Sync Divisor */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_DIV_A_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_DIV_A_t__ */

/*@}*/

/** @defgroup IEN_A Half SPORT A's Interrupt Enable register (IEN_A) Register
 *  Half SPORT A's Interrupt Enable register (IEN_A) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_SPORT_IEN_A_TF
 *! \brief  Transfer Finish Interrupt Enable (TF) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_IEN_A_CTL_TXFIN_DIS = 0,  /**< Transfer finish Interrupt is disabled */
  SPORT_IEN_A_CTL_TXFIN_EN  = 1   /**< Transfer Finish Interrupt is Enabled  */
} ADI_SPORT_IEN_A_TF;


/* ==========================================================================
 *! \struct ADI_SPORT_IEN_A_Struct
 *! \brief  Half SPORT A's Interrupt Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_IEN_A_t__
typedef struct _ADI_SPORT_IEN_A_t {
  union {
    struct {
      uint32_t TF         :  1;  /**< Transfer Finish Interrupt Enable */
      uint32_t DERRMSK    :  1;  /**< Data Error (Interrupt) Mask */
      uint32_t FSERRMSK   :  1;  /**< Frame Sync Error (Interrupt) Mask */
      uint32_t DATA       :  1;  /**< Data request interrupt to the core */
      uint32_t SYSDATERR  :  1;  /**< Data error for system writes or reads */
      uint32_t reserved5  : 27;
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_IEN_A_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_IEN_A_t__ */

/*@}*/

/** @defgroup STAT_A Half SPORT 'A' Status register (STAT_A) Register
 *  Half SPORT 'A' Status register (STAT_A) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_SPORT_STAT_A_DXS
 *! \brief  Data Transfer Buffer Status (DXS) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_STAT_A_CTL_EMPTY     = 0,  /**< Empty          */
  SPORT_STAT_A_CTL_PART_FULL = 2,  /**< Partially full */
  SPORT_STAT_A_CTL_FULL      = 3   /**< Full           */
} ADI_SPORT_STAT_A_DXS;


/* ==========================================================================
 *! \struct ADI_SPORT_STAT_A_Struct
 *! \brief  Half SPORT 'A' Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_STAT_A_t__
typedef struct _ADI_SPORT_STAT_A_t {
  union {
    struct {
      uint32_t TFI        :  1;  /**< Transmit Finish Interrupt Status */
      uint32_t DERR       :  1;  /**< Data Error Status */
      uint32_t FSERR      :  1;  /**< Frame Sync Error Status */
      uint32_t DATA       :  1;  /**< Data Buffer status */
      uint32_t SYSDATERR  :  1;  /**< System Data Error Status */
      uint32_t reserved5  :  3;
      uint32_t DXS        :  2;  /**< Data Transfer Buffer Status */
      uint32_t reserved10 : 22;
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_STAT_A_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_STAT_A_t__ */

/*@}*/

/** @defgroup NUMTRAN_A Half SPORT A Number of transfers register (NUMTRAN_A) Register
 *  Half SPORT A Number of transfers register (NUMTRAN_A) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPORT_NUMTRAN_A_Struct
 *! \brief  Half SPORT A Number of transfers Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_NUMTRAN_A_t__
typedef struct _ADI_SPORT_NUMTRAN_A_t {
  union {
    struct {
      uint32_t VALUE      : 12;  /**< Number of transfers (Half SPORT A) */
      uint32_t reserved12 : 20;
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_NUMTRAN_A_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_NUMTRAN_A_t__ */

/*@}*/

/** @defgroup CNVT_A Half SPORT 'A' CNV width (CNVT_A) Register
 *  Half SPORT 'A' CNV width (CNVT_A) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPORT_CNVT_A_Struct
 *! \brief  Half SPORT 'A' CNV width Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_CNVT_A_t__
typedef struct _ADI_SPORT_CNVT_A_t {
  union {
    struct {
      uint32_t WID        :  4;  /**< CNV signal width: Half SPORT A */
      uint32_t reserved4  :  4;
      uint32_t POL        :  1;  /**< Polarity of the CNV signal */
      uint32_t reserved9  :  7;
      uint32_t CNVT2FS    :  8;  /**< CNV to FS duration: Half SPORT A */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_CNVT_A_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_CNVT_A_t__ */

/*@}*/

/** @defgroup TX_A Half SPORT 'A' Tx Buffer Register (TX_A) Register
 *  Half SPORT 'A' Tx Buffer Register (TX_A) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPORT_TX_A_Struct
 *! \brief  Half SPORT 'A' Tx Buffer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_TX_A_t__
typedef struct _ADI_SPORT_TX_A_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Transmit Buffer */
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_TX_A_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_TX_A_t__ */

/*@}*/

/** @defgroup RX_A Half SPORT 'A' Rx Buffer Register (RX_A) Register
 *  Half SPORT 'A' Rx Buffer Register (RX_A) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPORT_RX_A_Struct
 *! \brief  Half SPORT 'A' Rx Buffer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_RX_A_t__
typedef struct _ADI_SPORT_RX_A_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Receive Buffer */
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_RX_A_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_RX_A_t__ */

/*@}*/

/** @defgroup CTL_B Half SPORT 'B' Control Register (CTL_B) Register
 *  Half SPORT 'B' Control Register (CTL_B) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_SPORT_CTL_B_PACK
 *! \brief  Packing Enable (PACK) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_CTL_B_CTL_PACK_DIS   = 0,  /**< Disable               */
  SPORT_CTL_B_CTL_PACK_8BIT  = 1,  /**< 8-bit packing enable  */
  SPORT_CTL_B_CTL_PACK_16BIT = 2   /**< 16-bit packing enable */
} ADI_SPORT_CTL_B_PACK;


/* ==========================================================================
 *! \struct ADI_SPORT_CTL_B_Struct
 *! \brief  Half SPORT 'B' Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_CTL_B_t__
typedef struct _ADI_SPORT_CTL_B_t {
  union {
    struct {
      uint32_t SPEN       :  1;  /**< Serial Port Enable */
      uint32_t reserved1  :  2;
      uint32_t LSBF       :  1;  /**< Least-Significant Bit First */
      uint32_t SLEN       :  5;  /**< Serial Word Length */
      uint32_t reserved9  :  1;
      uint32_t ICLK       :  1;  /**< Internal Clock */
      uint32_t OPMODE     :  1;  /**< Operation mode */
      uint32_t CKRE       :  1;  /**< Clock Rising Edge */
      uint32_t FSR        :  1;  /**< Frame Sync Required */
      uint32_t IFS        :  1;  /**< Internal Frame Sync */
      uint32_t DIFS       :  1;  /**< Data-Independent Frame Sync */
      uint32_t LFS        :  1;  /**< Active-Low Frame Sync */
      uint32_t LAFS       :  1;  /**< Late Frame Sync */
      uint32_t PACK       :  2;  /**< Packing Enable */
      uint32_t FSERRMODE  :  1;  /**< Frame Sync Error Operation */
      uint32_t GCLKEN     :  1;  /**< Gated Clock Enable */
      uint32_t reserved22 :  3;
      uint32_t SPTRAN     :  1;  /**< Serial Port Transfer Direction */
      uint32_t DMAEN      :  1;  /**< DMA Enable */
      uint32_t reserved27 :  5;
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_CTL_B_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_CTL_B_t__ */

/*@}*/

/** @defgroup DIV_B Half SPORT 'B' Divisor Register (DIV_B) Register
 *  Half SPORT 'B' Divisor Register (DIV_B) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPORT_DIV_B_Struct
 *! \brief  Half SPORT 'B' Divisor Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_DIV_B_t__
typedef struct _ADI_SPORT_DIV_B_t {
  union {
    struct {
      uint32_t CLKDIV     : 16;  /**< Clock Divisor */
      uint32_t FSDIV      :  8;  /**< Frame Sync Divisor */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_DIV_B_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_DIV_B_t__ */

/*@}*/

/** @defgroup IEN_B Half SPORT B's Interrupt Enable register (IEN_B) Register
 *  Half SPORT B's Interrupt Enable register (IEN_B) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_SPORT_IEN_B_TF
 *! \brief  Transmit Finish Interrupt Enable (TF) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_IEN_B_CTL_TXFIN_DIS = 0,  /**< Transfer Finish Interrupt is disabled */
  SPORT_IEN_B_CTL_TXFIN_EN  = 1   /**< Transfer Finish Interrupt is Enabled  */
} ADI_SPORT_IEN_B_TF;


/* ==========================================================================
 *! \struct ADI_SPORT_IEN_B_Struct
 *! \brief  Half SPORT B's Interrupt Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_IEN_B_t__
typedef struct _ADI_SPORT_IEN_B_t {
  union {
    struct {
      uint32_t TF         :  1;  /**< Transmit Finish Interrupt Enable */
      uint32_t DERRMSK    :  1;  /**< Data Error (Interrupt) Mask */
      uint32_t FSERRMSK   :  1;  /**< Frame Sync Error (Interrupt) Mask */
      uint32_t DATA       :  1;  /**< Data request interrupt to the core */
      uint32_t SYSDATERR  :  1;  /**< Data error for system writes or reads */
      uint32_t reserved5  : 27;
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_IEN_B_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_IEN_B_t__ */

/*@}*/

/** @defgroup STAT_B Half SPORT 'B' Status register (STAT_B) Register
 *  Half SPORT 'B' Status register (STAT_B) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_SPORT_STAT_B_DXS
 *! \brief  Data Transfer Buffer Status (DXS) Enumerations
 *  ========================================================================= */
typedef enum
{
  SPORT_STAT_B_CTL_EMPTY     = 0,  /**< Empty          */
  SPORT_STAT_B_CTL_PART_FULL = 2,  /**< Partially full */
  SPORT_STAT_B_CTL_FULL      = 3   /**< Full           */
} ADI_SPORT_STAT_B_DXS;


/* ==========================================================================
 *! \struct ADI_SPORT_STAT_B_Struct
 *! \brief  Half SPORT 'B' Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_STAT_B_t__
typedef struct _ADI_SPORT_STAT_B_t {
  union {
    struct {
      uint32_t TFI        :  1;  /**< Transmit Finish Interrupt Status */
      uint32_t DERR       :  1;  /**< Data Error Status */
      uint32_t FSERR      :  1;  /**< Frame Sync Error Status */
      uint32_t DATA       :  1;  /**< Data Buffer status */
      uint32_t SYSDATERR  :  1;  /**< System Data Error Status */
      uint32_t reserved5  :  3;
      uint32_t DXS        :  2;  /**< Data Transfer Buffer Status */
      uint32_t reserved10 : 22;
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_STAT_B_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_STAT_B_t__ */

/*@}*/

/** @defgroup NUMTRAN_B Half SPORT B Number of transfers register (NUMTRAN_B) Register
 *  Half SPORT B Number of transfers register (NUMTRAN_B) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPORT_NUMTRAN_B_Struct
 *! \brief  Half SPORT B Number of transfers Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_NUMTRAN_B_t__
typedef struct _ADI_SPORT_NUMTRAN_B_t {
  union {
    struct {
      uint32_t VALUE      : 12;  /**< Number of transfers (Half SPORT B) */
      uint32_t reserved12 : 20;
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_NUMTRAN_B_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_NUMTRAN_B_t__ */

/*@}*/

/** @defgroup CNVT_B Half SPORT 'B' CNV width register (CNVT_B) Register
 *  Half SPORT 'B' CNV width register (CNVT_B) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPORT_CNVT_B_Struct
 *! \brief  Half SPORT 'B' CNV width Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_CNVT_B_t__
typedef struct _ADI_SPORT_CNVT_B_t {
  union {
    struct {
      uint32_t WID        :  4;  /**< CNV signal width: Half SPORT B */
      uint32_t reserved4  :  4;
      uint32_t POL        :  1;  /**< Polarity of the CNV signal */
      uint32_t reserved9  :  7;
      uint32_t CNVT2FS    :  8;  /**< CNV to FS duration: Half SPORT B */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_CNVT_B_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_CNVT_B_t__ */

/*@}*/

/** @defgroup TX_B Half SPORT 'B' Tx Buffer Register (TX_B) Register
 *  Half SPORT 'B' Tx Buffer Register (TX_B) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPORT_TX_B_Struct
 *! \brief  Half SPORT 'B' Tx Buffer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_TX_B_t__
typedef struct _ADI_SPORT_TX_B_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Transmit Buffer */
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_TX_B_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_TX_B_t__ */

/*@}*/

/** @defgroup RX_B Half SPORT 'B' Rx Buffer Register (RX_B) Register
 *  Half SPORT 'B' Rx Buffer Register (RX_B) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPORT_RX_B_Struct
 *! \brief  Half SPORT 'B' Rx Buffer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPORT_RX_B_t__
typedef struct _ADI_SPORT_RX_B_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Receive Buffer */
    };
    uint32_t VALUE32;
  };
} ADI_SPORT_RX_B_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPORT_RX_B_t__ */

/*@}*/

/** @defgroup CTL CRC Control (CTL) Register
 *  CRC Control (CTL) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_CRC_CTL_EN
 *! \brief  CRC Peripheral Enable (EN) Enumerations
 *  ========================================================================= */
typedef enum
{
  CRC_CTL_CRC_DIS = 0,  /**< CRC peripheral is disabled */
  CRC_CTL_CRC_EN  = 1   /**< CRC peripheral is enabled  */
} ADI_CRC_CTL_EN;


/*  =========================================================================
 *! \enum   ADI_CRC_CTL_LSBFIRST
 *! \brief  LSB First Calculation Order (LSBFIRST) Enumerations
 *  ========================================================================= */
typedef enum
{
  CRC_CTL_MSB_FIRST = 0,  /**< MSB First CRC calculation is done */
  CRC_CTL_LSB_FIRST = 1   /**< LSB First CRC calculation is done */
} ADI_CRC_CTL_LSBFIRST;


/*  =========================================================================
 *! \enum   ADI_CRC_CTL_BITMIRR
 *! \brief  Bit Mirroring (BITMIRR) Enumerations
 *  ========================================================================= */
typedef enum
{
  CRC_CTL_BITMIRR_DIS = 0,  /**< Bit Mirroring is disabled */
  CRC_CTL_BITMIRR_EN  = 1   /**< Bit Mirroring is enabled  */
} ADI_CRC_CTL_BITMIRR;


/*  =========================================================================
 *! \enum   ADI_CRC_CTL_BYTMIRR
 *! \brief  Byte Mirroring (BYTMIRR) Enumerations
 *  ========================================================================= */
typedef enum
{
  CRC_CTL_BYTEMIR_DIS = 0,  /**< Byte Mirroring is disabled */
  CRC_CTL_BYTEMIR_EN  = 1   /**< Byte Mirroring is enabled  */
} ADI_CRC_CTL_BYTMIRR;


/*  =========================================================================
 *! \enum   ADI_CRC_CTL_W16SWP
 *! \brief  Word16 Swap (W16SWP) Enumerations
 *  ========================================================================= */
typedef enum
{
  CRC_CTL_W16SP_DIS = 0,  /**< Word16 Swap disabled */
  CRC_CTL_W16SP_EN  = 1   /**< Word16 Swap enabled  */
} ADI_CRC_CTL_W16SWP;


/* ==========================================================================
 *! \struct ADI_CRC_CTL_Struct
 *! \brief  CRC Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRC_CTL_t__
typedef struct _ADI_CRC_CTL_t {
  union {
    struct {
      uint32_t EN         :  1;  /**< CRC Peripheral Enable */
      uint32_t LSBFIRST   :  1;  /**< LSB First Calculation Order */
      uint32_t BITMIRR    :  1;  /**< Bit Mirroring */
      uint32_t BYTMIRR    :  1;  /**< Byte Mirroring */
      uint32_t W16SWP     :  1;  /**< Word16 Swap */
      uint32_t reserved5  : 23;
      uint32_t RevID      :  4;  /**< Revision ID */
    };
    uint32_t VALUE32;
  };
} ADI_CRC_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRC_CTL_t__ */

/*@}*/

/** @defgroup IPDATA Input Data Word (IPDATA) Register
 *  Input Data Word (IPDATA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRC_IPDATA_Struct
 *! \brief  Input Data Word Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRC_IPDATA_t__
typedef struct _ADI_CRC_IPDATA_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Data Input */
    };
    uint32_t VALUE32;
  };
} ADI_CRC_IPDATA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRC_IPDATA_t__ */

/*@}*/

/** @defgroup RESULT CRC Result (RESULT) Register
 *  CRC Result (RESULT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRC_RESULT_Struct
 *! \brief  CRC Result Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRC_RESULT_t__
typedef struct _ADI_CRC_RESULT_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< CRC Residue */
    };
    uint32_t VALUE32;
  };
} ADI_CRC_RESULT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRC_RESULT_t__ */

/*@}*/

/** @defgroup POLY Programmable CRC Polynomial (POLY) Register
 *  Programmable CRC Polynomial (POLY) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRC_POLY_Struct
 *! \brief  Programmable CRC Polynomial Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRC_POLY_t__
typedef struct _ADI_CRC_POLY_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< CRC Reduction Polynomial */
    };
    uint32_t VALUE32;
  };
} ADI_CRC_POLY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRC_POLY_t__ */

/*@}*/

/** @defgroup IPBITS Input Data Bits (IPBITS) Register
 *  Input Data Bits (IPBITS) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRC_IPBITS_Struct
 *! \brief  Input Data Bits Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRC_IPBITS_t__
typedef struct _ADI_CRC_IPBITS_t {
  union {
    struct {
      uint8_t DATA_BITS  :  8;  /**< Input Data Bits */
    };
    uint8_t VALUE8;
  };
} ADI_CRC_IPBITS_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRC_IPBITS_t__ */

/*@}*/

/** @defgroup IPBYTE Input Data Byte (IPBYTE) Register
 *  Input Data Byte (IPBYTE) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRC_IPBYTE_Struct
 *! \brief  Input Data Byte Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRC_IPBYTE_t__
typedef struct _ADI_CRC_IPBYTE_t {
  union {
    struct {
      uint8_t DATA_BYTE  :  8;  /**< Input Data Byte */
    };
    uint8_t VALUE8;
  };
} ADI_CRC_IPBYTE_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRC_IPBYTE_t__ */

/*@}*/

/** @defgroup CTL RNG Control Register (CTL) Register
 *  RNG Control Register (CTL) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_RNG_CTL_EN
 *! \brief  RNG Enable (EN) Enumerations
 *  ========================================================================= */
typedef enum
{
  RNG_CTL_DISABLE = 0,  /**< Disable the RNG */
  RNG_CTL_ENABLE  = 1   /**< Enable the RNG  */
} ADI_RNG_CTL_EN;


/*  =========================================================================
 *! \enum   ADI_RNG_CTL_SINGLE
 *! \brief  Generate a Single Number (SINGLE) Enumerations
 *  ========================================================================= */
typedef enum
{
  RNG_CTL_WORD   = 0,  /**< Buffer Word */
  RNG_CTL_SINGLE = 1   /**< Single Byte */
} ADI_RNG_CTL_SINGLE;


/* ==========================================================================
 *! \struct ADI_RNG_CTL_Struct
 *! \brief  RNG Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RNG_CTL_t__
typedef struct _ADI_RNG_CTL_t {
  union {
    struct {
      uint16_t EN         :  1;  /**< RNG Enable */
      uint16_t reserved1  :  2;
      uint16_t SINGLE     :  1;  /**< Generate a Single Number */
      uint16_t reserved4  : 12;
    };
    uint16_t VALUE16;
  };
} ADI_RNG_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RNG_CTL_t__ */

/*@}*/

/** @defgroup LEN RNG Sample Length Register (LEN) Register
 *  RNG Sample Length Register (LEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RNG_LEN_Struct
 *! \brief  RNG Sample Length Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RNG_LEN_t__
typedef struct _ADI_RNG_LEN_t {
  union {
    struct {
      uint16_t RELOAD     : 12;  /**< Reload Value for the Sample Counter */
      uint16_t PRESCALE   :  4;  /**< Prescaler for the Sample Counter */
    };
    uint16_t VALUE16;
  };
} ADI_RNG_LEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RNG_LEN_t__ */

/*@}*/

/** @defgroup STAT RNG Status Register (STAT) Register
 *  RNG Status Register (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RNG_STAT_Struct
 *! \brief  RNG Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RNG_STAT_t__
typedef struct _ADI_RNG_STAT_t {
  union {
    struct {
      uint16_t RNRDY      :  1;  /**< Random Number Ready */
      uint16_t STUCK      :  1;  /**< Sampled Data Stuck High or Low */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_RNG_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RNG_STAT_t__ */

/*@}*/

/** @defgroup DATA RNG Data Register (DATA) Register
 *  RNG Data Register (DATA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RNG_DATA_Struct
 *! \brief  RNG Data Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RNG_DATA_t__
typedef struct _ADI_RNG_DATA_t {
  union {
    struct {
      uint32_t VALUE      :  8;  /**< Value of the CRC Accumulator */
      uint32_t BUFF       : 24;  /**< Buffer for RNG Data */
    };
    uint32_t VALUE32;
  };
} ADI_RNG_DATA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RNG_DATA_t__ */

/*@}*/

/** @defgroup OSCCNT Oscillator Count (OSCCNT) Register
 *  Oscillator Count (OSCCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RNG_OSCCNT_Struct
 *! \brief  Oscillator Count Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RNG_OSCCNT_t__
typedef struct _ADI_RNG_OSCCNT_t {
  union {
    struct {
      uint32_t VALUE      : 28;  /**< Oscillator Count */
      uint32_t reserved28 :  4;
    };
    uint32_t VALUE32;
  };
} ADI_RNG_OSCCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RNG_OSCCNT_t__ */

/*@}*/

/** @defgroup OSCDIFF Oscillator Difference (OSCDIFF) Register
 *  Oscillator Difference (OSCDIFF) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RNG_OSCDIFF_Struct
 *! \brief  Oscillator Difference Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RNG_OSCDIFF_t__
typedef struct _ADI_RNG_OSCDIFF_t {
  union {
    struct {
      int8_t DELTA      :  8;  /**< Oscillator Count Difference */
    };
    int8_t VALUE8;
  };
} ADI_RNG_OSCDIFF_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RNG_OSCDIFF_t__ */

/*@}*/

/** @defgroup CFG Configuration Register (CFG) Register
 *  Configuration Register (CFG) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_CRYPT_CFG_BLKEN
 *! \brief  Enable Bit for Crypto Block (BLKEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  CRYPT_CFG_ENABLE  = 0,  /**< Enable Crypto Block  */
  CRYPT_CFG_DISABLE = 1   /**< Disable Crypto Block */
} ADI_CRYPT_CFG_BLKEN;


/*  =========================================================================
 *! \enum   ADI_CRYPT_CFG_INDMAEN
 *! \brief  Enable DMA Channel Request for Input Buffer (INDMAEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  CRYPT_CFG_DMA_DISABLE_INBUF = 0,  /**< Disable DMA Requesting for Input Buffer */
  CRYPT_CFG_DMA_ENABLE_INBUF  = 1   /**< Enable DMA Requesting for Input Buffer  */
} ADI_CRYPT_CFG_INDMAEN;


/*  =========================================================================
 *! \enum   ADI_CRYPT_CFG_OUTDMAEN
 *! \brief  Enable DMA Channel Request for Output Buffer (OUTDMAEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  CRYPT_CFG_DMA_DISABLE_OUTBUF = 0,  /**< Disable DMA Requesting for Output Buffer */
  CRYPT_CFG_DMA_ENABLE_OUTBUF  = 1   /**< Enable DMA Requesting for Output Buffer  */
} ADI_CRYPT_CFG_OUTDMAEN;


/*  =========================================================================
 *! \enum   ADI_CRYPT_CFG_AESKEYLEN
 *! \brief  Select Key Length for AES Cipher (AESKEYLEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  CRYPT_CFG_AESKEYLEN128 = 0,  /**< Uses 128-bit long key */
  CRYPT_CFG_AESKEYLEN256 = 2   /**< Uses 256-bit long key */
} ADI_CRYPT_CFG_AESKEYLEN;


/*  =========================================================================
 *! \enum   ADI_CRYPT_CFG_KUWKeyLen
 *! \brief  Key Length  Key Wrap Unwrap (KUWKeyLen) Enumerations
 *  ========================================================================= */
typedef enum
{
  CRYPT_CFG_LEN128 = 1,  /**< The key size of KUW key is 128 bits */
  CRYPT_CFG_LEN256 = 2,  /**< The key size of KUW key is 256 bits */
  CRYPT_CFG_LEN512 = 3   /**< The key size of KUW key is 512 bits */
} ADI_CRYPT_CFG_KUWKeyLen;


/* ==========================================================================
 *! \struct ADI_CRYPT_CFG_Struct
 *! \brief  Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_CFG_t__
typedef struct _ADI_CRYPT_CFG_t {
  union {
    struct {
      uint32_t BLKEN      :  1;  /**< Enable Bit for Crypto Block */
      uint32_t ENCR       :  1;  /**< Encrypt or Decrypt */
      uint32_t INDMAEN    :  1;  /**< Enable DMA Channel Request for Input Buffer */
      uint32_t OUTDMAEN   :  1;  /**< Enable DMA Channel Request for Output Buffer */
      uint32_t INFLUSH    :  1;  /**< Input Buffer Flush */
      uint32_t OUTFLUSH   :  1;  /**< Output Buffer Flush */
      uint32_t reserved6  :  2;
      uint32_t AESKEYLEN  :  2;  /**< Select Key Length for AES Cipher */
      uint32_t KUWKeyLen  :  2;  /**< Key Length  Key Wrap Unwrap */
      uint32_t AES_BYTESWAP :  1;  /**< Byteswap for AES Input */
      uint32_t SHA_BYTESWAP :  1;  /**< Enable Key Wrap */
      uint32_t KEY_BYTESWAP :  1;  /**< Use Key Unwrap Before HMAC */
      uint32_t PRKSTOREN    :  1;  /**< Enable PRKSTOR Commands */
      uint32_t ECBEN        :  1;  /**< Enable ECB Mode Operation */
      uint32_t CTREN        :  1;  /**< Enable CTR Mode Operation */
      uint32_t CBCEN        :  1;  /**< Enable CBC Mode Operation */
      uint32_t CCMEN        :  1;  /**< Enable CCM/CCM* Mode Operation */
      uint32_t CMACEN       :  1;  /**< Enable CMAC Mode Operation */
      uint32_t HMACEN       :  1;  /**< HMAC Enable */
      uint32_t reserved22   :  3;
      uint32_t SHA256EN     :  1;  /**< Enable SHA-256 Operation */
      uint32_t SHAINIT      :  1;  /**< Restarts SHA Computation */
      uint32_t reserved27   :  1;
      uint32_t RevID        :  4;  /**< Rev ID for Crypto */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_CFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_CFG_t__ */

/*@}*/

/** @defgroup DATALEN Payload Data Length (DATALEN) Register
 *  Payload Data Length (DATALEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_DATALEN_Struct
 *! \brief  Payload Data Length Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_DATALEN_t__
typedef struct _ADI_CRYPT_DATALEN_t {
  union {
    struct {
      uint32_t VALUE      : 20;  /**< Length of Payload Data */
      uint32_t reserved20 : 12;
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_DATALEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_DATALEN_t__ */

/*@}*/

/** @defgroup PREFIXLEN Authentication Data Length (PREFIXLEN) Register
 *  Authentication Data Length (PREFIXLEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_PREFIXLEN_Struct
 *! \brief  Authentication Data Length Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_PREFIXLEN_t__
typedef struct _ADI_CRYPT_PREFIXLEN_t {
  union {
    struct {
      uint32_t VALUE      : 16;  /**< Length of Associated Data */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_PREFIXLEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_PREFIXLEN_t__ */

/*@}*/

/** @defgroup INTEN Interrupt Enable Register (INTEN) Register
 *  Interrupt Enable Register (INTEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_INTEN_Struct
 *! \brief  Interrupt Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_INTEN_t__
typedef struct _ADI_CRYPT_INTEN_t {
  union {
    struct {
      uint32_t INRDYEN    :  1;  /**< Enable Input Ready Interrupt */
      uint32_t OUTRDYEN   :  1;  /**< Enables the Output Ready Interrupt */
      uint32_t INOVREN    :  1;  /**< Enable Input Overflow Interrupt */
      uint32_t reserved3  :  2;
      uint32_t SHADONEN   :  1;  /**< Enable SHA_Done Interrupt */
      uint32_t HMACDONEEN :  1;  /**< Interrupt Enable for HMAC Done */
      uint32_t HMACMSGRDYEN :  1;  /**< Status Bit for HMAC Message Input Ready */
      uint32_t PRKSTRCMDONEEN :  1;  /**< PRKSTOR CMD DONE INTEN */
      uint32_t reserved9      : 23;
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_INTEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_INTEN_t__ */

/*@}*/

/** @defgroup STAT Status Register (STAT) Register
 *  Status Register (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_STAT_Struct
 *! \brief  Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_STAT_t__
typedef struct _ADI_CRYPT_STAT_t {
  union {
    struct {
      uint32_t INRDY      :  1;  /**< Input Buffer Status */
      uint32_t OUTRDY     :  1;  /**< Output Data Ready */
      uint32_t INOVR      :  1;  /**< Overflow in the Input Buffer */
      uint32_t reserved3  :  2;
      uint32_t SHADONE    :  1;  /**< SHA Computation Complete */
      uint32_t SHABUSY    :  1;  /**< SHA Busy. in Computation */
      uint32_t INWORDS    :  3;  /**< Number of Words in the Input Buffer */
      uint32_t OUTWORDS   :  3;  /**< Number of Words in the Output Buffer */
      uint32_t HMACBUSY   :  1;  /**< Status Bit Indicates HMAC Busy */
      uint32_t HMACDONE   :  1;  /**< Status Bit Indicates HMAC Done */
      uint32_t HMACMSGRDY :  1;  /**< Status Bit Indicates HMAC is Message Ready */
      uint32_t reserved16       :  7;
      uint32_t PRKSTOR_CMD_DONE :  1;  /**< Indicates Command Done for PrKStor */
      uint32_t PRKSTOR_CMD_FAIL :  1;  /**< Indicates Last Command Issued Failed */
      uint32_t PRKSTOR_RET_STATUS :  2;  /**< ECC Errors in the PRKSTOR_RETRIEVE Command */
      uint32_t CMD_ISSUED         :  4;  /**< Last Command Issued to PrKStor */
      uint32_t PRKSTOR_BUSY       :  1;  /**< Indicates PrKSTOR is Busy */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_STAT_t__ */

/*@}*/

/** @defgroup INBUF Input Buffer (INBUF) Register
 *  Input Buffer (INBUF) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_INBUF_Struct
 *! \brief  Input Buffer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_INBUF_t__
typedef struct _ADI_CRYPT_INBUF_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Input Buffer */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_INBUF_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_INBUF_t__ */

/*@}*/

/** @defgroup OUTBUF Output Buffer (OUTBUF) Register
 *  Output Buffer (OUTBUF) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_OUTBUF_Struct
 *! \brief  Output Buffer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_OUTBUF_t__
typedef struct _ADI_CRYPT_OUTBUF_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Output Buffer */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_OUTBUF_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_OUTBUF_t__ */

/*@}*/

/** @defgroup NONCE0 Nonce Bits [31:0] (NONCE0) Register
 *  Nonce Bits [31:0] (NONCE0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_NONCE0_Struct
 *! \brief  Nonce Bits [31:0] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE0_t__
typedef struct _ADI_CRYPT_NONCE0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Word 0: Nonce Bits [31:0] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_NONCE0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE0_t__ */

/*@}*/

/** @defgroup NONCE1 Nonce Bits [63:32] (NONCE1) Register
 *  Nonce Bits [63:32] (NONCE1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_NONCE1_Struct
 *! \brief  Nonce Bits [63:32] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE1_t__
typedef struct _ADI_CRYPT_NONCE1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Word 1: Nonce Bits [63:32] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_NONCE1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE1_t__ */

/*@}*/

/** @defgroup NONCE2 Nonce Bits [95:64] (NONCE2) Register
 *  Nonce Bits [95:64] (NONCE2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_NONCE2_Struct
 *! \brief  Nonce Bits [95:64] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE2_t__
typedef struct _ADI_CRYPT_NONCE2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Word 2: Nonce Bits [95:64] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_NONCE2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE2_t__ */

/*@}*/

/** @defgroup NONCE3 Nonce Bits [127:96] (NONCE3) Register
 *  Nonce Bits [127:96] (NONCE3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_NONCE3_Struct
 *! \brief  Nonce Bits [127:96] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE3_t__
typedef struct _ADI_CRYPT_NONCE3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Word 3: Nonce Bits [127:96] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_NONCE3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE3_t__ */

/*@}*/

/** @defgroup AESKEY0 AES Key Bits [31:0] (AESKEY0) Register
 *  AES Key Bits [31:0] (AESKEY0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY0_Struct
 *! \brief  AES Key Bits [31:0] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY0_t__
typedef struct _ADI_CRYPT_AESKEY0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [3:0] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY0_t__ */

/*@}*/

/** @defgroup AESKEY1 AES Key Bits [63:32] (AESKEY1) Register
 *  AES Key Bits [63:32] (AESKEY1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY1_Struct
 *! \brief  AES Key Bits [63:32] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY1_t__
typedef struct _ADI_CRYPT_AESKEY1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [7:4] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY1_t__ */

/*@}*/

/** @defgroup AESKEY2 AES Key Bits [95:64] (AESKEY2) Register
 *  AES Key Bits [95:64] (AESKEY2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY2_Struct
 *! \brief  AES Key Bits [95:64] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY2_t__
typedef struct _ADI_CRYPT_AESKEY2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [11:8] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY2_t__ */

/*@}*/

/** @defgroup AESKEY3 AES Key Bits [127:96] (AESKEY3) Register
 *  AES Key Bits [127:96] (AESKEY3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY3_Struct
 *! \brief  AES Key Bits [127:96] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY3_t__
typedef struct _ADI_CRYPT_AESKEY3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [15:12] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY3_t__ */

/*@}*/

/** @defgroup AESKEY4 AES Key Bits [159:128] (AESKEY4) Register
 *  AES Key Bits [159:128] (AESKEY4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY4_Struct
 *! \brief  AES Key Bits [159:128] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY4_t__
typedef struct _ADI_CRYPT_AESKEY4_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [19:16] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY4_t__ */

/*@}*/

/** @defgroup AESKEY5 AES Key Bits [191:160] (AESKEY5) Register
 *  AES Key Bits [191:160] (AESKEY5) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY5_Struct
 *! \brief  AES Key Bits [191:160] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY5_t__
typedef struct _ADI_CRYPT_AESKEY5_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [23:20] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY5_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY5_t__ */

/*@}*/

/** @defgroup AESKEY6 AES Key Bits [223:192] (AESKEY6) Register
 *  AES Key Bits [223:192] (AESKEY6) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY6_Struct
 *! \brief  AES Key Bits [223:192] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY6_t__
typedef struct _ADI_CRYPT_AESKEY6_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [27:24] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY6_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY6_t__ */

/*@}*/

/** @defgroup AESKEY7 AES Key Bits [255:224] (AESKEY7) Register
 *  AES Key Bits [255:224] (AESKEY7) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY7_Struct
 *! \brief  AES Key Bits [255:224] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY7_t__
typedef struct _ADI_CRYPT_AESKEY7_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [31:28] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY7_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY7_t__ */

/*@}*/

/** @defgroup CNTRINIT Counter Initialization Vector (CNTRINIT) Register
 *  Counter Initialization Vector (CNTRINIT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_CNTRINIT_Struct
 *! \brief  Counter Initialization Vector Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_CNTRINIT_t__
typedef struct _ADI_CRYPT_CNTRINIT_t {
  union {
    struct {
      uint32_t VALUE      : 20;  /**< Counter Initialization Value */
      uint32_t reserved20 : 12;
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_CNTRINIT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_CNTRINIT_t__ */

/*@}*/

/** @defgroup SHAH0 SHA Bits [31:0] (SHAH0) Register
 *  SHA Bits [31:0] (SHAH0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH0_Struct
 *! \brief  SHA Bits [31:0] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH0_t__
typedef struct _ADI_CRYPT_SHAH0_t {
  union {
    struct {
      uint32_t SHAHASH0   : 32;  /**< Word 0: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH0_t__ */

/*@}*/

/** @defgroup SHAH1 SHA Bits [63:32] (SHAH1) Register
 *  SHA Bits [63:32] (SHAH1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH1_Struct
 *! \brief  SHA Bits [63:32] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH1_t__
typedef struct _ADI_CRYPT_SHAH1_t {
  union {
    struct {
      uint32_t SHAHASH1   : 32;  /**< Word 1: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH1_t__ */

/*@}*/

/** @defgroup SHAH2 SHA Bits [95:64] (SHAH2) Register
 *  SHA Bits [95:64] (SHAH2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH2_Struct
 *! \brief  SHA Bits [95:64] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH2_t__
typedef struct _ADI_CRYPT_SHAH2_t {
  union {
    struct {
      uint32_t SHAHASH2   : 32;  /**< Word 2: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH2_t__ */

/*@}*/

/** @defgroup SHAH3 SHA Bits [127:96] (SHAH3) Register
 *  SHA Bits [127:96] (SHAH3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH3_Struct
 *! \brief  SHA Bits [127:96] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH3_t__
typedef struct _ADI_CRYPT_SHAH3_t {
  union {
    struct {
      uint32_t SHAHASH3   : 32;  /**< Word 3: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH3_t__ */

/*@}*/

/** @defgroup SHAH4 SHA Bits [159:128] (SHAH4) Register
 *  SHA Bits [159:128] (SHAH4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH4_Struct
 *! \brief  SHA Bits [159:128] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH4_t__
typedef struct _ADI_CRYPT_SHAH4_t {
  union {
    struct {
      uint32_t SHAHASH4   : 32;  /**< Word 4: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH4_t__ */

/*@}*/

/** @defgroup SHAH5 SHA Bits [191:160] (SHAH5) Register
 *  SHA Bits [191:160] (SHAH5) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH5_Struct
 *! \brief  SHA Bits [191:160] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH5_t__
typedef struct _ADI_CRYPT_SHAH5_t {
  union {
    struct {
      uint32_t SHAHASH5   : 32;  /**< Word 5: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH5_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH5_t__ */

/*@}*/

/** @defgroup SHAH6 SHA Bits [223:192] (SHAH6) Register
 *  SHA Bits [223:192] (SHAH6) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH6_Struct
 *! \brief  SHA Bits [223:192] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH6_t__
typedef struct _ADI_CRYPT_SHAH6_t {
  union {
    struct {
      uint32_t SHAHASH6   : 32;  /**< Word 6: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH6_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH6_t__ */

/*@}*/

/** @defgroup SHAH7 SHA Bits [255:224] (SHAH7) Register
 *  SHA Bits [255:224] (SHAH7) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH7_Struct
 *! \brief  SHA Bits [255:224] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH7_t__
typedef struct _ADI_CRYPT_SHAH7_t {
  union {
    struct {
      uint32_t SHAHASH7   : 32;  /**< Word 7: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH7_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH7_t__ */

/*@}*/

/** @defgroup SHA_LAST_WORD SHA Last Word and Valid Bits Information (SHA_LAST_WORD) Register
 *  SHA Last Word and Valid Bits Information (SHA_LAST_WORD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHA_LAST_WORD_Struct
 *! \brief  SHA Last Word and Valid Bits Information Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHA_LAST_WORD_t__
typedef struct _ADI_CRYPT_SHA_LAST_WORD_t {
  union {
    struct {
      uint32_t O_Last_Word :  1;  /**< Last SHA Input Word */
      uint32_t O_Bits_Valid :  5;  /**< Bits Valid in SHA Last Word Input */
      uint32_t reserved6    : 26;
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHA_LAST_WORD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHA_LAST_WORD_t__ */

/*@}*/

/** @defgroup CCM_NUM_VALID_BYTES NUM_VALID_BYTES (CCM_NUM_VALID_BYTES) Register
 *  NUM_VALID_BYTES (CCM_NUM_VALID_BYTES) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_CCM_NUM_VALID_BYTES_Struct
 *! \brief  NUM_VALID_BYTES Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_CCM_NUM_VALID_BYTES_t__
typedef struct _ADI_CRYPT_CCM_NUM_VALID_BYTES_t {
  union {
    struct {
      uint32_t NUM_VALID_BYTES :  4;  /**< Number of Valid Bytes in CCM Last Data */
      uint32_t reserved4       : 28;
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_CCM_NUM_VALID_BYTES_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_CCM_NUM_VALID_BYTES_t__ */

/*@}*/

/** @defgroup PRKSTORCFG PRKSTOR Configuration (PRKSTORCFG) Register
 *  PRKSTOR Configuration (PRKSTORCFG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_PRKSTORCFG_Struct
 *! \brief  PRKSTOR Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_PRKSTORCFG_t__
typedef struct _ADI_CRYPT_PRKSTORCFG_t {
  union {
    struct {
      uint32_t KEY_INDEX  :  7;  /**< Index of Key in PRKSTOR */
      uint32_t CMD        :  4;  /**< Command Input for PRKSTOR */
      uint32_t reserved11 : 21;
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_PRKSTORCFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_PRKSTORCFG_t__ */

/*@}*/

/** @defgroup KUW0 Key Wrap Unwrap Register 0 (KUW0) Register
 *  Key Wrap Unwrap Register 0 (KUW0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW0_Struct
 *! \brief  Key Wrap Unwrap Register 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW0_t__
typedef struct _ADI_CRYPT_KUW0_t {
  union {
    struct {
      uint32_t KUW0       : 32;  /**< KUW [31:0] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW0_t__ */

/*@}*/

/** @defgroup KUW1 Key Wrap Unwrap Register 1 (KUW1) Register
 *  Key Wrap Unwrap Register 1 (KUW1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW1_Struct
 *! \brief  Key Wrap Unwrap Register 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW1_t__
typedef struct _ADI_CRYPT_KUW1_t {
  union {
    struct {
      uint32_t KUW1       : 32;  /**< KUW [63:32] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW1_t__ */

/*@}*/

/** @defgroup KUW2 Key Wrap Unwrap Register 2 (KUW2) Register
 *  Key Wrap Unwrap Register 2 (KUW2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW2_Struct
 *! \brief  Key Wrap Unwrap Register 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW2_t__
typedef struct _ADI_CRYPT_KUW2_t {
  union {
    struct {
      uint32_t KUW2       : 32;  /**< KUW [95:64] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW2_t__ */

/*@}*/

/** @defgroup KUW3 Key Wrap Unwrap Register 3 (KUW3) Register
 *  Key Wrap Unwrap Register 3 (KUW3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW3_Struct
 *! \brief  Key Wrap Unwrap Register 3 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW3_t__
typedef struct _ADI_CRYPT_KUW3_t {
  union {
    struct {
      uint32_t KUW3       : 32;  /**< KUW [127:96] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW3_t__ */

/*@}*/

/** @defgroup KUW4 Key Wrap Unwrap Register 4 (KUW4) Register
 *  Key Wrap Unwrap Register 4 (KUW4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW4_Struct
 *! \brief  Key Wrap Unwrap Register 4 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW4_t__
typedef struct _ADI_CRYPT_KUW4_t {
  union {
    struct {
      uint32_t KUW4       : 32;  /**< KUW [159:128] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW4_t__ */

/*@}*/

/** @defgroup KUW5 Key Wrap Unwrap Register 5 (KUW5) Register
 *  Key Wrap Unwrap Register 5 (KUW5) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW5_Struct
 *! \brief  Key Wrap Unwrap Register 5 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW5_t__
typedef struct _ADI_CRYPT_KUW5_t {
  union {
    struct {
      uint32_t KUW5       : 32;  /**< KUW [191:160] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW5_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW5_t__ */

/*@}*/

/** @defgroup KUW6 Key Wrap Unwrap Register 6 (KUW6) Register
 *  Key Wrap Unwrap Register 6 (KUW6) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW6_Struct
 *! \brief  Key Wrap Unwrap Register 6 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW6_t__
typedef struct _ADI_CRYPT_KUW6_t {
  union {
    struct {
      uint32_t KUW6       : 32;  /**< KUW [223:192] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW6_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW6_t__ */

/*@}*/

/** @defgroup KUW7 Key Wrap Unwrap Register 7 (KUW7) Register
 *  Key Wrap Unwrap Register 7 (KUW7) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW7_Struct
 *! \brief  Key Wrap Unwrap Register 7 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW7_t__
typedef struct _ADI_CRYPT_KUW7_t {
  union {
    struct {
      uint32_t KUW7       : 32;  /**< KUW [255:224] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW7_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW7_t__ */

/*@}*/

/** @defgroup KUW8 Key Wrap Unwrap Register 8 (KUW8) Register
 *  Key Wrap Unwrap Register 8 (KUW8) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW8_Struct
 *! \brief  Key Wrap Unwrap Register 8 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW8_t__
typedef struct _ADI_CRYPT_KUW8_t {
  union {
    struct {
      uint32_t KUW8       : 32;  /**< KUW [287:256] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW8_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW8_t__ */

/*@}*/

/** @defgroup KUW9 Key Wrap Unwrap Register 9 (KUW9) Register
 *  Key Wrap Unwrap Register 9 (KUW9) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW9_Struct
 *! \brief  Key Wrap Unwrap Register 9 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW9_t__
typedef struct _ADI_CRYPT_KUW9_t {
  union {
    struct {
      uint32_t KUW9       : 32;  /**< KUW [319:288] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW9_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW9_t__ */

/*@}*/

/** @defgroup KUW10 Key Wrap Unwrap Register 10 (KUW10) Register
 *  Key Wrap Unwrap Register 10 (KUW10) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW10_Struct
 *! \brief  Key Wrap Unwrap Register 10 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW10_t__
typedef struct _ADI_CRYPT_KUW10_t {
  union {
    struct {
      uint32_t KUW10      : 32;  /**< KUW [351:320] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW10_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW10_t__ */

/*@}*/

/** @defgroup KUW11 Key Wrap Unwrap Register 11 (KUW11) Register
 *  Key Wrap Unwrap Register 11 (KUW11) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW11_Struct
 *! \brief  Key Wrap Unwrap Register 11 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW11_t__
typedef struct _ADI_CRYPT_KUW11_t {
  union {
    struct {
      uint32_t KUW11      : 32;  /**< KUW [383:352] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW11_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW11_t__ */

/*@}*/

/** @defgroup KUW12 Key Wrap Unwrap Register 12 (KUW12) Register
 *  Key Wrap Unwrap Register 12 (KUW12) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW12_Struct
 *! \brief  Key Wrap Unwrap Register 12 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW12_t__
typedef struct _ADI_CRYPT_KUW12_t {
  union {
    struct {
      uint32_t KUW12      : 32;  /**< KUW [415:384] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW12_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW12_t__ */

/*@}*/

/** @defgroup KUW13 Key Wrap Unwrap Register 13 (KUW13) Register
 *  Key Wrap Unwrap Register 13 (KUW13) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW13_Struct
 *! \brief  Key Wrap Unwrap Register 13 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW13_t__
typedef struct _ADI_CRYPT_KUW13_t {
  union {
    struct {
      uint32_t KUW13      : 32;  /**< KUW [447:416] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW13_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW13_t__ */

/*@}*/

/** @defgroup KUW14 Key Wrap Unwrap Register 14 (KUW14) Register
 *  Key Wrap Unwrap Register 14 (KUW14) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW14_Struct
 *! \brief  Key Wrap Unwrap Register 14 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW14_t__
typedef struct _ADI_CRYPT_KUW14_t {
  union {
    struct {
      uint32_t KUW14      : 32;  /**< KUW [479:448] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW14_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW14_t__ */

/*@}*/

/** @defgroup KUW15 Key Wrap Unwrap Register 15 (KUW15) Register
 *  Key Wrap Unwrap Register 15 (KUW15) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUW15_Struct
 *! \brief  Key Wrap Unwrap Register 15 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW15_t__
typedef struct _ADI_CRYPT_KUW15_t {
  union {
    struct {
      uint32_t KUW15      : 32;  /**< KUW [511:480] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUW15_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUW15_t__ */

/*@}*/

/** @defgroup KUWValStr1 Key Wrap Unwrap Validation String [63:32] (KUWValStr1) Register
 *  Key Wrap Unwrap Validation String [63:32] (KUWValStr1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUWValStr1_Struct
 *! \brief  Key Wrap Unwrap Validation String [63:32] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUWValStr1_t__
typedef struct _ADI_CRYPT_KUWValStr1_t {
  union {
    struct {
      uint32_t InitialValue0 : 32;  /**< Initial Value */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUWValStr1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUWValStr1_t__ */

/*@}*/

/** @defgroup KUWValStr2 Key Wrap Unwrap Validation String [31:0] (KUWValStr2) Register
 *  Key Wrap Unwrap Validation String [31:0] (KUWValStr2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_KUWValStr2_Struct
 *! \brief  Key Wrap Unwrap Validation String [31:0] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_KUWValStr2_t__
typedef struct _ADI_CRYPT_KUWValStr2_t {
  union {
    struct {
      uint32_t InitialValue1 : 32;  /**< Initial Value */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_KUWValStr2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_KUWValStr2_t__ */

/*@}*/

/** @defgroup IEN Power Supply Monitor Interrupt Enable (IEN) Register
 *  Power Supply Monitor Interrupt Enable (IEN) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_PMG_IEN_RANGEBAT
 *! \brief  Battery Monitor Range (RANGEBAT) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_IEN_REGION1 = 0,  /**< Configure to generate interrupt if VBAT in Region1 */
  PMG_IEN_REGION2 = 1,  /**< Configure to generate interrupt if VBAT in Region2 */
  PMG_IEN_REGION3 = 2,  /**< Configure to generate interrupt if VBAT in Region3 */
  PMG_IEN_NA      = 3   /**< NA                                                 */
} ADI_PMG_IEN_RANGEBAT;


/* ==========================================================================
 *! \struct ADI_PMG_IEN_Struct
 *! \brief  Power Supply Monitor Interrupt Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_IEN_t__
typedef struct _ADI_PMG_IEN_t {
  union {
    struct {
      uint32_t VBAT       :  1;  /**< Enable Interrupt for VBAT */
      uint32_t VREGUNDR   :  1;  /**< Enable Interrupt When VREG Under Voltage (Below 1V) */
      uint32_t VREGOVR    :  1;  /**< Enable Interrupt When VREG Over Voltage (Above 1.32V) */
      uint32_t reserved3  :  5;
      uint32_t RANGEBAT   :  2;  /**< Battery Monitor Range */
      uint32_t IENBAT     :  1;  /**< Interrupt Enable for VBAT Range */
      uint32_t reserved11 : 21;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_IEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_IEN_t__ */

/*@}*/

/** @defgroup PSM_STAT Power Supply Monitor Status (PSM_STAT) Register
 *  Power Supply Monitor Status (PSM_STAT) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_PMG_PSM_STAT_RORANGE1
 *! \brief  VBAT Range1 (RORANGE1) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_PSM_STAT_BATSTAT1 = 0,  /**< VBAT NOT in the range specified */
  PMG_PSM_STAT_BATSTAT0 = 1   /**< VBAT in the range specified     */
} ADI_PMG_PSM_STAT_RORANGE1;


/* ==========================================================================
 *! \struct ADI_PMG_PSM_STAT_Struct
 *! \brief  Power Supply Monitor Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_PSM_STAT_t__
typedef struct _ADI_PMG_PSM_STAT_t {
  union {
    struct {
      uint32_t VBATUNDR   :  1;  /**< Status Bit Indicating an Alarm That Battery is Below 1.8V */
      uint32_t VREGUNDR   :  1;  /**< Status Bit for Alarm Indicating VREG is Below 1V */
      uint32_t VREGOVR    :  1;  /**< Status Bit for Alarm Indicating Over Voltage for VREG */
      uint32_t reserved3  :  4;
      uint32_t WICENACK   :  1;  /**< WIC Enable Acknowledge from Cortex */
      uint32_t RANGE1     :  1;  /**< VBAT Range1 */
      uint32_t RANGE2     :  1;  /**< VBAT Range2 */
      uint32_t RANGE3     :  1;  /**< VBAT Range3 */
      uint32_t reserved11 :  2;
      uint32_t RORANGE1   :  1;  /**< VBAT Range1 */
      uint32_t RORANGE2   :  1;  /**< VBAT Range2 */
      uint32_t RORANGE3   :  1;  /**< VBAT Range3 */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_PSM_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_PSM_STAT_t__ */

/*@}*/

/** @defgroup PWRMOD Power Mode Register (PWRMOD) Register
 *  Power Mode Register (PWRMOD) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_PMG_PWRMOD_MODE
 *! \brief  Power Mode Bits (MODE) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_PWRMOD_FLEXI     = 0,  /**< Flexi Mode     */
  PMG_PWRMOD_HIBERNATE = 2,  /**< Hibernate Mode */
  PMG_PWRMOD_SHUTDOWN  = 3   /**< Shutdown Mode  */
} ADI_PMG_PWRMOD_MODE;


/*  =========================================================================
 *! \enum   ADI_PMG_PWRMOD_MONVBATN
 *! \brief  Monitor VBAT During Hibernate Mode (MONVBATN) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_PWRMOD_MONITOR_EN  = 0,  /**< VBAT monitor enabled in PMG block  */
  PMG_PWRMOD_MONITOR_DIS = 1   /**< VBAT monitor disabled in PMG block */
} ADI_PMG_PWRMOD_MONVBATN;


/* ==========================================================================
 *! \struct ADI_PMG_PWRMOD_Struct
 *! \brief  Power Mode Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_PWRMOD_t__
typedef struct _ADI_PMG_PWRMOD_t {
  union {
    struct {
      uint32_t MODE       :  2;  /**< Power Mode Bits */
      uint32_t reserved2  :  1;
      uint32_t MONVBATN   :  1;  /**< Monitor VBAT During Hibernate Mode */
      uint32_t reserved4  : 28;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_PWRMOD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_PWRMOD_t__ */

/*@}*/

/** @defgroup PWRKEY Key Protection for PMG_PWRMOD and PMG_SRAMRET (PWRKEY) Register
 *  Key Protection for PMG_PWRMOD and PMG_SRAMRET (PWRKEY) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_PWRKEY_Struct
 *! \brief  Key Protection for PMG_PWRMOD and PMG_SRAMRET Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_PWRKEY_t__
typedef struct _ADI_PMG_PWRKEY_t {
  union {
    struct {
      uint32_t VALUE      : 16;  /**< Power Control Key */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_PWRKEY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_PWRKEY_t__ */

/*@}*/

/** @defgroup SHDN_STAT Shutdown Status Register (SHDN_STAT) Register
 *  Shutdown Status Register (SHDN_STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_SHDN_STAT_Struct
 *! \brief  Shutdown Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_SHDN_STAT_t__
typedef struct _ADI_PMG_SHDN_STAT_t {
  union {
    struct {
      uint32_t EXTINT0    :  1;  /**< Interrupt from External Interrupt 0 */
      uint32_t EXTINT1    :  1;  /**< Interrupt from External Interrupt 1 */
      uint32_t EXTINT2    :  1;  /**< Interrupt from External Interrupt 2 */
      uint32_t RTC        :  1;  /**< Interrupt from RTC */
      uint32_t reserved4  : 28;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_SHDN_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_SHDN_STAT_t__ */

/*@}*/

/** @defgroup SRAMRET Control for Retention SRAM in Hibernate Mode (SRAMRET) Register
 *  Control for Retention SRAM in Hibernate Mode (SRAMRET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_SRAMRET_Struct
 *! \brief  Control for Retention SRAM in Hibernate Mode Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_SRAMRET_t__
typedef struct _ADI_PMG_SRAMRET_t {
  union {
    struct {
      uint32_t RET1       :  1;  /**< Enable Retention Bank 1 (12 KB) */
      uint32_t RET2       :  1;  /**< Enable Retention Bank 3 and Bank 4 (32 KB) */
      uint32_t reserved2  :  6;
      uint32_t RET3       :  1;  /**< Enable Retention Bank 5 (32 KB) */
      uint32_t RET4       :  1;  /**< Enable Retention Bank 6 and Bank 7 (32 KB) */
      uint32_t reserved10               : 13;
      uint32_t HIBERNATE_SRAM_LOAD_MODE :  1;  /**< Hibernate Mode SRAM Load Mode Control */
      uint32_t reserved24               :  8;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_SRAMRET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_SRAMRET_t__ */

/*@}*/

/** @defgroup TRIM Trimming Bits (TRIM) Register
 *  Trimming Bits (TRIM) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_PMG_TRIM_hibernate_load_mode
 *! \brief  Hibernate Mode Load Mode Control (hibernate_load_mode) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_TRIM_HIGH_LOAD = 0,  /**< High hibernate load */
  PMG_TRIM_LOW_LOAD  = 7   /**< Low hibernate load  */
} ADI_PMG_TRIM_hibernate_load_mode;


/* ==========================================================================
 *! \struct ADI_PMG_TRIM_Struct
 *! \brief  Trimming Bits Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_TRIM_t__
typedef struct _ADI_PMG_TRIM_t {
  union {
    struct {
      uint32_t reserved0           : 29;
      uint32_t hibernate_load_mode :  3;  /**< Hibernate Mode Load Mode Control */
    };
    uint32_t VALUE32;
  };
} ADI_PMG_TRIM_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_TRIM_t__ */

/*@}*/

/** @defgroup RST_STAT Reset Status (RST_STAT) Register
 *  Reset Status (RST_STAT) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_PMG_RST_STAT_PORSRC
 *! \brief  Power on Reset Source (PORSRC) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_RST_STAT_FAILSAFE_HV = 0,  /**< POR triggered because VBAT drops below Fail Safe */
  PMG_RST_STAT_RST_VBAT    = 1,  /**< POR trigger because VBAT supply (VBAT < 1.7 V)   */
  PMG_RST_STAT_RST_VREG    = 2,  /**< POR triggered because VDD supply (VDD < 1.08 V)  */
  PMG_RST_STAT_FAILSAFE_LV = 3   /**< POR triggered because VREG drops below Fail Safe */
} ADI_PMG_RST_STAT_PORSRC;


/* ==========================================================================
 *! \struct ADI_PMG_RST_STAT_Struct
 *! \brief  Reset Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_RST_STAT_t__
typedef struct _ADI_PMG_RST_STAT_t {
  union {
    struct {
      uint32_t POR        :  1;  /**< Power-on Reset */
      uint32_t EXTRST     :  1;  /**< External Reset */
      uint32_t WDRST      :  1;  /**< Watchdog Timeout */
      uint32_t SWRST      :  1;  /**< Software Reset */
      uint32_t PORSRC     :  2;  /**< Power on Reset Source */
      uint32_t reserved6  : 26;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_RST_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_RST_STAT_t__ */

/*@}*/

/** @defgroup CTL1 HPBUCK Control (CTL1) Register
 *  HPBUCK Control (CTL1) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_PMG_CTL1_HPBUCK_LD_MODE
 *! \brief  HP Buck Load Mode (HPBUCK_LD_MODE) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_CTL1_HPBUCKLOWLOAD  = 0,  /**< HPBUCK Low load mode is enabled  */
  PMG_CTL1_HPBUCKHIGHLOAD = 1   /**< HPBUCK High load mode is enabled */
} ADI_PMG_CTL1_HPBUCK_LD_MODE;


/*  =========================================================================
 *! \enum   ADI_PMG_CTL1_HPBUCK_LOWPWR_MODE
 *! \brief  HP Buck Low Power Mode (HPBUCK_LOWPWR_MODE) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_CTL1_LOWPWRDISABLE = 0,  /**< HPBUCK Low power mode is disabled */
  PMG_CTL1_LOWPWRENABLE  = 1   /**< HPBUCK Low power mode is enabled  */
} ADI_PMG_CTL1_HPBUCK_LOWPWR_MODE;


/* ==========================================================================
 *! \struct ADI_PMG_CTL1_Struct
 *! \brief  HPBUCK Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_CTL1_t__
typedef struct _ADI_PMG_CTL1_t {
  union {
    struct {
      uint32_t HPBUCKEN   :  1;  /**< Enable HP Buck */
      uint32_t HPBUCK_LD_MODE :  1;  /**< HP Buck Load Mode */
      uint32_t HPBUCK_LOWPWR_MODE :  1;  /**< HP Buck Low Power Mode */
      uint32_t reserved3          : 29;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_CTL1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_CTL1_t__ */

/*@}*/

/** @defgroup CFG0 External Interrupt Configuration (CFG0) Register
 *  External Interrupt Configuration (CFG0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_XINT_CFG0_Struct
 *! \brief  External Interrupt Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_XINT_CFG0_t__
typedef struct _ADI_XINT_CFG0_t {
  union {
    struct {
      uint32_t IRQ0MDE    :  3;  /**< External Interrupt 0 Mode Registers */
      uint32_t IRQ0EN     :  1;  /**< External Interrupt 0 Enable */
      uint32_t IRQ1MDE    :  3;  /**< External Interrupt 1 Mode Registers */
      uint32_t IRQ1EN     :  1;  /**< External Interrupt 1 Enable */
      uint32_t IRQ2MDE    :  3;  /**< External Interrupt 2 Mode Registers */
      uint32_t IRQ2EN     :  1;  /**< External Interrupt 2 Enable */
      uint32_t IRQ3MDE    :  3;  /**< External Interrupt 3 Mode Registers */
      uint32_t IRQ3EN     :  1;  /**< External Interrupt 3 Enable */
      uint32_t reserved16 :  4;
      uint32_t UART_RX_EN :  1;  /**< External Interrupt Using UART_RX Enable Bit */
      uint32_t UART_RX_MDE :  3;  /**< External Interrupt Using UART_RX Wakeup Mode Registers */
      uint32_t reserved24  :  8;
    };
    uint32_t VALUE32;
  };
} ADI_XINT_CFG0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_XINT_CFG0_t__ */

/*@}*/

/** @defgroup EXT_STAT External Wakeup Interrupt Status (EXT_STAT) Register
 *  External Wakeup Interrupt Status (EXT_STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_XINT_EXT_STAT_Struct
 *! \brief  External Wakeup Interrupt Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_XINT_EXT_STAT_t__
typedef struct _ADI_XINT_EXT_STAT_t {
  union {
    struct {
      uint32_t STAT_EXTINT0 :  1;  /**< Interrupt Status Bit for External Interrupt 0 */
      uint32_t STAT_EXTINT1 :  1;  /**< Interrupt Status Bit for External Interrupt 1 */
      uint32_t STAT_EXTINT2 :  1;  /**< Interrupt Status Bit for External Interrupt 2 */
      uint32_t STAT_EXTINT3 :  1;  /**< Interrupt Status Bit for External Interrupt 3 */
      uint32_t reserved4        :  1;
      uint32_t STAT_UART_RXWKUP :  1;  /**< Interrupt Status Bit for UART RX WAKEUP Interrupt */
      uint32_t reserved6        : 26;
    };
    uint32_t VALUE32;
  };
} ADI_XINT_EXT_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_XINT_EXT_STAT_t__ */

/*@}*/

/** @defgroup CLR External Interrupt Clear (CLR) Register
 *  External Interrupt Clear (CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_XINT_CLR_Struct
 *! \brief  External Interrupt Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_XINT_CLR_t__
typedef struct _ADI_XINT_CLR_t {
  union {
    struct {
      uint32_t IRQ0       :  1;  /**< External Interrupt 0 */
      uint32_t IRQ1       :  1;  /**< External Interrupt 1 */
      uint32_t IRQ2       :  1;  /**< External Interrupt 2 */
      uint32_t IRQ3       :  1;  /**< External Interrupt 3 */
      uint32_t reserved4   :  1;
      uint32_t UART_RX_CLR :  1;  /**< External Interrupt Clear for UART_RX WAKEUP Interrupt */
      uint32_t reserved6   : 26;
    };
    uint32_t VALUE32;
  };
} ADI_XINT_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_XINT_CLR_t__ */

/*@}*/

/** @defgroup NMICLR Non-maskable Interrupt Clear (NMICLR) Register
 *  Non-maskable Interrupt Clear (NMICLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_XINT_NMICLR_Struct
 *! \brief  Non-maskable Interrupt Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_XINT_NMICLR_t__
typedef struct _ADI_XINT_NMICLR_t {
  union {
    struct {
      uint32_t CLR        :  1;  /**< NMI Clear */
      uint32_t reserved1  : 31;
    };
    uint32_t VALUE32;
  };
} ADI_XINT_NMICLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_XINT_NMICLR_t__ */

/*@}*/

/** @defgroup KEY Key Protection for OSCCTRL (KEY) Register
 *  Key Protection for OSCCTRL (KEY) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CLKG_OSC_KEY_Struct
 *! \brief  Key Protection for OSCCTRL Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_OSC_KEY_t__
typedef struct _ADI_CLKG_OSC_KEY_t {
  union {
    struct {
      uint32_t VALUE      : 16;  /**< Oscillator key */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_CLKG_OSC_KEY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_OSC_KEY_t__ */

/*@}*/

/** @defgroup CTL Oscillator Control (CTL) Register
 *  Oscillator Control (CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CLKG_OSC_CTL_Struct
 *! \brief  Oscillator Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_OSC_CTL_t__
typedef struct _ADI_CLKG_OSC_CTL_t {
  union {
    struct {
      uint32_t LFCLK_MUX  :  1;  /**< 32 kHz clock select mux */
      uint32_t HFOSC_EN   :  1;  /**< High frequency internal oscillator enable */
      uint32_t LFX_EN     :  1;  /**< Low frequency crystal oscillator enable */
      uint32_t HFX_EN     :  1;  /**< High frequency crystal oscillator enable */
      uint32_t LFX_BYP    :  1;  /**< Low frequency crystal oscillator Bypass */
      uint32_t LFX_MON_EN :  1;  /**< LFXTAL clock monitor and Clock FAIL interrupt enable */
      uint32_t reserved6  :  2;
      uint32_t LFOSC_OK   :  1;  /**< Status of LFOSC oscillator */
      uint32_t HFOSC_OK   :  1;  /**< Status of HFOSC oscillator */
      uint32_t LFX_OK     :  1;  /**< Status of LFXTAL oscillator */
      uint32_t HFX_OK     :  1;  /**< Status of HFXTAL oscillator */
      uint32_t LFX_AUTSW_EN :  1;  /**< Enables automatic Switching of the LF Mux to LFOSC on LFXTAL Failure */
      uint32_t LFX_AUTSW_STA :  1;  /**< Status of automatic switching of the LF Mux to LFOSC upon detection of LFXTAL failure */
      uint32_t LFX_ROBUST_EN :  1;  /**< LFXTAL Mode select */
      uint32_t LFX_ROBUST_LD :  2;  /**< LFXTAL Robust Mode Load select */
      uint32_t reserved17    :  3;
      uint32_t ROOT_MON_EN   :  1;  /**< ROOT clock monitor and Clock FAIL interrupt enable */
      uint32_t ROOT_AUTSW_EN :  1;  /**< Enables automatic Switching of the Root clock  to HFOSC on Root clock Failure */
      uint32_t ROOT_AUTSW_STA :  1;  /**< Status of automatic switching of the Root clock to HFOSC upon detection of Root clock failure */
      uint32_t reserved23     :  7;
      uint32_t ROOT_FAIL_STA  :  1;  /**< Root clock (crystal clock) Not Stable */
      uint32_t LFX_FAIL_STA   :  1;  /**< LF XTAL (crystal clock) Not Stable */
    };
    uint32_t VALUE32;
  };
} ADI_CLKG_OSC_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_OSC_CTL_t__ */

/*@}*/

/** @defgroup SRAM_CTL Control for SRAM Parity and Instruction SRAM (SRAM_CTL) Register
 *  Control for SRAM Parity and Instruction SRAM (SRAM_CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_TST_SRAM_CTL_Struct
 *! \brief  Control for SRAM Parity and Instruction SRAM Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_TST_SRAM_CTL_t__
typedef struct _ADI_PMG_TST_SRAM_CTL_t {
  union {
    struct {
      uint32_t reserved0  :  1;
      uint32_t BNK1EN     :  1;  /**< Enable Initialization */
      uint32_t BNK2EN     :  1;  /**< Enable Initialization */
      uint32_t reserved3  :  4;
      uint32_t BNK7EN     :  1;  /**< Enable Initialization */
      uint32_t reserved8  :  5;
      uint32_t STARTINIT  :  1;  /**< Start Manual Initialization */
      uint32_t AUTOINIT   :  1;  /**< Automatic Initialization on Wake up from Hibernate Mode */
      uint32_t ABTINIT    :  1;  /**< Abort Current Initialization. Self-cleared */
      uint32_t PENBNK0    :  1;  /**< Enable Parity Check */
      uint32_t PENBNK1    :  1;  /**< Enable Parity Check */
      uint32_t PENBNK2    :  1;  /**< Enable Parity Check */
      uint32_t PENBNK3    :  1;  /**< Enable Parity Check */
      uint32_t PENBNK4    :  1;  /**< Enable Parity Check */
      uint32_t PENBNK5    :  1;  /**< Enable Parity Check */
      uint32_t PENBNK6    :  1;  /**< Enable Parity Check */
      uint32_t PENBNK7    :  1;  /**< Enable Parity Check */
      uint32_t reserved24 :  7;
      uint32_t INSTREN    :  1;  /**< Enables 32kB Instruction SRAM */
    };
    uint32_t VALUE32;
  };
} ADI_PMG_TST_SRAM_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_TST_SRAM_CTL_t__ */

/*@}*/

/** @defgroup SRAM_INITSTAT Initialization Status Register (SRAM_INITSTAT) Register
 *  Initialization Status Register (SRAM_INITSTAT) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_PMG_TST_SRAM_INITSTAT_BNK0DONE
 *! \brief  Bank 0 Initialization Status (BNK0DONE) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_TST_SRAM_INITSTAT_NO_BANK0_INIT = 0,  /**< Bank 0 not initialized */
  PMG_TST_SRAM_INITSTAT_BANK0_INIT    = 1   /**< Bank 0 initialized     */
} ADI_PMG_TST_SRAM_INITSTAT_BNK0DONE;


/*  =========================================================================
 *! \enum   ADI_PMG_TST_SRAM_INITSTAT_BNK1DONE
 *! \brief  Bank 1 Initialization Status (BNK1DONE) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_TST_SRAM_INITSTAT_NO_BANK1_INIT = 0,  /**< Bank 1 not initialized */
  PMG_TST_SRAM_INITSTAT_BANK1_INIT    = 1   /**< Bank 1 initialized     */
} ADI_PMG_TST_SRAM_INITSTAT_BNK1DONE;


/*  =========================================================================
 *! \enum   ADI_PMG_TST_SRAM_INITSTAT_BNK2DONE
 *! \brief  Bank 2 Initialization Status (BNK2DONE) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_TST_SRAM_INITSTAT_NO_BANK2_INIT = 0,  /**< Bank 2 not initialized */
  PMG_TST_SRAM_INITSTAT_BANK2_INIT    = 1   /**< Bank 2 initialized     */
} ADI_PMG_TST_SRAM_INITSTAT_BNK2DONE;


/*  =========================================================================
 *! \enum   ADI_PMG_TST_SRAM_INITSTAT_BNK3DONE
 *! \brief  Bank 3 Initialization Status (BNK3DONE) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_TST_SRAM_INITSTAT_NO_BANK3_INIT = 0,  /**< Bank 3 not initialized */
  PMG_TST_SRAM_INITSTAT_BANK3_INIT    = 1   /**< Bank 3 initialized     */
} ADI_PMG_TST_SRAM_INITSTAT_BNK3DONE;


/*  =========================================================================
 *! \enum   ADI_PMG_TST_SRAM_INITSTAT_BNK4DONE
 *! \brief  Bank 4 Initialization Status (BNK4DONE) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_TST_SRAM_INITSTAT_NO_BANK4_INIT = 0,  /**< Bank 4 not initialized */
  PMG_TST_SRAM_INITSTAT_BANK4_INIT    = 1   /**< Bank 4 initialized     */
} ADI_PMG_TST_SRAM_INITSTAT_BNK4DONE;


/*  =========================================================================
 *! \enum   ADI_PMG_TST_SRAM_INITSTAT_BNK5DONE
 *! \brief  Bank 5 Initialization Status (BNK5DONE) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_TST_SRAM_INITSTAT_NO_BANK5_INIT = 0,  /**< Bank 5 not initialized */
  PMG_TST_SRAM_INITSTAT_BANK5_INIT    = 1   /**< Bank 5 initialized     */
} ADI_PMG_TST_SRAM_INITSTAT_BNK5DONE;


/*  =========================================================================
 *! \enum   ADI_PMG_TST_SRAM_INITSTAT_BNK6DONE
 *! \brief  Bank 6 Initialization Status (BNK6DONE) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_TST_SRAM_INITSTAT_NO_BANK6_INIT = 0,  /**< Bank 6 not initialized */
  PMG_TST_SRAM_INITSTAT_BANK6_INIT    = 1   /**< Bank 6 initialized     */
} ADI_PMG_TST_SRAM_INITSTAT_BNK6DONE;


/*  =========================================================================
 *! \enum   ADI_PMG_TST_SRAM_INITSTAT_BNK7DONE
 *! \brief  Bank 7 Initialization Status (BNK7DONE) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_TST_SRAM_INITSTAT_NO_BANK7_INIT = 0,  /**< Bank 7 not initialized */
  PMG_TST_SRAM_INITSTAT_BANK7_INIT    = 1   /**< Bank 7 initialized     */
} ADI_PMG_TST_SRAM_INITSTAT_BNK7DONE;


/* ==========================================================================
 *! \struct ADI_PMG_TST_SRAM_INITSTAT_Struct
 *! \brief  Initialization Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_TST_SRAM_INITSTAT_t__
typedef struct _ADI_PMG_TST_SRAM_INITSTAT_t {
  union {
    struct {
      uint32_t BNK0DONE   :  1;  /**< Bank 0 Initialization Status */
      uint32_t BNK1DONE   :  1;  /**< Bank 1 Initialization Status */
      uint32_t BNK2DONE   :  1;  /**< Bank 2 Initialization Status */
      uint32_t BNK3DONE   :  1;  /**< Bank 3 Initialization Status */
      uint32_t BNK4DONE   :  1;  /**< Bank 4 Initialization Status */
      uint32_t BNK5DONE   :  1;  /**< Bank 5 Initialization Status */
      uint32_t BNK6DONE   :  1;  /**< Bank 6 Initialization Status */
      uint32_t BNK7DONE   :  1;  /**< Bank 7 Initialization Status */
      uint32_t reserved8  : 24;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_TST_SRAM_INITSTAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_TST_SRAM_INITSTAT_t__ */

/*@}*/

/** @defgroup CLR_LATCH_GPIOS Clear GPIO After Shutdown Mode (CLR_LATCH_GPIOS) Register
 *  Clear GPIO After Shutdown Mode (CLR_LATCH_GPIOS) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_TST_CLR_LATCH_GPIOS_Struct
 *! \brief  Clear GPIO After Shutdown Mode Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_TST_CLR_LATCH_GPIOS_t__
typedef struct _ADI_PMG_TST_CLR_LATCH_GPIOS_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Clear the Latches for GPIOs */
    };
    uint16_t VALUE16;
  };
} ADI_PMG_TST_CLR_LATCH_GPIOS_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_TST_CLR_LATCH_GPIOS_t__ */

/*@}*/

/** @defgroup SCRPAD_IMG Scratch Pad Image (SCRPAD_IMG) Register
 *  Scratch Pad Image (SCRPAD_IMG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_TST_SCRPAD_IMG_Struct
 *! \brief  Scratch Pad Image Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_TST_SCRPAD_IMG_t__
typedef struct _ADI_PMG_TST_SCRPAD_IMG_t {
  union {
    struct {
      uint32_t DATA       : 32;  /**< Scratch Image */
    };
    uint32_t VALUE32;
  };
} ADI_PMG_TST_SCRPAD_IMG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_TST_SCRPAD_IMG_t__ */

/*@}*/

/** @defgroup SCRPAD_3V_RD Scratch Pad Saved in Battery Domain (SCRPAD_3V_RD) Register
 *  Scratch Pad Saved in Battery Domain (SCRPAD_3V_RD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_TST_SCRPAD_3V_RD_Struct
 *! \brief  Scratch Pad Saved in Battery Domain Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_TST_SCRPAD_3V_RD_t__
typedef struct _ADI_PMG_TST_SCRPAD_3V_RD_t {
  union {
    struct {
      uint32_t DATA       : 32;  /**< Reading the Scratch Pad Stored in Shutdown Mode */
    };
    uint32_t VALUE32;
  };
} ADI_PMG_TST_SCRPAD_3V_RD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_TST_SCRPAD_3V_RD_t__ */

/*@}*/

/** @defgroup FAST_SHT_WAKEUP Fast Shutdown Wake-up Enable (FAST_SHT_WAKEUP) Register
 *  Fast Shutdown Wake-up Enable (FAST_SHT_WAKEUP) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_PMG_TST_FAST_SHT_WAKEUP_FAST_SHT_WAKEUP
 *! \brief  Enables Fast Shutdown Wake-up (FAST_SHT_WAKEUP) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_TST_FAST_SHT_WAKEUP_FASTWAKE_DIS = 0,  /**< Fast shutdown wakeup is disabled */
  PMG_TST_FAST_SHT_WAKEUP_FASTWAKE_EN  = 1   /**< Fast shutdown wakeup is enabled  */
} ADI_PMG_TST_FAST_SHT_WAKEUP_FAST_SHT_WAKEUP;


/* ==========================================================================
 *! \struct ADI_PMG_TST_FAST_SHT_WAKEUP_Struct
 *! \brief  Fast Shutdown Wake-up Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_TST_FAST_SHT_WAKEUP_t__
typedef struct _ADI_PMG_TST_FAST_SHT_WAKEUP_t {
  union {
    struct {
      uint32_t FAST_SHT_WAKEUP :  1;  /**< Enables Fast Shutdown Wake-up */
      uint32_t reserved1       : 31;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_TST_FAST_SHT_WAKEUP_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_TST_FAST_SHT_WAKEUP_t__ */

/*@}*/

/** @defgroup CTL0 Misc Clock Settings (CTL0) Register
 *  Misc Clock Settings (CTL0) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_CLKG_CLK_CTL0_PLL_IPSEL
 *! \brief  SPLL source select mux (PLL_IPSEL) Enumerations
 *  ========================================================================= */
typedef enum
{
  CLKG_CLK_CTL0_PLL_HFOSC  = 0,  /**< Internal HF oscillator is selected      */
  CLKG_CLK_CTL0_PLL_HFXTAL = 1,  /**< External HF XTAL oscillator is selected */
  CLKG_CLK_CTL0_PLL_GPIO   = 2,  /**< GPIO_CLK input is selected              */
  CLKG_CLK_CTL0_PLL_GPIO1  = 3   /**< GPIO_CLK input is selected              */
} ADI_CLKG_CLK_CTL0_PLL_IPSEL;


/* ==========================================================================
 *! \struct ADI_CLKG_CLK_CTL0_Struct
 *! \brief  Misc Clock Settings Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL0_t__
typedef struct _ADI_CLKG_CLK_CTL0_t {
  union {
    struct {
      uint32_t CLKMUX     :  2;  /**< Clock mux select */
      uint32_t reserved2  :  1;
      uint32_t CLKOUT     :  4;  /**< GPIO clock out select */
      uint32_t reserved7  :  1;
      uint32_t RCLKMUX    :  2;  /**< Flash reference clock and HPBUCK clock source mux */
      uint32_t reserved10 :  1;
      uint32_t PLL_IPSEL  :  2;  /**< SPLL source select mux */
      uint32_t reserved13 :  1;
      uint32_t LFXTALIE   :  1;  /**< Low frequency crystal interrupt enable */
      uint32_t HFXTALIE   :  1;  /**< High frequency crystal interrupt enable */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_CLKG_CLK_CTL0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL0_t__ */

/*@}*/

/** @defgroup CTL1 Clock Dividers (CTL1) Register
 *  Clock Dividers (CTL1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CLKG_CLK_CTL1_Struct
 *! \brief  Clock Dividers Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL1_t__
typedef struct _ADI_CLKG_CLK_CTL1_t {
  union {
    struct {
      uint32_t HCLKDIVCNT :  6;  /**< HCLK divide count */
      uint32_t reserved6  :  2;
      uint32_t PCLKDIVCNT :  6;  /**< PCLK divide count */
      uint32_t reserved14 :  2;
      uint32_t ACLKDIVCNT :  9;  /**< ACLK Divide Count */
      uint32_t reserved25 :  7;
    };
    uint32_t VALUE32;
  };
} ADI_CLKG_CLK_CTL1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL1_t__ */

/*@}*/

/** @defgroup CTL2 HF Oscillator Divided Clock Select (CTL2) Register
 *  HF Oscillator Divided Clock Select (CTL2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CLKG_CLK_CTL2_Struct
 *! \brief  HF Oscillator Divided Clock Select Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL2_t__
typedef struct _ADI_CLKG_CLK_CTL2_t {
  union {
    struct {
      uint32_t HFOSCAUTODIV_EN :  1;  /**< HF Oscillator auto divide by one clock selection during wakeup from Flexi power mode */
      uint32_t HFOSCDIVCLKSEL  :  3;  /**< HF Oscillator divided clock select */
      uint32_t reserved4       : 28;
    };
    uint32_t VALUE32;
  };
} ADI_CLKG_CLK_CTL2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL2_t__ */

/*@}*/

/** @defgroup CTL3 System PLL (CTL3) Register
 *  System PLL (CTL3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CLKG_CLK_CTL3_Struct
 *! \brief  System PLL Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL3_t__
typedef struct _ADI_CLKG_CLK_CTL3_t {
  union {
    struct {
      uint32_t SPLLNSEL   :  5;  /**< System PLL N multiplier */
      uint32_t reserved5  :  3;
      uint32_t SPLLDIV2   :  1;  /**< System PLL division by 2 */
      uint32_t SPLLEN     :  1;  /**< System PLL enable */
      uint32_t SPLLIE     :  1;  /**< System PLL interrupt enable */
      uint32_t SPLLMSEL   :  4;  /**< System PLL M Divider */
      uint32_t reserved15 :  1;
      uint32_t SPLLMUL2   :  1;  /**< System PLL multiply by 2 */
      uint32_t reserved17 : 15;
    };
    uint32_t VALUE32;
  };
} ADI_CLKG_CLK_CTL3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL3_t__ */

/*@}*/

/** @defgroup CTL5 User Clock Gating Control (CTL5) Register
 *  User Clock Gating Control (CTL5) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CLKG_CLK_CTL5_Struct
 *! \brief  User Clock Gating Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL5_t__
typedef struct _ADI_CLKG_CLK_CTL5_t {
  union {
    struct {
      uint32_t GPTCLK0OFF :  1;  /**< GP Timer 0 user control */
      uint32_t GPTCLK1OFF :  1;  /**< GP Timer 1 user control */
      uint32_t GPTCLK2OFF :  1;  /**< GP Timer 2 user control */
      uint32_t UCLKI2COFF :  1;  /**< I2C clock user control */
      uint32_t GPIOCLKOFF :  1;  /**< GPIO clock control */
      uint32_t PERCLKOFF  :  1;  /**< This bit is used to disable all clocks connected to all peripherals */
      uint32_t TMRRGBCLKOFF :  1;  /**< Timer RGB user control */
      uint32_t reserved7    : 25;
    };
    uint32_t VALUE32;
  };
} ADI_CLKG_CLK_CTL5_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL5_t__ */

/*@}*/

/** @defgroup STAT0 Clocking Status (STAT0) Register
 *  Clocking Status (STAT0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CLKG_CLK_STAT0_Struct
 *! \brief  Clocking Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_STAT0_t__
typedef struct _ADI_CLKG_CLK_STAT0_t {
  union {
    struct {
      uint32_t SPLL       :  1;  /**< System PLL status */
      uint32_t SPLLLK     :  1;  /**< System PLL lock */
      uint32_t SPLLUNLK   :  1;  /**< System PLL unlock */
      uint32_t reserved3  :  5;
      uint32_t LFXTAL     :  1;  /**< LF crystal status */
      uint32_t LFXTALOK   :  1;  /**< LF crystal stable */
      uint32_t LFXTALNOK  :  1;  /**< LF crystal not stable */
      uint32_t reserved11 :  1;
      uint32_t HFXTAL     :  1;  /**< HF crystal status */
      uint32_t HFXTALOK   :  1;  /**< HF crystal stable */
      uint32_t HFXTALNOK  :  1;  /**< HF crystal not stable */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_CLKG_CLK_STAT0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_STAT0_t__ */

/*@}*/

/** @defgroup ARBIT0 Arbitration Priority Configuration for FLASH and SRAM0 (ARBIT0) Register
 *  Arbitration Priority Configuration for FLASH and SRAM0 (ARBIT0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_BUSM_ARBIT0_Struct
 *! \brief  Arbitration Priority Configuration for FLASH and SRAM0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT0_t__
typedef struct _ADI_BUSM_ARBIT0_t {
  union {
    struct {
      uint32_t FLSH_DCODE :  2;  /**< Flash priority for DCODE */
      uint32_t FLSH_SBUS  :  2;  /**< Flash priority for SBUS */
      uint32_t FLSH_DMA0  :  2;  /**< Flash priority for DMA0 */
      uint32_t reserved6   : 10;
      uint32_t SRAM0_DCODE :  2;  /**< SRAM0 priority for Dcode */
      uint32_t SRAM0_SBUS  :  2;  /**< SRAM0 priority for SBUS */
      uint32_t SRAM0_DMA0  :  2;  /**< SRAM0 priority for DMA0 */
      uint32_t reserved22  : 10;
    };
    uint32_t VALUE32;
  };
} ADI_BUSM_ARBIT0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT0_t__ */

/*@}*/

/** @defgroup ARBIT1 Arbitration Priority Configuration for SRAM1 (ARBIT1) Register
 *  Arbitration Priority Configuration for SRAM1 (ARBIT1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_BUSM_ARBIT1_Struct
 *! \brief  Arbitration Priority Configuration for SRAM1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT1_t__
typedef struct _ADI_BUSM_ARBIT1_t {
  union {
    struct {
      uint32_t SRAM1_DCODE :  2;  /**< SRAM1 priority for Dcode */
      uint32_t SRAM1_SBUS  :  2;  /**< SRAM1 priority for SBUS */
      uint32_t SRAM1_DMA0  :  2;  /**< SRAM1 priority for DMA0 */
      uint32_t reserved6   : 26;
    };
    uint32_t VALUE32;
  };
} ADI_BUSM_ARBIT1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT1_t__ */

/*@}*/

/** @defgroup ARBIT2 Arbitration Priority Configuration for APB32 and APB16 (ARBIT2) Register
 *  Arbitration Priority Configuration for APB32 and APB16 (ARBIT2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_BUSM_ARBIT2_Struct
 *! \brief  Arbitration Priority Configuration for APB32 and APB16 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT2_t__
typedef struct _ADI_BUSM_ARBIT2_t {
  union {
    struct {
      uint32_t APB32_DCODE :  2;  /**< APB32 priority for DCODE */
      uint32_t APB32_SBUS  :  2;  /**< APB32 priority for SBUS */
      uint32_t APB32_DMA0  :  2;  /**< APB32 priority for DMA0 */
      uint32_t reserved6   : 10;
      uint32_t APB16_DCODE :  2;  /**< APB16 priority for DCODE */
      uint32_t APB16_SBUS  :  2;  /**< APB16 priority for SBUS */
      uint32_t APB16_DMA0  :  2;  /**< APB16 priority for DMA0 */
      uint32_t reserved22  : 10;
    };
    uint32_t VALUE32;
  };
} ADI_BUSM_ARBIT2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT2_t__ */

/*@}*/

/** @defgroup ARBIT3 Arbitration Priority Configuration for APB16 priority for core and for DMA1 (ARBIT3) Register
 *  Arbitration Priority Configuration for APB16 priority for core and for DMA1 (ARBIT3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_BUSM_ARBIT3_Struct
 *! \brief  Arbitration Priority Configuration for APB16 priority for core and for DMA1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT3_t__
typedef struct _ADI_BUSM_ARBIT3_t {
  union {
    struct {
      uint32_t APB16_CORE :  1;  /**< APB16 priority for CORE */
      uint32_t APB16_DMA1 :  1;  /**< APB16 priority for DMA1 */
      uint32_t reserved2       : 14;
      uint32_t APB16_4DMA_CORE :  1;  /**< APB16 for dma priority for CORE */
      uint32_t APB16_4DMA_DMA1 :  1;  /**< APB16 for dma priority for DMA1 */
      uint32_t reserved18      : 14;
    };
    uint32_t VALUE32;
  };
} ADI_BUSM_ARBIT3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT3_t__ */

/*@}*/

/** @defgroup ARBIT4 Arbitration Priority Configuration for SRAM1 and SIP (ARBIT4) Register
 *  Arbitration Priority Configuration for SRAM1 and SIP (ARBIT4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_BUSM_ARBIT4_Struct
 *! \brief  Arbitration Priority Configuration for SRAM1 and SIP Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT4_t__
typedef struct _ADI_BUSM_ARBIT4_t {
  union {
    struct {
      uint32_t SRAM2_DCODE :  2;  /**< SRAM2 priority for Dcode */
      uint32_t SRAM2_SBUS  :  2;  /**< SRAM2 priority for SBUS */
      uint32_t SRAM2_DMA0  :  2;  /**< SRAM2 priority for DMA0 */
      uint32_t reserved6   : 26;
    };
    uint32_t VALUE32;
  };
} ADI_BUSM_ARBIT4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT4_t__ */

/*@}*/

/** @defgroup INTNUM Interrupt Control Type (INTNUM) Register
 *  Interrupt Control Type (INTNUM) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTNUM_Struct
 *! \brief  Interrupt Control Type Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTNUM_t__
typedef struct _ADI_NVIC_INTNUM_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Interrupt Control Type */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTNUM_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTNUM_t__ */

/*@}*/

/** @defgroup STKSTA Systick Control and Status (STKSTA) Register
 *  Systick Control and Status (STKSTA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_STKSTA_Struct
 *! \brief  Systick Control and Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_STKSTA_t__
typedef struct _ADI_NVIC_STKSTA_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Systick Control and Status */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_STKSTA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_STKSTA_t__ */

/*@}*/

/** @defgroup STKLD Systick Reload Value (STKLD) Register
 *  Systick Reload Value (STKLD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_STKLD_Struct
 *! \brief  Systick Reload Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_STKLD_t__
typedef struct _ADI_NVIC_STKLD_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Systick Reload Value */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_STKLD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_STKLD_t__ */

/*@}*/

/** @defgroup STKVAL Systick Current Value (STKVAL) Register
 *  Systick Current Value (STKVAL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_STKVAL_Struct
 *! \brief  Systick Current Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_STKVAL_t__
typedef struct _ADI_NVIC_STKVAL_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Systick Current Value */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_STKVAL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_STKVAL_t__ */

/*@}*/

/** @defgroup STKCAL Systick Calibration Value (STKCAL) Register
 *  Systick Calibration Value (STKCAL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_STKCAL_Struct
 *! \brief  Systick Calibration Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_STKCAL_t__
typedef struct _ADI_NVIC_STKCAL_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Systick Calibration Value */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_STKCAL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_STKCAL_t__ */

/*@}*/

/** @defgroup INTSETE0 IRQ0..31 Set_Enable (INTSETE0) Register
 *  IRQ0..31 Set_Enable (INTSETE0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSETE0_Struct
 *! \brief  IRQ0..31 Set_Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETE0_t__
typedef struct _ADI_NVIC_INTSETE0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ0..31 Set_Enable */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSETE0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETE0_t__ */

/*@}*/

/** @defgroup INTSETE1 IRQ32..63 Set_Enable (INTSETE1) Register
 *  IRQ32..63 Set_Enable (INTSETE1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSETE1_Struct
 *! \brief  IRQ32..63 Set_Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETE1_t__
typedef struct _ADI_NVIC_INTSETE1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ32..63 Set_Enable */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSETE1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETE1_t__ */

/*@}*/

/** @defgroup INTSETE2 IRQ64..95 Set_Enable (INTSETE2) Register
 *  IRQ64..95 Set_Enable (INTSETE2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSETE2_Struct
 *! \brief  IRQ64..95 Set_Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETE2_t__
typedef struct _ADI_NVIC_INTSETE2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ64..95 Set_Enable */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSETE2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETE2_t__ */

/*@}*/

/** @defgroup INTCLRE0 IRQ0..31 Clear_Enable (INTCLRE0) Register
 *  IRQ0..31 Clear_Enable (INTCLRE0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCLRE0_Struct
 *! \brief  IRQ0..31 Clear_Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRE0_t__
typedef struct _ADI_NVIC_INTCLRE0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ0..31 Clear_Enable */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCLRE0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRE0_t__ */

/*@}*/

/** @defgroup INTCLRE1 IRQ32..63 Clear_Enable (INTCLRE1) Register
 *  IRQ32..63 Clear_Enable (INTCLRE1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCLRE1_Struct
 *! \brief  IRQ32..63 Clear_Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRE1_t__
typedef struct _ADI_NVIC_INTCLRE1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ32..63 Clear_Enable */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCLRE1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRE1_t__ */

/*@}*/

/** @defgroup INTCLRE2 IRQ64..95 Clear_Enable (INTCLRE2) Register
 *  IRQ64..95 Clear_Enable (INTCLRE2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCLRE2_Struct
 *! \brief  IRQ64..95 Clear_Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRE2_t__
typedef struct _ADI_NVIC_INTCLRE2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ64..95 Clear_Enable */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCLRE2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRE2_t__ */

/*@}*/

/** @defgroup INTSETP0 IRQ0..31 Set_Pending (INTSETP0) Register
 *  IRQ0..31 Set_Pending (INTSETP0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSETP0_Struct
 *! \brief  IRQ0..31 Set_Pending Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETP0_t__
typedef struct _ADI_NVIC_INTSETP0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ0..31 Set_Pending */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSETP0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETP0_t__ */

/*@}*/

/** @defgroup INTSETP1 IRQ32..63 Set_Pending (INTSETP1) Register
 *  IRQ32..63 Set_Pending (INTSETP1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSETP1_Struct
 *! \brief  IRQ32..63 Set_Pending Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETP1_t__
typedef struct _ADI_NVIC_INTSETP1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ32..63 Set_Pending */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSETP1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETP1_t__ */

/*@}*/

/** @defgroup INTSETP2 IRQ64..95 Set_Pending (INTSETP2) Register
 *  IRQ64..95 Set_Pending (INTSETP2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSETP2_Struct
 *! \brief  IRQ64..95 Set_Pending Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETP2_t__
typedef struct _ADI_NVIC_INTSETP2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ64..95 Set_Pending */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSETP2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETP2_t__ */

/*@}*/

/** @defgroup INTCLRP0 IRQ0..31 Clear_Pending (INTCLRP0) Register
 *  IRQ0..31 Clear_Pending (INTCLRP0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCLRP0_Struct
 *! \brief  IRQ0..31 Clear_Pending Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRP0_t__
typedef struct _ADI_NVIC_INTCLRP0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ0..31 Clear_Pending */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCLRP0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRP0_t__ */

/*@}*/

/** @defgroup INTCLRP1 IRQ32..63 Clear_Pending (INTCLRP1) Register
 *  IRQ32..63 Clear_Pending (INTCLRP1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCLRP1_Struct
 *! \brief  IRQ32..63 Clear_Pending Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRP1_t__
typedef struct _ADI_NVIC_INTCLRP1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ32..63 Clear_Pending */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCLRP1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRP1_t__ */

/*@}*/

/** @defgroup INTCLRP2 IRQ64..95 Clear_Pending (INTCLRP2) Register
 *  IRQ64..95 Clear_Pending (INTCLRP2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCLRP2_Struct
 *! \brief  IRQ64..95 Clear_Pending Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRP2_t__
typedef struct _ADI_NVIC_INTCLRP2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ64..95 Clear_Pending */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCLRP2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRP2_t__ */

/*@}*/

/** @defgroup INTACT0 IRQ0..31 Active Bit (INTACT0) Register
 *  IRQ0..31 Active Bit (INTACT0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTACT0_Struct
 *! \brief  IRQ0..31 Active Bit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTACT0_t__
typedef struct _ADI_NVIC_INTACT0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ0..31 Active Bit */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTACT0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTACT0_t__ */

/*@}*/

/** @defgroup INTACT1 IRQ32..63 Active Bit (INTACT1) Register
 *  IRQ32..63 Active Bit (INTACT1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTACT1_Struct
 *! \brief  IRQ32..63 Active Bit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTACT1_t__
typedef struct _ADI_NVIC_INTACT1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ32..63 Active Bit */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTACT1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTACT1_t__ */

/*@}*/

/** @defgroup INTACT2 IRQ64..95 Active Bit (INTACT2) Register
 *  IRQ64..95 Active Bit (INTACT2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTACT2_Struct
 *! \brief  IRQ64..95 Active Bit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTACT2_t__
typedef struct _ADI_NVIC_INTACT2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ64..95 Active Bit */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTACT2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTACT2_t__ */

/*@}*/

/** @defgroup INTPRI0 IRQ0..3 Priority (INTPRI0) Register
 *  IRQ0..3 Priority (INTPRI0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI0_Struct
 *! \brief  IRQ0..3 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI0_t__
typedef struct _ADI_NVIC_INTPRI0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ0..3 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI0_t__ */

/*@}*/

/** @defgroup INTPRI1 IRQ4..7 Priority (INTPRI1) Register
 *  IRQ4..7 Priority (INTPRI1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI1_Struct
 *! \brief  IRQ4..7 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI1_t__
typedef struct _ADI_NVIC_INTPRI1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ4..7 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI1_t__ */

/*@}*/

/** @defgroup INTPRI2 IRQ8..11 Priority (INTPRI2) Register
 *  IRQ8..11 Priority (INTPRI2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI2_Struct
 *! \brief  IRQ8..11 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI2_t__
typedef struct _ADI_NVIC_INTPRI2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ8..11 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI2_t__ */

/*@}*/

/** @defgroup INTPRI3 IRQ12..15 Priority (INTPRI3) Register
 *  IRQ12..15 Priority (INTPRI3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI3_Struct
 *! \brief  IRQ12..15 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI3_t__
typedef struct _ADI_NVIC_INTPRI3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ12..15 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI3_t__ */

/*@}*/

/** @defgroup INTPRI4 IRQ16..19 Priority (INTPRI4) Register
 *  IRQ16..19 Priority (INTPRI4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI4_Struct
 *! \brief  IRQ16..19 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI4_t__
typedef struct _ADI_NVIC_INTPRI4_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ16..19 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI4_t__ */

/*@}*/

/** @defgroup INTPRI5 IRQ20..23 Priority (INTPRI5) Register
 *  IRQ20..23 Priority (INTPRI5) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI5_Struct
 *! \brief  IRQ20..23 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI5_t__
typedef struct _ADI_NVIC_INTPRI5_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ20..23 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI5_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI5_t__ */

/*@}*/

/** @defgroup INTPRI6 IRQ24..27 Priority (INTPRI6) Register
 *  IRQ24..27 Priority (INTPRI6) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI6_Struct
 *! \brief  IRQ24..27 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI6_t__
typedef struct _ADI_NVIC_INTPRI6_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ24..27 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI6_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI6_t__ */

/*@}*/

/** @defgroup INTPRI7 IRQ28..31 Priority (INTPRI7) Register
 *  IRQ28..31 Priority (INTPRI7) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI7_Struct
 *! \brief  IRQ28..31 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI7_t__
typedef struct _ADI_NVIC_INTPRI7_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ28..31 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI7_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI7_t__ */

/*@}*/

/** @defgroup INTPRI8 IRQ32..35 Priority (INTPRI8) Register
 *  IRQ32..35 Priority (INTPRI8) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI8_Struct
 *! \brief  IRQ32..35 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI8_t__
typedef struct _ADI_NVIC_INTPRI8_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ32..35 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI8_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI8_t__ */

/*@}*/

/** @defgroup INTPRI9 IRQ36..39 Priority (INTPRI9) Register
 *  IRQ36..39 Priority (INTPRI9) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI9_Struct
 *! \brief  IRQ36..39 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI9_t__
typedef struct _ADI_NVIC_INTPRI9_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ36..39 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI9_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI9_t__ */

/*@}*/

/** @defgroup INTPRI10 IRQ40..43 Priority (INTPRI10) Register
 *  IRQ40..43 Priority (INTPRI10) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI10_Struct
 *! \brief  IRQ40..43 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI10_t__
typedef struct _ADI_NVIC_INTPRI10_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ40..43 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI10_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI10_t__ */

/*@}*/

/** @defgroup INTPRI11 IRQ44..47 Priority (INTPRI11) Register
 *  IRQ44..47 Priority (INTPRI11) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI11_Struct
 *! \brief  IRQ44..47 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI11_t__
typedef struct _ADI_NVIC_INTPRI11_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ44..47 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI11_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI11_t__ */

/*@}*/

/** @defgroup INTPRI12 IRQ48..51 Priority (INTPRI12) Register
 *  IRQ48..51 Priority (INTPRI12) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI12_Struct
 *! \brief  IRQ48..51 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI12_t__
typedef struct _ADI_NVIC_INTPRI12_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ48..51 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI12_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI12_t__ */

/*@}*/

/** @defgroup INTPRI13 IRQ52..55 Priority (INTPRI13) Register
 *  IRQ52..55 Priority (INTPRI13) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI13_Struct
 *! \brief  IRQ52..55 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI13_t__
typedef struct _ADI_NVIC_INTPRI13_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ52..55 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI13_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI13_t__ */

/*@}*/

/** @defgroup INTPRI14 IRQ56..59 Priority (INTPRI14) Register
 *  IRQ56..59 Priority (INTPRI14) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI14_Struct
 *! \brief  IRQ56..59 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI14_t__
typedef struct _ADI_NVIC_INTPRI14_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ56..59 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI14_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI14_t__ */

/*@}*/

/** @defgroup INTPRI15 IRQ60..63 Priority (INTPRI15) Register
 *  IRQ60..63 Priority (INTPRI15) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI15_Struct
 *! \brief  IRQ60..63 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI15_t__
typedef struct _ADI_NVIC_INTPRI15_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ60..63 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI15_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI15_t__ */

/*@}*/

/** @defgroup INTPRI16 IRQ64..67 Priority (INTPRI16) Register
 *  IRQ64..67 Priority (INTPRI16) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI16_Struct
 *! \brief  IRQ64..67 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI16_t__
typedef struct _ADI_NVIC_INTPRI16_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ64..67 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI16_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI16_t__ */

/*@}*/

/** @defgroup INTPRI17 IRQ68..71 Priority (INTPRI17) Register
 *  IRQ68..71 Priority (INTPRI17) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI17_Struct
 *! \brief  IRQ68..71 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI17_t__
typedef struct _ADI_NVIC_INTPRI17_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ68..71 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI17_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI17_t__ */

/*@}*/

/** @defgroup INTCPID CPUID Base (INTCPID) Register
 *  CPUID Base (INTCPID) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCPID_Struct
 *! \brief  CPUID Base Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCPID_t__
typedef struct _ADI_NVIC_INTCPID_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< CPUID Base */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCPID_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCPID_t__ */

/*@}*/

/** @defgroup INTSTA Interrupt Control State (INTSTA) Register
 *  Interrupt Control State (INTSTA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSTA_Struct
 *! \brief  Interrupt Control State Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSTA_t__
typedef struct _ADI_NVIC_INTSTA_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Interrupt Control State */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSTA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSTA_t__ */

/*@}*/

/** @defgroup INTVEC Vector Table Offset (INTVEC) Register
 *  Vector Table Offset (INTVEC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTVEC_Struct
 *! \brief  Vector Table Offset Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTVEC_t__
typedef struct _ADI_NVIC_INTVEC_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Vector Table Offset */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTVEC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTVEC_t__ */

/*@}*/

/** @defgroup INTAIRC Application Interrupt/Reset Control (INTAIRC) Register
 *  Application Interrupt/Reset Control (INTAIRC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTAIRC_Struct
 *! \brief  Application Interrupt/Reset Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTAIRC_t__
typedef struct _ADI_NVIC_INTAIRC_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Application Interrupt/Reset Control */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTAIRC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTAIRC_t__ */

/*@}*/

/** @defgroup INTCON0 System Control (INTCON0) Register
 *  System Control (INTCON0) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_NVIC_INTCON0_SLEEPONEXIT
 *! \brief  Sleeps the Core on Exit from an ISR (SLEEPONEXIT) Enumerations
 *  ========================================================================= */
typedef enum
{
  NVIC_INTCON0_NO_SLEEPONEXIT = 0,  /**< Sleep On Exit is not enabled */
  NVIC_INTCON0_SLEEPONEXIT    = 1   /**< Sleep On Exit is enabled     */
} ADI_NVIC_INTCON0_SLEEPONEXIT;


/*  =========================================================================
 *! \enum   ADI_NVIC_INTCON0_SLEEPDEEP
 *! \brief  Deep Sleep Flag for Hibernate Mode (SLEEPDEEP) Enumerations
 *  ========================================================================= */
typedef enum
{
  NVIC_INTCON0_NO_SLEEPDEEP = 0,  /**< Sleep Deep is not enabled */
  NVIC_INTCON0_SLEEPDEEP    = 1   /**< Sleep Deep is enabled     */
} ADI_NVIC_INTCON0_SLEEPDEEP;


/* ==========================================================================
 *! \struct ADI_NVIC_INTCON0_Struct
 *! \brief  System Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCON0_t__
typedef struct _ADI_NVIC_INTCON0_t {
  union {
    struct {
      uint16_t reserved0   :  1;
      uint16_t SLEEPONEXIT :  1;  /**< Sleeps the Core on Exit from an ISR */
      uint16_t SLEEPDEEP   :  1;  /**< Deep Sleep Flag for Hibernate Mode */
      uint16_t reserved3   : 13;
    };
    uint16_t VALUE16;
  };
} ADI_NVIC_INTCON0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCON0_t__ */

/*@}*/

/** @defgroup INTCON1 Configuration Control (INTCON1) Register
 *  Configuration Control (INTCON1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCON1_Struct
 *! \brief  Configuration Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCON1_t__
typedef struct _ADI_NVIC_INTCON1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Configuration Control */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCON1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCON1_t__ */

/*@}*/

/** @defgroup INTSHPRIO0 System Handlers 4-7 Priority (INTSHPRIO0) Register
 *  System Handlers 4-7 Priority (INTSHPRIO0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSHPRIO0_Struct
 *! \brief  System Handlers 4-7 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHPRIO0_t__
typedef struct _ADI_NVIC_INTSHPRIO0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< System Handlers 4-7 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSHPRIO0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHPRIO0_t__ */

/*@}*/

/** @defgroup INTSHPRIO1 System Handlers 8-11 Priority (INTSHPRIO1) Register
 *  System Handlers 8-11 Priority (INTSHPRIO1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSHPRIO1_Struct
 *! \brief  System Handlers 8-11 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHPRIO1_t__
typedef struct _ADI_NVIC_INTSHPRIO1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< System Handlers 8-11 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSHPRIO1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHPRIO1_t__ */

/*@}*/

/** @defgroup INTSHPRIO3 System Handlers 12-15 Priority (INTSHPRIO3) Register
 *  System Handlers 12-15 Priority (INTSHPRIO3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSHPRIO3_Struct
 *! \brief  System Handlers 12-15 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHPRIO3_t__
typedef struct _ADI_NVIC_INTSHPRIO3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< System Handlers 12-15 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSHPRIO3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHPRIO3_t__ */

/*@}*/

/** @defgroup INTSHCSR System Handler Control and State (INTSHCSR) Register
 *  System Handler Control and State (INTSHCSR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSHCSR_Struct
 *! \brief  System Handler Control and State Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHCSR_t__
typedef struct _ADI_NVIC_INTSHCSR_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< System Handler Control and State */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSHCSR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHCSR_t__ */

/*@}*/

/** @defgroup INTCFSR Configurable Fault Status (INTCFSR) Register
 *  Configurable Fault Status (INTCFSR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCFSR_Struct
 *! \brief  Configurable Fault Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCFSR_t__
typedef struct _ADI_NVIC_INTCFSR_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Configurable Fault Status */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCFSR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCFSR_t__ */

/*@}*/

/** @defgroup INTHFSR Hard Fault Status (INTHFSR) Register
 *  Hard Fault Status (INTHFSR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTHFSR_Struct
 *! \brief  Hard Fault Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTHFSR_t__
typedef struct _ADI_NVIC_INTHFSR_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Hard Fault Status */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTHFSR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTHFSR_t__ */

/*@}*/

/** @defgroup INTDFSR Debug Fault Status (INTDFSR) Register
 *  Debug Fault Status (INTDFSR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTDFSR_Struct
 *! \brief  Debug Fault Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTDFSR_t__
typedef struct _ADI_NVIC_INTDFSR_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Debug Fault Status */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTDFSR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTDFSR_t__ */

/*@}*/

/** @defgroup INTMMAR Mem Manage Address (INTMMAR) Register
 *  Mem Manage Address (INTMMAR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTMMAR_Struct
 *! \brief  Mem Manage Address Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMAR_t__
typedef struct _ADI_NVIC_INTMMAR_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Mem Manage Address */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTMMAR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMAR_t__ */

/*@}*/

/** @defgroup INTBFAR Bus Fault Address (INTBFAR) Register
 *  Bus Fault Address (INTBFAR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTBFAR_Struct
 *! \brief  Bus Fault Address Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTBFAR_t__
typedef struct _ADI_NVIC_INTBFAR_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Bus Fault Address */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTBFAR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTBFAR_t__ */

/*@}*/

/** @defgroup INTAFSR Auxiliary Fault Status (INTAFSR) Register
 *  Auxiliary Fault Status (INTAFSR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTAFSR_Struct
 *! \brief  Auxiliary Fault Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTAFSR_t__
typedef struct _ADI_NVIC_INTAFSR_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Auxiliary Fault Status */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTAFSR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTAFSR_t__ */

/*@}*/

/** @defgroup INTPFR0 Processor Feature Register 0 (INTPFR0) Register
 *  Processor Feature Register 0 (INTPFR0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPFR0_Struct
 *! \brief  Processor Feature Register 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPFR0_t__
typedef struct _ADI_NVIC_INTPFR0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Processor Feature Register 0 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPFR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPFR0_t__ */

/*@}*/

/** @defgroup INTPFR1 Processor Feature Register 1 (INTPFR1) Register
 *  Processor Feature Register 1 (INTPFR1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPFR1_Struct
 *! \brief  Processor Feature Register 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPFR1_t__
typedef struct _ADI_NVIC_INTPFR1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Processor Feature Register 1 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPFR1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPFR1_t__ */

/*@}*/

/** @defgroup INTDFR0 Debug Feature Register 0 (INTDFR0) Register
 *  Debug Feature Register 0 (INTDFR0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTDFR0_Struct
 *! \brief  Debug Feature Register 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTDFR0_t__
typedef struct _ADI_NVIC_INTDFR0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Debug Feature Register 0 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTDFR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTDFR0_t__ */

/*@}*/

/** @defgroup INTAFR0 Auxiliary Feature Register 0 (INTAFR0) Register
 *  Auxiliary Feature Register 0 (INTAFR0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTAFR0_Struct
 *! \brief  Auxiliary Feature Register 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTAFR0_t__
typedef struct _ADI_NVIC_INTAFR0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Auxiliary Feature Register 0 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTAFR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTAFR0_t__ */

/*@}*/

/** @defgroup INTMMFR0 Memory Model Feature Register 0 (INTMMFR0) Register
 *  Memory Model Feature Register 0 (INTMMFR0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTMMFR0_Struct
 *! \brief  Memory Model Feature Register 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR0_t__
typedef struct _ADI_NVIC_INTMMFR0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Memory Model Feature Register 0 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTMMFR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR0_t__ */

/*@}*/

/** @defgroup INTMMFR1 Memory Model Feature Register 1 (INTMMFR1) Register
 *  Memory Model Feature Register 1 (INTMMFR1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTMMFR1_Struct
 *! \brief  Memory Model Feature Register 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR1_t__
typedef struct _ADI_NVIC_INTMMFR1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Memory Model Feature Register 1 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTMMFR1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR1_t__ */

/*@}*/

/** @defgroup INTMMFR2 Memory Model Feature Register 2 (INTMMFR2) Register
 *  Memory Model Feature Register 2 (INTMMFR2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTMMFR2_Struct
 *! \brief  Memory Model Feature Register 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR2_t__
typedef struct _ADI_NVIC_INTMMFR2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Memory Model Feature Register 2 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTMMFR2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR2_t__ */

/*@}*/

/** @defgroup INTMMFR3 Memory Model Feature Register 3 (INTMMFR3) Register
 *  Memory Model Feature Register 3 (INTMMFR3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTMMFR3_Struct
 *! \brief  Memory Model Feature Register 3 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR3_t__
typedef struct _ADI_NVIC_INTMMFR3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Memory Model Feature Register 3 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTMMFR3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR3_t__ */

/*@}*/

/** @defgroup INTISAR0 ISA Feature Register 0 (INTISAR0) Register
 *  ISA Feature Register 0 (INTISAR0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTISAR0_Struct
 *! \brief  ISA Feature Register 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR0_t__
typedef struct _ADI_NVIC_INTISAR0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< ISA Feature Register 0 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTISAR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR0_t__ */

/*@}*/

/** @defgroup INTISAR1 ISA Feature Register 1 (INTISAR1) Register
 *  ISA Feature Register 1 (INTISAR1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTISAR1_Struct
 *! \brief  ISA Feature Register 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR1_t__
typedef struct _ADI_NVIC_INTISAR1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< ISA Feature Register 1 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTISAR1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR1_t__ */

/*@}*/

/** @defgroup INTISAR2 ISA Feature Register 2 (INTISAR2) Register
 *  ISA Feature Register 2 (INTISAR2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTISAR2_Struct
 *! \brief  ISA Feature Register 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR2_t__
typedef struct _ADI_NVIC_INTISAR2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< ISA Feature Register 2 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTISAR2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR2_t__ */

/*@}*/

/** @defgroup INTISAR3 ISA Feature Register 3 (INTISAR3) Register
 *  ISA Feature Register 3 (INTISAR3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTISAR3_Struct
 *! \brief  ISA Feature Register 3 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR3_t__
typedef struct _ADI_NVIC_INTISAR3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< ISA Feature Register 3 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTISAR3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR3_t__ */

/*@}*/

/** @defgroup INTISAR4 ISA Feature Register 4 (INTISAR4) Register
 *  ISA Feature Register 4 (INTISAR4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTISAR4_Struct
 *! \brief  ISA Feature Register 4 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR4_t__
typedef struct _ADI_NVIC_INTISAR4_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< ISA Feature Register 4 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTISAR4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR4_t__ */

/*@}*/

/** @defgroup INTTRGI Software Trigger Interrupt Register (INTTRGI) Register
 *  Software Trigger Interrupt Register (INTTRGI) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTTRGI_Struct
 *! \brief  Software Trigger Interrupt Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTTRGI_t__
typedef struct _ADI_NVIC_INTTRGI_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Software Trigger Interrupt Register */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTTRGI_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTTRGI_t__ */

/*@}*/

/** @defgroup INTPID4 Peripheral Identification Register 4 (INTPID4) Register
 *  Peripheral Identification Register 4 (INTPID4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID4_Struct
 *! \brief  Peripheral Identification Register 4 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID4_t__
typedef struct _ADI_NVIC_INTPID4_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Register 4 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID4_t__ */

/*@}*/

/** @defgroup INTPID5 Peripheral Identification Register 5 (INTPID5) Register
 *  Peripheral Identification Register 5 (INTPID5) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID5_Struct
 *! \brief  Peripheral Identification Register 5 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID5_t__
typedef struct _ADI_NVIC_INTPID5_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Register 5 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID5_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID5_t__ */

/*@}*/

/** @defgroup INTPID6 Peripheral Identification Register 6 (INTPID6) Register
 *  Peripheral Identification Register 6 (INTPID6) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID6_Struct
 *! \brief  Peripheral Identification Register 6 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID6_t__
typedef struct _ADI_NVIC_INTPID6_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Register 6 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID6_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID6_t__ */

/*@}*/

/** @defgroup INTPID7 Peripheral Identification Register 7 (INTPID7) Register
 *  Peripheral Identification Register 7 (INTPID7) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID7_Struct
 *! \brief  Peripheral Identification Register 7 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID7_t__
typedef struct _ADI_NVIC_INTPID7_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Register 7 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID7_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID7_t__ */

/*@}*/

/** @defgroup INTPID0 Peripheral Identification Bits7:0 (INTPID0) Register
 *  Peripheral Identification Bits7:0 (INTPID0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID0_Struct
 *! \brief  Peripheral Identification Bits7:0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID0_t__
typedef struct _ADI_NVIC_INTPID0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Bits7:0 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID0_t__ */

/*@}*/

/** @defgroup INTPID1 Peripheral Identification Bits15:8 (INTPID1) Register
 *  Peripheral Identification Bits15:8 (INTPID1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID1_Struct
 *! \brief  Peripheral Identification Bits15:8 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID1_t__
typedef struct _ADI_NVIC_INTPID1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Bits15:8 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID1_t__ */

/*@}*/

/** @defgroup INTPID2 Peripheral Identification Bits16:23 (INTPID2) Register
 *  Peripheral Identification Bits16:23 (INTPID2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID2_Struct
 *! \brief  Peripheral Identification Bits16:23 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID2_t__
typedef struct _ADI_NVIC_INTPID2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Bits16:23 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID2_t__ */

/*@}*/

/** @defgroup INTPID3 Peripheral Identification Bits24:31 (INTPID3) Register
 *  Peripheral Identification Bits24:31 (INTPID3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID3_Struct
 *! \brief  Peripheral Identification Bits24:31 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID3_t__
typedef struct _ADI_NVIC_INTPID3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Bits24:31 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID3_t__ */

/*@}*/

/** @defgroup INTCID0 Component Identification Bits7:0 (INTCID0) Register
 *  Component Identification Bits7:0 (INTCID0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCID0_Struct
 *! \brief  Component Identification Bits7:0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID0_t__
typedef struct _ADI_NVIC_INTCID0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Component Identification Bits7:0 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCID0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID0_t__ */

/*@}*/

/** @defgroup INTCID1 Component Identification Bits15:8 (INTCID1) Register
 *  Component Identification Bits15:8 (INTCID1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCID1_Struct
 *! \brief  Component Identification Bits15:8 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID1_t__
typedef struct _ADI_NVIC_INTCID1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Component Identification Bits15:8 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCID1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID1_t__ */

/*@}*/

/** @defgroup INTCID2 Component Identification Bits16:23 (INTCID2) Register
 *  Component Identification Bits16:23 (INTCID2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCID2_Struct
 *! \brief  Component Identification Bits16:23 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID2_t__
typedef struct _ADI_NVIC_INTCID2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Component Identification Bits16:23 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCID2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID2_t__ */

/*@}*/

/** @defgroup INTCID3 Component Identification Bits24:31 (INTCID3) Register
 *  Component Identification Bits24:31 (INTCID3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCID3_Struct
 *! \brief  Component Identification Bits24:31 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID3_t__
typedef struct _ADI_NVIC_INTCID3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Component Identification Bits24:31 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCID3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID3_t__ */

/*@}*/


#if defined (_MISRA_RULES)
#pragma diag(pop)
#endif /* _MISRA_RULES */


#if defined (__CC_ARM)
#pragma pop
#endif 

#endif
