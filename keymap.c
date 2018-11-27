#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_french.h"
#include "muse.h"

extern keymap_config_t keymap_config;

 planck_layers {
  _AZERTY,
  _ALTERED,
  _SPECIAL,
  _CONFIG
};

enum planck_keycodes {
  AZERTY = SAFE_RANGE,
  BACKLIT
};

#define ALTERED MO(_ALTERED)
#define SPECIAL MO(_SPECIAL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* AZERTY
 * This is a basic azerty layer with some layers modifiers and two enter keys to keep touch typing
 * comfortable while programming
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   W  |   X  |   C  |   V  |   B  |   N  |  ,?  |  ;.  |  :/  |  !§  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  AL  |  GUI | Ctrl |SPECIA|    Space    |ALTERD| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_AZERTY] = LAYOUT_planck_grid(
    KC_TAB,  FR_A,    FR_Z,    KC_E,    KC_R,      KC_T,    KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  FR_Q,    KC_S,    KC_D,    KC_F,      KC_G,    KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, FR_W,    KC_X,    KC_C,    KC_V,      KC_B,    KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    _______, KC_LALT, KC_LGUI, KC_LCTL, SPECIAL,   KC_SPC,  KC_SPC,  ALTERED,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT

),

/* ALTERED
 * this is a french accentuated/altered characters and general programming special characters layers
 * ,-----------------------------------------------------------------------------------.
 * |   ²  |   &  |   é  |   "  |   '  |   (  |   )  |   ù  |   +  |   °  |   ¨  |   `  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Esc |   à  |   è  |   >  |   <  |   {  |   }  |   -  |   _  |   |  |   ^  |   $  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   #  |   @  |   €  |   ç  |   *  |   [  |   ]  |   =  |   %  |   \  |   £  |   ~  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 FR_OVRR
 FR_PERC
*/
[_ALTERED] = LAYOUT_planck_grid(
    FR_SUP2,  FR_AMP,   FR_EACU, FR_QUOT, FR_APOS, FR_LPRN, FR_RPRN, FR_UGRV, FR_PLUS, FR_OVRR, FR_UMLT,  FR_GRV, 
    KC_ESC,   FR_AGRV,  FR_EGRV, FR_GRTR, FR_LESS, FR_LCBR, FR_RCBR, FR_MINS, FR_UNDS, FR_PIPE, FR_CIRC,  FR_DLR,
    FR_HASH,  FR_AT,    FR_EURO, FR_CCED, FR_ASTR, FR_LBRC, FR_RBRC, FR_EQL,  FR_PERC, FR_BSLS, FR_PND,   FR_TILD,
    FR_SECT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* SPECIAL
 * Almost no changes from default here, but will soon be almost totally re-written
 * It should contain a number grid, a function keys grid (if I don't put these on their own layer),
 * and some media/utility keys/macros
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_SPECIAL] = LAYOUT_planck_grid(
    FR_TILD,  FR_1,    FR_2,    FR_3,    FR_4,    FR_5,    FR_6,    FR_7,    FR_8,    FR_9,    FR_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* CONFIG (ALTERED + SPECIAL)
 * this layer should contain only keyboard configuration and features controls, such as
 * backlight, rgb, music mode, layouts enabled, etc
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_CONFIG] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, AZERTY,  _______, _______,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _ALTERED, _SPECIAL, _CONFIG);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case AZERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_AZERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_SPECIAL)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_CONFIG);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_CONFIG);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case SPECIAL:
    case ALTERED:
      return false;
    default:
      return true;
  }
}
