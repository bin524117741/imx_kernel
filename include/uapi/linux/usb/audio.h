/*
 * <linux/usb/audio.h> -- USB Audio definitions.
 *
 * Copyright (C) 2006 Thumtronics Pty Ltd.
 * Developed for Thumtronics by Grey Innovation
 * Ben Williamson <ben.williamson@greyinnovation.com>
 *
 * This software is distributed under the terms of the GNU General Public
 * License ("GPL") version 2, as published by the Free Software Foundation.
 *
 * This file holds USB constants and structures defined
 * by the USB Device Class Definition for Audio Devices.
 * Comments below reference relevant sections of that document:
 *
 * http://www.usb.org/developers/devclass_docs/audio10.pdf
 *
 * Types and defines in this file are either specific to version 1.0 of
 * this standard or common for newer versions.
 */

#ifndef _UAPI__LINUX_USB_AUDIO_H
#define _UAPI__LINUX_USB_AUDIO_H

#include <linux/types.h>

/* bInterfaceProtocol values to denote the version of the standard used */
#define UAC_VERSION_1			0x00
#define UAC_VERSION_2			0x20

/* A.2 Audio Interface Subclass Codes */
#define USB_SUBCLASS_AUDIOCONTROL	0x01
#define USB_SUBCLASS_AUDIOSTREAMING	0x02
#define USB_SUBCLASS_MIDISTREAMING	0x03

/* A.5 Audio Class-Specific AC Interface Descriptor Subtypes */
#define UAC_HEADER			0x01
#define UAC_INPUT_TERMINAL		0x02
#define UAC_OUTPUT_TERMINAL		0x03
#define UAC_MIXER_UNIT			0x04
#define UAC_SELECTOR_UNIT		0x05
#define UAC_FEATURE_UNIT		0x06
#define UAC1_PROCESSING_UNIT		0x07
#define UAC1_EXTENSION_UNIT		0x08

/* A.6 Audio Class-Specific AS Interface Descriptor Subtypes */
#define UAC_AS_GENERAL			0x01
#define UAC_FORMAT_TYPE			0x02
#define UAC_FORMAT_SPECIFIC		0x03

/* A.7 Processing Unit Process Types */
#define UAC_PROCESS_UNDEFINED		0x00
#define UAC_PROCESS_UP_DOWNMIX		0x01
#define UAC_PROCESS_DOLBY_PROLOGIC	0x02
#define UAC_PROCESS_STEREO_EXTENDER	0x03
#define UAC_PROCESS_REVERB		0x04
#define UAC_PROCESS_CHORUS		0x05
#define UAC_PROCESS_DYN_RANGE_COMP	0x06

/* A.8 Audio Class-Specific Endpoint Descriptor Subtypes */
#define UAC_EP_GENERAL			0x01

/* A.9 Audio Class-Specific Request Codes */
#define UAC_SET_			0x00
#define UAC_GET_			0x80

#define UAC__CUR			0x1
#define UAC__MIN			0x2
#define UAC__MAX			0x3
#define UAC__RES			0x4
#define UAC__MEM			0x5

#define UAC_SET_CUR			(UAC_SET_ | UAC__CUR)
#define UAC_GET_CUR			(UAC_GET_ | UAC__CUR)
#define UAC_SET_MIN			(UAC_SET_ | UAC__MIN)
#define UAC_GET_MIN			(UAC_GET_ | UAC__MIN)
#define UAC_SET_MAX			(UAC_SET_ | UAC__MAX)
#define UAC_GET_MAX			(UAC_GET_ | UAC__MAX)
#define UAC_SET_RES			(UAC_SET_ | UAC__RES)
#define UAC_GET_RES			(UAC_GET_ | UAC__RES)
#define UAC_SET_MEM			(UAC_SET_ | UAC__MEM)
#define UAC_GET_MEM			(UAC_GET_ | UAC__MEM)

#define UAC_GET_STAT			0xff

/* A.10 Control Selector Codes */

/* A.10.1 Terminal Control Selectors */
#define UAC_TERM_COPY_PROTECT		0x01

