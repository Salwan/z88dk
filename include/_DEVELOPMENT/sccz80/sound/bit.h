
// automatically generated by m4 from headers in proto subdir


#ifndef _SOUND_BIT_H
#define _SOUND_BIT_H

#include <stdint.h>

//////////////////////
// 1-BIT SOUND LIBRARY
//////////////////////

// void bit_freq(float dur_ms, float freq_hz);
// not yet implemented -- requires float package

// SOUND EFFECTS FOR BIT_FX()

#define BFX_UNNAMED_1             bitfx_0
#define BFX_LASER_REPEAT          bitfx_1
#define BFX_SQUEAK                bitfx_2
#define BFX_EATING                bitfx_3
#define BFX_SQUELCH               bitfx_4
#define BFX_KLAXON                bitfx_5
#define BFX_BEEP                  bitfx_6
#define BFX_WARP                  bitfx_7
#define BFX_DEEP_SPACE            bitfx_8
#define BFX_DUAL_NOTE_FUZZY       bitfx_9
#define BFX_DUAL_NOTE_FUZZY_2     bitfx_10
#define BFX_KLAXON_2              bitfx_11
#define BFX_TSPACE                bitfx_12
#define BFX_TSPACE_2              bitfx_13
#define BFX_SQUOINK               bitfx_14
#define BFX_EXPLOSION             bitfx_15
#define BFX_BLIRP                 bitfx_16
#define BFX_BLIRP_2               bitfx_17
#define BFX_STEAM_ENGINE          bitfx_18
#define BFX_BLURP                 bitfx_19
#define BFX_BUZZER_DESCEND        bitfx_20
#define BFX_BUZZER_ASCEND         bitfx_21
#define BFX_BUZZER_DESCEND_2      bitfx_22
#define BFX_UNNAMED_2             bitfx_23
#define BFX_SQUEAK_2              bitfx_24
#define BFX_TAPE_REWIND           bitfx_25
#define BFX_UNNAMED_3             bitfx_26
#define BFX_UNNAMED_4             bitfx_27
#define BFX_SQUEAK_DESCEND        bitfx_28
#define BFX_UNNAMED_5             bitfx_29
#define BFX_UNNAMED_6             bitfx_30
#define BFX_UNNAMED_7             bitfx_31

// SOUND EFFECTS FOR BIT_BEEPFX()

