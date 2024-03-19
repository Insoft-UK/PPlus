/*
 Copyright © 2023 Insoft. All rights reserved.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

#include "Auto.hpp"

#include <sstream>
#include <regex>
#include "Singleton.hpp"

using namespace pp;

bool Auto::parse(std::string &str) {
    std::smatch m;
    std::regex r;
    size_t pos;
    Singleton *singleton = Singleton::shared();
    
    // Functions/Subroutines
    // TODO: ^ *(export +)?\bauto *: *((?:(?:[a-zA-Z_]\w*::)*?)[a-zA-Z][\w.]*) *(?=\()
    
    if (singleton->scope == Singleton::Scope::kGlobal) {
//        /*
//         eg. export auto:alias(p1, p2:alias, auto:alias)
//         Group  0 export auto:alias
//                1 export
//                2 alias
//         */
//        r = R"(^ *(export +)?\bauto *: *((?:(?:[a-zA-Z_]\w*::)*?)[a-zA-Z][\w.]*) *(?=\())";
//        if (regex_search(str, m, r)) {
//            auto it = std::sregex_token_iterator {
//                str.begin(), str.end(), r, {1, 2}
//            };
//            if (it != std::sregex_token_iterator()) {
//                std::ostringstream os;
//                
//                if (it++->matched) {
//                    os << "export ";
//                }
//                os << "fn" << ++_fnCount << ":" << *it;
//                str.replace(m.position(), m.str().length(), "if ");
//            }
//        }
        r = R"(\bauto *(?=: *(?:(?:(?:[a-zA-Z_]\w*::)*?)[a-zA-Z][\w.]*) *(?=\()))";
        if (regex_search(str, m, r)) {
            std::ostringstream os;
            os << "fn" << ++_fnCount;
            str.replace(m.position(), m.str().length(), os.str());
        }
        
        _paramCount = 0;
        while ((pos = str.find("auto:")) != std::string::npos) {
            std::ostringstream os;
            os << "p" << ++_paramCount;
            str.replace(pos, 4, os.str());
        }
    }
    
    
    // Variables/Constants
    r = R"(\b(var|const) +)";
    if (regex_search(str, m, r)) {
        while ((pos = str.find("auto:")) != std::string::npos) {
            str.erase(pos, 4);
            std::ostringstream os;
            os << "v" << ++_varCount;
            str.insert(pos, os.str());
        }
    }
    
    return true;
}