/* A.10.2 Feature Unit Control Selectors */
#define UAC_FU_MUTE			0x01
#define UAC_FU_VOLUME			0x02
#define UAC_FU_BASS			0x03
#define UAC_FU_MID			0x04
#define UAC_FU_TREBLE			0x05
#define UAC_FU_GRAPHIC_EQUALIZER	0x06
#define UAC_FU_AUTOMATIC_GAIN		0x07
#define UAC_FU_DELAY			0x08
#define UAC_FU_BASS_BOOST		0x09
#define UAC_FU_LOUDNESS			0x0a

#define UAC_CONTROL_BIT(CS)	(1 << ((CS) - 1))

/* A.10.3.1 Up/Down-mix Processing Unit Controls Selectors */
#define UAC_UD_ENABLE			0x01
#define UAC_UD_MODE_SELECT		0x02

/* A.10.3.2 Dolby Prologic (tm) Processing Unit Controls Selectors */
#define UAC_DP_ENABLE			0x01
#define UAC_DP_MODE_SELECT		0x02

/* A.10.3.3 3D Stereo Extender Processing Unit Control Selectors */
#define UAC_3D_ENABLE			0x01
#define UAC_3D_SPACE			0x02

/* A.10.3.4 Reverberation Processing Unit Control Selectors */
#define UAC_REVERB_ENABLE		0x01
#define UAC_REVERB_LEVEL		0x02
#define UAC_REVERB_TIME			0x03
#define UAC_REVERB_FEEDBACK		0x04

/* A.10.3.5 Chorus Processing Unit Control Selectors */
#define UAC_CHORUS_ENABLE		0x01
#define UAC_CHORUS_LEVEL		0x02
#define UAC_CHORUS_RATE			0x03
#define UAC_CHORUS_DEPTH		0x04

/* A.10.3.6 Dynamic Range Compressor Unit Control Selectors */
#define UAC_DCR_ENABLE			0x01
#define UAC_DCR_RATE			0x02
#define UAC_DCR_MAXAMPL			0x03
#define UAC_DCR_THRESHOLD		0x04
#define UAC_DCR_ATTACK_TIME		0x05
#define UAC_DCR_RELEASE_TIME		0x06

/* A.10.4 Extension Unit Control Selectors */
#define UAC_XU_ENABLE			0x01

/* MIDI - A.1 MS Class-Specific Interface Descriptor Subtypes */
#define UAC_MS_HEADER			0x01
#define UAC_MIDI_IN_JACK		0x02
#define UAC_MIDI_OUT_JACK		0x03

/* MIDI - A.1 MS Class-Specific Endpoint Descriptor Subtypes */
#define UAC_MS_GENERAL			0x01

/* Terminals - 2.1 USB Terminal Types */
#define UAC_TERMINAL_UNDEFINED		0x100//未定义的USB终端类型
#define UAC_TERMINAL_STREAMING		0x101//USB流终端
#define UAC_TERMINAL_VENDOR_SPEC	0x1FF//	厂商自定义的终端类型

/* Terminal Control Selectors */
/* 4.3.2  Class-Specific AC Interface Descriptor */
struct uac1_ac_header_descriptor {
	__u8  bLength;//描述符的大小			/* 8 + n */
	__u8  bDescriptorType;//	描述符的类型：音频类接口，代码为：0x24		/* USB_DT_CS_INTERFACE */
	__u8  bDescriptorSubtype;// 描述符子类型，属于音频控制头子类，代码为：0x01	/* UAC_MS_HEADER */
	__le16 bcdADC;			/* 0x0100 */
	/*
		所定义的所有的音频类控制接口描述符的长度总和，
		包括：该头描述符自身的长度 + 单元描述符长度 + 终端描述符的长度
		注：这个长度仅仅指的是控制接口（AC）的长度，并不包含控制接口下的流接口（AS）。
	*/
	__le16 wTotalLength;		/* includes Unit and Terminal desc. */
	__u8  bInCollection;//该音频控制接口所拥有的音频流接口总数，也就是n。		/* n */
	__u8  baInterfaceNr[];		/* [n] */
} __attribute__ ((packed));

#define UAC_DT_AC_HEADER_SIZE(n)	(8 + (n))

