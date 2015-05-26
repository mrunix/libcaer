/*
 * dvs128.h
 *
 *  Created on: May 26, 2015
 *      Author: llongi
 */

#ifndef LIBCAER_DEVICES_DVS128_H_
#define LIBCAER_DEVICES_DVS128_H_

#include "events/packetContainer.h"
#include "events/polarity.h"
#include "events/special.h"

#define DVS128_CONFIG_DVS  0
#define DVS128_CONFIG_BIAS 1

struct caer_dvs128_info {
	uint16_t deviceID;
	char *deviceString;
	// System information fields
	uint16_t logicVersion;
	bool deviceIsMaster;
	// DVS specific fields
	uint16_t dvsSizeX;
	uint16_t dvsSizeY;
};

typedef struct caer_dvs128_info *caerDVS128Info;

typedef struct caer_dvs128_handle *caerDVS128Handle;

caerDVS128Handle caerDVS128Open(uint8_t busNumberRestrict, uint8_t devAddressRestrict,
	const char *serialNumberRestrict);
bool caerDVS128Close(caerDVS128Handle handle);
caerDVS128Info caerDVS128InfoGet(caerDVS128Handle handle);
bool caerDVS128ConfigSet(caerDVS128Handle handle, int8_t modAddr, uint8_t paramAddr, uint32_t param);
bool caerDVS128ConfigGet(caerDVS128Handle handle, int8_t modAddr, uint8_t paramAddr, uint32_t *param);
bool caerDVS128DataStart(caerDVS128Handle);
bool caerDVS128DataStop(caerDVS128Handle handle);
caerEventPacketContainer caerDVS128DataGet(caerDVS128Handle handle);

#endif /* LIBCAER_DEVICES_DVS128_H_ */