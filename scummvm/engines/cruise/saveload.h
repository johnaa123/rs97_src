/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * $URL: https://scummvm.svn.sourceforge.net/svnroot/scummvm/scummvm/tags/release-1-2-1/engines/cruise/saveload.h $
 * $Id: saveload.h 45616 2009-11-02 21:54:57Z fingolfin $
 *
 */

#ifndef CRUISE_SAVELOAD_H
#define CRUISE_SAVELOAD_H

#include "common/scummsys.h"
#include "graphics/surface.h"

namespace Cruise {

#define CRUISE_SAVEGAME_VERSION 1

struct CruiseSavegameHeader {
	uint8 version;
	Common::String saveName;
	Graphics::Surface *thumbnail;
};

Common::Error saveSavegameData(int saveGameIdx, const Common::String &saveName);
Common::Error loadSavegameData(int saveGameIdx);
bool readSavegameHeader(Common::InSaveFile *in, CruiseSavegameHeader &header);
void initVars();

} // End of namespace Cruise

#endif