/* As above, but more useful for defining your own descriptors: */
#define DECLARE_UAC_AC_HEADER_DESCRIPTOR(n)			\
struct uac1_ac_header_descriptor_##n {			\
	__u8  bLength;						\
	__u8  bDescriptorType;					\
	__u8  bDescriptorSubtype;				\
	__le16 bcdADC;						\
	__le16 wTotalLength;					\
	__u8  bInCollection;					\
	__u8  baInterfaceNr[n];					\
} __attribute__ ((packed))

/* 4.3.2.1 Input Terminal Descriptor */
struct uac_input_terminal_descriptor {
	__u8  bLength;			/* 描述符的大小：12 字节*/
	__u8  bDescriptorType;		/* 描述符的类型：音频类接口，代码为：0x24 */
	__u8  bDescriptorSubtype;	/* 描述符子类型，属于输入终端描述符子类，代码为：0x02 */
	__u8  bTerminalID;		/* 该输入终端的编号(ID)，所有跟终端相关的请求（主机发送到终端的请求）都会通过这个值来访问此终端*/
	__le16 wTerminalType;		/* 输入终端类型 */
	__u8  bAssocTerminal;		/* 与输入终端相关联的输出终端的ID号。输入输出终端是两个端点，配对的。 */
	__u8  bNrChannels;		/* 此终端的输出声道簇中所包含的逻辑输出通道数目(逻辑通道数目)。*/
	__le16 wChannelConfig; /*描述逻辑声道的空间位置*/
	__u8  iChannelNames;/*描述第一个逻辑声道的字符串的索引号，一般填0。*/
	__u8  iTerminal;/*描述该输入终端的字符串的索引号，一般填0。*/
} __attribute__ ((packed));

#define UAC_DT_INPUT_TERMINAL_SIZE			12
/***输入终端类型***/
/* Terminals - 2.2 Input Terminal Types */
#define UAC_INPUT_TERMINAL_UNDEFINED			0x200//未定义的输入终端类型
#define UAC_INPUT_TERMINAL_MICROPHONE			0x201//通用麦克风类型
#define UAC_INPUT_TERMINAL_DESKTOP_MICROPHONE		0x202//桌面麦克风
#define UAC_INPUT_TERMINAL_PERSONAL_MICROPHONE		0x203//头戴式麦克风
#define UAC_INPUT_TERMINAL_OMNI_DIR_MICROPHONE		0x204//全向麦克风
#define UAC_INPUT_TERMINAL_MICROPHONE_ARRAY		0x205//麦克风阵列
#define UAC_INPUT_TERMINAL_PROC_MICROPHONE_ARRAY	0x206

/* Terminals - control selectors */

#define UAC_TERMINAL_CS_COPY_PROTECT_CONTROL		0x01

/* 4.3.2.2 Output Terminal Descriptor */
struct uac1_output_terminal_descriptor {
	__u8  bLength;			/*描述符的大小：9 字节*/
	__u8  bDescriptorType;		/* 描述符的类型：音频类接口，代码为：0x24 */
	__u8  bDescriptorSubtype;	/* 描述符子类型，属于输出终端描述符子类，代码为：0x03*/
	__u8  bTerminalID;		/*该输出终端的编号(ID)，所有跟终端相关的请求（主机发送到终端的请求）都会通过这个值来访问此终端*/
	__le16 wTerminalType;		/* 输出终端类型 */
	__u8  bAssocTerminal;		/*与此输出终端相关联的输入终端的ID号 */
	__u8  bSourceID;		/* 该输出终端的前序连接实体（可以是终端，也可以是单元）的IDl*/
	__u8  iTerminal;/*	描述该输出终端的字符串的索引号*/
} __attribute__ ((packed));

#define UAC_DT_OUTPUT_TERMINAL_SIZE			9

/* Terminals - 2.3 Output Terminal Types */
#define UAC_OUTPUT_TERMINAL_UNDEFINED			0x300//未定义的输出终端类型
#define UAC_OUTPUT_TERMINAL_SPEAKER			0x301//通用扬声器
#define UAC_OUTPUT_TERMINAL_HEADPHONES			0x302//头戴式耳机
#define UAC_OUTPUT_TERMINAL_HEAD_MOUNTED_DISPLAY_AUDIO	0x303//VR头盔听筒
#define UAC_OUTPUT_TERMINAL_DESKTOP_SPEAKER		0x304//桌面扬声器
#define UAC_OUTPUT_TERMINAL_ROOM_SPEAKER		0x305//室内扬声器
#define UAC_OUTPUT_TERMINAL_COMMUNICATION_SPEAKER	0x306//广播扬声器
#define UAC_OUTPUT_TERMINAL_LOW_FREQ_EFFECTS_SPEAKER	0x307

