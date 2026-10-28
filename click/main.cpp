// rev-w9sn0u-20261028 main.cpp
#include "Nvngx.h"
#include <iostream>

int main(int argc, char** argv) {
    dlss5::OneClick installer;
    dlss5::ClickConfig cfg;
    cfg.load("cards/Supported.json");

    std::cout << "DLSS 5 One Click v0.14.1\n";

    if (!installer.probeGpu(cfg)) {
        std::cerr << "refused: not on RTX 30/40/50 Tensor path\n";
        return 1;
    }

    const char* gameDir = (argc > 1) ? argv[1] : ".";
    if (!installer.installNvngx(gameDir, cfg)) {
        std::cerr << "install failed: nvngx_dlss.dll not written\n";
        return 2;
    }

    installer.writePreset(gameDir);
    return 0;
}
