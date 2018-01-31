/*
 * This file is part of the SmuView project.
 *
 * Copyright (C) 2018 Frank Stettner <frank-stettner@gmx.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include "virtualtab.hpp"
#include "src/session.hpp"
#include "src/devices/virtualdevice.hpp"
#include "src/tabs/devicetab.hpp"

namespace sv {
namespace tabs {

VirtualTab::VirtualTab(Session &session,
		shared_ptr<devices::VirtualDevice> device, QMainWindow *parent) :
	DeviceTab(session, device, parent)
{
}

} // namespace tabs
} // namespace sv
