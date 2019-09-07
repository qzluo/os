/* 割り込み関係 */

#include "bootpack.h"
#include <stdio.h>

void init_pic(void)
/* PICの初期化 */
{
	io_out8(PIC0_IMR,  0xff  ); /* 全ての割り込みを受け付けない */
	io_out8(PIC1_IMR,  0xff  ); /* 全ての割り込みを受け付けない */

	io_out8(PIC0_ICW1, 0x11  ); /* エッジトリガモード */
	io_out8(PIC0_ICW2, 0x20  ); /* IRQ0-7は、INT20-27で受ける */
	io_out8(PIC0_ICW3, 1 << 2); /* PIC1はIRQ2にて接続 */
	io_out8(PIC0_ICW4, 0x01  ); /* ノンバッファモード */

	io_out8(PIC1_ICW1, 0x11  ); /* エッジトリガモード */
	io_out8(PIC1_ICW2, 0x28  ); /* IRQ8-15は、INT28-2fで受ける */
	io_out8(PIC1_ICW3, 2     ); /* PIC1はIRQ2にて接続 */
	io_out8(PIC1_ICW4, 0x01  ); /* ノンバッファモード */

	io_out8(PIC0_IMR,  0xfb  ); /* 11111011 PIC1以外は全て禁止 */
	io_out8(PIC1_IMR,  0xff  ); /* 11111111 全ての割り込みを受け付けない */

	return;
}

void inthandler27(int *esp)
/* PIC0､ｫ､鬢ﾎｲｻﾍ�ﾈｫｸ�､�ﾞz､ﾟ拳ｲﾟ */
/* Athlon64X2僂､ﾊ､ﾉ､ﾇ､ﾏ･ﾁ･ﾃ･ﾗ･ｻ･ﾃ･ﾈ､ﾎｶｼｺﾏ､ﾋ､隍鷄IC､ﾎｳ�ﾆﾚｻｯ瓶､ﾋ､ｳ､ﾎｸ�､�ﾞz､ﾟ､ｬ1ｶﾈ､ﾀ､ｱ､ｪ､ｳ､� */
/* ､ｳ､ﾎｸ�､�ﾞz､ﾟИﾀ�騅ﾊ�､ﾏ｡｢､ｽ､ﾎｸ�､�ﾞz､ﾟ､ﾋ拳､ｷ､ﾆｺﾎ､筅ｷ､ﾊ､､､ﾇ､荀�ﾟ^､ｴ､ｹ */
/* ､ﾊ､ｼｺﾎ､筅ｷ､ﾊ､ｯ､ﾆ､､､､､ﾎ｣ｿ
	｡�  ､ｳ､ﾎｸ�､�ﾞz､ﾟ､ﾏPICｳ�ﾆﾚｻｯ瓶､ﾎ�噛ﾝｵﾄ､ﾊ･ﾎ･､･ｺ､ﾋ､隍ﾃ､ﾆｰkﾉ�､ｷ､ｿ､筅ﾎ､ﾊ､ﾎ､ﾇ｡｢
		､ﾞ､ｸ､皃ﾋｺﾎ､ｫИﾀ�､ｷ､ﾆ､荀�ｱﾘﾒｪ､ｬ､ﾊ､､｡｣									*/
{
	io_out8(PIC0_OCW2, 0x67); /* IRQ-07ﾊﾜｸｶﾍ�ﾁﾋ､�PIC､ﾋﾍｨﾖｪ */
	return;
}
