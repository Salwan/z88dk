include(__link__.m4)

#ifndef _ULAPLUS_H
#define _ULAPLUS_H

#include <arch.h>

// IO MAPPED REGISTERS

#ifdef __CLANG

extern unsigned char IO_ULAP_REGISTER;
extern unsigned char IO_ULAP_DATA;

#else
	
__sfr __banked __at __IO_ULAP_REGISTER IO_ULAP_REGISTER;
__sfr __banked __at __IO_ULAP_DATA     IO_ULAP_DATA;

#endif

// Enable or Disable ULA+

__OPROTO(`d,e,h,l,iyl,iyh',`d,e,h,l,iyl,iyh',void,,ulap_enable,void)
__OPROTO(`d,e,h,l,iyl,iyh',`d,e,h,l,iyl,iyh',void,,ulap_disable,void)

// Read or Write Many Palette Entries

__DPROTO(`iyl,iyh',`iyl,iyh',void,*,ulap_read_palette,void *dst,unsigned char pent,unsigned char num)
__DPROTO(`iyl,iyh',`iyl,iyh',void,*,ulap_write_palette,void *src,unsigned char pent,unsigned char num)

// Read or Write a Single Palette Entry

__DPROTO(`a,d,e,h,iyl,iyh',`d,e,iyl,iyh',unsigned char,,ulap_read_color,unsigned char pent)
__DPROTO(`a,d,e,iyl,iyh',`d,e,iyl,iyh',void,,ulap_write_color,unsigned char pent,unsigned char color)

// Runtime Versions of Selected Macros

__DPROTO(`b,c,d,e,iyl,iyh',`b,c,d,e,iyl,iyh',unsigned char,,ulap_attr_from_pentp_penti,unsigned char pentp,unsigned char penti)
__DPROTO(`b,c,d,e,iyl,iyh',`b,c,d,e,iyl,iyh',unsigned char,,ulap_pent_from_attr_ink,unsigned char attr)
__DPROTO(`b,c,d,e,iyl,iyh',`b,c,d,e,iyl,iyh',unsigned char,,ulap_pent_from_attr_paper,unsigned char attr)

// MACROS
// IN THE FOLLOWING:
//
// PENT  = Palette Entry = Index from 0-63 into ULA+ palette memory
// PENTI = Palette Entry for an INK colour
// PENTP = Palette Entry for a PAPER colour
// ATTR  = Attribute = Standard ZX Spectrum attribute value used to colour screen
//

// GENERATE AN ATTRIBUTE VALUE FROM A PALETTE ENTRY

#define ULAP_ATTR_FROM_GROUP_PAPER_INK(GROUP,PAPER,INK) ((((GROUP)&0x03)<<4)+(((PAPER)&0x07)<<3)+((INK)&0x07))
#define ULAP_ATTR_FROM_PENTP_PENTI(PENTP,PENTI)         ((((PENTP)&0x30)<<2)+(((PENTP)&0x07)<<3)+((PENTI)&0x07))

// GENERATE A PALETTE ENTRY

#define ULAP_PENT_FROM_GROUP_INK(GROUP,INK)      ((((GROUP)&0x03)<<4)+((INK)&0x07))
#define ULAP_PENT_FROM_GROUP_PAPER(GROUP,PAPER)  ((((GROUP)&0x03)<<4)+((PAPER)&0x07)+0x08)

#define ULAP_PENT_FROM_ATTR_INK(A)               ((((A)&0xc0)>>2)+((A)&0x07))
#define ULAP_PENT_FROM_ATTR_PAPER(A)             ((((A)&0xc0)>>2)+((A)&0x07)+0x08)

#define ULAP_PENT_FROM_BORDER(B)                 (((B)&0x07)+0x08)
#define ULAP_PENT_FROM_TIMEX_BORDER(B)           (((B)&0x07)+0x18)

// PALETTE INDICES FOR START OF GROUPS

#define ULAP_PENT_GROUP0  0x00
#define ULAP_PENT_GROUP1  0x10
#define ULAP_PENT_GROUP2  0x20
#define ULAP_PENT_GROUP3  0x30

// COLOUR MACROS
// Generate ULA+ colours from various RGB formats

#define ULAP_COLOR_RGB332(C)  ((((C)&0xe0)>>3)+(((C)&0x1c)<<3)+((C)&0x3))
#define ULAP_COLOR_RGB333(C)  ((((C)&0x1c0)>>4)+(((C)&0x38)<<2)+(((C)&0x6)>>1))
#define ULAP_COLOR_RGB888(C)  ((((C)&0xe00000)>>19)+(((C)&0xe000)>>8)+(((C)&0xc0)>>6))

#define ULAP_COLOR_RGB332_COMP(R,G,B) ((((G)&0x7)<<5)+(((R)&0x7)<<2)+((B)&0x3))
#define ULAP_COLOR_RGB333_COMP(R,G,B) ((((G)&0x7)<<5)+(((R)&0x7)<<2)+(((B)&0x6)>>1))
#define ULAP_COLOR_RGB888_COMP(R,G,B) (((G)&0xe0)+(((R)&0xe0)>>3)+(((B)&0xc0)>>6))

// SELECTION OF PREDEFINED COLOURS

// Monochrome
// http://unwind.se/bgr233/

#define ULAP_COLOR_MONO_BLACK         __ULAP_COLOR_MONO_BLACK
#define ULAP_COLOR_MONO_GREY_0        __ULAP_COLOR_MONO_GREY_0
#define ULAP_COLOR_MONO_GREY_1        __ULAP_COLOR_MONO_GREY_1
#define ULAP_COLOR_MONO_GREY_2        __ULAP_COLOR_MONO_GREY_2
#define ULAP_COLOR_MONO_GREY_3        __ULAP_COLOR_MONO_GREY_3
#define ULAP_COLOR_MONO_WHITE         __ULAP_COLOR_MONO_WHITE

// Amber Screen
// https://sites.google.com/site/ulaplus/

#define ULAP_COLOR_AMBER_0            __ULAP_COLOR_AMBER_0
#define ULAP_COLOR_AMBER_1            __ULAP_COLOR_AMBER_1
#define ULAP_COLOR_AMBER_2            __ULAP_COLOR_AMBER_2
#define ULAP_COLOR_AMBER_3            __ULAP_COLOR_AMBER_3
#define ULAP_COLOR_AMBER_4            __ULAP_COLOR_AMBER_4
#define ULAP_COLOR_AMBER_5            __ULAP_COLOR_AMBER_5
#define ULAP_COLOR_AMBER_6            __ULAP_COLOR_AMBER_6
#define ULAP_COLOR_AMBER_7            __ULAP_COLOR_AMBER_7

// Green Screen
// https://sites.google.com/site/ulaplus/

#define ULAP_COLOR_GREEN_0            __ULAP_COLOR_GREEN_0
#define ULAP_COLOR_GREEN_1            __ULAP_COLOR_GREEN_1
#define ULAP_COLOR_GREEN_2            __ULAP_COLOR_GREEN_2
#define ULAP_COLOR_GREEN_3            __ULAP_COLOR_GREEN_3
#define ULAP_COLOR_GREEN_4            __ULAP_COLOR_GREEN_4
#define ULAP_COLOR_GREEN_5            __ULAP_COLOR_GREEN_5
#define ULAP_COLOR_GREEN_6            __ULAP_COLOR_GREEN_6
#define ULAP_COLOR_GREEN_7            __ULAP_COLOR_GREEN_7

// Rainbow

#define ULAP_COLOR_RB_RED             __ULAP_COLOR_RB_RED
#define ULAP_COLOR_RB_ORANGE          __ULAP_COLOR_RB_ORANGE
#define ULAP_COLOR_RB_YELLOW          __ULAP_COLOR_RB_YELLOW
#define ULAP_COLOR_RB_GREEN           __ULAP_COLOR_RB_GREEN
#define ULAP_COLOR_RB_BLUE            __ULAP_COLOR_RB_BLUE
#define ULAP_COLOR_RB_VIOLET          __ULAP_COLOR_RB_VIOLET
#define ULAP_COLOR_RB_INDIGO          __ULAP_COLOR_RB_INDIGO

// Spectrum
// https://sites.google.com/site/ulaplus/

#define ULAP_COLOR_ZX_BLACK           __ULAP_COLOR_ZX_BLACK
#define ULAP_COLOR_ZX_BLUE            __ULAP_COLOR_ZX_BLUE
#define ULAP_COLOR_ZX_RED             __ULAP_COLOR_ZX_RED
#define ULAP_COLOR_ZX_MAGENTA         __ULAP_COLOR_ZX_MAGENTA
#define ULAP_COLOR_ZX_GREEN           __ULAP_COLOR_ZX_GREEN
#define ULAP_COLOR_ZX_CYAN            __ULAP_COLOR_ZX_CYAN
#define ULAP_COLOR_ZX_YELLOW          __ULAP_COLOR_ZX_YELLOW
#define ULAP_COLOR_ZX_WHITE           __ULAP_COLOR_ZX_WHITE
#define ULAP_COLOR_ZX_BRIGHT_BLACK    __ULAP_COLOR_ZX_BRIGHT_BLACK
#define ULAP_COLOR_ZX_BRIGHT_BLUE     __ULAP_COLOR_ZX_BRIGHT_BLUE
#define ULAP_COLOR_ZX_BRIGHT_RED      __ULAP_COLOR_ZX_BRIGHT_RED
#define ULAP_COLOR_ZX_BRIGHT_MAGENTA  __ULAP_COLOR_ZX_BRIGHT_MAGENTA
#define ULAP_COLOR_ZX_BRIGHT_GREEN    __ULAP_COLOR_ZX_BRIGHT_GREEN
#define ULAP_COLOR_ZX_BRIGHT_CYAN     __ULAP_COLOR_ZX_BRIGHT_CYAN
#define ULAP_COLOR_ZX_BRIGHT_YELLOW   __ULAP_COLOR_ZX_BRIGHT_YELLOW
#define ULAP_COLOR_ZX_BRIGHT_WHITE    __ULAP_COLOR_ZX_BRIGHT_WHITE

// C64
// https://sites.google.com/site/ulaplus/

#define ULAP_COLOR_C64_BLACK          __ULAP_COLOR_C64_BLACK
#define ULAP_COLOR_C64_WHITE          __ULAP_COLOR_C64_WHITE
#define ULAP_COLOR_C64_RED            __ULAP_COLOR_C64_RED
#define ULAP_COLOR_C64_CYAN           __ULAP_COLOR_C64_CYAN
#define ULAP_COLOR_C64_VIOLET         __ULAP_COLOR_C64_VIOLET
#define ULAP_COLOR_C64_GREEN          __ULAP_COLOR_C64_GREEN
#define ULAP_COLOR_C64_BLUE           __ULAP_COLOR_C64_BLUE
#define ULAP_COLOR_C64_YELLOW         __ULAP_COLOR_C64_YELLOW
#define ULAP_COLOR_C64_ORANGE         __ULAP_COLOR_C64_ORANGE
#define ULAP_COLOR_C64_BROWN          __ULAP_COLOR_C64_BROWN
#define ULAP_COLOR_C64_LIGHTRED       __ULAP_COLOR_C64_LIGHTRED
#define ULAP_COLOR_C64_GREY1          __ULAP_COLOR_C64_GREY1
#define ULAP_COLOR_C64_GREY2          __ULAP_COLOR_C64_GREY2
#define ULAP_COLOR_C64_LIGHTGREEN     __ULAP_COLOR_C64_LIGHTGREEN
#define ULAP_COLOR_C64_LIGHTBLUE      __ULAP_COLOR_C64_LIGHTBLUE
#define ULAP_COLOR_C64_GREY3          __ULAP_COLOR_C64_GREY3

// Games 1
// https://www.msx.org/wiki/Setting_up_a_palette

#define ULAP_COLOR_G1_BLACK           __ULAP_COLOR_G1_BLACK
#define ULAP_COLOR_G1_GREY            __ULAP_COLOR_G1_GREY
#define ULAP_COLOR_G1_SILVER          __ULAP_COLOR_G1_SILVER
#define ULAP_COLOR_G1_DARK_TEAL       __ULAP_COLOR_G1_DARK_TEAL
#define ULAP_COLOR_G1_GREEN           __ULAP_COLOR_G1_GREEN
#define ULAP_COLOR_G1_GREENYELLOW     __ULAP_COLOR_G1_GREENYELLOW
#define ULAP_COLOR_G1_MAROON          __ULAP_COLOR_G1_MAROON
#define ULAP_COLOR_G1_SIENNA          __ULAP_COLOR_G1_SIENNA
#define ULAP_COLOR_G1_SANDYBROWN      __ULAP_COLOR_G1_SANDYBROWN
#define ULAP_COLOR_G1_KHAKI           __ULAP_COLOR_G1_KHAKI
#define ULAP_COLOR_G1_WHITE           __ULAP_COLOR_G1_WHITE
#define ULAP_COLOR_G1_SKYBLUE         __ULAP_COLOR_G1_SKYBLUE
#define ULAP_COLOR_G1_SLATEBLUE       __ULAP_COLOR_G1_SLATEBLUE
#define ULAP_COLOR_G1_BLUE            __ULAP_COLOR_G1_BLUE

// Standard
// https://github.com/Gargy007/eGUI/blob/master/D4D/common_files/d4d_scheme.h

#define ULAP_COLOR_STD_DARK_BLUE      __ULAP_COLOR_STD_DARK_BLUE
#define ULAP_COLOR_STD_BRIGHT_BLUE    __ULAP_COLOR_STD_BRIGHT_BLUE
#define ULAP_COLOR_STD_BLUE           __ULAP_COLOR_STD_BLUE
#define ULAP_COLOR_STD_CYAN           __ULAP_COLOR_STD_CYAN
#define ULAP_COLOR_STD_BRIGHT_YELLOW  __ULAP_COLOR_STD_BRIGHT_YELLOW
#define ULAP_COLOR_STD_YELLOW         __ULAP_COLOR_STD_YELLOW
#define ULAP_COLOR_STD_ORANGE         __ULAP_COLOR_STD_ORANGE
#define ULAP_COLOR_STD_BRIGHT_RED     __ULAP_COLOR_STD_BRIGHT_RED
#define ULAP_COLOR_STD_RED            __ULAP_COLOR_STD_RED
#define ULAP_COLOR_STD_DARK_RED       __ULAP_COLOR_STD_DARK_RED
#define ULAP_COLOR_STD_MAGENTA        __ULAP_COLOR_STD_MAGENTA
#define ULAP_COLOR_STD_BRIGHT_GREEN   __ULAP_COLOR_STD_BRIGHT_GREEN
#define ULAP_COLOR_STD_GREEN          __ULAP_COLOR_STD_GREEN
#define ULAP_COLOR_STD_DARK_GREEN     __ULAP_COLOR_STD_DARK_GREEN
#define ULAP_COLOR_STD_BRIGHT_GREY    __ULAP_COLOR_STD_BRIGHT_GREY
#define ULAP_COLOR_STD_LIGHT_GREY     __ULAP_COLOR_STD_LIGHT_GREY
#define ULAP_COLOR_STD_GREY           __ULAP_COLOR_STD_GREY
#define ULAP_COLOR_STD_WHITE          __ULAP_COLOR_STD_WHITE
#define ULAP_COLOR_STD_BLACK          __ULAP_COLOR_STD_BLACK

// HTML
// Thanks to GreW at WOS

#define ULAP_COLOR_HTML_Black                 __ULAP_COLOR_HTML_Black
#define ULAP_COLOR_HTML_Navy                  __ULAP_COLOR_HTML_Navy
#define ULAP_COLOR_HTML_DarkBlue              __ULAP_COLOR_HTML_DarkBlue
#define ULAP_COLOR_HTML_MediumBlue            __ULAP_COLOR_HTML_MediumBlue
#define ULAP_COLOR_HTML_Blue                  __ULAP_COLOR_HTML_Blue
#define ULAP_COLOR_HTML_DarkGreen             __ULAP_COLOR_HTML_DarkGreen
#define ULAP_COLOR_HTML_Green                 __ULAP_COLOR_HTML_Green
#define ULAP_COLOR_HTML_Teal                  __ULAP_COLOR_HTML_Teal
#define ULAP_COLOR_HTML_DarkCyan              __ULAP_COLOR_HTML_DarkCyan
#define ULAP_COLOR_HTML_DeepSkyBlue           __ULAP_COLOR_HTML_DeepSkyBlue
#define ULAP_COLOR_HTML_DarkTurquoise         __ULAP_COLOR_HTML_DarkTurquoise
#define ULAP_COLOR_HTML_MediumSpringGreen     __ULAP_COLOR_HTML_MediumSpringGreen
#define ULAP_COLOR_HTML_Lime                  __ULAP_COLOR_HTML_Lime
#define ULAP_COLOR_HTML_SpringGreen           __ULAP_COLOR_HTML_SpringGreen
#define ULAP_COLOR_HTML_Aqua                  __ULAP_COLOR_HTML_Aqua
#define ULAP_COLOR_HTML_Cyan                  __ULAP_COLOR_HTML_Cyan
#define ULAP_COLOR_HTML_MidnightBlue          __ULAP_COLOR_HTML_MidnightBlue
#define ULAP_COLOR_HTML_DodgerBlue            __ULAP_COLOR_HTML_DodgerBlue
#define ULAP_COLOR_HTML_LightSeaGreen         __ULAP_COLOR_HTML_LightSeaGreen
#define ULAP_COLOR_HTML_ForestGreen           __ULAP_COLOR_HTML_ForestGreen
#define ULAP_COLOR_HTML_SeaGreen              __ULAP_COLOR_HTML_SeaGreen
#define ULAP_COLOR_HTML_DarkSlateGray         __ULAP_COLOR_HTML_DarkSlateGray
#define ULAP_COLOR_HTML_DarkSlateGrey         __ULAP_COLOR_HTML_DarkSlateGrey
#define ULAP_COLOR_HTML_LimeGreen             __ULAP_COLOR_HTML_LimeGreen
#define ULAP_COLOR_HTML_MediumSeaGreen        __ULAP_COLOR_HTML_MediumSeaGreen
#define ULAP_COLOR_HTML_Turquoise             __ULAP_COLOR_HTML_Turquoise
#define ULAP_COLOR_HTML_RoyalBlue             __ULAP_COLOR_HTML_RoyalBlue
#define ULAP_COLOR_HTML_SteelBlue             __ULAP_COLOR_HTML_SteelBlue
#define ULAP_COLOR_HTML_DarkSlateBlue         __ULAP_COLOR_HTML_DarkSlateBlue
#define ULAP_COLOR_HTML_MediumTurquoise       __ULAP_COLOR_HTML_MediumTurquoise
#define ULAP_COLOR_HTML_Indigo                __ULAP_COLOR_HTML_Indigo
#define ULAP_COLOR_HTML_DarkOliveGreen        __ULAP_COLOR_HTML_DarkOliveGreen
#define ULAP_COLOR_HTML_CadetBlue             __ULAP_COLOR_HTML_CadetBlue
#define ULAP_COLOR_HTML_CornflowerBlue        __ULAP_COLOR_HTML_CornflowerBlue
#define ULAP_COLOR_HTML_RebeccaPurple         __ULAP_COLOR_HTML_RebeccaPurple
#define ULAP_COLOR_HTML_MediumAquaMarine      __ULAP_COLOR_HTML_MediumAquaMarine
#define ULAP_COLOR_HTML_DimGray               __ULAP_COLOR_HTML_DimGray
#define ULAP_COLOR_HTML_DimGrey               __ULAP_COLOR_HTML_DimGrey
#define ULAP_COLOR_HTML_SlateBlue             __ULAP_COLOR_HTML_SlateBlue
#define ULAP_COLOR_HTML_OliveDrab             __ULAP_COLOR_HTML_OliveDrab
#define ULAP_COLOR_HTML_SlateGray             __ULAP_COLOR_HTML_SlateGray
#define ULAP_COLOR_HTML_SlateGrey             __ULAP_COLOR_HTML_SlateGrey
#define ULAP_COLOR_HTML_LightSlateGray        __ULAP_COLOR_HTML_LightSlateGray
#define ULAP_COLOR_HTML_LightSlateGrey        __ULAP_COLOR_HTML_LightSlateGrey
#define ULAP_COLOR_HTML_MediumSlateBlue       __ULAP_COLOR_HTML_MediumSlateBlue
#define ULAP_COLOR_HTML_LawnGreen             __ULAP_COLOR_HTML_LawnGreen
#define ULAP_COLOR_HTML_Chartreuse            __ULAP_COLOR_HTML_Chartreuse
#define ULAP_COLOR_HTML_Aquamarine            __ULAP_COLOR_HTML_Aquamarine
#define ULAP_COLOR_HTML_Maroon                __ULAP_COLOR_HTML_Maroon
#define ULAP_COLOR_HTML_Purple                __ULAP_COLOR_HTML_Purple
#define ULAP_COLOR_HTML_Olive                 __ULAP_COLOR_HTML_Olive
#define ULAP_COLOR_HTML_Gray                  __ULAP_COLOR_HTML_Gray
#define ULAP_COLOR_HTML_Grey                  __ULAP_COLOR_HTML_Grey
#define ULAP_COLOR_HTML_SkyBlue               __ULAP_COLOR_HTML_SkyBlue
#define ULAP_COLOR_HTML_LightSkyBlue          __ULAP_COLOR_HTML_LightSkyBlue
#define ULAP_COLOR_HTML_BlueViolet            __ULAP_COLOR_HTML_BlueViolet
#define ULAP_COLOR_HTML_DarkRed               __ULAP_COLOR_HTML_DarkRed
#define ULAP_COLOR_HTML_DarkMagenta           __ULAP_COLOR_HTML_DarkMagenta
#define ULAP_COLOR_HTML_SaddleBrown           __ULAP_COLOR_HTML_SaddleBrown
#define ULAP_COLOR_HTML_DarkSeaGreen          __ULAP_COLOR_HTML_DarkSeaGreen
#define ULAP_COLOR_HTML_LightGreen            __ULAP_COLOR_HTML_LightGreen
#define ULAP_COLOR_HTML_MediumPurple          __ULAP_COLOR_HTML_MediumPurple
#define ULAP_COLOR_HTML_DarkViolet            __ULAP_COLOR_HTML_DarkViolet
#define ULAP_COLOR_HTML_PaleGreen             __ULAP_COLOR_HTML_PaleGreen
#define ULAP_COLOR_HTML_DarkOrchid            __ULAP_COLOR_HTML_DarkOrchid
#define ULAP_COLOR_HTML_YellowGreen           __ULAP_COLOR_HTML_YellowGreen
#define ULAP_COLOR_HTML_Sienna                __ULAP_COLOR_HTML_Sienna
#define ULAP_COLOR_HTML_Brown                 __ULAP_COLOR_HTML_Brown
#define ULAP_COLOR_HTML_DarkGray              __ULAP_COLOR_HTML_DarkGray
#define ULAP_COLOR_HTML_DarkGrey              __ULAP_COLOR_HTML_DarkGrey
#define ULAP_COLOR_HTML_LightBlue             __ULAP_COLOR_HTML_LightBlue
#define ULAP_COLOR_HTML_GreenYellow           __ULAP_COLOR_HTML_GreenYellow
#define ULAP_COLOR_HTML_PaleTurquoise         __ULAP_COLOR_HTML_PaleTurquoise
#define ULAP_COLOR_HTML_LightSteelBlue        __ULAP_COLOR_HTML_LightSteelBlue
#define ULAP_COLOR_HTML_PowderBlue            __ULAP_COLOR_HTML_PowderBlue
#define ULAP_COLOR_HTML_FireBrick             __ULAP_COLOR_HTML_FireBrick
#define ULAP_COLOR_HTML_DarkGoldenRod         __ULAP_COLOR_HTML_DarkGoldenRod
#define ULAP_COLOR_HTML_MediumOrchid          __ULAP_COLOR_HTML_MediumOrchid
#define ULAP_COLOR_HTML_RosyBrown             __ULAP_COLOR_HTML_RosyBrown
#define ULAP_COLOR_HTML_DarkKhaki             __ULAP_COLOR_HTML_DarkKhaki
#define ULAP_COLOR_HTML_Silver                __ULAP_COLOR_HTML_Silver
#define ULAP_COLOR_HTML_MediumVioletRed       __ULAP_COLOR_HTML_MediumVioletRed
#define ULAP_COLOR_HTML_IndianRed             __ULAP_COLOR_HTML_IndianRed
#define ULAP_COLOR_HTML_Peru                  __ULAP_COLOR_HTML_Peru
#define ULAP_COLOR_HTML_Chocolate             __ULAP_COLOR_HTML_Chocolate
#define ULAP_COLOR_HTML_Tan                   __ULAP_COLOR_HTML_Tan
#define ULAP_COLOR_HTML_LightGray             __ULAP_COLOR_HTML_LightGray
#define ULAP_COLOR_HTML_LightGrey             __ULAP_COLOR_HTML_LightGrey
#define ULAP_COLOR_HTML_Thistle               __ULAP_COLOR_HTML_Thistle
#define ULAP_COLOR_HTML_Orchid                __ULAP_COLOR_HTML_Orchid
#define ULAP_COLOR_HTML_GoldenRod             __ULAP_COLOR_HTML_GoldenRod
#define ULAP_COLOR_HTML_PaleVioletRed         __ULAP_COLOR_HTML_PaleVioletRed
#define ULAP_COLOR_HTML_Crimson               __ULAP_COLOR_HTML_Crimson
#define ULAP_COLOR_HTML_Gainsboro             __ULAP_COLOR_HTML_Gainsboro
#define ULAP_COLOR_HTML_Plum                  __ULAP_COLOR_HTML_Plum
#define ULAP_COLOR_HTML_BurlyWood             __ULAP_COLOR_HTML_BurlyWood
#define ULAP_COLOR_HTML_LightCyan             __ULAP_COLOR_HTML_LightCyan
#define ULAP_COLOR_HTML_Lavender              __ULAP_COLOR_HTML_Lavender
#define ULAP_COLOR_HTML_DarkSalmon            __ULAP_COLOR_HTML_DarkSalmon
#define ULAP_COLOR_HTML_Violet                __ULAP_COLOR_HTML_Violet
#define ULAP_COLOR_HTML_PaleGoldenRod         __ULAP_COLOR_HTML_PaleGoldenRod
#define ULAP_COLOR_HTML_LightCoral            __ULAP_COLOR_HTML_LightCoral
#define ULAP_COLOR_HTML_Khaki                 __ULAP_COLOR_HTML_Khaki
#define ULAP_COLOR_HTML_AliceBlue             __ULAP_COLOR_HTML_AliceBlue
#define ULAP_COLOR_HTML_HoneyDew              __ULAP_COLOR_HTML_HoneyDew
#define ULAP_COLOR_HTML_Azure                 __ULAP_COLOR_HTML_Azure
#define ULAP_COLOR_HTML_SandyBrown            __ULAP_COLOR_HTML_SandyBrown
#define ULAP_COLOR_HTML_Wheat                 __ULAP_COLOR_HTML_Wheat
#define ULAP_COLOR_HTML_Beige                 __ULAP_COLOR_HTML_Beige
#define ULAP_COLOR_HTML_WhiteSmoke            __ULAP_COLOR_HTML_WhiteSmoke
#define ULAP_COLOR_HTML_MintCream             __ULAP_COLOR_HTML_MintCream
#define ULAP_COLOR_HTML_GhostWhite            __ULAP_COLOR_HTML_GhostWhite
#define ULAP_COLOR_HTML_Salmon                __ULAP_COLOR_HTML_Salmon
#define ULAP_COLOR_HTML_AntiqueWhite          __ULAP_COLOR_HTML_AntiqueWhite
#define ULAP_COLOR_HTML_Linen                 __ULAP_COLOR_HTML_Linen
#define ULAP_COLOR_HTML_LightGoldenRodYellow  __ULAP_COLOR_HTML_LightGoldenRodYellow
#define ULAP_COLOR_HTML_OldLace               __ULAP_COLOR_HTML_OldLace
#define ULAP_COLOR_HTML_Red                   __ULAP_COLOR_HTML_Red
#define ULAP_COLOR_HTML_Fuchsia               __ULAP_COLOR_HTML_Fuchsia
#define ULAP_COLOR_HTML_Magenta               __ULAP_COLOR_HTML_Magenta
#define ULAP_COLOR_HTML_DeepPink              __ULAP_COLOR_HTML_DeepPink
#define ULAP_COLOR_HTML_OrangeRed             __ULAP_COLOR_HTML_OrangeRed
#define ULAP_COLOR_HTML_Tomato                __ULAP_COLOR_HTML_Tomato
#define ULAP_COLOR_HTML_HotPink               __ULAP_COLOR_HTML_HotPink
#define ULAP_COLOR_HTML_Coral                 __ULAP_COLOR_HTML_Coral
#define ULAP_COLOR_HTML_DarkOrange            __ULAP_COLOR_HTML_DarkOrange
#define ULAP_COLOR_HTML_LightSalmon           __ULAP_COLOR_HTML_LightSalmon
#define ULAP_COLOR_HTML_Orange                __ULAP_COLOR_HTML_Orange
#define ULAP_COLOR_HTML_LightPink             __ULAP_COLOR_HTML_LightPink
#define ULAP_COLOR_HTML_Pink                  __ULAP_COLOR_HTML_Pink
#define ULAP_COLOR_HTML_Gold                  __ULAP_COLOR_HTML_Gold
#define ULAP_COLOR_HTML_PeachPuff             __ULAP_COLOR_HTML_PeachPuff
#define ULAP_COLOR_HTML_NavajoWhite           __ULAP_COLOR_HTML_NavajoWhite
#define ULAP_COLOR_HTML_Moccasin              __ULAP_COLOR_HTML_Moccasin
#define ULAP_COLOR_HTML_Bisque                __ULAP_COLOR_HTML_Bisque
#define ULAP_COLOR_HTML_MistyRose             __ULAP_COLOR_HTML_MistyRose
#define ULAP_COLOR_HTML_BlanchedAlmond        __ULAP_COLOR_HTML_BlanchedAlmond
#define ULAP_COLOR_HTML_PapayaWhip            __ULAP_COLOR_HTML_PapayaWhip
#define ULAP_COLOR_HTML_LavenderBlush         __ULAP_COLOR_HTML_LavenderBlush
#define ULAP_COLOR_HTML_SeaShell              __ULAP_COLOR_HTML_SeaShell
#define ULAP_COLOR_HTML_Cornsilk              __ULAP_COLOR_HTML_Cornsilk
#define ULAP_COLOR_HTML_LemonChiffon          __ULAP_COLOR_HTML_LemonChiffon
#define ULAP_COLOR_HTML_FloralWhite           __ULAP_COLOR_HTML_FloralWhite
#define ULAP_COLOR_HTML_Snow                  __ULAP_COLOR_HTML_Snow
#define ULAP_COLOR_HTML_Yellow                __ULAP_COLOR_HTML_Yellow
#define ULAP_COLOR_HTML_LightYellow           __ULAP_COLOR_HTML_LightYellow
#define ULAP_COLOR_HTML_Ivory                 __ULAP_COLOR_HTML_Ivory
#define ULAP_COLOR_HTML_White                 __ULAP_COLOR_HTML_White

#endif
