#ifndef EIGEN_FORWARD_DECLARATION_H
#define EIGEN_FORWARD_DECLARATION_H

constexpr int DYNAMIC = -1;

template<typename Derived> struct trasit_type;
template<int CompileRows, int CompileCols> struct trasit_storage;
template<typename T, int Size=0, bool IsArray=false> class StorageBase;
template<typename Derived> class CoeffBase;
template<typename T, int CompileRows=-1, int CompileCols=-1> class Matrix;

#endif