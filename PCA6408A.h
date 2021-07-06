#ifndef PCA6408A_LIBRARY_H
#define PCA6408A_LIBRARY_H

#include <stdbool.h>
#include <stdint.h>
#include "LL_i2c.h"

struct PCA6408A_t
{
	uint8_t I2C_Address;
	I2CMaster_WriteMethod_t I2C_WriteMethodPtr;
	I2CMaster_ReadMethod_t I2C_ReadMethodPtr;
};

/// This is a helper function to set the device address based on the state of the address pin on the device.
/// \param instance a pointer to the instance struct
/// \param addrPinHigh true if the ADDR pin is set to 1 on the device
void PCA6408A_SetDeviceAddress(struct PCA6408A_t* instance, bool addrPinHigh);

///Writes the outgoing logic levels of the pins defined as
///outputs by the Configuration register. Bit values in these registers have no effect on pins
///defined as inputs. In turn, reads from this register reflect the value that was written to this
///register, not the actual pin value.
/// \param instance a pointer to the instance struct
/// \param data the byte to be written to the port
/// \return true if transaction was successful
bool PCA6408A_WritePort(struct PCA6408A_t* instance, uint8_t data);

bool PCA6408A_ReadPort(struct PCA6408A_t* instance, uint8_t* data);

#endif //PCA6408A_LIBRARY_H
