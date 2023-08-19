#ifndef EIGEN_TRASIT_H
#define EIGEN_TRASIT_H

#include "forward_declaration.h"

template<typename _T, int _CompileRows, int _CompileCols>
struct trasit_type<Matrix<_T, _CompileRows, _CompileCols>>
{
    typedef _T T;
    enum {
        CompileRows = _CompileRows,
        CompileCols = _CompileCols,
    };
};

template<int CompileRows, int CompileCols>
struct trasit_storage
{
    enum {
        Size = (CompileRows == DYNAMIC || CompileCols == DYNAMIC) ? 0 : CompileRows * CompileCols,
        IsArray = (Size != 0),
    };
};

#endif