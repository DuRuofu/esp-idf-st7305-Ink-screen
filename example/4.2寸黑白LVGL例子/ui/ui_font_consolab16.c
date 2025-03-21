/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --user-data-dir=C:\Users\liuzewen\AppData\Roaming\eezstudio --app-path=C:\Users\liuzewen\AppData\Local\Programs\eezstudio\resources\app.asar --no-sandbox --no-zygote --node-integration-in-worker --lang=zh-CN --device-scale-factor=1.25 --num-raster-threads=4 --enable-main-frame-before-activation --renderer-client-id=5 --time-ticks-at-unix-epoch=-1730890786246894 --launch-time-ticks=2927978998 --mojo-platform-channel-handle=4036 --field-trial-handle=2200,i,5657085012181094998,1195354816607637950,262144 --enable-features=kWebSQLAccess --disable-features=SpareRendererForSitePerProcess,WinDelaySpellcheckServiceInit,WinRetrieveSuggestionsOnlyOnDemand --variations-seed-version /prefetch:1
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl.h"
#endif

#ifndef UI_FONT_CONSOLAB16
#define UI_FONT_CONSOLAB16 1
#endif

#if UI_FONT_CONSOLAB16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xdb, 0x6d, 0xb6, 0x3, 0x80,

    /* U+0022 "\"" */
    0xde, 0xf7, 0xb0,

    /* U+0023 "#" */
    0x26, 0x26, 0xff, 0x66, 0x66, 0x66, 0xff, 0x64,
    0x64, 0x4c,

    /* U+0024 "$" */
    0x8, 0x11, 0xf7, 0xed, 0x1e, 0x1e, 0x1f, 0x16,
    0x6f, 0xff, 0xe2, 0x4, 0x0,

    /* U+0025 "%" */
    0x71, 0xed, 0xb7, 0xce, 0xc0, 0xc0, 0xe0, 0x60,
    0x6e, 0x7d, 0xb6, 0xf1, 0xc0,

    /* U+0026 "&" */
    0x38, 0x32, 0x19, 0xc, 0x87, 0xc1, 0xc1, 0xed,
    0x9e, 0xcf, 0x63, 0x1f, 0xc0,

    /* U+0027 "'" */
    0xff,

    /* U+0028 "(" */
    0x19, 0x98, 0xcc, 0x63, 0x18, 0xc6, 0x18, 0xe3,
    0xc,

    /* U+0029 ")" */
    0xc3, 0xc, 0x61, 0x8c, 0x63, 0x18, 0xcc, 0xe6,
    0x60,

    /* U+002A "*" */
    0x11, 0xa9, 0xf3, 0xed, 0x42, 0x0,

    /* U+002B "+" */
    0x18, 0x18, 0x18, 0xff, 0x18, 0x18, 0x18,

    /* U+002C "," */
    0x27, 0x73, 0x2c,

    /* U+002D "-" */
    0xf8,

    /* U+002E "." */
    0xff, 0x80,

    /* U+002F "/" */
    0x6, 0x18, 0x30, 0xc1, 0x82, 0xc, 0x18, 0x60,
    0xc3, 0x6, 0x8, 0x0,

    /* U+0030 "0" */
    0x3c, 0x66, 0xc3, 0xc7, 0xdf, 0xfb, 0xf3, 0xc3,
    0x66, 0x3c,

    /* U+0031 "1" */
    0x39, 0xf3, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x19,
    0xfc,

    /* U+0032 "2" */
    0x7d, 0x8c, 0x18, 0x30, 0xe1, 0x86, 0x18, 0x61,
    0xfc,

    /* U+0033 "3" */
    0x7c, 0x6, 0x6, 0x6, 0x3c, 0x7, 0x3, 0x3,
    0x6, 0xfc,

    /* U+0034 "4" */
    0xe, 0x1e, 0x1e, 0x36, 0x76, 0x66, 0xc6, 0xff,
    0x6, 0x6,

    /* U+0035 "5" */
    0xfd, 0x83, 0x6, 0xf, 0x81, 0xc1, 0x83, 0xd,
    0xf0,

    /* U+0036 "6" */
    0x3c, 0xc3, 0x6, 0xf, 0xd8, 0xf1, 0xe3, 0x66,
    0x78,

    /* U+0037 "7" */
    0xfe, 0xc, 0x30, 0x61, 0x83, 0xe, 0x18, 0x70,
    0xc0,

    /* U+0038 "8" */
    0x7d, 0x8f, 0x1f, 0x77, 0xcf, 0xbb, 0xe3, 0xc6,
    0xf8,

    /* U+0039 "9" */
    0x39, 0x9b, 0x1e, 0x3c, 0x6f, 0xc1, 0x83, 0xc,
    0xf0,

    /* U+003A ":" */
    0xff, 0x81, 0xff,

    /* U+003B ";" */
    0x77, 0x70, 0x2, 0x77, 0x32, 0xc0,

    /* U+003C "<" */
    0x0, 0x31, 0x9c, 0xe1, 0x83, 0x87, 0xc,

    /* U+003D "=" */
    0xfe, 0x0, 0x7, 0xf0,

    /* U+003E ">" */
    0x3, 0x6, 0xc, 0x1c, 0x67, 0x38, 0xc0,

    /* U+003F "?" */
    0xf0, 0x60, 0xc3, 0xd, 0xe6, 0x18, 0x0, 0x6,
    0x0,

    /* U+0040 "@" */
    0x1e, 0x19, 0x98, 0x6c, 0x3d, 0xff, 0xaf, 0xd7,
    0xeb, 0xf5, 0xfa, 0xb7, 0xd8, 0x6, 0x21, 0xf0,

    /* U+0041 "A" */
    0x1c, 0xe, 0xf, 0x86, 0xc3, 0x63, 0x31, 0x8c,
    0xfe, 0xc3, 0x61, 0xc0,

    /* U+0042 "B" */
    0xfd, 0x8f, 0x1e, 0x3f, 0xd9, 0xf1, 0xe3, 0xcf,
    0xf8,

    /* U+0043 "C" */
    0x3e, 0xc3, 0x86, 0xc, 0x18, 0x30, 0x60, 0x60,
    0x7c,

    /* U+0044 "D" */
    0xfc, 0xc6, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc2,
    0xc6, 0xf8,

    /* U+0045 "E" */
    0xff, 0xc, 0x30, 0xff, 0xc, 0x30, 0xc3, 0xf0,

    /* U+0046 "F" */
    0xff, 0xc, 0x30, 0xc3, 0xfc, 0x30, 0xc3, 0x0,

    /* U+0047 "G" */
    0x1f, 0x61, 0x60, 0xc0, 0xcf, 0xc3, 0xc3, 0xc3,
    0x63, 0x3f,

    /* U+0048 "H" */
    0xc7, 0x8f, 0x1e, 0x3f, 0xf8, 0xf1, 0xe3, 0xc7,
    0x8c,

    /* U+0049 "I" */
    0xfc, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x33, 0xf0,

    /* U+004A "J" */
    0xfc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0x9f, 0xe0,

    /* U+004B "K" */
    0xc6, 0xcc, 0xdc, 0xd8, 0xf0, 0xf0, 0xd8, 0xdc,
    0xce, 0xc6,

    /* U+004C "L" */
    0xc1, 0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1,
    0xfc,

    /* U+004D "M" */
    0xe7, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xdb, 0xc3,
    0xc3, 0xc3,

    /* U+004E "N" */
    0xe3, 0xe3, 0xf3, 0xf3, 0xdb, 0xdb, 0xcf, 0xcf,
    0xc7, 0xc7,

    /* U+004F "O" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0x66, 0x3c,

    /* U+0050 "P" */
    0xfd, 0x9f, 0x1e, 0x3c, 0xff, 0x30, 0x60, 0xc1,
    0x80,

    /* U+0051 "Q" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xe6, 0x7e, 0x18, 0x19, 0xf,

    /* U+0052 "R" */
    0xfc, 0xce, 0xc6, 0xc6, 0xce, 0xf8, 0xcc, 0xcc,
    0xc6, 0xc6,

    /* U+0053 "S" */
    0x3d, 0x83, 0x7, 0x8f, 0xcf, 0xc3, 0x83, 0x7,
    0xf0,

    /* U+0054 "T" */
    0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+0055 "U" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc4,
    0xf8,

    /* U+0056 "V" */
    0xc1, 0xf1, 0x98, 0xcc, 0x66, 0x61, 0xb0, 0xd8,
    0x68, 0x1c, 0xe, 0x0,

    /* U+0057 "W" */
    0xc3, 0xc3, 0xc3, 0xdb, 0xdb, 0xdb, 0xff, 0xef,
    0xe7, 0xe7,

    /* U+0058 "X" */
    0x63, 0x33, 0x8d, 0x87, 0x81, 0xc0, 0xe0, 0xf8,
    0xec, 0x67, 0x71, 0x80,

    /* U+0059 "Y" */
    0xc3, 0xe3, 0x66, 0x76, 0x3c, 0x3c, 0x18, 0x18,
    0x18, 0x18,

    /* U+005A "Z" */
    0xfe, 0x1c, 0x30, 0xe1, 0x86, 0x1c, 0x30, 0xe1,
    0xfc,

    /* U+005B "[" */
    0xfc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcf,

    /* U+005C "\\" */
    0xc0, 0x81, 0x83, 0x3, 0x6, 0x6, 0xc, 0xc,
    0x18, 0x10, 0x30, 0x60,

    /* U+005D "]" */
    0xf3, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3f,

    /* U+005E "^" */
    0x30, 0x71, 0xb2, 0x2c, 0x60,

    /* U+005F "_" */
    0xff, 0x80,

    /* U+0060 "`" */
    0x70, 0xc0,

    /* U+0061 "a" */
    0x7c, 0xc, 0x1b, 0xfc, 0x78, 0xf3, 0xbf,

    /* U+0062 "b" */
    0xc1, 0x83, 0x7, 0xee, 0x78, 0xf1, 0xe3, 0xc7,
    0x9b, 0xe0,

    /* U+0063 "c" */
    0x3e, 0xc7, 0x6, 0xc, 0x18, 0x18, 0x9f,

    /* U+0064 "d" */
    0x6, 0xc, 0x19, 0xf6, 0x78, 0xf1, 0xe3, 0xc7,
    0x9d, 0xf8,

    /* U+0065 "e" */
    0x3c, 0xcf, 0x1f, 0xfc, 0x18, 0x18, 0x1f,

    /* U+0066 "f" */
    0xf, 0x18, 0x18, 0x18, 0x18, 0x7f, 0x18, 0x18,
    0x18, 0x18, 0x18,

    /* U+0067 "g" */
    0x3f, 0xb1, 0x98, 0xcc, 0x63, 0xe3, 0x1, 0x80,
    0x7e, 0x63, 0x31, 0x9f, 0x80,

    /* U+0068 "h" */
    0xc1, 0x83, 0x7, 0xee, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x18,

    /* U+0069 "i" */
    0x38, 0x0, 0x7, 0x83, 0x6, 0xc, 0x18, 0x30,
    0x63, 0xf8,

    /* U+006A "j" */
    0xc, 0x0, 0x3f, 0xc, 0x30, 0xc3, 0xc, 0x30,
    0xc3, 0x1f, 0xc0,

    /* U+006B "k" */
    0xc1, 0x83, 0x6, 0x7c, 0xdb, 0x3c, 0x7c, 0xd9,
    0x9b, 0x18,

    /* U+006C "l" */
    0xf0, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x18, 0x30,
    0x63, 0xf8,

    /* U+006D "m" */
    0xf6, 0xff, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb,

    /* U+006E "n" */
    0xfd, 0xcf, 0x1e, 0x3c, 0x78, 0xf1, 0xe3,

    /* U+006F "o" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+0070 "p" */
    0xfd, 0xcf, 0x1e, 0x3c, 0x78, 0xf3, 0x7c, 0xc1,
    0x83, 0x0,

    /* U+0071 "q" */
    0x3e, 0xcf, 0x1e, 0x3c, 0x78, 0xf3, 0xbf, 0x6,
    0xc, 0x18,

    /* U+0072 "r" */
    0xfd, 0xdb, 0x16, 0xc, 0x18, 0x30, 0x60,

    /* U+0073 "s" */
    0x7d, 0x83, 0x87, 0xc7, 0xc1, 0xc3, 0x7c,

    /* U+0074 "t" */
    0x0, 0x60, 0xc7, 0xf3, 0x6, 0xc, 0x18, 0x30,
    0x60, 0x78,

    /* U+0075 "u" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf3, 0xbf,

    /* U+0076 "v" */
    0xe3, 0x31, 0x98, 0xc6, 0xc3, 0x61, 0xb0, 0x70,
    0x38,

    /* U+0077 "w" */
    0xc1, 0xe0, 0xf2, 0x4b, 0xa5, 0xd3, 0xb9, 0xdc,
    0xce,

    /* U+0078 "x" */
    0x63, 0x3b, 0xd, 0x83, 0x81, 0xc1, 0xb1, 0xdc,
    0xc6,

    /* U+0079 "y" */
    0xc3, 0xc3, 0x66, 0x66, 0x64, 0x3c, 0x3c, 0x18,
    0x18, 0x30, 0xe0,

    /* U+007A "z" */
    0xfc, 0x71, 0x8c, 0x31, 0x8e, 0x3f,

    /* U+007B "{" */
    0x1c, 0xc3, 0xc, 0x30, 0xcc, 0xc, 0x30, 0xc3,
    0xc, 0x30, 0x70,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff,

    /* U+007D "}" */
    0xe0, 0xc3, 0xc, 0x30, 0xc0, 0xcc, 0x30, 0xc3,
    0xc, 0x33, 0x80,

    /* U+007E "~" */
    0x63, 0xdb, 0xce
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 141, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 141, .box_w = 3, .box_h = 11, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 6, .adv_w = 141, .box_w = 5, .box_h = 4, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 9, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 19, .adv_w = 141, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 32, .adv_w = 141, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 45, .adv_w = 141, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 58, .adv_w = 141, .box_w = 2, .box_h = 4, .ofs_x = 3, .ofs_y = 7},
    {.bitmap_index = 59, .adv_w = 141, .box_w = 5, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 68, .adv_w = 141, .box_w = 5, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 77, .adv_w = 141, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 83, .adv_w = 141, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 90, .adv_w = 141, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 93, .adv_w = 141, .box_w = 5, .box_h = 1, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 94, .adv_w = 141, .box_w = 3, .box_h = 3, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 141, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 108, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 118, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 127, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 136, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 146, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 201, .adv_w = 141, .box_w = 3, .box_h = 8, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 204, .adv_w = 141, .box_w = 4, .box_h = 11, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 210, .adv_w = 141, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 141, .box_w = 7, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 221, .adv_w = 141, .box_w = 6, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 228, .adv_w = 141, .box_w = 6, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 237, .adv_w = 141, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 253, .adv_w = 141, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 265, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 274, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 283, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 293, .adv_w = 141, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 141, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 319, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 141, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 336, .adv_w = 141, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 344, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 354, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 363, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 373, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 383, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 402, .adv_w = 141, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 415, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 425, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 434, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 444, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 453, .adv_w = 141, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 465, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 475, .adv_w = 141, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 487, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 506, .adv_w = 141, .box_w = 4, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 513, .adv_w = 141, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 525, .adv_w = 141, .box_w = 4, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 532, .adv_w = 141, .box_w = 7, .box_h = 5, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 537, .adv_w = 141, .box_w = 9, .box_h = 1, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 539, .adv_w = 141, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = 8},
    {.bitmap_index = 541, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 548, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 558, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 565, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 575, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 582, .adv_w = 141, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 593, .adv_w = 141, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 606, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 616, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 626, .adv_w = 141, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 637, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 647, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 657, .adv_w = 141, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 665, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 672, .adv_w = 141, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 680, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 690, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 700, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 707, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 714, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 724, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 731, .adv_w = 141, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 740, .adv_w = 141, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 749, .adv_w = 141, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 758, .adv_w = 141, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 769, .adv_w = 141, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 775, .adv_w = 141, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 786, .adv_w = 141, .box_w = 2, .box_h = 16, .ofs_x = 4, .ofs_y = -3},
    {.bitmap_index = 790, .adv_w = 141, .box_w = 6, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 801, .adv_w = 141, .box_w = 8, .box_h = 3, .ofs_x = 1, .ofs_y = 3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_consolab16 = {
#else
lv_font_t ui_font_consolab16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .fallback = NULL,
    .user_data = NULL
};



#endif /*#if UI_FONT_CONSOLAB16*/