/* Set bControlSize = 2 as default setting */
#define UAC_DT_FEATURE_UNIT_SIZE(ch)		(7 + ((ch) + 1) * 2)

/* As above, but more useful for defining your own descriptors: */
#define DECLARE_UAC_FEATURE_UNIT_DESCRIPTOR(ch)			\
struct uac_feature_unit_descriptor_##ch {			\
	__u8  bLength;						\
	__u8  bDescriptorType;					\
	__u8  bDescriptorSubtype;				\
	__u8  bUnitID;						\
	__u8  bSourceID;					\
	__u8  bControlSize;					\
	__le16 bmaControls[ch + 1];				\
	__u8  iFeature;						\
} __attribute__ ((packed))

/* 4.3.2.3 Mixer Unit Descriptor */
struct uac_mixer_unit_descriptor {
	__u8 bLength;
	__u8 bDescriptorType;
	__u8 bDescriptorSubtype;
	__u8 bUnitID;
	__u8 bNrInPins;
	__u8 baSourceID[];
} __attribute__ ((packed));

static inline __u8 uac_mixer_unit_bNrChannels(struct uac_mixer_unit_descriptor *desc)
{
	return desc->baSourceID[desc->bNrInPins];
}

static inline __u32 uac_mixer_unit_wChannelConfig(struct uac_mixer_unit_descriptor *desc,
						  int protocol)
{
	if (protocol == UAC_VERSION_1)
		return (desc->baSourceID[desc->bNrInPins + 2] << 8) |
			desc->baSourceID[desc->bNrInPins + 1];
	else
		return  (desc->baSourceID[desc->bNrInPins + 4] << 24) |
			(desc->baSourceID[desc->bNrInPins + 3] << 16) |
			(desc->baSourceID[desc->bNrInPins + 2] << 8)  |
			(desc->baSourceID[desc->bNrInPins + 1]);
}

static inline __u8 uac_mixer_unit_iChannelNames(struct uac_mixer_unit_descriptor *desc,
						int protocol)
{
	return (protocol == UAC_VERSION_1) ?
		desc->baSourceID[desc->bNrInPins + 3] :
		desc->baSourceID[desc->bNrInPins + 5];
}

static inline __u8 *uac_mixer_unit_bmControls(struct uac_mixer_unit_descriptor *desc,
					      int protocol)
{
	return (protocol == UAC_VERSION_1) ?
		&desc->baSourceID[desc->bNrInPins + 4] :
		&desc->baSourceID[desc->bNrInPins + 6];
}

static inline __u8 uac_mixer_unit_iMixer(struct uac_mixer_unit_descriptor *desc)
{
	__u8 *raw = (__u8 *) desc;
	return raw[desc->bLength - 1];
}

/* 4.3.2.4 Selector Unit Descriptor */
struct uac_selector_unit_descriptor {
	__u8 bLength;/*长度 为6*/
	__u8 bDescriptorType;/*描述符的类型：音频类接口，代码为：0x24*/
	__u8 bDescriptorSubtype;/*	描述符子类型，属于特征单元描述符子类，代码为：0x05*/
	__u8 bUintID;//该特征单元的ID号
	__u8 bNrInPins;
	__u8 baSourceID[];//该特征单元前序连接的实体ID号；前序连接实体可以是终端也可以是单元。和输出终端里面的bSourceID类似。
} __attribute__ ((packed));

static inline __u8 uac_selector_unit_iSelector(struct uac_selector_unit_descriptor *desc)
{
	__u8 *raw = (__u8 *) desc;
	return raw[desc->bLength - 1];
}

