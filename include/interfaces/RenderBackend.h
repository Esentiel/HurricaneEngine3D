#pragma once

namespace iface{
    struct RenderBackend{
        RenderBackend() = default;
        virtual void Initialize(const char * rootFolder) = 0;
        virtual void Render(float dt) = 0;
        virtual bool IsRunning() = 0;
        virtual ~RenderBackend() {};

    };
}