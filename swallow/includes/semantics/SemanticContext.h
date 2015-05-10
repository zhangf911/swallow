/* SemanticContext.h --
 *
 * Copyright (c) 2014, Lex Chou <lex at chou dot it>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Swallow nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef SEMANTIC_CONTEXT_H
#define SEMANTIC_CONTEXT_H
#include "Type.h"

SWALLOW_NS_BEGIN

class ScopedCodeBlock;
class InitializationTracer;
typedef std::shared_ptr<class LazyDeclaration> LazyDeclarationPtr;


struct SemanticContext
{

    enum
    {
        /*!
         * Visiting the node in declaration mode
         */
        FLAG_PROCESS_DECLARATION = 1,
        /*!
         * Visiting the node in implementation mode
         */
        FLAG_PROCESS_IMPLEMENTATION = 2,
        /*!
         * Visiting the node in write context, will not check if the variable is not initialized
         */
        FLAG_WRITE_CONTEXT = 4
    };
    TypePtr contextualType;
    TypePtr currentType;
    TypePtr currentExtension;
    TypePtr currentFunction;
    ScopedCodeBlock* currentCodeBlock;
    InitializationTracer* currentInitializationTracer;
    int numTemporaryNames;
    int flags;
    ModulePtr currentModule;
    /*!
     * All types in current module, including nested types,
     * used for protocol conform verification
     */
    std::vector<TypePtr> allTypes;

    std::map<std::wstring, LazyDeclarationPtr> lazyDeclarations;
    bool lazyDeclaration;

    SemanticContext()
        :currentCodeBlock(nullptr), currentInitializationTracer(nullptr), numTemporaryNames(0), flags(FLAG_PROCESS_DECLARATION | FLAG_PROCESS_IMPLEMENTATION)
    {
        lazyDeclaration = true;
    }
};


SWALLOW_NS_END

#endif//SEMANTIC_CONTEXT_H
