// Copyright 2017 Yahoo Holdings. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.
#pragma once

#include "iconfigcontext.h"
#include "timingvalues.h"
#include "configmanager.h"
#include <vespa/config/subscription/sourcespec.h>

namespace config {

class ConfigContext : public IConfigContext
{
public:
    ConfigContext(const SourceSpec & spec = ServerSpec());
    ConfigContext(const TimingValues & timingValues, const SourceSpec & spec = ServerSpec());
    IConfigManager & getManagerInstance() override;
    void reload() override;

private:
    TimingValues  _timingValues;
    int64_t       _generation;
    ConfigManager _manager;
};


} // namespace

