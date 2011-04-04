/***************************************************************************
 *   Copyright (C) 2010~2010 by CSSlayer                                   *
 *   wengxt@gmail.com                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _HOOK_H
#define _HOOK_H
#include "fcitx-config/fcitx-config.h"
#include "fcitx-config/hotkey.h"
#include "ime.h"

typedef struct HotkeyHook {
    HOTKEYS* hotkey;
    INPUT_RETURN_VALUE (*hotkeyhandle)();
} HotkeyHook;

void ProcessPreInputFilter(FcitxKeySym sym, unsigned int state, INPUT_RETURN_VALUE* retval);
void ProcessPostInputFilter(FcitxKeySym sym, unsigned int state, INPUT_RETURN_VALUE* retval);
char* ProcessOutputFilter(char *in);
INPUT_RETURN_VALUE CheckHotkey(FcitxKeySym keysym, unsigned int state);

#define DECLARE_HOOK(name, type) \
void Register##name(type value)

DECLARE_HOOK(PreInputFilter, void*);
DECLARE_HOOK(PostInputFilter, void*);
DECLARE_HOOK(OutputFilter, void*);
DECLARE_HOOK(HotkeyFilter, HotkeyHook);

#endif