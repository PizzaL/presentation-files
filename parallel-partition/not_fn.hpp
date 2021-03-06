// not_fn.hpp                                                         -*-C++-*-
// ----------------------------------------------------------------------------
//  Copyright (C) 2017 Dietmar Kuehl http://www.dietmar-kuehl.de         
//                                                                       
//  Permission is hereby granted, free of charge, to any person          
//  obtaining a copy of this software and associated documentation       
//  files (the "Software"), to deal in the Software without restriction, 
//  including without limitation the rights to use, copy, modify,        
//  merge, publish, distribute, sublicense, and/or sell copies of        
//  the Software, and to permit persons to whom the Software is          
//  furnished to do so, subject to the following conditions:             
//                                                                       
//  The above copyright notice and this permission notice shall be       
//  included in all copies or substantial portions of the Software.      
//                                                                       
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,      
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES      
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND             
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT          
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,         
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING         
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR        
//  OTHER DEALINGS IN THE SOFTWARE. 
// ----------------------------------------------------------------------------

#ifndef INCLUDED_NOT_FN
#define INCLUDED_NOT_FN

#include <utility>

// ----------------------------------------------------------------------------

namespace nstd {
#if 0
    template <typename Predicate>
    struct not_fn_t {
        Predicate predicate;
        template <typename... Args>
        bool operator()(Args&&... args) const {
            return !this->predicate(args...);
        }
    };

    template <typename Predicate>
    auto not_fn(Predicate predicate) ->not_fn_t<Predicate> {
        return not_fn_t<Predicate>{std::move(predicate)};
    }
#else
    template <typename Predicate>
    auto not_fn(Predicate predicate) {
        return [predicate=std::move(predicate)](auto&& value){
            return !predicate(value);
        };
    }
#endif
}

// ----------------------------------------------------------------------------

#endif