#define BEEPFX_SHOT_1             bfx_0
#define BEEPFX_SHOT_2             bfx_1
#define BEEPFX_JUMP_1             bfx_2
#define BEEPFX_JUMP_2             bfx_3
#define BEEPFX_PICK               bfx_4
#define BEEPFX_DROP_1             bfx_5
#define BEEPFX_DROP_2             bfx_6
#define BEEPFX_GRAB_1             bfx_7
#define BEEPFX_GRAB_2             bfx_8
#define BEEPFX_FAT_BEEP_1         bfx_9
#define BEEPFX_FAT_BEEP_2         bfx_10
#define BEEPFX_FAT_BEEP_3         bfx_11
#define BEEPFX_HARSH_BEEP_1       bfx_12
#define BEEPFX_HARSH_BEEP_2       bfx_13
#define BEEPFX_HARSH_BEEP_3       bfx_14
#define BEEPFX_HIT_1              bfx_15
#define BEEPFX_HIT_2              bfx_16
#define BEEPFX_HIT_3              bfx_17
#define BEEPFX_HIT_4              bfx_18
#define BEEPFX_JET_BURST          bfx_19
#define BEEPFX_BOOM_1             bfx_20
#define BEEPFX_BOOM_2             bfx_21
#define BEEPFX_BOOM_3             bfx_22
#define BEEPFX_BOOM_4             bfx_23
#define BEEPFX_BOOM_5             bfx_24
#define BEEPFX_BOOM_6             bfx_25
#define BEEPFX_BOOM_7             bfx_26
#define BEEPFX_BOOM_8             bfx_27
#define BEEPFX_ITEM_1             bfx_28
#define BEEPFX_ITEM_2             bfx_29
#define BEEPFX_ITEM_3             bfx_30
#define BEEPFX_ITEM_4             bfx_31
#define BEEPFX_ITEM_5             bfx_32
#define BEEPFX_ITEM_6             bfx_33
#define BEEPFX_SWITCH_1           bfx_34
#define BEEPFX_SWITCH_2           bfx_35
#define BEEPFX_POWER_OFF          bfx_36
#define BEEPFX_SCORE              bfx_37
#define BEEPFX_CLANG              bfx_38
#define BEEPFX_WATER_TAP          bfx_39
#define BEEPFX_SELECT_1           bfx_40
#define BEEPFX_SELECT_2           bfx_41
#define BEEPFX_SELECT_3           bfx_42
#define BEEPFX_SELECT_4           bfx_43
#define BEEPFX_SELECT_5           bfx_44
#define BEEPFX_SELECT_6           bfx_45
#define BEEPFX_SELECT_7           bfx_46
#define BEEPFX_ALARM_1            bfx_47
#define BEEPFX_ALARM_2            bfx_48
#define BEEPFX_ALARM_3            bfx_49
#define BEEPFX_EAT                bfx_50
#define BEEPFX_GULP               bfx_51
#define BEEPFX_ROBOBLIP           bfx_52
#define BEEPFX_NOPE               bfx_53
#define BEEPFX_UH_HUH             bfx_54
#define BEEPFX_OLD_COMPUTER       bfx_55
#define BEEPFX_YEAH               bfx_56
#define BEEPFX_AWW                bfx_57

extern void __LIB__ bit_beep(uint16_t dur_ms,uint16_t freq_hz) __smallc;
extern void __LIB__ __CALLEE__ bit_beep_callee(uint16_t dur_ms,uint16_t freq_hz) __smallc;
#define bit_beep(a,b) bit_beep_callee(a,b)


extern void __LIB__ bit_beep_raw(uint16_t cycles_num,uint16_t period_T) __smallc;
extern void __LIB__ __CALLEE__ bit_beep_raw_callee(uint16_t cycles_num,uint16_t period_T) __smallc;
#define bit_beep_raw(a,b) bit_beep_raw_callee(a,b)


extern void __LIB__ bit_click(void) __smallc;


extern void __LIB__ __FASTCALL__ bit_fx(void *bfx) __smallc;


extern void __LIB__ __FASTCALL__ bit_beepfx(void *bfx) __smallc;


extern char __LIB__ __FASTCALL__ *bit_play(char *melody) __smallc;


extern void __LIB__ __FASTCALL__ *bit_play_tritone(void *song) __smallc;


extern void __LIB__ bit_synth(uint16_t dur,uint16_t freq_1,uint16_t freq_2,uint16_t freq_3,uint16_t freq_4) __smallc;
extern void __LIB__ __CALLEE__ bit_synth_callee(uint16_t dur,uint16_t freq_1,uint16_t freq_2,uint16_t freq_3,uint16_t freq_4) __smallc;
#define bit_synth(a,b,c,d,e) bit_synth_callee(a,b,c,d,e)



extern void __LIB__ bit_beep_di(uint16_t dur_ms,uint16_t freq_hz) __smallc;
extern void __LIB__ __CALLEE__ bit_beep_di_callee(uint16_t dur_ms,uint16_t freq_hz) __smallc;
#define bit_beep_di(a,b) bit_beep_di_callee(a,b)


extern void __LIB__ bit_beep_raw_di(uint16_t cycles_num,uint16_t period_T) __smallc;
extern void __LIB__ __CALLEE__ bit_beep_raw_di_callee(uint16_t cycles_num,uint16_t period_T) __smallc;
#define bit_beep_raw_di(a,b) bit_beep_raw_di_callee(a,b)


