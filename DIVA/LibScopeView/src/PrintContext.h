//===-- LibScopeView/PrintContext.h -----------------------------*- C++ -*-===//
///
/// Copyright (c) Sony Interactive Entertainment Inc.
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to
/// deal in the Software without restriction, including without limitation the
/// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
/// sell copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
/// IN THE SOFTWARE.
///
//===----------------------------------------------------------------------===//
///
/// \file
/// Definition of the PrintContext class.
///
//===----------------------------------------------------------------------===//

#ifndef PRINT_CONTEXT_H
#define PRINT_CONTEXT_H

#include <memory>
#include <string>

namespace LibScopeView {

/// \brief Class to represent an output print context.
class PrintContext {
public:
  PrintContext();
  PrintContext(FILE *Context);
  ~PrintContext();

  typedef int (*PrintFunc)(const char *, ...);

public:
  static void create(FILE *Context);

public:
  bool open(const std::string &FilePath);
  void close();
  int print(const char *Fmt, ...);
  bool createLocation(const std::string &Location);

public:
  std::string getLocation() { return TheLocation; }

private:
  FILE *File;
  FILE *FileSave;
  std::string TheLocation;
  bool LocationDone;
};

// Instance to handle the print context.
extern std::unique_ptr<PrintContext> GlobalPrintContext;

} // namespace LibScopeView

#endif // PRINT_CONTEXT_H