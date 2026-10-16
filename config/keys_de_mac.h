/*
 * Keycodes for the macOS "German" (Deutsch) input source.
 *
 * ZMK keycodes are named after US key positions; these aliases name the
 * character the German Mac layout produces. Verified against the layout with
 * UCKeyTranslate.
 *
 * `<`/`>` depend on the keyboard type macOS assigns to the Corne. It has none
 * stored, so macOS treats it as ANSI, where GRAVE produces `<`/`>` (and NUBS
 * produces `^`/`°`). If the type is ever set to ISO, macOS swaps those two keys
 * and DE_LT/DE_GT must become NUBS.
 *
 * Dead keys (^ ` ´ ~) are macros in corne.keymap that add a space, so they
 * print the character directly.
 */

#pragma once

/* Letters that move compared to US */
#define DE_Z      Y
#define DE_Y      Z
#define DE_UE     LBKT
#define DE_OE     SEMI
#define DE_AE     SQT
#define DE_SZ     MINUS

/* Shift + number row */
#define DE_EXCL   LS(N1)
#define DE_DQT    LS(N2)
#define DE_SECT   LS(N3)
#define DE_DLLR   LS(N4)
#define DE_PRCNT  LS(N5)
#define DE_AMPS   LS(N6)
#define DE_SLSH   LS(N7)
#define DE_LPAR   LS(N8)
#define DE_RPAR   LS(N9)
#define DE_EQUAL  LS(N0)
#define DE_QMARK  LS(MINUS)

/* Other keys */
#define DE_PLUS   RBKT
#define DE_ASTRK  LS(RBKT)
#define DE_HASH   BSLH
#define DE_SQT    LS(BSLH)
#define DE_COMMA  COMMA
#define DE_SEMI   LS(COMMA)
#define DE_DOT    DOT
#define DE_COLON  LS(DOT)
#define DE_MINUS  FSLH
#define DE_UNDER  LS(FSLH)
#define DE_LT     GRAVE
#define DE_GT     LS(GRAVE)

/* Option layer */
#define DE_AT     LA(L)
#define DE_EURO   LA(E)
#define DE_LBKT   LA(N5)
#define DE_RBKT   LA(N6)
#define DE_LBRC   LA(N8)
#define DE_RBRC   LA(N9)
#define DE_PIPE   LA(N7)
#define DE_BSLH   LA(LS(N7))

/* Dead keys (only usable followed by another key) */
#define DE_DEAD_CARET  LA(LS(N6))
#define DE_DEAD_GRAVE  LS(EQUAL)
#define DE_DEAD_TILDE  LA(N)
