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

#include "PCA6408A.h"

#include <stdio.h>

enum PCA6408A_Registers_t
{
	PCA6408A_Registers_InputPort = 0,
	PCA6408A_Registers_OutputPort = 1,
	PCA6408A_Registers_PolarityInversion = 2,
	PCA6408A_Registers_Configuration = 3
};

void PCA6408A_SetDeviceAddress(struct PCA6408A_t* instance, bool addrPinHigh)
{
	const uint8_t fixedpartofaddress = 0b00100000; //defined by the device manufacturer
	instance->I2C_Address = addrPinHigh ? (fixedpartofaddress | 1) : fixedpartofaddress;
}

bool PCA6408A_WritePort(struct PCA6408A_t* instance, uint8_t data)
{
	uint8_t buffer[2] = { PCA6408A_Registers_OutputPort, data };
	return instance->I2C_WriteMethodPtr(instance->I2C_Address, &buffer[0], 2);
}

bool PCA6408A_ReadPort(struct PCA6408A_t* instance, uint8_t* data)
{
	uint8_t buffer = { PCA6408A_Registers_InputPort };
	bool success = instance->I2C_WriteMethodPtr(instance->I2C_Address, &buffer, 1);
	if (!success)
	{ return false; }
	return instance->I2C_ReadMethodPtr(instance->I2C_Address, data, 1);
}

bool PCA6408A_ConfigurePort(struct PCA6408A_t* instance, uint8_t config)
{
	uint8_t buffer[2] = { PCA6408A_Registers_Configuration, config };
	return instance->I2C_WriteMethodPtr(instance->I2C_Address, &buffer[0], 2);
}

bool PCA6408A_ConfigurePortPolarity(struct PCA6408A_t* instance, uint8_t polarityConfig)
{
	uint8_t buffer[2] = { PCA6408A_Registers_PolarityInversion, polarityConfig };
	return instance->I2C_WriteMethodPtr(instance->I2C_Address, &buffer[0], 2);
}