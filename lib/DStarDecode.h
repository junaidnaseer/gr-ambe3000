#pragma once

/* -*- c++ -*- */
/* 
 * Copyright 2016 Thomas Early N7TAE.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#include "DV3000U.h"
#include "SyncRegister.h"
#include "SlowData.h"

class CDStarDecode {
public:
	CDStarDecode();
	~CDStarDecode();
	bool OpenDevice(char *device, int baudrate);
	bool Process(const unsigned char *in, short int *out, int &output_count);
	void CloseDevice();
private:
	CDV3000U dv3000u;
	CSyncRegister sr;
	CSlowData slowdata;

	enum { headmode, datamode, nullmode } readmode;
	unsigned char buffer[660];
	int index, voiceframecount;
	short int audiobuffer[160];
	bool audio_ready;
	bool first_time;
};
