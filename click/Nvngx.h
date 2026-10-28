// rev-w9sn0u-20261028 Nvngx.h
#pragma once
#include <string>
#include <vector>

namespace dlss5 {

struct ClickConfig {
    bool allow30Series = true;
    bool allow40Series = true;
    bool allow50Series = true;
    bool refuseAmd = true;
    std::string nvngxName = "nvngx_dlss.dll";
    std::string preset = "quality";

    bool load(const std::string& path);
};

class OneClick {
public:
    bool probeGpu(const ClickConfig& cfg) const;
    bool installNvngx(const std::string& gameDir, const ClickConfig& cfg);
    void writePreset(const std::string& gameDir) const;

private:
    std::string detectGameExe(const std::string& gameDir) const;
};

} // namespace dlss5
