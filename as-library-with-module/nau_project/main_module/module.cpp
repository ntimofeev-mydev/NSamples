#include "nau/module/module.h"

#include "myapi_impl.h"


class MainGameModule final : public nau::DefaultModuleImpl
{
    nau::string getModuleName() override
    {
        return "GameMainModule";
    }

    void initialize() override
    {
        NAU_MODULE_EXPORT_SERVICE(MyApiImpl);
    }
};


IMPLEMENT_MODULE(MainGameModule)
