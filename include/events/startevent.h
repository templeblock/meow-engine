/*
 * Copyright 2019 Julian Haldenby
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef JNI_STARTEVENT_H
#define JNI_STARTEVENT_H

#include <main_character.h>
#include "event.h"
#include "event_ids.h"

class StartEvent: public LuaEvent {
private:
    MainCharacter * mainCharacter;

public:
    StartEvent(MainCharacter * character):LuaEvent(START_EVENT_ID, START_EVENT),mainCharacter(character) {};
    ~StartEvent() {};

    virtual int populateEvent(lua_State *L) {
        mainCharacter->serialize(L);
        return 1;
    }
};

#endif