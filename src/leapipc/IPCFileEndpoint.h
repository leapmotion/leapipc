// Copyright (C) 2012-2017 Leap Motion, Inc. All rights reserved.
#pragma once
#include "RawIPCEndpoint.h"
#include <fstream>

namespace leap {
namespace ipc {

class IPCFileEndpoint:
  public RawIPCEndpoint
{
public:
  IPCFileEndpoint(const std::string& fileName, bool read, bool write);
  ~IPCFileEndpoint(void);

private:
  std::fstream m_file;

public:
  // IPCEndpoint overrides:
  std::streamsize ReadRaw(void* buffer, std::streamsize size) override;
  bool WriteRaw(const void* pBuf, std::streamsize nBytes) override;
  bool Abort(Reason reason) override;
};

}}
