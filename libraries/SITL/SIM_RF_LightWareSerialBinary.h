/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
  Simulator for the serial LightWare rangefinder - binary mode

./Tools/autotest/sim_vehicle.py --gdb --debug -v ArduCopter -A --serial5=sim:lightwareserial-binary --speedup=1

param set SERIAL5_PROTOCOL 9
param set RNGFND1_TYPE 8
graph RANGEFINDER.distance
graph GLOBAL_POSITION_INT.relative_alt/1000-RANGEFINDER.distance
reboot

arm throttle
rc 3 1600
*/

#pragma once

#include "SIM_SerialRangeFinder.h"

namespace SITL {

class RF_LightWareSerialBinary : public SerialRangeFinder {
public:

    static SerialRangeFinder *create() { return NEW_NOTHROW RF_LightWareSerialBinary(); }

    uint32_t packet_for_alt(uint16_t alt_cm, uint8_t *buffer, uint8_t buflen) override;

};

}
