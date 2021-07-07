//MIT License
//
//Copyright (c) 2021 Jeroen Vandezande
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

#ifndef PCA6408A_LIBRARY_H
#define PCA6408A_LIBRARY_H

#include <stdbool.h>
#include <stdint.h>
#include "LL_i2c.h"

struct PCA6408A_t
{
	uint8_t I2C_Address;
	LL_I2CMaster_WriteMethod_t I2C_WriteMethodPtr;
	LL_I2CMaster_ReadMethod_t I2C_ReadMethodPtr;
};

/// This is a helper function to set the device address based on the state of the address pin on the device.
/// \param instance a pointer to the instance struct
/// \param addrPinHigh true if the ADDR pin is set to 1 on the device
void PCA6408A_SetDeviceAddress(struct PCA6408A_t* instance, bool addrPinHigh);

/// Writes the outgoing logic levels of the pins defined as
/// outputs by the Configuration register. Bit values in these registers have no effect on pins
/// defined as inputs. In turn, reads from this register reflect the value that was written to this
/// register, not the actual pin value.
/// \param instance a pointer to the instance struct
/// \param data the byte to be written to the port
/// \return true if transaction was successful
bool PCA6408A_WritePort(struct PCA6408A_t* instance, uint8_t data);

/// Reads the incoming logic levels of the pins,
/// regardless of whether the pin is defined as an input or an output by the Configuration register.
/// \param instance a pointer to the instance struct
/// \param data a pointer to a variable that will be filled with the port data
/// \return true if transaction was successful
bool PCA6408A_ReadPort(struct PCA6408A_t* instance, uint8_t* data);

/// configures the direction of the I/O pins. If a bit in this
/// register is set to 1, the corresponding port pin is enabled as a high-impedance input. If a
/// bit in this register is cleared to 0, the corresponding port pin is enabled as an output.
/// The default value of this register is all pins as input.
/// \param instance a pointer to the instance struct
/// \param config the configuration byte to be written to the port
/// \return true if transaction was successful
bool PCA6408A_ConfigurePort(struct PCA6408A_t* instance, uint8_t config);

/// allows polarity inversion of pins defined as
/// inputs by the Configuration register. If a bit in this register is set (written with ‘1’), the
/// corresponding port pin’s polarity is inverted. If a bit in this register is cleared (written with a‘0’),
/// the corresponding port pin’s original polarity is retained.
/// \param instance a pointer to the instance struct
/// \param polarityConfig the port polarity configuration byte to be written to the port
/// \return true if transaction was successful
bool PCA6408A_ConfigurePortPolarity(struct PCA6408A_t* instance, uint8_t polarityConfig);

#endif //PCA6408A_LIBRARY_H
