#include <Geode/Geode.hpp>
#include <Geode/modify/CCScheduler.hpp>

using namespace geode::prelude;

class $modify(MyCCScheduler, CCScheduler) {
    void update(float dt) {
        // Leemos la configuración del usuario desde el mod.json
        bool bypassEnabled = Mod::get()->getSettingValue<bool>("bypass-enabled");
        int fpsLimit = Mod::get()->getSettingValue<int64_t>("fps-limit");

        if (bypassEnabled && fpsLimit > 0) {
            // Modificamos el intervalo de tiempo por frame basado en los FPS deseados
            // Fórmula: 1.0f / (FPS deseados)
            float targetInterval = 1.0f / static_cast<float>(fpsLimit);
            this->setAnimationInterval(targetInterval);
        }

        // Ejecutamos la actualización normal del juego
        CCScheduler::update(dt);
    }
};
