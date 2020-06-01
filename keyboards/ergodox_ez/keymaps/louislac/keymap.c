#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_french.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  LAC_EAE,
  LAC_EAG,
  LAC_A,
  LAC_U,
  LAC_DOFUS1,
  LAC_DOFUS2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_EQUAL,       FR_AMPR,        FR_EACU,        FR_DQUO,        FR_QUOT,        FR_LPRN,        KC_F5,                                          TG(1),          FR_MINS,        FR_EGRV,        FR_UNDS,        FR_CCED,        FR_AGRV,        FR_RPRN,
    KC_TAB,         FR_A,           FR_Z,           FR_E,           FR_R,           FR_T,           KC_LCBR,                                        KC_RCBR,        FR_Y,           FR_U,           FR_I,           FR_O,           FR_P,           FR_ASTR,
    KC_LCTRL,       FR_Q,           FR_S,           FR_D,           FR_F,           FR_G,                                                                           FR_H,           FR_J,           FR_K,           FR_L,           FR_M,           FR_UGRV,
    KC_RALT,        FR_W,           FR_X,           FR_C,           FR_V,           FR_B,           KC_LBRACKET,                                    KC_RBRACKET,    FR_N,           FR_COMM,        FR_SCLN,        FR_COLN,        FR_EXLM,        KC_RALT,
    FR_CIRC,        FR_GRV,         KC_LALT,        KC_LEFT,        KC_RIGHT,                                                                                                       KC_UP,          KC_DOWN,        FR_LABK,        FR_RABK,        FR_DLR,
                                                                                                    KC_ESCAPE,      KC_LGUI,        KC_RGUI,        KC_ESCAPE,
                                                                                                                    KC_PGDOWN,      KC_PGUP,
                                                                                    KC_SPACE,       KC_DELETE,      LT(1,KC_NO),    LT(2,KC_NO),    KC_ENTER,       KC_BSPACE
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PC_COPY,                                     KC_MY_COMPUTER, KC_TRANSPARENT, KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, KC_F12,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PC_PASTE,                                    KC_CALCULATOR,  KC_TRANSPARENT, KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_SLASH,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(KC_F4),    KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_KP_DOT,      KC_KP_0,        KC_KP_EQUAL,    KC_TRANSPARENT,
                                                                                                    KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_AUDIO_MUTE,  KC_TRANSPARENT,
                                                                                    KC_MEDIA_PLAY_PAUSE,KC_MEDIA_STOP,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const int perso = 8;



rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

bool suspended = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
    case LAC_EAE:
      if (record->event.pressed) {
        SEND_STRING("'e");
      }
      return false;
    case LAC_EAG:
      if (record->event.pressed) {
        SEND_STRING("`e");
      }
      return false;
    case LAC_A:
      if (record->event.pressed) {
        SEND_STRING("`a");
      }
      return false;
    case LAC_U:
      if (record->event.pressed) {
        SEND_STRING("`u");
      }
      return false;
    // changement de map
    case LAC_DOFUS1:
      if (record->event.pressed) {
        for (size_t i = 0; i < (perso - 1); i++)
        {
          SEND_STRING(SS_TAP(X_MS_BTN1) SS_DELAY(20) SS_TAP(X_F7) SS_DELAY(200));
        }
        SEND_STRING(SS_TAP(X_MS_BTN1) SS_DELAY(20) SS_TAP(X_F7));
      }
      return false;
    // rentrer combat
    case LAC_DOFUS2:
      if (record->event.pressed) {
        for (size_t i = 0; i < (perso - 2); i++)
        {
          SEND_STRING(SS_DOWN(X_LSHIFT) SS_DELAY(20) SS_TAP(X_MS_BTN1) SS_DELAY(20) SS_UP(X_LSHIFT) SS_DELAY(20) SS_TAP(X_F7) SS_DELAY(200));
        }
        SEND_STRING(SS_DOWN(X_LSHIFT) SS_DELAY(20) SS_TAP(X_MS_BTN1) SS_DELAY(20) SS_UP(X_LSHIFT) SS_DELAY(20) SS_TAP(X_F7));
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    switch (layer) {
      case 0:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(213,188,255);
        }
        break;
      case 1:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(147,255,255);
        }
        break;
      case 2:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(0,255,255);
        }
        break;
      default:
        if(!disable_layer_color) {
          rgblight_config.raw = eeconfig_read_rgblight();
          if(rgblight_config.enable == true) {
            rgblight_enable();
            rgblight_mode(rgblight_config.mode);
            rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
          }
          else {
            rgblight_disable();
          }
        }
        break;
    }
    return state;

};

void keyboard_post_init_user(void) {
  layer_state_set_user(layer_state);
}
