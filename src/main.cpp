#include "App.hpp"

#include "Core/Context.hpp"

int main(int, char**) {
    auto context = Core::Context::GetInstance();
    App app;

    while (!context->GetExit()) {
        context->Update();
        switch (app.GetCurrentState()) {
            case App::State::START:
                app.Start();
                break;

            case App::State::UPDATE:
                app.Update();
                break;
            case App::State::END:
                app.End();
                context->SetExit(true);
                break;
            case App::State::gameovers:
                app.gameovers();
                break;
            case App::State::zero:
                app.zero();
                break;
            case App::State::ONE:
                app.one();
                break;
            case App::State::TWO:
                app.two();
            break;
            case App::State::Win:
                app.Win();
            break;
        }
    }
    return 0;
}