extern void __LIB__ bit_click_di(void) __smallc;


extern void __LIB__ __FASTCALL__ bit_fx_di(void *bfx) __smallc;


extern void __LIB__ __FASTCALL__ bit_beepfx_di(void *bfx) __smallc;


extern char __LIB__ __FASTCALL__ *bit_play_di(char *melody) __smallc;


extern void __LIB__ __FASTCALL__ *bit_play_tritone_di(void *song) __smallc;


extern void __LIB__ bit_synth_di(uint16_t dur,uint16_t freq_1,uint16_t freq_2,uint16_t freq_3,uint16_t freq_4) __smallc;
extern void __LIB__ __CALLEE__ bit_synth_di_callee(uint16_t dur,uint16_t freq_1,uint16_t freq_2,uint16_t freq_3,uint16_t freq_4) __smallc;
#define bit_synth_di(a,b,c,d,e) bit_synth_di_callee(a,b,c,d,e)



// IMPLEMENTATION DETAILS FOR BIT_FX()

extern void bitfx_0(void);
extern void bitfx_1(void);
extern void bitfx_2(void);
extern void bitfx_3(void);
extern void bitfx_4(void);
extern void bitfx_5(void);
extern void bitfx_6(void);
extern void bitfx_7(void);
extern void bitfx_8(void);
extern void bitfx_9(void);
extern void bitfx_10(void);
extern void bitfx_11(void);
extern void bitfx_12(void);
extern void bitfx_13(void);
extern void bitfx_14(void);
extern void bitfx_15(void);
extern void bitfx_16(void);
extern void bitfx_17(void);
extern void bitfx_18(void);
extern void bitfx_19(void);
extern void bitfx_20(void);
extern void bitfx_21(void);
extern void bitfx_22(void);
extern void bitfx_23(void);
extern void bitfx_24(void);
extern void bitfx_25(void);
extern void bitfx_26(void);
extern void bitfx_27(void);
extern void bitfx_28(void);
extern void bitfx_29(void);
extern void bitfx_30(void);
extern void bitfx_31(void);

// IMPLEMENTATION DETAILS FOR BIT_BEEPFX()

extern void bfx_0(void);
extern void bfx_1(void);
extern void bfx_2(void);
extern void bfx_3(void);
extern void bfx_4(void);
extern void bfx_5(void);
extern void bfx_6(void);
extern void bfx_7(void);
extern void bfx_8(void);
extern void bfx_9(void);
extern void bfx_10(void);
extern void bfx_11(void);
extern void bfx_12(void);
extern void bfx_13(void);
extern void bfx_14(void);
extern void bfx_15(void);
extern void bfx_16(void);
extern void bfx_17(void);
extern void bfx_18(void);
extern void bfx_19(void);
extern void bfx_20(void);
extern void bfx_21(void);
extern void bfx_22(void);
extern void bfx_23(void);
extern void bfx_24(void);
extern void bfx_25(void);
extern void bfx_26(void);
extern void bfx_27(void);
extern void bfx_28(void);
extern void bfx_29(void);
extern void bfx_30(void);
extern void bfx_31(void);
extern void bfx_32(void);
extern void bfx_33(void);
extern void bfx_34(void);
extern void bfx_35(void);
extern void bfx_36(void);
extern void bfx_37(void);
extern void bfx_38(void);
extern void bfx_39(void);
extern void bfx_40(void);
extern void bfx_41(void);
extern void bfx_42(void);
extern void bfx_43(void);
extern void bfx_44(void);
extern void bfx_45(void);
extern void bfx_46(void);
extern void bfx_47(void);
extern void bfx_48(void);
extern void bfx_49(void);
extern void bfx_50(void);
extern void bfx_51(void);
extern void bfx_52(void);
extern void bfx_53(void);
extern void bfx_54(void);
extern void bfx_55(void);
extern void bfx_56(void);
extern void bfx_57(void);

#endif
