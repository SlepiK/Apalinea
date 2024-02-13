#ifndef ENERGYLEAF_V1_SOURCE_CAMERAEL
#define ENERGYLEAF_V1_SOURCE_CAMERAEL

#include <Extras/Vision/Camera/AbstractCamera.hpp>

class CameraEL : public Energyleaf::Stream::V1::Extras::Vision::AbstractCamera<int> {
public:
    using CameraConfig = int;

    CameraEL() : AbstractCamera() {
        p = 3;
    }

    ~CameraEL() override = default;

    [[nodiscard]] const int& getConfig() const override {
       return p;
    }

    void setConfig(int&& config) override {
    }

    void setConfig(int& config) override {
    }
private:
    int p;
protected:
    void internalStart() override{
    }
    void internalStop() override{
    }
    [[nodiscard]] Energyleaf::Stream::V1::Types::Image getInternalImage() const override {
        Energyleaf::Stream::V1::Types::Image img;
        img.setWidth(30);
        img.setHeight(30);
        img.setBytesPerPixel(3);
        img.setFormat(Energyleaf::Stream::V1::Types::ImageFormat::FB_BGR888);
        img.initData();
        return img;
    }
};

#endif