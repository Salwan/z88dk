;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; memory model ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; Main Binary @ 0x2000 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

SECTION CODE

org __crt_org_code

IF (__crt_org_vector_table = -0x80) || (__crt_org_vector_table = -0x100)

section interrupt_vectors
section code_crt_start

ENDIF

section code_crt_init
section code_crt_main
section code_crt_exit
section code_crt_return
section code_crt_common

IF (__crt_org_vector_table) && (__crt_org_vector_table != -0x80) && (__crt_org_vector_table != -0x100)

section interrupt_vectors

ENDIF

section code_arch
section code_clib
section code_compress_aplib
section code_compress_zx7
section code_ctype
section code_error
section code_esxdos
section code_fcntl
section code_input
section code_l
section code_l_sccz80
section code_l_sdcc
section code_math
section code_sound_bit
section code_stdio
section code_stdlib
section code_string
section code_threads
section code_threads_mutex
section code_z180
section code_z80

section rodata_arch
section rodata_clib
section rodata_driver
section rodata_error_strings
section rodata_error_string_end
defb 0
section rodata_fcntl
section rodata_input
section rodata_sound_bit
section rodata_stdio
section rodata_stdlib

section smc_clib
section smc_fcntl
section smc_l

section data_arch
section data_clib
section data_fcntl
section data_fcntl_stdio_heap_head
section data_fcntl_stdio_heap_body
section data_fcntl_stdio_heap_tail
section data_fcntl_fdtable_body
section data_stdio
section data_stdlib
section data_threads

section bss_arch
section bss_clib
section bss_compress_aplib
section bss_error
section bss_fcntl
section bss_input
section bss_stdio
section bss_stdlib
section bss_string

section code_dot
section rodata_dot
section smc_dot
section data_dot
section bss_dot
section bss_dot_uninitialized
section dtn_allocated_pages

SECTION CODE_END

;; Dot Extension Code ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

SECTION DTN
org CRT_ORG_DTN

section code_adt_b_array
section code_adt_b_vector
section code_adt_ba_priority_queue
section code_adt_ba_stack
section code_adt_bv_priority_queue
section code_adt_bv_stack
section code_adt_p_forward_list
section code_adt_p_forward_list_alt
section code_adt_p_list
section code_adt_p_queue
section code_adt_p_stack
section code_adt_w_array
section code_adt_w_vector
section code_adt_wa_priority_queue
section code_adt_wa_stack
section code_adt_wv_priority_queue
section code_adt_wv_stack
section code_alloc_balloc
section code_alloc_malloc
section code_alloc_obstack
section code_bifrost_h
section code_bifrost_l
section code_bifrost2
section code_driver
section code_driver_general
section code_driver_character_input
section code_driver_character_output
section code_driver_memstream
section code_driver_terminal_input
section code_driver_terminal_output
section code_driver_tty
section code_font
section code_font_fzx
section code_fp_genmath
section code_fp_math48
section code_im2
section code_inttypes
section code_locale
section code_network
section code_nirvanam
section code_nirvanap
section code_PSGlib
section code_setjmp
section code_SMSlib
section code_temp_sp1

section code_lib
section code_compiler
section code_user

section rodata_font
section rodata_font_4x8
section rodata_font_8x8
section rodata_font_fzx
section rodata_SMSlib

section rodata_lib
section rodata_compiler
section rodata_user

section code_dtn
section rodata_dtn
section smc_dtn
section data_dtn
section bss_dtn

SECTION DATA

IF __crt_org_data

   org __crt_org_data

ELSE

   IF __crt_model
      
      "DATA section address must be specified for rom models"
   
   ENDIF

ENDIF

section data_align_256
section data_align_128
section data_align_64
section data_align_32
section data_align_16
section data_align_8
section data_align_4
section data_align_2

section smc_jump_vectors
section smc_driver
section smc_font

section smc_sound_bit

section smc_lib
section smc_compiler
section smc_user

section data_driver
section data_font

section data_alloc_balloc
section data_alloc_malloc
section data_PSGlib
section data_SMSlib
section data_sound_bit

section data_lib
section data_compiler
section data_user

SECTION DATA_END

SECTION BSS

IF __crt_org_bss

   org __crt_org_bss

ELSE

   IF __crt_model

      org -1

   ENDIF

ENDIF

section bss_align_256
section bss_align_128
section bss_align_64
section bss_align_32
section bss_align_16
section bss_align_8
section bss_align_4
section bss_align_2

section bss_driver
section bss_font

section bss_alloc_balloc
section bss_alloc_malloc
section bss_PSGlib
section bss_SMSlib
section bss_sound_bit

section bss_lib
section bss_compiler
section bss_user

section BSS_UNINITIALIZED
SECTION BSS_STACK_BOT
   defs __crt_stack_size
SECTION BSS_STACK_TOP
SECTION BSS_END
SECTION DTN_END

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

IF (__crt_org_vector_table = 0)

section interrupt_vectors
org 0

ENDIF

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
