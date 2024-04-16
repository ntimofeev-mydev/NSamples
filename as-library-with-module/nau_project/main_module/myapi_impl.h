#pragma once

#include "myapi.h"
#include "nau/rtti/rtti_impl.h"


class MyApiImpl : public IMyApi1
{
    NAU_RTTI_CLASS(MyApiImpl , IMyApi1)

public:
    MyApiImpl();

    void myApiFunction() override;

};
