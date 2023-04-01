// !!! DO NOT ADD #pragma once !!! //

RGB_MATRIX_EFFECT(base_effect)
RGB_MATRIX_EFFECT(layer_1_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

/* shorthand MYRGB_ colors */
#define RED       0xFF, 0x00, 0x00 // Red
#define ORA       0xFF, 0x7F, 0x00 // Orange
#define YEL       0xFF, 0xFF, 0x00 // Yellow **
#define LIM       0x7F, 0xFF, 0x00 // Lime
#define GRN       0x00, 0xFF, 0x00 // Green **
#define SPR       0x00, 0xFF, 0x7F // Spring Green *
#define CYA       0x00, 0xFF, 0xFF // Cyan *
#define AZU       0x00, 0x7F, 0xFF // Azure **
#define BLU       0x00, 0x00, 0xFF // Blue *
#define IND       0x7F, 0x00, 0xFF // Indigo **
#define MAG       0xFF, 0x00, 0xFF // Magenta *
#define PIN       0xFF, 0x00, 0x7F // Pink **
#define WHI       0xFF, 0xFF, 0xFF // White **


struct RGB_key {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct RGB_key base_rgb[56] = {
    // Left half
    // ╭─────────────────────────────────────────────────────────────────────────────────╮
          [0]={WHI},    [7]={MAG},    [8]={MAG},    [15]={MAG},   [16]={MAG},   [20]={MAG},
    // ├─────────────────────────────────────────────────────────────────────────────────┤
          [1]={BLU},    [6]={AZU},    [9]={AZU},    [14]={AZU},   [17]={AZU},   [21]={AZU},
    // ├─────────────────────────────────────────────────────────────────────────────────┤
          [2]={RED},    [5]={AZU},   [10]={AZU},    [13]={AZU},   [18]={AZU},   [22]={AZU},
    // ├─────────────────────────────────────────────────────────────────────────────────┤
          [3]={GRN},    [4]={AZU},   [11]={AZU},    [12]={AZU},   [19]={AZU},   [23]={AZU},
    // Right half
    // ╭─────────────────────────────────────────────────────────────────────────────────╮
         [49]={MAG},   [45]={MAG},   [44]={MAG},   [37]={MAG},   [36]={MAG},   [29]={WHI},
    // ├─────────────────────────────────────────────────────────────────────────────────┤
         [50]={AZU},   [46]={AZU},   [43]={AZU},   [38]={AZU},   [35]={AZU},   [30]={BLU},
    // ├─────────────────────────────────────────────────────────────────────────────────┤
         [51]={AZU},   [47]={AZU},   [42]={AZU},   [39]={AZU},   [34]={BLU},   [31]={BLU},
    // ├─────────────────────────────────────────────────────────────────────────────────┤
         [52]={AZU},   [48]={AZU},   [41]={BLU},   [40]={BLU},   [33]={BLU},   [32]={GRN},
    // Thumb cluster left and right
    // ╰─────────────────────────────────────────────────────────────────────────────────╯
         [26]={AZU},   [27]={BLU},   [28]={YEL},/**/[53]={WHI},   [54]={AZU},
                       [25]={RED},   [24]={CYA},/**/[55]={CYA},
};

struct RGB_key layer_1_rgb[56] = {
    // Left half
    // ╭─────────────────────────────────────────────────────────────────────────────────╮
          [0]={CYA},    [7]={RED},    [8]={RED},    [15]={RED},   [16]={RED},   [20]={RED},
    // ├─────────────────────────────────────────────────────────────────────────────────┤
          [1]={BLU},    [6]={BLU},    [9]={YEL},    [14]={ORA},   [17]={WHI},   [21]={WHI},
    // ├─────────────────────────────────────────────────────────────────────────────────┤
          [2]={RED},    [5]={IND},   [10]={IND},    [13]={BLU},   [18]={BLU},   [22]={BLU},
    // ├─────────────────────────────────────────────────────────────────────────────────┤
          [3]={GRN},    [4]={IND},   [11]={IND},    [12]={IND},   [19]={IND},   [23]={YEL},
    // Right half
    // ╭─────────────────────────────────────────────────────────────────────────────────╮
         [49]={RED},   [45]={RED},   [44]={RED},   [37]={RED},   [36]={RED},   [29]={CYA},
    // ├─────────────────────────────────────────────────────────────────────────────────┤
         [50]={BLU},   [46]={BLU},   [43]={WHI},   [38]={BLU},   [35]={RED},   [30]={RED},
    // ├─────────────────────────────────────────────────────────────────────────────────┤
         [51]={BLU},   [47]={WHI},   [42]={WHI},   [39]={WHI},   [34]={BLU},   [31]={CYA},
    // ├─────────────────────────────────────────────────────────────────────────────────┤
         [52]={GRN},   [48]={GRN},   [41]={BLU},   [40]={BLU},   [33]={GRN},   [32]={GRN},
    // Thumb cluster left and right
    // ╰─────────────────────────────────────────────────────────────────────────────────╯
         [26]={AZU},   [27]={BLU},   [28]={YEL},/**/[53]={WHI},   [54]={AZU},
                       [25]={RED},   [24]={CYA},/**/[55]={CYA},
};

static bool base_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t value = rgblight_get_val();
    float scale = value / 255.0;

    for(uint8_t i = 0; i < 56; i++) {
        rgb_matrix_set_color(i, base_rgb[i].r*scale, base_rgb[i].g*scale, base_rgb[i].b*scale);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

static bool layer_1_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t value = rgblight_get_val();
    float scale = value / 255.0;

    for(uint8_t i = 0; i < 56; i++) {
        rgb_matrix_set_color(i, layer_1_rgb[i].r*scale, layer_1_rgb[i].g*scale, layer_1_rgb[i].b*scale);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif
