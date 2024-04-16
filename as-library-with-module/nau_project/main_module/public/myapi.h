#pragma once

#include "nau/rtti/rtti_object.h"


struct NAU_ABSTRACT_TYPE IMyApi1 : nau::IRttiObject
{
    NAU_INTERFACE(IMyApi1, nau::IRttiObject)

    virtual void myApiFunction() = 0;
};

