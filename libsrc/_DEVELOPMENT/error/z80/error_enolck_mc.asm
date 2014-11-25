
INCLUDE "clib_cfg.asm"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
IF __CLIB_OPT_ERROR
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

   ; verbose mode

   SECTION seg_code_error
   
   PUBLIC error_enolck_mc
   
   EXTERN __ENOLCK, errno_mc
   
      pop hl
   
   error_enolck_mc:
   
      ; set hl = -1
      ; set carry flag
      ; set errno = ENOLCK
      
      ld l,__ENOLCK
      jp errno_mc
   
   
   SECTION seg_rodata_error_strings

   IF __CLIB_OPT_ERROR & $02

      defb __ENOLCK
      defm "ENOLCK - Attempt to lock failed"
      defb 0

   ELSE
   
      defb __ENOLCK
      defm "ENOLCK"
      defb 0
   
   ENDIF
   
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ELSE
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

   SECTION seg_code_error
   
   PUBLIC error_enolck_mc
   
   EXTERN errno_mc
   
   defc error_enolck_mc = errno_mc - 2

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ENDIF
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