/* 4.3.2.5 Feature Unit Descriptor */
struct uac_feature_unit_descriptor {
	/*
		描述符的大小：7+(要控制的声道数目 *n) 字节
		要控制的声道数目：主声道肯定要有。
		所以描述符的大小可以表示成：7 + (ch) * n
	*/
	__u8 bLength;
	__u8 bDescriptorType;/*	描述符的类型：音频类特征单元，代码为：0x24*/
	__u8 bDescriptorSubtype;/*描述符子类型，属于特征单元描述符子类，代码为：0x06*/
	__u8 bUnitID;/*该特征单元的ID号*/
	__u8 bSourceID;
	/*
		bmaControls()数组元素的字节大小：n
		元素大小用多少个字节来表示。在规范中，规定了10种功能，所以n最大值为2。也就是16位，足以描述这10种功能。
		所以 n要么取1，要么取2。一般来说，USB音频不会配置太复杂的控制，n取1，即一个字节就可以表示位映射。
	*/
	__u8 bControlSize;
	/*
		通道0的功能特性位图描述。通道0是主通道。
		每个通道（包括主通道0和非0的逻辑通道）的控制位映射如下：
		D0：Mute 静音
		D1：Volume 音量控制
		D2：Bass 低音控制
		D3：Mid中音控制
		D4：Treble高音控制
		D5：Graphic Equalizer图形均衡器控制
		D6：Automatic Gain自动增益控制
		D7：Delay延迟控制
		D8：Bass Boost低音增强控制
		D9：Loudness 响度控制
		D10：保留，设置为0
		….. ：保留，设置为0
		D15：保留，设置为0
		所以，n要么取1，要么取2。
		最多取2，两字节，16bit。
	*/
	__u8 bmaControls[0]; /* variable length */
} __attribute__((packed));

static inline __u8 uac_feature_unit_iFeature(struct uac_feature_unit_descriptor *desc)
{
	__u8 *raw = (__u8 *) desc;
	return raw[desc->bLength - 1];
}

/* 4.3.2.6 Processing Unit Descriptors */
struct uac_processing_unit_descriptor {
	__u8 bLength;
	__u8 bDescriptorType;
	__u8 bDescriptorSubtype;
	__u8 bUnitID;
	__u16 wProcessType;
	__u8 bNrInPins;
	__u8 baSourceID[];
} __attribute__ ((packed));

static inline __u8 uac_processing_unit_bNrChannels(struct uac_processing_unit_descriptor *desc)
{
	return desc->baSourceID[desc->bNrInPins];
}

static inline __u32 uac_processing_unit_wChannelConfig(struct uac_processing_unit_descriptor *desc,
						       int protocol)
{
	if (protocol == UAC_VERSION_1)
		return (desc->baSourceID[desc->bNrInPins + 2] << 8) |
			desc->baSourceID[desc->bNrInPins + 1];
	else
		return  (desc->baSourceID[desc->bNrInPins + 4] << 24) |
			(desc->baSourceID[desc->bNrInPins + 3] << 16) |
			(desc->baSourceID[desc->bNrInPins + 2] << 8)  |
			(desc->baSourceID[desc->bNrInPins + 1]);
}

static inline __u8 uac_processing_unit_iChannelNames(struct uac_processing_unit_descriptor *desc,
						     int protocol)
{
	return (protocol == UAC_VERSION_1) ?
		desc->baSourceID[desc->bNrInPins + 3] :
		desc->baSourceID[desc->bNrInPins + 5];
}

static inline __u8 uac_processing_unit_bControlSize(struct uac_processing_unit_descriptor *desc,
						    int protocol)
{
	return (protocol == UAC_VERSION_1) ?
		desc->baSourceID[desc->bNrInPins + 4] :
		desc->baSourceID[desc->bNrInPins + 6];
}

static inline __u8 *uac_processing_unit_bmControls(struct uac_processing_unit_descriptor *desc,
						   int protocol)
{
	return (protocol == UAC_VERSION_1) ?
		&desc->baSourceID[desc->bNrInPins + 5] :
		&desc->baSourceID[desc->bNrInPins + 7];
}

static inline __u8 uac_processing_unit_iProcessing(struct uac_processing_unit_descriptor *desc,
						   int protocol)
{
	__u8 control_size = uac_processing_unit_bControlSize(desc, protocol);
	return *(uac_processing_unit_bmControls(desc, protocol)
			+ control_size);
}

static inline __u8 *uac_processing_unit_specific(struct uac_processing_unit_descriptor *desc,
						 int protocol)
{
	__u8 control_size = uac_processing_unit_bControlSize(desc, protocol);
	return uac_processing_unit_bmControls(desc, protocol)
			+ control_size + 1;
}

