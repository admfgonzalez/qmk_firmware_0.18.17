/*
MIT License

Copyright (c) 2022 Fgonzalez <administrator@fgonzalez.me>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once

#include "quantum.h"
#define ___ KC_NO

/* matrix layout
   * ,-------------------.
   * | 00 | 01 | 02 | 03 |
   * |----|----|----|    |
   * | 10 | 11 | 12 |----|
   * |----|----|----| 13 |
   * | 20 | 21 | 22 |    |
   * `-------------------'
 */

#define LAYOUT( \
	k00, k01, k02, k03,  \
	k10, k11, k12, k13,   \
	k20, k21, k22  \
) \
{ \
	{k00, k01, k02, k03}, \
	{k10, k11, k12, k13}, \
	{k20, k21, k22, ___} \
}
