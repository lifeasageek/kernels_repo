/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __DRM_I2C_TDA998X_H__
#define __DRM_I2C_TDA998X_H__

#include <linux/hdmi.h>
#include <dt-bindings/display/tda998x.h>

enum {
	AFMT_UNUSED =	0,
	AFMT_SPDIF =	TDA998x_SPDIF,
	AFMT_I2S =	TDA998x_I2S,
};

struct tda998x_audio_params {
	u8 config;
	u8 format;
	unsigned sample_width;
	unsigned sample_rate;
	struct hdmi_audio_infoframe cea;
	u8 status[5];
};

struct tda998x_encoder_params {
	u8 swap_b;
	u8 mirr_b;
	u8 swap_a;
	u8 mirr_a;
	u8 swap_d;
	u8 mirr_d;
	u8 swap_c;
	u8 mirr_c;
	u8 swap_f;
	u8 mirr_f;
	u8 swap_e;
	u8 mirr_e;

	struct tda998x_audio_params audio_params;
};

#endif