/* 4.5.2 Class-Specific AS Interface Descriptor */
struct uac1_as_header_descriptor {
	__u8  bLength;			/* in bytes: 7 */
	__u8  bDescriptorType;		/* 描述符类型，音频类接口，代码：0x24 */
	__u8  bDescriptorSubtype;	/* 	描述符子类型，代码：0x01 */
	__u8  bTerminalLink;		/* 如果该音频流接口有音频传输端点，
									则bTerminalLink代表该传输端点所对应的的终端号，
									那么这里填入的就是终端的ID。
									[接口下某个端点与终端的对应] */
	__u8  bDelay;			/* 数据通路上的延时 */
	__le16 wFormatTag;		/* 	音频流编码格式*/
} __attribute__ ((packed));

#define UAC_DT_AS_HEADER_SIZE		7
/*wFormatTag*/
/* Formats - A.1.1 Audio Data Format Type I Codes */
#define UAC_FORMAT_TYPE_I_UNDEFINED	0x0
#define UAC_FORMAT_TYPE_I_PCM		0x1
#define UAC_FORMAT_TYPE_I_PCM8		0x2
#define UAC_FORMAT_TYPE_I_IEEE_FLOAT	0x3
#define UAC_FORMAT_TYPE_I_ALAW		0x4
#define UAC_FORMAT_TYPE_I_MULAW		0x5

struct uac_format_type_i_continuous_descriptor {
	__u8  bLength;			/* in bytes: 8 + (ns * 3) */
	__u8  bDescriptorType;		/* USB_DT_CS_INTERFACE */
	__u8  bDescriptorSubtype;	/* FORMAT_TYPE */
	__u8  bFormatType;		/* FORMAT_TYPE_1 */
	__u8  bNrChannels;		/* physical channels in the stream */
	__u8  bSubframeSize;		/* */
	__u8  bBitResolution;
	__u8  bSamFreqType;
	__u8  tLowerSamFreq[3];
	__u8  tUpperSamFreq[3];
} __attribute__ ((packed));

#define UAC_FORMAT_TYPE_I_CONTINUOUS_DESC_SIZE	14

struct uac_format_type_i_discrete_descriptor {
	__u8  bLength;			/* in bytes: 8 + (支持几种采样率 * 3) */
	__u8  bDescriptorType;		/* 描述符的类型：音频类数据格式描述符，代码：0x24 */
	__u8  bDescriptorSubtype;	/* 	描述符的子类型：数据格式子类描述符，代码：0x02 FORMAT_TYPE */
	__u8  bFormatType;		/* 音频流数据格式类型 FORMAT_TYPE_1 */
	__u8  bNrChannels;		/*该接口声道簇中的物理通道个数*/
	__u8  bSubframeSize;		/* 该接口的子帧中有几个字节的音频数据*/
	__u8  bBitResolution;/*位分辨率：接口的子帧中有几位的音频数据是有效的*/
	__u8  bSamFreqType;/*音频流接口的同步传输端点支持几种采样率（n）*/
	__u8  tSamFreq[][3];/*同步传输端点所支持的采样率*/
} __attribute__ ((packed));

#define DECLARE_UAC_FORMAT_TYPE_I_DISCRETE_DESC(n)		\
struct uac_format_type_i_discrete_descriptor_##n {		\
	__u8  bLength;						\
	__u8  bDescriptorType;					\
	__u8  bDescriptorSubtype;				\
	__u8  bFormatType;					\
	__u8  bNrChannels;					\
	__u8  bSubframeSize;					\
	__u8  bBitResolution;					\
	__u8  bSamFreqType;					\
	__u8  tSamFreq[n][3];					\
} __attribute__ ((packed))

#define UAC_FORMAT_TYPE_I_DISCRETE_DESC_SIZE(n)	(8 + (n * 3))

struct uac_format_type_i_ext_descriptor {
	__u8 bLength;
	__u8 bDescriptorType;
	__u8 bDescriptorSubtype;
	__u8 bFormatType;
	__u8 bSubslotSize;
	__u8 bBitResolution;
	__u8 bHeaderLength;
	__u8 bControlSize;
	__u8 bSideBandProtocol;
} __attribute__((packed));

