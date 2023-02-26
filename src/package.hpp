/*
 * Nifty - Nifty Programming Language
 * Copyright (c) 2022 - 2023 Skyler Burwell
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 */

#ifndef __NIFTY_PACKAGE_HPP__
#define __NIFTY_PACKAGE_HPP__

#include "symbolTable.hpp"

#include "util/str.hpp"

#include <unordered_map>

class Packages {
public:
    Packages *instance();
    bool contains(const String &name);
    bool add(const String &name);

    SymbolTable *get(const String &name);

private:
    Packages();
    Packages *_instance;

    std::unordered_map<String, SymbolTable *> _packages;
};


#endif //__NIFTY_PACKAGE_HPP__