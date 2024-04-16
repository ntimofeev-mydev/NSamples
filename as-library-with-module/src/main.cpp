#include "myapi.h"
#include "nau/app/application.h"
#include "nau/app/application_services.h"
#include "nau/app/platform_window.h"
#include "nau/app/window_manager.h"
#include "nau/module/module_manager.h"

#define RUN_PLATFORM_APP

int main()
{
    using namespace nau;
    using namespace nau::async;

    using namespace std::chrono_literals;

    auto app = createApplication(
        []
        {
            loadModulesList(NAU_MODULES_LIST).ignore();

#ifdef RUN_PLATFORM_APP
            getServiceProvider().addService(createPlatformWindowService());
#endif
            return ResultSuccess;
        });

    app->startupOnCurrentThread();

#ifdef RUN_PLATFORM_APP
    getServiceProvider().get<IWindowManager>().getActiveWindow().setVisible(true);
#endif

    []() -> Task<>
    {
        co_await 100ms;
        std::cout << "Tick\n";

        getServiceProvider().get<IMyApi1>().myApiFunction();

#ifndef RUN_PLATFORM_APP
        getApplication().stop();
#endif

    }()
                .detach();

    while(app->step())
    {
        std::this_thread::sleep_for(50ms);
    };

    return 0;
}