/* Formats - Audio Data Format Type I Codes */

#define UAC_FORMAT_TYPE_II_MPEG	0x1001
#define UAC_FORMAT_TYPE_II_AC3	0x1002

struct uac_format_type_ii_discrete_descriptor {
	__u8 bLength;
	__u8 bDescriptorType;
	__u8 bDescriptorSubtype;
	__u8 bFormatType;
	__le16 wMaxBitRate;
	__le16 wSamplesPerFrame;
	__u8 bSamFreqType;
	__u8 tSamFreq[][3];
} __attribute__((packed));

struct uac_format_type_ii_ext_descriptor {
	__u8 bLength;
	__u8 bDescriptorType;
	__u8 bDescriptorSubtype;
	__u8 bFormatType;
	__u16 wMaxBitRate;
	__u16 wSamplesPerFrame;
	__u8 bHeaderLength;
	__u8 bSideBandProtocol;
} __attribute__((packed));

/* type III */
#define UAC_FORMAT_TYPE_III_IEC1937_AC3	0x2001
#define UAC_FORMAT_TYPE_III_IEC1937_MPEG1_LAYER1	0x2002
#define UAC_FORMAT_TYPE_III_IEC1937_MPEG2_NOEXT	0x2003
#define UAC_FORMAT_TYPE_III_IEC1937_MPEG2_EXT	0x2004
#define UAC_FORMAT_TYPE_III_IEC1937_MPEG2_LAYER1_LS	0x2005
#define UAC_FORMAT_TYPE_III_IEC1937_MPEG2_LAYER23_LS	0x2006

/* Formats - A.2 Format Type Codes */
#define UAC_FORMAT_TYPE_UNDEFINED	0x0
#define UAC_FORMAT_TYPE_I		0x1
#define UAC_FORMAT_TYPE_II		0x2
#define UAC_FORMAT_TYPE_III		0x3
#define UAC_EXT_FORMAT_TYPE_I		0x81
#define UAC_EXT_FORMAT_TYPE_II		0x82
#define UAC_EXT_FORMAT_TYPE_III		0x83

struct uac_iso_endpoint_descriptor {
	__u8  bLength;			/* 长度：7 字节 */
	__u8  bDescriptorType;		/* 描述符类型，音频类传输端点，代码：0x25 */
	__u8  bDescriptorSubtype;	/* 描述符子类型，属于音频类端点子类描述符，代码：0x01*/
	/*
		对应的位设置为1，则说明该端点支持对应的操作
		D0：是否支持采样率调整
		D1：是否支持高音调整
		D6~D2：保留，设为0
		D7：该端点是否只支持wMaxPacketSize的传输。
			设置为0，表示可以传输短包（包长小于wMaxPacketSize）；
			设置为1，则表示只能传输大小为wMaxPacketSize的数据包。

	*/
	__u8  bmAttributes;
	/*
		字段wLockDelay所使用的单位：
		0：未定义的单位
		1：毫秒
		2：解码的PCM采样率
		其余位保留
	*/
	__u8  bLockDelayUnits;
	__le16 wLockDelay;//稳定产生/消耗音频数据前需要等待的时间(ms)。
} __attribute__((packed));
#define UAC_ISO_ENDPOINT_DESC_SIZE	7

#define UAC_EP_CS_ATTR_SAMPLE_RATE	0x01
#define UAC_EP_CS_ATTR_PITCH_CONTROL	0x02
#define UAC_EP_CS_ATTR_FILL_MAX		0x80

/* status word format (3.7.1.1) */

#define UAC1_STATUS_TYPE_ORIG_MASK		0x0f
#define UAC1_STATUS_TYPE_ORIG_AUDIO_CONTROL_IF	0x0
#define UAC1_STATUS_TYPE_ORIG_AUDIO_STREAM_IF	0x1
#define UAC1_STATUS_TYPE_ORIG_AUDIO_STREAM_EP	0x2

#define UAC1_STATUS_TYPE_IRQ_PENDING		(1 << 7)
#define UAC1_STATUS_TYPE_MEM_CHANGED		(1 << 6)

struct uac1_status_word {
	__u8 bStatusType;
	__u8 bOriginator;
} __attribute__((packed));


#endif /* _UAPI__LINUX_USB_AUDIO_H */
