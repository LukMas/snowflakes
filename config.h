/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once


// I don't want to tap a lot to fix a layer
#define TAPPING_TOGGLE 2

// !!! Lets you roll mod-tap keys it allows to type faster irrespective of the sequence of keys
// > shift/a > x then < shift/a < x produces ax - if a lot of times a shifted key is missed, REMOVE!!!!
// #define IGNORE_MOD_TAP_INTERRUPT
// use the following two to tune the way the tap or hold are handled
// #define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS
#define TAPPING_TERM 120
