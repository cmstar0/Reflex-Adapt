/*
*  Project     Nintendo Extension Controller Library
*  @author     David Madison
*  @link       github.com/dmadison/NintendoExtensionCtrl
*  @license    LGPLv3 - Copyright (c) 2018 David Madison
*
*  This file is part of the Nintendo Extension Controller Library.
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Lesser General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NXC_NUNCHUK_H
#define NXC_NUNCHUK_H

#include "../internal/ExtensionController.h"

namespace NintendoExtensionCtrl {
	class NunchukBase : public ExtensionController {
	public:
		struct Maps {
			constexpr static IndexMap JoyX = 0;
			constexpr static IndexMap JoyY = 1;

			constexpr static IndexMap AccelX_MSB = 2;
			constexpr static ByteMap  AccelX_LSB = ByteMap(5, 2, 2, 2);

			constexpr static IndexMap AccelY_MSB = 3;
			constexpr static ByteMap  AccelY_LSB = ByteMap(5, 2, 4, 4);

			constexpr static IndexMap AccelZ_MSB = 4;
			constexpr static ByteMap  AccelZ_LSB = ByteMap(5, 2, 6, 6);

			constexpr static BitMap   ButtonC = { 5, 1 };
			constexpr static BitMap   ButtonZ = { 5, 0 };
		};
		
		using ExtensionController::ExtensionController;

		ExtensionType getExpectedType() const;

		uint8_t joyX() const;  // 8 bits, 0-255
		uint8_t joyY() const;

		uint16_t accelX() const;  // 10 bits, 0-1023
		uint16_t accelY() const;
		uint16_t accelZ() const;

		boolean buttonC() const;
		boolean buttonZ() const;

		float rollAngle() const;  // -180.0 to 180.0
		float pitchAngle() const;

		void printDebug(Print& output = NXC_SERIAL_DEFAULT) const;
	};
}

using Nunchuk = NintendoExtensionCtrl::BuildControllerClass
	<NintendoExtensionCtrl::NunchukBase>;

#endif
